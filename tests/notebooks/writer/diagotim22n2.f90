MODULE diagotim22n2

   USE master_parameters
   USE real_utils

   IMPLICIT NONE

   INTEGER, PARAMETER :: num_im_dir = 276
   INTEGER, PARAMETER :: torder     = 2
   INTEGER, PARAMETER :: n_imdir_order(3) = [1,22,22]

   TYPE DONUMM22N2
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
     REAL(DP) :: E8
     REAL(DP) :: E9
     REAL(DP) :: EA
     REAL(DP) :: EB
     REAL(DP) :: EC
     REAL(DP) :: ED
     REAL(DP) :: EE
     REAL(DP) :: EF
     REAL(DP) :: EG
     REAL(DP) :: EH
     REAL(DP) :: EI
     REAL(DP) :: EJ
     REAL(DP) :: EK
     REAL(DP) :: EL
     REAL(DP) :: EM
     ! Order 2
     REAL(DP) :: E11
     REAL(DP) :: E22
     REAL(DP) :: E33
     REAL(DP) :: E44
     REAL(DP) :: E55
     REAL(DP) :: E66
     REAL(DP) :: E77
     REAL(DP) :: E88
     REAL(DP) :: E99
     REAL(DP) :: EAA
     REAL(DP) :: EBB
     REAL(DP) :: ECC
     REAL(DP) :: EDD
     REAL(DP) :: EEE
     REAL(DP) :: EFF
     REAL(DP) :: EGG
     REAL(DP) :: EHH
     REAL(DP) :: EII
     REAL(DP) :: EJJ
     REAL(DP) :: EKK
     REAL(DP) :: ELL
     REAL(DP) :: EMM
   END TYPE DONUMM22N2

   ! Constant imaginary directions.
   ! Order 1
   TYPE(DONUMM22N2), PARAMETER :: E1 = DONUMM22N2(0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: E2 = DONUMM22N2(0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: E3 = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: E4 = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: E5 = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: E6 = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: E7 = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: E8 = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: E9 = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EA = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EB = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EC = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: ED = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EE = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EF = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EG = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EH = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EI = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EJ = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EK = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EL = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EM = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   ! Order 2
   TYPE(DONUMM22N2), PARAMETER :: E11 = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: E22 = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: E33 = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: E44 = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: E55 = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: E66 = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: E77 = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: E88 = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: E99 = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EAA = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EBB = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: ECC = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EDD = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EEE = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EFF = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EGG = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EHH = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EII = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EJJ = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EKK = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: ELL = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp)
   TYPE(DONUMM22N2), PARAMETER :: EMM = DONUMM22N2(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp)


   INTERFACE OPERATOR(*)
      MODULE PROCEDURE DONUMM22N2_MUL_OO_SS,DONUMM22N2_MUL_RO_SS,DONUMM22N2_MUL_OR_SS,DONUMM22N2_MUL_OO_VS,&
                       DONUMM22N2_MUL_RO_VS,DONUMM22N2_MUL_OR_VS,DONUMM22N2_MUL_OO_MS,DONUMM22N2_MUL_RO_MS,&
                       DONUMM22N2_MUL_OR_MS,DONUMM22N2_MUL_OO_SV,DONUMM22N2_MUL_RO_SV,DONUMM22N2_MUL_OR_SV,&
                       DONUMM22N2_MUL_OO_SM,DONUMM22N2_MUL_RO_SM,DONUMM22N2_MUL_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(+)
      MODULE PROCEDURE DONUMM22N2_ADD_OO_SS,DONUMM22N2_ADD_RO_SS,DONUMM22N2_ADD_OR_SS,DONUMM22N2_ADD_OO_VS,&
                       DONUMM22N2_ADD_RO_VS,DONUMM22N2_ADD_OR_VS,DONUMM22N2_ADD_OO_MS,DONUMM22N2_ADD_RO_MS,&
                       DONUMM22N2_ADD_OR_MS,DONUMM22N2_ADD_OO_SV,DONUMM22N2_ADD_RO_SV,DONUMM22N2_ADD_OR_SV,&
                       DONUMM22N2_ADD_OO_SM,DONUMM22N2_ADD_RO_SM,DONUMM22N2_ADD_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(-)
      MODULE PROCEDURE DONUMM22N2_NEG,DONUMM22N2_SUB_OO_SS,DONUMM22N2_SUB_RO_SS,DONUMM22N2_SUB_OR_SS,&
                       DONUMM22N2_SUB_OO_VS,DONUMM22N2_SUB_RO_VS,DONUMM22N2_SUB_OR_VS,DONUMM22N2_SUB_OO_MS,&
                       DONUMM22N2_SUB_RO_MS,DONUMM22N2_SUB_OR_MS,DONUMM22N2_SUB_OO_SV,DONUMM22N2_SUB_RO_SV,&
                       DONUMM22N2_SUB_OR_SV,DONUMM22N2_SUB_OO_SM,DONUMM22N2_SUB_RO_SM,DONUMM22N2_SUB_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(/)
      MODULE PROCEDURE DONUMM22N2_DIVISION_OO,DONUMM22N2_DIVISION_OR,DONUMM22N2_DIVISION_RO
   END INTERFACE

   INTERFACE ASSIGNMENT(=)
      MODULE PROCEDURE DONUMM22N2_ASSIGN_R
   END INTERFACE

   INTERFACE OPERATOR(**)
      MODULE PROCEDURE DONUMM22N2_POW_OR,DONUMM22N2_POW_RO,DONUMM22N2_POW_OO
   END INTERFACE

   INTERFACE PPRINT
      MODULE PROCEDURE DONUMM22N2_PPRINT_S,DONUMM22N2_PPRINT_V,DONUMM22N2_PPRINT_M
   END INTERFACE

   INTERFACE TRANSPOSE
      MODULE PROCEDURE DONUMM22N2_TRANSPOSE
   END INTERFACE

   INTERFACE MATMUL
      MODULE PROCEDURE DONUMM22N2_MATMUL_DONUMM22N2,R_MATMUL_DONUMM22N2,DONUMM22N2_MATMUL_R
   END INTERFACE

   INTERFACE DOT_PRODUCT
      MODULE PROCEDURE DONUMM22N2_DOT_PRODUCT_DONUMM22N2,R_DOT_PRODUCT_DONUMM22N2,DONUMM22N2_DOT_PRODUCT_R
   END INTERFACE

   INTERFACE UNFOLD
      MODULE PROCEDURE DONUMM22N2_TO_CR_MAT_S,DONUMM22N2_TO_CR_MAT_V,DONUMM22N2_TO_CR_MAT_M
   END INTERFACE

   INTERFACE TO_CR
      MODULE PROCEDURE DONUMM22N2_TO_CR_MAT_S,DONUMM22N2_TO_CR_MAT_V,DONUMM22N2_TO_CR_MAT_M
   END INTERFACE

   INTERFACE SIN
      MODULE PROCEDURE DONUMM22N2_SIN
   END INTERFACE

   INTERFACE COS
      MODULE PROCEDURE DONUMM22N2_COS
   END INTERFACE

   INTERFACE TAN
      MODULE PROCEDURE DONUMM22N2_TAN
   END INTERFACE

   INTERFACE ASIN
      MODULE PROCEDURE DONUMM22N2_ASIN
   END INTERFACE

   INTERFACE ACOS
      MODULE PROCEDURE DONUMM22N2_ACOS
   END INTERFACE

   INTERFACE ATAN
      MODULE PROCEDURE DONUMM22N2_ATAN
   END INTERFACE

   INTERFACE SINH
      MODULE PROCEDURE DONUMM22N2_SINH
   END INTERFACE

   INTERFACE COSH
      MODULE PROCEDURE DONUMM22N2_COSH
   END INTERFACE

   INTERFACE TANH
      MODULE PROCEDURE DONUMM22N2_TANH
   END INTERFACE

   INTERFACE SQRT
      MODULE PROCEDURE DONUMM22N2_SQRT
   END INTERFACE

   INTERFACE LOG
      MODULE PROCEDURE DONUMM22N2_LOG
   END INTERFACE

   INTERFACE EXP
      MODULE PROCEDURE DONUMM22N2_EXP
   END INTERFACE

   INTERFACE GEM
      MODULE PROCEDURE DONUMM22N2_GEM_OOO,DONUMM22N2_GEM_ROO,DONUMM22N2_GEM_ORO
   END INTERFACE

   INTERFACE FEVAL
      MODULE PROCEDURE DONUMM22N2_FEVAL
   END INTERFACE

   INTERFACE F2EVAL
      MODULE PROCEDURE DONUMM22N2_F2EVAL
   END INTERFACE

   INTERFACE REAL
      MODULE PROCEDURE DONUMM22N2_REAL
   END INTERFACE

   INTERFACE DET2X2
      MODULE PROCEDURE DONUMM22N2_det2x2
   END INTERFACE

   INTERFACE DET3X3
      MODULE PROCEDURE DONUMM22N2_det3x3
   END INTERFACE

   INTERFACE DET4X4
      MODULE PROCEDURE DONUMM22N2_det4x4
   END INTERFACE

   INTERFACE INV2X2
      MODULE PROCEDURE DONUMM22N2_INV2X2
   END INTERFACE

   INTERFACE INV3X3
      MODULE PROCEDURE DONUMM22N2_INV3X3
   END INTERFACE

   INTERFACE INV4X4
      MODULE PROCEDURE DONUMM22N2_INV4X4
   END INTERFACE

   INTERFACE GETIM
      MODULE PROCEDURE DONUMM22N2_GETIM_S,DONUMM22N2_GETIM_V,DONUMM22N2_GETIM_M
   END INTERFACE

   INTERFACE SETIM
      MODULE PROCEDURE DONUMM22N2_SETIM_S,DONUMM22N2_SETIM_V,DONUMM22N2_SETIM_M
   END INTERFACE

   CONTAINS

   ELEMENTAL SUBROUTINE DONUMM22N2_ASSIGN_R(RES,LHS)
      
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS 
      TYPE(DONUMM22N2), INTENT(OUT) :: RES 

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
      RES%E8 = 0.0_dp
      RES%E9 = 0.0_dp
      RES%EA = 0.0_dp
      RES%EB = 0.0_dp
      RES%EC = 0.0_dp
      RES%ED = 0.0_dp
      RES%EE = 0.0_dp
      RES%EF = 0.0_dp
      RES%EG = 0.0_dp
      RES%EH = 0.0_dp
      RES%EI = 0.0_dp
      RES%EJ = 0.0_dp
      RES%EK = 0.0_dp
      RES%EL = 0.0_dp
      RES%EM = 0.0_dp

      ! Order 2
      RES%E11 = 0.0_dp
      RES%E22 = 0.0_dp
      RES%E33 = 0.0_dp
      RES%E44 = 0.0_dp
      RES%E55 = 0.0_dp
      RES%E66 = 0.0_dp
      RES%E77 = 0.0_dp
      RES%E88 = 0.0_dp
      RES%E99 = 0.0_dp
      RES%EAA = 0.0_dp
      RES%EBB = 0.0_dp
      RES%ECC = 0.0_dp
      RES%EDD = 0.0_dp
      RES%EEE = 0.0_dp
      RES%EFF = 0.0_dp
      RES%EGG = 0.0_dp
      RES%EHH = 0.0_dp
      RES%EII = 0.0_dp
      RES%EJJ = 0.0_dp
      RES%EKK = 0.0_dp
      RES%ELL = 0.0_dp
      RES%EMM = 0.0_dp

   END SUBROUTINE DONUMM22N2_ASSIGN_R

   ELEMENTAL FUNCTION DONUMM22N2_NEG(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS 
      TYPE(DONUMM22N2) :: RES 

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
      RES%E8 = -LHS%E8
      RES%E9 = -LHS%E9
      RES%EA = -LHS%EA
      RES%EB = -LHS%EB
      RES%EC = -LHS%EC
      RES%ED = -LHS%ED
      RES%EE = -LHS%EE
      RES%EF = -LHS%EF
      RES%EG = -LHS%EG
      RES%EH = -LHS%EH
      RES%EI = -LHS%EI
      RES%EJ = -LHS%EJ
      RES%EK = -LHS%EK
      RES%EL = -LHS%EL
      RES%EM = -LHS%EM
      ! Order 2
      RES%E11 = -LHS%E11
      RES%E22 = -LHS%E22
      RES%E33 = -LHS%E33
      RES%E44 = -LHS%E44
      RES%E55 = -LHS%E55
      RES%E66 = -LHS%E66
      RES%E77 = -LHS%E77
      RES%E88 = -LHS%E88
      RES%E99 = -LHS%E99
      RES%EAA = -LHS%EAA
      RES%EBB = -LHS%EBB
      RES%ECC = -LHS%ECC
      RES%EDD = -LHS%EDD
      RES%EEE = -LHS%EEE
      RES%EFF = -LHS%EFF
      RES%EGG = -LHS%EGG
      RES%EHH = -LHS%EHH
      RES%EII = -LHS%EII
      RES%EJJ = -LHS%EJJ
      RES%EKK = -LHS%EKK
      RES%ELL = -LHS%ELL
      RES%EMM = -LHS%EMM

   END FUNCTION DONUMM22N2_NEG

   ELEMENTAL FUNCTION DONUMM22N2_ADD_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES 

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
      RES%E8 = LHS%E8 + RHS%E8
      RES%E9 = LHS%E9 + RHS%E9
      RES%EA = LHS%EA + RHS%EA
      RES%EB = LHS%EB + RHS%EB
      RES%EC = LHS%EC + RHS%EC
      RES%ED = LHS%ED + RHS%ED
      RES%EE = LHS%EE + RHS%EE
      RES%EF = LHS%EF + RHS%EF
      RES%EG = LHS%EG + RHS%EG
      RES%EH = LHS%EH + RHS%EH
      RES%EI = LHS%EI + RHS%EI
      RES%EJ = LHS%EJ + RHS%EJ
      RES%EK = LHS%EK + RHS%EK
      RES%EL = LHS%EL + RHS%EL
      RES%EM = LHS%EM + RHS%EM

      ! Order 2
      RES%E11 = LHS%E11 + RHS%E11
      RES%E22 = LHS%E22 + RHS%E22
      RES%E33 = LHS%E33 + RHS%E33
      RES%E44 = LHS%E44 + RHS%E44
      RES%E55 = LHS%E55 + RHS%E55
      RES%E66 = LHS%E66 + RHS%E66
      RES%E77 = LHS%E77 + RHS%E77
      RES%E88 = LHS%E88 + RHS%E88
      RES%E99 = LHS%E99 + RHS%E99
      RES%EAA = LHS%EAA + RHS%EAA
      RES%EBB = LHS%EBB + RHS%EBB
      RES%ECC = LHS%ECC + RHS%ECC
      RES%EDD = LHS%EDD + RHS%EDD
      RES%EEE = LHS%EEE + RHS%EEE
      RES%EFF = LHS%EFF + RHS%EFF
      RES%EGG = LHS%EGG + RHS%EGG
      RES%EHH = LHS%EHH + RHS%EHH
      RES%EII = LHS%EII + RHS%EII
      RES%EJJ = LHS%EJJ + RHS%EJJ
      RES%EKK = LHS%EKK + RHS%EKK
      RES%ELL = LHS%ELL + RHS%ELL
      RES%EMM = LHS%EMM + RHS%EMM

   END FUNCTION DONUMM22N2_ADD_OO_SS

   ELEMENTAL FUNCTION DONUMM22N2_ADD_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES 

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
      RES%E8 =  + RHS%E8
      RES%E9 =  + RHS%E9
      RES%EA =  + RHS%EA
      RES%EB =  + RHS%EB
      RES%EC =  + RHS%EC
      RES%ED =  + RHS%ED
      RES%EE =  + RHS%EE
      RES%EF =  + RHS%EF
      RES%EG =  + RHS%EG
      RES%EH =  + RHS%EH
      RES%EI =  + RHS%EI
      RES%EJ =  + RHS%EJ
      RES%EK =  + RHS%EK
      RES%EL =  + RHS%EL
      RES%EM =  + RHS%EM

      ! Order 2
      RES%E11 =  + RHS%E11
      RES%E22 =  + RHS%E22
      RES%E33 =  + RHS%E33
      RES%E44 =  + RHS%E44
      RES%E55 =  + RHS%E55
      RES%E66 =  + RHS%E66
      RES%E77 =  + RHS%E77
      RES%E88 =  + RHS%E88
      RES%E99 =  + RHS%E99
      RES%EAA =  + RHS%EAA
      RES%EBB =  + RHS%EBB
      RES%ECC =  + RHS%ECC
      RES%EDD =  + RHS%EDD
      RES%EEE =  + RHS%EEE
      RES%EFF =  + RHS%EFF
      RES%EGG =  + RHS%EGG
      RES%EHH =  + RHS%EHH
      RES%EII =  + RHS%EII
      RES%EJJ =  + RHS%EJJ
      RES%EKK =  + RHS%EKK
      RES%ELL =  + RHS%ELL
      RES%EMM =  + RHS%EMM

   END FUNCTION DONUMM22N2_ADD_RO_SS

   ELEMENTAL FUNCTION DONUMM22N2_ADD_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES 

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
      RES%E8 = LHS%E8
      RES%E9 = LHS%E9
      RES%EA = LHS%EA
      RES%EB = LHS%EB
      RES%EC = LHS%EC
      RES%ED = LHS%ED
      RES%EE = LHS%EE
      RES%EF = LHS%EF
      RES%EG = LHS%EG
      RES%EH = LHS%EH
      RES%EI = LHS%EI
      RES%EJ = LHS%EJ
      RES%EK = LHS%EK
      RES%EL = LHS%EL
      RES%EM = LHS%EM

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77
      RES%E88 = LHS%E88
      RES%E99 = LHS%E99
      RES%EAA = LHS%EAA
      RES%EBB = LHS%EBB
      RES%ECC = LHS%ECC
      RES%EDD = LHS%EDD
      RES%EEE = LHS%EEE
      RES%EFF = LHS%EFF
      RES%EGG = LHS%EGG
      RES%EHH = LHS%EHH
      RES%EII = LHS%EII
      RES%EJJ = LHS%EJJ
      RES%EKK = LHS%EKK
      RES%ELL = LHS%ELL
      RES%EMM = LHS%EMM

   END FUNCTION DONUMM22N2_ADD_OR_SS

   ELEMENTAL FUNCTION DONUMM22N2_SUB_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES 

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
      RES%E8 = LHS%E8 - RHS%E8
      RES%E9 = LHS%E9 - RHS%E9
      RES%EA = LHS%EA - RHS%EA
      RES%EB = LHS%EB - RHS%EB
      RES%EC = LHS%EC - RHS%EC
      RES%ED = LHS%ED - RHS%ED
      RES%EE = LHS%EE - RHS%EE
      RES%EF = LHS%EF - RHS%EF
      RES%EG = LHS%EG - RHS%EG
      RES%EH = LHS%EH - RHS%EH
      RES%EI = LHS%EI - RHS%EI
      RES%EJ = LHS%EJ - RHS%EJ
      RES%EK = LHS%EK - RHS%EK
      RES%EL = LHS%EL - RHS%EL
      RES%EM = LHS%EM - RHS%EM

      ! Order 2
      RES%E11 = LHS%E11 - RHS%E11
      RES%E22 = LHS%E22 - RHS%E22
      RES%E33 = LHS%E33 - RHS%E33
      RES%E44 = LHS%E44 - RHS%E44
      RES%E55 = LHS%E55 - RHS%E55
      RES%E66 = LHS%E66 - RHS%E66
      RES%E77 = LHS%E77 - RHS%E77
      RES%E88 = LHS%E88 - RHS%E88
      RES%E99 = LHS%E99 - RHS%E99
      RES%EAA = LHS%EAA - RHS%EAA
      RES%EBB = LHS%EBB - RHS%EBB
      RES%ECC = LHS%ECC - RHS%ECC
      RES%EDD = LHS%EDD - RHS%EDD
      RES%EEE = LHS%EEE - RHS%EEE
      RES%EFF = LHS%EFF - RHS%EFF
      RES%EGG = LHS%EGG - RHS%EGG
      RES%EHH = LHS%EHH - RHS%EHH
      RES%EII = LHS%EII - RHS%EII
      RES%EJJ = LHS%EJJ - RHS%EJJ
      RES%EKK = LHS%EKK - RHS%EKK
      RES%ELL = LHS%ELL - RHS%ELL
      RES%EMM = LHS%EMM - RHS%EMM

   END FUNCTION DONUMM22N2_SUB_OO_SS

   ELEMENTAL FUNCTION DONUMM22N2_SUB_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES 

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
      RES%E8 =  - RHS%E8
      RES%E9 =  - RHS%E9
      RES%EA =  - RHS%EA
      RES%EB =  - RHS%EB
      RES%EC =  - RHS%EC
      RES%ED =  - RHS%ED
      RES%EE =  - RHS%EE
      RES%EF =  - RHS%EF
      RES%EG =  - RHS%EG
      RES%EH =  - RHS%EH
      RES%EI =  - RHS%EI
      RES%EJ =  - RHS%EJ
      RES%EK =  - RHS%EK
      RES%EL =  - RHS%EL
      RES%EM =  - RHS%EM

      ! Order 2
      RES%E11 =  - RHS%E11
      RES%E22 =  - RHS%E22
      RES%E33 =  - RHS%E33
      RES%E44 =  - RHS%E44
      RES%E55 =  - RHS%E55
      RES%E66 =  - RHS%E66
      RES%E77 =  - RHS%E77
      RES%E88 =  - RHS%E88
      RES%E99 =  - RHS%E99
      RES%EAA =  - RHS%EAA
      RES%EBB =  - RHS%EBB
      RES%ECC =  - RHS%ECC
      RES%EDD =  - RHS%EDD
      RES%EEE =  - RHS%EEE
      RES%EFF =  - RHS%EFF
      RES%EGG =  - RHS%EGG
      RES%EHH =  - RHS%EHH
      RES%EII =  - RHS%EII
      RES%EJJ =  - RHS%EJJ
      RES%EKK =  - RHS%EKK
      RES%ELL =  - RHS%ELL
      RES%EMM =  - RHS%EMM

   END FUNCTION DONUMM22N2_SUB_RO_SS

   ELEMENTAL FUNCTION DONUMM22N2_SUB_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES 

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
      RES%E8 = LHS%E8
      RES%E9 = LHS%E9
      RES%EA = LHS%EA
      RES%EB = LHS%EB
      RES%EC = LHS%EC
      RES%ED = LHS%ED
      RES%EE = LHS%EE
      RES%EF = LHS%EF
      RES%EG = LHS%EG
      RES%EH = LHS%EH
      RES%EI = LHS%EI
      RES%EJ = LHS%EJ
      RES%EK = LHS%EK
      RES%EL = LHS%EL
      RES%EM = LHS%EM

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77
      RES%E88 = LHS%E88
      RES%E99 = LHS%E99
      RES%EAA = LHS%EAA
      RES%EBB = LHS%EBB
      RES%ECC = LHS%ECC
      RES%EDD = LHS%EDD
      RES%EEE = LHS%EEE
      RES%EFF = LHS%EFF
      RES%EGG = LHS%EGG
      RES%EHH = LHS%EHH
      RES%EII = LHS%EII
      RES%EJJ = LHS%EJJ
      RES%EKK = LHS%EKK
      RES%ELL = LHS%ELL
      RES%EMM = LHS%EMM

   END FUNCTION DONUMM22N2_SUB_OR_SS

   ELEMENTAL FUNCTION DONUMM22N2_MUL_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES 

      !  Multiplication like function 'LHS*RHS'
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      RES%E22 = LHS%R*RHS%E22 + LHS%E22*RHS%R + LHS%E2*RHS%E2
      RES%E33 = LHS%R*RHS%E33 + LHS%E33*RHS%R + LHS%E3*RHS%E3
      RES%E44 = LHS%R*RHS%E44 + LHS%E44*RHS%R + LHS%E4*RHS%E4
      RES%E55 = LHS%R*RHS%E55 + LHS%E55*RHS%R + LHS%E5*RHS%E5
      RES%E66 = LHS%R*RHS%E66 + LHS%E66*RHS%R + LHS%E6*RHS%E6
      RES%E77 = LHS%R*RHS%E77 + LHS%E77*RHS%R + LHS%E7*RHS%E7
      RES%E88 = LHS%R*RHS%E88 + LHS%E88*RHS%R + LHS%E8*RHS%E8
      RES%E99 = LHS%R*RHS%E99 + LHS%E99*RHS%R + LHS%E9*RHS%E9
      RES%EAA = LHS%R*RHS%EAA + LHS%EAA*RHS%R + LHS%EA*RHS%EA
      RES%EBB = LHS%R*RHS%EBB + LHS%EBB*RHS%R + LHS%EB*RHS%EB
      RES%ECC = LHS%R*RHS%ECC + LHS%ECC*RHS%R + LHS%EC*RHS%EC
      RES%EDD = LHS%R*RHS%EDD + LHS%EDD*RHS%R + LHS%ED*RHS%ED
      RES%EEE = LHS%R*RHS%EEE + LHS%EEE*RHS%R + LHS%EE*RHS%EE
      RES%EFF = LHS%R*RHS%EFF + LHS%EFF*RHS%R + LHS%EF*RHS%EF
      RES%EGG = LHS%R*RHS%EGG + LHS%EGG*RHS%R + LHS%EG*RHS%EG
      RES%EHH = LHS%R*RHS%EHH + LHS%EHH*RHS%R + LHS%EH*RHS%EH
      RES%EII = LHS%R*RHS%EII + LHS%EII*RHS%R + LHS%EI*RHS%EI
      RES%EJJ = LHS%R*RHS%EJJ + LHS%EJJ*RHS%R + LHS%EJ*RHS%EJ
      RES%EKK = LHS%R*RHS%EKK + LHS%EKK*RHS%R + LHS%EK*RHS%EK
      RES%ELL = LHS%R*RHS%ELL + LHS%ELL*RHS%R + LHS%EL*RHS%EL
      RES%EMM = LHS%R*RHS%EMM + LHS%EMM*RHS%R + LHS%EM*RHS%EM
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      RES%E3 = LHS%R*RHS%E3 + LHS%E3*RHS%R
      RES%E4 = LHS%R*RHS%E4 + LHS%E4*RHS%R
      RES%E5 = LHS%R*RHS%E5 + LHS%E5*RHS%R
      RES%E6 = LHS%R*RHS%E6 + LHS%E6*RHS%R
      RES%E7 = LHS%R*RHS%E7 + LHS%E7*RHS%R
      RES%E8 = LHS%R*RHS%E8 + LHS%E8*RHS%R
      RES%E9 = LHS%R*RHS%E9 + LHS%E9*RHS%R
      RES%EA = LHS%R*RHS%EA + LHS%EA*RHS%R
      RES%EB = LHS%R*RHS%EB + LHS%EB*RHS%R
      RES%EC = LHS%R*RHS%EC + LHS%EC*RHS%R
      RES%ED = LHS%R*RHS%ED + LHS%ED*RHS%R
      RES%EE = LHS%R*RHS%EE + LHS%EE*RHS%R
      RES%EF = LHS%R*RHS%EF + LHS%EF*RHS%R
      RES%EG = LHS%R*RHS%EG + LHS%EG*RHS%R
      RES%EH = LHS%R*RHS%EH + LHS%EH*RHS%R
      RES%EI = LHS%R*RHS%EI + LHS%EI*RHS%R
      RES%EJ = LHS%R*RHS%EJ + LHS%EJ*RHS%R
      RES%EK = LHS%R*RHS%EK + LHS%EK*RHS%R
      RES%EL = LHS%R*RHS%EL + LHS%EL*RHS%R
      RES%EM = LHS%R*RHS%EM + LHS%EM*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION DONUMM22N2_MUL_OO_SS

   ELEMENTAL FUNCTION DONUMM22N2_MUL_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES 

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
      RES%E8 = LHS*RHS%E8
      RES%E9 = LHS*RHS%E9
      RES%EA = LHS*RHS%EA
      RES%EB = LHS*RHS%EB
      RES%EC = LHS*RHS%EC
      RES%ED = LHS*RHS%ED
      RES%EE = LHS*RHS%EE
      RES%EF = LHS*RHS%EF
      RES%EG = LHS*RHS%EG
      RES%EH = LHS*RHS%EH
      RES%EI = LHS*RHS%EI
      RES%EJ = LHS*RHS%EJ
      RES%EK = LHS*RHS%EK
      RES%EL = LHS*RHS%EL
      RES%EM = LHS*RHS%EM

      ! Order 2
      RES%E11 = LHS*RHS%E11
      RES%E22 = LHS*RHS%E22
      RES%E33 = LHS*RHS%E33
      RES%E44 = LHS*RHS%E44
      RES%E55 = LHS*RHS%E55
      RES%E66 = LHS*RHS%E66
      RES%E77 = LHS*RHS%E77
      RES%E88 = LHS*RHS%E88
      RES%E99 = LHS*RHS%E99
      RES%EAA = LHS*RHS%EAA
      RES%EBB = LHS*RHS%EBB
      RES%ECC = LHS*RHS%ECC
      RES%EDD = LHS*RHS%EDD
      RES%EEE = LHS*RHS%EEE
      RES%EFF = LHS*RHS%EFF
      RES%EGG = LHS*RHS%EGG
      RES%EHH = LHS*RHS%EHH
      RES%EII = LHS*RHS%EII
      RES%EJJ = LHS*RHS%EJJ
      RES%EKK = LHS*RHS%EKK
      RES%ELL = LHS*RHS%ELL
      RES%EMM = LHS*RHS%EMM

   END FUNCTION DONUMM22N2_MUL_RO_SS

   ELEMENTAL FUNCTION DONUMM22N2_MUL_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES 

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
      RES%E8 = LHS%E8*RHS
      RES%E9 = LHS%E9*RHS
      RES%EA = LHS%EA*RHS
      RES%EB = LHS%EB*RHS
      RES%EC = LHS%EC*RHS
      RES%ED = LHS%ED*RHS
      RES%EE = LHS%EE*RHS
      RES%EF = LHS%EF*RHS
      RES%EG = LHS%EG*RHS
      RES%EH = LHS%EH*RHS
      RES%EI = LHS%EI*RHS
      RES%EJ = LHS%EJ*RHS
      RES%EK = LHS%EK*RHS
      RES%EL = LHS%EL*RHS
      RES%EM = LHS%EM*RHS

      ! Order 2
      RES%E11 = LHS%E11*RHS
      RES%E22 = LHS%E22*RHS
      RES%E33 = LHS%E33*RHS
      RES%E44 = LHS%E44*RHS
      RES%E55 = LHS%E55*RHS
      RES%E66 = LHS%E66*RHS
      RES%E77 = LHS%E77*RHS
      RES%E88 = LHS%E88*RHS
      RES%E99 = LHS%E99*RHS
      RES%EAA = LHS%EAA*RHS
      RES%EBB = LHS%EBB*RHS
      RES%ECC = LHS%ECC*RHS
      RES%EDD = LHS%EDD*RHS
      RES%EEE = LHS%EEE*RHS
      RES%EFF = LHS%EFF*RHS
      RES%EGG = LHS%EGG*RHS
      RES%EHH = LHS%EHH*RHS
      RES%EII = LHS%EII*RHS
      RES%EJJ = LHS%EJJ*RHS
      RES%EKK = LHS%EKK*RHS
      RES%ELL = LHS%ELL*RHS
      RES%EMM = LHS%EMM*RHS

   END FUNCTION DONUMM22N2_MUL_OR_SS

   FUNCTION DONUMM22N2_ADD_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:)
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1)) 

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
      RES%E8 = LHS%E8 + RHS%E8
      RES%E9 = LHS%E9 + RHS%E9
      RES%EA = LHS%EA + RHS%EA
      RES%EB = LHS%EB + RHS%EB
      RES%EC = LHS%EC + RHS%EC
      RES%ED = LHS%ED + RHS%ED
      RES%EE = LHS%EE + RHS%EE
      RES%EF = LHS%EF + RHS%EF
      RES%EG = LHS%EG + RHS%EG
      RES%EH = LHS%EH + RHS%EH
      RES%EI = LHS%EI + RHS%EI
      RES%EJ = LHS%EJ + RHS%EJ
      RES%EK = LHS%EK + RHS%EK
      RES%EL = LHS%EL + RHS%EL
      RES%EM = LHS%EM + RHS%EM

      ! Order 2
      RES%E11 = LHS%E11 + RHS%E11
      RES%E22 = LHS%E22 + RHS%E22
      RES%E33 = LHS%E33 + RHS%E33
      RES%E44 = LHS%E44 + RHS%E44
      RES%E55 = LHS%E55 + RHS%E55
      RES%E66 = LHS%E66 + RHS%E66
      RES%E77 = LHS%E77 + RHS%E77
      RES%E88 = LHS%E88 + RHS%E88
      RES%E99 = LHS%E99 + RHS%E99
      RES%EAA = LHS%EAA + RHS%EAA
      RES%EBB = LHS%EBB + RHS%EBB
      RES%ECC = LHS%ECC + RHS%ECC
      RES%EDD = LHS%EDD + RHS%EDD
      RES%EEE = LHS%EEE + RHS%EEE
      RES%EFF = LHS%EFF + RHS%EFF
      RES%EGG = LHS%EGG + RHS%EGG
      RES%EHH = LHS%EHH + RHS%EHH
      RES%EII = LHS%EII + RHS%EII
      RES%EJJ = LHS%EJJ + RHS%EJJ
      RES%EKK = LHS%EKK + RHS%EKK
      RES%ELL = LHS%ELL + RHS%ELL
      RES%EMM = LHS%EMM + RHS%EMM

   END FUNCTION DONUMM22N2_ADD_OO_VS

   FUNCTION DONUMM22N2_ADD_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1)) 

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
      RES%E8 =  + RHS%E8
      RES%E9 =  + RHS%E9
      RES%EA =  + RHS%EA
      RES%EB =  + RHS%EB
      RES%EC =  + RHS%EC
      RES%ED =  + RHS%ED
      RES%EE =  + RHS%EE
      RES%EF =  + RHS%EF
      RES%EG =  + RHS%EG
      RES%EH =  + RHS%EH
      RES%EI =  + RHS%EI
      RES%EJ =  + RHS%EJ
      RES%EK =  + RHS%EK
      RES%EL =  + RHS%EL
      RES%EM =  + RHS%EM

      ! Order 2
      RES%E11 =  + RHS%E11
      RES%E22 =  + RHS%E22
      RES%E33 =  + RHS%E33
      RES%E44 =  + RHS%E44
      RES%E55 =  + RHS%E55
      RES%E66 =  + RHS%E66
      RES%E77 =  + RHS%E77
      RES%E88 =  + RHS%E88
      RES%E99 =  + RHS%E99
      RES%EAA =  + RHS%EAA
      RES%EBB =  + RHS%EBB
      RES%ECC =  + RHS%ECC
      RES%EDD =  + RHS%EDD
      RES%EEE =  + RHS%EEE
      RES%EFF =  + RHS%EFF
      RES%EGG =  + RHS%EGG
      RES%EHH =  + RHS%EHH
      RES%EII =  + RHS%EII
      RES%EJJ =  + RHS%EJJ
      RES%EKK =  + RHS%EKK
      RES%ELL =  + RHS%ELL
      RES%EMM =  + RHS%EMM

   END FUNCTION DONUMM22N2_ADD_RO_VS

   FUNCTION DONUMM22N2_ADD_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1)) 

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
      RES%E8 = LHS%E8
      RES%E9 = LHS%E9
      RES%EA = LHS%EA
      RES%EB = LHS%EB
      RES%EC = LHS%EC
      RES%ED = LHS%ED
      RES%EE = LHS%EE
      RES%EF = LHS%EF
      RES%EG = LHS%EG
      RES%EH = LHS%EH
      RES%EI = LHS%EI
      RES%EJ = LHS%EJ
      RES%EK = LHS%EK
      RES%EL = LHS%EL
      RES%EM = LHS%EM

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77
      RES%E88 = LHS%E88
      RES%E99 = LHS%E99
      RES%EAA = LHS%EAA
      RES%EBB = LHS%EBB
      RES%ECC = LHS%ECC
      RES%EDD = LHS%EDD
      RES%EEE = LHS%EEE
      RES%EFF = LHS%EFF
      RES%EGG = LHS%EGG
      RES%EHH = LHS%EHH
      RES%EII = LHS%EII
      RES%EJJ = LHS%EJJ
      RES%EKK = LHS%EKK
      RES%ELL = LHS%ELL
      RES%EMM = LHS%EMM

   END FUNCTION DONUMM22N2_ADD_OR_VS

   FUNCTION DONUMM22N2_SUB_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:)
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1)) 

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
      RES%E8 = LHS%E8 - RHS%E8
      RES%E9 = LHS%E9 - RHS%E9
      RES%EA = LHS%EA - RHS%EA
      RES%EB = LHS%EB - RHS%EB
      RES%EC = LHS%EC - RHS%EC
      RES%ED = LHS%ED - RHS%ED
      RES%EE = LHS%EE - RHS%EE
      RES%EF = LHS%EF - RHS%EF
      RES%EG = LHS%EG - RHS%EG
      RES%EH = LHS%EH - RHS%EH
      RES%EI = LHS%EI - RHS%EI
      RES%EJ = LHS%EJ - RHS%EJ
      RES%EK = LHS%EK - RHS%EK
      RES%EL = LHS%EL - RHS%EL
      RES%EM = LHS%EM - RHS%EM

      ! Order 2
      RES%E11 = LHS%E11 - RHS%E11
      RES%E22 = LHS%E22 - RHS%E22
      RES%E33 = LHS%E33 - RHS%E33
      RES%E44 = LHS%E44 - RHS%E44
      RES%E55 = LHS%E55 - RHS%E55
      RES%E66 = LHS%E66 - RHS%E66
      RES%E77 = LHS%E77 - RHS%E77
      RES%E88 = LHS%E88 - RHS%E88
      RES%E99 = LHS%E99 - RHS%E99
      RES%EAA = LHS%EAA - RHS%EAA
      RES%EBB = LHS%EBB - RHS%EBB
      RES%ECC = LHS%ECC - RHS%ECC
      RES%EDD = LHS%EDD - RHS%EDD
      RES%EEE = LHS%EEE - RHS%EEE
      RES%EFF = LHS%EFF - RHS%EFF
      RES%EGG = LHS%EGG - RHS%EGG
      RES%EHH = LHS%EHH - RHS%EHH
      RES%EII = LHS%EII - RHS%EII
      RES%EJJ = LHS%EJJ - RHS%EJJ
      RES%EKK = LHS%EKK - RHS%EKK
      RES%ELL = LHS%ELL - RHS%ELL
      RES%EMM = LHS%EMM - RHS%EMM

   END FUNCTION DONUMM22N2_SUB_OO_VS

   FUNCTION DONUMM22N2_SUB_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1)) 

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
      RES%E8 =  - RHS%E8
      RES%E9 =  - RHS%E9
      RES%EA =  - RHS%EA
      RES%EB =  - RHS%EB
      RES%EC =  - RHS%EC
      RES%ED =  - RHS%ED
      RES%EE =  - RHS%EE
      RES%EF =  - RHS%EF
      RES%EG =  - RHS%EG
      RES%EH =  - RHS%EH
      RES%EI =  - RHS%EI
      RES%EJ =  - RHS%EJ
      RES%EK =  - RHS%EK
      RES%EL =  - RHS%EL
      RES%EM =  - RHS%EM

      ! Order 2
      RES%E11 =  - RHS%E11
      RES%E22 =  - RHS%E22
      RES%E33 =  - RHS%E33
      RES%E44 =  - RHS%E44
      RES%E55 =  - RHS%E55
      RES%E66 =  - RHS%E66
      RES%E77 =  - RHS%E77
      RES%E88 =  - RHS%E88
      RES%E99 =  - RHS%E99
      RES%EAA =  - RHS%EAA
      RES%EBB =  - RHS%EBB
      RES%ECC =  - RHS%ECC
      RES%EDD =  - RHS%EDD
      RES%EEE =  - RHS%EEE
      RES%EFF =  - RHS%EFF
      RES%EGG =  - RHS%EGG
      RES%EHH =  - RHS%EHH
      RES%EII =  - RHS%EII
      RES%EJJ =  - RHS%EJJ
      RES%EKK =  - RHS%EKK
      RES%ELL =  - RHS%ELL
      RES%EMM =  - RHS%EMM

   END FUNCTION DONUMM22N2_SUB_RO_VS

   FUNCTION DONUMM22N2_SUB_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1)) 

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
      RES%E8 = LHS%E8
      RES%E9 = LHS%E9
      RES%EA = LHS%EA
      RES%EB = LHS%EB
      RES%EC = LHS%EC
      RES%ED = LHS%ED
      RES%EE = LHS%EE
      RES%EF = LHS%EF
      RES%EG = LHS%EG
      RES%EH = LHS%EH
      RES%EI = LHS%EI
      RES%EJ = LHS%EJ
      RES%EK = LHS%EK
      RES%EL = LHS%EL
      RES%EM = LHS%EM

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77
      RES%E88 = LHS%E88
      RES%E99 = LHS%E99
      RES%EAA = LHS%EAA
      RES%EBB = LHS%EBB
      RES%ECC = LHS%ECC
      RES%EDD = LHS%EDD
      RES%EEE = LHS%EEE
      RES%EFF = LHS%EFF
      RES%EGG = LHS%EGG
      RES%EHH = LHS%EHH
      RES%EII = LHS%EII
      RES%EJJ = LHS%EJJ
      RES%EKK = LHS%EKK
      RES%ELL = LHS%ELL
      RES%EMM = LHS%EMM

   END FUNCTION DONUMM22N2_SUB_OR_VS

   FUNCTION DONUMM22N2_MUL_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:)
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      RES%E22 = LHS%R*RHS%E22 + LHS%E22*RHS%R + LHS%E2*RHS%E2
      RES%E33 = LHS%R*RHS%E33 + LHS%E33*RHS%R + LHS%E3*RHS%E3
      RES%E44 = LHS%R*RHS%E44 + LHS%E44*RHS%R + LHS%E4*RHS%E4
      RES%E55 = LHS%R*RHS%E55 + LHS%E55*RHS%R + LHS%E5*RHS%E5
      RES%E66 = LHS%R*RHS%E66 + LHS%E66*RHS%R + LHS%E6*RHS%E6
      RES%E77 = LHS%R*RHS%E77 + LHS%E77*RHS%R + LHS%E7*RHS%E7
      RES%E88 = LHS%R*RHS%E88 + LHS%E88*RHS%R + LHS%E8*RHS%E8
      RES%E99 = LHS%R*RHS%E99 + LHS%E99*RHS%R + LHS%E9*RHS%E9
      RES%EAA = LHS%R*RHS%EAA + LHS%EAA*RHS%R + LHS%EA*RHS%EA
      RES%EBB = LHS%R*RHS%EBB + LHS%EBB*RHS%R + LHS%EB*RHS%EB
      RES%ECC = LHS%R*RHS%ECC + LHS%ECC*RHS%R + LHS%EC*RHS%EC
      RES%EDD = LHS%R*RHS%EDD + LHS%EDD*RHS%R + LHS%ED*RHS%ED
      RES%EEE = LHS%R*RHS%EEE + LHS%EEE*RHS%R + LHS%EE*RHS%EE
      RES%EFF = LHS%R*RHS%EFF + LHS%EFF*RHS%R + LHS%EF*RHS%EF
      RES%EGG = LHS%R*RHS%EGG + LHS%EGG*RHS%R + LHS%EG*RHS%EG
      RES%EHH = LHS%R*RHS%EHH + LHS%EHH*RHS%R + LHS%EH*RHS%EH
      RES%EII = LHS%R*RHS%EII + LHS%EII*RHS%R + LHS%EI*RHS%EI
      RES%EJJ = LHS%R*RHS%EJJ + LHS%EJJ*RHS%R + LHS%EJ*RHS%EJ
      RES%EKK = LHS%R*RHS%EKK + LHS%EKK*RHS%R + LHS%EK*RHS%EK
      RES%ELL = LHS%R*RHS%ELL + LHS%ELL*RHS%R + LHS%EL*RHS%EL
      RES%EMM = LHS%R*RHS%EMM + LHS%EMM*RHS%R + LHS%EM*RHS%EM
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      RES%E3 = LHS%R*RHS%E3 + LHS%E3*RHS%R
      RES%E4 = LHS%R*RHS%E4 + LHS%E4*RHS%R
      RES%E5 = LHS%R*RHS%E5 + LHS%E5*RHS%R
      RES%E6 = LHS%R*RHS%E6 + LHS%E6*RHS%R
      RES%E7 = LHS%R*RHS%E7 + LHS%E7*RHS%R
      RES%E8 = LHS%R*RHS%E8 + LHS%E8*RHS%R
      RES%E9 = LHS%R*RHS%E9 + LHS%E9*RHS%R
      RES%EA = LHS%R*RHS%EA + LHS%EA*RHS%R
      RES%EB = LHS%R*RHS%EB + LHS%EB*RHS%R
      RES%EC = LHS%R*RHS%EC + LHS%EC*RHS%R
      RES%ED = LHS%R*RHS%ED + LHS%ED*RHS%R
      RES%EE = LHS%R*RHS%EE + LHS%EE*RHS%R
      RES%EF = LHS%R*RHS%EF + LHS%EF*RHS%R
      RES%EG = LHS%R*RHS%EG + LHS%EG*RHS%R
      RES%EH = LHS%R*RHS%EH + LHS%EH*RHS%R
      RES%EI = LHS%R*RHS%EI + LHS%EI*RHS%R
      RES%EJ = LHS%R*RHS%EJ + LHS%EJ*RHS%R
      RES%EK = LHS%R*RHS%EK + LHS%EK*RHS%R
      RES%EL = LHS%R*RHS%EL + LHS%EL*RHS%R
      RES%EM = LHS%R*RHS%EM + LHS%EM*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION DONUMM22N2_MUL_OO_VS

   FUNCTION DONUMM22N2_MUL_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1)) 

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
      RES%E8 = LHS*RHS%E8
      RES%E9 = LHS*RHS%E9
      RES%EA = LHS*RHS%EA
      RES%EB = LHS*RHS%EB
      RES%EC = LHS*RHS%EC
      RES%ED = LHS*RHS%ED
      RES%EE = LHS*RHS%EE
      RES%EF = LHS*RHS%EF
      RES%EG = LHS*RHS%EG
      RES%EH = LHS*RHS%EH
      RES%EI = LHS*RHS%EI
      RES%EJ = LHS*RHS%EJ
      RES%EK = LHS*RHS%EK
      RES%EL = LHS*RHS%EL
      RES%EM = LHS*RHS%EM

      ! Order 2
      RES%E11 = LHS*RHS%E11
      RES%E22 = LHS*RHS%E22
      RES%E33 = LHS*RHS%E33
      RES%E44 = LHS*RHS%E44
      RES%E55 = LHS*RHS%E55
      RES%E66 = LHS*RHS%E66
      RES%E77 = LHS*RHS%E77
      RES%E88 = LHS*RHS%E88
      RES%E99 = LHS*RHS%E99
      RES%EAA = LHS*RHS%EAA
      RES%EBB = LHS*RHS%EBB
      RES%ECC = LHS*RHS%ECC
      RES%EDD = LHS*RHS%EDD
      RES%EEE = LHS*RHS%EEE
      RES%EFF = LHS*RHS%EFF
      RES%EGG = LHS*RHS%EGG
      RES%EHH = LHS*RHS%EHH
      RES%EII = LHS*RHS%EII
      RES%EJJ = LHS*RHS%EJJ
      RES%EKK = LHS*RHS%EKK
      RES%ELL = LHS*RHS%ELL
      RES%EMM = LHS*RHS%EMM

   END FUNCTION DONUMM22N2_MUL_RO_VS

   FUNCTION DONUMM22N2_MUL_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1)) 

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
      RES%E8 = LHS%E8*RHS
      RES%E9 = LHS%E9*RHS
      RES%EA = LHS%EA*RHS
      RES%EB = LHS%EB*RHS
      RES%EC = LHS%EC*RHS
      RES%ED = LHS%ED*RHS
      RES%EE = LHS%EE*RHS
      RES%EF = LHS%EF*RHS
      RES%EG = LHS%EG*RHS
      RES%EH = LHS%EH*RHS
      RES%EI = LHS%EI*RHS
      RES%EJ = LHS%EJ*RHS
      RES%EK = LHS%EK*RHS
      RES%EL = LHS%EL*RHS
      RES%EM = LHS%EM*RHS

      ! Order 2
      RES%E11 = LHS%E11*RHS
      RES%E22 = LHS%E22*RHS
      RES%E33 = LHS%E33*RHS
      RES%E44 = LHS%E44*RHS
      RES%E55 = LHS%E55*RHS
      RES%E66 = LHS%E66*RHS
      RES%E77 = LHS%E77*RHS
      RES%E88 = LHS%E88*RHS
      RES%E99 = LHS%E99*RHS
      RES%EAA = LHS%EAA*RHS
      RES%EBB = LHS%EBB*RHS
      RES%ECC = LHS%ECC*RHS
      RES%EDD = LHS%EDD*RHS
      RES%EEE = LHS%EEE*RHS
      RES%EFF = LHS%EFF*RHS
      RES%EGG = LHS%EGG*RHS
      RES%EHH = LHS%EHH*RHS
      RES%EII = LHS%EII*RHS
      RES%EJJ = LHS%EJJ*RHS
      RES%EKK = LHS%EKK*RHS
      RES%ELL = LHS%ELL*RHS
      RES%EMM = LHS%EMM*RHS

   END FUNCTION DONUMM22N2_MUL_OR_VS

   FUNCTION DONUMM22N2_ADD_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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
      RES%E8 = LHS%E8 + RHS%E8
      RES%E9 = LHS%E9 + RHS%E9
      RES%EA = LHS%EA + RHS%EA
      RES%EB = LHS%EB + RHS%EB
      RES%EC = LHS%EC + RHS%EC
      RES%ED = LHS%ED + RHS%ED
      RES%EE = LHS%EE + RHS%EE
      RES%EF = LHS%EF + RHS%EF
      RES%EG = LHS%EG + RHS%EG
      RES%EH = LHS%EH + RHS%EH
      RES%EI = LHS%EI + RHS%EI
      RES%EJ = LHS%EJ + RHS%EJ
      RES%EK = LHS%EK + RHS%EK
      RES%EL = LHS%EL + RHS%EL
      RES%EM = LHS%EM + RHS%EM

      ! Order 2
      RES%E11 = LHS%E11 + RHS%E11
      RES%E22 = LHS%E22 + RHS%E22
      RES%E33 = LHS%E33 + RHS%E33
      RES%E44 = LHS%E44 + RHS%E44
      RES%E55 = LHS%E55 + RHS%E55
      RES%E66 = LHS%E66 + RHS%E66
      RES%E77 = LHS%E77 + RHS%E77
      RES%E88 = LHS%E88 + RHS%E88
      RES%E99 = LHS%E99 + RHS%E99
      RES%EAA = LHS%EAA + RHS%EAA
      RES%EBB = LHS%EBB + RHS%EBB
      RES%ECC = LHS%ECC + RHS%ECC
      RES%EDD = LHS%EDD + RHS%EDD
      RES%EEE = LHS%EEE + RHS%EEE
      RES%EFF = LHS%EFF + RHS%EFF
      RES%EGG = LHS%EGG + RHS%EGG
      RES%EHH = LHS%EHH + RHS%EHH
      RES%EII = LHS%EII + RHS%EII
      RES%EJJ = LHS%EJJ + RHS%EJJ
      RES%EKK = LHS%EKK + RHS%EKK
      RES%ELL = LHS%ELL + RHS%ELL
      RES%EMM = LHS%EMM + RHS%EMM

   END FUNCTION DONUMM22N2_ADD_OO_MS

   FUNCTION DONUMM22N2_ADD_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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
      RES%E8 =  + RHS%E8
      RES%E9 =  + RHS%E9
      RES%EA =  + RHS%EA
      RES%EB =  + RHS%EB
      RES%EC =  + RHS%EC
      RES%ED =  + RHS%ED
      RES%EE =  + RHS%EE
      RES%EF =  + RHS%EF
      RES%EG =  + RHS%EG
      RES%EH =  + RHS%EH
      RES%EI =  + RHS%EI
      RES%EJ =  + RHS%EJ
      RES%EK =  + RHS%EK
      RES%EL =  + RHS%EL
      RES%EM =  + RHS%EM

      ! Order 2
      RES%E11 =  + RHS%E11
      RES%E22 =  + RHS%E22
      RES%E33 =  + RHS%E33
      RES%E44 =  + RHS%E44
      RES%E55 =  + RHS%E55
      RES%E66 =  + RHS%E66
      RES%E77 =  + RHS%E77
      RES%E88 =  + RHS%E88
      RES%E99 =  + RHS%E99
      RES%EAA =  + RHS%EAA
      RES%EBB =  + RHS%EBB
      RES%ECC =  + RHS%ECC
      RES%EDD =  + RHS%EDD
      RES%EEE =  + RHS%EEE
      RES%EFF =  + RHS%EFF
      RES%EGG =  + RHS%EGG
      RES%EHH =  + RHS%EHH
      RES%EII =  + RHS%EII
      RES%EJJ =  + RHS%EJJ
      RES%EKK =  + RHS%EKK
      RES%ELL =  + RHS%ELL
      RES%EMM =  + RHS%EMM

   END FUNCTION DONUMM22N2_ADD_RO_MS

   FUNCTION DONUMM22N2_ADD_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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
      RES%E8 = LHS%E8
      RES%E9 = LHS%E9
      RES%EA = LHS%EA
      RES%EB = LHS%EB
      RES%EC = LHS%EC
      RES%ED = LHS%ED
      RES%EE = LHS%EE
      RES%EF = LHS%EF
      RES%EG = LHS%EG
      RES%EH = LHS%EH
      RES%EI = LHS%EI
      RES%EJ = LHS%EJ
      RES%EK = LHS%EK
      RES%EL = LHS%EL
      RES%EM = LHS%EM

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77
      RES%E88 = LHS%E88
      RES%E99 = LHS%E99
      RES%EAA = LHS%EAA
      RES%EBB = LHS%EBB
      RES%ECC = LHS%ECC
      RES%EDD = LHS%EDD
      RES%EEE = LHS%EEE
      RES%EFF = LHS%EFF
      RES%EGG = LHS%EGG
      RES%EHH = LHS%EHH
      RES%EII = LHS%EII
      RES%EJJ = LHS%EJJ
      RES%EKK = LHS%EKK
      RES%ELL = LHS%ELL
      RES%EMM = LHS%EMM

   END FUNCTION DONUMM22N2_ADD_OR_MS

   FUNCTION DONUMM22N2_SUB_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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
      RES%E8 = LHS%E8 - RHS%E8
      RES%E9 = LHS%E9 - RHS%E9
      RES%EA = LHS%EA - RHS%EA
      RES%EB = LHS%EB - RHS%EB
      RES%EC = LHS%EC - RHS%EC
      RES%ED = LHS%ED - RHS%ED
      RES%EE = LHS%EE - RHS%EE
      RES%EF = LHS%EF - RHS%EF
      RES%EG = LHS%EG - RHS%EG
      RES%EH = LHS%EH - RHS%EH
      RES%EI = LHS%EI - RHS%EI
      RES%EJ = LHS%EJ - RHS%EJ
      RES%EK = LHS%EK - RHS%EK
      RES%EL = LHS%EL - RHS%EL
      RES%EM = LHS%EM - RHS%EM

      ! Order 2
      RES%E11 = LHS%E11 - RHS%E11
      RES%E22 = LHS%E22 - RHS%E22
      RES%E33 = LHS%E33 - RHS%E33
      RES%E44 = LHS%E44 - RHS%E44
      RES%E55 = LHS%E55 - RHS%E55
      RES%E66 = LHS%E66 - RHS%E66
      RES%E77 = LHS%E77 - RHS%E77
      RES%E88 = LHS%E88 - RHS%E88
      RES%E99 = LHS%E99 - RHS%E99
      RES%EAA = LHS%EAA - RHS%EAA
      RES%EBB = LHS%EBB - RHS%EBB
      RES%ECC = LHS%ECC - RHS%ECC
      RES%EDD = LHS%EDD - RHS%EDD
      RES%EEE = LHS%EEE - RHS%EEE
      RES%EFF = LHS%EFF - RHS%EFF
      RES%EGG = LHS%EGG - RHS%EGG
      RES%EHH = LHS%EHH - RHS%EHH
      RES%EII = LHS%EII - RHS%EII
      RES%EJJ = LHS%EJJ - RHS%EJJ
      RES%EKK = LHS%EKK - RHS%EKK
      RES%ELL = LHS%ELL - RHS%ELL
      RES%EMM = LHS%EMM - RHS%EMM

   END FUNCTION DONUMM22N2_SUB_OO_MS

   FUNCTION DONUMM22N2_SUB_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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
      RES%E8 =  - RHS%E8
      RES%E9 =  - RHS%E9
      RES%EA =  - RHS%EA
      RES%EB =  - RHS%EB
      RES%EC =  - RHS%EC
      RES%ED =  - RHS%ED
      RES%EE =  - RHS%EE
      RES%EF =  - RHS%EF
      RES%EG =  - RHS%EG
      RES%EH =  - RHS%EH
      RES%EI =  - RHS%EI
      RES%EJ =  - RHS%EJ
      RES%EK =  - RHS%EK
      RES%EL =  - RHS%EL
      RES%EM =  - RHS%EM

      ! Order 2
      RES%E11 =  - RHS%E11
      RES%E22 =  - RHS%E22
      RES%E33 =  - RHS%E33
      RES%E44 =  - RHS%E44
      RES%E55 =  - RHS%E55
      RES%E66 =  - RHS%E66
      RES%E77 =  - RHS%E77
      RES%E88 =  - RHS%E88
      RES%E99 =  - RHS%E99
      RES%EAA =  - RHS%EAA
      RES%EBB =  - RHS%EBB
      RES%ECC =  - RHS%ECC
      RES%EDD =  - RHS%EDD
      RES%EEE =  - RHS%EEE
      RES%EFF =  - RHS%EFF
      RES%EGG =  - RHS%EGG
      RES%EHH =  - RHS%EHH
      RES%EII =  - RHS%EII
      RES%EJJ =  - RHS%EJJ
      RES%EKK =  - RHS%EKK
      RES%ELL =  - RHS%ELL
      RES%EMM =  - RHS%EMM

   END FUNCTION DONUMM22N2_SUB_RO_MS

   FUNCTION DONUMM22N2_SUB_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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
      RES%E8 = LHS%E8
      RES%E9 = LHS%E9
      RES%EA = LHS%EA
      RES%EB = LHS%EB
      RES%EC = LHS%EC
      RES%ED = LHS%ED
      RES%EE = LHS%EE
      RES%EF = LHS%EF
      RES%EG = LHS%EG
      RES%EH = LHS%EH
      RES%EI = LHS%EI
      RES%EJ = LHS%EJ
      RES%EK = LHS%EK
      RES%EL = LHS%EL
      RES%EM = LHS%EM

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77
      RES%E88 = LHS%E88
      RES%E99 = LHS%E99
      RES%EAA = LHS%EAA
      RES%EBB = LHS%EBB
      RES%ECC = LHS%ECC
      RES%EDD = LHS%EDD
      RES%EEE = LHS%EEE
      RES%EFF = LHS%EFF
      RES%EGG = LHS%EGG
      RES%EHH = LHS%EHH
      RES%EII = LHS%EII
      RES%EJJ = LHS%EJJ
      RES%EKK = LHS%EKK
      RES%ELL = LHS%ELL
      RES%EMM = LHS%EMM

   END FUNCTION DONUMM22N2_SUB_OR_MS

   FUNCTION DONUMM22N2_MUL_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      RES%E22 = LHS%R*RHS%E22 + LHS%E22*RHS%R + LHS%E2*RHS%E2
      RES%E33 = LHS%R*RHS%E33 + LHS%E33*RHS%R + LHS%E3*RHS%E3
      RES%E44 = LHS%R*RHS%E44 + LHS%E44*RHS%R + LHS%E4*RHS%E4
      RES%E55 = LHS%R*RHS%E55 + LHS%E55*RHS%R + LHS%E5*RHS%E5
      RES%E66 = LHS%R*RHS%E66 + LHS%E66*RHS%R + LHS%E6*RHS%E6
      RES%E77 = LHS%R*RHS%E77 + LHS%E77*RHS%R + LHS%E7*RHS%E7
      RES%E88 = LHS%R*RHS%E88 + LHS%E88*RHS%R + LHS%E8*RHS%E8
      RES%E99 = LHS%R*RHS%E99 + LHS%E99*RHS%R + LHS%E9*RHS%E9
      RES%EAA = LHS%R*RHS%EAA + LHS%EAA*RHS%R + LHS%EA*RHS%EA
      RES%EBB = LHS%R*RHS%EBB + LHS%EBB*RHS%R + LHS%EB*RHS%EB
      RES%ECC = LHS%R*RHS%ECC + LHS%ECC*RHS%R + LHS%EC*RHS%EC
      RES%EDD = LHS%R*RHS%EDD + LHS%EDD*RHS%R + LHS%ED*RHS%ED
      RES%EEE = LHS%R*RHS%EEE + LHS%EEE*RHS%R + LHS%EE*RHS%EE
      RES%EFF = LHS%R*RHS%EFF + LHS%EFF*RHS%R + LHS%EF*RHS%EF
      RES%EGG = LHS%R*RHS%EGG + LHS%EGG*RHS%R + LHS%EG*RHS%EG
      RES%EHH = LHS%R*RHS%EHH + LHS%EHH*RHS%R + LHS%EH*RHS%EH
      RES%EII = LHS%R*RHS%EII + LHS%EII*RHS%R + LHS%EI*RHS%EI
      RES%EJJ = LHS%R*RHS%EJJ + LHS%EJJ*RHS%R + LHS%EJ*RHS%EJ
      RES%EKK = LHS%R*RHS%EKK + LHS%EKK*RHS%R + LHS%EK*RHS%EK
      RES%ELL = LHS%R*RHS%ELL + LHS%ELL*RHS%R + LHS%EL*RHS%EL
      RES%EMM = LHS%R*RHS%EMM + LHS%EMM*RHS%R + LHS%EM*RHS%EM
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      RES%E3 = LHS%R*RHS%E3 + LHS%E3*RHS%R
      RES%E4 = LHS%R*RHS%E4 + LHS%E4*RHS%R
      RES%E5 = LHS%R*RHS%E5 + LHS%E5*RHS%R
      RES%E6 = LHS%R*RHS%E6 + LHS%E6*RHS%R
      RES%E7 = LHS%R*RHS%E7 + LHS%E7*RHS%R
      RES%E8 = LHS%R*RHS%E8 + LHS%E8*RHS%R
      RES%E9 = LHS%R*RHS%E9 + LHS%E9*RHS%R
      RES%EA = LHS%R*RHS%EA + LHS%EA*RHS%R
      RES%EB = LHS%R*RHS%EB + LHS%EB*RHS%R
      RES%EC = LHS%R*RHS%EC + LHS%EC*RHS%R
      RES%ED = LHS%R*RHS%ED + LHS%ED*RHS%R
      RES%EE = LHS%R*RHS%EE + LHS%EE*RHS%R
      RES%EF = LHS%R*RHS%EF + LHS%EF*RHS%R
      RES%EG = LHS%R*RHS%EG + LHS%EG*RHS%R
      RES%EH = LHS%R*RHS%EH + LHS%EH*RHS%R
      RES%EI = LHS%R*RHS%EI + LHS%EI*RHS%R
      RES%EJ = LHS%R*RHS%EJ + LHS%EJ*RHS%R
      RES%EK = LHS%R*RHS%EK + LHS%EK*RHS%R
      RES%EL = LHS%R*RHS%EL + LHS%EL*RHS%R
      RES%EM = LHS%R*RHS%EM + LHS%EM*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION DONUMM22N2_MUL_OO_MS

   FUNCTION DONUMM22N2_MUL_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N2), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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
      RES%E8 = LHS*RHS%E8
      RES%E9 = LHS*RHS%E9
      RES%EA = LHS*RHS%EA
      RES%EB = LHS*RHS%EB
      RES%EC = LHS*RHS%EC
      RES%ED = LHS*RHS%ED
      RES%EE = LHS*RHS%EE
      RES%EF = LHS*RHS%EF
      RES%EG = LHS*RHS%EG
      RES%EH = LHS*RHS%EH
      RES%EI = LHS*RHS%EI
      RES%EJ = LHS*RHS%EJ
      RES%EK = LHS*RHS%EK
      RES%EL = LHS*RHS%EL
      RES%EM = LHS*RHS%EM

      ! Order 2
      RES%E11 = LHS*RHS%E11
      RES%E22 = LHS*RHS%E22
      RES%E33 = LHS*RHS%E33
      RES%E44 = LHS*RHS%E44
      RES%E55 = LHS*RHS%E55
      RES%E66 = LHS*RHS%E66
      RES%E77 = LHS*RHS%E77
      RES%E88 = LHS*RHS%E88
      RES%E99 = LHS*RHS%E99
      RES%EAA = LHS*RHS%EAA
      RES%EBB = LHS*RHS%EBB
      RES%ECC = LHS*RHS%ECC
      RES%EDD = LHS*RHS%EDD
      RES%EEE = LHS*RHS%EEE
      RES%EFF = LHS*RHS%EFF
      RES%EGG = LHS*RHS%EGG
      RES%EHH = LHS*RHS%EHH
      RES%EII = LHS*RHS%EII
      RES%EJJ = LHS*RHS%EJJ
      RES%EKK = LHS*RHS%EKK
      RES%ELL = LHS*RHS%ELL
      RES%EMM = LHS*RHS%EMM

   END FUNCTION DONUMM22N2_MUL_RO_MS

   FUNCTION DONUMM22N2_MUL_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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
      RES%E8 = LHS%E8*RHS
      RES%E9 = LHS%E9*RHS
      RES%EA = LHS%EA*RHS
      RES%EB = LHS%EB*RHS
      RES%EC = LHS%EC*RHS
      RES%ED = LHS%ED*RHS
      RES%EE = LHS%EE*RHS
      RES%EF = LHS%EF*RHS
      RES%EG = LHS%EG*RHS
      RES%EH = LHS%EH*RHS
      RES%EI = LHS%EI*RHS
      RES%EJ = LHS%EJ*RHS
      RES%EK = LHS%EK*RHS
      RES%EL = LHS%EL*RHS
      RES%EM = LHS%EM*RHS

      ! Order 2
      RES%E11 = LHS%E11*RHS
      RES%E22 = LHS%E22*RHS
      RES%E33 = LHS%E33*RHS
      RES%E44 = LHS%E44*RHS
      RES%E55 = LHS%E55*RHS
      RES%E66 = LHS%E66*RHS
      RES%E77 = LHS%E77*RHS
      RES%E88 = LHS%E88*RHS
      RES%E99 = LHS%E99*RHS
      RES%EAA = LHS%EAA*RHS
      RES%EBB = LHS%EBB*RHS
      RES%ECC = LHS%ECC*RHS
      RES%EDD = LHS%EDD*RHS
      RES%EEE = LHS%EEE*RHS
      RES%EFF = LHS%EFF*RHS
      RES%EGG = LHS%EGG*RHS
      RES%EHH = LHS%EHH*RHS
      RES%EII = LHS%EII*RHS
      RES%EJJ = LHS%EJJ*RHS
      RES%EKK = LHS%EKK*RHS
      RES%ELL = LHS%ELL*RHS
      RES%EMM = LHS%EMM*RHS

   END FUNCTION DONUMM22N2_MUL_OR_MS

   FUNCTION DONUMM22N2_ADD_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1)) 

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
      RES%E8 = LHS%E8 + RHS%E8
      RES%E9 = LHS%E9 + RHS%E9
      RES%EA = LHS%EA + RHS%EA
      RES%EB = LHS%EB + RHS%EB
      RES%EC = LHS%EC + RHS%EC
      RES%ED = LHS%ED + RHS%ED
      RES%EE = LHS%EE + RHS%EE
      RES%EF = LHS%EF + RHS%EF
      RES%EG = LHS%EG + RHS%EG
      RES%EH = LHS%EH + RHS%EH
      RES%EI = LHS%EI + RHS%EI
      RES%EJ = LHS%EJ + RHS%EJ
      RES%EK = LHS%EK + RHS%EK
      RES%EL = LHS%EL + RHS%EL
      RES%EM = LHS%EM + RHS%EM

      ! Order 2
      RES%E11 = LHS%E11 + RHS%E11
      RES%E22 = LHS%E22 + RHS%E22
      RES%E33 = LHS%E33 + RHS%E33
      RES%E44 = LHS%E44 + RHS%E44
      RES%E55 = LHS%E55 + RHS%E55
      RES%E66 = LHS%E66 + RHS%E66
      RES%E77 = LHS%E77 + RHS%E77
      RES%E88 = LHS%E88 + RHS%E88
      RES%E99 = LHS%E99 + RHS%E99
      RES%EAA = LHS%EAA + RHS%EAA
      RES%EBB = LHS%EBB + RHS%EBB
      RES%ECC = LHS%ECC + RHS%ECC
      RES%EDD = LHS%EDD + RHS%EDD
      RES%EEE = LHS%EEE + RHS%EEE
      RES%EFF = LHS%EFF + RHS%EFF
      RES%EGG = LHS%EGG + RHS%EGG
      RES%EHH = LHS%EHH + RHS%EHH
      RES%EII = LHS%EII + RHS%EII
      RES%EJJ = LHS%EJJ + RHS%EJJ
      RES%EKK = LHS%EKK + RHS%EKK
      RES%ELL = LHS%ELL + RHS%ELL
      RES%EMM = LHS%EMM + RHS%EMM

   END FUNCTION DONUMM22N2_ADD_OO_SV

   FUNCTION DONUMM22N2_ADD_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1)) 

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
      RES%E8 =  + RHS%E8
      RES%E9 =  + RHS%E9
      RES%EA =  + RHS%EA
      RES%EB =  + RHS%EB
      RES%EC =  + RHS%EC
      RES%ED =  + RHS%ED
      RES%EE =  + RHS%EE
      RES%EF =  + RHS%EF
      RES%EG =  + RHS%EG
      RES%EH =  + RHS%EH
      RES%EI =  + RHS%EI
      RES%EJ =  + RHS%EJ
      RES%EK =  + RHS%EK
      RES%EL =  + RHS%EL
      RES%EM =  + RHS%EM

      ! Order 2
      RES%E11 =  + RHS%E11
      RES%E22 =  + RHS%E22
      RES%E33 =  + RHS%E33
      RES%E44 =  + RHS%E44
      RES%E55 =  + RHS%E55
      RES%E66 =  + RHS%E66
      RES%E77 =  + RHS%E77
      RES%E88 =  + RHS%E88
      RES%E99 =  + RHS%E99
      RES%EAA =  + RHS%EAA
      RES%EBB =  + RHS%EBB
      RES%ECC =  + RHS%ECC
      RES%EDD =  + RHS%EDD
      RES%EEE =  + RHS%EEE
      RES%EFF =  + RHS%EFF
      RES%EGG =  + RHS%EGG
      RES%EHH =  + RHS%EHH
      RES%EII =  + RHS%EII
      RES%EJJ =  + RHS%EJJ
      RES%EKK =  + RHS%EKK
      RES%ELL =  + RHS%ELL
      RES%EMM =  + RHS%EMM

   END FUNCTION DONUMM22N2_ADD_RO_SV

   FUNCTION DONUMM22N2_ADD_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1)) 

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
      RES%E8 = LHS%E8
      RES%E9 = LHS%E9
      RES%EA = LHS%EA
      RES%EB = LHS%EB
      RES%EC = LHS%EC
      RES%ED = LHS%ED
      RES%EE = LHS%EE
      RES%EF = LHS%EF
      RES%EG = LHS%EG
      RES%EH = LHS%EH
      RES%EI = LHS%EI
      RES%EJ = LHS%EJ
      RES%EK = LHS%EK
      RES%EL = LHS%EL
      RES%EM = LHS%EM

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77
      RES%E88 = LHS%E88
      RES%E99 = LHS%E99
      RES%EAA = LHS%EAA
      RES%EBB = LHS%EBB
      RES%ECC = LHS%ECC
      RES%EDD = LHS%EDD
      RES%EEE = LHS%EEE
      RES%EFF = LHS%EFF
      RES%EGG = LHS%EGG
      RES%EHH = LHS%EHH
      RES%EII = LHS%EII
      RES%EJJ = LHS%EJJ
      RES%EKK = LHS%EKK
      RES%ELL = LHS%ELL
      RES%EMM = LHS%EMM

   END FUNCTION DONUMM22N2_ADD_OR_SV

   FUNCTION DONUMM22N2_SUB_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1)) 

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
      RES%E8 = LHS%E8 - RHS%E8
      RES%E9 = LHS%E9 - RHS%E9
      RES%EA = LHS%EA - RHS%EA
      RES%EB = LHS%EB - RHS%EB
      RES%EC = LHS%EC - RHS%EC
      RES%ED = LHS%ED - RHS%ED
      RES%EE = LHS%EE - RHS%EE
      RES%EF = LHS%EF - RHS%EF
      RES%EG = LHS%EG - RHS%EG
      RES%EH = LHS%EH - RHS%EH
      RES%EI = LHS%EI - RHS%EI
      RES%EJ = LHS%EJ - RHS%EJ
      RES%EK = LHS%EK - RHS%EK
      RES%EL = LHS%EL - RHS%EL
      RES%EM = LHS%EM - RHS%EM

      ! Order 2
      RES%E11 = LHS%E11 - RHS%E11
      RES%E22 = LHS%E22 - RHS%E22
      RES%E33 = LHS%E33 - RHS%E33
      RES%E44 = LHS%E44 - RHS%E44
      RES%E55 = LHS%E55 - RHS%E55
      RES%E66 = LHS%E66 - RHS%E66
      RES%E77 = LHS%E77 - RHS%E77
      RES%E88 = LHS%E88 - RHS%E88
      RES%E99 = LHS%E99 - RHS%E99
      RES%EAA = LHS%EAA - RHS%EAA
      RES%EBB = LHS%EBB - RHS%EBB
      RES%ECC = LHS%ECC - RHS%ECC
      RES%EDD = LHS%EDD - RHS%EDD
      RES%EEE = LHS%EEE - RHS%EEE
      RES%EFF = LHS%EFF - RHS%EFF
      RES%EGG = LHS%EGG - RHS%EGG
      RES%EHH = LHS%EHH - RHS%EHH
      RES%EII = LHS%EII - RHS%EII
      RES%EJJ = LHS%EJJ - RHS%EJJ
      RES%EKK = LHS%EKK - RHS%EKK
      RES%ELL = LHS%ELL - RHS%ELL
      RES%EMM = LHS%EMM - RHS%EMM

   END FUNCTION DONUMM22N2_SUB_OO_SV

   FUNCTION DONUMM22N2_SUB_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1)) 

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
      RES%E8 =  - RHS%E8
      RES%E9 =  - RHS%E9
      RES%EA =  - RHS%EA
      RES%EB =  - RHS%EB
      RES%EC =  - RHS%EC
      RES%ED =  - RHS%ED
      RES%EE =  - RHS%EE
      RES%EF =  - RHS%EF
      RES%EG =  - RHS%EG
      RES%EH =  - RHS%EH
      RES%EI =  - RHS%EI
      RES%EJ =  - RHS%EJ
      RES%EK =  - RHS%EK
      RES%EL =  - RHS%EL
      RES%EM =  - RHS%EM

      ! Order 2
      RES%E11 =  - RHS%E11
      RES%E22 =  - RHS%E22
      RES%E33 =  - RHS%E33
      RES%E44 =  - RHS%E44
      RES%E55 =  - RHS%E55
      RES%E66 =  - RHS%E66
      RES%E77 =  - RHS%E77
      RES%E88 =  - RHS%E88
      RES%E99 =  - RHS%E99
      RES%EAA =  - RHS%EAA
      RES%EBB =  - RHS%EBB
      RES%ECC =  - RHS%ECC
      RES%EDD =  - RHS%EDD
      RES%EEE =  - RHS%EEE
      RES%EFF =  - RHS%EFF
      RES%EGG =  - RHS%EGG
      RES%EHH =  - RHS%EHH
      RES%EII =  - RHS%EII
      RES%EJJ =  - RHS%EJJ
      RES%EKK =  - RHS%EKK
      RES%ELL =  - RHS%ELL
      RES%EMM =  - RHS%EMM

   END FUNCTION DONUMM22N2_SUB_RO_SV

   FUNCTION DONUMM22N2_SUB_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1)) 

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
      RES%E8 = LHS%E8
      RES%E9 = LHS%E9
      RES%EA = LHS%EA
      RES%EB = LHS%EB
      RES%EC = LHS%EC
      RES%ED = LHS%ED
      RES%EE = LHS%EE
      RES%EF = LHS%EF
      RES%EG = LHS%EG
      RES%EH = LHS%EH
      RES%EI = LHS%EI
      RES%EJ = LHS%EJ
      RES%EK = LHS%EK
      RES%EL = LHS%EL
      RES%EM = LHS%EM

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77
      RES%E88 = LHS%E88
      RES%E99 = LHS%E99
      RES%EAA = LHS%EAA
      RES%EBB = LHS%EBB
      RES%ECC = LHS%ECC
      RES%EDD = LHS%EDD
      RES%EEE = LHS%EEE
      RES%EFF = LHS%EFF
      RES%EGG = LHS%EGG
      RES%EHH = LHS%EHH
      RES%EII = LHS%EII
      RES%EJJ = LHS%EJJ
      RES%EKK = LHS%EKK
      RES%ELL = LHS%ELL
      RES%EMM = LHS%EMM

   END FUNCTION DONUMM22N2_SUB_OR_SV

   FUNCTION DONUMM22N2_MUL_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      RES%E22 = LHS%R*RHS%E22 + LHS%E22*RHS%R + LHS%E2*RHS%E2
      RES%E33 = LHS%R*RHS%E33 + LHS%E33*RHS%R + LHS%E3*RHS%E3
      RES%E44 = LHS%R*RHS%E44 + LHS%E44*RHS%R + LHS%E4*RHS%E4
      RES%E55 = LHS%R*RHS%E55 + LHS%E55*RHS%R + LHS%E5*RHS%E5
      RES%E66 = LHS%R*RHS%E66 + LHS%E66*RHS%R + LHS%E6*RHS%E6
      RES%E77 = LHS%R*RHS%E77 + LHS%E77*RHS%R + LHS%E7*RHS%E7
      RES%E88 = LHS%R*RHS%E88 + LHS%E88*RHS%R + LHS%E8*RHS%E8
      RES%E99 = LHS%R*RHS%E99 + LHS%E99*RHS%R + LHS%E9*RHS%E9
      RES%EAA = LHS%R*RHS%EAA + LHS%EAA*RHS%R + LHS%EA*RHS%EA
      RES%EBB = LHS%R*RHS%EBB + LHS%EBB*RHS%R + LHS%EB*RHS%EB
      RES%ECC = LHS%R*RHS%ECC + LHS%ECC*RHS%R + LHS%EC*RHS%EC
      RES%EDD = LHS%R*RHS%EDD + LHS%EDD*RHS%R + LHS%ED*RHS%ED
      RES%EEE = LHS%R*RHS%EEE + LHS%EEE*RHS%R + LHS%EE*RHS%EE
      RES%EFF = LHS%R*RHS%EFF + LHS%EFF*RHS%R + LHS%EF*RHS%EF
      RES%EGG = LHS%R*RHS%EGG + LHS%EGG*RHS%R + LHS%EG*RHS%EG
      RES%EHH = LHS%R*RHS%EHH + LHS%EHH*RHS%R + LHS%EH*RHS%EH
      RES%EII = LHS%R*RHS%EII + LHS%EII*RHS%R + LHS%EI*RHS%EI
      RES%EJJ = LHS%R*RHS%EJJ + LHS%EJJ*RHS%R + LHS%EJ*RHS%EJ
      RES%EKK = LHS%R*RHS%EKK + LHS%EKK*RHS%R + LHS%EK*RHS%EK
      RES%ELL = LHS%R*RHS%ELL + LHS%ELL*RHS%R + LHS%EL*RHS%EL
      RES%EMM = LHS%R*RHS%EMM + LHS%EMM*RHS%R + LHS%EM*RHS%EM
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      RES%E3 = LHS%R*RHS%E3 + LHS%E3*RHS%R
      RES%E4 = LHS%R*RHS%E4 + LHS%E4*RHS%R
      RES%E5 = LHS%R*RHS%E5 + LHS%E5*RHS%R
      RES%E6 = LHS%R*RHS%E6 + LHS%E6*RHS%R
      RES%E7 = LHS%R*RHS%E7 + LHS%E7*RHS%R
      RES%E8 = LHS%R*RHS%E8 + LHS%E8*RHS%R
      RES%E9 = LHS%R*RHS%E9 + LHS%E9*RHS%R
      RES%EA = LHS%R*RHS%EA + LHS%EA*RHS%R
      RES%EB = LHS%R*RHS%EB + LHS%EB*RHS%R
      RES%EC = LHS%R*RHS%EC + LHS%EC*RHS%R
      RES%ED = LHS%R*RHS%ED + LHS%ED*RHS%R
      RES%EE = LHS%R*RHS%EE + LHS%EE*RHS%R
      RES%EF = LHS%R*RHS%EF + LHS%EF*RHS%R
      RES%EG = LHS%R*RHS%EG + LHS%EG*RHS%R
      RES%EH = LHS%R*RHS%EH + LHS%EH*RHS%R
      RES%EI = LHS%R*RHS%EI + LHS%EI*RHS%R
      RES%EJ = LHS%R*RHS%EJ + LHS%EJ*RHS%R
      RES%EK = LHS%R*RHS%EK + LHS%EK*RHS%R
      RES%EL = LHS%R*RHS%EL + LHS%EL*RHS%R
      RES%EM = LHS%R*RHS%EM + LHS%EM*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION DONUMM22N2_MUL_OO_SV

   FUNCTION DONUMM22N2_MUL_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1)) 

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
      RES%E8 = LHS*RHS%E8
      RES%E9 = LHS*RHS%E9
      RES%EA = LHS*RHS%EA
      RES%EB = LHS*RHS%EB
      RES%EC = LHS*RHS%EC
      RES%ED = LHS*RHS%ED
      RES%EE = LHS*RHS%EE
      RES%EF = LHS*RHS%EF
      RES%EG = LHS*RHS%EG
      RES%EH = LHS*RHS%EH
      RES%EI = LHS*RHS%EI
      RES%EJ = LHS*RHS%EJ
      RES%EK = LHS*RHS%EK
      RES%EL = LHS*RHS%EL
      RES%EM = LHS*RHS%EM

      ! Order 2
      RES%E11 = LHS*RHS%E11
      RES%E22 = LHS*RHS%E22
      RES%E33 = LHS*RHS%E33
      RES%E44 = LHS*RHS%E44
      RES%E55 = LHS*RHS%E55
      RES%E66 = LHS*RHS%E66
      RES%E77 = LHS*RHS%E77
      RES%E88 = LHS*RHS%E88
      RES%E99 = LHS*RHS%E99
      RES%EAA = LHS*RHS%EAA
      RES%EBB = LHS*RHS%EBB
      RES%ECC = LHS*RHS%ECC
      RES%EDD = LHS*RHS%EDD
      RES%EEE = LHS*RHS%EEE
      RES%EFF = LHS*RHS%EFF
      RES%EGG = LHS*RHS%EGG
      RES%EHH = LHS*RHS%EHH
      RES%EII = LHS*RHS%EII
      RES%EJJ = LHS*RHS%EJJ
      RES%EKK = LHS*RHS%EKK
      RES%ELL = LHS*RHS%ELL
      RES%EMM = LHS*RHS%EMM

   END FUNCTION DONUMM22N2_MUL_RO_SV

   FUNCTION DONUMM22N2_MUL_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1)) 

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
      RES%E8 = LHS%E8*RHS
      RES%E9 = LHS%E9*RHS
      RES%EA = LHS%EA*RHS
      RES%EB = LHS%EB*RHS
      RES%EC = LHS%EC*RHS
      RES%ED = LHS%ED*RHS
      RES%EE = LHS%EE*RHS
      RES%EF = LHS%EF*RHS
      RES%EG = LHS%EG*RHS
      RES%EH = LHS%EH*RHS
      RES%EI = LHS%EI*RHS
      RES%EJ = LHS%EJ*RHS
      RES%EK = LHS%EK*RHS
      RES%EL = LHS%EL*RHS
      RES%EM = LHS%EM*RHS

      ! Order 2
      RES%E11 = LHS%E11*RHS
      RES%E22 = LHS%E22*RHS
      RES%E33 = LHS%E33*RHS
      RES%E44 = LHS%E44*RHS
      RES%E55 = LHS%E55*RHS
      RES%E66 = LHS%E66*RHS
      RES%E77 = LHS%E77*RHS
      RES%E88 = LHS%E88*RHS
      RES%E99 = LHS%E99*RHS
      RES%EAA = LHS%EAA*RHS
      RES%EBB = LHS%EBB*RHS
      RES%ECC = LHS%ECC*RHS
      RES%EDD = LHS%EDD*RHS
      RES%EEE = LHS%EEE*RHS
      RES%EFF = LHS%EFF*RHS
      RES%EGG = LHS%EGG*RHS
      RES%EHH = LHS%EHH*RHS
      RES%EII = LHS%EII*RHS
      RES%EJJ = LHS%EJJ*RHS
      RES%EKK = LHS%EKK*RHS
      RES%ELL = LHS%ELL*RHS
      RES%EMM = LHS%EMM*RHS

   END FUNCTION DONUMM22N2_MUL_OR_SV

   FUNCTION DONUMM22N2_ADD_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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
      RES%E8 = LHS%E8 + RHS%E8
      RES%E9 = LHS%E9 + RHS%E9
      RES%EA = LHS%EA + RHS%EA
      RES%EB = LHS%EB + RHS%EB
      RES%EC = LHS%EC + RHS%EC
      RES%ED = LHS%ED + RHS%ED
      RES%EE = LHS%EE + RHS%EE
      RES%EF = LHS%EF + RHS%EF
      RES%EG = LHS%EG + RHS%EG
      RES%EH = LHS%EH + RHS%EH
      RES%EI = LHS%EI + RHS%EI
      RES%EJ = LHS%EJ + RHS%EJ
      RES%EK = LHS%EK + RHS%EK
      RES%EL = LHS%EL + RHS%EL
      RES%EM = LHS%EM + RHS%EM

      ! Order 2
      RES%E11 = LHS%E11 + RHS%E11
      RES%E22 = LHS%E22 + RHS%E22
      RES%E33 = LHS%E33 + RHS%E33
      RES%E44 = LHS%E44 + RHS%E44
      RES%E55 = LHS%E55 + RHS%E55
      RES%E66 = LHS%E66 + RHS%E66
      RES%E77 = LHS%E77 + RHS%E77
      RES%E88 = LHS%E88 + RHS%E88
      RES%E99 = LHS%E99 + RHS%E99
      RES%EAA = LHS%EAA + RHS%EAA
      RES%EBB = LHS%EBB + RHS%EBB
      RES%ECC = LHS%ECC + RHS%ECC
      RES%EDD = LHS%EDD + RHS%EDD
      RES%EEE = LHS%EEE + RHS%EEE
      RES%EFF = LHS%EFF + RHS%EFF
      RES%EGG = LHS%EGG + RHS%EGG
      RES%EHH = LHS%EHH + RHS%EHH
      RES%EII = LHS%EII + RHS%EII
      RES%EJJ = LHS%EJJ + RHS%EJJ
      RES%EKK = LHS%EKK + RHS%EKK
      RES%ELL = LHS%ELL + RHS%ELL
      RES%EMM = LHS%EMM + RHS%EMM

   END FUNCTION DONUMM22N2_ADD_OO_SM

   FUNCTION DONUMM22N2_ADD_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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
      RES%E8 =  + RHS%E8
      RES%E9 =  + RHS%E9
      RES%EA =  + RHS%EA
      RES%EB =  + RHS%EB
      RES%EC =  + RHS%EC
      RES%ED =  + RHS%ED
      RES%EE =  + RHS%EE
      RES%EF =  + RHS%EF
      RES%EG =  + RHS%EG
      RES%EH =  + RHS%EH
      RES%EI =  + RHS%EI
      RES%EJ =  + RHS%EJ
      RES%EK =  + RHS%EK
      RES%EL =  + RHS%EL
      RES%EM =  + RHS%EM

      ! Order 2
      RES%E11 =  + RHS%E11
      RES%E22 =  + RHS%E22
      RES%E33 =  + RHS%E33
      RES%E44 =  + RHS%E44
      RES%E55 =  + RHS%E55
      RES%E66 =  + RHS%E66
      RES%E77 =  + RHS%E77
      RES%E88 =  + RHS%E88
      RES%E99 =  + RHS%E99
      RES%EAA =  + RHS%EAA
      RES%EBB =  + RHS%EBB
      RES%ECC =  + RHS%ECC
      RES%EDD =  + RHS%EDD
      RES%EEE =  + RHS%EEE
      RES%EFF =  + RHS%EFF
      RES%EGG =  + RHS%EGG
      RES%EHH =  + RHS%EHH
      RES%EII =  + RHS%EII
      RES%EJJ =  + RHS%EJJ
      RES%EKK =  + RHS%EKK
      RES%ELL =  + RHS%ELL
      RES%EMM =  + RHS%EMM

   END FUNCTION DONUMM22N2_ADD_RO_SM

   FUNCTION DONUMM22N2_ADD_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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
      RES%E8 = LHS%E8
      RES%E9 = LHS%E9
      RES%EA = LHS%EA
      RES%EB = LHS%EB
      RES%EC = LHS%EC
      RES%ED = LHS%ED
      RES%EE = LHS%EE
      RES%EF = LHS%EF
      RES%EG = LHS%EG
      RES%EH = LHS%EH
      RES%EI = LHS%EI
      RES%EJ = LHS%EJ
      RES%EK = LHS%EK
      RES%EL = LHS%EL
      RES%EM = LHS%EM

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77
      RES%E88 = LHS%E88
      RES%E99 = LHS%E99
      RES%EAA = LHS%EAA
      RES%EBB = LHS%EBB
      RES%ECC = LHS%ECC
      RES%EDD = LHS%EDD
      RES%EEE = LHS%EEE
      RES%EFF = LHS%EFF
      RES%EGG = LHS%EGG
      RES%EHH = LHS%EHH
      RES%EII = LHS%EII
      RES%EJJ = LHS%EJJ
      RES%EKK = LHS%EKK
      RES%ELL = LHS%ELL
      RES%EMM = LHS%EMM

   END FUNCTION DONUMM22N2_ADD_OR_SM

   FUNCTION DONUMM22N2_SUB_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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
      RES%E8 = LHS%E8 - RHS%E8
      RES%E9 = LHS%E9 - RHS%E9
      RES%EA = LHS%EA - RHS%EA
      RES%EB = LHS%EB - RHS%EB
      RES%EC = LHS%EC - RHS%EC
      RES%ED = LHS%ED - RHS%ED
      RES%EE = LHS%EE - RHS%EE
      RES%EF = LHS%EF - RHS%EF
      RES%EG = LHS%EG - RHS%EG
      RES%EH = LHS%EH - RHS%EH
      RES%EI = LHS%EI - RHS%EI
      RES%EJ = LHS%EJ - RHS%EJ
      RES%EK = LHS%EK - RHS%EK
      RES%EL = LHS%EL - RHS%EL
      RES%EM = LHS%EM - RHS%EM

      ! Order 2
      RES%E11 = LHS%E11 - RHS%E11
      RES%E22 = LHS%E22 - RHS%E22
      RES%E33 = LHS%E33 - RHS%E33
      RES%E44 = LHS%E44 - RHS%E44
      RES%E55 = LHS%E55 - RHS%E55
      RES%E66 = LHS%E66 - RHS%E66
      RES%E77 = LHS%E77 - RHS%E77
      RES%E88 = LHS%E88 - RHS%E88
      RES%E99 = LHS%E99 - RHS%E99
      RES%EAA = LHS%EAA - RHS%EAA
      RES%EBB = LHS%EBB - RHS%EBB
      RES%ECC = LHS%ECC - RHS%ECC
      RES%EDD = LHS%EDD - RHS%EDD
      RES%EEE = LHS%EEE - RHS%EEE
      RES%EFF = LHS%EFF - RHS%EFF
      RES%EGG = LHS%EGG - RHS%EGG
      RES%EHH = LHS%EHH - RHS%EHH
      RES%EII = LHS%EII - RHS%EII
      RES%EJJ = LHS%EJJ - RHS%EJJ
      RES%EKK = LHS%EKK - RHS%EKK
      RES%ELL = LHS%ELL - RHS%ELL
      RES%EMM = LHS%EMM - RHS%EMM

   END FUNCTION DONUMM22N2_SUB_OO_SM

   FUNCTION DONUMM22N2_SUB_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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
      RES%E8 =  - RHS%E8
      RES%E9 =  - RHS%E9
      RES%EA =  - RHS%EA
      RES%EB =  - RHS%EB
      RES%EC =  - RHS%EC
      RES%ED =  - RHS%ED
      RES%EE =  - RHS%EE
      RES%EF =  - RHS%EF
      RES%EG =  - RHS%EG
      RES%EH =  - RHS%EH
      RES%EI =  - RHS%EI
      RES%EJ =  - RHS%EJ
      RES%EK =  - RHS%EK
      RES%EL =  - RHS%EL
      RES%EM =  - RHS%EM

      ! Order 2
      RES%E11 =  - RHS%E11
      RES%E22 =  - RHS%E22
      RES%E33 =  - RHS%E33
      RES%E44 =  - RHS%E44
      RES%E55 =  - RHS%E55
      RES%E66 =  - RHS%E66
      RES%E77 =  - RHS%E77
      RES%E88 =  - RHS%E88
      RES%E99 =  - RHS%E99
      RES%EAA =  - RHS%EAA
      RES%EBB =  - RHS%EBB
      RES%ECC =  - RHS%ECC
      RES%EDD =  - RHS%EDD
      RES%EEE =  - RHS%EEE
      RES%EFF =  - RHS%EFF
      RES%EGG =  - RHS%EGG
      RES%EHH =  - RHS%EHH
      RES%EII =  - RHS%EII
      RES%EJJ =  - RHS%EJJ
      RES%EKK =  - RHS%EKK
      RES%ELL =  - RHS%ELL
      RES%EMM =  - RHS%EMM

   END FUNCTION DONUMM22N2_SUB_RO_SM

   FUNCTION DONUMM22N2_SUB_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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
      RES%E8 = LHS%E8
      RES%E9 = LHS%E9
      RES%EA = LHS%EA
      RES%EB = LHS%EB
      RES%EC = LHS%EC
      RES%ED = LHS%ED
      RES%EE = LHS%EE
      RES%EF = LHS%EF
      RES%EG = LHS%EG
      RES%EH = LHS%EH
      RES%EI = LHS%EI
      RES%EJ = LHS%EJ
      RES%EK = LHS%EK
      RES%EL = LHS%EL
      RES%EM = LHS%EM

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77
      RES%E88 = LHS%E88
      RES%E99 = LHS%E99
      RES%EAA = LHS%EAA
      RES%EBB = LHS%EBB
      RES%ECC = LHS%ECC
      RES%EDD = LHS%EDD
      RES%EEE = LHS%EEE
      RES%EFF = LHS%EFF
      RES%EGG = LHS%EGG
      RES%EHH = LHS%EHH
      RES%EII = LHS%EII
      RES%EJJ = LHS%EJJ
      RES%EKK = LHS%EKK
      RES%ELL = LHS%ELL
      RES%EMM = LHS%EMM

   END FUNCTION DONUMM22N2_SUB_OR_SM

   FUNCTION DONUMM22N2_MUL_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      RES%E22 = LHS%R*RHS%E22 + LHS%E22*RHS%R + LHS%E2*RHS%E2
      RES%E33 = LHS%R*RHS%E33 + LHS%E33*RHS%R + LHS%E3*RHS%E3
      RES%E44 = LHS%R*RHS%E44 + LHS%E44*RHS%R + LHS%E4*RHS%E4
      RES%E55 = LHS%R*RHS%E55 + LHS%E55*RHS%R + LHS%E5*RHS%E5
      RES%E66 = LHS%R*RHS%E66 + LHS%E66*RHS%R + LHS%E6*RHS%E6
      RES%E77 = LHS%R*RHS%E77 + LHS%E77*RHS%R + LHS%E7*RHS%E7
      RES%E88 = LHS%R*RHS%E88 + LHS%E88*RHS%R + LHS%E8*RHS%E8
      RES%E99 = LHS%R*RHS%E99 + LHS%E99*RHS%R + LHS%E9*RHS%E9
      RES%EAA = LHS%R*RHS%EAA + LHS%EAA*RHS%R + LHS%EA*RHS%EA
      RES%EBB = LHS%R*RHS%EBB + LHS%EBB*RHS%R + LHS%EB*RHS%EB
      RES%ECC = LHS%R*RHS%ECC + LHS%ECC*RHS%R + LHS%EC*RHS%EC
      RES%EDD = LHS%R*RHS%EDD + LHS%EDD*RHS%R + LHS%ED*RHS%ED
      RES%EEE = LHS%R*RHS%EEE + LHS%EEE*RHS%R + LHS%EE*RHS%EE
      RES%EFF = LHS%R*RHS%EFF + LHS%EFF*RHS%R + LHS%EF*RHS%EF
      RES%EGG = LHS%R*RHS%EGG + LHS%EGG*RHS%R + LHS%EG*RHS%EG
      RES%EHH = LHS%R*RHS%EHH + LHS%EHH*RHS%R + LHS%EH*RHS%EH
      RES%EII = LHS%R*RHS%EII + LHS%EII*RHS%R + LHS%EI*RHS%EI
      RES%EJJ = LHS%R*RHS%EJJ + LHS%EJJ*RHS%R + LHS%EJ*RHS%EJ
      RES%EKK = LHS%R*RHS%EKK + LHS%EKK*RHS%R + LHS%EK*RHS%EK
      RES%ELL = LHS%R*RHS%ELL + LHS%ELL*RHS%R + LHS%EL*RHS%EL
      RES%EMM = LHS%R*RHS%EMM + LHS%EMM*RHS%R + LHS%EM*RHS%EM
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      RES%E3 = LHS%R*RHS%E3 + LHS%E3*RHS%R
      RES%E4 = LHS%R*RHS%E4 + LHS%E4*RHS%R
      RES%E5 = LHS%R*RHS%E5 + LHS%E5*RHS%R
      RES%E6 = LHS%R*RHS%E6 + LHS%E6*RHS%R
      RES%E7 = LHS%R*RHS%E7 + LHS%E7*RHS%R
      RES%E8 = LHS%R*RHS%E8 + LHS%E8*RHS%R
      RES%E9 = LHS%R*RHS%E9 + LHS%E9*RHS%R
      RES%EA = LHS%R*RHS%EA + LHS%EA*RHS%R
      RES%EB = LHS%R*RHS%EB + LHS%EB*RHS%R
      RES%EC = LHS%R*RHS%EC + LHS%EC*RHS%R
      RES%ED = LHS%R*RHS%ED + LHS%ED*RHS%R
      RES%EE = LHS%R*RHS%EE + LHS%EE*RHS%R
      RES%EF = LHS%R*RHS%EF + LHS%EF*RHS%R
      RES%EG = LHS%R*RHS%EG + LHS%EG*RHS%R
      RES%EH = LHS%R*RHS%EH + LHS%EH*RHS%R
      RES%EI = LHS%R*RHS%EI + LHS%EI*RHS%R
      RES%EJ = LHS%R*RHS%EJ + LHS%EJ*RHS%R
      RES%EK = LHS%R*RHS%EK + LHS%EK*RHS%R
      RES%EL = LHS%R*RHS%EL + LHS%EL*RHS%R
      RES%EM = LHS%R*RHS%EM + LHS%EM*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION DONUMM22N2_MUL_OO_SM

   FUNCTION DONUMM22N2_MUL_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N2), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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
      RES%E8 = LHS*RHS%E8
      RES%E9 = LHS*RHS%E9
      RES%EA = LHS*RHS%EA
      RES%EB = LHS*RHS%EB
      RES%EC = LHS*RHS%EC
      RES%ED = LHS*RHS%ED
      RES%EE = LHS*RHS%EE
      RES%EF = LHS*RHS%EF
      RES%EG = LHS*RHS%EG
      RES%EH = LHS*RHS%EH
      RES%EI = LHS*RHS%EI
      RES%EJ = LHS*RHS%EJ
      RES%EK = LHS*RHS%EK
      RES%EL = LHS*RHS%EL
      RES%EM = LHS*RHS%EM

      ! Order 2
      RES%E11 = LHS*RHS%E11
      RES%E22 = LHS*RHS%E22
      RES%E33 = LHS*RHS%E33
      RES%E44 = LHS*RHS%E44
      RES%E55 = LHS*RHS%E55
      RES%E66 = LHS*RHS%E66
      RES%E77 = LHS*RHS%E77
      RES%E88 = LHS*RHS%E88
      RES%E99 = LHS*RHS%E99
      RES%EAA = LHS*RHS%EAA
      RES%EBB = LHS*RHS%EBB
      RES%ECC = LHS*RHS%ECC
      RES%EDD = LHS*RHS%EDD
      RES%EEE = LHS*RHS%EEE
      RES%EFF = LHS*RHS%EFF
      RES%EGG = LHS*RHS%EGG
      RES%EHH = LHS*RHS%EHH
      RES%EII = LHS*RHS%EII
      RES%EJJ = LHS*RHS%EJJ
      RES%EKK = LHS*RHS%EKK
      RES%ELL = LHS*RHS%ELL
      RES%EMM = LHS*RHS%EMM

   END FUNCTION DONUMM22N2_MUL_RO_SM

   FUNCTION DONUMM22N2_MUL_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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
      RES%E8 = LHS%E8*RHS
      RES%E9 = LHS%E9*RHS
      RES%EA = LHS%EA*RHS
      RES%EB = LHS%EB*RHS
      RES%EC = LHS%EC*RHS
      RES%ED = LHS%ED*RHS
      RES%EE = LHS%EE*RHS
      RES%EF = LHS%EF*RHS
      RES%EG = LHS%EG*RHS
      RES%EH = LHS%EH*RHS
      RES%EI = LHS%EI*RHS
      RES%EJ = LHS%EJ*RHS
      RES%EK = LHS%EK*RHS
      RES%EL = LHS%EL*RHS
      RES%EM = LHS%EM*RHS

      ! Order 2
      RES%E11 = LHS%E11*RHS
      RES%E22 = LHS%E22*RHS
      RES%E33 = LHS%E33*RHS
      RES%E44 = LHS%E44*RHS
      RES%E55 = LHS%E55*RHS
      RES%E66 = LHS%E66*RHS
      RES%E77 = LHS%E77*RHS
      RES%E88 = LHS%E88*RHS
      RES%E99 = LHS%E99*RHS
      RES%EAA = LHS%EAA*RHS
      RES%EBB = LHS%EBB*RHS
      RES%ECC = LHS%ECC*RHS
      RES%EDD = LHS%EDD*RHS
      RES%EEE = LHS%EEE*RHS
      RES%EFF = LHS%EFF*RHS
      RES%EGG = LHS%EGG*RHS
      RES%EHH = LHS%EHH*RHS
      RES%EII = LHS%EII*RHS
      RES%EJJ = LHS%EJJ*RHS
      RES%EKK = LHS%EKK*RHS
      RES%ELL = LHS%ELL*RHS
      RES%EMM = LHS%EMM*RHS

   END FUNCTION DONUMM22N2_MUL_OR_SM

