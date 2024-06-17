MODULE otim7n2

   USE master_parameters
   USE real_utils

   IMPLICIT NONE

   INTEGER, PARAMETER :: num_im_dir = 36
   INTEGER, PARAMETER :: torder     = 2
   INTEGER, PARAMETER :: n_imdir_order(3) = [1,7,28]

   TYPE ONUMM7N2
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
     REAL(DP) :: E12
     REAL(DP) :: E22
     REAL(DP) :: E13
     REAL(DP) :: E23
     REAL(DP) :: E33
     REAL(DP) :: E14
     REAL(DP) :: E24
     REAL(DP) :: E34
     REAL(DP) :: E44
     REAL(DP) :: E15
     REAL(DP) :: E25
     REAL(DP) :: E35
     REAL(DP) :: E45
     REAL(DP) :: E55
     REAL(DP) :: E16
     REAL(DP) :: E26
     REAL(DP) :: E36
     REAL(DP) :: E46
     REAL(DP) :: E56
     REAL(DP) :: E66
     REAL(DP) :: E17
     REAL(DP) :: E27
     REAL(DP) :: E37
     REAL(DP) :: E47
     REAL(DP) :: E57
     REAL(DP) :: E67
     REAL(DP) :: E77
   END TYPE ONUMM7N2

   ! Constant imaginary directions.
   ! Order 1
   TYPE(ONUMM7N2), PARAMETER :: E1 = ONUMM7N2(0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E2 = ONUMM7N2(0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E3 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E4 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E5 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E6 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E7 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   ! Order 2
   TYPE(ONUMM7N2), PARAMETER :: E11 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E12 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E22 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E13 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E23 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E33 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E14 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E24 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E34 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E44 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E15 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E25 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E35 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E45 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E55 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E16 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E26 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E36 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E46 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E56 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E66 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E17 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E27 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E37 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E47 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E57 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E67 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp)
   TYPE(ONUMM7N2), PARAMETER :: E77 = ONUMM7N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp)


   INTERFACE OPERATOR(*)
      MODULE PROCEDURE ONUMM7N2_MUL_OO_SS,ONUMM7N2_MUL_RO_SS,ONUMM7N2_MUL_OR_SS,ONUMM7N2_MUL_OO_VS,&
                       ONUMM7N2_MUL_RO_VS,ONUMM7N2_MUL_OR_VS,ONUMM7N2_MUL_OO_MS,ONUMM7N2_MUL_RO_MS,&
                       ONUMM7N2_MUL_OR_MS,ONUMM7N2_MUL_OO_SV,ONUMM7N2_MUL_RO_SV,ONUMM7N2_MUL_OR_SV,&
                       ONUMM7N2_MUL_OO_SM,ONUMM7N2_MUL_RO_SM,ONUMM7N2_MUL_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(+)
      MODULE PROCEDURE ONUMM7N2_ADD_OO_SS,ONUMM7N2_ADD_RO_SS,ONUMM7N2_ADD_OR_SS,ONUMM7N2_ADD_OO_VS,&
                       ONUMM7N2_ADD_RO_VS,ONUMM7N2_ADD_OR_VS,ONUMM7N2_ADD_OO_MS,ONUMM7N2_ADD_RO_MS,&
                       ONUMM7N2_ADD_OR_MS,ONUMM7N2_ADD_OO_SV,ONUMM7N2_ADD_RO_SV,ONUMM7N2_ADD_OR_SV,&
                       ONUMM7N2_ADD_OO_SM,ONUMM7N2_ADD_RO_SM,ONUMM7N2_ADD_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(-)
      MODULE PROCEDURE ONUMM7N2_NEG,ONUMM7N2_SUB_OO_SS,ONUMM7N2_SUB_RO_SS,ONUMM7N2_SUB_OR_SS,&
                       ONUMM7N2_SUB_OO_VS,ONUMM7N2_SUB_RO_VS,ONUMM7N2_SUB_OR_VS,ONUMM7N2_SUB_OO_MS,&
                       ONUMM7N2_SUB_RO_MS,ONUMM7N2_SUB_OR_MS,ONUMM7N2_SUB_OO_SV,ONUMM7N2_SUB_RO_SV,&
                       ONUMM7N2_SUB_OR_SV,ONUMM7N2_SUB_OO_SM,ONUMM7N2_SUB_RO_SM,ONUMM7N2_SUB_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(/)
      MODULE PROCEDURE ONUMM7N2_DIVISION_OO,ONUMM7N2_DIVISION_OR,ONUMM7N2_DIVISION_RO
   END INTERFACE

   INTERFACE ASSIGNMENT(=)
      MODULE PROCEDURE ONUMM7N2_ASSIGN_R
   END INTERFACE

   INTERFACE OPERATOR(**)
      MODULE PROCEDURE ONUMM7N2_POW_OR,ONUMM7N2_POW_RO,ONUMM7N2_POW_OO
   END INTERFACE

   INTERFACE PPRINT
      MODULE PROCEDURE ONUMM7N2_PPRINT_S,ONUMM7N2_PPRINT_V,ONUMM7N2_PPRINT_M
   END INTERFACE

   INTERFACE TRANSPOSE
      MODULE PROCEDURE ONUMM7N2_TRANSPOSE
   END INTERFACE

   INTERFACE MATMUL
      MODULE PROCEDURE ONUMM7N2_MATMUL_ONUMM7N2,R_MATMUL_ONUMM7N2,ONUMM7N2_MATMUL_R
   END INTERFACE

   INTERFACE DOT_PRODUCT
      MODULE PROCEDURE ONUMM7N2_DOT_PRODUCT_ONUMM7N2,R_DOT_PRODUCT_ONUMM7N2,ONUMM7N2_DOT_PRODUCT_R
   END INTERFACE

   INTERFACE UNFOLD
      MODULE PROCEDURE ONUMM7N2_TO_CR_MAT_S,ONUMM7N2_TO_CR_MAT_V,ONUMM7N2_TO_CR_MAT_M
   END INTERFACE

   INTERFACE TO_CR
      MODULE PROCEDURE ONUMM7N2_TO_CR_MAT_S,ONUMM7N2_TO_CR_MAT_V,ONUMM7N2_TO_CR_MAT_M
   END INTERFACE

   INTERFACE SIN
      MODULE PROCEDURE ONUMM7N2_SIN
   END INTERFACE

   INTERFACE COS
      MODULE PROCEDURE ONUMM7N2_COS
   END INTERFACE

   INTERFACE TAN
      MODULE PROCEDURE ONUMM7N2_TAN
   END INTERFACE

   INTERFACE ASIN
      MODULE PROCEDURE ONUMM7N2_ASIN
   END INTERFACE

   INTERFACE ACOS
      MODULE PROCEDURE ONUMM7N2_ACOS
   END INTERFACE

   INTERFACE ATAN
      MODULE PROCEDURE ONUMM7N2_ATAN
   END INTERFACE

   INTERFACE SINH
      MODULE PROCEDURE ONUMM7N2_SINH
   END INTERFACE

   INTERFACE COSH
      MODULE PROCEDURE ONUMM7N2_COSH
   END INTERFACE

   INTERFACE TANH
      MODULE PROCEDURE ONUMM7N2_TANH
   END INTERFACE

   INTERFACE SQRT
      MODULE PROCEDURE ONUMM7N2_SQRT
   END INTERFACE

   INTERFACE LOG
      MODULE PROCEDURE ONUMM7N2_LOG
   END INTERFACE

   INTERFACE EXP
      MODULE PROCEDURE ONUMM7N2_EXP
   END INTERFACE

   INTERFACE GEM
      MODULE PROCEDURE ONUMM7N2_GEM_OOO,ONUMM7N2_GEM_ROO,ONUMM7N2_GEM_ORO
   END INTERFACE

   INTERFACE FEVAL
      MODULE PROCEDURE ONUMM7N2_FEVAL
   END INTERFACE

   INTERFACE F2EVAL
      MODULE PROCEDURE ONUMM7N2_F2EVAL
   END INTERFACE

   INTERFACE REAL
      MODULE PROCEDURE ONUMM7N2_REAL
   END INTERFACE

   INTERFACE DET2X2
      MODULE PROCEDURE ONUMM7N2_det2x2
   END INTERFACE

   INTERFACE DET3X3
      MODULE PROCEDURE ONUMM7N2_det3x3
   END INTERFACE

   INTERFACE DET4X4
      MODULE PROCEDURE ONUMM7N2_det4x4
   END INTERFACE

   INTERFACE INV2X2
      MODULE PROCEDURE ONUMM7N2_INV2X2
   END INTERFACE

   INTERFACE INV3X3
      MODULE PROCEDURE ONUMM7N2_INV3X3
   END INTERFACE

   INTERFACE INV4X4
      MODULE PROCEDURE ONUMM7N2_INV4X4
   END INTERFACE

   INTERFACE GETIM
      MODULE PROCEDURE ONUMM7N2_GETIM_S,ONUMM7N2_GETIM_V,ONUMM7N2_GETIM_M
   END INTERFACE

   INTERFACE SETIM
      MODULE PROCEDURE ONUMM7N2_SETIM_S,ONUMM7N2_SETIM_V,ONUMM7N2_SETIM_M
   END INTERFACE

   CONTAINS

   ELEMENTAL SUBROUTINE ONUMM7N2_ASSIGN_R(RES,LHS)
      
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS 
      TYPE(ONUMM7N2), INTENT(OUT) :: RES 

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
      RES%E12 = 0.0_dp
      RES%E22 = 0.0_dp
      RES%E13 = 0.0_dp
      RES%E23 = 0.0_dp
      RES%E33 = 0.0_dp
      RES%E14 = 0.0_dp
      RES%E24 = 0.0_dp
      RES%E34 = 0.0_dp
      RES%E44 = 0.0_dp
      RES%E15 = 0.0_dp
      RES%E25 = 0.0_dp
      RES%E35 = 0.0_dp
      RES%E45 = 0.0_dp
      RES%E55 = 0.0_dp
      RES%E16 = 0.0_dp
      RES%E26 = 0.0_dp
      RES%E36 = 0.0_dp
      RES%E46 = 0.0_dp
      RES%E56 = 0.0_dp
      RES%E66 = 0.0_dp
      RES%E17 = 0.0_dp
      RES%E27 = 0.0_dp
      RES%E37 = 0.0_dp
      RES%E47 = 0.0_dp
      RES%E57 = 0.0_dp
      RES%E67 = 0.0_dp
      RES%E77 = 0.0_dp

   END SUBROUTINE ONUMM7N2_ASSIGN_R

   ELEMENTAL FUNCTION ONUMM7N2_NEG(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS 
      TYPE(ONUMM7N2) :: RES 

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
      RES%E12 = -LHS%E12
      RES%E22 = -LHS%E22
      RES%E13 = -LHS%E13
      RES%E23 = -LHS%E23
      RES%E33 = -LHS%E33
      RES%E14 = -LHS%E14
      RES%E24 = -LHS%E24
      RES%E34 = -LHS%E34
      RES%E44 = -LHS%E44
      RES%E15 = -LHS%E15
      RES%E25 = -LHS%E25
      RES%E35 = -LHS%E35
      RES%E45 = -LHS%E45
      RES%E55 = -LHS%E55
      RES%E16 = -LHS%E16
      RES%E26 = -LHS%E26
      RES%E36 = -LHS%E36
      RES%E46 = -LHS%E46
      RES%E56 = -LHS%E56
      RES%E66 = -LHS%E66
      RES%E17 = -LHS%E17
      RES%E27 = -LHS%E27
      RES%E37 = -LHS%E37
      RES%E47 = -LHS%E47
      RES%E57 = -LHS%E57
      RES%E67 = -LHS%E67
      RES%E77 = -LHS%E77

   END FUNCTION ONUMM7N2_NEG

   ELEMENTAL FUNCTION ONUMM7N2_ADD_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES 

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
      RES%E12 = LHS%E12 + RHS%E12
      RES%E22 = LHS%E22 + RHS%E22
      RES%E13 = LHS%E13 + RHS%E13
      RES%E23 = LHS%E23 + RHS%E23
      RES%E33 = LHS%E33 + RHS%E33
      RES%E14 = LHS%E14 + RHS%E14
      RES%E24 = LHS%E24 + RHS%E24
      RES%E34 = LHS%E34 + RHS%E34
      RES%E44 = LHS%E44 + RHS%E44
      RES%E15 = LHS%E15 + RHS%E15
      RES%E25 = LHS%E25 + RHS%E25
      RES%E35 = LHS%E35 + RHS%E35
      RES%E45 = LHS%E45 + RHS%E45
      RES%E55 = LHS%E55 + RHS%E55
      RES%E16 = LHS%E16 + RHS%E16
      RES%E26 = LHS%E26 + RHS%E26
      RES%E36 = LHS%E36 + RHS%E36
      RES%E46 = LHS%E46 + RHS%E46
      RES%E56 = LHS%E56 + RHS%E56
      RES%E66 = LHS%E66 + RHS%E66
      RES%E17 = LHS%E17 + RHS%E17
      RES%E27 = LHS%E27 + RHS%E27
      RES%E37 = LHS%E37 + RHS%E37
      RES%E47 = LHS%E47 + RHS%E47
      RES%E57 = LHS%E57 + RHS%E57
      RES%E67 = LHS%E67 + RHS%E67
      RES%E77 = LHS%E77 + RHS%E77

   END FUNCTION ONUMM7N2_ADD_OO_SS

   ELEMENTAL FUNCTION ONUMM7N2_ADD_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES 

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
      RES%E12 =  + RHS%E12
      RES%E22 =  + RHS%E22
      RES%E13 =  + RHS%E13
      RES%E23 =  + RHS%E23
      RES%E33 =  + RHS%E33
      RES%E14 =  + RHS%E14
      RES%E24 =  + RHS%E24
      RES%E34 =  + RHS%E34
      RES%E44 =  + RHS%E44
      RES%E15 =  + RHS%E15
      RES%E25 =  + RHS%E25
      RES%E35 =  + RHS%E35
      RES%E45 =  + RHS%E45
      RES%E55 =  + RHS%E55
      RES%E16 =  + RHS%E16
      RES%E26 =  + RHS%E26
      RES%E36 =  + RHS%E36
      RES%E46 =  + RHS%E46
      RES%E56 =  + RHS%E56
      RES%E66 =  + RHS%E66
      RES%E17 =  + RHS%E17
      RES%E27 =  + RHS%E27
      RES%E37 =  + RHS%E37
      RES%E47 =  + RHS%E47
      RES%E57 =  + RHS%E57
      RES%E67 =  + RHS%E67
      RES%E77 =  + RHS%E77

   END FUNCTION ONUMM7N2_ADD_RO_SS

   ELEMENTAL FUNCTION ONUMM7N2_ADD_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES 

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
      RES%E12 = LHS%E12
      RES%E22 = LHS%E22
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23
      RES%E33 = LHS%E33
      RES%E14 = LHS%E14
      RES%E24 = LHS%E24
      RES%E34 = LHS%E34
      RES%E44 = LHS%E44
      RES%E15 = LHS%E15
      RES%E25 = LHS%E25
      RES%E35 = LHS%E35
      RES%E45 = LHS%E45
      RES%E55 = LHS%E55
      RES%E16 = LHS%E16
      RES%E26 = LHS%E26
      RES%E36 = LHS%E36
      RES%E46 = LHS%E46
      RES%E56 = LHS%E56
      RES%E66 = LHS%E66
      RES%E17 = LHS%E17
      RES%E27 = LHS%E27
      RES%E37 = LHS%E37
      RES%E47 = LHS%E47
      RES%E57 = LHS%E57
      RES%E67 = LHS%E67
      RES%E77 = LHS%E77

   END FUNCTION ONUMM7N2_ADD_OR_SS

   ELEMENTAL FUNCTION ONUMM7N2_SUB_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES 

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
      RES%E12 = LHS%E12 - RHS%E12
      RES%E22 = LHS%E22 - RHS%E22
      RES%E13 = LHS%E13 - RHS%E13
      RES%E23 = LHS%E23 - RHS%E23
      RES%E33 = LHS%E33 - RHS%E33
      RES%E14 = LHS%E14 - RHS%E14
      RES%E24 = LHS%E24 - RHS%E24
      RES%E34 = LHS%E34 - RHS%E34
      RES%E44 = LHS%E44 - RHS%E44
      RES%E15 = LHS%E15 - RHS%E15
      RES%E25 = LHS%E25 - RHS%E25
      RES%E35 = LHS%E35 - RHS%E35
      RES%E45 = LHS%E45 - RHS%E45
      RES%E55 = LHS%E55 - RHS%E55
      RES%E16 = LHS%E16 - RHS%E16
      RES%E26 = LHS%E26 - RHS%E26
      RES%E36 = LHS%E36 - RHS%E36
      RES%E46 = LHS%E46 - RHS%E46
      RES%E56 = LHS%E56 - RHS%E56
      RES%E66 = LHS%E66 - RHS%E66
      RES%E17 = LHS%E17 - RHS%E17
      RES%E27 = LHS%E27 - RHS%E27
      RES%E37 = LHS%E37 - RHS%E37
      RES%E47 = LHS%E47 - RHS%E47
      RES%E57 = LHS%E57 - RHS%E57
      RES%E67 = LHS%E67 - RHS%E67
      RES%E77 = LHS%E77 - RHS%E77

   END FUNCTION ONUMM7N2_SUB_OO_SS

   ELEMENTAL FUNCTION ONUMM7N2_SUB_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES 

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
      RES%E12 =  - RHS%E12
      RES%E22 =  - RHS%E22
      RES%E13 =  - RHS%E13
      RES%E23 =  - RHS%E23
      RES%E33 =  - RHS%E33
      RES%E14 =  - RHS%E14
      RES%E24 =  - RHS%E24
      RES%E34 =  - RHS%E34
      RES%E44 =  - RHS%E44
      RES%E15 =  - RHS%E15
      RES%E25 =  - RHS%E25
      RES%E35 =  - RHS%E35
      RES%E45 =  - RHS%E45
      RES%E55 =  - RHS%E55
      RES%E16 =  - RHS%E16
      RES%E26 =  - RHS%E26
      RES%E36 =  - RHS%E36
      RES%E46 =  - RHS%E46
      RES%E56 =  - RHS%E56
      RES%E66 =  - RHS%E66
      RES%E17 =  - RHS%E17
      RES%E27 =  - RHS%E27
      RES%E37 =  - RHS%E37
      RES%E47 =  - RHS%E47
      RES%E57 =  - RHS%E57
      RES%E67 =  - RHS%E67
      RES%E77 =  - RHS%E77

   END FUNCTION ONUMM7N2_SUB_RO_SS

   ELEMENTAL FUNCTION ONUMM7N2_SUB_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES 

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
      RES%E12 = LHS%E12
      RES%E22 = LHS%E22
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23
      RES%E33 = LHS%E33
      RES%E14 = LHS%E14
      RES%E24 = LHS%E24
      RES%E34 = LHS%E34
      RES%E44 = LHS%E44
      RES%E15 = LHS%E15
      RES%E25 = LHS%E25
      RES%E35 = LHS%E35
      RES%E45 = LHS%E45
      RES%E55 = LHS%E55
      RES%E16 = LHS%E16
      RES%E26 = LHS%E26
      RES%E36 = LHS%E36
      RES%E46 = LHS%E46
      RES%E56 = LHS%E56
      RES%E66 = LHS%E66
      RES%E17 = LHS%E17
      RES%E27 = LHS%E27
      RES%E37 = LHS%E37
      RES%E47 = LHS%E47
      RES%E57 = LHS%E57
      RES%E67 = LHS%E67
      RES%E77 = LHS%E77

   END FUNCTION ONUMM7N2_SUB_OR_SS

   ELEMENTAL FUNCTION ONUMM7N2_MUL_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES 

      !  Multiplication like function 'LHS*RHS'
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      RES%E12 = LHS%R*RHS%E12 + LHS%E12*RHS%R +  &
             LHS%E1*RHS%E2 + LHS%E2*RHS%E1
      RES%E22 = LHS%R*RHS%E22 + LHS%E22*RHS%R + LHS%E2*RHS%E2
      RES%E13 = LHS%R*RHS%E13 + LHS%E13*RHS%R +  &
             LHS%E1*RHS%E3 + LHS%E3*RHS%E1
      RES%E23 = LHS%R*RHS%E23 + LHS%E23*RHS%R +  &
             LHS%E2*RHS%E3 + LHS%E3*RHS%E2
      RES%E33 = LHS%R*RHS%E33 + LHS%E33*RHS%R + LHS%E3*RHS%E3
      RES%E14 = LHS%R*RHS%E14 + LHS%E14*RHS%R +  &
             LHS%E1*RHS%E4 + LHS%E4*RHS%E1
      RES%E24 = LHS%R*RHS%E24 + LHS%E24*RHS%R +  &
             LHS%E2*RHS%E4 + LHS%E4*RHS%E2
      RES%E34 = LHS%R*RHS%E34 + LHS%E34*RHS%R +  &
             LHS%E3*RHS%E4 + LHS%E4*RHS%E3
      RES%E44 = LHS%R*RHS%E44 + LHS%E44*RHS%R + LHS%E4*RHS%E4
      RES%E15 = LHS%R*RHS%E15 + LHS%E15*RHS%R +  &
             LHS%E1*RHS%E5 + LHS%E5*RHS%E1
      RES%E25 = LHS%R*RHS%E25 + LHS%E25*RHS%R +  &
             LHS%E2*RHS%E5 + LHS%E5*RHS%E2
      RES%E35 = LHS%R*RHS%E35 + LHS%E35*RHS%R +  &
             LHS%E3*RHS%E5 + LHS%E5*RHS%E3
      RES%E45 = LHS%R*RHS%E45 + LHS%E45*RHS%R +  &
             LHS%E4*RHS%E5 + LHS%E5*RHS%E4
      RES%E55 = LHS%R*RHS%E55 + LHS%E55*RHS%R + LHS%E5*RHS%E5
      RES%E16 = LHS%R*RHS%E16 + LHS%E16*RHS%R +  &
             LHS%E1*RHS%E6 + LHS%E6*RHS%E1
      RES%E26 = LHS%R*RHS%E26 + LHS%E26*RHS%R +  &
             LHS%E2*RHS%E6 + LHS%E6*RHS%E2
      RES%E36 = LHS%R*RHS%E36 + LHS%E36*RHS%R +  &
             LHS%E3*RHS%E6 + LHS%E6*RHS%E3
      RES%E46 = LHS%R*RHS%E46 + LHS%E46*RHS%R +  &
             LHS%E4*RHS%E6 + LHS%E6*RHS%E4
      RES%E56 = LHS%R*RHS%E56 + LHS%E56*RHS%R +  &
             LHS%E5*RHS%E6 + LHS%E6*RHS%E5
      RES%E66 = LHS%R*RHS%E66 + LHS%E66*RHS%R + LHS%E6*RHS%E6
      RES%E17 = LHS%R*RHS%E17 + LHS%E17*RHS%R +  &
             LHS%E1*RHS%E7 + LHS%E7*RHS%E1
      RES%E27 = LHS%R*RHS%E27 + LHS%E27*RHS%R +  &
             LHS%E2*RHS%E7 + LHS%E7*RHS%E2
      RES%E37 = LHS%R*RHS%E37 + LHS%E37*RHS%R +  &
             LHS%E3*RHS%E7 + LHS%E7*RHS%E3
      RES%E47 = LHS%R*RHS%E47 + LHS%E47*RHS%R +  &
             LHS%E4*RHS%E7 + LHS%E7*RHS%E4
      RES%E57 = LHS%R*RHS%E57 + LHS%E57*RHS%R +  &
             LHS%E5*RHS%E7 + LHS%E7*RHS%E5
      RES%E67 = LHS%R*RHS%E67 + LHS%E67*RHS%R +  &
             LHS%E6*RHS%E7 + LHS%E7*RHS%E6
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

   END FUNCTION ONUMM7N2_MUL_OO_SS

   ELEMENTAL FUNCTION ONUMM7N2_MUL_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES 

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
      RES%E12 = LHS*RHS%E12
      RES%E22 = LHS*RHS%E22
      RES%E13 = LHS*RHS%E13
      RES%E23 = LHS*RHS%E23
      RES%E33 = LHS*RHS%E33
      RES%E14 = LHS*RHS%E14
      RES%E24 = LHS*RHS%E24
      RES%E34 = LHS*RHS%E34
      RES%E44 = LHS*RHS%E44
      RES%E15 = LHS*RHS%E15
      RES%E25 = LHS*RHS%E25
      RES%E35 = LHS*RHS%E35
      RES%E45 = LHS*RHS%E45
      RES%E55 = LHS*RHS%E55
      RES%E16 = LHS*RHS%E16
      RES%E26 = LHS*RHS%E26
      RES%E36 = LHS*RHS%E36
      RES%E46 = LHS*RHS%E46
      RES%E56 = LHS*RHS%E56
      RES%E66 = LHS*RHS%E66
      RES%E17 = LHS*RHS%E17
      RES%E27 = LHS*RHS%E27
      RES%E37 = LHS*RHS%E37
      RES%E47 = LHS*RHS%E47
      RES%E57 = LHS*RHS%E57
      RES%E67 = LHS*RHS%E67
      RES%E77 = LHS*RHS%E77

   END FUNCTION ONUMM7N2_MUL_RO_SS

   ELEMENTAL FUNCTION ONUMM7N2_MUL_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES 

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
      RES%E12 = LHS%E12*RHS
      RES%E22 = LHS%E22*RHS
      RES%E13 = LHS%E13*RHS
      RES%E23 = LHS%E23*RHS
      RES%E33 = LHS%E33*RHS
      RES%E14 = LHS%E14*RHS
      RES%E24 = LHS%E24*RHS
      RES%E34 = LHS%E34*RHS
      RES%E44 = LHS%E44*RHS
      RES%E15 = LHS%E15*RHS
      RES%E25 = LHS%E25*RHS
      RES%E35 = LHS%E35*RHS
      RES%E45 = LHS%E45*RHS
      RES%E55 = LHS%E55*RHS
      RES%E16 = LHS%E16*RHS
      RES%E26 = LHS%E26*RHS
      RES%E36 = LHS%E36*RHS
      RES%E46 = LHS%E46*RHS
      RES%E56 = LHS%E56*RHS
      RES%E66 = LHS%E66*RHS
      RES%E17 = LHS%E17*RHS
      RES%E27 = LHS%E27*RHS
      RES%E37 = LHS%E37*RHS
      RES%E47 = LHS%E47*RHS
      RES%E57 = LHS%E57*RHS
      RES%E67 = LHS%E67*RHS
      RES%E77 = LHS%E77*RHS

   END FUNCTION ONUMM7N2_MUL_OR_SS

   FUNCTION ONUMM7N2_ADD_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:)
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1)) 

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
      RES%E12 = LHS%E12 + RHS%E12
      RES%E22 = LHS%E22 + RHS%E22
      RES%E13 = LHS%E13 + RHS%E13
      RES%E23 = LHS%E23 + RHS%E23
      RES%E33 = LHS%E33 + RHS%E33
      RES%E14 = LHS%E14 + RHS%E14
      RES%E24 = LHS%E24 + RHS%E24
      RES%E34 = LHS%E34 + RHS%E34
      RES%E44 = LHS%E44 + RHS%E44
      RES%E15 = LHS%E15 + RHS%E15
      RES%E25 = LHS%E25 + RHS%E25
      RES%E35 = LHS%E35 + RHS%E35
      RES%E45 = LHS%E45 + RHS%E45
      RES%E55 = LHS%E55 + RHS%E55
      RES%E16 = LHS%E16 + RHS%E16
      RES%E26 = LHS%E26 + RHS%E26
      RES%E36 = LHS%E36 + RHS%E36
      RES%E46 = LHS%E46 + RHS%E46
      RES%E56 = LHS%E56 + RHS%E56
      RES%E66 = LHS%E66 + RHS%E66
      RES%E17 = LHS%E17 + RHS%E17
      RES%E27 = LHS%E27 + RHS%E27
      RES%E37 = LHS%E37 + RHS%E37
      RES%E47 = LHS%E47 + RHS%E47
      RES%E57 = LHS%E57 + RHS%E57
      RES%E67 = LHS%E67 + RHS%E67
      RES%E77 = LHS%E77 + RHS%E77

   END FUNCTION ONUMM7N2_ADD_OO_VS

   FUNCTION ONUMM7N2_ADD_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1)) 

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
      RES%E12 =  + RHS%E12
      RES%E22 =  + RHS%E22
      RES%E13 =  + RHS%E13
      RES%E23 =  + RHS%E23
      RES%E33 =  + RHS%E33
      RES%E14 =  + RHS%E14
      RES%E24 =  + RHS%E24
      RES%E34 =  + RHS%E34
      RES%E44 =  + RHS%E44
      RES%E15 =  + RHS%E15
      RES%E25 =  + RHS%E25
      RES%E35 =  + RHS%E35
      RES%E45 =  + RHS%E45
      RES%E55 =  + RHS%E55
      RES%E16 =  + RHS%E16
      RES%E26 =  + RHS%E26
      RES%E36 =  + RHS%E36
      RES%E46 =  + RHS%E46
      RES%E56 =  + RHS%E56
      RES%E66 =  + RHS%E66
      RES%E17 =  + RHS%E17
      RES%E27 =  + RHS%E27
      RES%E37 =  + RHS%E37
      RES%E47 =  + RHS%E47
      RES%E57 =  + RHS%E57
      RES%E67 =  + RHS%E67
      RES%E77 =  + RHS%E77

   END FUNCTION ONUMM7N2_ADD_RO_VS

   FUNCTION ONUMM7N2_ADD_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1)) 

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
      RES%E12 = LHS%E12
      RES%E22 = LHS%E22
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23
      RES%E33 = LHS%E33
      RES%E14 = LHS%E14
      RES%E24 = LHS%E24
      RES%E34 = LHS%E34
      RES%E44 = LHS%E44
      RES%E15 = LHS%E15
      RES%E25 = LHS%E25
      RES%E35 = LHS%E35
      RES%E45 = LHS%E45
      RES%E55 = LHS%E55
      RES%E16 = LHS%E16
      RES%E26 = LHS%E26
      RES%E36 = LHS%E36
      RES%E46 = LHS%E46
      RES%E56 = LHS%E56
      RES%E66 = LHS%E66
      RES%E17 = LHS%E17
      RES%E27 = LHS%E27
      RES%E37 = LHS%E37
      RES%E47 = LHS%E47
      RES%E57 = LHS%E57
      RES%E67 = LHS%E67
      RES%E77 = LHS%E77

   END FUNCTION ONUMM7N2_ADD_OR_VS

   FUNCTION ONUMM7N2_SUB_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:)
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1)) 

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
      RES%E12 = LHS%E12 - RHS%E12
      RES%E22 = LHS%E22 - RHS%E22
      RES%E13 = LHS%E13 - RHS%E13
      RES%E23 = LHS%E23 - RHS%E23
      RES%E33 = LHS%E33 - RHS%E33
      RES%E14 = LHS%E14 - RHS%E14
      RES%E24 = LHS%E24 - RHS%E24
      RES%E34 = LHS%E34 - RHS%E34
      RES%E44 = LHS%E44 - RHS%E44
      RES%E15 = LHS%E15 - RHS%E15
      RES%E25 = LHS%E25 - RHS%E25
      RES%E35 = LHS%E35 - RHS%E35
      RES%E45 = LHS%E45 - RHS%E45
      RES%E55 = LHS%E55 - RHS%E55
      RES%E16 = LHS%E16 - RHS%E16
      RES%E26 = LHS%E26 - RHS%E26
      RES%E36 = LHS%E36 - RHS%E36
      RES%E46 = LHS%E46 - RHS%E46
      RES%E56 = LHS%E56 - RHS%E56
      RES%E66 = LHS%E66 - RHS%E66
      RES%E17 = LHS%E17 - RHS%E17
      RES%E27 = LHS%E27 - RHS%E27
      RES%E37 = LHS%E37 - RHS%E37
      RES%E47 = LHS%E47 - RHS%E47
      RES%E57 = LHS%E57 - RHS%E57
      RES%E67 = LHS%E67 - RHS%E67
      RES%E77 = LHS%E77 - RHS%E77

   END FUNCTION ONUMM7N2_SUB_OO_VS

   FUNCTION ONUMM7N2_SUB_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1)) 

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
      RES%E12 =  - RHS%E12
      RES%E22 =  - RHS%E22
      RES%E13 =  - RHS%E13
      RES%E23 =  - RHS%E23
      RES%E33 =  - RHS%E33
      RES%E14 =  - RHS%E14
      RES%E24 =  - RHS%E24
      RES%E34 =  - RHS%E34
      RES%E44 =  - RHS%E44
      RES%E15 =  - RHS%E15
      RES%E25 =  - RHS%E25
      RES%E35 =  - RHS%E35
      RES%E45 =  - RHS%E45
      RES%E55 =  - RHS%E55
      RES%E16 =  - RHS%E16
      RES%E26 =  - RHS%E26
      RES%E36 =  - RHS%E36
      RES%E46 =  - RHS%E46
      RES%E56 =  - RHS%E56
      RES%E66 =  - RHS%E66
      RES%E17 =  - RHS%E17
      RES%E27 =  - RHS%E27
      RES%E37 =  - RHS%E37
      RES%E47 =  - RHS%E47
      RES%E57 =  - RHS%E57
      RES%E67 =  - RHS%E67
      RES%E77 =  - RHS%E77

   END FUNCTION ONUMM7N2_SUB_RO_VS

   FUNCTION ONUMM7N2_SUB_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1)) 

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
      RES%E12 = LHS%E12
      RES%E22 = LHS%E22
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23
      RES%E33 = LHS%E33
      RES%E14 = LHS%E14
      RES%E24 = LHS%E24
      RES%E34 = LHS%E34
      RES%E44 = LHS%E44
      RES%E15 = LHS%E15
      RES%E25 = LHS%E25
      RES%E35 = LHS%E35
      RES%E45 = LHS%E45
      RES%E55 = LHS%E55
      RES%E16 = LHS%E16
      RES%E26 = LHS%E26
      RES%E36 = LHS%E36
      RES%E46 = LHS%E46
      RES%E56 = LHS%E56
      RES%E66 = LHS%E66
      RES%E17 = LHS%E17
      RES%E27 = LHS%E27
      RES%E37 = LHS%E37
      RES%E47 = LHS%E47
      RES%E57 = LHS%E57
      RES%E67 = LHS%E67
      RES%E77 = LHS%E77

   END FUNCTION ONUMM7N2_SUB_OR_VS

   FUNCTION ONUMM7N2_MUL_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:)
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      RES%E12 = LHS%R*RHS%E12 + LHS%E12*RHS%R +  &
             LHS%E1*RHS%E2 + LHS%E2*RHS%E1
      RES%E22 = LHS%R*RHS%E22 + LHS%E22*RHS%R + LHS%E2*RHS%E2
      RES%E13 = LHS%R*RHS%E13 + LHS%E13*RHS%R +  &
             LHS%E1*RHS%E3 + LHS%E3*RHS%E1
      RES%E23 = LHS%R*RHS%E23 + LHS%E23*RHS%R +  &
             LHS%E2*RHS%E3 + LHS%E3*RHS%E2
      RES%E33 = LHS%R*RHS%E33 + LHS%E33*RHS%R + LHS%E3*RHS%E3
      RES%E14 = LHS%R*RHS%E14 + LHS%E14*RHS%R +  &
             LHS%E1*RHS%E4 + LHS%E4*RHS%E1
      RES%E24 = LHS%R*RHS%E24 + LHS%E24*RHS%R +  &
             LHS%E2*RHS%E4 + LHS%E4*RHS%E2
      RES%E34 = LHS%R*RHS%E34 + LHS%E34*RHS%R +  &
             LHS%E3*RHS%E4 + LHS%E4*RHS%E3
      RES%E44 = LHS%R*RHS%E44 + LHS%E44*RHS%R + LHS%E4*RHS%E4
      RES%E15 = LHS%R*RHS%E15 + LHS%E15*RHS%R +  &
             LHS%E1*RHS%E5 + LHS%E5*RHS%E1
      RES%E25 = LHS%R*RHS%E25 + LHS%E25*RHS%R +  &
             LHS%E2*RHS%E5 + LHS%E5*RHS%E2
      RES%E35 = LHS%R*RHS%E35 + LHS%E35*RHS%R +  &
             LHS%E3*RHS%E5 + LHS%E5*RHS%E3
      RES%E45 = LHS%R*RHS%E45 + LHS%E45*RHS%R +  &
             LHS%E4*RHS%E5 + LHS%E5*RHS%E4
      RES%E55 = LHS%R*RHS%E55 + LHS%E55*RHS%R + LHS%E5*RHS%E5
      RES%E16 = LHS%R*RHS%E16 + LHS%E16*RHS%R +  &
             LHS%E1*RHS%E6 + LHS%E6*RHS%E1
      RES%E26 = LHS%R*RHS%E26 + LHS%E26*RHS%R +  &
             LHS%E2*RHS%E6 + LHS%E6*RHS%E2
      RES%E36 = LHS%R*RHS%E36 + LHS%E36*RHS%R +  &
             LHS%E3*RHS%E6 + LHS%E6*RHS%E3
      RES%E46 = LHS%R*RHS%E46 + LHS%E46*RHS%R +  &
             LHS%E4*RHS%E6 + LHS%E6*RHS%E4
      RES%E56 = LHS%R*RHS%E56 + LHS%E56*RHS%R +  &
             LHS%E5*RHS%E6 + LHS%E6*RHS%E5
      RES%E66 = LHS%R*RHS%E66 + LHS%E66*RHS%R + LHS%E6*RHS%E6
      RES%E17 = LHS%R*RHS%E17 + LHS%E17*RHS%R +  &
             LHS%E1*RHS%E7 + LHS%E7*RHS%E1
      RES%E27 = LHS%R*RHS%E27 + LHS%E27*RHS%R +  &
             LHS%E2*RHS%E7 + LHS%E7*RHS%E2
      RES%E37 = LHS%R*RHS%E37 + LHS%E37*RHS%R +  &
             LHS%E3*RHS%E7 + LHS%E7*RHS%E3
      RES%E47 = LHS%R*RHS%E47 + LHS%E47*RHS%R +  &
             LHS%E4*RHS%E7 + LHS%E7*RHS%E4
      RES%E57 = LHS%R*RHS%E57 + LHS%E57*RHS%R +  &
             LHS%E5*RHS%E7 + LHS%E7*RHS%E5
      RES%E67 = LHS%R*RHS%E67 + LHS%E67*RHS%R +  &
             LHS%E6*RHS%E7 + LHS%E7*RHS%E6
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

   END FUNCTION ONUMM7N2_MUL_OO_VS

   FUNCTION ONUMM7N2_MUL_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1)) 

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
      RES%E12 = LHS*RHS%E12
      RES%E22 = LHS*RHS%E22
      RES%E13 = LHS*RHS%E13
      RES%E23 = LHS*RHS%E23
      RES%E33 = LHS*RHS%E33
      RES%E14 = LHS*RHS%E14
      RES%E24 = LHS*RHS%E24
      RES%E34 = LHS*RHS%E34
      RES%E44 = LHS*RHS%E44
      RES%E15 = LHS*RHS%E15
      RES%E25 = LHS*RHS%E25
      RES%E35 = LHS*RHS%E35
      RES%E45 = LHS*RHS%E45
      RES%E55 = LHS*RHS%E55
      RES%E16 = LHS*RHS%E16
      RES%E26 = LHS*RHS%E26
      RES%E36 = LHS*RHS%E36
      RES%E46 = LHS*RHS%E46
      RES%E56 = LHS*RHS%E56
      RES%E66 = LHS*RHS%E66
      RES%E17 = LHS*RHS%E17
      RES%E27 = LHS*RHS%E27
      RES%E37 = LHS*RHS%E37
      RES%E47 = LHS*RHS%E47
      RES%E57 = LHS*RHS%E57
      RES%E67 = LHS*RHS%E67
      RES%E77 = LHS*RHS%E77

   END FUNCTION ONUMM7N2_MUL_RO_VS

   FUNCTION ONUMM7N2_MUL_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1)) 

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
      RES%E12 = LHS%E12*RHS
      RES%E22 = LHS%E22*RHS
      RES%E13 = LHS%E13*RHS
      RES%E23 = LHS%E23*RHS
      RES%E33 = LHS%E33*RHS
      RES%E14 = LHS%E14*RHS
      RES%E24 = LHS%E24*RHS
      RES%E34 = LHS%E34*RHS
      RES%E44 = LHS%E44*RHS
      RES%E15 = LHS%E15*RHS
      RES%E25 = LHS%E25*RHS
      RES%E35 = LHS%E35*RHS
      RES%E45 = LHS%E45*RHS
      RES%E55 = LHS%E55*RHS
      RES%E16 = LHS%E16*RHS
      RES%E26 = LHS%E26*RHS
      RES%E36 = LHS%E36*RHS
      RES%E46 = LHS%E46*RHS
      RES%E56 = LHS%E56*RHS
      RES%E66 = LHS%E66*RHS
      RES%E17 = LHS%E17*RHS
      RES%E27 = LHS%E27*RHS
      RES%E37 = LHS%E37*RHS
      RES%E47 = LHS%E47*RHS
      RES%E57 = LHS%E57*RHS
      RES%E67 = LHS%E67*RHS
      RES%E77 = LHS%E77*RHS

   END FUNCTION ONUMM7N2_MUL_OR_VS

   FUNCTION ONUMM7N2_ADD_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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
      RES%E12 = LHS%E12 + RHS%E12
      RES%E22 = LHS%E22 + RHS%E22
      RES%E13 = LHS%E13 + RHS%E13
      RES%E23 = LHS%E23 + RHS%E23
      RES%E33 = LHS%E33 + RHS%E33
      RES%E14 = LHS%E14 + RHS%E14
      RES%E24 = LHS%E24 + RHS%E24
      RES%E34 = LHS%E34 + RHS%E34
      RES%E44 = LHS%E44 + RHS%E44
      RES%E15 = LHS%E15 + RHS%E15
      RES%E25 = LHS%E25 + RHS%E25
      RES%E35 = LHS%E35 + RHS%E35
      RES%E45 = LHS%E45 + RHS%E45
      RES%E55 = LHS%E55 + RHS%E55
      RES%E16 = LHS%E16 + RHS%E16
      RES%E26 = LHS%E26 + RHS%E26
      RES%E36 = LHS%E36 + RHS%E36
      RES%E46 = LHS%E46 + RHS%E46
      RES%E56 = LHS%E56 + RHS%E56
      RES%E66 = LHS%E66 + RHS%E66
      RES%E17 = LHS%E17 + RHS%E17
      RES%E27 = LHS%E27 + RHS%E27
      RES%E37 = LHS%E37 + RHS%E37
      RES%E47 = LHS%E47 + RHS%E47
      RES%E57 = LHS%E57 + RHS%E57
      RES%E67 = LHS%E67 + RHS%E67
      RES%E77 = LHS%E77 + RHS%E77

   END FUNCTION ONUMM7N2_ADD_OO_MS

   FUNCTION ONUMM7N2_ADD_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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
      RES%E12 =  + RHS%E12
      RES%E22 =  + RHS%E22
      RES%E13 =  + RHS%E13
      RES%E23 =  + RHS%E23
      RES%E33 =  + RHS%E33
      RES%E14 =  + RHS%E14
      RES%E24 =  + RHS%E24
      RES%E34 =  + RHS%E34
      RES%E44 =  + RHS%E44
      RES%E15 =  + RHS%E15
      RES%E25 =  + RHS%E25
      RES%E35 =  + RHS%E35
      RES%E45 =  + RHS%E45
      RES%E55 =  + RHS%E55
      RES%E16 =  + RHS%E16
      RES%E26 =  + RHS%E26
      RES%E36 =  + RHS%E36
      RES%E46 =  + RHS%E46
      RES%E56 =  + RHS%E56
      RES%E66 =  + RHS%E66
      RES%E17 =  + RHS%E17
      RES%E27 =  + RHS%E27
      RES%E37 =  + RHS%E37
      RES%E47 =  + RHS%E47
      RES%E57 =  + RHS%E57
      RES%E67 =  + RHS%E67
      RES%E77 =  + RHS%E77

   END FUNCTION ONUMM7N2_ADD_RO_MS

   FUNCTION ONUMM7N2_ADD_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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
      RES%E12 = LHS%E12
      RES%E22 = LHS%E22
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23
      RES%E33 = LHS%E33
      RES%E14 = LHS%E14
      RES%E24 = LHS%E24
      RES%E34 = LHS%E34
      RES%E44 = LHS%E44
      RES%E15 = LHS%E15
      RES%E25 = LHS%E25
      RES%E35 = LHS%E35
      RES%E45 = LHS%E45
      RES%E55 = LHS%E55
      RES%E16 = LHS%E16
      RES%E26 = LHS%E26
      RES%E36 = LHS%E36
      RES%E46 = LHS%E46
      RES%E56 = LHS%E56
      RES%E66 = LHS%E66
      RES%E17 = LHS%E17
      RES%E27 = LHS%E27
      RES%E37 = LHS%E37
      RES%E47 = LHS%E47
      RES%E57 = LHS%E57
      RES%E67 = LHS%E67
      RES%E77 = LHS%E77

   END FUNCTION ONUMM7N2_ADD_OR_MS

   FUNCTION ONUMM7N2_SUB_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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
      RES%E12 = LHS%E12 - RHS%E12
      RES%E22 = LHS%E22 - RHS%E22
      RES%E13 = LHS%E13 - RHS%E13
      RES%E23 = LHS%E23 - RHS%E23
      RES%E33 = LHS%E33 - RHS%E33
      RES%E14 = LHS%E14 - RHS%E14
      RES%E24 = LHS%E24 - RHS%E24
      RES%E34 = LHS%E34 - RHS%E34
      RES%E44 = LHS%E44 - RHS%E44
      RES%E15 = LHS%E15 - RHS%E15
      RES%E25 = LHS%E25 - RHS%E25
      RES%E35 = LHS%E35 - RHS%E35
      RES%E45 = LHS%E45 - RHS%E45
      RES%E55 = LHS%E55 - RHS%E55
      RES%E16 = LHS%E16 - RHS%E16
      RES%E26 = LHS%E26 - RHS%E26
      RES%E36 = LHS%E36 - RHS%E36
      RES%E46 = LHS%E46 - RHS%E46
      RES%E56 = LHS%E56 - RHS%E56
      RES%E66 = LHS%E66 - RHS%E66
      RES%E17 = LHS%E17 - RHS%E17
      RES%E27 = LHS%E27 - RHS%E27
      RES%E37 = LHS%E37 - RHS%E37
      RES%E47 = LHS%E47 - RHS%E47
      RES%E57 = LHS%E57 - RHS%E57
      RES%E67 = LHS%E67 - RHS%E67
      RES%E77 = LHS%E77 - RHS%E77

   END FUNCTION ONUMM7N2_SUB_OO_MS

   FUNCTION ONUMM7N2_SUB_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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
      RES%E12 =  - RHS%E12
      RES%E22 =  - RHS%E22
      RES%E13 =  - RHS%E13
      RES%E23 =  - RHS%E23
      RES%E33 =  - RHS%E33
      RES%E14 =  - RHS%E14
      RES%E24 =  - RHS%E24
      RES%E34 =  - RHS%E34
      RES%E44 =  - RHS%E44
      RES%E15 =  - RHS%E15
      RES%E25 =  - RHS%E25
      RES%E35 =  - RHS%E35
      RES%E45 =  - RHS%E45
      RES%E55 =  - RHS%E55
      RES%E16 =  - RHS%E16
      RES%E26 =  - RHS%E26
      RES%E36 =  - RHS%E36
      RES%E46 =  - RHS%E46
      RES%E56 =  - RHS%E56
      RES%E66 =  - RHS%E66
      RES%E17 =  - RHS%E17
      RES%E27 =  - RHS%E27
      RES%E37 =  - RHS%E37
      RES%E47 =  - RHS%E47
      RES%E57 =  - RHS%E57
      RES%E67 =  - RHS%E67
      RES%E77 =  - RHS%E77

   END FUNCTION ONUMM7N2_SUB_RO_MS

   FUNCTION ONUMM7N2_SUB_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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
      RES%E12 = LHS%E12
      RES%E22 = LHS%E22
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23
      RES%E33 = LHS%E33
      RES%E14 = LHS%E14
      RES%E24 = LHS%E24
      RES%E34 = LHS%E34
      RES%E44 = LHS%E44
      RES%E15 = LHS%E15
      RES%E25 = LHS%E25
      RES%E35 = LHS%E35
      RES%E45 = LHS%E45
      RES%E55 = LHS%E55
      RES%E16 = LHS%E16
      RES%E26 = LHS%E26
      RES%E36 = LHS%E36
      RES%E46 = LHS%E46
      RES%E56 = LHS%E56
      RES%E66 = LHS%E66
      RES%E17 = LHS%E17
      RES%E27 = LHS%E27
      RES%E37 = LHS%E37
      RES%E47 = LHS%E47
      RES%E57 = LHS%E57
      RES%E67 = LHS%E67
      RES%E77 = LHS%E77

   END FUNCTION ONUMM7N2_SUB_OR_MS

   FUNCTION ONUMM7N2_MUL_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      RES%E12 = LHS%R*RHS%E12 + LHS%E12*RHS%R +  &
             LHS%E1*RHS%E2 + LHS%E2*RHS%E1
      RES%E22 = LHS%R*RHS%E22 + LHS%E22*RHS%R + LHS%E2*RHS%E2
      RES%E13 = LHS%R*RHS%E13 + LHS%E13*RHS%R +  &
             LHS%E1*RHS%E3 + LHS%E3*RHS%E1
      RES%E23 = LHS%R*RHS%E23 + LHS%E23*RHS%R +  &
             LHS%E2*RHS%E3 + LHS%E3*RHS%E2
      RES%E33 = LHS%R*RHS%E33 + LHS%E33*RHS%R + LHS%E3*RHS%E3
      RES%E14 = LHS%R*RHS%E14 + LHS%E14*RHS%R +  &
             LHS%E1*RHS%E4 + LHS%E4*RHS%E1
      RES%E24 = LHS%R*RHS%E24 + LHS%E24*RHS%R +  &
             LHS%E2*RHS%E4 + LHS%E4*RHS%E2
      RES%E34 = LHS%R*RHS%E34 + LHS%E34*RHS%R +  &
             LHS%E3*RHS%E4 + LHS%E4*RHS%E3
      RES%E44 = LHS%R*RHS%E44 + LHS%E44*RHS%R + LHS%E4*RHS%E4
      RES%E15 = LHS%R*RHS%E15 + LHS%E15*RHS%R +  &
             LHS%E1*RHS%E5 + LHS%E5*RHS%E1
      RES%E25 = LHS%R*RHS%E25 + LHS%E25*RHS%R +  &
             LHS%E2*RHS%E5 + LHS%E5*RHS%E2
      RES%E35 = LHS%R*RHS%E35 + LHS%E35*RHS%R +  &
             LHS%E3*RHS%E5 + LHS%E5*RHS%E3
      RES%E45 = LHS%R*RHS%E45 + LHS%E45*RHS%R +  &
             LHS%E4*RHS%E5 + LHS%E5*RHS%E4
      RES%E55 = LHS%R*RHS%E55 + LHS%E55*RHS%R + LHS%E5*RHS%E5
      RES%E16 = LHS%R*RHS%E16 + LHS%E16*RHS%R +  &
             LHS%E1*RHS%E6 + LHS%E6*RHS%E1
      RES%E26 = LHS%R*RHS%E26 + LHS%E26*RHS%R +  &
             LHS%E2*RHS%E6 + LHS%E6*RHS%E2
      RES%E36 = LHS%R*RHS%E36 + LHS%E36*RHS%R +  &
             LHS%E3*RHS%E6 + LHS%E6*RHS%E3
      RES%E46 = LHS%R*RHS%E46 + LHS%E46*RHS%R +  &
             LHS%E4*RHS%E6 + LHS%E6*RHS%E4
      RES%E56 = LHS%R*RHS%E56 + LHS%E56*RHS%R +  &
             LHS%E5*RHS%E6 + LHS%E6*RHS%E5
      RES%E66 = LHS%R*RHS%E66 + LHS%E66*RHS%R + LHS%E6*RHS%E6
      RES%E17 = LHS%R*RHS%E17 + LHS%E17*RHS%R +  &
             LHS%E1*RHS%E7 + LHS%E7*RHS%E1
      RES%E27 = LHS%R*RHS%E27 + LHS%E27*RHS%R +  &
             LHS%E2*RHS%E7 + LHS%E7*RHS%E2
      RES%E37 = LHS%R*RHS%E37 + LHS%E37*RHS%R +  &
             LHS%E3*RHS%E7 + LHS%E7*RHS%E3
      RES%E47 = LHS%R*RHS%E47 + LHS%E47*RHS%R +  &
             LHS%E4*RHS%E7 + LHS%E7*RHS%E4
      RES%E57 = LHS%R*RHS%E57 + LHS%E57*RHS%R +  &
             LHS%E5*RHS%E7 + LHS%E7*RHS%E5
      RES%E67 = LHS%R*RHS%E67 + LHS%E67*RHS%R +  &
             LHS%E6*RHS%E7 + LHS%E7*RHS%E6
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

   END FUNCTION ONUMM7N2_MUL_OO_MS

   FUNCTION ONUMM7N2_MUL_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N2), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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
      RES%E12 = LHS*RHS%E12
      RES%E22 = LHS*RHS%E22
      RES%E13 = LHS*RHS%E13
      RES%E23 = LHS*RHS%E23
      RES%E33 = LHS*RHS%E33
      RES%E14 = LHS*RHS%E14
      RES%E24 = LHS*RHS%E24
      RES%E34 = LHS*RHS%E34
      RES%E44 = LHS*RHS%E44
      RES%E15 = LHS*RHS%E15
      RES%E25 = LHS*RHS%E25
      RES%E35 = LHS*RHS%E35
      RES%E45 = LHS*RHS%E45
      RES%E55 = LHS*RHS%E55
      RES%E16 = LHS*RHS%E16
      RES%E26 = LHS*RHS%E26
      RES%E36 = LHS*RHS%E36
      RES%E46 = LHS*RHS%E46
      RES%E56 = LHS*RHS%E56
      RES%E66 = LHS*RHS%E66
      RES%E17 = LHS*RHS%E17
      RES%E27 = LHS*RHS%E27
      RES%E37 = LHS*RHS%E37
      RES%E47 = LHS*RHS%E47
      RES%E57 = LHS*RHS%E57
      RES%E67 = LHS*RHS%E67
      RES%E77 = LHS*RHS%E77

   END FUNCTION ONUMM7N2_MUL_RO_MS

   FUNCTION ONUMM7N2_MUL_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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
      RES%E12 = LHS%E12*RHS
      RES%E22 = LHS%E22*RHS
      RES%E13 = LHS%E13*RHS
      RES%E23 = LHS%E23*RHS
      RES%E33 = LHS%E33*RHS
      RES%E14 = LHS%E14*RHS
      RES%E24 = LHS%E24*RHS
      RES%E34 = LHS%E34*RHS
      RES%E44 = LHS%E44*RHS
      RES%E15 = LHS%E15*RHS
      RES%E25 = LHS%E25*RHS
      RES%E35 = LHS%E35*RHS
      RES%E45 = LHS%E45*RHS
      RES%E55 = LHS%E55*RHS
      RES%E16 = LHS%E16*RHS
      RES%E26 = LHS%E26*RHS
      RES%E36 = LHS%E36*RHS
      RES%E46 = LHS%E46*RHS
      RES%E56 = LHS%E56*RHS
      RES%E66 = LHS%E66*RHS
      RES%E17 = LHS%E17*RHS
      RES%E27 = LHS%E27*RHS
      RES%E37 = LHS%E37*RHS
      RES%E47 = LHS%E47*RHS
      RES%E57 = LHS%E57*RHS
      RES%E67 = LHS%E67*RHS
      RES%E77 = LHS%E77*RHS

   END FUNCTION ONUMM7N2_MUL_OR_MS

   FUNCTION ONUMM7N2_ADD_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1)) 

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
      RES%E12 = LHS%E12 + RHS%E12
      RES%E22 = LHS%E22 + RHS%E22
      RES%E13 = LHS%E13 + RHS%E13
      RES%E23 = LHS%E23 + RHS%E23
      RES%E33 = LHS%E33 + RHS%E33
      RES%E14 = LHS%E14 + RHS%E14
      RES%E24 = LHS%E24 + RHS%E24
      RES%E34 = LHS%E34 + RHS%E34
      RES%E44 = LHS%E44 + RHS%E44
      RES%E15 = LHS%E15 + RHS%E15
      RES%E25 = LHS%E25 + RHS%E25
      RES%E35 = LHS%E35 + RHS%E35
      RES%E45 = LHS%E45 + RHS%E45
      RES%E55 = LHS%E55 + RHS%E55
      RES%E16 = LHS%E16 + RHS%E16
      RES%E26 = LHS%E26 + RHS%E26
      RES%E36 = LHS%E36 + RHS%E36
      RES%E46 = LHS%E46 + RHS%E46
      RES%E56 = LHS%E56 + RHS%E56
      RES%E66 = LHS%E66 + RHS%E66
      RES%E17 = LHS%E17 + RHS%E17
      RES%E27 = LHS%E27 + RHS%E27
      RES%E37 = LHS%E37 + RHS%E37
      RES%E47 = LHS%E47 + RHS%E47
      RES%E57 = LHS%E57 + RHS%E57
      RES%E67 = LHS%E67 + RHS%E67
      RES%E77 = LHS%E77 + RHS%E77

   END FUNCTION ONUMM7N2_ADD_OO_SV

   FUNCTION ONUMM7N2_ADD_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1)) 

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
      RES%E12 =  + RHS%E12
      RES%E22 =  + RHS%E22
      RES%E13 =  + RHS%E13
      RES%E23 =  + RHS%E23
      RES%E33 =  + RHS%E33
      RES%E14 =  + RHS%E14
      RES%E24 =  + RHS%E24
      RES%E34 =  + RHS%E34
      RES%E44 =  + RHS%E44
      RES%E15 =  + RHS%E15
      RES%E25 =  + RHS%E25
      RES%E35 =  + RHS%E35
      RES%E45 =  + RHS%E45
      RES%E55 =  + RHS%E55
      RES%E16 =  + RHS%E16
      RES%E26 =  + RHS%E26
      RES%E36 =  + RHS%E36
      RES%E46 =  + RHS%E46
      RES%E56 =  + RHS%E56
      RES%E66 =  + RHS%E66
      RES%E17 =  + RHS%E17
      RES%E27 =  + RHS%E27
      RES%E37 =  + RHS%E37
      RES%E47 =  + RHS%E47
      RES%E57 =  + RHS%E57
      RES%E67 =  + RHS%E67
      RES%E77 =  + RHS%E77

   END FUNCTION ONUMM7N2_ADD_RO_SV

   FUNCTION ONUMM7N2_ADD_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1)) 

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
      RES%E12 = LHS%E12
      RES%E22 = LHS%E22
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23
      RES%E33 = LHS%E33
      RES%E14 = LHS%E14
      RES%E24 = LHS%E24
      RES%E34 = LHS%E34
      RES%E44 = LHS%E44
      RES%E15 = LHS%E15
      RES%E25 = LHS%E25
      RES%E35 = LHS%E35
      RES%E45 = LHS%E45
      RES%E55 = LHS%E55
      RES%E16 = LHS%E16
      RES%E26 = LHS%E26
      RES%E36 = LHS%E36
      RES%E46 = LHS%E46
      RES%E56 = LHS%E56
      RES%E66 = LHS%E66
      RES%E17 = LHS%E17
      RES%E27 = LHS%E27
      RES%E37 = LHS%E37
      RES%E47 = LHS%E47
      RES%E57 = LHS%E57
      RES%E67 = LHS%E67
      RES%E77 = LHS%E77

   END FUNCTION ONUMM7N2_ADD_OR_SV

   FUNCTION ONUMM7N2_SUB_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1)) 

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
      RES%E12 = LHS%E12 - RHS%E12
      RES%E22 = LHS%E22 - RHS%E22
      RES%E13 = LHS%E13 - RHS%E13
      RES%E23 = LHS%E23 - RHS%E23
      RES%E33 = LHS%E33 - RHS%E33
      RES%E14 = LHS%E14 - RHS%E14
      RES%E24 = LHS%E24 - RHS%E24
      RES%E34 = LHS%E34 - RHS%E34
      RES%E44 = LHS%E44 - RHS%E44
      RES%E15 = LHS%E15 - RHS%E15
      RES%E25 = LHS%E25 - RHS%E25
      RES%E35 = LHS%E35 - RHS%E35
      RES%E45 = LHS%E45 - RHS%E45
      RES%E55 = LHS%E55 - RHS%E55
      RES%E16 = LHS%E16 - RHS%E16
      RES%E26 = LHS%E26 - RHS%E26
      RES%E36 = LHS%E36 - RHS%E36
      RES%E46 = LHS%E46 - RHS%E46
      RES%E56 = LHS%E56 - RHS%E56
      RES%E66 = LHS%E66 - RHS%E66
      RES%E17 = LHS%E17 - RHS%E17
      RES%E27 = LHS%E27 - RHS%E27
      RES%E37 = LHS%E37 - RHS%E37
      RES%E47 = LHS%E47 - RHS%E47
      RES%E57 = LHS%E57 - RHS%E57
      RES%E67 = LHS%E67 - RHS%E67
      RES%E77 = LHS%E77 - RHS%E77

   END FUNCTION ONUMM7N2_SUB_OO_SV

   FUNCTION ONUMM7N2_SUB_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1)) 

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
      RES%E12 =  - RHS%E12
      RES%E22 =  - RHS%E22
      RES%E13 =  - RHS%E13
      RES%E23 =  - RHS%E23
      RES%E33 =  - RHS%E33
      RES%E14 =  - RHS%E14
      RES%E24 =  - RHS%E24
      RES%E34 =  - RHS%E34
      RES%E44 =  - RHS%E44
      RES%E15 =  - RHS%E15
      RES%E25 =  - RHS%E25
      RES%E35 =  - RHS%E35
      RES%E45 =  - RHS%E45
      RES%E55 =  - RHS%E55
      RES%E16 =  - RHS%E16
      RES%E26 =  - RHS%E26
      RES%E36 =  - RHS%E36
      RES%E46 =  - RHS%E46
      RES%E56 =  - RHS%E56
      RES%E66 =  - RHS%E66
      RES%E17 =  - RHS%E17
      RES%E27 =  - RHS%E27
      RES%E37 =  - RHS%E37
      RES%E47 =  - RHS%E47
      RES%E57 =  - RHS%E57
      RES%E67 =  - RHS%E67
      RES%E77 =  - RHS%E77

   END FUNCTION ONUMM7N2_SUB_RO_SV

   FUNCTION ONUMM7N2_SUB_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1)) 

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
      RES%E12 = LHS%E12
      RES%E22 = LHS%E22
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23
      RES%E33 = LHS%E33
      RES%E14 = LHS%E14
      RES%E24 = LHS%E24
      RES%E34 = LHS%E34
      RES%E44 = LHS%E44
      RES%E15 = LHS%E15
      RES%E25 = LHS%E25
      RES%E35 = LHS%E35
      RES%E45 = LHS%E45
      RES%E55 = LHS%E55
      RES%E16 = LHS%E16
      RES%E26 = LHS%E26
      RES%E36 = LHS%E36
      RES%E46 = LHS%E46
      RES%E56 = LHS%E56
      RES%E66 = LHS%E66
      RES%E17 = LHS%E17
      RES%E27 = LHS%E27
      RES%E37 = LHS%E37
      RES%E47 = LHS%E47
      RES%E57 = LHS%E57
      RES%E67 = LHS%E67
      RES%E77 = LHS%E77

   END FUNCTION ONUMM7N2_SUB_OR_SV

   FUNCTION ONUMM7N2_MUL_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      RES%E12 = LHS%R*RHS%E12 + LHS%E12*RHS%R +  &
             LHS%E1*RHS%E2 + LHS%E2*RHS%E1
      RES%E22 = LHS%R*RHS%E22 + LHS%E22*RHS%R + LHS%E2*RHS%E2
      RES%E13 = LHS%R*RHS%E13 + LHS%E13*RHS%R +  &
             LHS%E1*RHS%E3 + LHS%E3*RHS%E1
      RES%E23 = LHS%R*RHS%E23 + LHS%E23*RHS%R +  &
             LHS%E2*RHS%E3 + LHS%E3*RHS%E2
      RES%E33 = LHS%R*RHS%E33 + LHS%E33*RHS%R + LHS%E3*RHS%E3
      RES%E14 = LHS%R*RHS%E14 + LHS%E14*RHS%R +  &
             LHS%E1*RHS%E4 + LHS%E4*RHS%E1
      RES%E24 = LHS%R*RHS%E24 + LHS%E24*RHS%R +  &
             LHS%E2*RHS%E4 + LHS%E4*RHS%E2
      RES%E34 = LHS%R*RHS%E34 + LHS%E34*RHS%R +  &
             LHS%E3*RHS%E4 + LHS%E4*RHS%E3
      RES%E44 = LHS%R*RHS%E44 + LHS%E44*RHS%R + LHS%E4*RHS%E4
      RES%E15 = LHS%R*RHS%E15 + LHS%E15*RHS%R +  &
             LHS%E1*RHS%E5 + LHS%E5*RHS%E1
      RES%E25 = LHS%R*RHS%E25 + LHS%E25*RHS%R +  &
             LHS%E2*RHS%E5 + LHS%E5*RHS%E2
      RES%E35 = LHS%R*RHS%E35 + LHS%E35*RHS%R +  &
             LHS%E3*RHS%E5 + LHS%E5*RHS%E3
      RES%E45 = LHS%R*RHS%E45 + LHS%E45*RHS%R +  &
             LHS%E4*RHS%E5 + LHS%E5*RHS%E4
      RES%E55 = LHS%R*RHS%E55 + LHS%E55*RHS%R + LHS%E5*RHS%E5
      RES%E16 = LHS%R*RHS%E16 + LHS%E16*RHS%R +  &
             LHS%E1*RHS%E6 + LHS%E6*RHS%E1
      RES%E26 = LHS%R*RHS%E26 + LHS%E26*RHS%R +  &
             LHS%E2*RHS%E6 + LHS%E6*RHS%E2
      RES%E36 = LHS%R*RHS%E36 + LHS%E36*RHS%R +  &
             LHS%E3*RHS%E6 + LHS%E6*RHS%E3
      RES%E46 = LHS%R*RHS%E46 + LHS%E46*RHS%R +  &
             LHS%E4*RHS%E6 + LHS%E6*RHS%E4
      RES%E56 = LHS%R*RHS%E56 + LHS%E56*RHS%R +  &
             LHS%E5*RHS%E6 + LHS%E6*RHS%E5
      RES%E66 = LHS%R*RHS%E66 + LHS%E66*RHS%R + LHS%E6*RHS%E6
      RES%E17 = LHS%R*RHS%E17 + LHS%E17*RHS%R +  &
             LHS%E1*RHS%E7 + LHS%E7*RHS%E1
      RES%E27 = LHS%R*RHS%E27 + LHS%E27*RHS%R +  &
             LHS%E2*RHS%E7 + LHS%E7*RHS%E2
      RES%E37 = LHS%R*RHS%E37 + LHS%E37*RHS%R +  &
             LHS%E3*RHS%E7 + LHS%E7*RHS%E3
      RES%E47 = LHS%R*RHS%E47 + LHS%E47*RHS%R +  &
             LHS%E4*RHS%E7 + LHS%E7*RHS%E4
      RES%E57 = LHS%R*RHS%E57 + LHS%E57*RHS%R +  &
             LHS%E5*RHS%E7 + LHS%E7*RHS%E5
      RES%E67 = LHS%R*RHS%E67 + LHS%E67*RHS%R +  &
             LHS%E6*RHS%E7 + LHS%E7*RHS%E6
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

   END FUNCTION ONUMM7N2_MUL_OO_SV

   FUNCTION ONUMM7N2_MUL_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1)) 

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
      RES%E12 = LHS*RHS%E12
      RES%E22 = LHS*RHS%E22
      RES%E13 = LHS*RHS%E13
      RES%E23 = LHS*RHS%E23
      RES%E33 = LHS*RHS%E33
      RES%E14 = LHS*RHS%E14
      RES%E24 = LHS*RHS%E24
      RES%E34 = LHS*RHS%E34
      RES%E44 = LHS*RHS%E44
      RES%E15 = LHS*RHS%E15
      RES%E25 = LHS*RHS%E25
      RES%E35 = LHS*RHS%E35
      RES%E45 = LHS*RHS%E45
      RES%E55 = LHS*RHS%E55
      RES%E16 = LHS*RHS%E16
      RES%E26 = LHS*RHS%E26
      RES%E36 = LHS*RHS%E36
      RES%E46 = LHS*RHS%E46
      RES%E56 = LHS*RHS%E56
      RES%E66 = LHS*RHS%E66
      RES%E17 = LHS*RHS%E17
      RES%E27 = LHS*RHS%E27
      RES%E37 = LHS*RHS%E37
      RES%E47 = LHS*RHS%E47
      RES%E57 = LHS*RHS%E57
      RES%E67 = LHS*RHS%E67
      RES%E77 = LHS*RHS%E77

   END FUNCTION ONUMM7N2_MUL_RO_SV

   FUNCTION ONUMM7N2_MUL_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1)) 

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
      RES%E12 = LHS%E12*RHS
      RES%E22 = LHS%E22*RHS
      RES%E13 = LHS%E13*RHS
      RES%E23 = LHS%E23*RHS
      RES%E33 = LHS%E33*RHS
      RES%E14 = LHS%E14*RHS
      RES%E24 = LHS%E24*RHS
      RES%E34 = LHS%E34*RHS
      RES%E44 = LHS%E44*RHS
      RES%E15 = LHS%E15*RHS
      RES%E25 = LHS%E25*RHS
      RES%E35 = LHS%E35*RHS
      RES%E45 = LHS%E45*RHS
      RES%E55 = LHS%E55*RHS
      RES%E16 = LHS%E16*RHS
      RES%E26 = LHS%E26*RHS
      RES%E36 = LHS%E36*RHS
      RES%E46 = LHS%E46*RHS
      RES%E56 = LHS%E56*RHS
      RES%E66 = LHS%E66*RHS
      RES%E17 = LHS%E17*RHS
      RES%E27 = LHS%E27*RHS
      RES%E37 = LHS%E37*RHS
      RES%E47 = LHS%E47*RHS
      RES%E57 = LHS%E57*RHS
      RES%E67 = LHS%E67*RHS
      RES%E77 = LHS%E77*RHS

   END FUNCTION ONUMM7N2_MUL_OR_SV

   FUNCTION ONUMM7N2_ADD_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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
      RES%E12 = LHS%E12 + RHS%E12
      RES%E22 = LHS%E22 + RHS%E22
      RES%E13 = LHS%E13 + RHS%E13
      RES%E23 = LHS%E23 + RHS%E23
      RES%E33 = LHS%E33 + RHS%E33
      RES%E14 = LHS%E14 + RHS%E14
      RES%E24 = LHS%E24 + RHS%E24
      RES%E34 = LHS%E34 + RHS%E34
      RES%E44 = LHS%E44 + RHS%E44
      RES%E15 = LHS%E15 + RHS%E15
      RES%E25 = LHS%E25 + RHS%E25
      RES%E35 = LHS%E35 + RHS%E35
      RES%E45 = LHS%E45 + RHS%E45
      RES%E55 = LHS%E55 + RHS%E55
      RES%E16 = LHS%E16 + RHS%E16
      RES%E26 = LHS%E26 + RHS%E26
      RES%E36 = LHS%E36 + RHS%E36
      RES%E46 = LHS%E46 + RHS%E46
      RES%E56 = LHS%E56 + RHS%E56
      RES%E66 = LHS%E66 + RHS%E66
      RES%E17 = LHS%E17 + RHS%E17
      RES%E27 = LHS%E27 + RHS%E27
      RES%E37 = LHS%E37 + RHS%E37
      RES%E47 = LHS%E47 + RHS%E47
      RES%E57 = LHS%E57 + RHS%E57
      RES%E67 = LHS%E67 + RHS%E67
      RES%E77 = LHS%E77 + RHS%E77

   END FUNCTION ONUMM7N2_ADD_OO_SM

   FUNCTION ONUMM7N2_ADD_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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
      RES%E12 =  + RHS%E12
      RES%E22 =  + RHS%E22
      RES%E13 =  + RHS%E13
      RES%E23 =  + RHS%E23
      RES%E33 =  + RHS%E33
      RES%E14 =  + RHS%E14
      RES%E24 =  + RHS%E24
      RES%E34 =  + RHS%E34
      RES%E44 =  + RHS%E44
      RES%E15 =  + RHS%E15
      RES%E25 =  + RHS%E25
      RES%E35 =  + RHS%E35
      RES%E45 =  + RHS%E45
      RES%E55 =  + RHS%E55
      RES%E16 =  + RHS%E16
      RES%E26 =  + RHS%E26
      RES%E36 =  + RHS%E36
      RES%E46 =  + RHS%E46
      RES%E56 =  + RHS%E56
      RES%E66 =  + RHS%E66
      RES%E17 =  + RHS%E17
      RES%E27 =  + RHS%E27
      RES%E37 =  + RHS%E37
      RES%E47 =  + RHS%E47
      RES%E57 =  + RHS%E57
      RES%E67 =  + RHS%E67
      RES%E77 =  + RHS%E77

   END FUNCTION ONUMM7N2_ADD_RO_SM

   FUNCTION ONUMM7N2_ADD_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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
      RES%E12 = LHS%E12
      RES%E22 = LHS%E22
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23
      RES%E33 = LHS%E33
      RES%E14 = LHS%E14
      RES%E24 = LHS%E24
      RES%E34 = LHS%E34
      RES%E44 = LHS%E44
      RES%E15 = LHS%E15
      RES%E25 = LHS%E25
      RES%E35 = LHS%E35
      RES%E45 = LHS%E45
      RES%E55 = LHS%E55
      RES%E16 = LHS%E16
      RES%E26 = LHS%E26
      RES%E36 = LHS%E36
      RES%E46 = LHS%E46
      RES%E56 = LHS%E56
      RES%E66 = LHS%E66
      RES%E17 = LHS%E17
      RES%E27 = LHS%E27
      RES%E37 = LHS%E37
      RES%E47 = LHS%E47
      RES%E57 = LHS%E57
      RES%E67 = LHS%E67
      RES%E77 = LHS%E77

   END FUNCTION ONUMM7N2_ADD_OR_SM

   FUNCTION ONUMM7N2_SUB_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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
      RES%E12 = LHS%E12 - RHS%E12
      RES%E22 = LHS%E22 - RHS%E22
      RES%E13 = LHS%E13 - RHS%E13
      RES%E23 = LHS%E23 - RHS%E23
      RES%E33 = LHS%E33 - RHS%E33
      RES%E14 = LHS%E14 - RHS%E14
      RES%E24 = LHS%E24 - RHS%E24
      RES%E34 = LHS%E34 - RHS%E34
      RES%E44 = LHS%E44 - RHS%E44
      RES%E15 = LHS%E15 - RHS%E15
      RES%E25 = LHS%E25 - RHS%E25
      RES%E35 = LHS%E35 - RHS%E35
      RES%E45 = LHS%E45 - RHS%E45
      RES%E55 = LHS%E55 - RHS%E55
      RES%E16 = LHS%E16 - RHS%E16
      RES%E26 = LHS%E26 - RHS%E26
      RES%E36 = LHS%E36 - RHS%E36
      RES%E46 = LHS%E46 - RHS%E46
      RES%E56 = LHS%E56 - RHS%E56
      RES%E66 = LHS%E66 - RHS%E66
      RES%E17 = LHS%E17 - RHS%E17
      RES%E27 = LHS%E27 - RHS%E27
      RES%E37 = LHS%E37 - RHS%E37
      RES%E47 = LHS%E47 - RHS%E47
      RES%E57 = LHS%E57 - RHS%E57
      RES%E67 = LHS%E67 - RHS%E67
      RES%E77 = LHS%E77 - RHS%E77

   END FUNCTION ONUMM7N2_SUB_OO_SM

   FUNCTION ONUMM7N2_SUB_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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
      RES%E12 =  - RHS%E12
      RES%E22 =  - RHS%E22
      RES%E13 =  - RHS%E13
      RES%E23 =  - RHS%E23
      RES%E33 =  - RHS%E33
      RES%E14 =  - RHS%E14
      RES%E24 =  - RHS%E24
      RES%E34 =  - RHS%E34
      RES%E44 =  - RHS%E44
      RES%E15 =  - RHS%E15
      RES%E25 =  - RHS%E25
      RES%E35 =  - RHS%E35
      RES%E45 =  - RHS%E45
      RES%E55 =  - RHS%E55
      RES%E16 =  - RHS%E16
      RES%E26 =  - RHS%E26
      RES%E36 =  - RHS%E36
      RES%E46 =  - RHS%E46
      RES%E56 =  - RHS%E56
      RES%E66 =  - RHS%E66
      RES%E17 =  - RHS%E17
      RES%E27 =  - RHS%E27
      RES%E37 =  - RHS%E37
      RES%E47 =  - RHS%E47
      RES%E57 =  - RHS%E57
      RES%E67 =  - RHS%E67
      RES%E77 =  - RHS%E77

   END FUNCTION ONUMM7N2_SUB_RO_SM

   FUNCTION ONUMM7N2_SUB_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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
      RES%E12 = LHS%E12
      RES%E22 = LHS%E22
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23
      RES%E33 = LHS%E33
      RES%E14 = LHS%E14
      RES%E24 = LHS%E24
      RES%E34 = LHS%E34
      RES%E44 = LHS%E44
      RES%E15 = LHS%E15
      RES%E25 = LHS%E25
      RES%E35 = LHS%E35
      RES%E45 = LHS%E45
      RES%E55 = LHS%E55
      RES%E16 = LHS%E16
      RES%E26 = LHS%E26
      RES%E36 = LHS%E36
      RES%E46 = LHS%E46
      RES%E56 = LHS%E56
      RES%E66 = LHS%E66
      RES%E17 = LHS%E17
      RES%E27 = LHS%E27
      RES%E37 = LHS%E37
      RES%E47 = LHS%E47
      RES%E57 = LHS%E57
      RES%E67 = LHS%E67
      RES%E77 = LHS%E77

   END FUNCTION ONUMM7N2_SUB_OR_SM

   FUNCTION ONUMM7N2_MUL_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      RES%E12 = LHS%R*RHS%E12 + LHS%E12*RHS%R +  &
             LHS%E1*RHS%E2 + LHS%E2*RHS%E1
      RES%E22 = LHS%R*RHS%E22 + LHS%E22*RHS%R + LHS%E2*RHS%E2
      RES%E13 = LHS%R*RHS%E13 + LHS%E13*RHS%R +  &
             LHS%E1*RHS%E3 + LHS%E3*RHS%E1
      RES%E23 = LHS%R*RHS%E23 + LHS%E23*RHS%R +  &
             LHS%E2*RHS%E3 + LHS%E3*RHS%E2
      RES%E33 = LHS%R*RHS%E33 + LHS%E33*RHS%R + LHS%E3*RHS%E3
      RES%E14 = LHS%R*RHS%E14 + LHS%E14*RHS%R +  &
             LHS%E1*RHS%E4 + LHS%E4*RHS%E1
      RES%E24 = LHS%R*RHS%E24 + LHS%E24*RHS%R +  &
             LHS%E2*RHS%E4 + LHS%E4*RHS%E2
      RES%E34 = LHS%R*RHS%E34 + LHS%E34*RHS%R +  &
             LHS%E3*RHS%E4 + LHS%E4*RHS%E3
      RES%E44 = LHS%R*RHS%E44 + LHS%E44*RHS%R + LHS%E4*RHS%E4
      RES%E15 = LHS%R*RHS%E15 + LHS%E15*RHS%R +  &
             LHS%E1*RHS%E5 + LHS%E5*RHS%E1
      RES%E25 = LHS%R*RHS%E25 + LHS%E25*RHS%R +  &
             LHS%E2*RHS%E5 + LHS%E5*RHS%E2
      RES%E35 = LHS%R*RHS%E35 + LHS%E35*RHS%R +  &
             LHS%E3*RHS%E5 + LHS%E5*RHS%E3
      RES%E45 = LHS%R*RHS%E45 + LHS%E45*RHS%R +  &
             LHS%E4*RHS%E5 + LHS%E5*RHS%E4
      RES%E55 = LHS%R*RHS%E55 + LHS%E55*RHS%R + LHS%E5*RHS%E5
      RES%E16 = LHS%R*RHS%E16 + LHS%E16*RHS%R +  &
             LHS%E1*RHS%E6 + LHS%E6*RHS%E1
      RES%E26 = LHS%R*RHS%E26 + LHS%E26*RHS%R +  &
             LHS%E2*RHS%E6 + LHS%E6*RHS%E2
      RES%E36 = LHS%R*RHS%E36 + LHS%E36*RHS%R +  &
             LHS%E3*RHS%E6 + LHS%E6*RHS%E3
      RES%E46 = LHS%R*RHS%E46 + LHS%E46*RHS%R +  &
             LHS%E4*RHS%E6 + LHS%E6*RHS%E4
      RES%E56 = LHS%R*RHS%E56 + LHS%E56*RHS%R +  &
             LHS%E5*RHS%E6 + LHS%E6*RHS%E5
      RES%E66 = LHS%R*RHS%E66 + LHS%E66*RHS%R + LHS%E6*RHS%E6
      RES%E17 = LHS%R*RHS%E17 + LHS%E17*RHS%R +  &
             LHS%E1*RHS%E7 + LHS%E7*RHS%E1
      RES%E27 = LHS%R*RHS%E27 + LHS%E27*RHS%R +  &
             LHS%E2*RHS%E7 + LHS%E7*RHS%E2
      RES%E37 = LHS%R*RHS%E37 + LHS%E37*RHS%R +  &
             LHS%E3*RHS%E7 + LHS%E7*RHS%E3
      RES%E47 = LHS%R*RHS%E47 + LHS%E47*RHS%R +  &
             LHS%E4*RHS%E7 + LHS%E7*RHS%E4
      RES%E57 = LHS%R*RHS%E57 + LHS%E57*RHS%R +  &
             LHS%E5*RHS%E7 + LHS%E7*RHS%E5
      RES%E67 = LHS%R*RHS%E67 + LHS%E67*RHS%R +  &
             LHS%E6*RHS%E7 + LHS%E7*RHS%E6
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

   END FUNCTION ONUMM7N2_MUL_OO_SM

   FUNCTION ONUMM7N2_MUL_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N2), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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
      RES%E12 = LHS*RHS%E12
      RES%E22 = LHS*RHS%E22
      RES%E13 = LHS*RHS%E13
      RES%E23 = LHS*RHS%E23
      RES%E33 = LHS*RHS%E33
      RES%E14 = LHS*RHS%E14
      RES%E24 = LHS*RHS%E24
      RES%E34 = LHS*RHS%E34
      RES%E44 = LHS*RHS%E44
      RES%E15 = LHS*RHS%E15
      RES%E25 = LHS*RHS%E25
      RES%E35 = LHS*RHS%E35
      RES%E45 = LHS*RHS%E45
      RES%E55 = LHS*RHS%E55
      RES%E16 = LHS*RHS%E16
      RES%E26 = LHS*RHS%E26
      RES%E36 = LHS*RHS%E36
      RES%E46 = LHS*RHS%E46
      RES%E56 = LHS*RHS%E56
      RES%E66 = LHS*RHS%E66
      RES%E17 = LHS*RHS%E17
      RES%E27 = LHS*RHS%E27
      RES%E37 = LHS*RHS%E37
      RES%E47 = LHS*RHS%E47
      RES%E57 = LHS*RHS%E57
      RES%E67 = LHS*RHS%E67
      RES%E77 = LHS*RHS%E77

   END FUNCTION ONUMM7N2_MUL_RO_SM

   FUNCTION ONUMM7N2_MUL_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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
      RES%E12 = LHS%E12*RHS
      RES%E22 = LHS%E22*RHS
      RES%E13 = LHS%E13*RHS
      RES%E23 = LHS%E23*RHS
      RES%E33 = LHS%E33*RHS
      RES%E14 = LHS%E14*RHS
      RES%E24 = LHS%E24*RHS
      RES%E34 = LHS%E34*RHS
      RES%E44 = LHS%E44*RHS
      RES%E15 = LHS%E15*RHS
      RES%E25 = LHS%E25*RHS
      RES%E35 = LHS%E35*RHS
      RES%E45 = LHS%E45*RHS
      RES%E55 = LHS%E55*RHS
      RES%E16 = LHS%E16*RHS
      RES%E26 = LHS%E26*RHS
      RES%E36 = LHS%E36*RHS
      RES%E46 = LHS%E46*RHS
      RES%E56 = LHS%E56*RHS
      RES%E66 = LHS%E66*RHS
      RES%E17 = LHS%E17*RHS
      RES%E27 = LHS%E27*RHS
      RES%E37 = LHS%E37*RHS
      RES%E47 = LHS%E47*RHS
      RES%E57 = LHS%E57*RHS
      RES%E67 = LHS%E67*RHS
      RES%E77 = LHS%E77*RHS

   END FUNCTION ONUMM7N2_MUL_OR_SM

ELEMENTAL    FUNCTION ONUMM7N2_GEM_OOO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: A 
      TYPE(ONUMM7N2), INTENT(IN) :: B 
      TYPE(ONUMM7N2), INTENT(IN) :: C 
      TYPE(ONUMM7N2) :: RES 

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
      RES%E12 = C%E12 + A%R*B%E12 + A%E12*B%R + A%E1*B%E2 &
              + A%E2*B%E1
      RES%E22 = C%E22 + A%R*B%E22 + A%E22*B%R + A%E2*B%E2
      RES%E13 = C%E13 + A%R*B%E13 + A%E13*B%R + A%E1*B%E3 &
              + A%E3*B%E1
      RES%E23 = C%E23 + A%R*B%E23 + A%E23*B%R + A%E2*B%E3 &
              + A%E3*B%E2
      RES%E33 = C%E33 + A%R*B%E33 + A%E33*B%R + A%E3*B%E3
      RES%E14 = C%E14 + A%R*B%E14 + A%E14*B%R + A%E1*B%E4 &
              + A%E4*B%E1
      RES%E24 = C%E24 + A%R*B%E24 + A%E24*B%R + A%E2*B%E4 &
              + A%E4*B%E2
      RES%E34 = C%E34 + A%R*B%E34 + A%E34*B%R + A%E3*B%E4 &
              + A%E4*B%E3
      RES%E44 = C%E44 + A%R*B%E44 + A%E44*B%R + A%E4*B%E4
      RES%E15 = C%E15 + A%R*B%E15 + A%E15*B%R + A%E1*B%E5 &
              + A%E5*B%E1
      RES%E25 = C%E25 + A%R*B%E25 + A%E25*B%R + A%E2*B%E5 &
              + A%E5*B%E2
      RES%E35 = C%E35 + A%R*B%E35 + A%E35*B%R + A%E3*B%E5 &
              + A%E5*B%E3
      RES%E45 = C%E45 + A%R*B%E45 + A%E45*B%R + A%E4*B%E5 &
              + A%E5*B%E4
      RES%E55 = C%E55 + A%R*B%E55 + A%E55*B%R + A%E5*B%E5
      RES%E16 = C%E16 + A%R*B%E16 + A%E16*B%R + A%E1*B%E6 &
              + A%E6*B%E1
      RES%E26 = C%E26 + A%R*B%E26 + A%E26*B%R + A%E2*B%E6 &
              + A%E6*B%E2
      RES%E36 = C%E36 + A%R*B%E36 + A%E36*B%R + A%E3*B%E6 &
              + A%E6*B%E3
      RES%E46 = C%E46 + A%R*B%E46 + A%E46*B%R + A%E4*B%E6 &
              + A%E6*B%E4
      RES%E56 = C%E56 + A%R*B%E56 + A%E56*B%R + A%E5*B%E6 &
              + A%E6*B%E5
      RES%E66 = C%E66 + A%R*B%E66 + A%E66*B%R + A%E6*B%E6
      RES%E17 = C%E17 + A%R*B%E17 + A%E17*B%R + A%E1*B%E7 &
              + A%E7*B%E1
      RES%E27 = C%E27 + A%R*B%E27 + A%E27*B%R + A%E2*B%E7 &
              + A%E7*B%E2
      RES%E37 = C%E37 + A%R*B%E37 + A%E37*B%R + A%E3*B%E7 &
              + A%E7*B%E3
      RES%E47 = C%E47 + A%R*B%E47 + A%E47*B%R + A%E4*B%E7 &
              + A%E7*B%E4
      RES%E57 = C%E57 + A%R*B%E57 + A%E57*B%R + A%E5*B%E7 &
              + A%E7*B%E5
      RES%E67 = C%E67 + A%R*B%E67 + A%E67*B%R + A%E6*B%E7 &
              + A%E7*B%E6
      RES%E77 = C%E77 + A%R*B%E77 + A%E77*B%R + A%E7*B%E7

   END FUNCTION ONUMM7N2_GEM_OOO