ELEMENTAL    FUNCTION DONUMM22N2_GEM_OOO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: A 
      TYPE(DONUMM22N2), INTENT(IN) :: B 
      TYPE(DONUMM22N2), INTENT(IN) :: C 
      TYPE(DONUMM22N2) :: RES 

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
      RES%E8 = C%E8 + A%R*B%E8 + A%E8*B%R
      RES%E9 = C%E9 + A%R*B%E9 + A%E9*B%R
      RES%EA = C%EA + A%R*B%EA + A%EA*B%R
      RES%EB = C%EB + A%R*B%EB + A%EB*B%R
      RES%EC = C%EC + A%R*B%EC + A%EC*B%R
      RES%ED = C%ED + A%R*B%ED + A%ED*B%R
      RES%EE = C%EE + A%R*B%EE + A%EE*B%R
      RES%EF = C%EF + A%R*B%EF + A%EF*B%R
      RES%EG = C%EG + A%R*B%EG + A%EG*B%R
      RES%EH = C%EH + A%R*B%EH + A%EH*B%R
      RES%EI = C%EI + A%R*B%EI + A%EI*B%R
      RES%EJ = C%EJ + A%R*B%EJ + A%EJ*B%R
      RES%EK = C%EK + A%R*B%EK + A%EK*B%R
      RES%EL = C%EL + A%R*B%EL + A%EL*B%R
      RES%EM = C%EM + A%R*B%EM + A%EM*B%R

      ! Order 2
      RES%E11 = C%E11 + A%R*B%E11 + A%E11*B%R + A%E1*B%E1
      RES%E22 = C%E22 + A%R*B%E22 + A%E22*B%R + A%E2*B%E2
      RES%E33 = C%E33 + A%R*B%E33 + A%E33*B%R + A%E3*B%E3
      RES%E44 = C%E44 + A%R*B%E44 + A%E44*B%R + A%E4*B%E4
      RES%E55 = C%E55 + A%R*B%E55 + A%E55*B%R + A%E5*B%E5
      RES%E66 = C%E66 + A%R*B%E66 + A%E66*B%R + A%E6*B%E6
      RES%E77 = C%E77 + A%R*B%E77 + A%E77*B%R + A%E7*B%E7
      RES%E88 = C%E88 + A%R*B%E88 + A%E88*B%R + A%E8*B%E8
      RES%E99 = C%E99 + A%R*B%E99 + A%E99*B%R + A%E9*B%E9
      RES%EAA = C%EAA + A%R*B%EAA + A%EAA*B%R + A%EA*B%EA
      RES%EBB = C%EBB + A%R*B%EBB + A%EBB*B%R + A%EB*B%EB
      RES%ECC = C%ECC + A%R*B%ECC + A%ECC*B%R + A%EC*B%EC
      RES%EDD = C%EDD + A%R*B%EDD + A%EDD*B%R + A%ED*B%ED
      RES%EEE = C%EEE + A%R*B%EEE + A%EEE*B%R + A%EE*B%EE
      RES%EFF = C%EFF + A%R*B%EFF + A%EFF*B%R + A%EF*B%EF
      RES%EGG = C%EGG + A%R*B%EGG + A%EGG*B%R + A%EG*B%EG
      RES%EHH = C%EHH + A%R*B%EHH + A%EHH*B%R + A%EH*B%EH
      RES%EII = C%EII + A%R*B%EII + A%EII*B%R + A%EI*B%EI
      RES%EJJ = C%EJJ + A%R*B%EJJ + A%EJJ*B%R + A%EJ*B%EJ
      RES%EKK = C%EKK + A%R*B%EKK + A%EKK*B%R + A%EK*B%EK
      RES%ELL = C%ELL + A%R*B%ELL + A%ELL*B%R + A%EL*B%EL
      RES%EMM = C%EMM + A%R*B%EMM + A%EMM*B%R + A%EM*B%EM

   END FUNCTION DONUMM22N2_GEM_OOO

ELEMENTAL    FUNCTION DONUMM22N2_GEM_ROO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: A 
      TYPE(DONUMM22N2), INTENT(IN) :: B 
      TYPE(DONUMM22N2), INTENT(IN) :: C 
      TYPE(DONUMM22N2) :: RES 

      !  General multiplication like function 'A*B + C'
      ! Order 2
      RES%E11 = C%E11 + A*B%E11
      RES%E22 = C%E22 + A*B%E22
      RES%E33 = C%E33 + A*B%E33
      RES%E44 = C%E44 + A*B%E44
      RES%E55 = C%E55 + A*B%E55
      RES%E66 = C%E66 + A*B%E66
      RES%E77 = C%E77 + A*B%E77
      RES%E88 = C%E88 + A*B%E88
      RES%E99 = C%E99 + A*B%E99
      RES%EAA = C%EAA + A*B%EAA
      RES%EBB = C%EBB + A*B%EBB
      RES%ECC = C%ECC + A*B%ECC
      RES%EDD = C%EDD + A*B%EDD
      RES%EEE = C%EEE + A*B%EEE
      RES%EFF = C%EFF + A*B%EFF
      RES%EGG = C%EGG + A*B%EGG
      RES%EHH = C%EHH + A*B%EHH
      RES%EII = C%EII + A*B%EII
      RES%EJJ = C%EJJ + A*B%EJJ
      RES%EKK = C%EKK + A*B%EKK
      RES%ELL = C%ELL + A*B%ELL
      RES%EMM = C%EMM + A*B%EMM
      ! Order 1
      RES%E1 = C%E1 + A*B%E1
      RES%E2 = C%E2 + A*B%E2
      RES%E3 = C%E3 + A*B%E3
      RES%E4 = C%E4 + A*B%E4
      RES%E5 = C%E5 + A*B%E5
      RES%E6 = C%E6 + A*B%E6
      RES%E7 = C%E7 + A*B%E7
      RES%E8 = C%E8 + A*B%E8
      RES%E9 = C%E9 + A*B%E9
      RES%EA = C%EA + A*B%EA
      RES%EB = C%EB + A*B%EB
      RES%EC = C%EC + A*B%EC
      RES%ED = C%ED + A*B%ED
      RES%EE = C%EE + A*B%EE
      RES%EF = C%EF + A*B%EF
      RES%EG = C%EG + A*B%EG
      RES%EH = C%EH + A*B%EH
      RES%EI = C%EI + A*B%EI
      RES%EJ = C%EJ + A*B%EJ
      RES%EK = C%EK + A*B%EK
      RES%EL = C%EL + A*B%EL
      RES%EM = C%EM + A*B%EM
      ! Order 0
      RES%R = C%R + A*B%R

   END FUNCTION DONUMM22N2_GEM_ROO