ELEMENTAL    FUNCTION ONUMM7N2_GEM_ROO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: A 
      TYPE(ONUMM7N2), INTENT(IN) :: B 
      TYPE(ONUMM7N2), INTENT(IN) :: C 
      TYPE(ONUMM7N2) :: RES 

      !  General multiplication like function 'A*B + C'
      ! Order 2
      RES%E11 = C%E11 + A*B%E11
      RES%E12 = C%E12 + A*B%E12
      RES%E22 = C%E22 + A*B%E22
      RES%E13 = C%E13 + A*B%E13
      RES%E23 = C%E23 + A*B%E23
      RES%E33 = C%E33 + A*B%E33
      RES%E14 = C%E14 + A*B%E14
      RES%E24 = C%E24 + A*B%E24
      RES%E34 = C%E34 + A*B%E34
      RES%E44 = C%E44 + A*B%E44
      RES%E15 = C%E15 + A*B%E15
      RES%E25 = C%E25 + A*B%E25
      RES%E35 = C%E35 + A*B%E35
      RES%E45 = C%E45 + A*B%E45
      RES%E55 = C%E55 + A*B%E55
      RES%E16 = C%E16 + A*B%E16
      RES%E26 = C%E26 + A*B%E26
      RES%E36 = C%E36 + A*B%E36
      RES%E46 = C%E46 + A*B%E46
      RES%E56 = C%E56 + A*B%E56
      RES%E66 = C%E66 + A*B%E66
      RES%E17 = C%E17 + A*B%E17
      RES%E27 = C%E27 + A*B%E27
      RES%E37 = C%E37 + A*B%E37
      RES%E47 = C%E47 + A*B%E47
      RES%E57 = C%E57 + A*B%E57
      RES%E67 = C%E67 + A*B%E67
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

   END FUNCTION ONUMM7N2_GEM_ROO