ELEMENTAL    FUNCTION DONUMM22N2_GEM_ORO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: A 
      REAL(DP), INTENT(IN) :: B 
      TYPE(DONUMM22N2), INTENT(IN) :: C 
      TYPE(DONUMM22N2) :: RES 

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
      RES%E8 = C%E8 + A%E8*B
      RES%E9 = C%E9 + A%E9*B
      RES%EA = C%EA + A%EA*B
      RES%EB = C%EB + A%EB*B
      RES%EC = C%EC + A%EC*B
      RES%ED = C%ED + A%ED*B
      RES%EE = C%EE + A%EE*B
      RES%EF = C%EF + A%EF*B
      RES%EG = C%EG + A%EG*B
      RES%EH = C%EH + A%EH*B
      RES%EI = C%EI + A%EI*B
      RES%EJ = C%EJ + A%EJ*B
      RES%EK = C%EK + A%EK*B
      RES%EL = C%EL + A%EL*B
      RES%EM = C%EM + A%EM*B

      ! Order 2
      RES%E11 = C%E11 + A%E11*B
      RES%E22 = C%E22 + A%E22*B
      RES%E33 = C%E33 + A%E33*B
      RES%E44 = C%E44 + A%E44*B
      RES%E55 = C%E55 + A%E55*B
      RES%E66 = C%E66 + A%E66*B
      RES%E77 = C%E77 + A%E77*B
      RES%E88 = C%E88 + A%E88*B
      RES%E99 = C%E99 + A%E99*B
      RES%EAA = C%EAA + A%EAA*B
      RES%EBB = C%EBB + A%EBB*B
      RES%ECC = C%ECC + A%ECC*B
      RES%EDD = C%EDD + A%EDD*B
      RES%EEE = C%EEE + A%EEE*B
      RES%EFF = C%EFF + A%EFF*B
      RES%EGG = C%EGG + A%EGG*B
      RES%EHH = C%EHH + A%EHH*B
      RES%EII = C%EII + A%EII*B
      RES%EJJ = C%EJJ + A%EJJ*B
      RES%EKK = C%EKK + A%EKK*B
      RES%ELL = C%ELL + A%ELL*B
      RES%EMM = C%EMM + A%EMM*B

   END FUNCTION DONUMM22N2_GEM_ORO

   FUNCTION DONUMM22N2_MATMUL_DONUMM22N2(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N2), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      !  Multiplication like function 'MATMUL(lhs,rhs)'
      ! Order 2
      res%E11 = MATMUL(lhs%R,rhs%E11) + MATMUL(lhs%E11,rhs%R) + MATMUL(lhs%E1,rhs%E1)
      res%E22 = MATMUL(lhs%R,rhs%E22) + MATMUL(lhs%E22,rhs%R) + MATMUL(lhs%E2,rhs%E2)
      res%E33 = MATMUL(lhs%R,rhs%E33) + MATMUL(lhs%E33,rhs%R) + MATMUL(lhs%E3,rhs%E3)
      res%E44 = MATMUL(lhs%R,rhs%E44) + MATMUL(lhs%E44,rhs%R) + MATMUL(lhs%E4,rhs%E4)
      res%E55 = MATMUL(lhs%R,rhs%E55) + MATMUL(lhs%E55,rhs%R) + MATMUL(lhs%E5,rhs%E5)
      res%E66 = MATMUL(lhs%R,rhs%E66) + MATMUL(lhs%E66,rhs%R) + MATMUL(lhs%E6,rhs%E6)
      res%E77 = MATMUL(lhs%R,rhs%E77) + MATMUL(lhs%E77,rhs%R) + MATMUL(lhs%E7,rhs%E7)
      res%E88 = MATMUL(lhs%R,rhs%E88) + MATMUL(lhs%E88,rhs%R) + MATMUL(lhs%E8,rhs%E8)
      res%E99 = MATMUL(lhs%R,rhs%E99) + MATMUL(lhs%E99,rhs%R) + MATMUL(lhs%E9,rhs%E9)
      res%EAA = MATMUL(lhs%R,rhs%EAA) + MATMUL(lhs%EAA,rhs%R) + MATMUL(lhs%EA,rhs%EA)
      res%EBB = MATMUL(lhs%R,rhs%EBB) + MATMUL(lhs%EBB,rhs%R) + MATMUL(lhs%EB,rhs%EB)
      res%ECC = MATMUL(lhs%R,rhs%ECC) + MATMUL(lhs%ECC,rhs%R) + MATMUL(lhs%EC,rhs%EC)
      res%EDD = MATMUL(lhs%R,rhs%EDD) + MATMUL(lhs%EDD,rhs%R) + MATMUL(lhs%ED,rhs%ED)
      res%EEE = MATMUL(lhs%R,rhs%EEE) + MATMUL(lhs%EEE,rhs%R) + MATMUL(lhs%EE,rhs%EE)
      res%EFF = MATMUL(lhs%R,rhs%EFF) + MATMUL(lhs%EFF,rhs%R) + MATMUL(lhs%EF,rhs%EF)
      res%EGG = MATMUL(lhs%R,rhs%EGG) + MATMUL(lhs%EGG,rhs%R) + MATMUL(lhs%EG,rhs%EG)
      res%EHH = MATMUL(lhs%R,rhs%EHH) + MATMUL(lhs%EHH,rhs%R) + MATMUL(lhs%EH,rhs%EH)
      res%EII = MATMUL(lhs%R,rhs%EII) + MATMUL(lhs%EII,rhs%R) + MATMUL(lhs%EI,rhs%EI)
      res%EJJ = MATMUL(lhs%R,rhs%EJJ) + MATMUL(lhs%EJJ,rhs%R) + MATMUL(lhs%EJ,rhs%EJ)
      res%EKK = MATMUL(lhs%R,rhs%EKK) + MATMUL(lhs%EKK,rhs%R) + MATMUL(lhs%EK,rhs%EK)
      res%ELL = MATMUL(lhs%R,rhs%ELL) + MATMUL(lhs%ELL,rhs%R) + MATMUL(lhs%EL,rhs%EL)
      res%EMM = MATMUL(lhs%R,rhs%EMM) + MATMUL(lhs%EMM,rhs%R) + MATMUL(lhs%EM,rhs%EM)
      ! Order 1
      res%E1 = MATMUL(lhs%R,rhs%E1) + MATMUL(lhs%E1,rhs%R)
      res%E2 = MATMUL(lhs%R,rhs%E2) + MATMUL(lhs%E2,rhs%R)
      res%E3 = MATMUL(lhs%R,rhs%E3) + MATMUL(lhs%E3,rhs%R)
      res%E4 = MATMUL(lhs%R,rhs%E4) + MATMUL(lhs%E4,rhs%R)
      res%E5 = MATMUL(lhs%R,rhs%E5) + MATMUL(lhs%E5,rhs%R)
      res%E6 = MATMUL(lhs%R,rhs%E6) + MATMUL(lhs%E6,rhs%R)
      res%E7 = MATMUL(lhs%R,rhs%E7) + MATMUL(lhs%E7,rhs%R)
      res%E8 = MATMUL(lhs%R,rhs%E8) + MATMUL(lhs%E8,rhs%R)
      res%E9 = MATMUL(lhs%R,rhs%E9) + MATMUL(lhs%E9,rhs%R)
      res%EA = MATMUL(lhs%R,rhs%EA) + MATMUL(lhs%EA,rhs%R)
      res%EB = MATMUL(lhs%R,rhs%EB) + MATMUL(lhs%EB,rhs%R)
      res%EC = MATMUL(lhs%R,rhs%EC) + MATMUL(lhs%EC,rhs%R)
      res%ED = MATMUL(lhs%R,rhs%ED) + MATMUL(lhs%ED,rhs%R)
      res%EE = MATMUL(lhs%R,rhs%EE) + MATMUL(lhs%EE,rhs%R)
      res%EF = MATMUL(lhs%R,rhs%EF) + MATMUL(lhs%EF,rhs%R)
      res%EG = MATMUL(lhs%R,rhs%EG) + MATMUL(lhs%EG,rhs%R)
      res%EH = MATMUL(lhs%R,rhs%EH) + MATMUL(lhs%EH,rhs%R)
      res%EI = MATMUL(lhs%R,rhs%EI) + MATMUL(lhs%EI,rhs%R)
      res%EJ = MATMUL(lhs%R,rhs%EJ) + MATMUL(lhs%EJ,rhs%R)
      res%EK = MATMUL(lhs%R,rhs%EK) + MATMUL(lhs%EK,rhs%R)
      res%EL = MATMUL(lhs%R,rhs%EL) + MATMUL(lhs%EL,rhs%R)
      res%EM = MATMUL(lhs%R,rhs%EM) + MATMUL(lhs%EM,rhs%R)
      ! Order 0
      res%R = MATMUL(lhs%R,rhs%R)

   END FUNCTION DONUMM22N2_MATMUL_DONUMM22N2

   FUNCTION R_MATMUL_DONUMM22N2(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N2), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1),SIZE(RHS,2))

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
      res%E8 = MATMUL(lhs,rhs%E8)
      res%E9 = MATMUL(lhs,rhs%E9)
      res%EA = MATMUL(lhs,rhs%EA)
      res%EB = MATMUL(lhs,rhs%EB)
      res%EC = MATMUL(lhs,rhs%EC)
      res%ED = MATMUL(lhs,rhs%ED)
      res%EE = MATMUL(lhs,rhs%EE)
      res%EF = MATMUL(lhs,rhs%EF)
      res%EG = MATMUL(lhs,rhs%EG)
      res%EH = MATMUL(lhs,rhs%EH)
      res%EI = MATMUL(lhs,rhs%EI)
      res%EJ = MATMUL(lhs,rhs%EJ)
      res%EK = MATMUL(lhs,rhs%EK)
      res%EL = MATMUL(lhs,rhs%EL)
      res%EM = MATMUL(lhs,rhs%EM)

      ! Order 2
      res%E11 = MATMUL(lhs,rhs%E11)
      res%E22 = MATMUL(lhs,rhs%E22)
      res%E33 = MATMUL(lhs,rhs%E33)
      res%E44 = MATMUL(lhs,rhs%E44)
      res%E55 = MATMUL(lhs,rhs%E55)
      res%E66 = MATMUL(lhs,rhs%E66)
      res%E77 = MATMUL(lhs,rhs%E77)
      res%E88 = MATMUL(lhs,rhs%E88)
      res%E99 = MATMUL(lhs,rhs%E99)
      res%EAA = MATMUL(lhs,rhs%EAA)
      res%EBB = MATMUL(lhs,rhs%EBB)
      res%ECC = MATMUL(lhs,rhs%ECC)
      res%EDD = MATMUL(lhs,rhs%EDD)
      res%EEE = MATMUL(lhs,rhs%EEE)
      res%EFF = MATMUL(lhs,rhs%EFF)
      res%EGG = MATMUL(lhs,rhs%EGG)
      res%EHH = MATMUL(lhs,rhs%EHH)
      res%EII = MATMUL(lhs,rhs%EII)
      res%EJJ = MATMUL(lhs,rhs%EJJ)
      res%EKK = MATMUL(lhs,rhs%EKK)
      res%ELL = MATMUL(lhs,rhs%ELL)
      res%EMM = MATMUL(lhs,rhs%EMM)

   END FUNCTION R_MATMUL_DONUMM22N2

   FUNCTION DONUMM22N2_MATMUL_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N2) :: RES(SIZE(LHS,1),SIZE(RHS,2))

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
      res%E8 = MATMUL(lhs%E8,rhs)
      res%E9 = MATMUL(lhs%E9,rhs)
      res%EA = MATMUL(lhs%EA,rhs)
      res%EB = MATMUL(lhs%EB,rhs)
      res%EC = MATMUL(lhs%EC,rhs)
      res%ED = MATMUL(lhs%ED,rhs)
      res%EE = MATMUL(lhs%EE,rhs)
      res%EF = MATMUL(lhs%EF,rhs)
      res%EG = MATMUL(lhs%EG,rhs)
      res%EH = MATMUL(lhs%EH,rhs)
      res%EI = MATMUL(lhs%EI,rhs)
      res%EJ = MATMUL(lhs%EJ,rhs)
      res%EK = MATMUL(lhs%EK,rhs)
      res%EL = MATMUL(lhs%EL,rhs)
      res%EM = MATMUL(lhs%EM,rhs)

      ! Order 2
      res%E11 = MATMUL(lhs%E11,rhs)
      res%E22 = MATMUL(lhs%E22,rhs)
      res%E33 = MATMUL(lhs%E33,rhs)
      res%E44 = MATMUL(lhs%E44,rhs)
      res%E55 = MATMUL(lhs%E55,rhs)
      res%E66 = MATMUL(lhs%E66,rhs)
      res%E77 = MATMUL(lhs%E77,rhs)
      res%E88 = MATMUL(lhs%E88,rhs)
      res%E99 = MATMUL(lhs%E99,rhs)
      res%EAA = MATMUL(lhs%EAA,rhs)
      res%EBB = MATMUL(lhs%EBB,rhs)
      res%ECC = MATMUL(lhs%ECC,rhs)
      res%EDD = MATMUL(lhs%EDD,rhs)
      res%EEE = MATMUL(lhs%EEE,rhs)
      res%EFF = MATMUL(lhs%EFF,rhs)
      res%EGG = MATMUL(lhs%EGG,rhs)
      res%EHH = MATMUL(lhs%EHH,rhs)
      res%EII = MATMUL(lhs%EII,rhs)
      res%EJJ = MATMUL(lhs%EJJ,rhs)
      res%EKK = MATMUL(lhs%EKK,rhs)
      res%ELL = MATMUL(lhs%ELL,rhs)
      res%EMM = MATMUL(lhs%EMM,rhs)

   END FUNCTION DONUMM22N2_MATMUL_R

   FUNCTION DONUMM22N2_DOT_PRODUCT_DONUMM22N2(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:)
      TYPE(DONUMM22N2), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(DONUMM22N2) :: RES

      !  Multiplication like function 'DOT_PRODUCT(lhs,rhs)'
      ! Order 2
      res%E11 = DOT_PRODUCT(lhs%R,rhs%E11) + DOT_PRODUCT(lhs%E11,rhs%R) + DOT_PRODUCT(lhs%E1,rhs%E1)
      res%E22 = DOT_PRODUCT(lhs%R,rhs%E22) + DOT_PRODUCT(lhs%E22,rhs%R) + DOT_PRODUCT(lhs%E2,rhs%E2)
      res%E33 = DOT_PRODUCT(lhs%R,rhs%E33) + DOT_PRODUCT(lhs%E33,rhs%R) + DOT_PRODUCT(lhs%E3,rhs%E3)
      res%E44 = DOT_PRODUCT(lhs%R,rhs%E44) + DOT_PRODUCT(lhs%E44,rhs%R) + DOT_PRODUCT(lhs%E4,rhs%E4)
      res%E55 = DOT_PRODUCT(lhs%R,rhs%E55) + DOT_PRODUCT(lhs%E55,rhs%R) + DOT_PRODUCT(lhs%E5,rhs%E5)
      res%E66 = DOT_PRODUCT(lhs%R,rhs%E66) + DOT_PRODUCT(lhs%E66,rhs%R) + DOT_PRODUCT(lhs%E6,rhs%E6)
      res%E77 = DOT_PRODUCT(lhs%R,rhs%E77) + DOT_PRODUCT(lhs%E77,rhs%R) + DOT_PRODUCT(lhs%E7,rhs%E7)
      res%E88 = DOT_PRODUCT(lhs%R,rhs%E88) + DOT_PRODUCT(lhs%E88,rhs%R) + DOT_PRODUCT(lhs%E8,rhs%E8)
      res%E99 = DOT_PRODUCT(lhs%R,rhs%E99) + DOT_PRODUCT(lhs%E99,rhs%R) + DOT_PRODUCT(lhs%E9,rhs%E9)
      res%EAA = DOT_PRODUCT(lhs%R,rhs%EAA) + DOT_PRODUCT(lhs%EAA,rhs%R) + DOT_PRODUCT(lhs%EA,rhs%EA)
      res%EBB = DOT_PRODUCT(lhs%R,rhs%EBB) + DOT_PRODUCT(lhs%EBB,rhs%R) + DOT_PRODUCT(lhs%EB,rhs%EB)
      res%ECC = DOT_PRODUCT(lhs%R,rhs%ECC) + DOT_PRODUCT(lhs%ECC,rhs%R) + DOT_PRODUCT(lhs%EC,rhs%EC)
      res%EDD = DOT_PRODUCT(lhs%R,rhs%EDD) + DOT_PRODUCT(lhs%EDD,rhs%R) + DOT_PRODUCT(lhs%ED,rhs%ED)
      res%EEE = DOT_PRODUCT(lhs%R,rhs%EEE) + DOT_PRODUCT(lhs%EEE,rhs%R) + DOT_PRODUCT(lhs%EE,rhs%EE)
      res%EFF = DOT_PRODUCT(lhs%R,rhs%EFF) + DOT_PRODUCT(lhs%EFF,rhs%R) + DOT_PRODUCT(lhs%EF,rhs%EF)
      res%EGG = DOT_PRODUCT(lhs%R,rhs%EGG) + DOT_PRODUCT(lhs%EGG,rhs%R) + DOT_PRODUCT(lhs%EG,rhs%EG)
      res%EHH = DOT_PRODUCT(lhs%R,rhs%EHH) + DOT_PRODUCT(lhs%EHH,rhs%R) + DOT_PRODUCT(lhs%EH,rhs%EH)
      res%EII = DOT_PRODUCT(lhs%R,rhs%EII) + DOT_PRODUCT(lhs%EII,rhs%R) + DOT_PRODUCT(lhs%EI,rhs%EI)
      res%EJJ = DOT_PRODUCT(lhs%R,rhs%EJJ) + DOT_PRODUCT(lhs%EJJ,rhs%R) + DOT_PRODUCT(lhs%EJ,rhs%EJ)
      res%EKK = DOT_PRODUCT(lhs%R,rhs%EKK) + DOT_PRODUCT(lhs%EKK,rhs%R) + DOT_PRODUCT(lhs%EK,rhs%EK)
      res%ELL = DOT_PRODUCT(lhs%R,rhs%ELL) + DOT_PRODUCT(lhs%ELL,rhs%R) + DOT_PRODUCT(lhs%EL,rhs%EL)
      res%EMM = DOT_PRODUCT(lhs%R,rhs%EMM) + DOT_PRODUCT(lhs%EMM,rhs%R) + DOT_PRODUCT(lhs%EM,rhs%EM)
      ! Order 1
      res%E1 = DOT_PRODUCT(lhs%R,rhs%E1) + DOT_PRODUCT(lhs%E1,rhs%R)
      res%E2 = DOT_PRODUCT(lhs%R,rhs%E2) + DOT_PRODUCT(lhs%E2,rhs%R)
      res%E3 = DOT_PRODUCT(lhs%R,rhs%E3) + DOT_PRODUCT(lhs%E3,rhs%R)
      res%E4 = DOT_PRODUCT(lhs%R,rhs%E4) + DOT_PRODUCT(lhs%E4,rhs%R)
      res%E5 = DOT_PRODUCT(lhs%R,rhs%E5) + DOT_PRODUCT(lhs%E5,rhs%R)
      res%E6 = DOT_PRODUCT(lhs%R,rhs%E6) + DOT_PRODUCT(lhs%E6,rhs%R)
      res%E7 = DOT_PRODUCT(lhs%R,rhs%E7) + DOT_PRODUCT(lhs%E7,rhs%R)
      res%E8 = DOT_PRODUCT(lhs%R,rhs%E8) + DOT_PRODUCT(lhs%E8,rhs%R)
      res%E9 = DOT_PRODUCT(lhs%R,rhs%E9) + DOT_PRODUCT(lhs%E9,rhs%R)
      res%EA = DOT_PRODUCT(lhs%R,rhs%EA) + DOT_PRODUCT(lhs%EA,rhs%R)
      res%EB = DOT_PRODUCT(lhs%R,rhs%EB) + DOT_PRODUCT(lhs%EB,rhs%R)
      res%EC = DOT_PRODUCT(lhs%R,rhs%EC) + DOT_PRODUCT(lhs%EC,rhs%R)
      res%ED = DOT_PRODUCT(lhs%R,rhs%ED) + DOT_PRODUCT(lhs%ED,rhs%R)
      res%EE = DOT_PRODUCT(lhs%R,rhs%EE) + DOT_PRODUCT(lhs%EE,rhs%R)
      res%EF = DOT_PRODUCT(lhs%R,rhs%EF) + DOT_PRODUCT(lhs%EF,rhs%R)
      res%EG = DOT_PRODUCT(lhs%R,rhs%EG) + DOT_PRODUCT(lhs%EG,rhs%R)
      res%EH = DOT_PRODUCT(lhs%R,rhs%EH) + DOT_PRODUCT(lhs%EH,rhs%R)
      res%EI = DOT_PRODUCT(lhs%R,rhs%EI) + DOT_PRODUCT(lhs%EI,rhs%R)
      res%EJ = DOT_PRODUCT(lhs%R,rhs%EJ) + DOT_PRODUCT(lhs%EJ,rhs%R)
      res%EK = DOT_PRODUCT(lhs%R,rhs%EK) + DOT_PRODUCT(lhs%EK,rhs%R)
      res%EL = DOT_PRODUCT(lhs%R,rhs%EL) + DOT_PRODUCT(lhs%EL,rhs%R)
      res%EM = DOT_PRODUCT(lhs%R,rhs%EM) + DOT_PRODUCT(lhs%EM,rhs%R)
      ! Order 0
      res%R = DOT_PRODUCT(lhs%R,rhs%R)

   END FUNCTION DONUMM22N2_DOT_PRODUCT_DONUMM22N2

   FUNCTION R_DOT_PRODUCT_DONUMM22N2(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(DONUMM22N2), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(DONUMM22N2) :: RES

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
      res%E8 = DOT_PRODUCT(lhs,rhs%E8)
      res%E9 = DOT_PRODUCT(lhs,rhs%E9)
      res%EA = DOT_PRODUCT(lhs,rhs%EA)
      res%EB = DOT_PRODUCT(lhs,rhs%EB)
      res%EC = DOT_PRODUCT(lhs,rhs%EC)
      res%ED = DOT_PRODUCT(lhs,rhs%ED)
      res%EE = DOT_PRODUCT(lhs,rhs%EE)
      res%EF = DOT_PRODUCT(lhs,rhs%EF)
      res%EG = DOT_PRODUCT(lhs,rhs%EG)
      res%EH = DOT_PRODUCT(lhs,rhs%EH)
      res%EI = DOT_PRODUCT(lhs,rhs%EI)
      res%EJ = DOT_PRODUCT(lhs,rhs%EJ)
      res%EK = DOT_PRODUCT(lhs,rhs%EK)
      res%EL = DOT_PRODUCT(lhs,rhs%EL)
      res%EM = DOT_PRODUCT(lhs,rhs%EM)

      ! Order 2
      res%E11 = DOT_PRODUCT(lhs,rhs%E11)
      res%E22 = DOT_PRODUCT(lhs,rhs%E22)
      res%E33 = DOT_PRODUCT(lhs,rhs%E33)
      res%E44 = DOT_PRODUCT(lhs,rhs%E44)
      res%E55 = DOT_PRODUCT(lhs,rhs%E55)
      res%E66 = DOT_PRODUCT(lhs,rhs%E66)
      res%E77 = DOT_PRODUCT(lhs,rhs%E77)
      res%E88 = DOT_PRODUCT(lhs,rhs%E88)
      res%E99 = DOT_PRODUCT(lhs,rhs%E99)
      res%EAA = DOT_PRODUCT(lhs,rhs%EAA)
      res%EBB = DOT_PRODUCT(lhs,rhs%EBB)
      res%ECC = DOT_PRODUCT(lhs,rhs%ECC)
      res%EDD = DOT_PRODUCT(lhs,rhs%EDD)
      res%EEE = DOT_PRODUCT(lhs,rhs%EEE)
      res%EFF = DOT_PRODUCT(lhs,rhs%EFF)
      res%EGG = DOT_PRODUCT(lhs,rhs%EGG)
      res%EHH = DOT_PRODUCT(lhs,rhs%EHH)
      res%EII = DOT_PRODUCT(lhs,rhs%EII)
      res%EJJ = DOT_PRODUCT(lhs,rhs%EJJ)
      res%EKK = DOT_PRODUCT(lhs,rhs%EKK)
      res%ELL = DOT_PRODUCT(lhs,rhs%ELL)
      res%EMM = DOT_PRODUCT(lhs,rhs%EMM)

   END FUNCTION R_DOT_PRODUCT_DONUMM22N2

   FUNCTION DONUMM22N2_DOT_PRODUCT_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(DONUMM22N2) :: RES

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
      res%E8 = DOT_PRODUCT(lhs%E8,rhs)
      res%E9 = DOT_PRODUCT(lhs%E9,rhs)
      res%EA = DOT_PRODUCT(lhs%EA,rhs)
      res%EB = DOT_PRODUCT(lhs%EB,rhs)
      res%EC = DOT_PRODUCT(lhs%EC,rhs)
      res%ED = DOT_PRODUCT(lhs%ED,rhs)
      res%EE = DOT_PRODUCT(lhs%EE,rhs)
      res%EF = DOT_PRODUCT(lhs%EF,rhs)
      res%EG = DOT_PRODUCT(lhs%EG,rhs)
      res%EH = DOT_PRODUCT(lhs%EH,rhs)
      res%EI = DOT_PRODUCT(lhs%EI,rhs)
      res%EJ = DOT_PRODUCT(lhs%EJ,rhs)
      res%EK = DOT_PRODUCT(lhs%EK,rhs)
      res%EL = DOT_PRODUCT(lhs%EL,rhs)
      res%EM = DOT_PRODUCT(lhs%EM,rhs)

      ! Order 2
      res%E11 = DOT_PRODUCT(lhs%E11,rhs)
      res%E22 = DOT_PRODUCT(lhs%E22,rhs)
      res%E33 = DOT_PRODUCT(lhs%E33,rhs)
      res%E44 = DOT_PRODUCT(lhs%E44,rhs)
      res%E55 = DOT_PRODUCT(lhs%E55,rhs)
      res%E66 = DOT_PRODUCT(lhs%E66,rhs)
      res%E77 = DOT_PRODUCT(lhs%E77,rhs)
      res%E88 = DOT_PRODUCT(lhs%E88,rhs)
      res%E99 = DOT_PRODUCT(lhs%E99,rhs)
      res%EAA = DOT_PRODUCT(lhs%EAA,rhs)
      res%EBB = DOT_PRODUCT(lhs%EBB,rhs)
      res%ECC = DOT_PRODUCT(lhs%ECC,rhs)
      res%EDD = DOT_PRODUCT(lhs%EDD,rhs)
      res%EEE = DOT_PRODUCT(lhs%EEE,rhs)
      res%EFF = DOT_PRODUCT(lhs%EFF,rhs)
      res%EGG = DOT_PRODUCT(lhs%EGG,rhs)
      res%EHH = DOT_PRODUCT(lhs%EHH,rhs)
      res%EII = DOT_PRODUCT(lhs%EII,rhs)
      res%EJJ = DOT_PRODUCT(lhs%EJJ,rhs)
      res%EKK = DOT_PRODUCT(lhs%EKK,rhs)
      res%ELL = DOT_PRODUCT(lhs%ELL,rhs)
      res%EMM = DOT_PRODUCT(lhs%EMM,rhs)

   END FUNCTION DONUMM22N2_DOT_PRODUCT_R

   FUNCTION DONUMM22N2_TRANSPOSE(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N2) :: RES (SIZE(LHS,2),SIZE(LHS,1))

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
      RES%E8 = TRANSPOSE(LHS%E8)
      RES%E9 = TRANSPOSE(LHS%E9)
      RES%EA = TRANSPOSE(LHS%EA)
      RES%EB = TRANSPOSE(LHS%EB)
      RES%EC = TRANSPOSE(LHS%EC)
      RES%ED = TRANSPOSE(LHS%ED)
      RES%EE = TRANSPOSE(LHS%EE)
      RES%EF = TRANSPOSE(LHS%EF)
      RES%EG = TRANSPOSE(LHS%EG)
      RES%EH = TRANSPOSE(LHS%EH)
      RES%EI = TRANSPOSE(LHS%EI)
      RES%EJ = TRANSPOSE(LHS%EJ)
      RES%EK = TRANSPOSE(LHS%EK)
      RES%EL = TRANSPOSE(LHS%EL)
      RES%EM = TRANSPOSE(LHS%EM)
      ! Order 2
      RES%E11 = TRANSPOSE(LHS%E11)
      RES%E22 = TRANSPOSE(LHS%E22)
      RES%E33 = TRANSPOSE(LHS%E33)
      RES%E44 = TRANSPOSE(LHS%E44)
      RES%E55 = TRANSPOSE(LHS%E55)
      RES%E66 = TRANSPOSE(LHS%E66)
      RES%E77 = TRANSPOSE(LHS%E77)
      RES%E88 = TRANSPOSE(LHS%E88)
      RES%E99 = TRANSPOSE(LHS%E99)
      RES%EAA = TRANSPOSE(LHS%EAA)
      RES%EBB = TRANSPOSE(LHS%EBB)
      RES%ECC = TRANSPOSE(LHS%ECC)
      RES%EDD = TRANSPOSE(LHS%EDD)
      RES%EEE = TRANSPOSE(LHS%EEE)
      RES%EFF = TRANSPOSE(LHS%EFF)
      RES%EGG = TRANSPOSE(LHS%EGG)
      RES%EHH = TRANSPOSE(LHS%EHH)
      RES%EII = TRANSPOSE(LHS%EII)
      RES%EJJ = TRANSPOSE(LHS%EJJ)
      RES%EKK = TRANSPOSE(LHS%EKK)
      RES%ELL = TRANSPOSE(LHS%ELL)
      RES%EMM = TRANSPOSE(LHS%EMM)

   END FUNCTION DONUMM22N2_TRANSPOSE

FUNCTION DONUMM22N2_TO_CR_MAT_S(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: VAL
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
      ! R x E8 -> E8 (9, 9)
      RES(1+NROWS*8:NROWS*9,1+NCOLS*8:NCOLS*9) = VAL%R
      ! E8 x R -> E8 (9, 1)
      RES(1+NROWS*8:NROWS*9,1+NCOLS*0:NCOLS*1) = VAL%E8
      ! R x E9 -> E9 (10, 10)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*9:NCOLS*10) = VAL%R
      ! E9 x R -> E9 (10, 1)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*0:NCOLS*1) = VAL%E9
      ! R x EA -> EA (11, 11)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*10:NCOLS*11) = VAL%R
      ! EA x R -> EA (11, 1)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*0:NCOLS*1) = VAL%EA
      ! R x EB -> EB (12, 12)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*11:NCOLS*12) = VAL%R
      ! EB x R -> EB (12, 1)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*0:NCOLS*1) = VAL%EB
      ! R x EC -> EC (13, 13)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*12:NCOLS*13) = VAL%R
      ! EC x R -> EC (13, 1)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*0:NCOLS*1) = VAL%EC
      ! R x ED -> ED (14, 14)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*13:NCOLS*14) = VAL%R
      ! ED x R -> ED (14, 1)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*0:NCOLS*1) = VAL%ED
      ! R x EE -> EE (15, 15)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*14:NCOLS*15) = VAL%R
      ! EE x R -> EE (15, 1)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*0:NCOLS*1) = VAL%EE
      ! R x EF -> EF (16, 16)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*15:NCOLS*16) = VAL%R
      ! EF x R -> EF (16, 1)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*0:NCOLS*1) = VAL%EF
      ! R x EG -> EG (17, 17)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*16:NCOLS*17) = VAL%R
      ! EG x R -> EG (17, 1)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*0:NCOLS*1) = VAL%EG
      ! R x EH -> EH (18, 18)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*17:NCOLS*18) = VAL%R
      ! EH x R -> EH (18, 1)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*0:NCOLS*1) = VAL%EH
      ! R x EI -> EI (19, 19)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*18:NCOLS*19) = VAL%R
      ! EI x R -> EI (19, 1)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*0:NCOLS*1) = VAL%EI
      ! R x EJ -> EJ (20, 20)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*19:NCOLS*20) = VAL%R
      ! EJ x R -> EJ (20, 1)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*0:NCOLS*1) = VAL%EJ
      ! R x EK -> EK (21, 21)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*20:NCOLS*21) = VAL%R
      ! EK x R -> EK (21, 1)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*0:NCOLS*1) = VAL%EK
      ! R x EL -> EL (22, 22)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*21:NCOLS*22) = VAL%R
      ! EL x R -> EL (22, 1)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*0:NCOLS*1) = VAL%EL
      ! R x EM -> EM (23, 23)
      RES(1+NROWS*22:NROWS*23,1+NCOLS*22:NCOLS*23) = VAL%R
      ! EM x R -> EM (23, 1)
      RES(1+NROWS*22:NROWS*23,1+NCOLS*0:NCOLS*1) = VAL%EM
      ! R x E11 -> E11 (24, 24)
      RES(1+NROWS*23:NROWS*24,1+NCOLS*23:NCOLS*24) = VAL%R
      ! E11 x R -> E11 (24, 1)
      RES(1+NROWS*23:NROWS*24,1+NCOLS*0:NCOLS*1) = VAL%E11
      ! E1 x E1 -> E11 (24, 2)
      RES(1+NROWS*23:NROWS*24,1+NCOLS*1:NCOLS*2) = VAL%E1
      ! R x E22 -> E22 (25, 25)
      RES(1+NROWS*24:NROWS*25,1+NCOLS*24:NCOLS*25) = VAL%R
      ! E22 x R -> E22 (25, 1)
      RES(1+NROWS*24:NROWS*25,1+NCOLS*0:NCOLS*1) = VAL%E22
      ! E2 x E2 -> E22 (25, 3)
      RES(1+NROWS*24:NROWS*25,1+NCOLS*2:NCOLS*3) = VAL%E2
      ! R x E33 -> E33 (26, 26)
      RES(1+NROWS*25:NROWS*26,1+NCOLS*25:NCOLS*26) = VAL%R
      ! E33 x R -> E33 (26, 1)
      RES(1+NROWS*25:NROWS*26,1+NCOLS*0:NCOLS*1) = VAL%E33
      ! E3 x E3 -> E33 (26, 4)
      RES(1+NROWS*25:NROWS*26,1+NCOLS*3:NCOLS*4) = VAL%E3
      ! R x E44 -> E44 (27, 27)
      RES(1+NROWS*26:NROWS*27,1+NCOLS*26:NCOLS*27) = VAL%R
      ! E44 x R -> E44 (27, 1)
      RES(1+NROWS*26:NROWS*27,1+NCOLS*0:NCOLS*1) = VAL%E44
      ! E4 x E4 -> E44 (27, 5)
      RES(1+NROWS*26:NROWS*27,1+NCOLS*4:NCOLS*5) = VAL%E4
      ! R x E55 -> E55 (28, 28)
      RES(1+NROWS*27:NROWS*28,1+NCOLS*27:NCOLS*28) = VAL%R
      ! E55 x R -> E55 (28, 1)
      RES(1+NROWS*27:NROWS*28,1+NCOLS*0:NCOLS*1) = VAL%E55
      ! E5 x E5 -> E55 (28, 6)
      RES(1+NROWS*27:NROWS*28,1+NCOLS*5:NCOLS*6) = VAL%E5
      ! R x E66 -> E66 (29, 29)
      RES(1+NROWS*28:NROWS*29,1+NCOLS*28:NCOLS*29) = VAL%R
      ! E66 x R -> E66 (29, 1)
      RES(1+NROWS*28:NROWS*29,1+NCOLS*0:NCOLS*1) = VAL%E66
      ! E6 x E6 -> E66 (29, 7)
      RES(1+NROWS*28:NROWS*29,1+NCOLS*6:NCOLS*7) = VAL%E6
      ! R x E77 -> E77 (30, 30)
      RES(1+NROWS*29:NROWS*30,1+NCOLS*29:NCOLS*30) = VAL%R
      ! E77 x R -> E77 (30, 1)
      RES(1+NROWS*29:NROWS*30,1+NCOLS*0:NCOLS*1) = VAL%E77
      ! E7 x E7 -> E77 (30, 8)
      RES(1+NROWS*29:NROWS*30,1+NCOLS*7:NCOLS*8) = VAL%E7
      ! R x E88 -> E88 (31, 31)
      RES(1+NROWS*30:NROWS*31,1+NCOLS*30:NCOLS*31) = VAL%R
      ! E88 x R -> E88 (31, 1)
      RES(1+NROWS*30:NROWS*31,1+NCOLS*0:NCOLS*1) = VAL%E88
      ! E8 x E8 -> E88 (31, 9)
      RES(1+NROWS*30:NROWS*31,1+NCOLS*8:NCOLS*9) = VAL%E8
      ! R x E99 -> E99 (32, 32)
      RES(1+NROWS*31:NROWS*32,1+NCOLS*31:NCOLS*32) = VAL%R
      ! E99 x R -> E99 (32, 1)
      RES(1+NROWS*31:NROWS*32,1+NCOLS*0:NCOLS*1) = VAL%E99
      ! E9 x E9 -> E99 (32, 10)
      RES(1+NROWS*31:NROWS*32,1+NCOLS*9:NCOLS*10) = VAL%E9
      ! R x EAA -> EAA (33, 33)
      RES(1+NROWS*32:NROWS*33,1+NCOLS*32:NCOLS*33) = VAL%R
      ! EAA x R -> EAA (33, 1)
      RES(1+NROWS*32:NROWS*33,1+NCOLS*0:NCOLS*1) = VAL%EAA
      ! EA x EA -> EAA (33, 11)
      RES(1+NROWS*32:NROWS*33,1+NCOLS*10:NCOLS*11) = VAL%EA
      ! R x EBB -> EBB (34, 34)
      RES(1+NROWS*33:NROWS*34,1+NCOLS*33:NCOLS*34) = VAL%R
      ! EBB x R -> EBB (34, 1)
      RES(1+NROWS*33:NROWS*34,1+NCOLS*0:NCOLS*1) = VAL%EBB
      ! EB x EB -> EBB (34, 12)
      RES(1+NROWS*33:NROWS*34,1+NCOLS*11:NCOLS*12) = VAL%EB
      ! R x ECC -> ECC (35, 35)
      RES(1+NROWS*34:NROWS*35,1+NCOLS*34:NCOLS*35) = VAL%R
      ! ECC x R -> ECC (35, 1)
      RES(1+NROWS*34:NROWS*35,1+NCOLS*0:NCOLS*1) = VAL%ECC
      ! EC x EC -> ECC (35, 13)
      RES(1+NROWS*34:NROWS*35,1+NCOLS*12:NCOLS*13) = VAL%EC
      ! R x EDD -> EDD (36, 36)
      RES(1+NROWS*35:NROWS*36,1+NCOLS*35:NCOLS*36) = VAL%R
      ! EDD x R -> EDD (36, 1)
      RES(1+NROWS*35:NROWS*36,1+NCOLS*0:NCOLS*1) = VAL%EDD
      ! ED x ED -> EDD (36, 14)
      RES(1+NROWS*35:NROWS*36,1+NCOLS*13:NCOLS*14) = VAL%ED
      ! R x EEE -> EEE (37, 37)
      RES(1+NROWS*36:NROWS*37,1+NCOLS*36:NCOLS*37) = VAL%R
      ! EEE x R -> EEE (37, 1)
      RES(1+NROWS*36:NROWS*37,1+NCOLS*0:NCOLS*1) = VAL%EEE
      ! EE x EE -> EEE (37, 15)
      RES(1+NROWS*36:NROWS*37,1+NCOLS*14:NCOLS*15) = VAL%EE
      ! R x EFF -> EFF (38, 38)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*37:NCOLS*38) = VAL%R
      ! EFF x R -> EFF (38, 1)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*0:NCOLS*1) = VAL%EFF
      ! EF x EF -> EFF (38, 16)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*15:NCOLS*16) = VAL%EF
      ! R x EGG -> EGG (39, 39)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*38:NCOLS*39) = VAL%R
      ! EGG x R -> EGG (39, 1)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*0:NCOLS*1) = VAL%EGG
      ! EG x EG -> EGG (39, 17)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*16:NCOLS*17) = VAL%EG
      ! R x EHH -> EHH (40, 40)
      RES(1+NROWS*39:NROWS*40,1+NCOLS*39:NCOLS*40) = VAL%R
      ! EHH x R -> EHH (40, 1)
      RES(1+NROWS*39:NROWS*40,1+NCOLS*0:NCOLS*1) = VAL%EHH
      ! EH x EH -> EHH (40, 18)
      RES(1+NROWS*39:NROWS*40,1+NCOLS*17:NCOLS*18) = VAL%EH
      ! R x EII -> EII (41, 41)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*40:NCOLS*41) = VAL%R
      ! EII x R -> EII (41, 1)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*0:NCOLS*1) = VAL%EII
      ! EI x EI -> EII (41, 19)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*18:NCOLS*19) = VAL%EI
      ! R x EJJ -> EJJ (42, 42)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*41:NCOLS*42) = VAL%R
      ! EJJ x R -> EJJ (42, 1)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*0:NCOLS*1) = VAL%EJJ
      ! EJ x EJ -> EJJ (42, 20)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*19:NCOLS*20) = VAL%EJ
      ! R x EKK -> EKK (43, 43)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*42:NCOLS*43) = VAL%R
      ! EKK x R -> EKK (43, 1)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*0:NCOLS*1) = VAL%EKK
      ! EK x EK -> EKK (43, 21)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*20:NCOLS*21) = VAL%EK
      ! R x ELL -> ELL (44, 44)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*43:NCOLS*44) = VAL%R
      ! ELL x R -> ELL (44, 1)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*0:NCOLS*1) = VAL%ELL
      ! EL x EL -> ELL (44, 22)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*21:NCOLS*22) = VAL%EL
      ! R x EMM -> EMM (45, 45)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*44:NCOLS*45) = VAL%R
      ! EMM x R -> EMM (45, 1)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*0:NCOLS*1) = VAL%EMM
      ! EM x EM -> EMM (45, 23)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*22:NCOLS*23) = VAL%EM
   END FUNCTION DONUMM22N2_TO_CR_MAT_S