ELEMENTAL    FUNCTION ONUMM7N2_GEM_ORO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: A 
      REAL(DP), INTENT(IN) :: B 
      TYPE(ONUMM7N2), INTENT(IN) :: C 
      TYPE(ONUMM7N2) :: RES 

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
      RES%E12 = C%E12 + A%E12*B
      RES%E22 = C%E22 + A%E22*B
      RES%E13 = C%E13 + A%E13*B
      RES%E23 = C%E23 + A%E23*B
      RES%E33 = C%E33 + A%E33*B
      RES%E14 = C%E14 + A%E14*B
      RES%E24 = C%E24 + A%E24*B
      RES%E34 = C%E34 + A%E34*B
      RES%E44 = C%E44 + A%E44*B
      RES%E15 = C%E15 + A%E15*B
      RES%E25 = C%E25 + A%E25*B
      RES%E35 = C%E35 + A%E35*B
      RES%E45 = C%E45 + A%E45*B
      RES%E55 = C%E55 + A%E55*B
      RES%E16 = C%E16 + A%E16*B
      RES%E26 = C%E26 + A%E26*B
      RES%E36 = C%E36 + A%E36*B
      RES%E46 = C%E46 + A%E46*B
      RES%E56 = C%E56 + A%E56*B
      RES%E66 = C%E66 + A%E66*B
      RES%E17 = C%E17 + A%E17*B
      RES%E27 = C%E27 + A%E27*B
      RES%E37 = C%E37 + A%E37*B
      RES%E47 = C%E47 + A%E47*B
      RES%E57 = C%E57 + A%E57*B
      RES%E67 = C%E67 + A%E67*B
      RES%E77 = C%E77 + A%E77*B

   END FUNCTION ONUMM7N2_GEM_ORO

   FUNCTION ONUMM7N2_MATMUL_ONUMM7N2(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N2), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      !  Multiplication like function 'MATMUL(lhs,rhs)'
      ! Order 2
      res%E11 = MATMUL(lhs%R,rhs%E11) + MATMUL(lhs%E11,rhs%R) + MATMUL(lhs%E1,rhs%E1)
      res%E12 = MATMUL(lhs%R,rhs%E12) + MATMUL(lhs%E12,rhs%R) +  &
             MATMUL(lhs%E1,rhs%E2) + MATMUL(lhs%E2,rhs%E1)
      res%E22 = MATMUL(lhs%R,rhs%E22) + MATMUL(lhs%E22,rhs%R) + MATMUL(lhs%E2,rhs%E2)
      res%E13 = MATMUL(lhs%R,rhs%E13) + MATMUL(lhs%E13,rhs%R) +  &
             MATMUL(lhs%E1,rhs%E3) + MATMUL(lhs%E3,rhs%E1)
      res%E23 = MATMUL(lhs%R,rhs%E23) + MATMUL(lhs%E23,rhs%R) +  &
             MATMUL(lhs%E2,rhs%E3) + MATMUL(lhs%E3,rhs%E2)
      res%E33 = MATMUL(lhs%R,rhs%E33) + MATMUL(lhs%E33,rhs%R) + MATMUL(lhs%E3,rhs%E3)
      res%E14 = MATMUL(lhs%R,rhs%E14) + MATMUL(lhs%E14,rhs%R) +  &
             MATMUL(lhs%E1,rhs%E4) + MATMUL(lhs%E4,rhs%E1)
      res%E24 = MATMUL(lhs%R,rhs%E24) + MATMUL(lhs%E24,rhs%R) +  &
             MATMUL(lhs%E2,rhs%E4) + MATMUL(lhs%E4,rhs%E2)
      res%E34 = MATMUL(lhs%R,rhs%E34) + MATMUL(lhs%E34,rhs%R) +  &
             MATMUL(lhs%E3,rhs%E4) + MATMUL(lhs%E4,rhs%E3)
      res%E44 = MATMUL(lhs%R,rhs%E44) + MATMUL(lhs%E44,rhs%R) + MATMUL(lhs%E4,rhs%E4)
      res%E15 = MATMUL(lhs%R,rhs%E15) + MATMUL(lhs%E15,rhs%R) +  &
             MATMUL(lhs%E1,rhs%E5) + MATMUL(lhs%E5,rhs%E1)
      res%E25 = MATMUL(lhs%R,rhs%E25) + MATMUL(lhs%E25,rhs%R) +  &
             MATMUL(lhs%E2,rhs%E5) + MATMUL(lhs%E5,rhs%E2)
      res%E35 = MATMUL(lhs%R,rhs%E35) + MATMUL(lhs%E35,rhs%R) +  &
             MATMUL(lhs%E3,rhs%E5) + MATMUL(lhs%E5,rhs%E3)
      res%E45 = MATMUL(lhs%R,rhs%E45) + MATMUL(lhs%E45,rhs%R) +  &
             MATMUL(lhs%E4,rhs%E5) + MATMUL(lhs%E5,rhs%E4)
      res%E55 = MATMUL(lhs%R,rhs%E55) + MATMUL(lhs%E55,rhs%R) + MATMUL(lhs%E5,rhs%E5)
      res%E16 = MATMUL(lhs%R,rhs%E16) + MATMUL(lhs%E16,rhs%R) +  &
             MATMUL(lhs%E1,rhs%E6) + MATMUL(lhs%E6,rhs%E1)
      res%E26 = MATMUL(lhs%R,rhs%E26) + MATMUL(lhs%E26,rhs%R) +  &
             MATMUL(lhs%E2,rhs%E6) + MATMUL(lhs%E6,rhs%E2)
      res%E36 = MATMUL(lhs%R,rhs%E36) + MATMUL(lhs%E36,rhs%R) +  &
             MATMUL(lhs%E3,rhs%E6) + MATMUL(lhs%E6,rhs%E3)
      res%E46 = MATMUL(lhs%R,rhs%E46) + MATMUL(lhs%E46,rhs%R) +  &
             MATMUL(lhs%E4,rhs%E6) + MATMUL(lhs%E6,rhs%E4)
      res%E56 = MATMUL(lhs%R,rhs%E56) + MATMUL(lhs%E56,rhs%R) +  &
             MATMUL(lhs%E5,rhs%E6) + MATMUL(lhs%E6,rhs%E5)
      res%E66 = MATMUL(lhs%R,rhs%E66) + MATMUL(lhs%E66,rhs%R) + MATMUL(lhs%E6,rhs%E6)
      res%E17 = MATMUL(lhs%R,rhs%E17) + MATMUL(lhs%E17,rhs%R) +  &
             MATMUL(lhs%E1,rhs%E7) + MATMUL(lhs%E7,rhs%E1)
      res%E27 = MATMUL(lhs%R,rhs%E27) + MATMUL(lhs%E27,rhs%R) +  &
             MATMUL(lhs%E2,rhs%E7) + MATMUL(lhs%E7,rhs%E2)
      res%E37 = MATMUL(lhs%R,rhs%E37) + MATMUL(lhs%E37,rhs%R) +  &
             MATMUL(lhs%E3,rhs%E7) + MATMUL(lhs%E7,rhs%E3)
      res%E47 = MATMUL(lhs%R,rhs%E47) + MATMUL(lhs%E47,rhs%R) +  &
             MATMUL(lhs%E4,rhs%E7) + MATMUL(lhs%E7,rhs%E4)
      res%E57 = MATMUL(lhs%R,rhs%E57) + MATMUL(lhs%E57,rhs%R) +  &
             MATMUL(lhs%E5,rhs%E7) + MATMUL(lhs%E7,rhs%E5)
      res%E67 = MATMUL(lhs%R,rhs%E67) + MATMUL(lhs%E67,rhs%R) +  &
             MATMUL(lhs%E6,rhs%E7) + MATMUL(lhs%E7,rhs%E6)
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

   END FUNCTION ONUMM7N2_MATMUL_ONUMM7N2

   FUNCTION R_MATMUL_ONUMM7N2(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N2), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1),SIZE(RHS,2))

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
      res%E12 = MATMUL(lhs,rhs%E12)
      res%E22 = MATMUL(lhs,rhs%E22)
      res%E13 = MATMUL(lhs,rhs%E13)
      res%E23 = MATMUL(lhs,rhs%E23)
      res%E33 = MATMUL(lhs,rhs%E33)
      res%E14 = MATMUL(lhs,rhs%E14)
      res%E24 = MATMUL(lhs,rhs%E24)
      res%E34 = MATMUL(lhs,rhs%E34)
      res%E44 = MATMUL(lhs,rhs%E44)
      res%E15 = MATMUL(lhs,rhs%E15)
      res%E25 = MATMUL(lhs,rhs%E25)
      res%E35 = MATMUL(lhs,rhs%E35)
      res%E45 = MATMUL(lhs,rhs%E45)
      res%E55 = MATMUL(lhs,rhs%E55)
      res%E16 = MATMUL(lhs,rhs%E16)
      res%E26 = MATMUL(lhs,rhs%E26)
      res%E36 = MATMUL(lhs,rhs%E36)
      res%E46 = MATMUL(lhs,rhs%E46)
      res%E56 = MATMUL(lhs,rhs%E56)
      res%E66 = MATMUL(lhs,rhs%E66)
      res%E17 = MATMUL(lhs,rhs%E17)
      res%E27 = MATMUL(lhs,rhs%E27)
      res%E37 = MATMUL(lhs,rhs%E37)
      res%E47 = MATMUL(lhs,rhs%E47)
      res%E57 = MATMUL(lhs,rhs%E57)
      res%E67 = MATMUL(lhs,rhs%E67)
      res%E77 = MATMUL(lhs,rhs%E77)

   END FUNCTION R_MATMUL_ONUMM7N2

   FUNCTION ONUMM7N2_MATMUL_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N2) :: RES(SIZE(LHS,1),SIZE(RHS,2))

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
      res%E12 = MATMUL(lhs%E12,rhs)
      res%E22 = MATMUL(lhs%E22,rhs)
      res%E13 = MATMUL(lhs%E13,rhs)
      res%E23 = MATMUL(lhs%E23,rhs)
      res%E33 = MATMUL(lhs%E33,rhs)
      res%E14 = MATMUL(lhs%E14,rhs)
      res%E24 = MATMUL(lhs%E24,rhs)
      res%E34 = MATMUL(lhs%E34,rhs)
      res%E44 = MATMUL(lhs%E44,rhs)
      res%E15 = MATMUL(lhs%E15,rhs)
      res%E25 = MATMUL(lhs%E25,rhs)
      res%E35 = MATMUL(lhs%E35,rhs)
      res%E45 = MATMUL(lhs%E45,rhs)
      res%E55 = MATMUL(lhs%E55,rhs)
      res%E16 = MATMUL(lhs%E16,rhs)
      res%E26 = MATMUL(lhs%E26,rhs)
      res%E36 = MATMUL(lhs%E36,rhs)
      res%E46 = MATMUL(lhs%E46,rhs)
      res%E56 = MATMUL(lhs%E56,rhs)
      res%E66 = MATMUL(lhs%E66,rhs)
      res%E17 = MATMUL(lhs%E17,rhs)
      res%E27 = MATMUL(lhs%E27,rhs)
      res%E37 = MATMUL(lhs%E37,rhs)
      res%E47 = MATMUL(lhs%E47,rhs)
      res%E57 = MATMUL(lhs%E57,rhs)
      res%E67 = MATMUL(lhs%E67,rhs)
      res%E77 = MATMUL(lhs%E77,rhs)

   END FUNCTION ONUMM7N2_MATMUL_R

   FUNCTION ONUMM7N2_DOT_PRODUCT_ONUMM7N2(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:)
      TYPE(ONUMM7N2), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(ONUMM7N2) :: RES

      !  Multiplication like function 'DOT_PRODUCT(lhs,rhs)'
      ! Order 2
      res%E11 = DOT_PRODUCT(lhs%R,rhs%E11) + DOT_PRODUCT(lhs%E11,rhs%R) + DOT_PRODUCT(lhs%E1,rhs%E1)
      res%E12 = DOT_PRODUCT(lhs%R,rhs%E12) + DOT_PRODUCT(lhs%E12,rhs%R) +  &
             DOT_PRODUCT(lhs%E1,rhs%E2) + DOT_PRODUCT(lhs%E2,rhs%E1)
      res%E22 = DOT_PRODUCT(lhs%R,rhs%E22) + DOT_PRODUCT(lhs%E22,rhs%R) + DOT_PRODUCT(lhs%E2,rhs%E2)
      res%E13 = DOT_PRODUCT(lhs%R,rhs%E13) + DOT_PRODUCT(lhs%E13,rhs%R) +  &
             DOT_PRODUCT(lhs%E1,rhs%E3) + DOT_PRODUCT(lhs%E3,rhs%E1)
      res%E23 = DOT_PRODUCT(lhs%R,rhs%E23) + DOT_PRODUCT(lhs%E23,rhs%R) +  &
             DOT_PRODUCT(lhs%E2,rhs%E3) + DOT_PRODUCT(lhs%E3,rhs%E2)
      res%E33 = DOT_PRODUCT(lhs%R,rhs%E33) + DOT_PRODUCT(lhs%E33,rhs%R) + DOT_PRODUCT(lhs%E3,rhs%E3)
      res%E14 = DOT_PRODUCT(lhs%R,rhs%E14) + DOT_PRODUCT(lhs%E14,rhs%R) +  &
             DOT_PRODUCT(lhs%E1,rhs%E4) + DOT_PRODUCT(lhs%E4,rhs%E1)
      res%E24 = DOT_PRODUCT(lhs%R,rhs%E24) + DOT_PRODUCT(lhs%E24,rhs%R) +  &
             DOT_PRODUCT(lhs%E2,rhs%E4) + DOT_PRODUCT(lhs%E4,rhs%E2)
      res%E34 = DOT_PRODUCT(lhs%R,rhs%E34) + DOT_PRODUCT(lhs%E34,rhs%R) +  &
             DOT_PRODUCT(lhs%E3,rhs%E4) + DOT_PRODUCT(lhs%E4,rhs%E3)
      res%E44 = DOT_PRODUCT(lhs%R,rhs%E44) + DOT_PRODUCT(lhs%E44,rhs%R) + DOT_PRODUCT(lhs%E4,rhs%E4)
      res%E15 = DOT_PRODUCT(lhs%R,rhs%E15) + DOT_PRODUCT(lhs%E15,rhs%R) +  &
             DOT_PRODUCT(lhs%E1,rhs%E5) + DOT_PRODUCT(lhs%E5,rhs%E1)
      res%E25 = DOT_PRODUCT(lhs%R,rhs%E25) + DOT_PRODUCT(lhs%E25,rhs%R) +  &
             DOT_PRODUCT(lhs%E2,rhs%E5) + DOT_PRODUCT(lhs%E5,rhs%E2)
      res%E35 = DOT_PRODUCT(lhs%R,rhs%E35) + DOT_PRODUCT(lhs%E35,rhs%R) +  &
             DOT_PRODUCT(lhs%E3,rhs%E5) + DOT_PRODUCT(lhs%E5,rhs%E3)
      res%E45 = DOT_PRODUCT(lhs%R,rhs%E45) + DOT_PRODUCT(lhs%E45,rhs%R) +  &
             DOT_PRODUCT(lhs%E4,rhs%E5) + DOT_PRODUCT(lhs%E5,rhs%E4)
      res%E55 = DOT_PRODUCT(lhs%R,rhs%E55) + DOT_PRODUCT(lhs%E55,rhs%R) + DOT_PRODUCT(lhs%E5,rhs%E5)
      res%E16 = DOT_PRODUCT(lhs%R,rhs%E16) + DOT_PRODUCT(lhs%E16,rhs%R) +  &
             DOT_PRODUCT(lhs%E1,rhs%E6) + DOT_PRODUCT(lhs%E6,rhs%E1)
      res%E26 = DOT_PRODUCT(lhs%R,rhs%E26) + DOT_PRODUCT(lhs%E26,rhs%R) +  &
             DOT_PRODUCT(lhs%E2,rhs%E6) + DOT_PRODUCT(lhs%E6,rhs%E2)
      res%E36 = DOT_PRODUCT(lhs%R,rhs%E36) + DOT_PRODUCT(lhs%E36,rhs%R) +  &
             DOT_PRODUCT(lhs%E3,rhs%E6) + DOT_PRODUCT(lhs%E6,rhs%E3)
      res%E46 = DOT_PRODUCT(lhs%R,rhs%E46) + DOT_PRODUCT(lhs%E46,rhs%R) +  &
             DOT_PRODUCT(lhs%E4,rhs%E6) + DOT_PRODUCT(lhs%E6,rhs%E4)
      res%E56 = DOT_PRODUCT(lhs%R,rhs%E56) + DOT_PRODUCT(lhs%E56,rhs%R) +  &
             DOT_PRODUCT(lhs%E5,rhs%E6) + DOT_PRODUCT(lhs%E6,rhs%E5)
      res%E66 = DOT_PRODUCT(lhs%R,rhs%E66) + DOT_PRODUCT(lhs%E66,rhs%R) + DOT_PRODUCT(lhs%E6,rhs%E6)
      res%E17 = DOT_PRODUCT(lhs%R,rhs%E17) + DOT_PRODUCT(lhs%E17,rhs%R) +  &
             DOT_PRODUCT(lhs%E1,rhs%E7) + DOT_PRODUCT(lhs%E7,rhs%E1)
      res%E27 = DOT_PRODUCT(lhs%R,rhs%E27) + DOT_PRODUCT(lhs%E27,rhs%R) +  &
             DOT_PRODUCT(lhs%E2,rhs%E7) + DOT_PRODUCT(lhs%E7,rhs%E2)
      res%E37 = DOT_PRODUCT(lhs%R,rhs%E37) + DOT_PRODUCT(lhs%E37,rhs%R) +  &
             DOT_PRODUCT(lhs%E3,rhs%E7) + DOT_PRODUCT(lhs%E7,rhs%E3)
      res%E47 = DOT_PRODUCT(lhs%R,rhs%E47) + DOT_PRODUCT(lhs%E47,rhs%R) +  &
             DOT_PRODUCT(lhs%E4,rhs%E7) + DOT_PRODUCT(lhs%E7,rhs%E4)
      res%E57 = DOT_PRODUCT(lhs%R,rhs%E57) + DOT_PRODUCT(lhs%E57,rhs%R) +  &
             DOT_PRODUCT(lhs%E5,rhs%E7) + DOT_PRODUCT(lhs%E7,rhs%E5)
      res%E67 = DOT_PRODUCT(lhs%R,rhs%E67) + DOT_PRODUCT(lhs%E67,rhs%R) +  &
             DOT_PRODUCT(lhs%E6,rhs%E7) + DOT_PRODUCT(lhs%E7,rhs%E6)
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

   END FUNCTION ONUMM7N2_DOT_PRODUCT_ONUMM7N2

   FUNCTION R_DOT_PRODUCT_ONUMM7N2(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(ONUMM7N2), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(ONUMM7N2) :: RES

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
      res%E12 = DOT_PRODUCT(lhs,rhs%E12)
      res%E22 = DOT_PRODUCT(lhs,rhs%E22)
      res%E13 = DOT_PRODUCT(lhs,rhs%E13)
      res%E23 = DOT_PRODUCT(lhs,rhs%E23)
      res%E33 = DOT_PRODUCT(lhs,rhs%E33)
      res%E14 = DOT_PRODUCT(lhs,rhs%E14)
      res%E24 = DOT_PRODUCT(lhs,rhs%E24)
      res%E34 = DOT_PRODUCT(lhs,rhs%E34)
      res%E44 = DOT_PRODUCT(lhs,rhs%E44)
      res%E15 = DOT_PRODUCT(lhs,rhs%E15)
      res%E25 = DOT_PRODUCT(lhs,rhs%E25)
      res%E35 = DOT_PRODUCT(lhs,rhs%E35)
      res%E45 = DOT_PRODUCT(lhs,rhs%E45)
      res%E55 = DOT_PRODUCT(lhs,rhs%E55)
      res%E16 = DOT_PRODUCT(lhs,rhs%E16)
      res%E26 = DOT_PRODUCT(lhs,rhs%E26)
      res%E36 = DOT_PRODUCT(lhs,rhs%E36)
      res%E46 = DOT_PRODUCT(lhs,rhs%E46)
      res%E56 = DOT_PRODUCT(lhs,rhs%E56)
      res%E66 = DOT_PRODUCT(lhs,rhs%E66)
      res%E17 = DOT_PRODUCT(lhs,rhs%E17)
      res%E27 = DOT_PRODUCT(lhs,rhs%E27)
      res%E37 = DOT_PRODUCT(lhs,rhs%E37)
      res%E47 = DOT_PRODUCT(lhs,rhs%E47)
      res%E57 = DOT_PRODUCT(lhs,rhs%E57)
      res%E67 = DOT_PRODUCT(lhs,rhs%E67)
      res%E77 = DOT_PRODUCT(lhs,rhs%E77)

   END FUNCTION R_DOT_PRODUCT_ONUMM7N2

   FUNCTION ONUMM7N2_DOT_PRODUCT_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(ONUMM7N2) :: RES

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
      res%E12 = DOT_PRODUCT(lhs%E12,rhs)
      res%E22 = DOT_PRODUCT(lhs%E22,rhs)
      res%E13 = DOT_PRODUCT(lhs%E13,rhs)
      res%E23 = DOT_PRODUCT(lhs%E23,rhs)
      res%E33 = DOT_PRODUCT(lhs%E33,rhs)
      res%E14 = DOT_PRODUCT(lhs%E14,rhs)
      res%E24 = DOT_PRODUCT(lhs%E24,rhs)
      res%E34 = DOT_PRODUCT(lhs%E34,rhs)
      res%E44 = DOT_PRODUCT(lhs%E44,rhs)
      res%E15 = DOT_PRODUCT(lhs%E15,rhs)
      res%E25 = DOT_PRODUCT(lhs%E25,rhs)
      res%E35 = DOT_PRODUCT(lhs%E35,rhs)
      res%E45 = DOT_PRODUCT(lhs%E45,rhs)
      res%E55 = DOT_PRODUCT(lhs%E55,rhs)
      res%E16 = DOT_PRODUCT(lhs%E16,rhs)
      res%E26 = DOT_PRODUCT(lhs%E26,rhs)
      res%E36 = DOT_PRODUCT(lhs%E36,rhs)
      res%E46 = DOT_PRODUCT(lhs%E46,rhs)
      res%E56 = DOT_PRODUCT(lhs%E56,rhs)
      res%E66 = DOT_PRODUCT(lhs%E66,rhs)
      res%E17 = DOT_PRODUCT(lhs%E17,rhs)
      res%E27 = DOT_PRODUCT(lhs%E27,rhs)
      res%E37 = DOT_PRODUCT(lhs%E37,rhs)
      res%E47 = DOT_PRODUCT(lhs%E47,rhs)
      res%E57 = DOT_PRODUCT(lhs%E57,rhs)
      res%E67 = DOT_PRODUCT(lhs%E67,rhs)
      res%E77 = DOT_PRODUCT(lhs%E77,rhs)

   END FUNCTION ONUMM7N2_DOT_PRODUCT_R

   FUNCTION ONUMM7N2_TRANSPOSE(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N2) :: RES (SIZE(LHS,2),SIZE(LHS,1))

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
      RES%E12 = TRANSPOSE(LHS%E12)
      RES%E22 = TRANSPOSE(LHS%E22)
      RES%E13 = TRANSPOSE(LHS%E13)
      RES%E23 = TRANSPOSE(LHS%E23)
      RES%E33 = TRANSPOSE(LHS%E33)
      RES%E14 = TRANSPOSE(LHS%E14)
      RES%E24 = TRANSPOSE(LHS%E24)
      RES%E34 = TRANSPOSE(LHS%E34)
      RES%E44 = TRANSPOSE(LHS%E44)
      RES%E15 = TRANSPOSE(LHS%E15)
      RES%E25 = TRANSPOSE(LHS%E25)
      RES%E35 = TRANSPOSE(LHS%E35)
      RES%E45 = TRANSPOSE(LHS%E45)
      RES%E55 = TRANSPOSE(LHS%E55)
      RES%E16 = TRANSPOSE(LHS%E16)
      RES%E26 = TRANSPOSE(LHS%E26)
      RES%E36 = TRANSPOSE(LHS%E36)
      RES%E46 = TRANSPOSE(LHS%E46)
      RES%E56 = TRANSPOSE(LHS%E56)
      RES%E66 = TRANSPOSE(LHS%E66)
      RES%E17 = TRANSPOSE(LHS%E17)
      RES%E27 = TRANSPOSE(LHS%E27)
      RES%E37 = TRANSPOSE(LHS%E37)
      RES%E47 = TRANSPOSE(LHS%E47)
      RES%E57 = TRANSPOSE(LHS%E57)
      RES%E67 = TRANSPOSE(LHS%E67)
      RES%E77 = TRANSPOSE(LHS%E77)

   END FUNCTION ONUMM7N2_TRANSPOSE

FUNCTION ONUMM7N2_TO_CR_MAT_S(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: VAL
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
      ! R x E12 -> E12 (10, 10)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*9:NCOLS*10) = VAL%R
      ! E12 x R -> E12 (10, 1)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*0:NCOLS*1) = VAL%E12
      ! E1 x E2 -> E12 (10, 3)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*2:NCOLS*3) = VAL%E1
      ! E2 x E1 -> E12 (10, 2)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*1:NCOLS*2) = VAL%E2
      ! R x E22 -> E22 (11, 11)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*10:NCOLS*11) = VAL%R
      ! E22 x R -> E22 (11, 1)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*0:NCOLS*1) = VAL%E22
      ! E2 x E2 -> E22 (11, 3)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*2:NCOLS*3) = VAL%E2
      ! R x E13 -> E13 (12, 12)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*11:NCOLS*12) = VAL%R
      ! E13 x R -> E13 (12, 1)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*0:NCOLS*1) = VAL%E13
      ! E1 x E3 -> E13 (12, 4)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*3:NCOLS*4) = VAL%E1
      ! E3 x E1 -> E13 (12, 2)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*1:NCOLS*2) = VAL%E3
      ! R x E23 -> E23 (13, 13)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*12:NCOLS*13) = VAL%R
      ! E23 x R -> E23 (13, 1)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*0:NCOLS*1) = VAL%E23
      ! E2 x E3 -> E23 (13, 4)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*3:NCOLS*4) = VAL%E2
      ! E3 x E2 -> E23 (13, 3)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*2:NCOLS*3) = VAL%E3
      ! R x E33 -> E33 (14, 14)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*13:NCOLS*14) = VAL%R
      ! E33 x R -> E33 (14, 1)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*0:NCOLS*1) = VAL%E33
      ! E3 x E3 -> E33 (14, 4)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*3:NCOLS*4) = VAL%E3
      ! R x E14 -> E14 (15, 15)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*14:NCOLS*15) = VAL%R
      ! E14 x R -> E14 (15, 1)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*0:NCOLS*1) = VAL%E14
      ! E1 x E4 -> E14 (15, 5)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*4:NCOLS*5) = VAL%E1
      ! E4 x E1 -> E14 (15, 2)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*1:NCOLS*2) = VAL%E4
      ! R x E24 -> E24 (16, 16)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*15:NCOLS*16) = VAL%R
      ! E24 x R -> E24 (16, 1)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*0:NCOLS*1) = VAL%E24
      ! E2 x E4 -> E24 (16, 5)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*4:NCOLS*5) = VAL%E2
      ! E4 x E2 -> E24 (16, 3)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*2:NCOLS*3) = VAL%E4
      ! R x E34 -> E34 (17, 17)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*16:NCOLS*17) = VAL%R
      ! E34 x R -> E34 (17, 1)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*0:NCOLS*1) = VAL%E34
      ! E3 x E4 -> E34 (17, 5)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*4:NCOLS*5) = VAL%E3
      ! E4 x E3 -> E34 (17, 4)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*3:NCOLS*4) = VAL%E4
      ! R x E44 -> E44 (18, 18)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*17:NCOLS*18) = VAL%R
      ! E44 x R -> E44 (18, 1)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*0:NCOLS*1) = VAL%E44
      ! E4 x E4 -> E44 (18, 5)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*4:NCOLS*5) = VAL%E4
      ! R x E15 -> E15 (19, 19)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*18:NCOLS*19) = VAL%R
      ! E15 x R -> E15 (19, 1)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*0:NCOLS*1) = VAL%E15
      ! E1 x E5 -> E15 (19, 6)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*5:NCOLS*6) = VAL%E1
      ! E5 x E1 -> E15 (19, 2)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*1:NCOLS*2) = VAL%E5
      ! R x E25 -> E25 (20, 20)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*19:NCOLS*20) = VAL%R
      ! E25 x R -> E25 (20, 1)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*0:NCOLS*1) = VAL%E25
      ! E2 x E5 -> E25 (20, 6)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*5:NCOLS*6) = VAL%E2
      ! E5 x E2 -> E25 (20, 3)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*2:NCOLS*3) = VAL%E5
      ! R x E35 -> E35 (21, 21)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*20:NCOLS*21) = VAL%R
      ! E35 x R -> E35 (21, 1)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*0:NCOLS*1) = VAL%E35
      ! E3 x E5 -> E35 (21, 6)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*5:NCOLS*6) = VAL%E3
      ! E5 x E3 -> E35 (21, 4)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*3:NCOLS*4) = VAL%E5
      ! R x E45 -> E45 (22, 22)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*21:NCOLS*22) = VAL%R
      ! E45 x R -> E45 (22, 1)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*0:NCOLS*1) = VAL%E45
      ! E4 x E5 -> E45 (22, 6)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*5:NCOLS*6) = VAL%E4
      ! E5 x E4 -> E45 (22, 5)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*4:NCOLS*5) = VAL%E5
      ! R x E55 -> E55 (23, 23)
      RES(1+NROWS*22:NROWS*23,1+NCOLS*22:NCOLS*23) = VAL%R
      ! E55 x R -> E55 (23, 1)
      RES(1+NROWS*22:NROWS*23,1+NCOLS*0:NCOLS*1) = VAL%E55
      ! E5 x E5 -> E55 (23, 6)
      RES(1+NROWS*22:NROWS*23,1+NCOLS*5:NCOLS*6) = VAL%E5
      ! R x E16 -> E16 (24, 24)
      RES(1+NROWS*23:NROWS*24,1+NCOLS*23:NCOLS*24) = VAL%R
      ! E16 x R -> E16 (24, 1)
      RES(1+NROWS*23:NROWS*24,1+NCOLS*0:NCOLS*1) = VAL%E16
      ! E1 x E6 -> E16 (24, 7)
      RES(1+NROWS*23:NROWS*24,1+NCOLS*6:NCOLS*7) = VAL%E1
      ! E6 x E1 -> E16 (24, 2)
      RES(1+NROWS*23:NROWS*24,1+NCOLS*1:NCOLS*2) = VAL%E6
      ! R x E26 -> E26 (25, 25)
      RES(1+NROWS*24:NROWS*25,1+NCOLS*24:NCOLS*25) = VAL%R
      ! E26 x R -> E26 (25, 1)
      RES(1+NROWS*24:NROWS*25,1+NCOLS*0:NCOLS*1) = VAL%E26
      ! E2 x E6 -> E26 (25, 7)
      RES(1+NROWS*24:NROWS*25,1+NCOLS*6:NCOLS*7) = VAL%E2
      ! E6 x E2 -> E26 (25, 3)
      RES(1+NROWS*24:NROWS*25,1+NCOLS*2:NCOLS*3) = VAL%E6
      ! R x E36 -> E36 (26, 26)
      RES(1+NROWS*25:NROWS*26,1+NCOLS*25:NCOLS*26) = VAL%R
      ! E36 x R -> E36 (26, 1)
      RES(1+NROWS*25:NROWS*26,1+NCOLS*0:NCOLS*1) = VAL%E36
      ! E3 x E6 -> E36 (26, 7)
      RES(1+NROWS*25:NROWS*26,1+NCOLS*6:NCOLS*7) = VAL%E3
      ! E6 x E3 -> E36 (26, 4)
      RES(1+NROWS*25:NROWS*26,1+NCOLS*3:NCOLS*4) = VAL%E6
      ! R x E46 -> E46 (27, 27)
      RES(1+NROWS*26:NROWS*27,1+NCOLS*26:NCOLS*27) = VAL%R
      ! E46 x R -> E46 (27, 1)
      RES(1+NROWS*26:NROWS*27,1+NCOLS*0:NCOLS*1) = VAL%E46
      ! E4 x E6 -> E46 (27, 7)
      RES(1+NROWS*26:NROWS*27,1+NCOLS*6:NCOLS*7) = VAL%E4
      ! E6 x E4 -> E46 (27, 5)
      RES(1+NROWS*26:NROWS*27,1+NCOLS*4:NCOLS*5) = VAL%E6
      ! R x E56 -> E56 (28, 28)
      RES(1+NROWS*27:NROWS*28,1+NCOLS*27:NCOLS*28) = VAL%R
      ! E56 x R -> E56 (28, 1)
      RES(1+NROWS*27:NROWS*28,1+NCOLS*0:NCOLS*1) = VAL%E56
      ! E5 x E6 -> E56 (28, 7)
      RES(1+NROWS*27:NROWS*28,1+NCOLS*6:NCOLS*7) = VAL%E5
      ! E6 x E5 -> E56 (28, 6)
      RES(1+NROWS*27:NROWS*28,1+NCOLS*5:NCOLS*6) = VAL%E6
      ! R x E66 -> E66 (29, 29)
      RES(1+NROWS*28:NROWS*29,1+NCOLS*28:NCOLS*29) = VAL%R
      ! E66 x R -> E66 (29, 1)
      RES(1+NROWS*28:NROWS*29,1+NCOLS*0:NCOLS*1) = VAL%E66
      ! E6 x E6 -> E66 (29, 7)
      RES(1+NROWS*28:NROWS*29,1+NCOLS*6:NCOLS*7) = VAL%E6
      ! R x E17 -> E17 (30, 30)
      RES(1+NROWS*29:NROWS*30,1+NCOLS*29:NCOLS*30) = VAL%R
      ! E17 x R -> E17 (30, 1)
      RES(1+NROWS*29:NROWS*30,1+NCOLS*0:NCOLS*1) = VAL%E17
      ! E1 x E7 -> E17 (30, 8)
      RES(1+NROWS*29:NROWS*30,1+NCOLS*7:NCOLS*8) = VAL%E1
      ! E7 x E1 -> E17 (30, 2)
      RES(1+NROWS*29:NROWS*30,1+NCOLS*1:NCOLS*2) = VAL%E7
      ! R x E27 -> E27 (31, 31)
      RES(1+NROWS*30:NROWS*31,1+NCOLS*30:NCOLS*31) = VAL%R
      ! E27 x R -> E27 (31, 1)
      RES(1+NROWS*30:NROWS*31,1+NCOLS*0:NCOLS*1) = VAL%E27
      ! E2 x E7 -> E27 (31, 8)
      RES(1+NROWS*30:NROWS*31,1+NCOLS*7:NCOLS*8) = VAL%E2
      ! E7 x E2 -> E27 (31, 3)
      RES(1+NROWS*30:NROWS*31,1+NCOLS*2:NCOLS*3) = VAL%E7
      ! R x E37 -> E37 (32, 32)
      RES(1+NROWS*31:NROWS*32,1+NCOLS*31:NCOLS*32) = VAL%R
      ! E37 x R -> E37 (32, 1)
      RES(1+NROWS*31:NROWS*32,1+NCOLS*0:NCOLS*1) = VAL%E37
      ! E3 x E7 -> E37 (32, 8)
      RES(1+NROWS*31:NROWS*32,1+NCOLS*7:NCOLS*8) = VAL%E3
      ! E7 x E3 -> E37 (32, 4)
      RES(1+NROWS*31:NROWS*32,1+NCOLS*3:NCOLS*4) = VAL%E7
      ! R x E47 -> E47 (33, 33)
      RES(1+NROWS*32:NROWS*33,1+NCOLS*32:NCOLS*33) = VAL%R
      ! E47 x R -> E47 (33, 1)
      RES(1+NROWS*32:NROWS*33,1+NCOLS*0:NCOLS*1) = VAL%E47
      ! E4 x E7 -> E47 (33, 8)
      RES(1+NROWS*32:NROWS*33,1+NCOLS*7:NCOLS*8) = VAL%E4
      ! E7 x E4 -> E47 (33, 5)
      RES(1+NROWS*32:NROWS*33,1+NCOLS*4:NCOLS*5) = VAL%E7
      ! R x E57 -> E57 (34, 34)
      RES(1+NROWS*33:NROWS*34,1+NCOLS*33:NCOLS*34) = VAL%R
      ! E57 x R -> E57 (34, 1)
      RES(1+NROWS*33:NROWS*34,1+NCOLS*0:NCOLS*1) = VAL%E57
      ! E5 x E7 -> E57 (34, 8)
      RES(1+NROWS*33:NROWS*34,1+NCOLS*7:NCOLS*8) = VAL%E5
      ! E7 x E5 -> E57 (34, 6)
      RES(1+NROWS*33:NROWS*34,1+NCOLS*5:NCOLS*6) = VAL%E7
      ! R x E67 -> E67 (35, 35)
      RES(1+NROWS*34:NROWS*35,1+NCOLS*34:NCOLS*35) = VAL%R
      ! E67 x R -> E67 (35, 1)
      RES(1+NROWS*34:NROWS*35,1+NCOLS*0:NCOLS*1) = VAL%E67
      ! E6 x E7 -> E67 (35, 8)
      RES(1+NROWS*34:NROWS*35,1+NCOLS*7:NCOLS*8) = VAL%E6
      ! E7 x E6 -> E67 (35, 7)
      RES(1+NROWS*34:NROWS*35,1+NCOLS*6:NCOLS*7) = VAL%E7
      ! R x E77 -> E77 (36, 36)
      RES(1+NROWS*35:NROWS*36,1+NCOLS*35:NCOLS*36) = VAL%R
      ! E77 x R -> E77 (36, 1)
      RES(1+NROWS*35:NROWS*36,1+NCOLS*0:NCOLS*1) = VAL%E77
      ! E7 x E7 -> E77 (36, 8)
      RES(1+NROWS*35:NROWS*36,1+NCOLS*7:NCOLS*8) = VAL%E7
   END FUNCTION ONUMM7N2_TO_CR_MAT_S

FUNCTION ONUMM7N2_TO_CR_MAT_V(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: VAL(:)
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
      ! R x E12 -> E12 (10, 10)
      RES(1+NROWS*9:NROWS*10,10) = VAL%R
      ! E12 x R -> E12 (10, 1)
      RES(1+NROWS*9:NROWS*10,1) = VAL%E12
      ! E1 x E2 -> E12 (10, 3)
      RES(1+NROWS*9:NROWS*10,3) = VAL%E1
      ! E2 x E1 -> E12 (10, 2)
      RES(1+NROWS*9:NROWS*10,2) = VAL%E2
      ! R x E22 -> E22 (11, 11)
      RES(1+NROWS*10:NROWS*11,11) = VAL%R
      ! E22 x R -> E22 (11, 1)
      RES(1+NROWS*10:NROWS*11,1) = VAL%E22
      ! E2 x E2 -> E22 (11, 3)
      RES(1+NROWS*10:NROWS*11,3) = VAL%E2
      ! R x E13 -> E13 (12, 12)
      RES(1+NROWS*11:NROWS*12,12) = VAL%R
      ! E13 x R -> E13 (12, 1)
      RES(1+NROWS*11:NROWS*12,1) = VAL%E13
      ! E1 x E3 -> E13 (12, 4)
      RES(1+NROWS*11:NROWS*12,4) = VAL%E1
      ! E3 x E1 -> E13 (12, 2)
      RES(1+NROWS*11:NROWS*12,2) = VAL%E3
      ! R x E23 -> E23 (13, 13)
      RES(1+NROWS*12:NROWS*13,13) = VAL%R
      ! E23 x R -> E23 (13, 1)
      RES(1+NROWS*12:NROWS*13,1) = VAL%E23
      ! E2 x E3 -> E23 (13, 4)
      RES(1+NROWS*12:NROWS*13,4) = VAL%E2
      ! E3 x E2 -> E23 (13, 3)
      RES(1+NROWS*12:NROWS*13,3) = VAL%E3
      ! R x E33 -> E33 (14, 14)
      RES(1+NROWS*13:NROWS*14,14) = VAL%R
      ! E33 x R -> E33 (14, 1)
      RES(1+NROWS*13:NROWS*14,1) = VAL%E33
      ! E3 x E3 -> E33 (14, 4)
      RES(1+NROWS*13:NROWS*14,4) = VAL%E3
      ! R x E14 -> E14 (15, 15)
      RES(1+NROWS*14:NROWS*15,15) = VAL%R
      ! E14 x R -> E14 (15, 1)
      RES(1+NROWS*14:NROWS*15,1) = VAL%E14
      ! E1 x E4 -> E14 (15, 5)
      RES(1+NROWS*14:NROWS*15,5) = VAL%E1
      ! E4 x E1 -> E14 (15, 2)
      RES(1+NROWS*14:NROWS*15,2) = VAL%E4
      ! R x E24 -> E24 (16, 16)
      RES(1+NROWS*15:NROWS*16,16) = VAL%R
      ! E24 x R -> E24 (16, 1)
      RES(1+NROWS*15:NROWS*16,1) = VAL%E24
      ! E2 x E4 -> E24 (16, 5)
      RES(1+NROWS*15:NROWS*16,5) = VAL%E2
      ! E4 x E2 -> E24 (16, 3)
      RES(1+NROWS*15:NROWS*16,3) = VAL%E4
      ! R x E34 -> E34 (17, 17)
      RES(1+NROWS*16:NROWS*17,17) = VAL%R
      ! E34 x R -> E34 (17, 1)
      RES(1+NROWS*16:NROWS*17,1) = VAL%E34
      ! E3 x E4 -> E34 (17, 5)
      RES(1+NROWS*16:NROWS*17,5) = VAL%E3
      ! E4 x E3 -> E34 (17, 4)
      RES(1+NROWS*16:NROWS*17,4) = VAL%E4
      ! R x E44 -> E44 (18, 18)
      RES(1+NROWS*17:NROWS*18,18) = VAL%R
      ! E44 x R -> E44 (18, 1)
      RES(1+NROWS*17:NROWS*18,1) = VAL%E44
      ! E4 x E4 -> E44 (18, 5)
      RES(1+NROWS*17:NROWS*18,5) = VAL%E4
      ! R x E15 -> E15 (19, 19)
      RES(1+NROWS*18:NROWS*19,19) = VAL%R
      ! E15 x R -> E15 (19, 1)
      RES(1+NROWS*18:NROWS*19,1) = VAL%E15
      ! E1 x E5 -> E15 (19, 6)
      RES(1+NROWS*18:NROWS*19,6) = VAL%E1
      ! E5 x E1 -> E15 (19, 2)
      RES(1+NROWS*18:NROWS*19,2) = VAL%E5
      ! R x E25 -> E25 (20, 20)
      RES(1+NROWS*19:NROWS*20,20) = VAL%R
      ! E25 x R -> E25 (20, 1)
      RES(1+NROWS*19:NROWS*20,1) = VAL%E25
      ! E2 x E5 -> E25 (20, 6)
      RES(1+NROWS*19:NROWS*20,6) = VAL%E2
      ! E5 x E2 -> E25 (20, 3)
      RES(1+NROWS*19:NROWS*20,3) = VAL%E5
      ! R x E35 -> E35 (21, 21)
      RES(1+NROWS*20:NROWS*21,21) = VAL%R
      ! E35 x R -> E35 (21, 1)
      RES(1+NROWS*20:NROWS*21,1) = VAL%E35
      ! E3 x E5 -> E35 (21, 6)
      RES(1+NROWS*20:NROWS*21,6) = VAL%E3
      ! E5 x E3 -> E35 (21, 4)
      RES(1+NROWS*20:NROWS*21,4) = VAL%E5
      ! R x E45 -> E45 (22, 22)
      RES(1+NROWS*21:NROWS*22,22) = VAL%R
      ! E45 x R -> E45 (22, 1)
      RES(1+NROWS*21:NROWS*22,1) = VAL%E45
      ! E4 x E5 -> E45 (22, 6)
      RES(1+NROWS*21:NROWS*22,6) = VAL%E4
      ! E5 x E4 -> E45 (22, 5)
      RES(1+NROWS*21:NROWS*22,5) = VAL%E5
      ! R x E55 -> E55 (23, 23)
      RES(1+NROWS*22:NROWS*23,23) = VAL%R
      ! E55 x R -> E55 (23, 1)
      RES(1+NROWS*22:NROWS*23,1) = VAL%E55
      ! E5 x E5 -> E55 (23, 6)
      RES(1+NROWS*22:NROWS*23,6) = VAL%E5
      ! R x E16 -> E16 (24, 24)
      RES(1+NROWS*23:NROWS*24,24) = VAL%R
      ! E16 x R -> E16 (24, 1)
      RES(1+NROWS*23:NROWS*24,1) = VAL%E16
      ! E1 x E6 -> E16 (24, 7)
      RES(1+NROWS*23:NROWS*24,7) = VAL%E1
      ! E6 x E1 -> E16 (24, 2)
      RES(1+NROWS*23:NROWS*24,2) = VAL%E6
      ! R x E26 -> E26 (25, 25)
      RES(1+NROWS*24:NROWS*25,25) = VAL%R
      ! E26 x R -> E26 (25, 1)
      RES(1+NROWS*24:NROWS*25,1) = VAL%E26
      ! E2 x E6 -> E26 (25, 7)
      RES(1+NROWS*24:NROWS*25,7) = VAL%E2
      ! E6 x E2 -> E26 (25, 3)
      RES(1+NROWS*24:NROWS*25,3) = VAL%E6
      ! R x E36 -> E36 (26, 26)
      RES(1+NROWS*25:NROWS*26,26) = VAL%R
      ! E36 x R -> E36 (26, 1)
      RES(1+NROWS*25:NROWS*26,1) = VAL%E36
      ! E3 x E6 -> E36 (26, 7)
      RES(1+NROWS*25:NROWS*26,7) = VAL%E3
      ! E6 x E3 -> E36 (26, 4)
      RES(1+NROWS*25:NROWS*26,4) = VAL%E6
      ! R x E46 -> E46 (27, 27)
      RES(1+NROWS*26:NROWS*27,27) = VAL%R
      ! E46 x R -> E46 (27, 1)
      RES(1+NROWS*26:NROWS*27,1) = VAL%E46
      ! E4 x E6 -> E46 (27, 7)
      RES(1+NROWS*26:NROWS*27,7) = VAL%E4
      ! E6 x E4 -> E46 (27, 5)
      RES(1+NROWS*26:NROWS*27,5) = VAL%E6
      ! R x E56 -> E56 (28, 28)
      RES(1+NROWS*27:NROWS*28,28) = VAL%R
      ! E56 x R -> E56 (28, 1)
      RES(1+NROWS*27:NROWS*28,1) = VAL%E56
      ! E5 x E6 -> E56 (28, 7)
      RES(1+NROWS*27:NROWS*28,7) = VAL%E5
      ! E6 x E5 -> E56 (28, 6)
      RES(1+NROWS*27:NROWS*28,6) = VAL%E6
      ! R x E66 -> E66 (29, 29)
      RES(1+NROWS*28:NROWS*29,29) = VAL%R
      ! E66 x R -> E66 (29, 1)
      RES(1+NROWS*28:NROWS*29,1) = VAL%E66
      ! E6 x E6 -> E66 (29, 7)
      RES(1+NROWS*28:NROWS*29,7) = VAL%E6
      ! R x E17 -> E17 (30, 30)
      RES(1+NROWS*29:NROWS*30,30) = VAL%R
      ! E17 x R -> E17 (30, 1)
      RES(1+NROWS*29:NROWS*30,1) = VAL%E17
      ! E1 x E7 -> E17 (30, 8)
      RES(1+NROWS*29:NROWS*30,8) = VAL%E1
      ! E7 x E1 -> E17 (30, 2)
      RES(1+NROWS*29:NROWS*30,2) = VAL%E7
      ! R x E27 -> E27 (31, 31)
      RES(1+NROWS*30:NROWS*31,31) = VAL%R
      ! E27 x R -> E27 (31, 1)
      RES(1+NROWS*30:NROWS*31,1) = VAL%E27
      ! E2 x E7 -> E27 (31, 8)
      RES(1+NROWS*30:NROWS*31,8) = VAL%E2
      ! E7 x E2 -> E27 (31, 3)
      RES(1+NROWS*30:NROWS*31,3) = VAL%E7
      ! R x E37 -> E37 (32, 32)
      RES(1+NROWS*31:NROWS*32,32) = VAL%R
      ! E37 x R -> E37 (32, 1)
      RES(1+NROWS*31:NROWS*32,1) = VAL%E37
      ! E3 x E7 -> E37 (32, 8)
      RES(1+NROWS*31:NROWS*32,8) = VAL%E3
      ! E7 x E3 -> E37 (32, 4)
      RES(1+NROWS*31:NROWS*32,4) = VAL%E7
      ! R x E47 -> E47 (33, 33)
      RES(1+NROWS*32:NROWS*33,33) = VAL%R
      ! E47 x R -> E47 (33, 1)
      RES(1+NROWS*32:NROWS*33,1) = VAL%E47
      ! E4 x E7 -> E47 (33, 8)
      RES(1+NROWS*32:NROWS*33,8) = VAL%E4
      ! E7 x E4 -> E47 (33, 5)
      RES(1+NROWS*32:NROWS*33,5) = VAL%E7
      ! R x E57 -> E57 (34, 34)
      RES(1+NROWS*33:NROWS*34,34) = VAL%R
      ! E57 x R -> E57 (34, 1)
      RES(1+NROWS*33:NROWS*34,1) = VAL%E57
      ! E5 x E7 -> E57 (34, 8)
      RES(1+NROWS*33:NROWS*34,8) = VAL%E5
      ! E7 x E5 -> E57 (34, 6)
      RES(1+NROWS*33:NROWS*34,6) = VAL%E7
      ! R x E67 -> E67 (35, 35)
      RES(1+NROWS*34:NROWS*35,35) = VAL%R
      ! E67 x R -> E67 (35, 1)
      RES(1+NROWS*34:NROWS*35,1) = VAL%E67
      ! E6 x E7 -> E67 (35, 8)
      RES(1+NROWS*34:NROWS*35,8) = VAL%E6
      ! E7 x E6 -> E67 (35, 7)
      RES(1+NROWS*34:NROWS*35,7) = VAL%E7
      ! R x E77 -> E77 (36, 36)
      RES(1+NROWS*35:NROWS*36,36) = VAL%R
      ! E77 x R -> E77 (36, 1)
      RES(1+NROWS*35:NROWS*36,1) = VAL%E77
      ! E7 x E7 -> E77 (36, 8)
      RES(1+NROWS*35:NROWS*36,8) = VAL%E7
   END FUNCTION ONUMM7N2_TO_CR_MAT_V

FUNCTION ONUMM7N2_TO_CR_MAT_M(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: VAL(:,:)
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
      ! R x E12 -> E12 (10, 10)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*9:NCOLS*10) = VAL%R
      ! E12 x R -> E12 (10, 1)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*0:NCOLS*1) = VAL%E12
      ! E1 x E2 -> E12 (10, 3)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*2:NCOLS*3) = VAL%E1
      ! E2 x E1 -> E12 (10, 2)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*1:NCOLS*2) = VAL%E2
      ! R x E22 -> E22 (11, 11)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*10:NCOLS*11) = VAL%R
      ! E22 x R -> E22 (11, 1)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*0:NCOLS*1) = VAL%E22
      ! E2 x E2 -> E22 (11, 3)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*2:NCOLS*3) = VAL%E2
      ! R x E13 -> E13 (12, 12)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*11:NCOLS*12) = VAL%R
      ! E13 x R -> E13 (12, 1)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*0:NCOLS*1) = VAL%E13
      ! E1 x E3 -> E13 (12, 4)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*3:NCOLS*4) = VAL%E1
      ! E3 x E1 -> E13 (12, 2)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*1:NCOLS*2) = VAL%E3
      ! R x E23 -> E23 (13, 13)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*12:NCOLS*13) = VAL%R
      ! E23 x R -> E23 (13, 1)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*0:NCOLS*1) = VAL%E23
      ! E2 x E3 -> E23 (13, 4)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*3:NCOLS*4) = VAL%E2
      ! E3 x E2 -> E23 (13, 3)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*2:NCOLS*3) = VAL%E3
      ! R x E33 -> E33 (14, 14)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*13:NCOLS*14) = VAL%R
      ! E33 x R -> E33 (14, 1)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*0:NCOLS*1) = VAL%E33
      ! E3 x E3 -> E33 (14, 4)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*3:NCOLS*4) = VAL%E3
      ! R x E14 -> E14 (15, 15)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*14:NCOLS*15) = VAL%R
      ! E14 x R -> E14 (15, 1)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*0:NCOLS*1) = VAL%E14
      ! E1 x E4 -> E14 (15, 5)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*4:NCOLS*5) = VAL%E1
      ! E4 x E1 -> E14 (15, 2)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*1:NCOLS*2) = VAL%E4
      ! R x E24 -> E24 (16, 16)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*15:NCOLS*16) = VAL%R
      ! E24 x R -> E24 (16, 1)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*0:NCOLS*1) = VAL%E24
      ! E2 x E4 -> E24 (16, 5)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*4:NCOLS*5) = VAL%E2
      ! E4 x E2 -> E24 (16, 3)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*2:NCOLS*3) = VAL%E4
      ! R x E34 -> E34 (17, 17)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*16:NCOLS*17) = VAL%R
      ! E34 x R -> E34 (17, 1)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*0:NCOLS*1) = VAL%E34
      ! E3 x E4 -> E34 (17, 5)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*4:NCOLS*5) = VAL%E3
      ! E4 x E3 -> E34 (17, 4)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*3:NCOLS*4) = VAL%E4
      ! R x E44 -> E44 (18, 18)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*17:NCOLS*18) = VAL%R
      ! E44 x R -> E44 (18, 1)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*0:NCOLS*1) = VAL%E44
      ! E4 x E4 -> E44 (18, 5)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*4:NCOLS*5) = VAL%E4
      ! R x E15 -> E15 (19, 19)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*18:NCOLS*19) = VAL%R
      ! E15 x R -> E15 (19, 1)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*0:NCOLS*1) = VAL%E15
      ! E1 x E5 -> E15 (19, 6)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*5:NCOLS*6) = VAL%E1
      ! E5 x E1 -> E15 (19, 2)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*1:NCOLS*2) = VAL%E5
      ! R x E25 -> E25 (20, 20)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*19:NCOLS*20) = VAL%R
      ! E25 x R -> E25 (20, 1)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*0:NCOLS*1) = VAL%E25
      ! E2 x E5 -> E25 (20, 6)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*5:NCOLS*6) = VAL%E2
      ! E5 x E2 -> E25 (20, 3)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*2:NCOLS*3) = VAL%E5
      ! R x E35 -> E35 (21, 21)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*20:NCOLS*21) = VAL%R
      ! E35 x R -> E35 (21, 1)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*0:NCOLS*1) = VAL%E35
      ! E3 x E5 -> E35 (21, 6)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*5:NCOLS*6) = VAL%E3
      ! E5 x E3 -> E35 (21, 4)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*3:NCOLS*4) = VAL%E5
      ! R x E45 -> E45 (22, 22)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*21:NCOLS*22) = VAL%R
      ! E45 x R -> E45 (22, 1)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*0:NCOLS*1) = VAL%E45
      ! E4 x E5 -> E45 (22, 6)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*5:NCOLS*6) = VAL%E4
      ! E5 x E4 -> E45 (22, 5)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*4:NCOLS*5) = VAL%E5
      ! R x E55 -> E55 (23, 23)
      RES(1+NROWS*22:NROWS*23,1+NCOLS*22:NCOLS*23) = VAL%R
      ! E55 x R -> E55 (23, 1)
      RES(1+NROWS*22:NROWS*23,1+NCOLS*0:NCOLS*1) = VAL%E55
      ! E5 x E5 -> E55 (23, 6)
      RES(1+NROWS*22:NROWS*23,1+NCOLS*5:NCOLS*6) = VAL%E5
      ! R x E16 -> E16 (24, 24)
      RES(1+NROWS*23:NROWS*24,1+NCOLS*23:NCOLS*24) = VAL%R
      ! E16 x R -> E16 (24, 1)
      RES(1+NROWS*23:NROWS*24,1+NCOLS*0:NCOLS*1) = VAL%E16
      ! E1 x E6 -> E16 (24, 7)
      RES(1+NROWS*23:NROWS*24,1+NCOLS*6:NCOLS*7) = VAL%E1
      ! E6 x E1 -> E16 (24, 2)
      RES(1+NROWS*23:NROWS*24,1+NCOLS*1:NCOLS*2) = VAL%E6
      ! R x E26 -> E26 (25, 25)
      RES(1+NROWS*24:NROWS*25,1+NCOLS*24:NCOLS*25) = VAL%R
      ! E26 x R -> E26 (25, 1)
      RES(1+NROWS*24:NROWS*25,1+NCOLS*0:NCOLS*1) = VAL%E26
      ! E2 x E6 -> E26 (25, 7)
      RES(1+NROWS*24:NROWS*25,1+NCOLS*6:NCOLS*7) = VAL%E2
      ! E6 x E2 -> E26 (25, 3)
      RES(1+NROWS*24:NROWS*25,1+NCOLS*2:NCOLS*3) = VAL%E6
      ! R x E36 -> E36 (26, 26)
      RES(1+NROWS*25:NROWS*26,1+NCOLS*25:NCOLS*26) = VAL%R
      ! E36 x R -> E36 (26, 1)
      RES(1+NROWS*25:NROWS*26,1+NCOLS*0:NCOLS*1) = VAL%E36
      ! E3 x E6 -> E36 (26, 7)
      RES(1+NROWS*25:NROWS*26,1+NCOLS*6:NCOLS*7) = VAL%E3
      ! E6 x E3 -> E36 (26, 4)
      RES(1+NROWS*25:NROWS*26,1+NCOLS*3:NCOLS*4) = VAL%E6
      ! R x E46 -> E46 (27, 27)
      RES(1+NROWS*26:NROWS*27,1+NCOLS*26:NCOLS*27) = VAL%R
      ! E46 x R -> E46 (27, 1)
      RES(1+NROWS*26:NROWS*27,1+NCOLS*0:NCOLS*1) = VAL%E46
      ! E4 x E6 -> E46 (27, 7)
      RES(1+NROWS*26:NROWS*27,1+NCOLS*6:NCOLS*7) = VAL%E4
      ! E6 x E4 -> E46 (27, 5)
      RES(1+NROWS*26:NROWS*27,1+NCOLS*4:NCOLS*5) = VAL%E6
      ! R x E56 -> E56 (28, 28)
      RES(1+NROWS*27:NROWS*28,1+NCOLS*27:NCOLS*28) = VAL%R
      ! E56 x R -> E56 (28, 1)
      RES(1+NROWS*27:NROWS*28,1+NCOLS*0:NCOLS*1) = VAL%E56
      ! E5 x E6 -> E56 (28, 7)
      RES(1+NROWS*27:NROWS*28,1+NCOLS*6:NCOLS*7) = VAL%E5
      ! E6 x E5 -> E56 (28, 6)
      RES(1+NROWS*27:NROWS*28,1+NCOLS*5:NCOLS*6) = VAL%E6
      ! R x E66 -> E66 (29, 29)
      RES(1+NROWS*28:NROWS*29,1+NCOLS*28:NCOLS*29) = VAL%R
      ! E66 x R -> E66 (29, 1)
      RES(1+NROWS*28:NROWS*29,1+NCOLS*0:NCOLS*1) = VAL%E66
      ! E6 x E6 -> E66 (29, 7)
      RES(1+NROWS*28:NROWS*29,1+NCOLS*6:NCOLS*7) = VAL%E6
      ! R x E17 -> E17 (30, 30)
      RES(1+NROWS*29:NROWS*30,1+NCOLS*29:NCOLS*30) = VAL%R
      ! E17 x R -> E17 (30, 1)
      RES(1+NROWS*29:NROWS*30,1+NCOLS*0:NCOLS*1) = VAL%E17
      ! E1 x E7 -> E17 (30, 8)
      RES(1+NROWS*29:NROWS*30,1+NCOLS*7:NCOLS*8) = VAL%E1
      ! E7 x E1 -> E17 (30, 2)
      RES(1+NROWS*29:NROWS*30,1+NCOLS*1:NCOLS*2) = VAL%E7
      ! R x E27 -> E27 (31, 31)
      RES(1+NROWS*30:NROWS*31,1+NCOLS*30:NCOLS*31) = VAL%R
      ! E27 x R -> E27 (31, 1)
      RES(1+NROWS*30:NROWS*31,1+NCOLS*0:NCOLS*1) = VAL%E27
      ! E2 x E7 -> E27 (31, 8)
      RES(1+NROWS*30:NROWS*31,1+NCOLS*7:NCOLS*8) = VAL%E2
      ! E7 x E2 -> E27 (31, 3)
      RES(1+NROWS*30:NROWS*31,1+NCOLS*2:NCOLS*3) = VAL%E7
      ! R x E37 -> E37 (32, 32)
      RES(1+NROWS*31:NROWS*32,1+NCOLS*31:NCOLS*32) = VAL%R
      ! E37 x R -> E37 (32, 1)
      RES(1+NROWS*31:NROWS*32,1+NCOLS*0:NCOLS*1) = VAL%E37
      ! E3 x E7 -> E37 (32, 8)
      RES(1+NROWS*31:NROWS*32,1+NCOLS*7:NCOLS*8) = VAL%E3
      ! E7 x E3 -> E37 (32, 4)
      RES(1+NROWS*31:NROWS*32,1+NCOLS*3:NCOLS*4) = VAL%E7
      ! R x E47 -> E47 (33, 33)
      RES(1+NROWS*32:NROWS*33,1+NCOLS*32:NCOLS*33) = VAL%R
      ! E47 x R -> E47 (33, 1)
      RES(1+NROWS*32:NROWS*33,1+NCOLS*0:NCOLS*1) = VAL%E47
      ! E4 x E7 -> E47 (33, 8)
      RES(1+NROWS*32:NROWS*33,1+NCOLS*7:NCOLS*8) = VAL%E4
      ! E7 x E4 -> E47 (33, 5)
      RES(1+NROWS*32:NROWS*33,1+NCOLS*4:NCOLS*5) = VAL%E7
      ! R x E57 -> E57 (34, 34)
      RES(1+NROWS*33:NROWS*34,1+NCOLS*33:NCOLS*34) = VAL%R
      ! E57 x R -> E57 (34, 1)
      RES(1+NROWS*33:NROWS*34,1+NCOLS*0:NCOLS*1) = VAL%E57
      ! E5 x E7 -> E57 (34, 8)
      RES(1+NROWS*33:NROWS*34,1+NCOLS*7:NCOLS*8) = VAL%E5
      ! E7 x E5 -> E57 (34, 6)
      RES(1+NROWS*33:NROWS*34,1+NCOLS*5:NCOLS*6) = VAL%E7
      ! R x E67 -> E67 (35, 35)
      RES(1+NROWS*34:NROWS*35,1+NCOLS*34:NCOLS*35) = VAL%R
      ! E67 x R -> E67 (35, 1)
      RES(1+NROWS*34:NROWS*35,1+NCOLS*0:NCOLS*1) = VAL%E67
      ! E6 x E7 -> E67 (35, 8)
      RES(1+NROWS*34:NROWS*35,1+NCOLS*7:NCOLS*8) = VAL%E6
      ! E7 x E6 -> E67 (35, 7)
      RES(1+NROWS*34:NROWS*35,1+NCOLS*6:NCOLS*7) = VAL%E7
      ! R x E77 -> E77 (36, 36)
      RES(1+NROWS*35:NROWS*36,1+NCOLS*35:NCOLS*36) = VAL%R
      ! E77 x R -> E77 (36, 1)
      RES(1+NROWS*35:NROWS*36,1+NCOLS*0:NCOLS*1) = VAL%E77
      ! E7 x E7 -> E77 (36, 8)
      RES(1+NROWS*35:NROWS*36,1+NCOLS*7:NCOLS*8) = VAL%E7
   END FUNCTION ONUMM7N2_TO_CR_MAT_M

      SUBROUTINE ONUMM7N2_SETIM_S(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(INOUT) :: VAL
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
         VAL%E12=RES
      CASE(10)
         VAL%E22=RES
      CASE(11)
         VAL%E13=RES
      CASE(12)
         VAL%E23=RES
      CASE(13)
         VAL%E33=RES
      CASE(14)
         VAL%E14=RES
      CASE(15)
         VAL%E24=RES
      CASE(16)
         VAL%E34=RES
      CASE(17)
         VAL%E44=RES
      CASE(18)
         VAL%E15=RES
      CASE(19)
         VAL%E25=RES
      CASE(20)
         VAL%E35=RES
      CASE(21)
         VAL%E45=RES
      CASE(22)
         VAL%E55=RES
      CASE(23)
         VAL%E16=RES
      CASE(24)
         VAL%E26=RES
      CASE(25)
         VAL%E36=RES
      CASE(26)
         VAL%E46=RES
      CASE(27)
         VAL%E56=RES
      CASE(28)
         VAL%E66=RES
      CASE(29)
         VAL%E17=RES
      CASE(30)
         VAL%E27=RES
      CASE(31)
         VAL%E37=RES
      CASE(32)
         VAL%E47=RES
      CASE(33)
         VAL%E57=RES
      CASE(34)
         VAL%E67=RES
      CASE(35)
         VAL%E77=RES

      END SELECT
   END SUBROUTINE ONUMM7N2_SETIM_S

      SUBROUTINE ONUMM7N2_SETIM_V(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(INOUT) :: VAL(:)
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
         VAL%E12=RES
      CASE(10)
         VAL%E22=RES
      CASE(11)
         VAL%E13=RES
      CASE(12)
         VAL%E23=RES
      CASE(13)
         VAL%E33=RES
      CASE(14)
         VAL%E14=RES
      CASE(15)
         VAL%E24=RES
      CASE(16)
         VAL%E34=RES
      CASE(17)
         VAL%E44=RES
      CASE(18)
         VAL%E15=RES
      CASE(19)
         VAL%E25=RES
      CASE(20)
         VAL%E35=RES
      CASE(21)
         VAL%E45=RES
      CASE(22)
         VAL%E55=RES
      CASE(23)
         VAL%E16=RES
      CASE(24)
         VAL%E26=RES
      CASE(25)
         VAL%E36=RES
      CASE(26)
         VAL%E46=RES
      CASE(27)
         VAL%E56=RES
      CASE(28)
         VAL%E66=RES
      CASE(29)
         VAL%E17=RES
      CASE(30)
         VAL%E27=RES
      CASE(31)
         VAL%E37=RES
      CASE(32)
         VAL%E47=RES
      CASE(33)
         VAL%E57=RES
      CASE(34)
         VAL%E67=RES
      CASE(35)
         VAL%E77=RES

      END SELECT
   END SUBROUTINE ONUMM7N2_SETIM_V

      SUBROUTINE ONUMM7N2_SETIM_M(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(INOUT) :: VAL(:,:)
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
         VAL%E12=RES
      CASE(10)
         VAL%E22=RES
      CASE(11)
         VAL%E13=RES
      CASE(12)
         VAL%E23=RES
      CASE(13)
         VAL%E33=RES
      CASE(14)
         VAL%E14=RES
      CASE(15)
         VAL%E24=RES
      CASE(16)
         VAL%E34=RES
      CASE(17)
         VAL%E44=RES
      CASE(18)
         VAL%E15=RES
      CASE(19)
         VAL%E25=RES
      CASE(20)
         VAL%E35=RES
      CASE(21)
         VAL%E45=RES
      CASE(22)
         VAL%E55=RES
      CASE(23)
         VAL%E16=RES
      CASE(24)
         VAL%E26=RES
      CASE(25)
         VAL%E36=RES
      CASE(26)
         VAL%E46=RES
      CASE(27)
         VAL%E56=RES
      CASE(28)
         VAL%E66=RES
      CASE(29)
         VAL%E17=RES
      CASE(30)
         VAL%E27=RES
      CASE(31)
         VAL%E37=RES
      CASE(32)
         VAL%E47=RES
      CASE(33)
         VAL%E57=RES
      CASE(34)
         VAL%E67=RES
      CASE(35)
         VAL%E77=RES

      END SELECT
   END SUBROUTINE ONUMM7N2_SETIM_M

FUNCTION ONUMM7N2_GETIM_S(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: VAL
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
         RES=VAL%E12
      CASE(10)
         RES=VAL%E22
      CASE(11)
         RES=VAL%E13
      CASE(12)
         RES=VAL%E23
      CASE(13)
         RES=VAL%E33
      CASE(14)
         RES=VAL%E14
      CASE(15)
         RES=VAL%E24
      CASE(16)
         RES=VAL%E34
      CASE(17)
         RES=VAL%E44
      CASE(18)
         RES=VAL%E15
      CASE(19)
         RES=VAL%E25
      CASE(20)
         RES=VAL%E35
      CASE(21)
         RES=VAL%E45
      CASE(22)
         RES=VAL%E55
      CASE(23)
         RES=VAL%E16
      CASE(24)
         RES=VAL%E26
      CASE(25)
         RES=VAL%E36
      CASE(26)
         RES=VAL%E46
      CASE(27)
         RES=VAL%E56
      CASE(28)
         RES=VAL%E66
      CASE(29)
         RES=VAL%E17
      CASE(30)
         RES=VAL%E27
      CASE(31)
         RES=VAL%E37
      CASE(32)
         RES=VAL%E47
      CASE(33)
         RES=VAL%E57
      CASE(34)
         RES=VAL%E67
      CASE(35)
         RES=VAL%E77

      END SELECT
   END FUNCTION ONUMM7N2_GETIM_S

FUNCTION ONUMM7N2_GETIM_V(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: VAL(:)
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
         RES=VAL%E12
      CASE(10)
         RES=VAL%E22
      CASE(11)
         RES=VAL%E13
      CASE(12)
         RES=VAL%E23
      CASE(13)
         RES=VAL%E33
      CASE(14)
         RES=VAL%E14
      CASE(15)
         RES=VAL%E24
      CASE(16)
         RES=VAL%E34
      CASE(17)
         RES=VAL%E44
      CASE(18)
         RES=VAL%E15
      CASE(19)
         RES=VAL%E25
      CASE(20)
         RES=VAL%E35
      CASE(21)
         RES=VAL%E45
      CASE(22)
         RES=VAL%E55
      CASE(23)
         RES=VAL%E16
      CASE(24)
         RES=VAL%E26
      CASE(25)
         RES=VAL%E36
      CASE(26)
         RES=VAL%E46
      CASE(27)
         RES=VAL%E56
      CASE(28)
         RES=VAL%E66
      CASE(29)
         RES=VAL%E17
      CASE(30)
         RES=VAL%E27
      CASE(31)
         RES=VAL%E37
      CASE(32)
         RES=VAL%E47
      CASE(33)
         RES=VAL%E57
      CASE(34)
         RES=VAL%E67
      CASE(35)
         RES=VAL%E77

      END SELECT
   END FUNCTION ONUMM7N2_GETIM_V

FUNCTION ONUMM7N2_GETIM_M(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: VAL(:,:)
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
         RES=VAL%E12
      CASE(10)
         RES=VAL%E22
      CASE(11)
         RES=VAL%E13
      CASE(12)
         RES=VAL%E23
      CASE(13)
         RES=VAL%E33
      CASE(14)
         RES=VAL%E14
      CASE(15)
         RES=VAL%E24
      CASE(16)
         RES=VAL%E34
      CASE(17)
         RES=VAL%E44
      CASE(18)
         RES=VAL%E15
      CASE(19)
         RES=VAL%E25
      CASE(20)
         RES=VAL%E35
      CASE(21)
         RES=VAL%E45
      CASE(22)
         RES=VAL%E55
      CASE(23)
         RES=VAL%E16
      CASE(24)
         RES=VAL%E26
      CASE(25)
         RES=VAL%E36
      CASE(26)
         RES=VAL%E46
      CASE(27)
         RES=VAL%E56
      CASE(28)
         RES=VAL%E66
      CASE(29)
         RES=VAL%E17
      CASE(30)
         RES=VAL%E27
      CASE(31)
         RES=VAL%E37
      CASE(32)
         RES=VAL%E47
      CASE(33)
         RES=VAL%E57
      CASE(34)
         RES=VAL%E67
      CASE(35)
         RES=VAL%E77

      END SELECT
   END FUNCTION ONUMM7N2_GETIM_M

   SUBROUTINE ONUMM7N2_PPRINT_S(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: VAR
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
      WRITE(unt,'(A)',advance='NO') 'E12 * '
      CALL PPRINT(VAR%E12,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E22 * '
      CALL PPRINT(VAR%E22,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E13 * '
      CALL PPRINT(VAR%E13,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E23 * '
      CALL PPRINT(VAR%E23,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E33 * '
      CALL PPRINT(VAR%E33,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E14 * '
      CALL PPRINT(VAR%E14,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E24 * '
      CALL PPRINT(VAR%E24,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E34 * '
      CALL PPRINT(VAR%E34,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E44 * '
      CALL PPRINT(VAR%E44,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E15 * '
      CALL PPRINT(VAR%E15,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E25 * '
      CALL PPRINT(VAR%E25,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E35 * '
      CALL PPRINT(VAR%E35,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E45 * '
      CALL PPRINT(VAR%E45,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E55 * '
      CALL PPRINT(VAR%E55,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E16 * '
      CALL PPRINT(VAR%E16,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E26 * '
      CALL PPRINT(VAR%E26,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E36 * '
      CALL PPRINT(VAR%E36,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E46 * '
      CALL PPRINT(VAR%E46,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E56 * '
      CALL PPRINT(VAR%E56,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E66 * '
      CALL PPRINT(VAR%E66,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E17 * '
      CALL PPRINT(VAR%E17,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E27 * '
      CALL PPRINT(VAR%E27,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E37 * '
      CALL PPRINT(VAR%E37,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E47 * '
      CALL PPRINT(VAR%E47,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E57 * '
      CALL PPRINT(VAR%E57,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E67 * '
      CALL PPRINT(VAR%E67,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E77 * '
      CALL PPRINT(VAR%E77,unit=unt,fmt=output_format)


   END SUBROUTINE ONUMM7N2_PPRINT_S

   SUBROUTINE ONUMM7N2_PPRINT_V(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: VAR(:)
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
      WRITE(unt,'(A)',advance='YES') 'E12 * '
      CALL PPRINT(VAR%E12,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E22 * '
      CALL PPRINT(VAR%E22,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E13 * '
      CALL PPRINT(VAR%E13,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E23 * '
      CALL PPRINT(VAR%E23,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E33 * '
      CALL PPRINT(VAR%E33,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E14 * '
      CALL PPRINT(VAR%E14,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E24 * '
      CALL PPRINT(VAR%E24,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E34 * '
      CALL PPRINT(VAR%E34,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E44 * '
      CALL PPRINT(VAR%E44,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E15 * '
      CALL PPRINT(VAR%E15,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E25 * '
      CALL PPRINT(VAR%E25,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E35 * '
      CALL PPRINT(VAR%E35,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E45 * '
      CALL PPRINT(VAR%E45,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E55 * '
      CALL PPRINT(VAR%E55,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E16 * '
      CALL PPRINT(VAR%E16,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E26 * '
      CALL PPRINT(VAR%E26,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E36 * '
      CALL PPRINT(VAR%E36,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E46 * '
      CALL PPRINT(VAR%E46,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E56 * '
      CALL PPRINT(VAR%E56,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E66 * '
      CALL PPRINT(VAR%E66,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E17 * '
      CALL PPRINT(VAR%E17,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E27 * '
      CALL PPRINT(VAR%E27,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E37 * '
      CALL PPRINT(VAR%E37,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E47 * '
      CALL PPRINT(VAR%E47,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E57 * '
      CALL PPRINT(VAR%E57,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E67 * '
      CALL PPRINT(VAR%E67,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E77 * '
      CALL PPRINT(VAR%E77,unit=unt,fmt=output_format)


   END SUBROUTINE ONUMM7N2_PPRINT_V

   SUBROUTINE ONUMM7N2_PPRINT_M(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: VAR(:,:)
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
      WRITE(unt,'(A)',advance='YES') 'E12 * '
      CALL PPRINT(VAR%E12,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E22 * '
      CALL PPRINT(VAR%E22,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E13 * '
      CALL PPRINT(VAR%E13,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E23 * '
      CALL PPRINT(VAR%E23,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E33 * '
      CALL PPRINT(VAR%E33,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E14 * '
      CALL PPRINT(VAR%E14,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E24 * '
      CALL PPRINT(VAR%E24,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E34 * '
      CALL PPRINT(VAR%E34,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E44 * '
      CALL PPRINT(VAR%E44,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E15 * '
      CALL PPRINT(VAR%E15,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E25 * '
      CALL PPRINT(VAR%E25,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E35 * '
      CALL PPRINT(VAR%E35,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E45 * '
      CALL PPRINT(VAR%E45,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E55 * '
      CALL PPRINT(VAR%E55,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E16 * '
      CALL PPRINT(VAR%E16,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E26 * '
      CALL PPRINT(VAR%E26,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E36 * '
      CALL PPRINT(VAR%E36,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E46 * '
      CALL PPRINT(VAR%E46,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E56 * '
      CALL PPRINT(VAR%E56,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E66 * '
      CALL PPRINT(VAR%E66,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E17 * '
      CALL PPRINT(VAR%E17,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E27 * '
      CALL PPRINT(VAR%E27,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E37 * '
      CALL PPRINT(VAR%E37,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E47 * '
      CALL PPRINT(VAR%E47,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E57 * '
      CALL PPRINT(VAR%E57,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E67 * '
      CALL PPRINT(VAR%E67,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E77 * '
      CALL PPRINT(VAR%E77,unit=unt,fmt=output_format)


   END SUBROUTINE ONUMM7N2_PPRINT_M

   ELEMENTAL FUNCTION ONUMM7N2_FEVAL(X,DER0,DER1,DER2)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: FACTOR, COEF
      TYPE(ONUMM7N2), INTENT(IN)  :: X
      REAL(DP), INTENT(IN)  :: DER0,DER1,DER2
      TYPE(ONUMM7N2) :: RES
      TYPE(ONUMM7N2) :: DX, DX_P

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
      ! Order 2
      RES%E11 = RES%E11+COEF*DX_P%E11
      RES%E12 = RES%E12+COEF*DX_P%E12
      RES%E22 = RES%E22+COEF*DX_P%E22
      RES%E13 = RES%E13+COEF*DX_P%E13
      RES%E23 = RES%E23+COEF*DX_P%E23
      RES%E33 = RES%E33+COEF*DX_P%E33
      RES%E14 = RES%E14+COEF*DX_P%E14
      RES%E24 = RES%E24+COEF*DX_P%E24
      RES%E34 = RES%E34+COEF*DX_P%E34
      RES%E44 = RES%E44+COEF*DX_P%E44
      RES%E15 = RES%E15+COEF*DX_P%E15
      RES%E25 = RES%E25+COEF*DX_P%E25
      RES%E35 = RES%E35+COEF*DX_P%E35
      RES%E45 = RES%E45+COEF*DX_P%E45
      RES%E55 = RES%E55+COEF*DX_P%E55
      RES%E16 = RES%E16+COEF*DX_P%E16
      RES%E26 = RES%E26+COEF*DX_P%E26
      RES%E36 = RES%E36+COEF*DX_P%E36
      RES%E46 = RES%E46+COEF*DX_P%E46
      RES%E56 = RES%E56+COEF*DX_P%E56
      RES%E66 = RES%E66+COEF*DX_P%E66
      RES%E17 = RES%E17+COEF*DX_P%E17
      RES%E27 = RES%E27+COEF*DX_P%E27
      RES%E37 = RES%E37+COEF*DX_P%E37
      RES%E47 = RES%E47+COEF*DX_P%E47
      RES%E57 = RES%E57+COEF*DX_P%E57
      RES%E67 = RES%E67+COEF*DX_P%E67
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
      ! Order 2
      DX_P%E11 = DX_P%E1*DX%E1
      DX_P%E12 = DX_P%E1*DX%E2+DX_P%E2*DX%E1
      DX_P%E22 = DX_P%E2*DX%E2
      DX_P%E13 = DX_P%E1*DX%E3+DX_P%E3*DX%E1
      DX_P%E23 = DX_P%E2*DX%E3+DX_P%E3*DX%E2
      DX_P%E33 = DX_P%E3*DX%E3
      DX_P%E14 = DX_P%E1*DX%E4+DX_P%E4*DX%E1
      DX_P%E24 = DX_P%E2*DX%E4+DX_P%E4*DX%E2
      DX_P%E34 = DX_P%E3*DX%E4+DX_P%E4*DX%E3
      DX_P%E44 = DX_P%E4*DX%E4
      DX_P%E15 = DX_P%E1*DX%E5+DX_P%E5*DX%E1
      DX_P%E25 = DX_P%E2*DX%E5+DX_P%E5*DX%E2
      DX_P%E35 = DX_P%E3*DX%E5+DX_P%E5*DX%E3
      DX_P%E45 = DX_P%E4*DX%E5+DX_P%E5*DX%E4
      DX_P%E55 = DX_P%E5*DX%E5
      DX_P%E16 = DX_P%E1*DX%E6+DX_P%E6*DX%E1
      DX_P%E26 = DX_P%E2*DX%E6+DX_P%E6*DX%E2
      DX_P%E36 = DX_P%E3*DX%E6+DX_P%E6*DX%E3
      DX_P%E46 = DX_P%E4*DX%E6+DX_P%E6*DX%E4
      DX_P%E56 = DX_P%E5*DX%E6+DX_P%E6*DX%E5
      DX_P%E66 = DX_P%E6*DX%E6
      DX_P%E17 = DX_P%E1*DX%E7+DX_P%E7*DX%E1
      DX_P%E27 = DX_P%E2*DX%E7+DX_P%E7*DX%E2
      DX_P%E37 = DX_P%E3*DX%E7+DX_P%E7*DX%E3
      DX_P%E47 = DX_P%E4*DX%E7+DX_P%E7*DX%E4
      DX_P%E57 = DX_P%E5*DX%E7+DX_P%E7*DX%E5
      DX_P%E67 = DX_P%E6*DX%E7+DX_P%E7*DX%E6
      DX_P%E77 = DX_P%E7*DX%E7
      
      ! Sets order 2
      FACTOR = FACTOR * 2
      COEF = DER2 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 2
      RES%E11 = RES%E11+COEF*DX_P%E11
      RES%E12 = RES%E12+COEF*DX_P%E12
      RES%E22 = RES%E22+COEF*DX_P%E22
      RES%E13 = RES%E13+COEF*DX_P%E13
      RES%E23 = RES%E23+COEF*DX_P%E23
      RES%E33 = RES%E33+COEF*DX_P%E33
      RES%E14 = RES%E14+COEF*DX_P%E14
      RES%E24 = RES%E24+COEF*DX_P%E24
      RES%E34 = RES%E34+COEF*DX_P%E34
      RES%E44 = RES%E44+COEF*DX_P%E44
      RES%E15 = RES%E15+COEF*DX_P%E15
      RES%E25 = RES%E25+COEF*DX_P%E25
      RES%E35 = RES%E35+COEF*DX_P%E35
      RES%E45 = RES%E45+COEF*DX_P%E45
      RES%E55 = RES%E55+COEF*DX_P%E55
      RES%E16 = RES%E16+COEF*DX_P%E16
      RES%E26 = RES%E26+COEF*DX_P%E26
      RES%E36 = RES%E36+COEF*DX_P%E36
      RES%E46 = RES%E46+COEF*DX_P%E46
      RES%E56 = RES%E56+COEF*DX_P%E56
      RES%E66 = RES%E66+COEF*DX_P%E66
      RES%E17 = RES%E17+COEF*DX_P%E17
      RES%E27 = RES%E27+COEF*DX_P%E27
      RES%E37 = RES%E37+COEF*DX_P%E37
      RES%E47 = RES%E47+COEF*DX_P%E47
      RES%E57 = RES%E57+COEF*DX_P%E57
      RES%E67 = RES%E67+COEF*DX_P%E67
      RES%E77 = RES%E77+COEF*DX_P%E77
      
   END FUNCTION ONUMM7N2_FEVAL


  ! SUBROUTINE ONUMM7N2_PPRINT_M_R(X, FMT)
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

  ! END SUBROUTINE ONUMM7N2_PPRINT_M_R

  ! SUBROUTINE ONUMM7N2_PPRINT_V_R(X, FMT)
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

  ! END SUBROUTINE ONUMM7N2_PPRINT_V_R

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
  PURE FUNCTION ONUMM7N2_det2x2(A) RESULT(det)

    IMPLICIT NONE

    TYPE(ONUMM7N2), INTENT(IN) :: A(2,2)   !! Matrix
    TYPE(ONUMM7N2)             :: det

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
  PURE FUNCTION ONUMM7N2_det3x3(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(ONUMM7N2), INTENT(IN) :: A(3,3)   !! Matrix
    TYPE(ONUMM7N2)             :: det

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
  PURE FUNCTION ONUMM7N2_det4x4(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(ONUMM7N2), INTENT(IN) :: A(4,4)   !! Matrix
    TYPE(ONUMM7N2)             :: det

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
  PURE FUNCTION ONUMM7N2_cross3(a,b) RESULT(v)
      
    IMPLICIT NONE 

    TYPE(ONUMM7N2), DIMENSION (3),INTENT(IN) :: a,b
    TYPE(ONUMM7N2), DIMENSION (3) :: v
    
    v(1) = a(2) * b(3) - a(3) * b(2)
    v(2) = a(3) * b(1) - a(1) * b(3)
    v(3) = a(1) * b(2) - a(2) * b(1)

  END FUNCTION ONUMM7N2_cross3
  !===================================================================================================! 

  !***************************************************************************************************! 
  !> @brief Norm of a 3 element vector. # There is an intrinsic function named norm2.
  !!
  !! @param[in] a: Vector of 3 reals (rank 1).
  !! @param[in] b: Vector of 3 reals (rank 1).
  !!
  !***************************************************************************************************!
  FUNCTION ONUMM7N2_norm2_3(v) RESULT(n)
     
    IMPLICIT NONE 

    TYPE(ONUMM7N2), INTENT(IN) :: v(3)
    TYPE(ONUMM7N2) :: n
     
    n = SQRT( v(1)*v(1) + v(2)*v(2) + v(3)*v(3) )

  END FUNCTION ONUMM7N2_norm2_3
  !===================================================================================================! 

  ELEMENTAL FUNCTION ONUMM7N2_DIVISION_OO(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(ONUMM7N2), INTENT(IN) :: X
      TYPE(ONUMM7N2), INTENT(IN) :: Y
      TYPE(ONUMM7N2) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION ONUMM7N2_DIVISION_OO

  ELEMENTAL FUNCTION ONUMM7N2_DIVISION_OR(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(ONUMM7N2), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: Y
      TYPE(ONUMM7N2) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION ONUMM7N2_DIVISION_OR

  ELEMENTAL FUNCTION ONUMM7N2_DIVISION_RO(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      REAL(DP), INTENT(IN) :: X
      TYPE(ONUMM7N2), INTENT(IN) :: Y
      TYPE(ONUMM7N2) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION ONUMM7N2_DIVISION_RO

  ELEMENTAL FUNCTION ONUMM7N2_REAL(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: X
      REAL(DP) :: RES

      RES = X%R

  END FUNCTION ONUMM7N2_REAL

  FUNCTION ONUMM7N2_SQRT(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2), INTENT(IN) :: X
      TYPE(ONUMM7N2) :: RES

      RES = X**0.5_DP

  END FUNCTION ONUMM7N2_SQRT

   ELEMENTAL FUNCTION ONUMM7N2_TAN(X) RESULT(RES)

      TYPE(ONUMM7N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(ONUMM7N2) :: RES
      
      DER0 = TAN(X%R)
      DER1 = TAN(X%R)**2 + 1
      DER2 = 2*(TAN(X%R)**2 + 1)*TAN(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION ONUMM7N2_TAN

   ELEMENTAL FUNCTION ONUMM7N2_COS(X) RESULT(RES)

      TYPE(ONUMM7N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(ONUMM7N2) :: RES
      
      DER0 = COS(X%R)
      DER1 = -SIN(X%R)
      DER2 = -COS(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION ONUMM7N2_COS

   ELEMENTAL FUNCTION ONUMM7N2_SIN(X) RESULT(RES)

      TYPE(ONUMM7N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(ONUMM7N2) :: RES
      
      DER0 = SIN(X%R)
      DER1 = COS(X%R)
      DER2 = -SIN(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION ONUMM7N2_SIN

   ELEMENTAL FUNCTION ONUMM7N2_ATAN(X) RESULT(RES)

      TYPE(ONUMM7N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(ONUMM7N2) :: RES
      
      DER0 = ATAN(X%R)
      DER1 = 1D0/(X%R**2 + 1)
      DER2 = -2*X%R/(X%R**2 + 1)**2

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION ONUMM7N2_ATAN

   ELEMENTAL FUNCTION ONUMM7N2_ACOS(X) RESULT(RES)

      TYPE(ONUMM7N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(ONUMM7N2) :: RES
      
      DER0 = ACOS(X%R)
      DER1 = -1/SQRT(1 - X%R**2)
      DER2 = -X%R/(1 - X%R**2)**(3.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION ONUMM7N2_ACOS

   ELEMENTAL FUNCTION ONUMM7N2_ASIN(X) RESULT(RES)

      TYPE(ONUMM7N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(ONUMM7N2) :: RES
      
      DER0 = ASIN(X%R)
      DER1 = 1/SQRT(1 - X%R**2)
      DER2 = X%R/(1 - X%R**2)**(3.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION ONUMM7N2_ASIN

   ELEMENTAL FUNCTION ONUMM7N2_TANH(X) RESULT(RES)

      TYPE(ONUMM7N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(ONUMM7N2) :: RES
      
      DER0 = TANH(X%R)
      DER1 = 1 - TANH(X%R)**2
      DER2 = 2*(TANH(X%R)**2 - 1)*TANH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION ONUMM7N2_TANH

   ELEMENTAL FUNCTION ONUMM7N2_COSH(X) RESULT(RES)

      TYPE(ONUMM7N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(ONUMM7N2) :: RES
      
      DER0 = COSH(X%R)
      DER1 = SINH(X%R)
      DER2 = COSH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION ONUMM7N2_COSH

   ELEMENTAL FUNCTION ONUMM7N2_SINH(X) RESULT(RES)

      TYPE(ONUMM7N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(ONUMM7N2) :: RES
      
      DER0 = SINH(X%R)
      DER1 = COSH(X%R)
      DER2 = SINH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION ONUMM7N2_SINH

   ELEMENTAL FUNCTION ONUMM7N2_EXP(X) RESULT(RES)

      TYPE(ONUMM7N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(ONUMM7N2) :: RES
      
      DER0 = EXP(X%R)
      DER1 = EXP(X%R)
      DER2 = EXP(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION ONUMM7N2_EXP

   ELEMENTAL FUNCTION ONUMM7N2_LOG(X) RESULT(RES)

      TYPE(ONUMM7N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(ONUMM7N2) :: RES
      
      DER0 = LOG(X%R)
      DER1 = 1D0/X%R
      DER2 = -1/X%R**2

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION ONUMM7N2_LOG

   ELEMENTAL FUNCTION ONUMM7N2_POW_OR(X,E) RESULT(RES)

      TYPE(ONUMM7N2), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2
      TYPE(ONUMM7N2) :: RES
      
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

   END FUNCTION ONUMM7N2_POW_OR

   ELEMENTAL FUNCTION ONUMM7N2_POW_RO(E,X) RESULT(RES)

      TYPE(ONUMM7N2), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2
      TYPE(ONUMM7N2) :: RES
      
      
      DER0 = E**X%R
      DER1 = E**X%R*LOG(E)
      DER2 = E**X%R*LOG(E)**2

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION ONUMM7N2_POW_RO

   ELEMENTAL FUNCTION ONUMM7N2_F2EVAL(X,Y,DER0_0,DER1_0,DER1_1, &
                                  DER2_0,DER2_1,DER2_2)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: COEF, DELTA
      TYPE(ONUMM7N2), INTENT(IN)  :: X,Y
      REAL(DP), INTENT(IN)  :: DER0_0,DER1_0,DER1_1, &
                               DER2_0,DER2_1,DER2_2
      TYPE(ONUMM7N2) :: RES
      TYPE(ONUMM7N2) :: DX, DY

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

      

   END FUNCTION ONUMM7N2_F2EVAL


   ELEMENTAL FUNCTION ONUMM7N2_POW_OO(X,Y) RESULT(RES)

      TYPE(ONUMM7N2), INTENT(IN) :: X, Y
      REAL(DP) :: DER0_0,DER1_0,DER1_1,DER2_0,DER2_1,DER2_2
      TYPE(ONUMM7N2) :: RES
      
      DER0_0 = X%R**Y%R
      DER1_0 = X%R**Y%R*Y%R/X%R
      DER1_1 = X%R**Y%R*LOG(X%R)
      DER2_0 = X%R**Y%R*Y%R*(Y%R - 1)/X%R**2
      DER2_1 = X%R**Y%R*(Y%R*LOG(X%R) + 1)/X%R
      DER2_2 = X%R**Y%R*LOG(X%R)**2

      RES = F2EVAL(X,Y,DER0_0,DER1_0,DER1_1,DER2_0,DER2_1,DER2_2)

   END FUNCTION ONUMM7N2_POW_OO


   FUNCTION ONUMM7N2_INV2X2(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2) , INTENT(IN) :: A(2,2) 
      TYPE(ONUMM7N2) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(ONUMM7N2) :: RES(SIZE(A,1),SIZE(A,2)) 

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
      RES%E12=-MATMUL(RES%R,(MATMUL(A%E12,RES%R)+MATMUL(A%E1,RES%E2)+&
             MATMUL(A%E2,RES%E1)))
      RES%E22=-MATMUL(RES%R,(MATMUL(A%E22,RES%R)+MATMUL(A%E2,RES%E2)))
      RES%E13=-MATMUL(RES%R,(MATMUL(A%E13,RES%R)+MATMUL(A%E1,RES%E3)+&
             MATMUL(A%E3,RES%E1)))
      RES%E23=-MATMUL(RES%R,(MATMUL(A%E23,RES%R)+MATMUL(A%E2,RES%E3)+&
             MATMUL(A%E3,RES%E2)))
      RES%E33=-MATMUL(RES%R,(MATMUL(A%E33,RES%R)+MATMUL(A%E3,RES%E3)))
      RES%E14=-MATMUL(RES%R,(MATMUL(A%E14,RES%R)+MATMUL(A%E1,RES%E4)+&
             MATMUL(A%E4,RES%E1)))
      RES%E24=-MATMUL(RES%R,(MATMUL(A%E24,RES%R)+MATMUL(A%E2,RES%E4)+&
             MATMUL(A%E4,RES%E2)))
      RES%E34=-MATMUL(RES%R,(MATMUL(A%E34,RES%R)+MATMUL(A%E3,RES%E4)+&
             MATMUL(A%E4,RES%E3)))
      RES%E44=-MATMUL(RES%R,(MATMUL(A%E44,RES%R)+MATMUL(A%E4,RES%E4)))
      RES%E15=-MATMUL(RES%R,(MATMUL(A%E15,RES%R)+MATMUL(A%E1,RES%E5)+&
             MATMUL(A%E5,RES%E1)))
      RES%E25=-MATMUL(RES%R,(MATMUL(A%E25,RES%R)+MATMUL(A%E2,RES%E5)+&
             MATMUL(A%E5,RES%E2)))
      RES%E35=-MATMUL(RES%R,(MATMUL(A%E35,RES%R)+MATMUL(A%E3,RES%E5)+&
             MATMUL(A%E5,RES%E3)))
      RES%E45=-MATMUL(RES%R,(MATMUL(A%E45,RES%R)+MATMUL(A%E4,RES%E5)+&
             MATMUL(A%E5,RES%E4)))
      RES%E55=-MATMUL(RES%R,(MATMUL(A%E55,RES%R)+MATMUL(A%E5,RES%E5)))
      RES%E16=-MATMUL(RES%R,(MATMUL(A%E16,RES%R)+MATMUL(A%E1,RES%E6)+&
             MATMUL(A%E6,RES%E1)))
      RES%E26=-MATMUL(RES%R,(MATMUL(A%E26,RES%R)+MATMUL(A%E2,RES%E6)+&
             MATMUL(A%E6,RES%E2)))
      RES%E36=-MATMUL(RES%R,(MATMUL(A%E36,RES%R)+MATMUL(A%E3,RES%E6)+&
             MATMUL(A%E6,RES%E3)))
      RES%E46=-MATMUL(RES%R,(MATMUL(A%E46,RES%R)+MATMUL(A%E4,RES%E6)+&
             MATMUL(A%E6,RES%E4)))
      RES%E56=-MATMUL(RES%R,(MATMUL(A%E56,RES%R)+MATMUL(A%E5,RES%E6)+&
             MATMUL(A%E6,RES%E5)))
      RES%E66=-MATMUL(RES%R,(MATMUL(A%E66,RES%R)+MATMUL(A%E6,RES%E6)))
      RES%E17=-MATMUL(RES%R,(MATMUL(A%E17,RES%R)+MATMUL(A%E1,RES%E7)+&
             MATMUL(A%E7,RES%E1)))
      RES%E27=-MATMUL(RES%R,(MATMUL(A%E27,RES%R)+MATMUL(A%E2,RES%E7)+&
             MATMUL(A%E7,RES%E2)))
      RES%E37=-MATMUL(RES%R,(MATMUL(A%E37,RES%R)+MATMUL(A%E3,RES%E7)+&
             MATMUL(A%E7,RES%E3)))
      RES%E47=-MATMUL(RES%R,(MATMUL(A%E47,RES%R)+MATMUL(A%E4,RES%E7)+&
             MATMUL(A%E7,RES%E4)))
      RES%E57=-MATMUL(RES%R,(MATMUL(A%E57,RES%R)+MATMUL(A%E5,RES%E7)+&
             MATMUL(A%E7,RES%E5)))
      RES%E67=-MATMUL(RES%R,(MATMUL(A%E67,RES%R)+MATMUL(A%E6,RES%E7)+&
             MATMUL(A%E7,RES%E6)))
      RES%E77=-MATMUL(RES%R,(MATMUL(A%E77,RES%R)+MATMUL(A%E7,RES%E7)))

   END FUNCTION ONUMM7N2_INV2X2

   FUNCTION ONUMM7N2_INV3X3(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2) , INTENT(IN) :: A(3,3) 
      TYPE(ONUMM7N2) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(ONUMM7N2) :: RES(SIZE(A,1),SIZE(A,2)) 

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
      RES%E12=-MATMUL(RES%R,(MATMUL(A%E12,RES%R)+MATMUL(A%E1,RES%E2)+&
             MATMUL(A%E2,RES%E1)))
      RES%E22=-MATMUL(RES%R,(MATMUL(A%E22,RES%R)+MATMUL(A%E2,RES%E2)))
      RES%E13=-MATMUL(RES%R,(MATMUL(A%E13,RES%R)+MATMUL(A%E1,RES%E3)+&
             MATMUL(A%E3,RES%E1)))
      RES%E23=-MATMUL(RES%R,(MATMUL(A%E23,RES%R)+MATMUL(A%E2,RES%E3)+&
             MATMUL(A%E3,RES%E2)))
      RES%E33=-MATMUL(RES%R,(MATMUL(A%E33,RES%R)+MATMUL(A%E3,RES%E3)))
      RES%E14=-MATMUL(RES%R,(MATMUL(A%E14,RES%R)+MATMUL(A%E1,RES%E4)+&
             MATMUL(A%E4,RES%E1)))
      RES%E24=-MATMUL(RES%R,(MATMUL(A%E24,RES%R)+MATMUL(A%E2,RES%E4)+&
             MATMUL(A%E4,RES%E2)))
      RES%E34=-MATMUL(RES%R,(MATMUL(A%E34,RES%R)+MATMUL(A%E3,RES%E4)+&
             MATMUL(A%E4,RES%E3)))
      RES%E44=-MATMUL(RES%R,(MATMUL(A%E44,RES%R)+MATMUL(A%E4,RES%E4)))
      RES%E15=-MATMUL(RES%R,(MATMUL(A%E15,RES%R)+MATMUL(A%E1,RES%E5)+&
             MATMUL(A%E5,RES%E1)))
      RES%E25=-MATMUL(RES%R,(MATMUL(A%E25,RES%R)+MATMUL(A%E2,RES%E5)+&
             MATMUL(A%E5,RES%E2)))
      RES%E35=-MATMUL(RES%R,(MATMUL(A%E35,RES%R)+MATMUL(A%E3,RES%E5)+&
             MATMUL(A%E5,RES%E3)))
      RES%E45=-MATMUL(RES%R,(MATMUL(A%E45,RES%R)+MATMUL(A%E4,RES%E5)+&
             MATMUL(A%E5,RES%E4)))
      RES%E55=-MATMUL(RES%R,(MATMUL(A%E55,RES%R)+MATMUL(A%E5,RES%E5)))
      RES%E16=-MATMUL(RES%R,(MATMUL(A%E16,RES%R)+MATMUL(A%E1,RES%E6)+&
             MATMUL(A%E6,RES%E1)))
      RES%E26=-MATMUL(RES%R,(MATMUL(A%E26,RES%R)+MATMUL(A%E2,RES%E6)+&
             MATMUL(A%E6,RES%E2)))
      RES%E36=-MATMUL(RES%R,(MATMUL(A%E36,RES%R)+MATMUL(A%E3,RES%E6)+&
             MATMUL(A%E6,RES%E3)))
      RES%E46=-MATMUL(RES%R,(MATMUL(A%E46,RES%R)+MATMUL(A%E4,RES%E6)+&
             MATMUL(A%E6,RES%E4)))
      RES%E56=-MATMUL(RES%R,(MATMUL(A%E56,RES%R)+MATMUL(A%E5,RES%E6)+&
             MATMUL(A%E6,RES%E5)))
      RES%E66=-MATMUL(RES%R,(MATMUL(A%E66,RES%R)+MATMUL(A%E6,RES%E6)))
      RES%E17=-MATMUL(RES%R,(MATMUL(A%E17,RES%R)+MATMUL(A%E1,RES%E7)+&
             MATMUL(A%E7,RES%E1)))
      RES%E27=-MATMUL(RES%R,(MATMUL(A%E27,RES%R)+MATMUL(A%E2,RES%E7)+&
             MATMUL(A%E7,RES%E2)))
      RES%E37=-MATMUL(RES%R,(MATMUL(A%E37,RES%R)+MATMUL(A%E3,RES%E7)+&
             MATMUL(A%E7,RES%E3)))
      RES%E47=-MATMUL(RES%R,(MATMUL(A%E47,RES%R)+MATMUL(A%E4,RES%E7)+&
             MATMUL(A%E7,RES%E4)))
      RES%E57=-MATMUL(RES%R,(MATMUL(A%E57,RES%R)+MATMUL(A%E5,RES%E7)+&
             MATMUL(A%E7,RES%E5)))
      RES%E67=-MATMUL(RES%R,(MATMUL(A%E67,RES%R)+MATMUL(A%E6,RES%E7)+&
             MATMUL(A%E7,RES%E6)))
      RES%E77=-MATMUL(RES%R,(MATMUL(A%E77,RES%R)+MATMUL(A%E7,RES%E7)))

   END FUNCTION ONUMM7N2_INV3X3

   FUNCTION ONUMM7N2_INV4X4(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N2) , INTENT(IN) :: A(4,4) 
      TYPE(ONUMM7N2) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(ONUMM7N2) :: RES(SIZE(A,1),SIZE(A,2)) 

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
      RES%E12=-MATMUL(RES%R,(MATMUL(A%E12,RES%R)+MATMUL(A%E1,RES%E2)+&
             MATMUL(A%E2,RES%E1)))
      RES%E22=-MATMUL(RES%R,(MATMUL(A%E22,RES%R)+MATMUL(A%E2,RES%E2)))
      RES%E13=-MATMUL(RES%R,(MATMUL(A%E13,RES%R)+MATMUL(A%E1,RES%E3)+&
             MATMUL(A%E3,RES%E1)))
      RES%E23=-MATMUL(RES%R,(MATMUL(A%E23,RES%R)+MATMUL(A%E2,RES%E3)+&
             MATMUL(A%E3,RES%E2)))
      RES%E33=-MATMUL(RES%R,(MATMUL(A%E33,RES%R)+MATMUL(A%E3,RES%E3)))
      RES%E14=-MATMUL(RES%R,(MATMUL(A%E14,RES%R)+MATMUL(A%E1,RES%E4)+&
             MATMUL(A%E4,RES%E1)))
      RES%E24=-MATMUL(RES%R,(MATMUL(A%E24,RES%R)+MATMUL(A%E2,RES%E4)+&
             MATMUL(A%E4,RES%E2)))
      RES%E34=-MATMUL(RES%R,(MATMUL(A%E34,RES%R)+MATMUL(A%E3,RES%E4)+&
             MATMUL(A%E4,RES%E3)))
      RES%E44=-MATMUL(RES%R,(MATMUL(A%E44,RES%R)+MATMUL(A%E4,RES%E4)))
      RES%E15=-MATMUL(RES%R,(MATMUL(A%E15,RES%R)+MATMUL(A%E1,RES%E5)+&
             MATMUL(A%E5,RES%E1)))
      RES%E25=-MATMUL(RES%R,(MATMUL(A%E25,RES%R)+MATMUL(A%E2,RES%E5)+&
             MATMUL(A%E5,RES%E2)))
      RES%E35=-MATMUL(RES%R,(MATMUL(A%E35,RES%R)+MATMUL(A%E3,RES%E5)+&
             MATMUL(A%E5,RES%E3)))
      RES%E45=-MATMUL(RES%R,(MATMUL(A%E45,RES%R)+MATMUL(A%E4,RES%E5)+&
             MATMUL(A%E5,RES%E4)))
      RES%E55=-MATMUL(RES%R,(MATMUL(A%E55,RES%R)+MATMUL(A%E5,RES%E5)))
      RES%E16=-MATMUL(RES%R,(MATMUL(A%E16,RES%R)+MATMUL(A%E1,RES%E6)+&
             MATMUL(A%E6,RES%E1)))
      RES%E26=-MATMUL(RES%R,(MATMUL(A%E26,RES%R)+MATMUL(A%E2,RES%E6)+&
             MATMUL(A%E6,RES%E2)))
      RES%E36=-MATMUL(RES%R,(MATMUL(A%E36,RES%R)+MATMUL(A%E3,RES%E6)+&
             MATMUL(A%E6,RES%E3)))
      RES%E46=-MATMUL(RES%R,(MATMUL(A%E46,RES%R)+MATMUL(A%E4,RES%E6)+&
             MATMUL(A%E6,RES%E4)))
      RES%E56=-MATMUL(RES%R,(MATMUL(A%E56,RES%R)+MATMUL(A%E5,RES%E6)+&
             MATMUL(A%E6,RES%E5)))
      RES%E66=-MATMUL(RES%R,(MATMUL(A%E66,RES%R)+MATMUL(A%E6,RES%E6)))
      RES%E17=-MATMUL(RES%R,(MATMUL(A%E17,RES%R)+MATMUL(A%E1,RES%E7)+&
             MATMUL(A%E7,RES%E1)))
      RES%E27=-MATMUL(RES%R,(MATMUL(A%E27,RES%R)+MATMUL(A%E2,RES%E7)+&
             MATMUL(A%E7,RES%E2)))
      RES%E37=-MATMUL(RES%R,(MATMUL(A%E37,RES%R)+MATMUL(A%E3,RES%E7)+&
             MATMUL(A%E7,RES%E3)))
      RES%E47=-MATMUL(RES%R,(MATMUL(A%E47,RES%R)+MATMUL(A%E4,RES%E7)+&
             MATMUL(A%E7,RES%E4)))
      RES%E57=-MATMUL(RES%R,(MATMUL(A%E57,RES%R)+MATMUL(A%E5,RES%E7)+&
             MATMUL(A%E7,RES%E5)))
      RES%E67=-MATMUL(RES%R,(MATMUL(A%E67,RES%R)+MATMUL(A%E6,RES%E7)+&
             MATMUL(A%E7,RES%E6)))
      RES%E77=-MATMUL(RES%R,(MATMUL(A%E77,RES%R)+MATMUL(A%E7,RES%E7)))

   END FUNCTION ONUMM7N2_INV4X4

END MODULE otim7n2