FUNCTION DONUMM22N2_TO_CR_MAT_V(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: VAL(:)
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
      ! R x E8 -> E8 (9, 9)
      RES(1+NROWS*8:NROWS*9,9) = VAL%R
      ! E8 x R -> E8 (9, 1)
      RES(1+NROWS*8:NROWS*9,1) = VAL%E8
      ! R x E9 -> E9 (10, 10)
      RES(1+NROWS*9:NROWS*10,10) = VAL%R
      ! E9 x R -> E9 (10, 1)
      RES(1+NROWS*9:NROWS*10,1) = VAL%E9
      ! R x EA -> EA (11, 11)
      RES(1+NROWS*10:NROWS*11,11) = VAL%R
      ! EA x R -> EA (11, 1)
      RES(1+NROWS*10:NROWS*11,1) = VAL%EA
      ! R x EB -> EB (12, 12)
      RES(1+NROWS*11:NROWS*12,12) = VAL%R
      ! EB x R -> EB (12, 1)
      RES(1+NROWS*11:NROWS*12,1) = VAL%EB
      ! R x EC -> EC (13, 13)
      RES(1+NROWS*12:NROWS*13,13) = VAL%R
      ! EC x R -> EC (13, 1)
      RES(1+NROWS*12:NROWS*13,1) = VAL%EC
      ! R x ED -> ED (14, 14)
      RES(1+NROWS*13:NROWS*14,14) = VAL%R
      ! ED x R -> ED (14, 1)
      RES(1+NROWS*13:NROWS*14,1) = VAL%ED
      ! R x EE -> EE (15, 15)
      RES(1+NROWS*14:NROWS*15,15) = VAL%R
      ! EE x R -> EE (15, 1)
      RES(1+NROWS*14:NROWS*15,1) = VAL%EE
      ! R x EF -> EF (16, 16)
      RES(1+NROWS*15:NROWS*16,16) = VAL%R
      ! EF x R -> EF (16, 1)
      RES(1+NROWS*15:NROWS*16,1) = VAL%EF
      ! R x EG -> EG (17, 17)
      RES(1+NROWS*16:NROWS*17,17) = VAL%R
      ! EG x R -> EG (17, 1)
      RES(1+NROWS*16:NROWS*17,1) = VAL%EG
      ! R x EH -> EH (18, 18)
      RES(1+NROWS*17:NROWS*18,18) = VAL%R
      ! EH x R -> EH (18, 1)
      RES(1+NROWS*17:NROWS*18,1) = VAL%EH
      ! R x EI -> EI (19, 19)
      RES(1+NROWS*18:NROWS*19,19) = VAL%R
      ! EI x R -> EI (19, 1)
      RES(1+NROWS*18:NROWS*19,1) = VAL%EI
      ! R x EJ -> EJ (20, 20)
      RES(1+NROWS*19:NROWS*20,20) = VAL%R
      ! EJ x R -> EJ (20, 1)
      RES(1+NROWS*19:NROWS*20,1) = VAL%EJ
      ! R x EK -> EK (21, 21)
      RES(1+NROWS*20:NROWS*21,21) = VAL%R
      ! EK x R -> EK (21, 1)
      RES(1+NROWS*20:NROWS*21,1) = VAL%EK
      ! R x EL -> EL (22, 22)
      RES(1+NROWS*21:NROWS*22,22) = VAL%R
      ! EL x R -> EL (22, 1)
      RES(1+NROWS*21:NROWS*22,1) = VAL%EL
      ! R x EM -> EM (23, 23)
      RES(1+NROWS*22:NROWS*23,23) = VAL%R
      ! EM x R -> EM (23, 1)
      RES(1+NROWS*22:NROWS*23,1) = VAL%EM
      ! R x E11 -> E11 (24, 24)
      RES(1+NROWS*23:NROWS*24,24) = VAL%R
      ! E11 x R -> E11 (24, 1)
      RES(1+NROWS*23:NROWS*24,1) = VAL%E11
      ! E1 x E1 -> E11 (24, 2)
      RES(1+NROWS*23:NROWS*24,2) = VAL%E1
      ! R x E22 -> E22 (25, 25)
      RES(1+NROWS*24:NROWS*25,25) = VAL%R
      ! E22 x R -> E22 (25, 1)
      RES(1+NROWS*24:NROWS*25,1) = VAL%E22
      ! E2 x E2 -> E22 (25, 3)
      RES(1+NROWS*24:NROWS*25,3) = VAL%E2
      ! R x E33 -> E33 (26, 26)
      RES(1+NROWS*25:NROWS*26,26) = VAL%R
      ! E33 x R -> E33 (26, 1)
      RES(1+NROWS*25:NROWS*26,1) = VAL%E33
      ! E3 x E3 -> E33 (26, 4)
      RES(1+NROWS*25:NROWS*26,4) = VAL%E3
      ! R x E44 -> E44 (27, 27)
      RES(1+NROWS*26:NROWS*27,27) = VAL%R
      ! E44 x R -> E44 (27, 1)
      RES(1+NROWS*26:NROWS*27,1) = VAL%E44
      ! E4 x E4 -> E44 (27, 5)
      RES(1+NROWS*26:NROWS*27,5) = VAL%E4
      ! R x E55 -> E55 (28, 28)
      RES(1+NROWS*27:NROWS*28,28) = VAL%R
      ! E55 x R -> E55 (28, 1)
      RES(1+NROWS*27:NROWS*28,1) = VAL%E55
      ! E5 x E5 -> E55 (28, 6)
      RES(1+NROWS*27:NROWS*28,6) = VAL%E5
      ! R x E66 -> E66 (29, 29)
      RES(1+NROWS*28:NROWS*29,29) = VAL%R
      ! E66 x R -> E66 (29, 1)
      RES(1+NROWS*28:NROWS*29,1) = VAL%E66
      ! E6 x E6 -> E66 (29, 7)
      RES(1+NROWS*28:NROWS*29,7) = VAL%E6
      ! R x E77 -> E77 (30, 30)
      RES(1+NROWS*29:NROWS*30,30) = VAL%R
      ! E77 x R -> E77 (30, 1)
      RES(1+NROWS*29:NROWS*30,1) = VAL%E77
      ! E7 x E7 -> E77 (30, 8)
      RES(1+NROWS*29:NROWS*30,8) = VAL%E7
      ! R x E88 -> E88 (31, 31)
      RES(1+NROWS*30:NROWS*31,31) = VAL%R
      ! E88 x R -> E88 (31, 1)
      RES(1+NROWS*30:NROWS*31,1) = VAL%E88
      ! E8 x E8 -> E88 (31, 9)
      RES(1+NROWS*30:NROWS*31,9) = VAL%E8
      ! R x E99 -> E99 (32, 32)
      RES(1+NROWS*31:NROWS*32,32) = VAL%R
      ! E99 x R -> E99 (32, 1)
      RES(1+NROWS*31:NROWS*32,1) = VAL%E99
      ! E9 x E9 -> E99 (32, 10)
      RES(1+NROWS*31:NROWS*32,10) = VAL%E9
      ! R x EAA -> EAA (33, 33)
      RES(1+NROWS*32:NROWS*33,33) = VAL%R
      ! EAA x R -> EAA (33, 1)
      RES(1+NROWS*32:NROWS*33,1) = VAL%EAA
      ! EA x EA -> EAA (33, 11)
      RES(1+NROWS*32:NROWS*33,11) = VAL%EA
      ! R x EBB -> EBB (34, 34)
      RES(1+NROWS*33:NROWS*34,34) = VAL%R
      ! EBB x R -> EBB (34, 1)
      RES(1+NROWS*33:NROWS*34,1) = VAL%EBB
      ! EB x EB -> EBB (34, 12)
      RES(1+NROWS*33:NROWS*34,12) = VAL%EB
      ! R x ECC -> ECC (35, 35)
      RES(1+NROWS*34:NROWS*35,35) = VAL%R
      ! ECC x R -> ECC (35, 1)
      RES(1+NROWS*34:NROWS*35,1) = VAL%ECC
      ! EC x EC -> ECC (35, 13)
      RES(1+NROWS*34:NROWS*35,13) = VAL%EC
      ! R x EDD -> EDD (36, 36)
      RES(1+NROWS*35:NROWS*36,36) = VAL%R
      ! EDD x R -> EDD (36, 1)
      RES(1+NROWS*35:NROWS*36,1) = VAL%EDD
      ! ED x ED -> EDD (36, 14)
      RES(1+NROWS*35:NROWS*36,14) = VAL%ED
      ! R x EEE -> EEE (37, 37)
      RES(1+NROWS*36:NROWS*37,37) = VAL%R
      ! EEE x R -> EEE (37, 1)
      RES(1+NROWS*36:NROWS*37,1) = VAL%EEE
      ! EE x EE -> EEE (37, 15)
      RES(1+NROWS*36:NROWS*37,15) = VAL%EE
      ! R x EFF -> EFF (38, 38)
      RES(1+NROWS*37:NROWS*38,38) = VAL%R
      ! EFF x R -> EFF (38, 1)
      RES(1+NROWS*37:NROWS*38,1) = VAL%EFF
      ! EF x EF -> EFF (38, 16)
      RES(1+NROWS*37:NROWS*38,16) = VAL%EF
      ! R x EGG -> EGG (39, 39)
      RES(1+NROWS*38:NROWS*39,39) = VAL%R
      ! EGG x R -> EGG (39, 1)
      RES(1+NROWS*38:NROWS*39,1) = VAL%EGG
      ! EG x EG -> EGG (39, 17)
      RES(1+NROWS*38:NROWS*39,17) = VAL%EG
      ! R x EHH -> EHH (40, 40)
      RES(1+NROWS*39:NROWS*40,40) = VAL%R
      ! EHH x R -> EHH (40, 1)
      RES(1+NROWS*39:NROWS*40,1) = VAL%EHH
      ! EH x EH -> EHH (40, 18)
      RES(1+NROWS*39:NROWS*40,18) = VAL%EH
      ! R x EII -> EII (41, 41)
      RES(1+NROWS*40:NROWS*41,41) = VAL%R
      ! EII x R -> EII (41, 1)
      RES(1+NROWS*40:NROWS*41,1) = VAL%EII
      ! EI x EI -> EII (41, 19)
      RES(1+NROWS*40:NROWS*41,19) = VAL%EI
      ! R x EJJ -> EJJ (42, 42)
      RES(1+NROWS*41:NROWS*42,42) = VAL%R
      ! EJJ x R -> EJJ (42, 1)
      RES(1+NROWS*41:NROWS*42,1) = VAL%EJJ
      ! EJ x EJ -> EJJ (42, 20)
      RES(1+NROWS*41:NROWS*42,20) = VAL%EJ
      ! R x EKK -> EKK (43, 43)
      RES(1+NROWS*42:NROWS*43,43) = VAL%R
      ! EKK x R -> EKK (43, 1)
      RES(1+NROWS*42:NROWS*43,1) = VAL%EKK
      ! EK x EK -> EKK (43, 21)
      RES(1+NROWS*42:NROWS*43,21) = VAL%EK
      ! R x ELL -> ELL (44, 44)
      RES(1+NROWS*43:NROWS*44,44) = VAL%R
      ! ELL x R -> ELL (44, 1)
      RES(1+NROWS*43:NROWS*44,1) = VAL%ELL
      ! EL x EL -> ELL (44, 22)
      RES(1+NROWS*43:NROWS*44,22) = VAL%EL
      ! R x EMM -> EMM (45, 45)
      RES(1+NROWS*44:NROWS*45,45) = VAL%R
      ! EMM x R -> EMM (45, 1)
      RES(1+NROWS*44:NROWS*45,1) = VAL%EMM
      ! EM x EM -> EMM (45, 23)
      RES(1+NROWS*44:NROWS*45,23) = VAL%EM
   END FUNCTION DONUMM22N2_TO_CR_MAT_V

FUNCTION DONUMM22N2_TO_CR_MAT_M(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: VAL(:,:)
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
      ! R x E8 -> E8 (9, 9)
      RES(1+NROWS*8:NROWS*9,1+NCOLS*8:NCOLS*9) = VAL%R
      ! E8 x R -> E8 (9, 1)
      RES(1+NROWS*8:NROWS*9,1+NCOLS*0:NCOLS*1) = VAL%E8
      ! R x E9 -> E9 (10, 10)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*9:NCOLS*10) = VAL%R
      ! E9 x R -> E9 (10, 1)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*0:NCOLS*1) = VAL%E9
      ! R x EA -> EA (11, 11)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*10:NCOLS*11) = VAL%R
      ! EA x R -> EA (11, 1)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*0:NCOLS*1) = VAL%EA
      ! R x EB -> EB (12, 12)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*11:NCOLS*12) = VAL%R
      ! EB x R -> EB (12, 1)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*0:NCOLS*1) = VAL%EB
      ! R x EC -> EC (13, 13)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*12:NCOLS*13) = VAL%R
      ! EC x R -> EC (13, 1)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*0:NCOLS*1) = VAL%EC
      ! R x ED -> ED (14, 14)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*13:NCOLS*14) = VAL%R
      ! ED x R -> ED (14, 1)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*0:NCOLS*1) = VAL%ED
      ! R x EE -> EE (15, 15)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*14:NCOLS*15) = VAL%R
      ! EE x R -> EE (15, 1)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*0:NCOLS*1) = VAL%EE
      ! R x EF -> EF (16, 16)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*15:NCOLS*16) = VAL%R
      ! EF x R -> EF (16, 1)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*0:NCOLS*1) = VAL%EF
      ! R x EG -> EG (17, 17)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*16:NCOLS*17) = VAL%R
      ! EG x R -> EG (17, 1)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*0:NCOLS*1) = VAL%EG
      ! R x EH -> EH (18, 18)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*17:NCOLS*18) = VAL%R
      ! EH x R -> EH (18, 1)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*0:NCOLS*1) = VAL%EH
      ! R x EI -> EI (19, 19)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*18:NCOLS*19) = VAL%R
      ! EI x R -> EI (19, 1)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*0:NCOLS*1) = VAL%EI
      ! R x EJ -> EJ (20, 20)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*19:NCOLS*20) = VAL%R
      ! EJ x R -> EJ (20, 1)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*0:NCOLS*1) = VAL%EJ
      ! R x EK -> EK (21, 21)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*20:NCOLS*21) = VAL%R
      ! EK x R -> EK (21, 1)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*0:NCOLS*1) = VAL%EK
      ! R x EL -> EL (22, 22)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*21:NCOLS*22) = VAL%R
      ! EL x R -> EL (22, 1)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*0:NCOLS*1) = VAL%EL
      ! R x EM -> EM (23, 23)
      RES(1+NROWS*22:NROWS*23,1+NCOLS*22:NCOLS*23) = VAL%R
      ! EM x R -> EM (23, 1)
      RES(1+NROWS*22:NROWS*23,1+NCOLS*0:NCOLS*1) = VAL%EM
      ! R x E11 -> E11 (24, 24)
      RES(1+NROWS*23:NROWS*24,1+NCOLS*23:NCOLS*24) = VAL%R
      ! E11 x R -> E11 (24, 1)
      RES(1+NROWS*23:NROWS*24,1+NCOLS*0:NCOLS*1) = VAL%E11
      ! E1 x E1 -> E11 (24, 2)
      RES(1+NROWS*23:NROWS*24,1+NCOLS*1:NCOLS*2) = VAL%E1
      ! R x E22 -> E22 (25, 25)
      RES(1+NROWS*24:NROWS*25,1+NCOLS*24:NCOLS*25) = VAL%R
      ! E22 x R -> E22 (25, 1)
      RES(1+NROWS*24:NROWS*25,1+NCOLS*0:NCOLS*1) = VAL%E22
      ! E2 x E2 -> E22 (25, 3)
      RES(1+NROWS*24:NROWS*25,1+NCOLS*2:NCOLS*3) = VAL%E2
      ! R x E33 -> E33 (26, 26)
      RES(1+NROWS*25:NROWS*26,1+NCOLS*25:NCOLS*26) = VAL%R
      ! E33 x R -> E33 (26, 1)
      RES(1+NROWS*25:NROWS*26,1+NCOLS*0:NCOLS*1) = VAL%E33
      ! E3 x E3 -> E33 (26, 4)
      RES(1+NROWS*25:NROWS*26,1+NCOLS*3:NCOLS*4) = VAL%E3
      ! R x E44 -> E44 (27, 27)
      RES(1+NROWS*26:NROWS*27,1+NCOLS*26:NCOLS*27) = VAL%R
      ! E44 x R -> E44 (27, 1)
      RES(1+NROWS*26:NROWS*27,1+NCOLS*0:NCOLS*1) = VAL%E44
      ! E4 x E4 -> E44 (27, 5)
      RES(1+NROWS*26:NROWS*27,1+NCOLS*4:NCOLS*5) = VAL%E4
      ! R x E55 -> E55 (28, 28)
      RES(1+NROWS*27:NROWS*28,1+NCOLS*27:NCOLS*28) = VAL%R
      ! E55 x R -> E55 (28, 1)
      RES(1+NROWS*27:NROWS*28,1+NCOLS*0:NCOLS*1) = VAL%E55
      ! E5 x E5 -> E55 (28, 6)
      RES(1+NROWS*27:NROWS*28,1+NCOLS*5:NCOLS*6) = VAL%E5
      ! R x E66 -> E66 (29, 29)
      RES(1+NROWS*28:NROWS*29,1+NCOLS*28:NCOLS*29) = VAL%R
      ! E66 x R -> E66 (29, 1)
      RES(1+NROWS*28:NROWS*29,1+NCOLS*0:NCOLS*1) = VAL%E66
      ! E6 x E6 -> E66 (29, 7)
      RES(1+NROWS*28:NROWS*29,1+NCOLS*6:NCOLS*7) = VAL%E6
      ! R x E77 -> E77 (30, 30)
      RES(1+NROWS*29:NROWS*30,1+NCOLS*29:NCOLS*30) = VAL%R
      ! E77 x R -> E77 (30, 1)
      RES(1+NROWS*29:NROWS*30,1+NCOLS*0:NCOLS*1) = VAL%E77
      ! E7 x E7 -> E77 (30, 8)
      RES(1+NROWS*29:NROWS*30,1+NCOLS*7:NCOLS*8) = VAL%E7
      ! R x E88 -> E88 (31, 31)
      RES(1+NROWS*30:NROWS*31,1+NCOLS*30:NCOLS*31) = VAL%R
      ! E88 x R -> E88 (31, 1)
      RES(1+NROWS*30:NROWS*31,1+NCOLS*0:NCOLS*1) = VAL%E88
      ! E8 x E8 -> E88 (31, 9)
      RES(1+NROWS*30:NROWS*31,1+NCOLS*8:NCOLS*9) = VAL%E8
      ! R x E99 -> E99 (32, 32)
      RES(1+NROWS*31:NROWS*32,1+NCOLS*31:NCOLS*32) = VAL%R
      ! E99 x R -> E99 (32, 1)
      RES(1+NROWS*31:NROWS*32,1+NCOLS*0:NCOLS*1) = VAL%E99
      ! E9 x E9 -> E99 (32, 10)
      RES(1+NROWS*31:NROWS*32,1+NCOLS*9:NCOLS*10) = VAL%E9
      ! R x EAA -> EAA (33, 33)
      RES(1+NROWS*32:NROWS*33,1+NCOLS*32:NCOLS*33) = VAL%R
      ! EAA x R -> EAA (33, 1)
      RES(1+NROWS*32:NROWS*33,1+NCOLS*0:NCOLS*1) = VAL%EAA
      ! EA x EA -> EAA (33, 11)
      RES(1+NROWS*32:NROWS*33,1+NCOLS*10:NCOLS*11) = VAL%EA
      ! R x EBB -> EBB (34, 34)
      RES(1+NROWS*33:NROWS*34,1+NCOLS*33:NCOLS*34) = VAL%R
      ! EBB x R -> EBB (34, 1)
      RES(1+NROWS*33:NROWS*34,1+NCOLS*0:NCOLS*1) = VAL%EBB
      ! EB x EB -> EBB (34, 12)
      RES(1+NROWS*33:NROWS*34,1+NCOLS*11:NCOLS*12) = VAL%EB
      ! R x ECC -> ECC (35, 35)
      RES(1+NROWS*34:NROWS*35,1+NCOLS*34:NCOLS*35) = VAL%R
      ! ECC x R -> ECC (35, 1)
      RES(1+NROWS*34:NROWS*35,1+NCOLS*0:NCOLS*1) = VAL%ECC
      ! EC x EC -> ECC (35, 13)
      RES(1+NROWS*34:NROWS*35,1+NCOLS*12:NCOLS*13) = VAL%EC
      ! R x EDD -> EDD (36, 36)
      RES(1+NROWS*35:NROWS*36,1+NCOLS*35:NCOLS*36) = VAL%R
      ! EDD x R -> EDD (36, 1)
      RES(1+NROWS*35:NROWS*36,1+NCOLS*0:NCOLS*1) = VAL%EDD
      ! ED x ED -> EDD (36, 14)
      RES(1+NROWS*35:NROWS*36,1+NCOLS*13:NCOLS*14) = VAL%ED
      ! R x EEE -> EEE (37, 37)
      RES(1+NROWS*36:NROWS*37,1+NCOLS*36:NCOLS*37) = VAL%R
      ! EEE x R -> EEE (37, 1)
      RES(1+NROWS*36:NROWS*37,1+NCOLS*0:NCOLS*1) = VAL%EEE
      ! EE x EE -> EEE (37, 15)
      RES(1+NROWS*36:NROWS*37,1+NCOLS*14:NCOLS*15) = VAL%EE
      ! R x EFF -> EFF (38, 38)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*37:NCOLS*38) = VAL%R
      ! EFF x R -> EFF (38, 1)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*0:NCOLS*1) = VAL%EFF
      ! EF x EF -> EFF (38, 16)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*15:NCOLS*16) = VAL%EF
      ! R x EGG -> EGG (39, 39)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*38:NCOLS*39) = VAL%R
      ! EGG x R -> EGG (39, 1)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*0:NCOLS*1) = VAL%EGG
      ! EG x EG -> EGG (39, 17)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*16:NCOLS*17) = VAL%EG
      ! R x EHH -> EHH (40, 40)
      RES(1+NROWS*39:NROWS*40,1+NCOLS*39:NCOLS*40) = VAL%R
      ! EHH x R -> EHH (40, 1)
      RES(1+NROWS*39:NROWS*40,1+NCOLS*0:NCOLS*1) = VAL%EHH
      ! EH x EH -> EHH (40, 18)
      RES(1+NROWS*39:NROWS*40,1+NCOLS*17:NCOLS*18) = VAL%EH
      ! R x EII -> EII (41, 41)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*40:NCOLS*41) = VAL%R
      ! EII x R -> EII (41, 1)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*0:NCOLS*1) = VAL%EII
      ! EI x EI -> EII (41, 19)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*18:NCOLS*19) = VAL%EI
      ! R x EJJ -> EJJ (42, 42)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*41:NCOLS*42) = VAL%R
      ! EJJ x R -> EJJ (42, 1)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*0:NCOLS*1) = VAL%EJJ
      ! EJ x EJ -> EJJ (42, 20)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*19:NCOLS*20) = VAL%EJ
      ! R x EKK -> EKK (43, 43)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*42:NCOLS*43) = VAL%R
      ! EKK x R -> EKK (43, 1)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*0:NCOLS*1) = VAL%EKK
      ! EK x EK -> EKK (43, 21)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*20:NCOLS*21) = VAL%EK
      ! R x ELL -> ELL (44, 44)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*43:NCOLS*44) = VAL%R
      ! ELL x R -> ELL (44, 1)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*0:NCOLS*1) = VAL%ELL
      ! EL x EL -> ELL (44, 22)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*21:NCOLS*22) = VAL%EL
      ! R x EMM -> EMM (45, 45)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*44:NCOLS*45) = VAL%R
      ! EMM x R -> EMM (45, 1)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*0:NCOLS*1) = VAL%EMM
      ! EM x EM -> EMM (45, 23)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*22:NCOLS*23) = VAL%EM
   END FUNCTION DONUMM22N2_TO_CR_MAT_M

      SUBROUTINE DONUMM22N2_SETIM_S(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(INOUT) :: VAL
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
      CASE(8)
         VAL%E8=RES
      CASE(9)
         VAL%E9=RES
      CASE(10)
         VAL%EA=RES
      CASE(11)
         VAL%EB=RES
      CASE(12)
         VAL%EC=RES
      CASE(13)
         VAL%ED=RES
      CASE(14)
         VAL%EE=RES
      CASE(15)
         VAL%EF=RES
      CASE(16)
         VAL%EG=RES
      CASE(17)
         VAL%EH=RES
      CASE(18)
         VAL%EI=RES
      CASE(19)
         VAL%EJ=RES
      CASE(20)
         VAL%EK=RES
      CASE(21)
         VAL%EL=RES
      CASE(22)
         VAL%EM=RES

      ! Order 2
      CASE(23)
         VAL%E11=RES
      CASE(24)
         VAL%E22=RES
      CASE(25)
         VAL%E33=RES
      CASE(26)
         VAL%E44=RES
      CASE(27)
         VAL%E55=RES
      CASE(28)
         VAL%E66=RES
      CASE(29)
         VAL%E77=RES
      CASE(30)
         VAL%E88=RES
      CASE(31)
         VAL%E99=RES
      CASE(32)
         VAL%EAA=RES
      CASE(33)
         VAL%EBB=RES
      CASE(34)
         VAL%ECC=RES
      CASE(35)
         VAL%EDD=RES
      CASE(36)
         VAL%EEE=RES
      CASE(37)
         VAL%EFF=RES
      CASE(38)
         VAL%EGG=RES
      CASE(39)
         VAL%EHH=RES
      CASE(40)
         VAL%EII=RES
      CASE(41)
         VAL%EJJ=RES
      CASE(42)
         VAL%EKK=RES
      CASE(43)
         VAL%ELL=RES
      CASE(44)
         VAL%EMM=RES

      END SELECT
   END SUBROUTINE DONUMM22N2_SETIM_S

      SUBROUTINE DONUMM22N2_SETIM_V(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(INOUT) :: VAL(:)
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
      CASE(8)
         VAL%E8=RES
      CASE(9)
         VAL%E9=RES
      CASE(10)
         VAL%EA=RES
      CASE(11)
         VAL%EB=RES
      CASE(12)
         VAL%EC=RES
      CASE(13)
         VAL%ED=RES
      CASE(14)
         VAL%EE=RES
      CASE(15)
         VAL%EF=RES
      CASE(16)
         VAL%EG=RES
      CASE(17)
         VAL%EH=RES
      CASE(18)
         VAL%EI=RES
      CASE(19)
         VAL%EJ=RES
      CASE(20)
         VAL%EK=RES
      CASE(21)
         VAL%EL=RES
      CASE(22)
         VAL%EM=RES

      ! Order 2
      CASE(23)
         VAL%E11=RES
      CASE(24)
         VAL%E22=RES
      CASE(25)
         VAL%E33=RES
      CASE(26)
         VAL%E44=RES
      CASE(27)
         VAL%E55=RES
      CASE(28)
         VAL%E66=RES
      CASE(29)
         VAL%E77=RES
      CASE(30)
         VAL%E88=RES
      CASE(31)
         VAL%E99=RES
      CASE(32)
         VAL%EAA=RES
      CASE(33)
         VAL%EBB=RES
      CASE(34)
         VAL%ECC=RES
      CASE(35)
         VAL%EDD=RES
      CASE(36)
         VAL%EEE=RES
      CASE(37)
         VAL%EFF=RES
      CASE(38)
         VAL%EGG=RES
      CASE(39)
         VAL%EHH=RES
      CASE(40)
         VAL%EII=RES
      CASE(41)
         VAL%EJJ=RES
      CASE(42)
         VAL%EKK=RES
      CASE(43)
         VAL%ELL=RES
      CASE(44)
         VAL%EMM=RES

      END SELECT
   END SUBROUTINE DONUMM22N2_SETIM_V

      SUBROUTINE DONUMM22N2_SETIM_M(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(INOUT) :: VAL(:,:)
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
      CASE(8)
         VAL%E8=RES
      CASE(9)
         VAL%E9=RES
      CASE(10)
         VAL%EA=RES
      CASE(11)
         VAL%EB=RES
      CASE(12)
         VAL%EC=RES
      CASE(13)
         VAL%ED=RES
      CASE(14)
         VAL%EE=RES
      CASE(15)
         VAL%EF=RES
      CASE(16)
         VAL%EG=RES
      CASE(17)
         VAL%EH=RES
      CASE(18)
         VAL%EI=RES
      CASE(19)
         VAL%EJ=RES
      CASE(20)
         VAL%EK=RES
      CASE(21)
         VAL%EL=RES
      CASE(22)
         VAL%EM=RES

      ! Order 2
      CASE(23)
         VAL%E11=RES
      CASE(24)
         VAL%E22=RES
      CASE(25)
         VAL%E33=RES
      CASE(26)
         VAL%E44=RES
      CASE(27)
         VAL%E55=RES
      CASE(28)
         VAL%E66=RES
      CASE(29)
         VAL%E77=RES
      CASE(30)
         VAL%E88=RES
      CASE(31)
         VAL%E99=RES
      CASE(32)
         VAL%EAA=RES
      CASE(33)
         VAL%EBB=RES
      CASE(34)
         VAL%ECC=RES
      CASE(35)
         VAL%EDD=RES
      CASE(36)
         VAL%EEE=RES
      CASE(37)
         VAL%EFF=RES
      CASE(38)
         VAL%EGG=RES
      CASE(39)
         VAL%EHH=RES
      CASE(40)
         VAL%EII=RES
      CASE(41)
         VAL%EJJ=RES
      CASE(42)
         VAL%EKK=RES
      CASE(43)
         VAL%ELL=RES
      CASE(44)
         VAL%EMM=RES

      END SELECT
   END SUBROUTINE DONUMM22N2_SETIM_M

FUNCTION DONUMM22N2_GETIM_S(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: VAL
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
      CASE(8)
         RES=VAL%E8
      CASE(9)
         RES=VAL%E9
      CASE(10)
         RES=VAL%EA
      CASE(11)
         RES=VAL%EB
      CASE(12)
         RES=VAL%EC
      CASE(13)
         RES=VAL%ED
      CASE(14)
         RES=VAL%EE
      CASE(15)
         RES=VAL%EF
      CASE(16)
         RES=VAL%EG
      CASE(17)
         RES=VAL%EH
      CASE(18)
         RES=VAL%EI
      CASE(19)
         RES=VAL%EJ
      CASE(20)
         RES=VAL%EK
      CASE(21)
         RES=VAL%EL
      CASE(22)
         RES=VAL%EM

      ! Order 2
      CASE(23)
         RES=VAL%E11
      CASE(24)
         RES=VAL%E22
      CASE(25)
         RES=VAL%E33
      CASE(26)
         RES=VAL%E44
      CASE(27)
         RES=VAL%E55
      CASE(28)
         RES=VAL%E66
      CASE(29)
         RES=VAL%E77
      CASE(30)
         RES=VAL%E88
      CASE(31)
         RES=VAL%E99
      CASE(32)
         RES=VAL%EAA
      CASE(33)
         RES=VAL%EBB
      CASE(34)
         RES=VAL%ECC
      CASE(35)
         RES=VAL%EDD
      CASE(36)
         RES=VAL%EEE
      CASE(37)
         RES=VAL%EFF
      CASE(38)
         RES=VAL%EGG
      CASE(39)
         RES=VAL%EHH
      CASE(40)
         RES=VAL%EII
      CASE(41)
         RES=VAL%EJJ
      CASE(42)
         RES=VAL%EKK
      CASE(43)
         RES=VAL%ELL
      CASE(44)
         RES=VAL%EMM

      END SELECT
   END FUNCTION DONUMM22N2_GETIM_S

FUNCTION DONUMM22N2_GETIM_V(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: VAL(:)
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
      CASE(8)
         RES=VAL%E8
      CASE(9)
         RES=VAL%E9
      CASE(10)
         RES=VAL%EA
      CASE(11)
         RES=VAL%EB
      CASE(12)
         RES=VAL%EC
      CASE(13)
         RES=VAL%ED
      CASE(14)
         RES=VAL%EE
      CASE(15)
         RES=VAL%EF
      CASE(16)
         RES=VAL%EG
      CASE(17)
         RES=VAL%EH
      CASE(18)
         RES=VAL%EI
      CASE(19)
         RES=VAL%EJ
      CASE(20)
         RES=VAL%EK
      CASE(21)
         RES=VAL%EL
      CASE(22)
         RES=VAL%EM

      ! Order 2
      CASE(23)
         RES=VAL%E11
      CASE(24)
         RES=VAL%E22
      CASE(25)
         RES=VAL%E33
      CASE(26)
         RES=VAL%E44
      CASE(27)
         RES=VAL%E55
      CASE(28)
         RES=VAL%E66
      CASE(29)
         RES=VAL%E77
      CASE(30)
         RES=VAL%E88
      CASE(31)
         RES=VAL%E99
      CASE(32)
         RES=VAL%EAA
      CASE(33)
         RES=VAL%EBB
      CASE(34)
         RES=VAL%ECC
      CASE(35)
         RES=VAL%EDD
      CASE(36)
         RES=VAL%EEE
      CASE(37)
         RES=VAL%EFF
      CASE(38)
         RES=VAL%EGG
      CASE(39)
         RES=VAL%EHH
      CASE(40)
         RES=VAL%EII
      CASE(41)
         RES=VAL%EJJ
      CASE(42)
         RES=VAL%EKK
      CASE(43)
         RES=VAL%ELL
      CASE(44)
         RES=VAL%EMM

      END SELECT
   END FUNCTION DONUMM22N2_GETIM_V

FUNCTION DONUMM22N2_GETIM_M(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: VAL(:,:)
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
      CASE(8)
         RES=VAL%E8
      CASE(9)
         RES=VAL%E9
      CASE(10)
         RES=VAL%EA
      CASE(11)
         RES=VAL%EB
      CASE(12)
         RES=VAL%EC
      CASE(13)
         RES=VAL%ED
      CASE(14)
         RES=VAL%EE
      CASE(15)
         RES=VAL%EF
      CASE(16)
         RES=VAL%EG
      CASE(17)
         RES=VAL%EH
      CASE(18)
         RES=VAL%EI
      CASE(19)
         RES=VAL%EJ
      CASE(20)
         RES=VAL%EK
      CASE(21)
         RES=VAL%EL
      CASE(22)
         RES=VAL%EM

      ! Order 2
      CASE(23)
         RES=VAL%E11
      CASE(24)
         RES=VAL%E22
      CASE(25)
         RES=VAL%E33
      CASE(26)
         RES=VAL%E44
      CASE(27)
         RES=VAL%E55
      CASE(28)
         RES=VAL%E66
      CASE(29)
         RES=VAL%E77
      CASE(30)
         RES=VAL%E88
      CASE(31)
         RES=VAL%E99
      CASE(32)
         RES=VAL%EAA
      CASE(33)
         RES=VAL%EBB
      CASE(34)
         RES=VAL%ECC
      CASE(35)
         RES=VAL%EDD
      CASE(36)
         RES=VAL%EEE
      CASE(37)
         RES=VAL%EFF
      CASE(38)
         RES=VAL%EGG
      CASE(39)
         RES=VAL%EHH
      CASE(40)
         RES=VAL%EII
      CASE(41)
         RES=VAL%EJJ
      CASE(42)
         RES=VAL%EKK
      CASE(43)
         RES=VAL%ELL
      CASE(44)
         RES=VAL%EMM

      END SELECT
   END FUNCTION DONUMM22N2_GETIM_M

   SUBROUTINE DONUMM22N2_PPRINT_S(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: VAR
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
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E8 * '
      CALL PPRINT(VAR%E8,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E9 * '
      CALL PPRINT(VAR%E9,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EA * '
      CALL PPRINT(VAR%EA,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EB * '
      CALL PPRINT(VAR%EB,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EC * '
      CALL PPRINT(VAR%EC,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'ED * '
      CALL PPRINT(VAR%ED,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EE * '
      CALL PPRINT(VAR%EE,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EF * '
      CALL PPRINT(VAR%EF,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EG * '
      CALL PPRINT(VAR%EG,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EH * '
      CALL PPRINT(VAR%EH,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EI * '
      CALL PPRINT(VAR%EI,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EJ * '
      CALL PPRINT(VAR%EJ,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EK * '
      CALL PPRINT(VAR%EK,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EL * '
      CALL PPRINT(VAR%EL,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EM * '
      CALL PPRINT(VAR%EM,unit=unt,fmt=output_format)

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
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E88 * '
      CALL PPRINT(VAR%E88,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E99 * '
      CALL PPRINT(VAR%E99,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EAA * '
      CALL PPRINT(VAR%EAA,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EBB * '
      CALL PPRINT(VAR%EBB,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'ECC * '
      CALL PPRINT(VAR%ECC,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EDD * '
      CALL PPRINT(VAR%EDD,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EEE * '
      CALL PPRINT(VAR%EEE,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EFF * '
      CALL PPRINT(VAR%EFF,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EGG * '
      CALL PPRINT(VAR%EGG,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EHH * '
      CALL PPRINT(VAR%EHH,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EII * '
      CALL PPRINT(VAR%EII,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EJJ * '
      CALL PPRINT(VAR%EJJ,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EKK * '
      CALL PPRINT(VAR%EKK,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'ELL * '
      CALL PPRINT(VAR%ELL,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EMM * '
      CALL PPRINT(VAR%EMM,unit=unt,fmt=output_format)


   END SUBROUTINE DONUMM22N2_PPRINT_S

   SUBROUTINE DONUMM22N2_PPRINT_V(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: VAR(:)
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
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E8 * '
      CALL PPRINT(VAR%E8,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E9 * '
      CALL PPRINT(VAR%E9,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EA * '
      CALL PPRINT(VAR%EA,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EB * '
      CALL PPRINT(VAR%EB,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EC * '
      CALL PPRINT(VAR%EC,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ED * '
      CALL PPRINT(VAR%ED,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EE * '
      CALL PPRINT(VAR%EE,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EF * '
      CALL PPRINT(VAR%EF,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EG * '
      CALL PPRINT(VAR%EG,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EH * '
      CALL PPRINT(VAR%EH,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EI * '
      CALL PPRINT(VAR%EI,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EJ * '
      CALL PPRINT(VAR%EJ,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EK * '
      CALL PPRINT(VAR%EK,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EL * '
      CALL PPRINT(VAR%EL,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EM * '
      CALL PPRINT(VAR%EM,unit=unt,fmt=output_format)

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
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E88 * '
      CALL PPRINT(VAR%E88,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E99 * '
      CALL PPRINT(VAR%E99,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EAA * '
      CALL PPRINT(VAR%EAA,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EBB * '
      CALL PPRINT(VAR%EBB,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ECC * '
      CALL PPRINT(VAR%ECC,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EDD * '
      CALL PPRINT(VAR%EDD,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EEE * '
      CALL PPRINT(VAR%EEE,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EFF * '
      CALL PPRINT(VAR%EFF,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EGG * '
      CALL PPRINT(VAR%EGG,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EHH * '
      CALL PPRINT(VAR%EHH,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EII * '
      CALL PPRINT(VAR%EII,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EJJ * '
      CALL PPRINT(VAR%EJJ,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EKK * '
      CALL PPRINT(VAR%EKK,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ELL * '
      CALL PPRINT(VAR%ELL,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EMM * '
      CALL PPRINT(VAR%EMM,unit=unt,fmt=output_format)


   END SUBROUTINE DONUMM22N2_PPRINT_V

   SUBROUTINE DONUMM22N2_PPRINT_M(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: VAR(:,:)
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
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E8 * '
      CALL PPRINT(VAR%E8,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E9 * '
      CALL PPRINT(VAR%E9,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EA * '
      CALL PPRINT(VAR%EA,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EB * '
      CALL PPRINT(VAR%EB,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EC * '
      CALL PPRINT(VAR%EC,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ED * '
      CALL PPRINT(VAR%ED,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EE * '
      CALL PPRINT(VAR%EE,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EF * '
      CALL PPRINT(VAR%EF,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EG * '
      CALL PPRINT(VAR%EG,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EH * '
      CALL PPRINT(VAR%EH,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EI * '
      CALL PPRINT(VAR%EI,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EJ * '
      CALL PPRINT(VAR%EJ,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EK * '
      CALL PPRINT(VAR%EK,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EL * '
      CALL PPRINT(VAR%EL,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EM * '
      CALL PPRINT(VAR%EM,unit=unt,fmt=output_format)

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
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E88 * '
      CALL PPRINT(VAR%E88,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E99 * '
      CALL PPRINT(VAR%E99,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EAA * '
      CALL PPRINT(VAR%EAA,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EBB * '
      CALL PPRINT(VAR%EBB,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ECC * '
      CALL PPRINT(VAR%ECC,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EDD * '
      CALL PPRINT(VAR%EDD,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EEE * '
      CALL PPRINT(VAR%EEE,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EFF * '
      CALL PPRINT(VAR%EFF,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EGG * '
      CALL PPRINT(VAR%EGG,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EHH * '
      CALL PPRINT(VAR%EHH,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EII * '
      CALL PPRINT(VAR%EII,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EJJ * '
      CALL PPRINT(VAR%EJJ,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EKK * '
      CALL PPRINT(VAR%EKK,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ELL * '
      CALL PPRINT(VAR%ELL,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EMM * '
      CALL PPRINT(VAR%EMM,unit=unt,fmt=output_format)


   END SUBROUTINE DONUMM22N2_PPRINT_M

   ELEMENTAL FUNCTION DONUMM22N2_FEVAL(X,DER0,DER1,DER2)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: FACTOR, COEF
      TYPE(DONUMM22N2), INTENT(IN)  :: X
      REAL(DP), INTENT(IN)  :: DER0,DER1,DER2
      TYPE(DONUMM22N2) :: RES
      TYPE(DONUMM22N2) :: DX, DX_P

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
      RES%E22 = RES%E22+COEF*DX_P%E22
      RES%E33 = RES%E33+COEF*DX_P%E33
      RES%E44 = RES%E44+COEF*DX_P%E44
      RES%E55 = RES%E55+COEF*DX_P%E55
      RES%E66 = RES%E66+COEF*DX_P%E66
      RES%E77 = RES%E77+COEF*DX_P%E77
      RES%E88 = RES%E88+COEF*DX_P%E88
      RES%E99 = RES%E99+COEF*DX_P%E99
      RES%EAA = RES%EAA+COEF*DX_P%EAA
      RES%EBB = RES%EBB+COEF*DX_P%EBB
      RES%ECC = RES%ECC+COEF*DX_P%ECC
      RES%EDD = RES%EDD+COEF*DX_P%EDD
      RES%EEE = RES%EEE+COEF*DX_P%EEE
      RES%EFF = RES%EFF+COEF*DX_P%EFF
      RES%EGG = RES%EGG+COEF*DX_P%EGG
      RES%EHH = RES%EHH+COEF*DX_P%EHH
      RES%EII = RES%EII+COEF*DX_P%EII
      RES%EJJ = RES%EJJ+COEF*DX_P%EJJ
      RES%EKK = RES%EKK+COEF*DX_P%EKK
      RES%ELL = RES%ELL+COEF*DX_P%ELL
      RES%EMM = RES%EMM+COEF*DX_P%EMM
      ! Order 1
      RES%E1 = RES%E1+COEF*DX_P%E1
      RES%E2 = RES%E2+COEF*DX_P%E2
      RES%E3 = RES%E3+COEF*DX_P%E3
      RES%E4 = RES%E4+COEF*DX_P%E4
      RES%E5 = RES%E5+COEF*DX_P%E5
      RES%E6 = RES%E6+COEF*DX_P%E6
      RES%E7 = RES%E7+COEF*DX_P%E7
      RES%E8 = RES%E8+COEF*DX_P%E8
      RES%E9 = RES%E9+COEF*DX_P%E9
      RES%EA = RES%EA+COEF*DX_P%EA
      RES%EB = RES%EB+COEF*DX_P%EB
      RES%EC = RES%EC+COEF*DX_P%EC
      RES%ED = RES%ED+COEF*DX_P%ED
      RES%EE = RES%EE+COEF*DX_P%EE
      RES%EF = RES%EF+COEF*DX_P%EF
      RES%EG = RES%EG+COEF*DX_P%EG
      RES%EH = RES%EH+COEF*DX_P%EH
      RES%EI = RES%EI+COEF*DX_P%EI
      RES%EJ = RES%EJ+COEF*DX_P%EJ
      RES%EK = RES%EK+COEF*DX_P%EK
      RES%EL = RES%EL+COEF*DX_P%EL
      RES%EM = RES%EM+COEF*DX_P%EM
      ! DX_P = DX_P * DX
      ! Order 2
      DX_P%E11 = DX_P%E1*DX%E1
      DX_P%E22 = DX_P%E2*DX%E2
      DX_P%E33 = DX_P%E3*DX%E3
      DX_P%E44 = DX_P%E4*DX%E4
      DX_P%E55 = DX_P%E5*DX%E5
      DX_P%E66 = DX_P%E6*DX%E6
      DX_P%E77 = DX_P%E7*DX%E7
      DX_P%E88 = DX_P%E8*DX%E8
      DX_P%E99 = DX_P%E9*DX%E9
      DX_P%EAA = DX_P%EA*DX%EA
      DX_P%EBB = DX_P%EB*DX%EB
      DX_P%ECC = DX_P%EC*DX%EC
      DX_P%EDD = DX_P%ED*DX%ED
      DX_P%EEE = DX_P%EE*DX%EE
      DX_P%EFF = DX_P%EF*DX%EF
      DX_P%EGG = DX_P%EG*DX%EG
      DX_P%EHH = DX_P%EH*DX%EH
      DX_P%EII = DX_P%EI*DX%EI
      DX_P%EJJ = DX_P%EJ*DX%EJ
      DX_P%EKK = DX_P%EK*DX%EK
      DX_P%ELL = DX_P%EL*DX%EL
      DX_P%EMM = DX_P%EM*DX%EM
      
      ! Sets order 2
      FACTOR = FACTOR * 2
      COEF = DER2 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 2
      RES%E11 = RES%E11+COEF*DX_P%E11
      RES%E22 = RES%E22+COEF*DX_P%E22
      RES%E33 = RES%E33+COEF*DX_P%E33
      RES%E44 = RES%E44+COEF*DX_P%E44
      RES%E55 = RES%E55+COEF*DX_P%E55
      RES%E66 = RES%E66+COEF*DX_P%E66
      RES%E77 = RES%E77+COEF*DX_P%E77
      RES%E88 = RES%E88+COEF*DX_P%E88
      RES%E99 = RES%E99+COEF*DX_P%E99
      RES%EAA = RES%EAA+COEF*DX_P%EAA
      RES%EBB = RES%EBB+COEF*DX_P%EBB
      RES%ECC = RES%ECC+COEF*DX_P%ECC
      RES%EDD = RES%EDD+COEF*DX_P%EDD
      RES%EEE = RES%EEE+COEF*DX_P%EEE
      RES%EFF = RES%EFF+COEF*DX_P%EFF
      RES%EGG = RES%EGG+COEF*DX_P%EGG
      RES%EHH = RES%EHH+COEF*DX_P%EHH
      RES%EII = RES%EII+COEF*DX_P%EII
      RES%EJJ = RES%EJJ+COEF*DX_P%EJJ
      RES%EKK = RES%EKK+COEF*DX_P%EKK
      RES%ELL = RES%ELL+COEF*DX_P%ELL
      RES%EMM = RES%EMM+COEF*DX_P%EMM
      
   END FUNCTION DONUMM22N2_FEVAL


  ! SUBROUTINE DONUMM22N2_PPRINT_M_R(X, FMT)
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

  ! END SUBROUTINE DONUMM22N2_PPRINT_M_R

  ! SUBROUTINE DONUMM22N2_PPRINT_V_R(X, FMT)
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

  ! END SUBROUTINE DONUMM22N2_PPRINT_V_R

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
  PURE FUNCTION DONUMM22N2_det2x2(A) RESULT(det)

    IMPLICIT NONE

    TYPE(DONUMM22N2), INTENT(IN) :: A(2,2)   !! Matrix
    TYPE(DONUMM22N2)             :: det

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
  PURE FUNCTION DONUMM22N2_det3x3(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(DONUMM22N2), INTENT(IN) :: A(3,3)   !! Matrix
    TYPE(DONUMM22N2)             :: det

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
  PURE FUNCTION DONUMM22N2_det4x4(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(DONUMM22N2), INTENT(IN) :: A(4,4)   !! Matrix
    TYPE(DONUMM22N2)             :: det

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
  PURE FUNCTION DONUMM22N2_cross3(a,b) RESULT(v)
      
    IMPLICIT NONE 

    TYPE(DONUMM22N2), DIMENSION (3),INTENT(IN) :: a,b
    TYPE(DONUMM22N2), DIMENSION (3) :: v
    
    v(1) = a(2) * b(3) - a(3) * b(2)
    v(2) = a(3) * b(1) - a(1) * b(3)
    v(3) = a(1) * b(2) - a(2) * b(1)

  END FUNCTION DONUMM22N2_cross3
  !===================================================================================================! 

  !***************************************************************************************************! 
  !> @brief Norm of a 3 element vector. # There is an intrinsic function named norm2.
  !!
  !! @param[in] a: Vector of 3 reals (rank 1).
  !! @param[in] b: Vector of 3 reals (rank 1).
  !!
  !***************************************************************************************************!
  FUNCTION DONUMM22N2_norm2_3(v) RESULT(n)
     
    IMPLICIT NONE 

    TYPE(DONUMM22N2), INTENT(IN) :: v(3)
    TYPE(DONUMM22N2) :: n
     
    n = SQRT( v(1)*v(1) + v(2)*v(2) + v(3)*v(3) )

  END FUNCTION DONUMM22N2_norm2_3
  !===================================================================================================! 

  ELEMENTAL FUNCTION DONUMM22N2_DIVISION_OO(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(DONUMM22N2), INTENT(IN) :: X
      TYPE(DONUMM22N2), INTENT(IN) :: Y
      TYPE(DONUMM22N2) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION DONUMM22N2_DIVISION_OO

  ELEMENTAL FUNCTION DONUMM22N2_DIVISION_OR(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(DONUMM22N2), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: Y
      TYPE(DONUMM22N2) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION DONUMM22N2_DIVISION_OR

  ELEMENTAL FUNCTION DONUMM22N2_DIVISION_RO(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      REAL(DP), INTENT(IN) :: X
      TYPE(DONUMM22N2), INTENT(IN) :: Y
      TYPE(DONUMM22N2) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION DONUMM22N2_DIVISION_RO

  ELEMENTAL FUNCTION DONUMM22N2_REAL(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: X
      REAL(DP) :: RES

      RES = X%R

  END FUNCTION DONUMM22N2_REAL

  FUNCTION DONUMM22N2_SQRT(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2), INTENT(IN) :: X
      TYPE(DONUMM22N2) :: RES

      RES = X**0.5_DP

  END FUNCTION DONUMM22N2_SQRT

   ELEMENTAL FUNCTION DONUMM22N2_TAN(X) RESULT(RES)

      TYPE(DONUMM22N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(DONUMM22N2) :: RES
      
      DER0 = TAN(X%R)
      DER1 = TAN(X%R)**2 + 1
      DER2 = 2*(TAN(X%R)**2 + 1)*TAN(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION DONUMM22N2_TAN

   ELEMENTAL FUNCTION DONUMM22N2_COS(X) RESULT(RES)

      TYPE(DONUMM22N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(DONUMM22N2) :: RES
      
      DER0 = COS(X%R)
      DER1 = -SIN(X%R)
      DER2 = -COS(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION DONUMM22N2_COS

   ELEMENTAL FUNCTION DONUMM22N2_SIN(X) RESULT(RES)

      TYPE(DONUMM22N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(DONUMM22N2) :: RES
      
      DER0 = SIN(X%R)
      DER1 = COS(X%R)
      DER2 = -SIN(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION DONUMM22N2_SIN

   ELEMENTAL FUNCTION DONUMM22N2_ATAN(X) RESULT(RES)

      TYPE(DONUMM22N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(DONUMM22N2) :: RES
      
      DER0 = ATAN(X%R)
      DER1 = 1D0/(X%R**2 + 1)
      DER2 = -2*X%R/(X%R**2 + 1)**2

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION DONUMM22N2_ATAN

   ELEMENTAL FUNCTION DONUMM22N2_ACOS(X) RESULT(RES)

      TYPE(DONUMM22N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(DONUMM22N2) :: RES
      
      DER0 = ACOS(X%R)
      DER1 = -1/SQRT(1 - X%R**2)
      DER2 = -X%R/(1 - X%R**2)**(3.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION DONUMM22N2_ACOS

   ELEMENTAL FUNCTION DONUMM22N2_ASIN(X) RESULT(RES)

      TYPE(DONUMM22N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(DONUMM22N2) :: RES
      
      DER0 = ASIN(X%R)
      DER1 = 1/SQRT(1 - X%R**2)
      DER2 = X%R/(1 - X%R**2)**(3.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION DONUMM22N2_ASIN

   ELEMENTAL FUNCTION DONUMM22N2_TANH(X) RESULT(RES)

      TYPE(DONUMM22N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(DONUMM22N2) :: RES
      
      DER0 = TANH(X%R)
      DER1 = 1 - TANH(X%R)**2
      DER2 = 2*(TANH(X%R)**2 - 1)*TANH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION DONUMM22N2_TANH

   ELEMENTAL FUNCTION DONUMM22N2_COSH(X) RESULT(RES)

      TYPE(DONUMM22N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(DONUMM22N2) :: RES
      
      DER0 = COSH(X%R)
      DER1 = SINH(X%R)
      DER2 = COSH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION DONUMM22N2_COSH

   ELEMENTAL FUNCTION DONUMM22N2_SINH(X) RESULT(RES)

      TYPE(DONUMM22N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(DONUMM22N2) :: RES
      
      DER0 = SINH(X%R)
      DER1 = COSH(X%R)
      DER2 = SINH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION DONUMM22N2_SINH

   ELEMENTAL FUNCTION DONUMM22N2_EXP(X) RESULT(RES)

      TYPE(DONUMM22N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(DONUMM22N2) :: RES
      
      DER0 = EXP(X%R)
      DER1 = EXP(X%R)
      DER2 = EXP(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION DONUMM22N2_EXP

   ELEMENTAL FUNCTION DONUMM22N2_LOG(X) RESULT(RES)

      TYPE(DONUMM22N2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(DONUMM22N2) :: RES
      
      DER0 = LOG(X%R)
      DER1 = 1D0/X%R
      DER2 = -1/X%R**2

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION DONUMM22N2_LOG

   ELEMENTAL FUNCTION DONUMM22N2_POW_OR(X,E) RESULT(RES)

      TYPE(DONUMM22N2), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2
      TYPE(DONUMM22N2) :: RES
      
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

   END FUNCTION DONUMM22N2_POW_OR

   ELEMENTAL FUNCTION DONUMM22N2_POW_RO(E,X) RESULT(RES)

      TYPE(DONUMM22N2), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2
      TYPE(DONUMM22N2) :: RES
      
      
      DER0 = E**X%R
      DER1 = E**X%R*LOG(E)
      DER2 = E**X%R*LOG(E)**2

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION DONUMM22N2_POW_RO

   ELEMENTAL FUNCTION DONUMM22N2_F2EVAL(X,Y,DER0_0,DER1_0,DER1_1, &
                                    DER2_0,DER2_1,DER2_2)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: COEF, DELTA
      TYPE(DONUMM22N2), INTENT(IN)  :: X,Y
      REAL(DP), INTENT(IN)  :: DER0_0,DER1_0,DER1_1, &
                               DER2_0,DER2_1,DER2_2
      TYPE(DONUMM22N2) :: RES
      TYPE(DONUMM22N2) :: DX, DY

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

      

   END FUNCTION DONUMM22N2_F2EVAL


   ELEMENTAL FUNCTION DONUMM22N2_POW_OO(X,Y) RESULT(RES)

      TYPE(DONUMM22N2), INTENT(IN) :: X, Y
      REAL(DP) :: DER0_0,DER1_0,DER1_1,DER2_0,DER2_1,DER2_2
      TYPE(DONUMM22N2) :: RES
      
      DER0_0 = X%R**Y%R
      DER1_0 = X%R**Y%R*Y%R/X%R
      DER1_1 = X%R**Y%R*LOG(X%R)
      DER2_0 = X%R**Y%R*Y%R*(Y%R - 1)/X%R**2
      DER2_1 = X%R**Y%R*(Y%R*LOG(X%R) + 1)/X%R
      DER2_2 = X%R**Y%R*LOG(X%R)**2

      RES = F2EVAL(X,Y,DER0_0,DER1_0,DER1_1,DER2_0,DER2_1,DER2_2)

   END FUNCTION DONUMM22N2_POW_OO


   FUNCTION DONUMM22N2_INV2X2(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2) , INTENT(IN) :: A(2,2) 
      TYPE(DONUMM22N2) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(DONUMM22N2) :: RES(SIZE(A,1),SIZE(A,2)) 

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
      RES%E8=-MATMUL(RES%R,(MATMUL(A%E8,RES%R)))
      RES%E9=-MATMUL(RES%R,(MATMUL(A%E9,RES%R)))
      RES%EA=-MATMUL(RES%R,(MATMUL(A%EA,RES%R)))
      RES%EB=-MATMUL(RES%R,(MATMUL(A%EB,RES%R)))
      RES%EC=-MATMUL(RES%R,(MATMUL(A%EC,RES%R)))
      RES%ED=-MATMUL(RES%R,(MATMUL(A%ED,RES%R)))
      RES%EE=-MATMUL(RES%R,(MATMUL(A%EE,RES%R)))
      RES%EF=-MATMUL(RES%R,(MATMUL(A%EF,RES%R)))
      RES%EG=-MATMUL(RES%R,(MATMUL(A%EG,RES%R)))
      RES%EH=-MATMUL(RES%R,(MATMUL(A%EH,RES%R)))
      RES%EI=-MATMUL(RES%R,(MATMUL(A%EI,RES%R)))
      RES%EJ=-MATMUL(RES%R,(MATMUL(A%EJ,RES%R)))
      RES%EK=-MATMUL(RES%R,(MATMUL(A%EK,RES%R)))
      RES%EL=-MATMUL(RES%R,(MATMUL(A%EL,RES%R)))
      RES%EM=-MATMUL(RES%R,(MATMUL(A%EM,RES%R)))

      ! Order 2
      RES%E11=-MATMUL(RES%R,(MATMUL(A%E11,RES%R)+MATMUL(A%E1,RES%E1)))
      RES%E22=-MATMUL(RES%R,(MATMUL(A%E22,RES%R)+MATMUL(A%E2,RES%E2)))
      RES%E33=-MATMUL(RES%R,(MATMUL(A%E33,RES%R)+MATMUL(A%E3,RES%E3)))
      RES%E44=-MATMUL(RES%R,(MATMUL(A%E44,RES%R)+MATMUL(A%E4,RES%E4)))
      RES%E55=-MATMUL(RES%R,(MATMUL(A%E55,RES%R)+MATMUL(A%E5,RES%E5)))
      RES%E66=-MATMUL(RES%R,(MATMUL(A%E66,RES%R)+MATMUL(A%E6,RES%E6)))
      RES%E77=-MATMUL(RES%R,(MATMUL(A%E77,RES%R)+MATMUL(A%E7,RES%E7)))
      RES%E88=-MATMUL(RES%R,(MATMUL(A%E88,RES%R)+MATMUL(A%E8,RES%E8)))
      RES%E99=-MATMUL(RES%R,(MATMUL(A%E99,RES%R)+MATMUL(A%E9,RES%E9)))
      RES%EAA=-MATMUL(RES%R,(MATMUL(A%EAA,RES%R)+MATMUL(A%EA,RES%EA)))
      RES%EBB=-MATMUL(RES%R,(MATMUL(A%EBB,RES%R)+MATMUL(A%EB,RES%EB)))
      RES%ECC=-MATMUL(RES%R,(MATMUL(A%ECC,RES%R)+MATMUL(A%EC,RES%EC)))
      RES%EDD=-MATMUL(RES%R,(MATMUL(A%EDD,RES%R)+MATMUL(A%ED,RES%ED)))
      RES%EEE=-MATMUL(RES%R,(MATMUL(A%EEE,RES%R)+MATMUL(A%EE,RES%EE)))
      RES%EFF=-MATMUL(RES%R,(MATMUL(A%EFF,RES%R)+MATMUL(A%EF,RES%EF)))
      RES%EGG=-MATMUL(RES%R,(MATMUL(A%EGG,RES%R)+MATMUL(A%EG,RES%EG)))
      RES%EHH=-MATMUL(RES%R,(MATMUL(A%EHH,RES%R)+MATMUL(A%EH,RES%EH)))
      RES%EII=-MATMUL(RES%R,(MATMUL(A%EII,RES%R)+MATMUL(A%EI,RES%EI)))
      RES%EJJ=-MATMUL(RES%R,(MATMUL(A%EJJ,RES%R)+MATMUL(A%EJ,RES%EJ)))
      RES%EKK=-MATMUL(RES%R,(MATMUL(A%EKK,RES%R)+MATMUL(A%EK,RES%EK)))
      RES%ELL=-MATMUL(RES%R,(MATMUL(A%ELL,RES%R)+MATMUL(A%EL,RES%EL)))
      RES%EMM=-MATMUL(RES%R,(MATMUL(A%EMM,RES%R)+MATMUL(A%EM,RES%EM)))

   END FUNCTION DONUMM22N2_INV2X2

   FUNCTION DONUMM22N2_INV3X3(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2) , INTENT(IN) :: A(3,3) 
      TYPE(DONUMM22N2) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(DONUMM22N2) :: RES(SIZE(A,1),SIZE(A,2)) 

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
      RES%E8=-MATMUL(RES%R,(MATMUL(A%E8,RES%R)))
      RES%E9=-MATMUL(RES%R,(MATMUL(A%E9,RES%R)))
      RES%EA=-MATMUL(RES%R,(MATMUL(A%EA,RES%R)))
      RES%EB=-MATMUL(RES%R,(MATMUL(A%EB,RES%R)))
      RES%EC=-MATMUL(RES%R,(MATMUL(A%EC,RES%R)))
      RES%ED=-MATMUL(RES%R,(MATMUL(A%ED,RES%R)))
      RES%EE=-MATMUL(RES%R,(MATMUL(A%EE,RES%R)))
      RES%EF=-MATMUL(RES%R,(MATMUL(A%EF,RES%R)))
      RES%EG=-MATMUL(RES%R,(MATMUL(A%EG,RES%R)))
      RES%EH=-MATMUL(RES%R,(MATMUL(A%EH,RES%R)))
      RES%EI=-MATMUL(RES%R,(MATMUL(A%EI,RES%R)))
      RES%EJ=-MATMUL(RES%R,(MATMUL(A%EJ,RES%R)))
      RES%EK=-MATMUL(RES%R,(MATMUL(A%EK,RES%R)))
      RES%EL=-MATMUL(RES%R,(MATMUL(A%EL,RES%R)))
      RES%EM=-MATMUL(RES%R,(MATMUL(A%EM,RES%R)))

      ! Order 2
      RES%E11=-MATMUL(RES%R,(MATMUL(A%E11,RES%R)+MATMUL(A%E1,RES%E1)))
      RES%E22=-MATMUL(RES%R,(MATMUL(A%E22,RES%R)+MATMUL(A%E2,RES%E2)))
      RES%E33=-MATMUL(RES%R,(MATMUL(A%E33,RES%R)+MATMUL(A%E3,RES%E3)))
      RES%E44=-MATMUL(RES%R,(MATMUL(A%E44,RES%R)+MATMUL(A%E4,RES%E4)))
      RES%E55=-MATMUL(RES%R,(MATMUL(A%E55,RES%R)+MATMUL(A%E5,RES%E5)))
      RES%E66=-MATMUL(RES%R,(MATMUL(A%E66,RES%R)+MATMUL(A%E6,RES%E6)))
      RES%E77=-MATMUL(RES%R,(MATMUL(A%E77,RES%R)+MATMUL(A%E7,RES%E7)))
      RES%E88=-MATMUL(RES%R,(MATMUL(A%E88,RES%R)+MATMUL(A%E8,RES%E8)))
      RES%E99=-MATMUL(RES%R,(MATMUL(A%E99,RES%R)+MATMUL(A%E9,RES%E9)))
      RES%EAA=-MATMUL(RES%R,(MATMUL(A%EAA,RES%R)+MATMUL(A%EA,RES%EA)))
      RES%EBB=-MATMUL(RES%R,(MATMUL(A%EBB,RES%R)+MATMUL(A%EB,RES%EB)))
      RES%ECC=-MATMUL(RES%R,(MATMUL(A%ECC,RES%R)+MATMUL(A%EC,RES%EC)))
      RES%EDD=-MATMUL(RES%R,(MATMUL(A%EDD,RES%R)+MATMUL(A%ED,RES%ED)))
      RES%EEE=-MATMUL(RES%R,(MATMUL(A%EEE,RES%R)+MATMUL(A%EE,RES%EE)))
      RES%EFF=-MATMUL(RES%R,(MATMUL(A%EFF,RES%R)+MATMUL(A%EF,RES%EF)))
      RES%EGG=-MATMUL(RES%R,(MATMUL(A%EGG,RES%R)+MATMUL(A%EG,RES%EG)))
      RES%EHH=-MATMUL(RES%R,(MATMUL(A%EHH,RES%R)+MATMUL(A%EH,RES%EH)))
      RES%EII=-MATMUL(RES%R,(MATMUL(A%EII,RES%R)+MATMUL(A%EI,RES%EI)))
      RES%EJJ=-MATMUL(RES%R,(MATMUL(A%EJJ,RES%R)+MATMUL(A%EJ,RES%EJ)))
      RES%EKK=-MATMUL(RES%R,(MATMUL(A%EKK,RES%R)+MATMUL(A%EK,RES%EK)))
      RES%ELL=-MATMUL(RES%R,(MATMUL(A%ELL,RES%R)+MATMUL(A%EL,RES%EL)))
      RES%EMM=-MATMUL(RES%R,(MATMUL(A%EMM,RES%R)+MATMUL(A%EM,RES%EM)))

   END FUNCTION DONUMM22N2_INV3X3

   FUNCTION DONUMM22N2_INV4X4(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N2) , INTENT(IN) :: A(4,4) 
      TYPE(DONUMM22N2) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(DONUMM22N2) :: RES(SIZE(A,1),SIZE(A,2)) 

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
      RES%E8=-MATMUL(RES%R,(MATMUL(A%E8,RES%R)))
      RES%E9=-MATMUL(RES%R,(MATMUL(A%E9,RES%R)))
      RES%EA=-MATMUL(RES%R,(MATMUL(A%EA,RES%R)))
      RES%EB=-MATMUL(RES%R,(MATMUL(A%EB,RES%R)))
      RES%EC=-MATMUL(RES%R,(MATMUL(A%EC,RES%R)))
      RES%ED=-MATMUL(RES%R,(MATMUL(A%ED,RES%R)))
      RES%EE=-MATMUL(RES%R,(MATMUL(A%EE,RES%R)))
      RES%EF=-MATMUL(RES%R,(MATMUL(A%EF,RES%R)))
      RES%EG=-MATMUL(RES%R,(MATMUL(A%EG,RES%R)))
      RES%EH=-MATMUL(RES%R,(MATMUL(A%EH,RES%R)))
      RES%EI=-MATMUL(RES%R,(MATMUL(A%EI,RES%R)))
      RES%EJ=-MATMUL(RES%R,(MATMUL(A%EJ,RES%R)))
      RES%EK=-MATMUL(RES%R,(MATMUL(A%EK,RES%R)))
      RES%EL=-MATMUL(RES%R,(MATMUL(A%EL,RES%R)))
      RES%EM=-MATMUL(RES%R,(MATMUL(A%EM,RES%R)))

      ! Order 2
      RES%E11=-MATMUL(RES%R,(MATMUL(A%E11,RES%R)+MATMUL(A%E1,RES%E1)))
      RES%E22=-MATMUL(RES%R,(MATMUL(A%E22,RES%R)+MATMUL(A%E2,RES%E2)))
      RES%E33=-MATMUL(RES%R,(MATMUL(A%E33,RES%R)+MATMUL(A%E3,RES%E3)))
      RES%E44=-MATMUL(RES%R,(MATMUL(A%E44,RES%R)+MATMUL(A%E4,RES%E4)))
      RES%E55=-MATMUL(RES%R,(MATMUL(A%E55,RES%R)+MATMUL(A%E5,RES%E5)))
      RES%E66=-MATMUL(RES%R,(MATMUL(A%E66,RES%R)+MATMUL(A%E6,RES%E6)))
      RES%E77=-MATMUL(RES%R,(MATMUL(A%E77,RES%R)+MATMUL(A%E7,RES%E7)))
      RES%E88=-MATMUL(RES%R,(MATMUL(A%E88,RES%R)+MATMUL(A%E8,RES%E8)))
      RES%E99=-MATMUL(RES%R,(MATMUL(A%E99,RES%R)+MATMUL(A%E9,RES%E9)))
      RES%EAA=-MATMUL(RES%R,(MATMUL(A%EAA,RES%R)+MATMUL(A%EA,RES%EA)))
      RES%EBB=-MATMUL(RES%R,(MATMUL(A%EBB,RES%R)+MATMUL(A%EB,RES%EB)))
      RES%ECC=-MATMUL(RES%R,(MATMUL(A%ECC,RES%R)+MATMUL(A%EC,RES%EC)))
      RES%EDD=-MATMUL(RES%R,(MATMUL(A%EDD,RES%R)+MATMUL(A%ED,RES%ED)))
      RES%EEE=-MATMUL(RES%R,(MATMUL(A%EEE,RES%R)+MATMUL(A%EE,RES%EE)))
      RES%EFF=-MATMUL(RES%R,(MATMUL(A%EFF,RES%R)+MATMUL(A%EF,RES%EF)))
      RES%EGG=-MATMUL(RES%R,(MATMUL(A%EGG,RES%R)+MATMUL(A%EG,RES%EG)))
      RES%EHH=-MATMUL(RES%R,(MATMUL(A%EHH,RES%R)+MATMUL(A%EH,RES%EH)))
      RES%EII=-MATMUL(RES%R,(MATMUL(A%EII,RES%R)+MATMUL(A%EI,RES%EI)))
      RES%EJJ=-MATMUL(RES%R,(MATMUL(A%EJJ,RES%R)+MATMUL(A%EJ,RES%EJ)))
      RES%EKK=-MATMUL(RES%R,(MATMUL(A%EKK,RES%R)+MATMUL(A%EK,RES%EK)))
      RES%ELL=-MATMUL(RES%R,(MATMUL(A%ELL,RES%R)+MATMUL(A%EL,RES%EL)))
      RES%EMM=-MATMUL(RES%R,(MATMUL(A%EMM,RES%R)+MATMUL(A%EM,RES%EM)))

   END FUNCTION DONUMM22N2_INV4X4

END MODULE diagotim22n2
