MODULE diagotim22n5

   USE master_parameters
   USE real_utils

   IMPLICIT NONE

   INTEGER, PARAMETER :: num_im_dir = 80730
   INTEGER, PARAMETER :: torder     = 5
   INTEGER, PARAMETER :: n_imdir_order(6) = [1,22,22,22,22,22]

   TYPE DONUMM22N5
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
     ! Order 3
     REAL(DP) :: E111
     REAL(DP) :: E222
     REAL(DP) :: E333
     REAL(DP) :: E444
     REAL(DP) :: E555
     REAL(DP) :: E666
     REAL(DP) :: E777
     REAL(DP) :: E888
     REAL(DP) :: E999
     REAL(DP) :: EAAA
     REAL(DP) :: EBBB
     REAL(DP) :: ECCC
     REAL(DP) :: EDDD
     REAL(DP) :: EEEE
     REAL(DP) :: EFFF
     REAL(DP) :: EGGG
     REAL(DP) :: EHHH
     REAL(DP) :: EIII
     REAL(DP) :: EJJJ
     REAL(DP) :: EKKK
     REAL(DP) :: ELLL
     REAL(DP) :: EMMM
     ! Order 4
     REAL(DP) :: E1111
     REAL(DP) :: E2222
     REAL(DP) :: E3333
     REAL(DP) :: E4444
     REAL(DP) :: E5555
     REAL(DP) :: E6666
     REAL(DP) :: E7777
     REAL(DP) :: E8888
     REAL(DP) :: E9999
     REAL(DP) :: EAAAA
     REAL(DP) :: EBBBB
     REAL(DP) :: ECCCC
     REAL(DP) :: EDDDD
     REAL(DP) :: EEEEE
     REAL(DP) :: EFFFF
     REAL(DP) :: EGGGG
     REAL(DP) :: EHHHH
     REAL(DP) :: EIIII
     REAL(DP) :: EJJJJ
     REAL(DP) :: EKKKK
     REAL(DP) :: ELLLL
     REAL(DP) :: EMMMM
     ! Order 5
     REAL(DP) :: E11111
     REAL(DP) :: E22222
     REAL(DP) :: E33333
     REAL(DP) :: E44444
     REAL(DP) :: E55555
     REAL(DP) :: E66666
     REAL(DP) :: E77777
     REAL(DP) :: E88888
     REAL(DP) :: E99999
     REAL(DP) :: EAAAAA
     REAL(DP) :: EBBBBB
     REAL(DP) :: ECCCCC
     REAL(DP) :: EDDDDD
     REAL(DP) :: EEEEEE
     REAL(DP) :: EFFFFF
     REAL(DP) :: EGGGGG
     REAL(DP) :: EHHHHH
     REAL(DP) :: EIIIII
     REAL(DP) :: EJJJJJ
     REAL(DP) :: EKKKKK
     REAL(DP) :: ELLLLL
     REAL(DP) :: EMMMMM
   END TYPE DONUMM22N5

   ! Constant imaginary directions.
   ! Order 1
   TYPE(DONUMM22N5), PARAMETER :: E1 = DONUMM22N5(0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E2 = DONUMM22N5(0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E3 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E4 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E5 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E6 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E7 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E8 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E9 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EA = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EB = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EC = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: ED = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EE = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EF = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EG = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EH = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EI = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EJ = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EK = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EL = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EM = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   ! Order 2
   TYPE(DONUMM22N5), PARAMETER :: E11 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E22 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E33 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E44 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E55 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E66 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E77 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E88 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E99 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EAA = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EBB = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: ECC = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EDD = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EEE = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EFF = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EGG = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EHH = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EII = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EJJ = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EKK = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: ELL = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EMM = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   ! Order 3
   TYPE(DONUMM22N5), PARAMETER :: E111 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E222 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E333 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E444 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E555 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E666 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E777 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E888 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E999 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EAAA = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EBBB = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: ECCC = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EDDD = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EEEE = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EFFF = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EGGG = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EHHH = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EIII = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EJJJ = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EKKK = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: ELLL = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EMMM = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   ! Order 4
   TYPE(DONUMM22N5), PARAMETER :: E1111 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E2222 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E3333 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E4444 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E5555 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E6666 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E7777 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E8888 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E9999 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EAAAA = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EBBBB = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: ECCCC = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EDDDD = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EEEEE = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EFFFF = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EGGGG = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EHHHH = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EIIII = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EJJJJ = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EKKKK = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: ELLLL = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EMMMM = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   ! Order 5
   TYPE(DONUMM22N5), PARAMETER :: E11111 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E22222 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E33333 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E44444 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E55555 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E66666 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E77777 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E88888 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: E99999 = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EAAAAA = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EBBBBB = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: ECCCCC = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EDDDDD = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EEEEEE = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EFFFFF = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EGGGGG = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EHHHHH = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EIIIII = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EJJJJJ = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EKKKKK = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: ELLLLL = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp)
   TYPE(DONUMM22N5), PARAMETER :: EMMMMM = DONUMM22N5(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp)


   INTERFACE OPERATOR(*)
      MODULE PROCEDURE DONUMM22N5_MUL_OO_SS,DONUMM22N5_MUL_RO_SS,DONUMM22N5_MUL_OR_SS,DONUMM22N5_MUL_OO_VS,&
                       DONUMM22N5_MUL_RO_VS,DONUMM22N5_MUL_OR_VS,DONUMM22N5_MUL_OO_MS,DONUMM22N5_MUL_RO_MS,&
                       DONUMM22N5_MUL_OR_MS,DONUMM22N5_MUL_OO_SV,DONUMM22N5_MUL_RO_SV,DONUMM22N5_MUL_OR_SV,&
                       DONUMM22N5_MUL_OO_SM,DONUMM22N5_MUL_RO_SM,DONUMM22N5_MUL_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(+)
      MODULE PROCEDURE DONUMM22N5_ADD_OO_SS,DONUMM22N5_ADD_RO_SS,DONUMM22N5_ADD_OR_SS,DONUMM22N5_ADD_OO_VS,&
                       DONUMM22N5_ADD_RO_VS,DONUMM22N5_ADD_OR_VS,DONUMM22N5_ADD_OO_MS,DONUMM22N5_ADD_RO_MS,&
                       DONUMM22N5_ADD_OR_MS,DONUMM22N5_ADD_OO_SV,DONUMM22N5_ADD_RO_SV,DONUMM22N5_ADD_OR_SV,&
                       DONUMM22N5_ADD_OO_SM,DONUMM22N5_ADD_RO_SM,DONUMM22N5_ADD_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(-)
      MODULE PROCEDURE DONUMM22N5_NEG,DONUMM22N5_SUB_OO_SS,DONUMM22N5_SUB_RO_SS,DONUMM22N5_SUB_OR_SS,&
                       DONUMM22N5_SUB_OO_VS,DONUMM22N5_SUB_RO_VS,DONUMM22N5_SUB_OR_VS,DONUMM22N5_SUB_OO_MS,&
                       DONUMM22N5_SUB_RO_MS,DONUMM22N5_SUB_OR_MS,DONUMM22N5_SUB_OO_SV,DONUMM22N5_SUB_RO_SV,&
                       DONUMM22N5_SUB_OR_SV,DONUMM22N5_SUB_OO_SM,DONUMM22N5_SUB_RO_SM,DONUMM22N5_SUB_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(/)
      MODULE PROCEDURE DONUMM22N5_DIVISION_OO,DONUMM22N5_DIVISION_OR,DONUMM22N5_DIVISION_RO
   END INTERFACE

   INTERFACE ASSIGNMENT(=)
      MODULE PROCEDURE DONUMM22N5_ASSIGN_R
   END INTERFACE

   INTERFACE OPERATOR(**)
      MODULE PROCEDURE DONUMM22N5_POW_OR,DONUMM22N5_POW_RO,DONUMM22N5_POW_OO
   END INTERFACE

   INTERFACE PPRINT
      MODULE PROCEDURE DONUMM22N5_PPRINT_S,DONUMM22N5_PPRINT_V,DONUMM22N5_PPRINT_M
   END INTERFACE

   INTERFACE TRANSPOSE
      MODULE PROCEDURE DONUMM22N5_TRANSPOSE
   END INTERFACE

   INTERFACE MATMUL
      MODULE PROCEDURE DONUMM22N5_MATMUL_DONUMM22N5,R_MATMUL_DONUMM22N5,DONUMM22N5_MATMUL_R
   END INTERFACE

   INTERFACE DOT_PRODUCT
      MODULE PROCEDURE DONUMM22N5_DOT_PRODUCT_DONUMM22N5,R_DOT_PRODUCT_DONUMM22N5,DONUMM22N5_DOT_PRODUCT_R
   END INTERFACE

   ! INTERFACE UNFOLD
   !    MODULE PROCEDURE DONUMM22N5_TO_CR_MAT_S,DONUMM22N5_TO_CR_MAT_V,DONUMM22N5_TO_CR_MAT_M
   ! END INTERFACE

   ! INTERFACE TO_CR
   !    MODULE PROCEDURE DONUMM22N5_TO_CR_MAT_S,DONUMM22N5_TO_CR_MAT_V,DONUMM22N5_TO_CR_MAT_M
   ! END INTERFACE

   INTERFACE SIN
      MODULE PROCEDURE DONUMM22N5_SIN
   END INTERFACE

   INTERFACE COS
      MODULE PROCEDURE DONUMM22N5_COS
   END INTERFACE

   INTERFACE TAN
      MODULE PROCEDURE DONUMM22N5_TAN
   END INTERFACE

   INTERFACE ASIN
      MODULE PROCEDURE DONUMM22N5_ASIN
   END INTERFACE

   INTERFACE ACOS
      MODULE PROCEDURE DONUMM22N5_ACOS
   END INTERFACE

   INTERFACE ATAN
      MODULE PROCEDURE DONUMM22N5_ATAN
   END INTERFACE

   INTERFACE SINH
      MODULE PROCEDURE DONUMM22N5_SINH
   END INTERFACE

   INTERFACE COSH
      MODULE PROCEDURE DONUMM22N5_COSH
   END INTERFACE

   INTERFACE TANH
      MODULE PROCEDURE DONUMM22N5_TANH
   END INTERFACE

   INTERFACE SQRT
      MODULE PROCEDURE DONUMM22N5_SQRT
   END INTERFACE

   INTERFACE LOG
      MODULE PROCEDURE DONUMM22N5_LOG
   END INTERFACE

   INTERFACE EXP
      MODULE PROCEDURE DONUMM22N5_EXP
   END INTERFACE

   INTERFACE GEM
      MODULE PROCEDURE DONUMM22N5_GEM_OOO,DONUMM22N5_GEM_ROO,DONUMM22N5_GEM_ORO
   END INTERFACE

   INTERFACE FEVAL
      MODULE PROCEDURE DONUMM22N5_FEVAL
   END INTERFACE

   INTERFACE F2EVAL
      MODULE PROCEDURE DONUMM22N5_F2EVAL
   END INTERFACE

   INTERFACE REAL
      MODULE PROCEDURE DONUMM22N5_REAL
   END INTERFACE

   INTERFACE DET2X2
      MODULE PROCEDURE DONUMM22N5_det2x2
   END INTERFACE

   INTERFACE DET3X3
      MODULE PROCEDURE DONUMM22N5_det3x3
   END INTERFACE

   INTERFACE DET4X4
      MODULE PROCEDURE DONUMM22N5_det4x4
   END INTERFACE

   INTERFACE INV2X2
      MODULE PROCEDURE DONUMM22N5_INV2X2
   END INTERFACE

   INTERFACE INV3X3
      MODULE PROCEDURE DONUMM22N5_INV3X3
   END INTERFACE

   INTERFACE INV4X4
      MODULE PROCEDURE DONUMM22N5_INV4X4
   END INTERFACE

   INTERFACE GETIM
      MODULE PROCEDURE DONUMM22N5_GETIM_S,DONUMM22N5_GETIM_V,DONUMM22N5_GETIM_M
   END INTERFACE

   INTERFACE SETIM
      MODULE PROCEDURE DONUMM22N5_SETIM_S,DONUMM22N5_SETIM_V,DONUMM22N5_SETIM_M
   END INTERFACE

   CONTAINS

   ELEMENTAL SUBROUTINE DONUMM22N5_ASSIGN_R(RES,LHS)
      
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS 
      TYPE(DONUMM22N5), INTENT(OUT) :: RES 

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

      ! Order 3
      RES%E111 = 0.0_dp
      RES%E222 = 0.0_dp
      RES%E333 = 0.0_dp
      RES%E444 = 0.0_dp
      RES%E555 = 0.0_dp
      RES%E666 = 0.0_dp
      RES%E777 = 0.0_dp
      RES%E888 = 0.0_dp
      RES%E999 = 0.0_dp
      RES%EAAA = 0.0_dp
      RES%EBBB = 0.0_dp
      RES%ECCC = 0.0_dp
      RES%EDDD = 0.0_dp
      RES%EEEE = 0.0_dp
      RES%EFFF = 0.0_dp
      RES%EGGG = 0.0_dp
      RES%EHHH = 0.0_dp
      RES%EIII = 0.0_dp
      RES%EJJJ = 0.0_dp
      RES%EKKK = 0.0_dp
      RES%ELLL = 0.0_dp
      RES%EMMM = 0.0_dp

      ! Order 4
      RES%E1111 = 0.0_dp
      RES%E2222 = 0.0_dp
      RES%E3333 = 0.0_dp
      RES%E4444 = 0.0_dp
      RES%E5555 = 0.0_dp
      RES%E6666 = 0.0_dp
      RES%E7777 = 0.0_dp
      RES%E8888 = 0.0_dp
      RES%E9999 = 0.0_dp
      RES%EAAAA = 0.0_dp
      RES%EBBBB = 0.0_dp
      RES%ECCCC = 0.0_dp
      RES%EDDDD = 0.0_dp
      RES%EEEEE = 0.0_dp
      RES%EFFFF = 0.0_dp
      RES%EGGGG = 0.0_dp
      RES%EHHHH = 0.0_dp
      RES%EIIII = 0.0_dp
      RES%EJJJJ = 0.0_dp
      RES%EKKKK = 0.0_dp
      RES%ELLLL = 0.0_dp
      RES%EMMMM = 0.0_dp

      ! Order 5
      RES%E11111 = 0.0_dp
      RES%E22222 = 0.0_dp
      RES%E33333 = 0.0_dp
      RES%E44444 = 0.0_dp
      RES%E55555 = 0.0_dp
      RES%E66666 = 0.0_dp
      RES%E77777 = 0.0_dp
      RES%E88888 = 0.0_dp
      RES%E99999 = 0.0_dp
      RES%EAAAAA = 0.0_dp
      RES%EBBBBB = 0.0_dp
      RES%ECCCCC = 0.0_dp
      RES%EDDDDD = 0.0_dp
      RES%EEEEEE = 0.0_dp
      RES%EFFFFF = 0.0_dp
      RES%EGGGGG = 0.0_dp
      RES%EHHHHH = 0.0_dp
      RES%EIIIII = 0.0_dp
      RES%EJJJJJ = 0.0_dp
      RES%EKKKKK = 0.0_dp
      RES%ELLLLL = 0.0_dp
      RES%EMMMMM = 0.0_dp

   END SUBROUTINE DONUMM22N5_ASSIGN_R

   ELEMENTAL FUNCTION DONUMM22N5_NEG(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS 
      TYPE(DONUMM22N5) :: RES 

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
      ! Order 3
      RES%E111 = -LHS%E111
      RES%E222 = -LHS%E222
      RES%E333 = -LHS%E333
      RES%E444 = -LHS%E444
      RES%E555 = -LHS%E555
      RES%E666 = -LHS%E666
      RES%E777 = -LHS%E777
      RES%E888 = -LHS%E888
      RES%E999 = -LHS%E999
      RES%EAAA = -LHS%EAAA
      RES%EBBB = -LHS%EBBB
      RES%ECCC = -LHS%ECCC
      RES%EDDD = -LHS%EDDD
      RES%EEEE = -LHS%EEEE
      RES%EFFF = -LHS%EFFF
      RES%EGGG = -LHS%EGGG
      RES%EHHH = -LHS%EHHH
      RES%EIII = -LHS%EIII
      RES%EJJJ = -LHS%EJJJ
      RES%EKKK = -LHS%EKKK
      RES%ELLL = -LHS%ELLL
      RES%EMMM = -LHS%EMMM
      ! Order 4
      RES%E1111 = -LHS%E1111
      RES%E2222 = -LHS%E2222
      RES%E3333 = -LHS%E3333
      RES%E4444 = -LHS%E4444
      RES%E5555 = -LHS%E5555
      RES%E6666 = -LHS%E6666
      RES%E7777 = -LHS%E7777
      RES%E8888 = -LHS%E8888
      RES%E9999 = -LHS%E9999
      RES%EAAAA = -LHS%EAAAA
      RES%EBBBB = -LHS%EBBBB
      RES%ECCCC = -LHS%ECCCC
      RES%EDDDD = -LHS%EDDDD
      RES%EEEEE = -LHS%EEEEE
      RES%EFFFF = -LHS%EFFFF
      RES%EGGGG = -LHS%EGGGG
      RES%EHHHH = -LHS%EHHHH
      RES%EIIII = -LHS%EIIII
      RES%EJJJJ = -LHS%EJJJJ
      RES%EKKKK = -LHS%EKKKK
      RES%ELLLL = -LHS%ELLLL
      RES%EMMMM = -LHS%EMMMM
      ! Order 5
      RES%E11111 = -LHS%E11111
      RES%E22222 = -LHS%E22222
      RES%E33333 = -LHS%E33333
      RES%E44444 = -LHS%E44444
      RES%E55555 = -LHS%E55555
      RES%E66666 = -LHS%E66666
      RES%E77777 = -LHS%E77777
      RES%E88888 = -LHS%E88888
      RES%E99999 = -LHS%E99999
      RES%EAAAAA = -LHS%EAAAAA
      RES%EBBBBB = -LHS%EBBBBB
      RES%ECCCCC = -LHS%ECCCCC
      RES%EDDDDD = -LHS%EDDDDD
      RES%EEEEEE = -LHS%EEEEEE
      RES%EFFFFF = -LHS%EFFFFF
      RES%EGGGGG = -LHS%EGGGGG
      RES%EHHHHH = -LHS%EHHHHH
      RES%EIIIII = -LHS%EIIIII
      RES%EJJJJJ = -LHS%EJJJJJ
      RES%EKKKKK = -LHS%EKKKKK
      RES%ELLLLL = -LHS%ELLLLL
      RES%EMMMMM = -LHS%EMMMMM

   END FUNCTION DONUMM22N5_NEG

   ELEMENTAL FUNCTION DONUMM22N5_ADD_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES 

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

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111
      RES%E222 = LHS%E222 + RHS%E222
      RES%E333 = LHS%E333 + RHS%E333
      RES%E444 = LHS%E444 + RHS%E444
      RES%E555 = LHS%E555 + RHS%E555
      RES%E666 = LHS%E666 + RHS%E666
      RES%E777 = LHS%E777 + RHS%E777
      RES%E888 = LHS%E888 + RHS%E888
      RES%E999 = LHS%E999 + RHS%E999
      RES%EAAA = LHS%EAAA + RHS%EAAA
      RES%EBBB = LHS%EBBB + RHS%EBBB
      RES%ECCC = LHS%ECCC + RHS%ECCC
      RES%EDDD = LHS%EDDD + RHS%EDDD
      RES%EEEE = LHS%EEEE + RHS%EEEE
      RES%EFFF = LHS%EFFF + RHS%EFFF
      RES%EGGG = LHS%EGGG + RHS%EGGG
      RES%EHHH = LHS%EHHH + RHS%EHHH
      RES%EIII = LHS%EIII + RHS%EIII
      RES%EJJJ = LHS%EJJJ + RHS%EJJJ
      RES%EKKK = LHS%EKKK + RHS%EKKK
      RES%ELLL = LHS%ELLL + RHS%ELLL
      RES%EMMM = LHS%EMMM + RHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111 + RHS%E1111
      RES%E2222 = LHS%E2222 + RHS%E2222
      RES%E3333 = LHS%E3333 + RHS%E3333
      RES%E4444 = LHS%E4444 + RHS%E4444
      RES%E5555 = LHS%E5555 + RHS%E5555
      RES%E6666 = LHS%E6666 + RHS%E6666
      RES%E7777 = LHS%E7777 + RHS%E7777
      RES%E8888 = LHS%E8888 + RHS%E8888
      RES%E9999 = LHS%E9999 + RHS%E9999
      RES%EAAAA = LHS%EAAAA + RHS%EAAAA
      RES%EBBBB = LHS%EBBBB + RHS%EBBBB
      RES%ECCCC = LHS%ECCCC + RHS%ECCCC
      RES%EDDDD = LHS%EDDDD + RHS%EDDDD
      RES%EEEEE = LHS%EEEEE + RHS%EEEEE
      RES%EFFFF = LHS%EFFFF + RHS%EFFFF
      RES%EGGGG = LHS%EGGGG + RHS%EGGGG
      RES%EHHHH = LHS%EHHHH + RHS%EHHHH
      RES%EIIII = LHS%EIIII + RHS%EIIII
      RES%EJJJJ = LHS%EJJJJ + RHS%EJJJJ
      RES%EKKKK = LHS%EKKKK + RHS%EKKKK
      RES%ELLLL = LHS%ELLLL + RHS%ELLLL
      RES%EMMMM = LHS%EMMMM + RHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111 + RHS%E11111
      RES%E22222 = LHS%E22222 + RHS%E22222
      RES%E33333 = LHS%E33333 + RHS%E33333
      RES%E44444 = LHS%E44444 + RHS%E44444
      RES%E55555 = LHS%E55555 + RHS%E55555
      RES%E66666 = LHS%E66666 + RHS%E66666
      RES%E77777 = LHS%E77777 + RHS%E77777
      RES%E88888 = LHS%E88888 + RHS%E88888
      RES%E99999 = LHS%E99999 + RHS%E99999
      RES%EAAAAA = LHS%EAAAAA + RHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB + RHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC + RHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD + RHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE + RHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF + RHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG + RHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH + RHS%EHHHHH
      RES%EIIIII = LHS%EIIIII + RHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ + RHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK + RHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL + RHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM + RHS%EMMMMM

   END FUNCTION DONUMM22N5_ADD_OO_SS

   ELEMENTAL FUNCTION DONUMM22N5_ADD_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES 

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

      ! Order 3
      RES%E111 =  + RHS%E111
      RES%E222 =  + RHS%E222
      RES%E333 =  + RHS%E333
      RES%E444 =  + RHS%E444
      RES%E555 =  + RHS%E555
      RES%E666 =  + RHS%E666
      RES%E777 =  + RHS%E777
      RES%E888 =  + RHS%E888
      RES%E999 =  + RHS%E999
      RES%EAAA =  + RHS%EAAA
      RES%EBBB =  + RHS%EBBB
      RES%ECCC =  + RHS%ECCC
      RES%EDDD =  + RHS%EDDD
      RES%EEEE =  + RHS%EEEE
      RES%EFFF =  + RHS%EFFF
      RES%EGGG =  + RHS%EGGG
      RES%EHHH =  + RHS%EHHH
      RES%EIII =  + RHS%EIII
      RES%EJJJ =  + RHS%EJJJ
      RES%EKKK =  + RHS%EKKK
      RES%ELLL =  + RHS%ELLL
      RES%EMMM =  + RHS%EMMM

      ! Order 4
      RES%E1111 =  + RHS%E1111
      RES%E2222 =  + RHS%E2222
      RES%E3333 =  + RHS%E3333
      RES%E4444 =  + RHS%E4444
      RES%E5555 =  + RHS%E5555
      RES%E6666 =  + RHS%E6666
      RES%E7777 =  + RHS%E7777
      RES%E8888 =  + RHS%E8888
      RES%E9999 =  + RHS%E9999
      RES%EAAAA =  + RHS%EAAAA
      RES%EBBBB =  + RHS%EBBBB
      RES%ECCCC =  + RHS%ECCCC
      RES%EDDDD =  + RHS%EDDDD
      RES%EEEEE =  + RHS%EEEEE
      RES%EFFFF =  + RHS%EFFFF
      RES%EGGGG =  + RHS%EGGGG
      RES%EHHHH =  + RHS%EHHHH
      RES%EIIII =  + RHS%EIIII
      RES%EJJJJ =  + RHS%EJJJJ
      RES%EKKKK =  + RHS%EKKKK
      RES%ELLLL =  + RHS%ELLLL
      RES%EMMMM =  + RHS%EMMMM

      ! Order 5
      RES%E11111 =  + RHS%E11111
      RES%E22222 =  + RHS%E22222
      RES%E33333 =  + RHS%E33333
      RES%E44444 =  + RHS%E44444
      RES%E55555 =  + RHS%E55555
      RES%E66666 =  + RHS%E66666
      RES%E77777 =  + RHS%E77777
      RES%E88888 =  + RHS%E88888
      RES%E99999 =  + RHS%E99999
      RES%EAAAAA =  + RHS%EAAAAA
      RES%EBBBBB =  + RHS%EBBBBB
      RES%ECCCCC =  + RHS%ECCCCC
      RES%EDDDDD =  + RHS%EDDDDD
      RES%EEEEEE =  + RHS%EEEEEE
      RES%EFFFFF =  + RHS%EFFFFF
      RES%EGGGGG =  + RHS%EGGGGG
      RES%EHHHHH =  + RHS%EHHHHH
      RES%EIIIII =  + RHS%EIIIII
      RES%EJJJJJ =  + RHS%EJJJJJ
      RES%EKKKKK =  + RHS%EKKKKK
      RES%ELLLLL =  + RHS%ELLLLL
      RES%EMMMMM =  + RHS%EMMMMM

   END FUNCTION DONUMM22N5_ADD_RO_SS

   ELEMENTAL FUNCTION DONUMM22N5_ADD_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777
      RES%E888 = LHS%E888
      RES%E999 = LHS%E999
      RES%EAAA = LHS%EAAA
      RES%EBBB = LHS%EBBB
      RES%ECCC = LHS%ECCC
      RES%EDDD = LHS%EDDD
      RES%EEEE = LHS%EEEE
      RES%EFFF = LHS%EFFF
      RES%EGGG = LHS%EGGG
      RES%EHHH = LHS%EHHH
      RES%EIII = LHS%EIII
      RES%EJJJ = LHS%EJJJ
      RES%EKKK = LHS%EKKK
      RES%ELLL = LHS%ELLL
      RES%EMMM = LHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111
      RES%E2222 = LHS%E2222
      RES%E3333 = LHS%E3333
      RES%E4444 = LHS%E4444
      RES%E5555 = LHS%E5555
      RES%E6666 = LHS%E6666
      RES%E7777 = LHS%E7777
      RES%E8888 = LHS%E8888
      RES%E9999 = LHS%E9999
      RES%EAAAA = LHS%EAAAA
      RES%EBBBB = LHS%EBBBB
      RES%ECCCC = LHS%ECCCC
      RES%EDDDD = LHS%EDDDD
      RES%EEEEE = LHS%EEEEE
      RES%EFFFF = LHS%EFFFF
      RES%EGGGG = LHS%EGGGG
      RES%EHHHH = LHS%EHHHH
      RES%EIIII = LHS%EIIII
      RES%EJJJJ = LHS%EJJJJ
      RES%EKKKK = LHS%EKKKK
      RES%ELLLL = LHS%ELLLL
      RES%EMMMM = LHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111
      RES%E22222 = LHS%E22222
      RES%E33333 = LHS%E33333
      RES%E44444 = LHS%E44444
      RES%E55555 = LHS%E55555
      RES%E66666 = LHS%E66666
      RES%E77777 = LHS%E77777
      RES%E88888 = LHS%E88888
      RES%E99999 = LHS%E99999
      RES%EAAAAA = LHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH
      RES%EIIIII = LHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM

   END FUNCTION DONUMM22N5_ADD_OR_SS

   ELEMENTAL FUNCTION DONUMM22N5_SUB_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES 

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

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111
      RES%E222 = LHS%E222 - RHS%E222
      RES%E333 = LHS%E333 - RHS%E333
      RES%E444 = LHS%E444 - RHS%E444
      RES%E555 = LHS%E555 - RHS%E555
      RES%E666 = LHS%E666 - RHS%E666
      RES%E777 = LHS%E777 - RHS%E777
      RES%E888 = LHS%E888 - RHS%E888
      RES%E999 = LHS%E999 - RHS%E999
      RES%EAAA = LHS%EAAA - RHS%EAAA
      RES%EBBB = LHS%EBBB - RHS%EBBB
      RES%ECCC = LHS%ECCC - RHS%ECCC
      RES%EDDD = LHS%EDDD - RHS%EDDD
      RES%EEEE = LHS%EEEE - RHS%EEEE
      RES%EFFF = LHS%EFFF - RHS%EFFF
      RES%EGGG = LHS%EGGG - RHS%EGGG
      RES%EHHH = LHS%EHHH - RHS%EHHH
      RES%EIII = LHS%EIII - RHS%EIII
      RES%EJJJ = LHS%EJJJ - RHS%EJJJ
      RES%EKKK = LHS%EKKK - RHS%EKKK
      RES%ELLL = LHS%ELLL - RHS%ELLL
      RES%EMMM = LHS%EMMM - RHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111 - RHS%E1111
      RES%E2222 = LHS%E2222 - RHS%E2222
      RES%E3333 = LHS%E3333 - RHS%E3333
      RES%E4444 = LHS%E4444 - RHS%E4444
      RES%E5555 = LHS%E5555 - RHS%E5555
      RES%E6666 = LHS%E6666 - RHS%E6666
      RES%E7777 = LHS%E7777 - RHS%E7777
      RES%E8888 = LHS%E8888 - RHS%E8888
      RES%E9999 = LHS%E9999 - RHS%E9999
      RES%EAAAA = LHS%EAAAA - RHS%EAAAA
      RES%EBBBB = LHS%EBBBB - RHS%EBBBB
      RES%ECCCC = LHS%ECCCC - RHS%ECCCC
      RES%EDDDD = LHS%EDDDD - RHS%EDDDD
      RES%EEEEE = LHS%EEEEE - RHS%EEEEE
      RES%EFFFF = LHS%EFFFF - RHS%EFFFF
      RES%EGGGG = LHS%EGGGG - RHS%EGGGG
      RES%EHHHH = LHS%EHHHH - RHS%EHHHH
      RES%EIIII = LHS%EIIII - RHS%EIIII
      RES%EJJJJ = LHS%EJJJJ - RHS%EJJJJ
      RES%EKKKK = LHS%EKKKK - RHS%EKKKK
      RES%ELLLL = LHS%ELLLL - RHS%ELLLL
      RES%EMMMM = LHS%EMMMM - RHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111 - RHS%E11111
      RES%E22222 = LHS%E22222 - RHS%E22222
      RES%E33333 = LHS%E33333 - RHS%E33333
      RES%E44444 = LHS%E44444 - RHS%E44444
      RES%E55555 = LHS%E55555 - RHS%E55555
      RES%E66666 = LHS%E66666 - RHS%E66666
      RES%E77777 = LHS%E77777 - RHS%E77777
      RES%E88888 = LHS%E88888 - RHS%E88888
      RES%E99999 = LHS%E99999 - RHS%E99999
      RES%EAAAAA = LHS%EAAAAA - RHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB - RHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC - RHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD - RHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE - RHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF - RHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG - RHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH - RHS%EHHHHH
      RES%EIIIII = LHS%EIIIII - RHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ - RHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK - RHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL - RHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM - RHS%EMMMMM

   END FUNCTION DONUMM22N5_SUB_OO_SS

   ELEMENTAL FUNCTION DONUMM22N5_SUB_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES 

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

      ! Order 3
      RES%E111 =  - RHS%E111
      RES%E222 =  - RHS%E222
      RES%E333 =  - RHS%E333
      RES%E444 =  - RHS%E444
      RES%E555 =  - RHS%E555
      RES%E666 =  - RHS%E666
      RES%E777 =  - RHS%E777
      RES%E888 =  - RHS%E888
      RES%E999 =  - RHS%E999
      RES%EAAA =  - RHS%EAAA
      RES%EBBB =  - RHS%EBBB
      RES%ECCC =  - RHS%ECCC
      RES%EDDD =  - RHS%EDDD
      RES%EEEE =  - RHS%EEEE
      RES%EFFF =  - RHS%EFFF
      RES%EGGG =  - RHS%EGGG
      RES%EHHH =  - RHS%EHHH
      RES%EIII =  - RHS%EIII
      RES%EJJJ =  - RHS%EJJJ
      RES%EKKK =  - RHS%EKKK
      RES%ELLL =  - RHS%ELLL
      RES%EMMM =  - RHS%EMMM

      ! Order 4
      RES%E1111 =  - RHS%E1111
      RES%E2222 =  - RHS%E2222
      RES%E3333 =  - RHS%E3333
      RES%E4444 =  - RHS%E4444
      RES%E5555 =  - RHS%E5555
      RES%E6666 =  - RHS%E6666
      RES%E7777 =  - RHS%E7777
      RES%E8888 =  - RHS%E8888
      RES%E9999 =  - RHS%E9999
      RES%EAAAA =  - RHS%EAAAA
      RES%EBBBB =  - RHS%EBBBB
      RES%ECCCC =  - RHS%ECCCC
      RES%EDDDD =  - RHS%EDDDD
      RES%EEEEE =  - RHS%EEEEE
      RES%EFFFF =  - RHS%EFFFF
      RES%EGGGG =  - RHS%EGGGG
      RES%EHHHH =  - RHS%EHHHH
      RES%EIIII =  - RHS%EIIII
      RES%EJJJJ =  - RHS%EJJJJ
      RES%EKKKK =  - RHS%EKKKK
      RES%ELLLL =  - RHS%ELLLL
      RES%EMMMM =  - RHS%EMMMM

      ! Order 5
      RES%E11111 =  - RHS%E11111
      RES%E22222 =  - RHS%E22222
      RES%E33333 =  - RHS%E33333
      RES%E44444 =  - RHS%E44444
      RES%E55555 =  - RHS%E55555
      RES%E66666 =  - RHS%E66666
      RES%E77777 =  - RHS%E77777
      RES%E88888 =  - RHS%E88888
      RES%E99999 =  - RHS%E99999
      RES%EAAAAA =  - RHS%EAAAAA
      RES%EBBBBB =  - RHS%EBBBBB
      RES%ECCCCC =  - RHS%ECCCCC
      RES%EDDDDD =  - RHS%EDDDDD
      RES%EEEEEE =  - RHS%EEEEEE
      RES%EFFFFF =  - RHS%EFFFFF
      RES%EGGGGG =  - RHS%EGGGGG
      RES%EHHHHH =  - RHS%EHHHHH
      RES%EIIIII =  - RHS%EIIIII
      RES%EJJJJJ =  - RHS%EJJJJJ
      RES%EKKKKK =  - RHS%EKKKKK
      RES%ELLLLL =  - RHS%ELLLLL
      RES%EMMMMM =  - RHS%EMMMMM

   END FUNCTION DONUMM22N5_SUB_RO_SS

   ELEMENTAL FUNCTION DONUMM22N5_SUB_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777
      RES%E888 = LHS%E888
      RES%E999 = LHS%E999
      RES%EAAA = LHS%EAAA
      RES%EBBB = LHS%EBBB
      RES%ECCC = LHS%ECCC
      RES%EDDD = LHS%EDDD
      RES%EEEE = LHS%EEEE
      RES%EFFF = LHS%EFFF
      RES%EGGG = LHS%EGGG
      RES%EHHH = LHS%EHHH
      RES%EIII = LHS%EIII
      RES%EJJJ = LHS%EJJJ
      RES%EKKK = LHS%EKKK
      RES%ELLL = LHS%ELLL
      RES%EMMM = LHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111
      RES%E2222 = LHS%E2222
      RES%E3333 = LHS%E3333
      RES%E4444 = LHS%E4444
      RES%E5555 = LHS%E5555
      RES%E6666 = LHS%E6666
      RES%E7777 = LHS%E7777
      RES%E8888 = LHS%E8888
      RES%E9999 = LHS%E9999
      RES%EAAAA = LHS%EAAAA
      RES%EBBBB = LHS%EBBBB
      RES%ECCCC = LHS%ECCCC
      RES%EDDDD = LHS%EDDDD
      RES%EEEEE = LHS%EEEEE
      RES%EFFFF = LHS%EFFFF
      RES%EGGGG = LHS%EGGGG
      RES%EHHHH = LHS%EHHHH
      RES%EIIII = LHS%EIIII
      RES%EJJJJ = LHS%EJJJJ
      RES%EKKKK = LHS%EKKKK
      RES%ELLLL = LHS%ELLLL
      RES%EMMMM = LHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111
      RES%E22222 = LHS%E22222
      RES%E33333 = LHS%E33333
      RES%E44444 = LHS%E44444
      RES%E55555 = LHS%E55555
      RES%E66666 = LHS%E66666
      RES%E77777 = LHS%E77777
      RES%E88888 = LHS%E88888
      RES%E99999 = LHS%E99999
      RES%EAAAAA = LHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH
      RES%EIIIII = LHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM

   END FUNCTION DONUMM22N5_SUB_OR_SS

   ELEMENTAL FUNCTION DONUMM22N5_MUL_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES 

      !  Multiplication like function 'LHS*RHS'
      ! Order 5
      RES%E11111 = LHS%R*RHS%E11111 + LHS%E11111*RHS%R +  &
                LHS%E1*RHS%E1111 + LHS%E1111*RHS%E1 + LHS%E11*RHS%E111 + LHS%E111*RHS%E11
      RES%E22222 = LHS%R*RHS%E22222 + LHS%E22222*RHS%R +  &
                LHS%E2*RHS%E2222 + LHS%E2222*RHS%E2 + LHS%E22*RHS%E222 + LHS%E222*RHS%E22
      RES%E33333 = LHS%R*RHS%E33333 + LHS%E33333*RHS%R +  &
                LHS%E3*RHS%E3333 + LHS%E3333*RHS%E3 + LHS%E33*RHS%E333 + LHS%E333*RHS%E33
      RES%E44444 = LHS%R*RHS%E44444 + LHS%E44444*RHS%R +  &
                LHS%E4*RHS%E4444 + LHS%E4444*RHS%E4 + LHS%E44*RHS%E444 + LHS%E444*RHS%E44
      RES%E55555 = LHS%R*RHS%E55555 + LHS%E55555*RHS%R +  &
                LHS%E5*RHS%E5555 + LHS%E5555*RHS%E5 + LHS%E55*RHS%E555 + LHS%E555*RHS%E55
      RES%E66666 = LHS%R*RHS%E66666 + LHS%E66666*RHS%R +  &
                LHS%E6*RHS%E6666 + LHS%E6666*RHS%E6 + LHS%E66*RHS%E666 + LHS%E666*RHS%E66
      RES%E77777 = LHS%R*RHS%E77777 + LHS%E77777*RHS%R +  &
                LHS%E7*RHS%E7777 + LHS%E7777*RHS%E7 + LHS%E77*RHS%E777 + LHS%E777*RHS%E77
      RES%E88888 = LHS%R*RHS%E88888 + LHS%E88888*RHS%R +  &
                LHS%E8*RHS%E8888 + LHS%E8888*RHS%E8 + LHS%E88*RHS%E888 + LHS%E888*RHS%E88
      RES%E99999 = LHS%R*RHS%E99999 + LHS%E99999*RHS%R +  &
                LHS%E9*RHS%E9999 + LHS%E9999*RHS%E9 + LHS%E99*RHS%E999 + LHS%E999*RHS%E99
      RES%EAAAAA = LHS%R*RHS%EAAAAA + LHS%EAAAAA*RHS%R +  &
                LHS%EA*RHS%EAAAA + LHS%EAAAA*RHS%EA + LHS%EAA*RHS%EAAA + LHS%EAAA*RHS%EAA
      RES%EBBBBB = LHS%R*RHS%EBBBBB + LHS%EBBBBB*RHS%R +  &
                LHS%EB*RHS%EBBBB + LHS%EBBBB*RHS%EB + LHS%EBB*RHS%EBBB + LHS%EBBB*RHS%EBB
      RES%ECCCCC = LHS%R*RHS%ECCCCC + LHS%ECCCCC*RHS%R +  &
                LHS%EC*RHS%ECCCC + LHS%ECCCC*RHS%EC + LHS%ECC*RHS%ECCC + LHS%ECCC*RHS%ECC
      RES%EDDDDD = LHS%R*RHS%EDDDDD + LHS%EDDDDD*RHS%R +  &
                LHS%ED*RHS%EDDDD + LHS%EDDDD*RHS%ED + LHS%EDD*RHS%EDDD + LHS%EDDD*RHS%EDD
      RES%EEEEEE = LHS%R*RHS%EEEEEE + LHS%EEEEEE*RHS%R +  &
                LHS%EE*RHS%EEEEE + LHS%EEEEE*RHS%EE + LHS%EEE*RHS%EEEE + LHS%EEEE*RHS%EEE
      RES%EFFFFF = LHS%R*RHS%EFFFFF + LHS%EFFFFF*RHS%R +  &
                LHS%EF*RHS%EFFFF + LHS%EFFFF*RHS%EF + LHS%EFF*RHS%EFFF + LHS%EFFF*RHS%EFF
      RES%EGGGGG = LHS%R*RHS%EGGGGG + LHS%EGGGGG*RHS%R +  &
                LHS%EG*RHS%EGGGG + LHS%EGGGG*RHS%EG + LHS%EGG*RHS%EGGG + LHS%EGGG*RHS%EGG
      RES%EHHHHH = LHS%R*RHS%EHHHHH + LHS%EHHHHH*RHS%R +  &
                LHS%EH*RHS%EHHHH + LHS%EHHHH*RHS%EH + LHS%EHH*RHS%EHHH + LHS%EHHH*RHS%EHH
      RES%EIIIII = LHS%R*RHS%EIIIII + LHS%EIIIII*RHS%R +  &
                LHS%EI*RHS%EIIII + LHS%EIIII*RHS%EI + LHS%EII*RHS%EIII + LHS%EIII*RHS%EII
      RES%EJJJJJ = LHS%R*RHS%EJJJJJ + LHS%EJJJJJ*RHS%R +  &
                LHS%EJ*RHS%EJJJJ + LHS%EJJJJ*RHS%EJ + LHS%EJJ*RHS%EJJJ + LHS%EJJJ*RHS%EJJ
      RES%EKKKKK = LHS%R*RHS%EKKKKK + LHS%EKKKKK*RHS%R +  &
                LHS%EK*RHS%EKKKK + LHS%EKKKK*RHS%EK + LHS%EKK*RHS%EKKK + LHS%EKKK*RHS%EKK
      RES%ELLLLL = LHS%R*RHS%ELLLLL + LHS%ELLLLL*RHS%R +  &
                LHS%EL*RHS%ELLLL + LHS%ELLLL*RHS%EL + LHS%ELL*RHS%ELLL + LHS%ELLL*RHS%ELL
      RES%EMMMMM = LHS%R*RHS%EMMMMM + LHS%EMMMMM*RHS%R +  &
                LHS%EM*RHS%EMMMM + LHS%EMMMM*RHS%EM + LHS%EMM*RHS%EMMM + LHS%EMMM*RHS%EMM
      ! Order 4
      RES%E1111 = LHS%R*RHS%E1111 + LHS%E1111*RHS%R +  &
               LHS%E1*RHS%E111 + LHS%E111*RHS%E1 + LHS%E11*RHS%E11
      RES%E2222 = LHS%R*RHS%E2222 + LHS%E2222*RHS%R +  &
               LHS%E2*RHS%E222 + LHS%E222*RHS%E2 + LHS%E22*RHS%E22
      RES%E3333 = LHS%R*RHS%E3333 + LHS%E3333*RHS%R +  &
               LHS%E3*RHS%E333 + LHS%E333*RHS%E3 + LHS%E33*RHS%E33
      RES%E4444 = LHS%R*RHS%E4444 + LHS%E4444*RHS%R +  &
               LHS%E4*RHS%E444 + LHS%E444*RHS%E4 + LHS%E44*RHS%E44
      RES%E5555 = LHS%R*RHS%E5555 + LHS%E5555*RHS%R +  &
               LHS%E5*RHS%E555 + LHS%E555*RHS%E5 + LHS%E55*RHS%E55
      RES%E6666 = LHS%R*RHS%E6666 + LHS%E6666*RHS%R +  &
               LHS%E6*RHS%E666 + LHS%E666*RHS%E6 + LHS%E66*RHS%E66
      RES%E7777 = LHS%R*RHS%E7777 + LHS%E7777*RHS%R +  &
               LHS%E7*RHS%E777 + LHS%E777*RHS%E7 + LHS%E77*RHS%E77
      RES%E8888 = LHS%R*RHS%E8888 + LHS%E8888*RHS%R +  &
               LHS%E8*RHS%E888 + LHS%E888*RHS%E8 + LHS%E88*RHS%E88
      RES%E9999 = LHS%R*RHS%E9999 + LHS%E9999*RHS%R +  &
               LHS%E9*RHS%E999 + LHS%E999*RHS%E9 + LHS%E99*RHS%E99
      RES%EAAAA = LHS%R*RHS%EAAAA + LHS%EAAAA*RHS%R +  &
               LHS%EA*RHS%EAAA + LHS%EAAA*RHS%EA + LHS%EAA*RHS%EAA
      RES%EBBBB = LHS%R*RHS%EBBBB + LHS%EBBBB*RHS%R +  &
               LHS%EB*RHS%EBBB + LHS%EBBB*RHS%EB + LHS%EBB*RHS%EBB
      RES%ECCCC = LHS%R*RHS%ECCCC + LHS%ECCCC*RHS%R +  &
               LHS%EC*RHS%ECCC + LHS%ECCC*RHS%EC + LHS%ECC*RHS%ECC
      RES%EDDDD = LHS%R*RHS%EDDDD + LHS%EDDDD*RHS%R +  &
               LHS%ED*RHS%EDDD + LHS%EDDD*RHS%ED + LHS%EDD*RHS%EDD
      RES%EEEEE = LHS%R*RHS%EEEEE + LHS%EEEEE*RHS%R +  &
               LHS%EE*RHS%EEEE + LHS%EEEE*RHS%EE + LHS%EEE*RHS%EEE
      RES%EFFFF = LHS%R*RHS%EFFFF + LHS%EFFFF*RHS%R +  &
               LHS%EF*RHS%EFFF + LHS%EFFF*RHS%EF + LHS%EFF*RHS%EFF
      RES%EGGGG = LHS%R*RHS%EGGGG + LHS%EGGGG*RHS%R +  &
               LHS%EG*RHS%EGGG + LHS%EGGG*RHS%EG + LHS%EGG*RHS%EGG
      RES%EHHHH = LHS%R*RHS%EHHHH + LHS%EHHHH*RHS%R +  &
               LHS%EH*RHS%EHHH + LHS%EHHH*RHS%EH + LHS%EHH*RHS%EHH
      RES%EIIII = LHS%R*RHS%EIIII + LHS%EIIII*RHS%R +  &
               LHS%EI*RHS%EIII + LHS%EIII*RHS%EI + LHS%EII*RHS%EII
      RES%EJJJJ = LHS%R*RHS%EJJJJ + LHS%EJJJJ*RHS%R +  &
               LHS%EJ*RHS%EJJJ + LHS%EJJJ*RHS%EJ + LHS%EJJ*RHS%EJJ
      RES%EKKKK = LHS%R*RHS%EKKKK + LHS%EKKKK*RHS%R +  &
               LHS%EK*RHS%EKKK + LHS%EKKK*RHS%EK + LHS%EKK*RHS%EKK
      RES%ELLLL = LHS%R*RHS%ELLLL + LHS%ELLLL*RHS%R +  &
               LHS%EL*RHS%ELLL + LHS%ELLL*RHS%EL + LHS%ELL*RHS%ELL
      RES%EMMMM = LHS%R*RHS%EMMMM + LHS%EMMMM*RHS%R +  &
               LHS%EM*RHS%EMMM + LHS%EMMM*RHS%EM + LHS%EMM*RHS%EMM
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
      RES%E888 = LHS%R*RHS%E888 + LHS%E888*RHS%R +  &
              LHS%E8*RHS%E88 + LHS%E88*RHS%E8
      RES%E999 = LHS%R*RHS%E999 + LHS%E999*RHS%R +  &
              LHS%E9*RHS%E99 + LHS%E99*RHS%E9
      RES%EAAA = LHS%R*RHS%EAAA + LHS%EAAA*RHS%R +  &
              LHS%EA*RHS%EAA + LHS%EAA*RHS%EA
      RES%EBBB = LHS%R*RHS%EBBB + LHS%EBBB*RHS%R +  &
              LHS%EB*RHS%EBB + LHS%EBB*RHS%EB
      RES%ECCC = LHS%R*RHS%ECCC + LHS%ECCC*RHS%R +  &
              LHS%EC*RHS%ECC + LHS%ECC*RHS%EC
      RES%EDDD = LHS%R*RHS%EDDD + LHS%EDDD*RHS%R +  &
              LHS%ED*RHS%EDD + LHS%EDD*RHS%ED
      RES%EEEE = LHS%R*RHS%EEEE + LHS%EEEE*RHS%R +  &
              LHS%EE*RHS%EEE + LHS%EEE*RHS%EE
      RES%EFFF = LHS%R*RHS%EFFF + LHS%EFFF*RHS%R +  &
              LHS%EF*RHS%EFF + LHS%EFF*RHS%EF
      RES%EGGG = LHS%R*RHS%EGGG + LHS%EGGG*RHS%R +  &
              LHS%EG*RHS%EGG + LHS%EGG*RHS%EG
      RES%EHHH = LHS%R*RHS%EHHH + LHS%EHHH*RHS%R +  &
              LHS%EH*RHS%EHH + LHS%EHH*RHS%EH
      RES%EIII = LHS%R*RHS%EIII + LHS%EIII*RHS%R +  &
              LHS%EI*RHS%EII + LHS%EII*RHS%EI
      RES%EJJJ = LHS%R*RHS%EJJJ + LHS%EJJJ*RHS%R +  &
              LHS%EJ*RHS%EJJ + LHS%EJJ*RHS%EJ
      RES%EKKK = LHS%R*RHS%EKKK + LHS%EKKK*RHS%R +  &
              LHS%EK*RHS%EKK + LHS%EKK*RHS%EK
      RES%ELLL = LHS%R*RHS%ELLL + LHS%ELLL*RHS%R +  &
              LHS%EL*RHS%ELL + LHS%ELL*RHS%EL
      RES%EMMM = LHS%R*RHS%EMMM + LHS%EMMM*RHS%R +  &
              LHS%EM*RHS%EMM + LHS%EMM*RHS%EM
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

   END FUNCTION DONUMM22N5_MUL_OO_SS

   ELEMENTAL FUNCTION DONUMM22N5_MUL_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES 

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

      ! Order 3
      RES%E111 = LHS*RHS%E111
      RES%E222 = LHS*RHS%E222
      RES%E333 = LHS*RHS%E333
      RES%E444 = LHS*RHS%E444
      RES%E555 = LHS*RHS%E555
      RES%E666 = LHS*RHS%E666
      RES%E777 = LHS*RHS%E777
      RES%E888 = LHS*RHS%E888
      RES%E999 = LHS*RHS%E999
      RES%EAAA = LHS*RHS%EAAA
      RES%EBBB = LHS*RHS%EBBB
      RES%ECCC = LHS*RHS%ECCC
      RES%EDDD = LHS*RHS%EDDD
      RES%EEEE = LHS*RHS%EEEE
      RES%EFFF = LHS*RHS%EFFF
      RES%EGGG = LHS*RHS%EGGG
      RES%EHHH = LHS*RHS%EHHH
      RES%EIII = LHS*RHS%EIII
      RES%EJJJ = LHS*RHS%EJJJ
      RES%EKKK = LHS*RHS%EKKK
      RES%ELLL = LHS*RHS%ELLL
      RES%EMMM = LHS*RHS%EMMM

      ! Order 4
      RES%E1111 = LHS*RHS%E1111
      RES%E2222 = LHS*RHS%E2222
      RES%E3333 = LHS*RHS%E3333
      RES%E4444 = LHS*RHS%E4444
      RES%E5555 = LHS*RHS%E5555
      RES%E6666 = LHS*RHS%E6666
      RES%E7777 = LHS*RHS%E7777
      RES%E8888 = LHS*RHS%E8888
      RES%E9999 = LHS*RHS%E9999
      RES%EAAAA = LHS*RHS%EAAAA
      RES%EBBBB = LHS*RHS%EBBBB
      RES%ECCCC = LHS*RHS%ECCCC
      RES%EDDDD = LHS*RHS%EDDDD
      RES%EEEEE = LHS*RHS%EEEEE
      RES%EFFFF = LHS*RHS%EFFFF
      RES%EGGGG = LHS*RHS%EGGGG
      RES%EHHHH = LHS*RHS%EHHHH
      RES%EIIII = LHS*RHS%EIIII
      RES%EJJJJ = LHS*RHS%EJJJJ
      RES%EKKKK = LHS*RHS%EKKKK
      RES%ELLLL = LHS*RHS%ELLLL
      RES%EMMMM = LHS*RHS%EMMMM

      ! Order 5
      RES%E11111 = LHS*RHS%E11111
      RES%E22222 = LHS*RHS%E22222
      RES%E33333 = LHS*RHS%E33333
      RES%E44444 = LHS*RHS%E44444
      RES%E55555 = LHS*RHS%E55555
      RES%E66666 = LHS*RHS%E66666
      RES%E77777 = LHS*RHS%E77777
      RES%E88888 = LHS*RHS%E88888
      RES%E99999 = LHS*RHS%E99999
      RES%EAAAAA = LHS*RHS%EAAAAA
      RES%EBBBBB = LHS*RHS%EBBBBB
      RES%ECCCCC = LHS*RHS%ECCCCC
      RES%EDDDDD = LHS*RHS%EDDDDD
      RES%EEEEEE = LHS*RHS%EEEEEE
      RES%EFFFFF = LHS*RHS%EFFFFF
      RES%EGGGGG = LHS*RHS%EGGGGG
      RES%EHHHHH = LHS*RHS%EHHHHH
      RES%EIIIII = LHS*RHS%EIIIII
      RES%EJJJJJ = LHS*RHS%EJJJJJ
      RES%EKKKKK = LHS*RHS%EKKKKK
      RES%ELLLLL = LHS*RHS%ELLLLL
      RES%EMMMMM = LHS*RHS%EMMMMM

   END FUNCTION DONUMM22N5_MUL_RO_SS

   ELEMENTAL FUNCTION DONUMM22N5_MUL_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES 

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

      ! Order 3
      RES%E111 = LHS%E111*RHS
      RES%E222 = LHS%E222*RHS
      RES%E333 = LHS%E333*RHS
      RES%E444 = LHS%E444*RHS
      RES%E555 = LHS%E555*RHS
      RES%E666 = LHS%E666*RHS
      RES%E777 = LHS%E777*RHS
      RES%E888 = LHS%E888*RHS
      RES%E999 = LHS%E999*RHS
      RES%EAAA = LHS%EAAA*RHS
      RES%EBBB = LHS%EBBB*RHS
      RES%ECCC = LHS%ECCC*RHS
      RES%EDDD = LHS%EDDD*RHS
      RES%EEEE = LHS%EEEE*RHS
      RES%EFFF = LHS%EFFF*RHS
      RES%EGGG = LHS%EGGG*RHS
      RES%EHHH = LHS%EHHH*RHS
      RES%EIII = LHS%EIII*RHS
      RES%EJJJ = LHS%EJJJ*RHS
      RES%EKKK = LHS%EKKK*RHS
      RES%ELLL = LHS%ELLL*RHS
      RES%EMMM = LHS%EMMM*RHS

      ! Order 4
      RES%E1111 = LHS%E1111*RHS
      RES%E2222 = LHS%E2222*RHS
      RES%E3333 = LHS%E3333*RHS
      RES%E4444 = LHS%E4444*RHS
      RES%E5555 = LHS%E5555*RHS
      RES%E6666 = LHS%E6666*RHS
      RES%E7777 = LHS%E7777*RHS
      RES%E8888 = LHS%E8888*RHS
      RES%E9999 = LHS%E9999*RHS
      RES%EAAAA = LHS%EAAAA*RHS
      RES%EBBBB = LHS%EBBBB*RHS
      RES%ECCCC = LHS%ECCCC*RHS
      RES%EDDDD = LHS%EDDDD*RHS
      RES%EEEEE = LHS%EEEEE*RHS
      RES%EFFFF = LHS%EFFFF*RHS
      RES%EGGGG = LHS%EGGGG*RHS
      RES%EHHHH = LHS%EHHHH*RHS
      RES%EIIII = LHS%EIIII*RHS
      RES%EJJJJ = LHS%EJJJJ*RHS
      RES%EKKKK = LHS%EKKKK*RHS
      RES%ELLLL = LHS%ELLLL*RHS
      RES%EMMMM = LHS%EMMMM*RHS

      ! Order 5
      RES%E11111 = LHS%E11111*RHS
      RES%E22222 = LHS%E22222*RHS
      RES%E33333 = LHS%E33333*RHS
      RES%E44444 = LHS%E44444*RHS
      RES%E55555 = LHS%E55555*RHS
      RES%E66666 = LHS%E66666*RHS
      RES%E77777 = LHS%E77777*RHS
      RES%E88888 = LHS%E88888*RHS
      RES%E99999 = LHS%E99999*RHS
      RES%EAAAAA = LHS%EAAAAA*RHS
      RES%EBBBBB = LHS%EBBBBB*RHS
      RES%ECCCCC = LHS%ECCCCC*RHS
      RES%EDDDDD = LHS%EDDDDD*RHS
      RES%EEEEEE = LHS%EEEEEE*RHS
      RES%EFFFFF = LHS%EFFFFF*RHS
      RES%EGGGGG = LHS%EGGGGG*RHS
      RES%EHHHHH = LHS%EHHHHH*RHS
      RES%EIIIII = LHS%EIIIII*RHS
      RES%EJJJJJ = LHS%EJJJJJ*RHS
      RES%EKKKKK = LHS%EKKKKK*RHS
      RES%ELLLLL = LHS%ELLLLL*RHS
      RES%EMMMMM = LHS%EMMMMM*RHS

   END FUNCTION DONUMM22N5_MUL_OR_SS

   FUNCTION DONUMM22N5_ADD_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:)
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111
      RES%E222 = LHS%E222 + RHS%E222
      RES%E333 = LHS%E333 + RHS%E333
      RES%E444 = LHS%E444 + RHS%E444
      RES%E555 = LHS%E555 + RHS%E555
      RES%E666 = LHS%E666 + RHS%E666
      RES%E777 = LHS%E777 + RHS%E777
      RES%E888 = LHS%E888 + RHS%E888
      RES%E999 = LHS%E999 + RHS%E999
      RES%EAAA = LHS%EAAA + RHS%EAAA
      RES%EBBB = LHS%EBBB + RHS%EBBB
      RES%ECCC = LHS%ECCC + RHS%ECCC
      RES%EDDD = LHS%EDDD + RHS%EDDD
      RES%EEEE = LHS%EEEE + RHS%EEEE
      RES%EFFF = LHS%EFFF + RHS%EFFF
      RES%EGGG = LHS%EGGG + RHS%EGGG
      RES%EHHH = LHS%EHHH + RHS%EHHH
      RES%EIII = LHS%EIII + RHS%EIII
      RES%EJJJ = LHS%EJJJ + RHS%EJJJ
      RES%EKKK = LHS%EKKK + RHS%EKKK
      RES%ELLL = LHS%ELLL + RHS%ELLL
      RES%EMMM = LHS%EMMM + RHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111 + RHS%E1111
      RES%E2222 = LHS%E2222 + RHS%E2222
      RES%E3333 = LHS%E3333 + RHS%E3333
      RES%E4444 = LHS%E4444 + RHS%E4444
      RES%E5555 = LHS%E5555 + RHS%E5555
      RES%E6666 = LHS%E6666 + RHS%E6666
      RES%E7777 = LHS%E7777 + RHS%E7777
      RES%E8888 = LHS%E8888 + RHS%E8888
      RES%E9999 = LHS%E9999 + RHS%E9999
      RES%EAAAA = LHS%EAAAA + RHS%EAAAA
      RES%EBBBB = LHS%EBBBB + RHS%EBBBB
      RES%ECCCC = LHS%ECCCC + RHS%ECCCC
      RES%EDDDD = LHS%EDDDD + RHS%EDDDD
      RES%EEEEE = LHS%EEEEE + RHS%EEEEE
      RES%EFFFF = LHS%EFFFF + RHS%EFFFF
      RES%EGGGG = LHS%EGGGG + RHS%EGGGG
      RES%EHHHH = LHS%EHHHH + RHS%EHHHH
      RES%EIIII = LHS%EIIII + RHS%EIIII
      RES%EJJJJ = LHS%EJJJJ + RHS%EJJJJ
      RES%EKKKK = LHS%EKKKK + RHS%EKKKK
      RES%ELLLL = LHS%ELLLL + RHS%ELLLL
      RES%EMMMM = LHS%EMMMM + RHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111 + RHS%E11111
      RES%E22222 = LHS%E22222 + RHS%E22222
      RES%E33333 = LHS%E33333 + RHS%E33333
      RES%E44444 = LHS%E44444 + RHS%E44444
      RES%E55555 = LHS%E55555 + RHS%E55555
      RES%E66666 = LHS%E66666 + RHS%E66666
      RES%E77777 = LHS%E77777 + RHS%E77777
      RES%E88888 = LHS%E88888 + RHS%E88888
      RES%E99999 = LHS%E99999 + RHS%E99999
      RES%EAAAAA = LHS%EAAAAA + RHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB + RHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC + RHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD + RHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE + RHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF + RHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG + RHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH + RHS%EHHHHH
      RES%EIIIII = LHS%EIIIII + RHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ + RHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK + RHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL + RHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM + RHS%EMMMMM

   END FUNCTION DONUMM22N5_ADD_OO_VS

   FUNCTION DONUMM22N5_ADD_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1)) 

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

      ! Order 3
      RES%E111 =  + RHS%E111
      RES%E222 =  + RHS%E222
      RES%E333 =  + RHS%E333
      RES%E444 =  + RHS%E444
      RES%E555 =  + RHS%E555
      RES%E666 =  + RHS%E666
      RES%E777 =  + RHS%E777
      RES%E888 =  + RHS%E888
      RES%E999 =  + RHS%E999
      RES%EAAA =  + RHS%EAAA
      RES%EBBB =  + RHS%EBBB
      RES%ECCC =  + RHS%ECCC
      RES%EDDD =  + RHS%EDDD
      RES%EEEE =  + RHS%EEEE
      RES%EFFF =  + RHS%EFFF
      RES%EGGG =  + RHS%EGGG
      RES%EHHH =  + RHS%EHHH
      RES%EIII =  + RHS%EIII
      RES%EJJJ =  + RHS%EJJJ
      RES%EKKK =  + RHS%EKKK
      RES%ELLL =  + RHS%ELLL
      RES%EMMM =  + RHS%EMMM

      ! Order 4
      RES%E1111 =  + RHS%E1111
      RES%E2222 =  + RHS%E2222
      RES%E3333 =  + RHS%E3333
      RES%E4444 =  + RHS%E4444
      RES%E5555 =  + RHS%E5555
      RES%E6666 =  + RHS%E6666
      RES%E7777 =  + RHS%E7777
      RES%E8888 =  + RHS%E8888
      RES%E9999 =  + RHS%E9999
      RES%EAAAA =  + RHS%EAAAA
      RES%EBBBB =  + RHS%EBBBB
      RES%ECCCC =  + RHS%ECCCC
      RES%EDDDD =  + RHS%EDDDD
      RES%EEEEE =  + RHS%EEEEE
      RES%EFFFF =  + RHS%EFFFF
      RES%EGGGG =  + RHS%EGGGG
      RES%EHHHH =  + RHS%EHHHH
      RES%EIIII =  + RHS%EIIII
      RES%EJJJJ =  + RHS%EJJJJ
      RES%EKKKK =  + RHS%EKKKK
      RES%ELLLL =  + RHS%ELLLL
      RES%EMMMM =  + RHS%EMMMM

      ! Order 5
      RES%E11111 =  + RHS%E11111
      RES%E22222 =  + RHS%E22222
      RES%E33333 =  + RHS%E33333
      RES%E44444 =  + RHS%E44444
      RES%E55555 =  + RHS%E55555
      RES%E66666 =  + RHS%E66666
      RES%E77777 =  + RHS%E77777
      RES%E88888 =  + RHS%E88888
      RES%E99999 =  + RHS%E99999
      RES%EAAAAA =  + RHS%EAAAAA
      RES%EBBBBB =  + RHS%EBBBBB
      RES%ECCCCC =  + RHS%ECCCCC
      RES%EDDDDD =  + RHS%EDDDDD
      RES%EEEEEE =  + RHS%EEEEEE
      RES%EFFFFF =  + RHS%EFFFFF
      RES%EGGGGG =  + RHS%EGGGGG
      RES%EHHHHH =  + RHS%EHHHHH
      RES%EIIIII =  + RHS%EIIIII
      RES%EJJJJJ =  + RHS%EJJJJJ
      RES%EKKKKK =  + RHS%EKKKKK
      RES%ELLLLL =  + RHS%ELLLLL
      RES%EMMMMM =  + RHS%EMMMMM

   END FUNCTION DONUMM22N5_ADD_RO_VS

   FUNCTION DONUMM22N5_ADD_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777
      RES%E888 = LHS%E888
      RES%E999 = LHS%E999
      RES%EAAA = LHS%EAAA
      RES%EBBB = LHS%EBBB
      RES%ECCC = LHS%ECCC
      RES%EDDD = LHS%EDDD
      RES%EEEE = LHS%EEEE
      RES%EFFF = LHS%EFFF
      RES%EGGG = LHS%EGGG
      RES%EHHH = LHS%EHHH
      RES%EIII = LHS%EIII
      RES%EJJJ = LHS%EJJJ
      RES%EKKK = LHS%EKKK
      RES%ELLL = LHS%ELLL
      RES%EMMM = LHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111
      RES%E2222 = LHS%E2222
      RES%E3333 = LHS%E3333
      RES%E4444 = LHS%E4444
      RES%E5555 = LHS%E5555
      RES%E6666 = LHS%E6666
      RES%E7777 = LHS%E7777
      RES%E8888 = LHS%E8888
      RES%E9999 = LHS%E9999
      RES%EAAAA = LHS%EAAAA
      RES%EBBBB = LHS%EBBBB
      RES%ECCCC = LHS%ECCCC
      RES%EDDDD = LHS%EDDDD
      RES%EEEEE = LHS%EEEEE
      RES%EFFFF = LHS%EFFFF
      RES%EGGGG = LHS%EGGGG
      RES%EHHHH = LHS%EHHHH
      RES%EIIII = LHS%EIIII
      RES%EJJJJ = LHS%EJJJJ
      RES%EKKKK = LHS%EKKKK
      RES%ELLLL = LHS%ELLLL
      RES%EMMMM = LHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111
      RES%E22222 = LHS%E22222
      RES%E33333 = LHS%E33333
      RES%E44444 = LHS%E44444
      RES%E55555 = LHS%E55555
      RES%E66666 = LHS%E66666
      RES%E77777 = LHS%E77777
      RES%E88888 = LHS%E88888
      RES%E99999 = LHS%E99999
      RES%EAAAAA = LHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH
      RES%EIIIII = LHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM

   END FUNCTION DONUMM22N5_ADD_OR_VS

   FUNCTION DONUMM22N5_SUB_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:)
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111
      RES%E222 = LHS%E222 - RHS%E222
      RES%E333 = LHS%E333 - RHS%E333
      RES%E444 = LHS%E444 - RHS%E444
      RES%E555 = LHS%E555 - RHS%E555
      RES%E666 = LHS%E666 - RHS%E666
      RES%E777 = LHS%E777 - RHS%E777
      RES%E888 = LHS%E888 - RHS%E888
      RES%E999 = LHS%E999 - RHS%E999
      RES%EAAA = LHS%EAAA - RHS%EAAA
      RES%EBBB = LHS%EBBB - RHS%EBBB
      RES%ECCC = LHS%ECCC - RHS%ECCC
      RES%EDDD = LHS%EDDD - RHS%EDDD
      RES%EEEE = LHS%EEEE - RHS%EEEE
      RES%EFFF = LHS%EFFF - RHS%EFFF
      RES%EGGG = LHS%EGGG - RHS%EGGG
      RES%EHHH = LHS%EHHH - RHS%EHHH
      RES%EIII = LHS%EIII - RHS%EIII
      RES%EJJJ = LHS%EJJJ - RHS%EJJJ
      RES%EKKK = LHS%EKKK - RHS%EKKK
      RES%ELLL = LHS%ELLL - RHS%ELLL
      RES%EMMM = LHS%EMMM - RHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111 - RHS%E1111
      RES%E2222 = LHS%E2222 - RHS%E2222
      RES%E3333 = LHS%E3333 - RHS%E3333
      RES%E4444 = LHS%E4444 - RHS%E4444
      RES%E5555 = LHS%E5555 - RHS%E5555
      RES%E6666 = LHS%E6666 - RHS%E6666
      RES%E7777 = LHS%E7777 - RHS%E7777
      RES%E8888 = LHS%E8888 - RHS%E8888
      RES%E9999 = LHS%E9999 - RHS%E9999
      RES%EAAAA = LHS%EAAAA - RHS%EAAAA
      RES%EBBBB = LHS%EBBBB - RHS%EBBBB
      RES%ECCCC = LHS%ECCCC - RHS%ECCCC
      RES%EDDDD = LHS%EDDDD - RHS%EDDDD
      RES%EEEEE = LHS%EEEEE - RHS%EEEEE
      RES%EFFFF = LHS%EFFFF - RHS%EFFFF
      RES%EGGGG = LHS%EGGGG - RHS%EGGGG
      RES%EHHHH = LHS%EHHHH - RHS%EHHHH
      RES%EIIII = LHS%EIIII - RHS%EIIII
      RES%EJJJJ = LHS%EJJJJ - RHS%EJJJJ
      RES%EKKKK = LHS%EKKKK - RHS%EKKKK
      RES%ELLLL = LHS%ELLLL - RHS%ELLLL
      RES%EMMMM = LHS%EMMMM - RHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111 - RHS%E11111
      RES%E22222 = LHS%E22222 - RHS%E22222
      RES%E33333 = LHS%E33333 - RHS%E33333
      RES%E44444 = LHS%E44444 - RHS%E44444
      RES%E55555 = LHS%E55555 - RHS%E55555
      RES%E66666 = LHS%E66666 - RHS%E66666
      RES%E77777 = LHS%E77777 - RHS%E77777
      RES%E88888 = LHS%E88888 - RHS%E88888
      RES%E99999 = LHS%E99999 - RHS%E99999
      RES%EAAAAA = LHS%EAAAAA - RHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB - RHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC - RHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD - RHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE - RHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF - RHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG - RHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH - RHS%EHHHHH
      RES%EIIIII = LHS%EIIIII - RHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ - RHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK - RHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL - RHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM - RHS%EMMMMM

   END FUNCTION DONUMM22N5_SUB_OO_VS

   FUNCTION DONUMM22N5_SUB_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1)) 

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

      ! Order 3
      RES%E111 =  - RHS%E111
      RES%E222 =  - RHS%E222
      RES%E333 =  - RHS%E333
      RES%E444 =  - RHS%E444
      RES%E555 =  - RHS%E555
      RES%E666 =  - RHS%E666
      RES%E777 =  - RHS%E777
      RES%E888 =  - RHS%E888
      RES%E999 =  - RHS%E999
      RES%EAAA =  - RHS%EAAA
      RES%EBBB =  - RHS%EBBB
      RES%ECCC =  - RHS%ECCC
      RES%EDDD =  - RHS%EDDD
      RES%EEEE =  - RHS%EEEE
      RES%EFFF =  - RHS%EFFF
      RES%EGGG =  - RHS%EGGG
      RES%EHHH =  - RHS%EHHH
      RES%EIII =  - RHS%EIII
      RES%EJJJ =  - RHS%EJJJ
      RES%EKKK =  - RHS%EKKK
      RES%ELLL =  - RHS%ELLL
      RES%EMMM =  - RHS%EMMM

      ! Order 4
      RES%E1111 =  - RHS%E1111
      RES%E2222 =  - RHS%E2222
      RES%E3333 =  - RHS%E3333
      RES%E4444 =  - RHS%E4444
      RES%E5555 =  - RHS%E5555
      RES%E6666 =  - RHS%E6666
      RES%E7777 =  - RHS%E7777
      RES%E8888 =  - RHS%E8888
      RES%E9999 =  - RHS%E9999
      RES%EAAAA =  - RHS%EAAAA
      RES%EBBBB =  - RHS%EBBBB
      RES%ECCCC =  - RHS%ECCCC
      RES%EDDDD =  - RHS%EDDDD
      RES%EEEEE =  - RHS%EEEEE
      RES%EFFFF =  - RHS%EFFFF
      RES%EGGGG =  - RHS%EGGGG
      RES%EHHHH =  - RHS%EHHHH
      RES%EIIII =  - RHS%EIIII
      RES%EJJJJ =  - RHS%EJJJJ
      RES%EKKKK =  - RHS%EKKKK
      RES%ELLLL =  - RHS%ELLLL
      RES%EMMMM =  - RHS%EMMMM

      ! Order 5
      RES%E11111 =  - RHS%E11111
      RES%E22222 =  - RHS%E22222
      RES%E33333 =  - RHS%E33333
      RES%E44444 =  - RHS%E44444
      RES%E55555 =  - RHS%E55555
      RES%E66666 =  - RHS%E66666
      RES%E77777 =  - RHS%E77777
      RES%E88888 =  - RHS%E88888
      RES%E99999 =  - RHS%E99999
      RES%EAAAAA =  - RHS%EAAAAA
      RES%EBBBBB =  - RHS%EBBBBB
      RES%ECCCCC =  - RHS%ECCCCC
      RES%EDDDDD =  - RHS%EDDDDD
      RES%EEEEEE =  - RHS%EEEEEE
      RES%EFFFFF =  - RHS%EFFFFF
      RES%EGGGGG =  - RHS%EGGGGG
      RES%EHHHHH =  - RHS%EHHHHH
      RES%EIIIII =  - RHS%EIIIII
      RES%EJJJJJ =  - RHS%EJJJJJ
      RES%EKKKKK =  - RHS%EKKKKK
      RES%ELLLLL =  - RHS%ELLLLL
      RES%EMMMMM =  - RHS%EMMMMM

   END FUNCTION DONUMM22N5_SUB_RO_VS

   FUNCTION DONUMM22N5_SUB_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777
      RES%E888 = LHS%E888
      RES%E999 = LHS%E999
      RES%EAAA = LHS%EAAA
      RES%EBBB = LHS%EBBB
      RES%ECCC = LHS%ECCC
      RES%EDDD = LHS%EDDD
      RES%EEEE = LHS%EEEE
      RES%EFFF = LHS%EFFF
      RES%EGGG = LHS%EGGG
      RES%EHHH = LHS%EHHH
      RES%EIII = LHS%EIII
      RES%EJJJ = LHS%EJJJ
      RES%EKKK = LHS%EKKK
      RES%ELLL = LHS%ELLL
      RES%EMMM = LHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111
      RES%E2222 = LHS%E2222
      RES%E3333 = LHS%E3333
      RES%E4444 = LHS%E4444
      RES%E5555 = LHS%E5555
      RES%E6666 = LHS%E6666
      RES%E7777 = LHS%E7777
      RES%E8888 = LHS%E8888
      RES%E9999 = LHS%E9999
      RES%EAAAA = LHS%EAAAA
      RES%EBBBB = LHS%EBBBB
      RES%ECCCC = LHS%ECCCC
      RES%EDDDD = LHS%EDDDD
      RES%EEEEE = LHS%EEEEE
      RES%EFFFF = LHS%EFFFF
      RES%EGGGG = LHS%EGGGG
      RES%EHHHH = LHS%EHHHH
      RES%EIIII = LHS%EIIII
      RES%EJJJJ = LHS%EJJJJ
      RES%EKKKK = LHS%EKKKK
      RES%ELLLL = LHS%ELLLL
      RES%EMMMM = LHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111
      RES%E22222 = LHS%E22222
      RES%E33333 = LHS%E33333
      RES%E44444 = LHS%E44444
      RES%E55555 = LHS%E55555
      RES%E66666 = LHS%E66666
      RES%E77777 = LHS%E77777
      RES%E88888 = LHS%E88888
      RES%E99999 = LHS%E99999
      RES%EAAAAA = LHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH
      RES%EIIIII = LHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM

   END FUNCTION DONUMM22N5_SUB_OR_VS

   FUNCTION DONUMM22N5_MUL_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:)
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 5
      RES%E11111 = LHS%R*RHS%E11111 + LHS%E11111*RHS%R +  &
                LHS%E1*RHS%E1111 + LHS%E1111*RHS%E1 + LHS%E11*RHS%E111 + LHS%E111*RHS%E11
      RES%E22222 = LHS%R*RHS%E22222 + LHS%E22222*RHS%R +  &
                LHS%E2*RHS%E2222 + LHS%E2222*RHS%E2 + LHS%E22*RHS%E222 + LHS%E222*RHS%E22
      RES%E33333 = LHS%R*RHS%E33333 + LHS%E33333*RHS%R +  &
                LHS%E3*RHS%E3333 + LHS%E3333*RHS%E3 + LHS%E33*RHS%E333 + LHS%E333*RHS%E33
      RES%E44444 = LHS%R*RHS%E44444 + LHS%E44444*RHS%R +  &
                LHS%E4*RHS%E4444 + LHS%E4444*RHS%E4 + LHS%E44*RHS%E444 + LHS%E444*RHS%E44
      RES%E55555 = LHS%R*RHS%E55555 + LHS%E55555*RHS%R +  &
                LHS%E5*RHS%E5555 + LHS%E5555*RHS%E5 + LHS%E55*RHS%E555 + LHS%E555*RHS%E55
      RES%E66666 = LHS%R*RHS%E66666 + LHS%E66666*RHS%R +  &
                LHS%E6*RHS%E6666 + LHS%E6666*RHS%E6 + LHS%E66*RHS%E666 + LHS%E666*RHS%E66
      RES%E77777 = LHS%R*RHS%E77777 + LHS%E77777*RHS%R +  &
                LHS%E7*RHS%E7777 + LHS%E7777*RHS%E7 + LHS%E77*RHS%E777 + LHS%E777*RHS%E77
      RES%E88888 = LHS%R*RHS%E88888 + LHS%E88888*RHS%R +  &
                LHS%E8*RHS%E8888 + LHS%E8888*RHS%E8 + LHS%E88*RHS%E888 + LHS%E888*RHS%E88
      RES%E99999 = LHS%R*RHS%E99999 + LHS%E99999*RHS%R +  &
                LHS%E9*RHS%E9999 + LHS%E9999*RHS%E9 + LHS%E99*RHS%E999 + LHS%E999*RHS%E99
      RES%EAAAAA = LHS%R*RHS%EAAAAA + LHS%EAAAAA*RHS%R +  &
                LHS%EA*RHS%EAAAA + LHS%EAAAA*RHS%EA + LHS%EAA*RHS%EAAA + LHS%EAAA*RHS%EAA
      RES%EBBBBB = LHS%R*RHS%EBBBBB + LHS%EBBBBB*RHS%R +  &
                LHS%EB*RHS%EBBBB + LHS%EBBBB*RHS%EB + LHS%EBB*RHS%EBBB + LHS%EBBB*RHS%EBB
      RES%ECCCCC = LHS%R*RHS%ECCCCC + LHS%ECCCCC*RHS%R +  &
                LHS%EC*RHS%ECCCC + LHS%ECCCC*RHS%EC + LHS%ECC*RHS%ECCC + LHS%ECCC*RHS%ECC
      RES%EDDDDD = LHS%R*RHS%EDDDDD + LHS%EDDDDD*RHS%R +  &
                LHS%ED*RHS%EDDDD + LHS%EDDDD*RHS%ED + LHS%EDD*RHS%EDDD + LHS%EDDD*RHS%EDD
      RES%EEEEEE = LHS%R*RHS%EEEEEE + LHS%EEEEEE*RHS%R +  &
                LHS%EE*RHS%EEEEE + LHS%EEEEE*RHS%EE + LHS%EEE*RHS%EEEE + LHS%EEEE*RHS%EEE
      RES%EFFFFF = LHS%R*RHS%EFFFFF + LHS%EFFFFF*RHS%R +  &
                LHS%EF*RHS%EFFFF + LHS%EFFFF*RHS%EF + LHS%EFF*RHS%EFFF + LHS%EFFF*RHS%EFF
      RES%EGGGGG = LHS%R*RHS%EGGGGG + LHS%EGGGGG*RHS%R +  &
                LHS%EG*RHS%EGGGG + LHS%EGGGG*RHS%EG + LHS%EGG*RHS%EGGG + LHS%EGGG*RHS%EGG
      RES%EHHHHH = LHS%R*RHS%EHHHHH + LHS%EHHHHH*RHS%R +  &
                LHS%EH*RHS%EHHHH + LHS%EHHHH*RHS%EH + LHS%EHH*RHS%EHHH + LHS%EHHH*RHS%EHH
      RES%EIIIII = LHS%R*RHS%EIIIII + LHS%EIIIII*RHS%R +  &
                LHS%EI*RHS%EIIII + LHS%EIIII*RHS%EI + LHS%EII*RHS%EIII + LHS%EIII*RHS%EII
      RES%EJJJJJ = LHS%R*RHS%EJJJJJ + LHS%EJJJJJ*RHS%R +  &
                LHS%EJ*RHS%EJJJJ + LHS%EJJJJ*RHS%EJ + LHS%EJJ*RHS%EJJJ + LHS%EJJJ*RHS%EJJ
      RES%EKKKKK = LHS%R*RHS%EKKKKK + LHS%EKKKKK*RHS%R +  &
                LHS%EK*RHS%EKKKK + LHS%EKKKK*RHS%EK + LHS%EKK*RHS%EKKK + LHS%EKKK*RHS%EKK
      RES%ELLLLL = LHS%R*RHS%ELLLLL + LHS%ELLLLL*RHS%R +  &
                LHS%EL*RHS%ELLLL + LHS%ELLLL*RHS%EL + LHS%ELL*RHS%ELLL + LHS%ELLL*RHS%ELL
      RES%EMMMMM = LHS%R*RHS%EMMMMM + LHS%EMMMMM*RHS%R +  &
                LHS%EM*RHS%EMMMM + LHS%EMMMM*RHS%EM + LHS%EMM*RHS%EMMM + LHS%EMMM*RHS%EMM
      ! Order 4
      RES%E1111 = LHS%R*RHS%E1111 + LHS%E1111*RHS%R +  &
               LHS%E1*RHS%E111 + LHS%E111*RHS%E1 + LHS%E11*RHS%E11
      RES%E2222 = LHS%R*RHS%E2222 + LHS%E2222*RHS%R +  &
               LHS%E2*RHS%E222 + LHS%E222*RHS%E2 + LHS%E22*RHS%E22
      RES%E3333 = LHS%R*RHS%E3333 + LHS%E3333*RHS%R +  &
               LHS%E3*RHS%E333 + LHS%E333*RHS%E3 + LHS%E33*RHS%E33
      RES%E4444 = LHS%R*RHS%E4444 + LHS%E4444*RHS%R +  &
               LHS%E4*RHS%E444 + LHS%E444*RHS%E4 + LHS%E44*RHS%E44
      RES%E5555 = LHS%R*RHS%E5555 + LHS%E5555*RHS%R +  &
               LHS%E5*RHS%E555 + LHS%E555*RHS%E5 + LHS%E55*RHS%E55
      RES%E6666 = LHS%R*RHS%E6666 + LHS%E6666*RHS%R +  &
               LHS%E6*RHS%E666 + LHS%E666*RHS%E6 + LHS%E66*RHS%E66
      RES%E7777 = LHS%R*RHS%E7777 + LHS%E7777*RHS%R +  &
               LHS%E7*RHS%E777 + LHS%E777*RHS%E7 + LHS%E77*RHS%E77
      RES%E8888 = LHS%R*RHS%E8888 + LHS%E8888*RHS%R +  &
               LHS%E8*RHS%E888 + LHS%E888*RHS%E8 + LHS%E88*RHS%E88
      RES%E9999 = LHS%R*RHS%E9999 + LHS%E9999*RHS%R +  &
               LHS%E9*RHS%E999 + LHS%E999*RHS%E9 + LHS%E99*RHS%E99
      RES%EAAAA = LHS%R*RHS%EAAAA + LHS%EAAAA*RHS%R +  &
               LHS%EA*RHS%EAAA + LHS%EAAA*RHS%EA + LHS%EAA*RHS%EAA
      RES%EBBBB = LHS%R*RHS%EBBBB + LHS%EBBBB*RHS%R +  &
               LHS%EB*RHS%EBBB + LHS%EBBB*RHS%EB + LHS%EBB*RHS%EBB
      RES%ECCCC = LHS%R*RHS%ECCCC + LHS%ECCCC*RHS%R +  &
               LHS%EC*RHS%ECCC + LHS%ECCC*RHS%EC + LHS%ECC*RHS%ECC
      RES%EDDDD = LHS%R*RHS%EDDDD + LHS%EDDDD*RHS%R +  &
               LHS%ED*RHS%EDDD + LHS%EDDD*RHS%ED + LHS%EDD*RHS%EDD
      RES%EEEEE = LHS%R*RHS%EEEEE + LHS%EEEEE*RHS%R +  &
               LHS%EE*RHS%EEEE + LHS%EEEE*RHS%EE + LHS%EEE*RHS%EEE
      RES%EFFFF = LHS%R*RHS%EFFFF + LHS%EFFFF*RHS%R +  &
               LHS%EF*RHS%EFFF + LHS%EFFF*RHS%EF + LHS%EFF*RHS%EFF
      RES%EGGGG = LHS%R*RHS%EGGGG + LHS%EGGGG*RHS%R +  &
               LHS%EG*RHS%EGGG + LHS%EGGG*RHS%EG + LHS%EGG*RHS%EGG
      RES%EHHHH = LHS%R*RHS%EHHHH + LHS%EHHHH*RHS%R +  &
               LHS%EH*RHS%EHHH + LHS%EHHH*RHS%EH + LHS%EHH*RHS%EHH
      RES%EIIII = LHS%R*RHS%EIIII + LHS%EIIII*RHS%R +  &
               LHS%EI*RHS%EIII + LHS%EIII*RHS%EI + LHS%EII*RHS%EII
      RES%EJJJJ = LHS%R*RHS%EJJJJ + LHS%EJJJJ*RHS%R +  &
               LHS%EJ*RHS%EJJJ + LHS%EJJJ*RHS%EJ + LHS%EJJ*RHS%EJJ
      RES%EKKKK = LHS%R*RHS%EKKKK + LHS%EKKKK*RHS%R +  &
               LHS%EK*RHS%EKKK + LHS%EKKK*RHS%EK + LHS%EKK*RHS%EKK
      RES%ELLLL = LHS%R*RHS%ELLLL + LHS%ELLLL*RHS%R +  &
               LHS%EL*RHS%ELLL + LHS%ELLL*RHS%EL + LHS%ELL*RHS%ELL
      RES%EMMMM = LHS%R*RHS%EMMMM + LHS%EMMMM*RHS%R +  &
               LHS%EM*RHS%EMMM + LHS%EMMM*RHS%EM + LHS%EMM*RHS%EMM
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
      RES%E888 = LHS%R*RHS%E888 + LHS%E888*RHS%R +  &
              LHS%E8*RHS%E88 + LHS%E88*RHS%E8
      RES%E999 = LHS%R*RHS%E999 + LHS%E999*RHS%R +  &
              LHS%E9*RHS%E99 + LHS%E99*RHS%E9
      RES%EAAA = LHS%R*RHS%EAAA + LHS%EAAA*RHS%R +  &
              LHS%EA*RHS%EAA + LHS%EAA*RHS%EA
      RES%EBBB = LHS%R*RHS%EBBB + LHS%EBBB*RHS%R +  &
              LHS%EB*RHS%EBB + LHS%EBB*RHS%EB
      RES%ECCC = LHS%R*RHS%ECCC + LHS%ECCC*RHS%R +  &
              LHS%EC*RHS%ECC + LHS%ECC*RHS%EC
      RES%EDDD = LHS%R*RHS%EDDD + LHS%EDDD*RHS%R +  &
              LHS%ED*RHS%EDD + LHS%EDD*RHS%ED
      RES%EEEE = LHS%R*RHS%EEEE + LHS%EEEE*RHS%R +  &
              LHS%EE*RHS%EEE + LHS%EEE*RHS%EE
      RES%EFFF = LHS%R*RHS%EFFF + LHS%EFFF*RHS%R +  &
              LHS%EF*RHS%EFF + LHS%EFF*RHS%EF
      RES%EGGG = LHS%R*RHS%EGGG + LHS%EGGG*RHS%R +  &
              LHS%EG*RHS%EGG + LHS%EGG*RHS%EG
      RES%EHHH = LHS%R*RHS%EHHH + LHS%EHHH*RHS%R +  &
              LHS%EH*RHS%EHH + LHS%EHH*RHS%EH
      RES%EIII = LHS%R*RHS%EIII + LHS%EIII*RHS%R +  &
              LHS%EI*RHS%EII + LHS%EII*RHS%EI
      RES%EJJJ = LHS%R*RHS%EJJJ + LHS%EJJJ*RHS%R +  &
              LHS%EJ*RHS%EJJ + LHS%EJJ*RHS%EJ
      RES%EKKK = LHS%R*RHS%EKKK + LHS%EKKK*RHS%R +  &
              LHS%EK*RHS%EKK + LHS%EKK*RHS%EK
      RES%ELLL = LHS%R*RHS%ELLL + LHS%ELLL*RHS%R +  &
              LHS%EL*RHS%ELL + LHS%ELL*RHS%EL
      RES%EMMM = LHS%R*RHS%EMMM + LHS%EMMM*RHS%R +  &
              LHS%EM*RHS%EMM + LHS%EMM*RHS%EM
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

   END FUNCTION DONUMM22N5_MUL_OO_VS

   FUNCTION DONUMM22N5_MUL_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1)) 

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

      ! Order 3
      RES%E111 = LHS*RHS%E111
      RES%E222 = LHS*RHS%E222
      RES%E333 = LHS*RHS%E333
      RES%E444 = LHS*RHS%E444
      RES%E555 = LHS*RHS%E555
      RES%E666 = LHS*RHS%E666
      RES%E777 = LHS*RHS%E777
      RES%E888 = LHS*RHS%E888
      RES%E999 = LHS*RHS%E999
      RES%EAAA = LHS*RHS%EAAA
      RES%EBBB = LHS*RHS%EBBB
      RES%ECCC = LHS*RHS%ECCC
      RES%EDDD = LHS*RHS%EDDD
      RES%EEEE = LHS*RHS%EEEE
      RES%EFFF = LHS*RHS%EFFF
      RES%EGGG = LHS*RHS%EGGG
      RES%EHHH = LHS*RHS%EHHH
      RES%EIII = LHS*RHS%EIII
      RES%EJJJ = LHS*RHS%EJJJ
      RES%EKKK = LHS*RHS%EKKK
      RES%ELLL = LHS*RHS%ELLL
      RES%EMMM = LHS*RHS%EMMM

      ! Order 4
      RES%E1111 = LHS*RHS%E1111
      RES%E2222 = LHS*RHS%E2222
      RES%E3333 = LHS*RHS%E3333
      RES%E4444 = LHS*RHS%E4444
      RES%E5555 = LHS*RHS%E5555
      RES%E6666 = LHS*RHS%E6666
      RES%E7777 = LHS*RHS%E7777
      RES%E8888 = LHS*RHS%E8888
      RES%E9999 = LHS*RHS%E9999
      RES%EAAAA = LHS*RHS%EAAAA
      RES%EBBBB = LHS*RHS%EBBBB
      RES%ECCCC = LHS*RHS%ECCCC
      RES%EDDDD = LHS*RHS%EDDDD
      RES%EEEEE = LHS*RHS%EEEEE
      RES%EFFFF = LHS*RHS%EFFFF
      RES%EGGGG = LHS*RHS%EGGGG
      RES%EHHHH = LHS*RHS%EHHHH
      RES%EIIII = LHS*RHS%EIIII
      RES%EJJJJ = LHS*RHS%EJJJJ
      RES%EKKKK = LHS*RHS%EKKKK
      RES%ELLLL = LHS*RHS%ELLLL
      RES%EMMMM = LHS*RHS%EMMMM

      ! Order 5
      RES%E11111 = LHS*RHS%E11111
      RES%E22222 = LHS*RHS%E22222
      RES%E33333 = LHS*RHS%E33333
      RES%E44444 = LHS*RHS%E44444
      RES%E55555 = LHS*RHS%E55555
      RES%E66666 = LHS*RHS%E66666
      RES%E77777 = LHS*RHS%E77777
      RES%E88888 = LHS*RHS%E88888
      RES%E99999 = LHS*RHS%E99999
      RES%EAAAAA = LHS*RHS%EAAAAA
      RES%EBBBBB = LHS*RHS%EBBBBB
      RES%ECCCCC = LHS*RHS%ECCCCC
      RES%EDDDDD = LHS*RHS%EDDDDD
      RES%EEEEEE = LHS*RHS%EEEEEE
      RES%EFFFFF = LHS*RHS%EFFFFF
      RES%EGGGGG = LHS*RHS%EGGGGG
      RES%EHHHHH = LHS*RHS%EHHHHH
      RES%EIIIII = LHS*RHS%EIIIII
      RES%EJJJJJ = LHS*RHS%EJJJJJ
      RES%EKKKKK = LHS*RHS%EKKKKK
      RES%ELLLLL = LHS*RHS%ELLLLL
      RES%EMMMMM = LHS*RHS%EMMMMM

   END FUNCTION DONUMM22N5_MUL_RO_VS

   FUNCTION DONUMM22N5_MUL_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111*RHS
      RES%E222 = LHS%E222*RHS
      RES%E333 = LHS%E333*RHS
      RES%E444 = LHS%E444*RHS
      RES%E555 = LHS%E555*RHS
      RES%E666 = LHS%E666*RHS
      RES%E777 = LHS%E777*RHS
      RES%E888 = LHS%E888*RHS
      RES%E999 = LHS%E999*RHS
      RES%EAAA = LHS%EAAA*RHS
      RES%EBBB = LHS%EBBB*RHS
      RES%ECCC = LHS%ECCC*RHS
      RES%EDDD = LHS%EDDD*RHS
      RES%EEEE = LHS%EEEE*RHS
      RES%EFFF = LHS%EFFF*RHS
      RES%EGGG = LHS%EGGG*RHS
      RES%EHHH = LHS%EHHH*RHS
      RES%EIII = LHS%EIII*RHS
      RES%EJJJ = LHS%EJJJ*RHS
      RES%EKKK = LHS%EKKK*RHS
      RES%ELLL = LHS%ELLL*RHS
      RES%EMMM = LHS%EMMM*RHS

      ! Order 4
      RES%E1111 = LHS%E1111*RHS
      RES%E2222 = LHS%E2222*RHS
      RES%E3333 = LHS%E3333*RHS
      RES%E4444 = LHS%E4444*RHS
      RES%E5555 = LHS%E5555*RHS
      RES%E6666 = LHS%E6666*RHS
      RES%E7777 = LHS%E7777*RHS
      RES%E8888 = LHS%E8888*RHS
      RES%E9999 = LHS%E9999*RHS
      RES%EAAAA = LHS%EAAAA*RHS
      RES%EBBBB = LHS%EBBBB*RHS
      RES%ECCCC = LHS%ECCCC*RHS
      RES%EDDDD = LHS%EDDDD*RHS
      RES%EEEEE = LHS%EEEEE*RHS
      RES%EFFFF = LHS%EFFFF*RHS
      RES%EGGGG = LHS%EGGGG*RHS
      RES%EHHHH = LHS%EHHHH*RHS
      RES%EIIII = LHS%EIIII*RHS
      RES%EJJJJ = LHS%EJJJJ*RHS
      RES%EKKKK = LHS%EKKKK*RHS
      RES%ELLLL = LHS%ELLLL*RHS
      RES%EMMMM = LHS%EMMMM*RHS

      ! Order 5
      RES%E11111 = LHS%E11111*RHS
      RES%E22222 = LHS%E22222*RHS
      RES%E33333 = LHS%E33333*RHS
      RES%E44444 = LHS%E44444*RHS
      RES%E55555 = LHS%E55555*RHS
      RES%E66666 = LHS%E66666*RHS
      RES%E77777 = LHS%E77777*RHS
      RES%E88888 = LHS%E88888*RHS
      RES%E99999 = LHS%E99999*RHS
      RES%EAAAAA = LHS%EAAAAA*RHS
      RES%EBBBBB = LHS%EBBBBB*RHS
      RES%ECCCCC = LHS%ECCCCC*RHS
      RES%EDDDDD = LHS%EDDDDD*RHS
      RES%EEEEEE = LHS%EEEEEE*RHS
      RES%EFFFFF = LHS%EFFFFF*RHS
      RES%EGGGGG = LHS%EGGGGG*RHS
      RES%EHHHHH = LHS%EHHHHH*RHS
      RES%EIIIII = LHS%EIIIII*RHS
      RES%EJJJJJ = LHS%EJJJJJ*RHS
      RES%EKKKKK = LHS%EKKKKK*RHS
      RES%ELLLLL = LHS%ELLLLL*RHS
      RES%EMMMMM = LHS%EMMMMM*RHS

   END FUNCTION DONUMM22N5_MUL_OR_VS

   FUNCTION DONUMM22N5_ADD_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111
      RES%E222 = LHS%E222 + RHS%E222
      RES%E333 = LHS%E333 + RHS%E333
      RES%E444 = LHS%E444 + RHS%E444
      RES%E555 = LHS%E555 + RHS%E555
      RES%E666 = LHS%E666 + RHS%E666
      RES%E777 = LHS%E777 + RHS%E777
      RES%E888 = LHS%E888 + RHS%E888
      RES%E999 = LHS%E999 + RHS%E999
      RES%EAAA = LHS%EAAA + RHS%EAAA
      RES%EBBB = LHS%EBBB + RHS%EBBB
      RES%ECCC = LHS%ECCC + RHS%ECCC
      RES%EDDD = LHS%EDDD + RHS%EDDD
      RES%EEEE = LHS%EEEE + RHS%EEEE
      RES%EFFF = LHS%EFFF + RHS%EFFF
      RES%EGGG = LHS%EGGG + RHS%EGGG
      RES%EHHH = LHS%EHHH + RHS%EHHH
      RES%EIII = LHS%EIII + RHS%EIII
      RES%EJJJ = LHS%EJJJ + RHS%EJJJ
      RES%EKKK = LHS%EKKK + RHS%EKKK
      RES%ELLL = LHS%ELLL + RHS%ELLL
      RES%EMMM = LHS%EMMM + RHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111 + RHS%E1111
      RES%E2222 = LHS%E2222 + RHS%E2222
      RES%E3333 = LHS%E3333 + RHS%E3333
      RES%E4444 = LHS%E4444 + RHS%E4444
      RES%E5555 = LHS%E5555 + RHS%E5555
      RES%E6666 = LHS%E6666 + RHS%E6666
      RES%E7777 = LHS%E7777 + RHS%E7777
      RES%E8888 = LHS%E8888 + RHS%E8888
      RES%E9999 = LHS%E9999 + RHS%E9999
      RES%EAAAA = LHS%EAAAA + RHS%EAAAA
      RES%EBBBB = LHS%EBBBB + RHS%EBBBB
      RES%ECCCC = LHS%ECCCC + RHS%ECCCC
      RES%EDDDD = LHS%EDDDD + RHS%EDDDD
      RES%EEEEE = LHS%EEEEE + RHS%EEEEE
      RES%EFFFF = LHS%EFFFF + RHS%EFFFF
      RES%EGGGG = LHS%EGGGG + RHS%EGGGG
      RES%EHHHH = LHS%EHHHH + RHS%EHHHH
      RES%EIIII = LHS%EIIII + RHS%EIIII
      RES%EJJJJ = LHS%EJJJJ + RHS%EJJJJ
      RES%EKKKK = LHS%EKKKK + RHS%EKKKK
      RES%ELLLL = LHS%ELLLL + RHS%ELLLL
      RES%EMMMM = LHS%EMMMM + RHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111 + RHS%E11111
      RES%E22222 = LHS%E22222 + RHS%E22222
      RES%E33333 = LHS%E33333 + RHS%E33333
      RES%E44444 = LHS%E44444 + RHS%E44444
      RES%E55555 = LHS%E55555 + RHS%E55555
      RES%E66666 = LHS%E66666 + RHS%E66666
      RES%E77777 = LHS%E77777 + RHS%E77777
      RES%E88888 = LHS%E88888 + RHS%E88888
      RES%E99999 = LHS%E99999 + RHS%E99999
      RES%EAAAAA = LHS%EAAAAA + RHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB + RHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC + RHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD + RHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE + RHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF + RHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG + RHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH + RHS%EHHHHH
      RES%EIIIII = LHS%EIIIII + RHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ + RHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK + RHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL + RHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM + RHS%EMMMMM

   END FUNCTION DONUMM22N5_ADD_OO_MS

   FUNCTION DONUMM22N5_ADD_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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

      ! Order 3
      RES%E111 =  + RHS%E111
      RES%E222 =  + RHS%E222
      RES%E333 =  + RHS%E333
      RES%E444 =  + RHS%E444
      RES%E555 =  + RHS%E555
      RES%E666 =  + RHS%E666
      RES%E777 =  + RHS%E777
      RES%E888 =  + RHS%E888
      RES%E999 =  + RHS%E999
      RES%EAAA =  + RHS%EAAA
      RES%EBBB =  + RHS%EBBB
      RES%ECCC =  + RHS%ECCC
      RES%EDDD =  + RHS%EDDD
      RES%EEEE =  + RHS%EEEE
      RES%EFFF =  + RHS%EFFF
      RES%EGGG =  + RHS%EGGG
      RES%EHHH =  + RHS%EHHH
      RES%EIII =  + RHS%EIII
      RES%EJJJ =  + RHS%EJJJ
      RES%EKKK =  + RHS%EKKK
      RES%ELLL =  + RHS%ELLL
      RES%EMMM =  + RHS%EMMM

      ! Order 4
      RES%E1111 =  + RHS%E1111
      RES%E2222 =  + RHS%E2222
      RES%E3333 =  + RHS%E3333
      RES%E4444 =  + RHS%E4444
      RES%E5555 =  + RHS%E5555
      RES%E6666 =  + RHS%E6666
      RES%E7777 =  + RHS%E7777
      RES%E8888 =  + RHS%E8888
      RES%E9999 =  + RHS%E9999
      RES%EAAAA =  + RHS%EAAAA
      RES%EBBBB =  + RHS%EBBBB
      RES%ECCCC =  + RHS%ECCCC
      RES%EDDDD =  + RHS%EDDDD
      RES%EEEEE =  + RHS%EEEEE
      RES%EFFFF =  + RHS%EFFFF
      RES%EGGGG =  + RHS%EGGGG
      RES%EHHHH =  + RHS%EHHHH
      RES%EIIII =  + RHS%EIIII
      RES%EJJJJ =  + RHS%EJJJJ
      RES%EKKKK =  + RHS%EKKKK
      RES%ELLLL =  + RHS%ELLLL
      RES%EMMMM =  + RHS%EMMMM

      ! Order 5
      RES%E11111 =  + RHS%E11111
      RES%E22222 =  + RHS%E22222
      RES%E33333 =  + RHS%E33333
      RES%E44444 =  + RHS%E44444
      RES%E55555 =  + RHS%E55555
      RES%E66666 =  + RHS%E66666
      RES%E77777 =  + RHS%E77777
      RES%E88888 =  + RHS%E88888
      RES%E99999 =  + RHS%E99999
      RES%EAAAAA =  + RHS%EAAAAA
      RES%EBBBBB =  + RHS%EBBBBB
      RES%ECCCCC =  + RHS%ECCCCC
      RES%EDDDDD =  + RHS%EDDDDD
      RES%EEEEEE =  + RHS%EEEEEE
      RES%EFFFFF =  + RHS%EFFFFF
      RES%EGGGGG =  + RHS%EGGGGG
      RES%EHHHHH =  + RHS%EHHHHH
      RES%EIIIII =  + RHS%EIIIII
      RES%EJJJJJ =  + RHS%EJJJJJ
      RES%EKKKKK =  + RHS%EKKKKK
      RES%ELLLLL =  + RHS%ELLLLL
      RES%EMMMMM =  + RHS%EMMMMM

   END FUNCTION DONUMM22N5_ADD_RO_MS

   FUNCTION DONUMM22N5_ADD_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777
      RES%E888 = LHS%E888
      RES%E999 = LHS%E999
      RES%EAAA = LHS%EAAA
      RES%EBBB = LHS%EBBB
      RES%ECCC = LHS%ECCC
      RES%EDDD = LHS%EDDD
      RES%EEEE = LHS%EEEE
      RES%EFFF = LHS%EFFF
      RES%EGGG = LHS%EGGG
      RES%EHHH = LHS%EHHH
      RES%EIII = LHS%EIII
      RES%EJJJ = LHS%EJJJ
      RES%EKKK = LHS%EKKK
      RES%ELLL = LHS%ELLL
      RES%EMMM = LHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111
      RES%E2222 = LHS%E2222
      RES%E3333 = LHS%E3333
      RES%E4444 = LHS%E4444
      RES%E5555 = LHS%E5555
      RES%E6666 = LHS%E6666
      RES%E7777 = LHS%E7777
      RES%E8888 = LHS%E8888
      RES%E9999 = LHS%E9999
      RES%EAAAA = LHS%EAAAA
      RES%EBBBB = LHS%EBBBB
      RES%ECCCC = LHS%ECCCC
      RES%EDDDD = LHS%EDDDD
      RES%EEEEE = LHS%EEEEE
      RES%EFFFF = LHS%EFFFF
      RES%EGGGG = LHS%EGGGG
      RES%EHHHH = LHS%EHHHH
      RES%EIIII = LHS%EIIII
      RES%EJJJJ = LHS%EJJJJ
      RES%EKKKK = LHS%EKKKK
      RES%ELLLL = LHS%ELLLL
      RES%EMMMM = LHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111
      RES%E22222 = LHS%E22222
      RES%E33333 = LHS%E33333
      RES%E44444 = LHS%E44444
      RES%E55555 = LHS%E55555
      RES%E66666 = LHS%E66666
      RES%E77777 = LHS%E77777
      RES%E88888 = LHS%E88888
      RES%E99999 = LHS%E99999
      RES%EAAAAA = LHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH
      RES%EIIIII = LHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM

   END FUNCTION DONUMM22N5_ADD_OR_MS

   FUNCTION DONUMM22N5_SUB_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111
      RES%E222 = LHS%E222 - RHS%E222
      RES%E333 = LHS%E333 - RHS%E333
      RES%E444 = LHS%E444 - RHS%E444
      RES%E555 = LHS%E555 - RHS%E555
      RES%E666 = LHS%E666 - RHS%E666
      RES%E777 = LHS%E777 - RHS%E777
      RES%E888 = LHS%E888 - RHS%E888
      RES%E999 = LHS%E999 - RHS%E999
      RES%EAAA = LHS%EAAA - RHS%EAAA
      RES%EBBB = LHS%EBBB - RHS%EBBB
      RES%ECCC = LHS%ECCC - RHS%ECCC
      RES%EDDD = LHS%EDDD - RHS%EDDD
      RES%EEEE = LHS%EEEE - RHS%EEEE
      RES%EFFF = LHS%EFFF - RHS%EFFF
      RES%EGGG = LHS%EGGG - RHS%EGGG
      RES%EHHH = LHS%EHHH - RHS%EHHH
      RES%EIII = LHS%EIII - RHS%EIII
      RES%EJJJ = LHS%EJJJ - RHS%EJJJ
      RES%EKKK = LHS%EKKK - RHS%EKKK
      RES%ELLL = LHS%ELLL - RHS%ELLL
      RES%EMMM = LHS%EMMM - RHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111 - RHS%E1111
      RES%E2222 = LHS%E2222 - RHS%E2222
      RES%E3333 = LHS%E3333 - RHS%E3333
      RES%E4444 = LHS%E4444 - RHS%E4444
      RES%E5555 = LHS%E5555 - RHS%E5555
      RES%E6666 = LHS%E6666 - RHS%E6666
      RES%E7777 = LHS%E7777 - RHS%E7777
      RES%E8888 = LHS%E8888 - RHS%E8888
      RES%E9999 = LHS%E9999 - RHS%E9999
      RES%EAAAA = LHS%EAAAA - RHS%EAAAA
      RES%EBBBB = LHS%EBBBB - RHS%EBBBB
      RES%ECCCC = LHS%ECCCC - RHS%ECCCC
      RES%EDDDD = LHS%EDDDD - RHS%EDDDD
      RES%EEEEE = LHS%EEEEE - RHS%EEEEE
      RES%EFFFF = LHS%EFFFF - RHS%EFFFF
      RES%EGGGG = LHS%EGGGG - RHS%EGGGG
      RES%EHHHH = LHS%EHHHH - RHS%EHHHH
      RES%EIIII = LHS%EIIII - RHS%EIIII
      RES%EJJJJ = LHS%EJJJJ - RHS%EJJJJ
      RES%EKKKK = LHS%EKKKK - RHS%EKKKK
      RES%ELLLL = LHS%ELLLL - RHS%ELLLL
      RES%EMMMM = LHS%EMMMM - RHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111 - RHS%E11111
      RES%E22222 = LHS%E22222 - RHS%E22222
      RES%E33333 = LHS%E33333 - RHS%E33333
      RES%E44444 = LHS%E44444 - RHS%E44444
      RES%E55555 = LHS%E55555 - RHS%E55555
      RES%E66666 = LHS%E66666 - RHS%E66666
      RES%E77777 = LHS%E77777 - RHS%E77777
      RES%E88888 = LHS%E88888 - RHS%E88888
      RES%E99999 = LHS%E99999 - RHS%E99999
      RES%EAAAAA = LHS%EAAAAA - RHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB - RHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC - RHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD - RHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE - RHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF - RHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG - RHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH - RHS%EHHHHH
      RES%EIIIII = LHS%EIIIII - RHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ - RHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK - RHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL - RHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM - RHS%EMMMMM

   END FUNCTION DONUMM22N5_SUB_OO_MS

   FUNCTION DONUMM22N5_SUB_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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

      ! Order 3
      RES%E111 =  - RHS%E111
      RES%E222 =  - RHS%E222
      RES%E333 =  - RHS%E333
      RES%E444 =  - RHS%E444
      RES%E555 =  - RHS%E555
      RES%E666 =  - RHS%E666
      RES%E777 =  - RHS%E777
      RES%E888 =  - RHS%E888
      RES%E999 =  - RHS%E999
      RES%EAAA =  - RHS%EAAA
      RES%EBBB =  - RHS%EBBB
      RES%ECCC =  - RHS%ECCC
      RES%EDDD =  - RHS%EDDD
      RES%EEEE =  - RHS%EEEE
      RES%EFFF =  - RHS%EFFF
      RES%EGGG =  - RHS%EGGG
      RES%EHHH =  - RHS%EHHH
      RES%EIII =  - RHS%EIII
      RES%EJJJ =  - RHS%EJJJ
      RES%EKKK =  - RHS%EKKK
      RES%ELLL =  - RHS%ELLL
      RES%EMMM =  - RHS%EMMM

      ! Order 4
      RES%E1111 =  - RHS%E1111
      RES%E2222 =  - RHS%E2222
      RES%E3333 =  - RHS%E3333
      RES%E4444 =  - RHS%E4444
      RES%E5555 =  - RHS%E5555
      RES%E6666 =  - RHS%E6666
      RES%E7777 =  - RHS%E7777
      RES%E8888 =  - RHS%E8888
      RES%E9999 =  - RHS%E9999
      RES%EAAAA =  - RHS%EAAAA
      RES%EBBBB =  - RHS%EBBBB
      RES%ECCCC =  - RHS%ECCCC
      RES%EDDDD =  - RHS%EDDDD
      RES%EEEEE =  - RHS%EEEEE
      RES%EFFFF =  - RHS%EFFFF
      RES%EGGGG =  - RHS%EGGGG
      RES%EHHHH =  - RHS%EHHHH
      RES%EIIII =  - RHS%EIIII
      RES%EJJJJ =  - RHS%EJJJJ
      RES%EKKKK =  - RHS%EKKKK
      RES%ELLLL =  - RHS%ELLLL
      RES%EMMMM =  - RHS%EMMMM

      ! Order 5
      RES%E11111 =  - RHS%E11111
      RES%E22222 =  - RHS%E22222
      RES%E33333 =  - RHS%E33333
      RES%E44444 =  - RHS%E44444
      RES%E55555 =  - RHS%E55555
      RES%E66666 =  - RHS%E66666
      RES%E77777 =  - RHS%E77777
      RES%E88888 =  - RHS%E88888
      RES%E99999 =  - RHS%E99999
      RES%EAAAAA =  - RHS%EAAAAA
      RES%EBBBBB =  - RHS%EBBBBB
      RES%ECCCCC =  - RHS%ECCCCC
      RES%EDDDDD =  - RHS%EDDDDD
      RES%EEEEEE =  - RHS%EEEEEE
      RES%EFFFFF =  - RHS%EFFFFF
      RES%EGGGGG =  - RHS%EGGGGG
      RES%EHHHHH =  - RHS%EHHHHH
      RES%EIIIII =  - RHS%EIIIII
      RES%EJJJJJ =  - RHS%EJJJJJ
      RES%EKKKKK =  - RHS%EKKKKK
      RES%ELLLLL =  - RHS%ELLLLL
      RES%EMMMMM =  - RHS%EMMMMM

   END FUNCTION DONUMM22N5_SUB_RO_MS

   FUNCTION DONUMM22N5_SUB_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777
      RES%E888 = LHS%E888
      RES%E999 = LHS%E999
      RES%EAAA = LHS%EAAA
      RES%EBBB = LHS%EBBB
      RES%ECCC = LHS%ECCC
      RES%EDDD = LHS%EDDD
      RES%EEEE = LHS%EEEE
      RES%EFFF = LHS%EFFF
      RES%EGGG = LHS%EGGG
      RES%EHHH = LHS%EHHH
      RES%EIII = LHS%EIII
      RES%EJJJ = LHS%EJJJ
      RES%EKKK = LHS%EKKK
      RES%ELLL = LHS%ELLL
      RES%EMMM = LHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111
      RES%E2222 = LHS%E2222
      RES%E3333 = LHS%E3333
      RES%E4444 = LHS%E4444
      RES%E5555 = LHS%E5555
      RES%E6666 = LHS%E6666
      RES%E7777 = LHS%E7777
      RES%E8888 = LHS%E8888
      RES%E9999 = LHS%E9999
      RES%EAAAA = LHS%EAAAA
      RES%EBBBB = LHS%EBBBB
      RES%ECCCC = LHS%ECCCC
      RES%EDDDD = LHS%EDDDD
      RES%EEEEE = LHS%EEEEE
      RES%EFFFF = LHS%EFFFF
      RES%EGGGG = LHS%EGGGG
      RES%EHHHH = LHS%EHHHH
      RES%EIIII = LHS%EIIII
      RES%EJJJJ = LHS%EJJJJ
      RES%EKKKK = LHS%EKKKK
      RES%ELLLL = LHS%ELLLL
      RES%EMMMM = LHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111
      RES%E22222 = LHS%E22222
      RES%E33333 = LHS%E33333
      RES%E44444 = LHS%E44444
      RES%E55555 = LHS%E55555
      RES%E66666 = LHS%E66666
      RES%E77777 = LHS%E77777
      RES%E88888 = LHS%E88888
      RES%E99999 = LHS%E99999
      RES%EAAAAA = LHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH
      RES%EIIIII = LHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM

   END FUNCTION DONUMM22N5_SUB_OR_MS

   FUNCTION DONUMM22N5_MUL_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 5
      RES%E11111 = LHS%R*RHS%E11111 + LHS%E11111*RHS%R +  &
                LHS%E1*RHS%E1111 + LHS%E1111*RHS%E1 + LHS%E11*RHS%E111 + LHS%E111*RHS%E11
      RES%E22222 = LHS%R*RHS%E22222 + LHS%E22222*RHS%R +  &
                LHS%E2*RHS%E2222 + LHS%E2222*RHS%E2 + LHS%E22*RHS%E222 + LHS%E222*RHS%E22
      RES%E33333 = LHS%R*RHS%E33333 + LHS%E33333*RHS%R +  &
                LHS%E3*RHS%E3333 + LHS%E3333*RHS%E3 + LHS%E33*RHS%E333 + LHS%E333*RHS%E33
      RES%E44444 = LHS%R*RHS%E44444 + LHS%E44444*RHS%R +  &
                LHS%E4*RHS%E4444 + LHS%E4444*RHS%E4 + LHS%E44*RHS%E444 + LHS%E444*RHS%E44
      RES%E55555 = LHS%R*RHS%E55555 + LHS%E55555*RHS%R +  &
                LHS%E5*RHS%E5555 + LHS%E5555*RHS%E5 + LHS%E55*RHS%E555 + LHS%E555*RHS%E55
      RES%E66666 = LHS%R*RHS%E66666 + LHS%E66666*RHS%R +  &
                LHS%E6*RHS%E6666 + LHS%E6666*RHS%E6 + LHS%E66*RHS%E666 + LHS%E666*RHS%E66
      RES%E77777 = LHS%R*RHS%E77777 + LHS%E77777*RHS%R +  &
                LHS%E7*RHS%E7777 + LHS%E7777*RHS%E7 + LHS%E77*RHS%E777 + LHS%E777*RHS%E77
      RES%E88888 = LHS%R*RHS%E88888 + LHS%E88888*RHS%R +  &
                LHS%E8*RHS%E8888 + LHS%E8888*RHS%E8 + LHS%E88*RHS%E888 + LHS%E888*RHS%E88
      RES%E99999 = LHS%R*RHS%E99999 + LHS%E99999*RHS%R +  &
                LHS%E9*RHS%E9999 + LHS%E9999*RHS%E9 + LHS%E99*RHS%E999 + LHS%E999*RHS%E99
      RES%EAAAAA = LHS%R*RHS%EAAAAA + LHS%EAAAAA*RHS%R +  &
                LHS%EA*RHS%EAAAA + LHS%EAAAA*RHS%EA + LHS%EAA*RHS%EAAA + LHS%EAAA*RHS%EAA
      RES%EBBBBB = LHS%R*RHS%EBBBBB + LHS%EBBBBB*RHS%R +  &
                LHS%EB*RHS%EBBBB + LHS%EBBBB*RHS%EB + LHS%EBB*RHS%EBBB + LHS%EBBB*RHS%EBB
      RES%ECCCCC = LHS%R*RHS%ECCCCC + LHS%ECCCCC*RHS%R +  &
                LHS%EC*RHS%ECCCC + LHS%ECCCC*RHS%EC + LHS%ECC*RHS%ECCC + LHS%ECCC*RHS%ECC
      RES%EDDDDD = LHS%R*RHS%EDDDDD + LHS%EDDDDD*RHS%R +  &
                LHS%ED*RHS%EDDDD + LHS%EDDDD*RHS%ED + LHS%EDD*RHS%EDDD + LHS%EDDD*RHS%EDD
      RES%EEEEEE = LHS%R*RHS%EEEEEE + LHS%EEEEEE*RHS%R +  &
                LHS%EE*RHS%EEEEE + LHS%EEEEE*RHS%EE + LHS%EEE*RHS%EEEE + LHS%EEEE*RHS%EEE
      RES%EFFFFF = LHS%R*RHS%EFFFFF + LHS%EFFFFF*RHS%R +  &
                LHS%EF*RHS%EFFFF + LHS%EFFFF*RHS%EF + LHS%EFF*RHS%EFFF + LHS%EFFF*RHS%EFF
      RES%EGGGGG = LHS%R*RHS%EGGGGG + LHS%EGGGGG*RHS%R +  &
                LHS%EG*RHS%EGGGG + LHS%EGGGG*RHS%EG + LHS%EGG*RHS%EGGG + LHS%EGGG*RHS%EGG
      RES%EHHHHH = LHS%R*RHS%EHHHHH + LHS%EHHHHH*RHS%R +  &
                LHS%EH*RHS%EHHHH + LHS%EHHHH*RHS%EH + LHS%EHH*RHS%EHHH + LHS%EHHH*RHS%EHH
      RES%EIIIII = LHS%R*RHS%EIIIII + LHS%EIIIII*RHS%R +  &
                LHS%EI*RHS%EIIII + LHS%EIIII*RHS%EI + LHS%EII*RHS%EIII + LHS%EIII*RHS%EII
      RES%EJJJJJ = LHS%R*RHS%EJJJJJ + LHS%EJJJJJ*RHS%R +  &
                LHS%EJ*RHS%EJJJJ + LHS%EJJJJ*RHS%EJ + LHS%EJJ*RHS%EJJJ + LHS%EJJJ*RHS%EJJ
      RES%EKKKKK = LHS%R*RHS%EKKKKK + LHS%EKKKKK*RHS%R +  &
                LHS%EK*RHS%EKKKK + LHS%EKKKK*RHS%EK + LHS%EKK*RHS%EKKK + LHS%EKKK*RHS%EKK
      RES%ELLLLL = LHS%R*RHS%ELLLLL + LHS%ELLLLL*RHS%R +  &
                LHS%EL*RHS%ELLLL + LHS%ELLLL*RHS%EL + LHS%ELL*RHS%ELLL + LHS%ELLL*RHS%ELL
      RES%EMMMMM = LHS%R*RHS%EMMMMM + LHS%EMMMMM*RHS%R +  &
                LHS%EM*RHS%EMMMM + LHS%EMMMM*RHS%EM + LHS%EMM*RHS%EMMM + LHS%EMMM*RHS%EMM
      ! Order 4
      RES%E1111 = LHS%R*RHS%E1111 + LHS%E1111*RHS%R +  &
               LHS%E1*RHS%E111 + LHS%E111*RHS%E1 + LHS%E11*RHS%E11
      RES%E2222 = LHS%R*RHS%E2222 + LHS%E2222*RHS%R +  &
               LHS%E2*RHS%E222 + LHS%E222*RHS%E2 + LHS%E22*RHS%E22
      RES%E3333 = LHS%R*RHS%E3333 + LHS%E3333*RHS%R +  &
               LHS%E3*RHS%E333 + LHS%E333*RHS%E3 + LHS%E33*RHS%E33
      RES%E4444 = LHS%R*RHS%E4444 + LHS%E4444*RHS%R +  &
               LHS%E4*RHS%E444 + LHS%E444*RHS%E4 + LHS%E44*RHS%E44
      RES%E5555 = LHS%R*RHS%E5555 + LHS%E5555*RHS%R +  &
               LHS%E5*RHS%E555 + LHS%E555*RHS%E5 + LHS%E55*RHS%E55
      RES%E6666 = LHS%R*RHS%E6666 + LHS%E6666*RHS%R +  &
               LHS%E6*RHS%E666 + LHS%E666*RHS%E6 + LHS%E66*RHS%E66
      RES%E7777 = LHS%R*RHS%E7777 + LHS%E7777*RHS%R +  &
               LHS%E7*RHS%E777 + LHS%E777*RHS%E7 + LHS%E77*RHS%E77
      RES%E8888 = LHS%R*RHS%E8888 + LHS%E8888*RHS%R +  &
               LHS%E8*RHS%E888 + LHS%E888*RHS%E8 + LHS%E88*RHS%E88
      RES%E9999 = LHS%R*RHS%E9999 + LHS%E9999*RHS%R +  &
               LHS%E9*RHS%E999 + LHS%E999*RHS%E9 + LHS%E99*RHS%E99
      RES%EAAAA = LHS%R*RHS%EAAAA + LHS%EAAAA*RHS%R +  &
               LHS%EA*RHS%EAAA + LHS%EAAA*RHS%EA + LHS%EAA*RHS%EAA
      RES%EBBBB = LHS%R*RHS%EBBBB + LHS%EBBBB*RHS%R +  &
               LHS%EB*RHS%EBBB + LHS%EBBB*RHS%EB + LHS%EBB*RHS%EBB
      RES%ECCCC = LHS%R*RHS%ECCCC + LHS%ECCCC*RHS%R +  &
               LHS%EC*RHS%ECCC + LHS%ECCC*RHS%EC + LHS%ECC*RHS%ECC
      RES%EDDDD = LHS%R*RHS%EDDDD + LHS%EDDDD*RHS%R +  &
               LHS%ED*RHS%EDDD + LHS%EDDD*RHS%ED + LHS%EDD*RHS%EDD
      RES%EEEEE = LHS%R*RHS%EEEEE + LHS%EEEEE*RHS%R +  &
               LHS%EE*RHS%EEEE + LHS%EEEE*RHS%EE + LHS%EEE*RHS%EEE
      RES%EFFFF = LHS%R*RHS%EFFFF + LHS%EFFFF*RHS%R +  &
               LHS%EF*RHS%EFFF + LHS%EFFF*RHS%EF + LHS%EFF*RHS%EFF
      RES%EGGGG = LHS%R*RHS%EGGGG + LHS%EGGGG*RHS%R +  &
               LHS%EG*RHS%EGGG + LHS%EGGG*RHS%EG + LHS%EGG*RHS%EGG
      RES%EHHHH = LHS%R*RHS%EHHHH + LHS%EHHHH*RHS%R +  &
               LHS%EH*RHS%EHHH + LHS%EHHH*RHS%EH + LHS%EHH*RHS%EHH
      RES%EIIII = LHS%R*RHS%EIIII + LHS%EIIII*RHS%R +  &
               LHS%EI*RHS%EIII + LHS%EIII*RHS%EI + LHS%EII*RHS%EII
      RES%EJJJJ = LHS%R*RHS%EJJJJ + LHS%EJJJJ*RHS%R +  &
               LHS%EJ*RHS%EJJJ + LHS%EJJJ*RHS%EJ + LHS%EJJ*RHS%EJJ
      RES%EKKKK = LHS%R*RHS%EKKKK + LHS%EKKKK*RHS%R +  &
               LHS%EK*RHS%EKKK + LHS%EKKK*RHS%EK + LHS%EKK*RHS%EKK
      RES%ELLLL = LHS%R*RHS%ELLLL + LHS%ELLLL*RHS%R +  &
               LHS%EL*RHS%ELLL + LHS%ELLL*RHS%EL + LHS%ELL*RHS%ELL
      RES%EMMMM = LHS%R*RHS%EMMMM + LHS%EMMMM*RHS%R +  &
               LHS%EM*RHS%EMMM + LHS%EMMM*RHS%EM + LHS%EMM*RHS%EMM
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
      RES%E888 = LHS%R*RHS%E888 + LHS%E888*RHS%R +  &
              LHS%E8*RHS%E88 + LHS%E88*RHS%E8
      RES%E999 = LHS%R*RHS%E999 + LHS%E999*RHS%R +  &
              LHS%E9*RHS%E99 + LHS%E99*RHS%E9
      RES%EAAA = LHS%R*RHS%EAAA + LHS%EAAA*RHS%R +  &
              LHS%EA*RHS%EAA + LHS%EAA*RHS%EA
      RES%EBBB = LHS%R*RHS%EBBB + LHS%EBBB*RHS%R +  &
              LHS%EB*RHS%EBB + LHS%EBB*RHS%EB
      RES%ECCC = LHS%R*RHS%ECCC + LHS%ECCC*RHS%R +  &
              LHS%EC*RHS%ECC + LHS%ECC*RHS%EC
      RES%EDDD = LHS%R*RHS%EDDD + LHS%EDDD*RHS%R +  &
              LHS%ED*RHS%EDD + LHS%EDD*RHS%ED
      RES%EEEE = LHS%R*RHS%EEEE + LHS%EEEE*RHS%R +  &
              LHS%EE*RHS%EEE + LHS%EEE*RHS%EE
      RES%EFFF = LHS%R*RHS%EFFF + LHS%EFFF*RHS%R +  &
              LHS%EF*RHS%EFF + LHS%EFF*RHS%EF
      RES%EGGG = LHS%R*RHS%EGGG + LHS%EGGG*RHS%R +  &
              LHS%EG*RHS%EGG + LHS%EGG*RHS%EG
      RES%EHHH = LHS%R*RHS%EHHH + LHS%EHHH*RHS%R +  &
              LHS%EH*RHS%EHH + LHS%EHH*RHS%EH
      RES%EIII = LHS%R*RHS%EIII + LHS%EIII*RHS%R +  &
              LHS%EI*RHS%EII + LHS%EII*RHS%EI
      RES%EJJJ = LHS%R*RHS%EJJJ + LHS%EJJJ*RHS%R +  &
              LHS%EJ*RHS%EJJ + LHS%EJJ*RHS%EJ
      RES%EKKK = LHS%R*RHS%EKKK + LHS%EKKK*RHS%R +  &
              LHS%EK*RHS%EKK + LHS%EKK*RHS%EK
      RES%ELLL = LHS%R*RHS%ELLL + LHS%ELLL*RHS%R +  &
              LHS%EL*RHS%ELL + LHS%ELL*RHS%EL
      RES%EMMM = LHS%R*RHS%EMMM + LHS%EMMM*RHS%R +  &
              LHS%EM*RHS%EMM + LHS%EMM*RHS%EM
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

   END FUNCTION DONUMM22N5_MUL_OO_MS

   FUNCTION DONUMM22N5_MUL_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N5), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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

      ! Order 3
      RES%E111 = LHS*RHS%E111
      RES%E222 = LHS*RHS%E222
      RES%E333 = LHS*RHS%E333
      RES%E444 = LHS*RHS%E444
      RES%E555 = LHS*RHS%E555
      RES%E666 = LHS*RHS%E666
      RES%E777 = LHS*RHS%E777
      RES%E888 = LHS*RHS%E888
      RES%E999 = LHS*RHS%E999
      RES%EAAA = LHS*RHS%EAAA
      RES%EBBB = LHS*RHS%EBBB
      RES%ECCC = LHS*RHS%ECCC
      RES%EDDD = LHS*RHS%EDDD
      RES%EEEE = LHS*RHS%EEEE
      RES%EFFF = LHS*RHS%EFFF
      RES%EGGG = LHS*RHS%EGGG
      RES%EHHH = LHS*RHS%EHHH
      RES%EIII = LHS*RHS%EIII
      RES%EJJJ = LHS*RHS%EJJJ
      RES%EKKK = LHS*RHS%EKKK
      RES%ELLL = LHS*RHS%ELLL
      RES%EMMM = LHS*RHS%EMMM

      ! Order 4
      RES%E1111 = LHS*RHS%E1111
      RES%E2222 = LHS*RHS%E2222
      RES%E3333 = LHS*RHS%E3333
      RES%E4444 = LHS*RHS%E4444
      RES%E5555 = LHS*RHS%E5555
      RES%E6666 = LHS*RHS%E6666
      RES%E7777 = LHS*RHS%E7777
      RES%E8888 = LHS*RHS%E8888
      RES%E9999 = LHS*RHS%E9999
      RES%EAAAA = LHS*RHS%EAAAA
      RES%EBBBB = LHS*RHS%EBBBB
      RES%ECCCC = LHS*RHS%ECCCC
      RES%EDDDD = LHS*RHS%EDDDD
      RES%EEEEE = LHS*RHS%EEEEE
      RES%EFFFF = LHS*RHS%EFFFF
      RES%EGGGG = LHS*RHS%EGGGG
      RES%EHHHH = LHS*RHS%EHHHH
      RES%EIIII = LHS*RHS%EIIII
      RES%EJJJJ = LHS*RHS%EJJJJ
      RES%EKKKK = LHS*RHS%EKKKK
      RES%ELLLL = LHS*RHS%ELLLL
      RES%EMMMM = LHS*RHS%EMMMM

      ! Order 5
      RES%E11111 = LHS*RHS%E11111
      RES%E22222 = LHS*RHS%E22222
      RES%E33333 = LHS*RHS%E33333
      RES%E44444 = LHS*RHS%E44444
      RES%E55555 = LHS*RHS%E55555
      RES%E66666 = LHS*RHS%E66666
      RES%E77777 = LHS*RHS%E77777
      RES%E88888 = LHS*RHS%E88888
      RES%E99999 = LHS*RHS%E99999
      RES%EAAAAA = LHS*RHS%EAAAAA
      RES%EBBBBB = LHS*RHS%EBBBBB
      RES%ECCCCC = LHS*RHS%ECCCCC
      RES%EDDDDD = LHS*RHS%EDDDDD
      RES%EEEEEE = LHS*RHS%EEEEEE
      RES%EFFFFF = LHS*RHS%EFFFFF
      RES%EGGGGG = LHS*RHS%EGGGGG
      RES%EHHHHH = LHS*RHS%EHHHHH
      RES%EIIIII = LHS*RHS%EIIIII
      RES%EJJJJJ = LHS*RHS%EJJJJJ
      RES%EKKKKK = LHS*RHS%EKKKKK
      RES%ELLLLL = LHS*RHS%ELLLLL
      RES%EMMMMM = LHS*RHS%EMMMMM

   END FUNCTION DONUMM22N5_MUL_RO_MS

   FUNCTION DONUMM22N5_MUL_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111*RHS
      RES%E222 = LHS%E222*RHS
      RES%E333 = LHS%E333*RHS
      RES%E444 = LHS%E444*RHS
      RES%E555 = LHS%E555*RHS
      RES%E666 = LHS%E666*RHS
      RES%E777 = LHS%E777*RHS
      RES%E888 = LHS%E888*RHS
      RES%E999 = LHS%E999*RHS
      RES%EAAA = LHS%EAAA*RHS
      RES%EBBB = LHS%EBBB*RHS
      RES%ECCC = LHS%ECCC*RHS
      RES%EDDD = LHS%EDDD*RHS
      RES%EEEE = LHS%EEEE*RHS
      RES%EFFF = LHS%EFFF*RHS
      RES%EGGG = LHS%EGGG*RHS
      RES%EHHH = LHS%EHHH*RHS
      RES%EIII = LHS%EIII*RHS
      RES%EJJJ = LHS%EJJJ*RHS
      RES%EKKK = LHS%EKKK*RHS
      RES%ELLL = LHS%ELLL*RHS
      RES%EMMM = LHS%EMMM*RHS

      ! Order 4
      RES%E1111 = LHS%E1111*RHS
      RES%E2222 = LHS%E2222*RHS
      RES%E3333 = LHS%E3333*RHS
      RES%E4444 = LHS%E4444*RHS
      RES%E5555 = LHS%E5555*RHS
      RES%E6666 = LHS%E6666*RHS
      RES%E7777 = LHS%E7777*RHS
      RES%E8888 = LHS%E8888*RHS
      RES%E9999 = LHS%E9999*RHS
      RES%EAAAA = LHS%EAAAA*RHS
      RES%EBBBB = LHS%EBBBB*RHS
      RES%ECCCC = LHS%ECCCC*RHS
      RES%EDDDD = LHS%EDDDD*RHS
      RES%EEEEE = LHS%EEEEE*RHS
      RES%EFFFF = LHS%EFFFF*RHS
      RES%EGGGG = LHS%EGGGG*RHS
      RES%EHHHH = LHS%EHHHH*RHS
      RES%EIIII = LHS%EIIII*RHS
      RES%EJJJJ = LHS%EJJJJ*RHS
      RES%EKKKK = LHS%EKKKK*RHS
      RES%ELLLL = LHS%ELLLL*RHS
      RES%EMMMM = LHS%EMMMM*RHS

      ! Order 5
      RES%E11111 = LHS%E11111*RHS
      RES%E22222 = LHS%E22222*RHS
      RES%E33333 = LHS%E33333*RHS
      RES%E44444 = LHS%E44444*RHS
      RES%E55555 = LHS%E55555*RHS
      RES%E66666 = LHS%E66666*RHS
      RES%E77777 = LHS%E77777*RHS
      RES%E88888 = LHS%E88888*RHS
      RES%E99999 = LHS%E99999*RHS
      RES%EAAAAA = LHS%EAAAAA*RHS
      RES%EBBBBB = LHS%EBBBBB*RHS
      RES%ECCCCC = LHS%ECCCCC*RHS
      RES%EDDDDD = LHS%EDDDDD*RHS
      RES%EEEEEE = LHS%EEEEEE*RHS
      RES%EFFFFF = LHS%EFFFFF*RHS
      RES%EGGGGG = LHS%EGGGGG*RHS
      RES%EHHHHH = LHS%EHHHHH*RHS
      RES%EIIIII = LHS%EIIIII*RHS
      RES%EJJJJJ = LHS%EJJJJJ*RHS
      RES%EKKKKK = LHS%EKKKKK*RHS
      RES%ELLLLL = LHS%ELLLLL*RHS
      RES%EMMMMM = LHS%EMMMMM*RHS

   END FUNCTION DONUMM22N5_MUL_OR_MS

   FUNCTION DONUMM22N5_ADD_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111
      RES%E222 = LHS%E222 + RHS%E222
      RES%E333 = LHS%E333 + RHS%E333
      RES%E444 = LHS%E444 + RHS%E444
      RES%E555 = LHS%E555 + RHS%E555
      RES%E666 = LHS%E666 + RHS%E666
      RES%E777 = LHS%E777 + RHS%E777
      RES%E888 = LHS%E888 + RHS%E888
      RES%E999 = LHS%E999 + RHS%E999
      RES%EAAA = LHS%EAAA + RHS%EAAA
      RES%EBBB = LHS%EBBB + RHS%EBBB
      RES%ECCC = LHS%ECCC + RHS%ECCC
      RES%EDDD = LHS%EDDD + RHS%EDDD
      RES%EEEE = LHS%EEEE + RHS%EEEE
      RES%EFFF = LHS%EFFF + RHS%EFFF
      RES%EGGG = LHS%EGGG + RHS%EGGG
      RES%EHHH = LHS%EHHH + RHS%EHHH
      RES%EIII = LHS%EIII + RHS%EIII
      RES%EJJJ = LHS%EJJJ + RHS%EJJJ
      RES%EKKK = LHS%EKKK + RHS%EKKK
      RES%ELLL = LHS%ELLL + RHS%ELLL
      RES%EMMM = LHS%EMMM + RHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111 + RHS%E1111
      RES%E2222 = LHS%E2222 + RHS%E2222
      RES%E3333 = LHS%E3333 + RHS%E3333
      RES%E4444 = LHS%E4444 + RHS%E4444
      RES%E5555 = LHS%E5555 + RHS%E5555
      RES%E6666 = LHS%E6666 + RHS%E6666
      RES%E7777 = LHS%E7777 + RHS%E7777
      RES%E8888 = LHS%E8888 + RHS%E8888
      RES%E9999 = LHS%E9999 + RHS%E9999
      RES%EAAAA = LHS%EAAAA + RHS%EAAAA
      RES%EBBBB = LHS%EBBBB + RHS%EBBBB
      RES%ECCCC = LHS%ECCCC + RHS%ECCCC
      RES%EDDDD = LHS%EDDDD + RHS%EDDDD
      RES%EEEEE = LHS%EEEEE + RHS%EEEEE
      RES%EFFFF = LHS%EFFFF + RHS%EFFFF
      RES%EGGGG = LHS%EGGGG + RHS%EGGGG
      RES%EHHHH = LHS%EHHHH + RHS%EHHHH
      RES%EIIII = LHS%EIIII + RHS%EIIII
      RES%EJJJJ = LHS%EJJJJ + RHS%EJJJJ
      RES%EKKKK = LHS%EKKKK + RHS%EKKKK
      RES%ELLLL = LHS%ELLLL + RHS%ELLLL
      RES%EMMMM = LHS%EMMMM + RHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111 + RHS%E11111
      RES%E22222 = LHS%E22222 + RHS%E22222
      RES%E33333 = LHS%E33333 + RHS%E33333
      RES%E44444 = LHS%E44444 + RHS%E44444
      RES%E55555 = LHS%E55555 + RHS%E55555
      RES%E66666 = LHS%E66666 + RHS%E66666
      RES%E77777 = LHS%E77777 + RHS%E77777
      RES%E88888 = LHS%E88888 + RHS%E88888
      RES%E99999 = LHS%E99999 + RHS%E99999
      RES%EAAAAA = LHS%EAAAAA + RHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB + RHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC + RHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD + RHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE + RHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF + RHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG + RHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH + RHS%EHHHHH
      RES%EIIIII = LHS%EIIIII + RHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ + RHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK + RHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL + RHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM + RHS%EMMMMM

   END FUNCTION DONUMM22N5_ADD_OO_SV

   FUNCTION DONUMM22N5_ADD_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1)) 

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

      ! Order 3
      RES%E111 =  + RHS%E111
      RES%E222 =  + RHS%E222
      RES%E333 =  + RHS%E333
      RES%E444 =  + RHS%E444
      RES%E555 =  + RHS%E555
      RES%E666 =  + RHS%E666
      RES%E777 =  + RHS%E777
      RES%E888 =  + RHS%E888
      RES%E999 =  + RHS%E999
      RES%EAAA =  + RHS%EAAA
      RES%EBBB =  + RHS%EBBB
      RES%ECCC =  + RHS%ECCC
      RES%EDDD =  + RHS%EDDD
      RES%EEEE =  + RHS%EEEE
      RES%EFFF =  + RHS%EFFF
      RES%EGGG =  + RHS%EGGG
      RES%EHHH =  + RHS%EHHH
      RES%EIII =  + RHS%EIII
      RES%EJJJ =  + RHS%EJJJ
      RES%EKKK =  + RHS%EKKK
      RES%ELLL =  + RHS%ELLL
      RES%EMMM =  + RHS%EMMM

      ! Order 4
      RES%E1111 =  + RHS%E1111
      RES%E2222 =  + RHS%E2222
      RES%E3333 =  + RHS%E3333
      RES%E4444 =  + RHS%E4444
      RES%E5555 =  + RHS%E5555
      RES%E6666 =  + RHS%E6666
      RES%E7777 =  + RHS%E7777
      RES%E8888 =  + RHS%E8888
      RES%E9999 =  + RHS%E9999
      RES%EAAAA =  + RHS%EAAAA
      RES%EBBBB =  + RHS%EBBBB
      RES%ECCCC =  + RHS%ECCCC
      RES%EDDDD =  + RHS%EDDDD
      RES%EEEEE =  + RHS%EEEEE
      RES%EFFFF =  + RHS%EFFFF
      RES%EGGGG =  + RHS%EGGGG
      RES%EHHHH =  + RHS%EHHHH
      RES%EIIII =  + RHS%EIIII
      RES%EJJJJ =  + RHS%EJJJJ
      RES%EKKKK =  + RHS%EKKKK
      RES%ELLLL =  + RHS%ELLLL
      RES%EMMMM =  + RHS%EMMMM

      ! Order 5
      RES%E11111 =  + RHS%E11111
      RES%E22222 =  + RHS%E22222
      RES%E33333 =  + RHS%E33333
      RES%E44444 =  + RHS%E44444
      RES%E55555 =  + RHS%E55555
      RES%E66666 =  + RHS%E66666
      RES%E77777 =  + RHS%E77777
      RES%E88888 =  + RHS%E88888
      RES%E99999 =  + RHS%E99999
      RES%EAAAAA =  + RHS%EAAAAA
      RES%EBBBBB =  + RHS%EBBBBB
      RES%ECCCCC =  + RHS%ECCCCC
      RES%EDDDDD =  + RHS%EDDDDD
      RES%EEEEEE =  + RHS%EEEEEE
      RES%EFFFFF =  + RHS%EFFFFF
      RES%EGGGGG =  + RHS%EGGGGG
      RES%EHHHHH =  + RHS%EHHHHH
      RES%EIIIII =  + RHS%EIIIII
      RES%EJJJJJ =  + RHS%EJJJJJ
      RES%EKKKKK =  + RHS%EKKKKK
      RES%ELLLLL =  + RHS%ELLLLL
      RES%EMMMMM =  + RHS%EMMMMM

   END FUNCTION DONUMM22N5_ADD_RO_SV

   FUNCTION DONUMM22N5_ADD_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777
      RES%E888 = LHS%E888
      RES%E999 = LHS%E999
      RES%EAAA = LHS%EAAA
      RES%EBBB = LHS%EBBB
      RES%ECCC = LHS%ECCC
      RES%EDDD = LHS%EDDD
      RES%EEEE = LHS%EEEE
      RES%EFFF = LHS%EFFF
      RES%EGGG = LHS%EGGG
      RES%EHHH = LHS%EHHH
      RES%EIII = LHS%EIII
      RES%EJJJ = LHS%EJJJ
      RES%EKKK = LHS%EKKK
      RES%ELLL = LHS%ELLL
      RES%EMMM = LHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111
      RES%E2222 = LHS%E2222
      RES%E3333 = LHS%E3333
      RES%E4444 = LHS%E4444
      RES%E5555 = LHS%E5555
      RES%E6666 = LHS%E6666
      RES%E7777 = LHS%E7777
      RES%E8888 = LHS%E8888
      RES%E9999 = LHS%E9999
      RES%EAAAA = LHS%EAAAA
      RES%EBBBB = LHS%EBBBB
      RES%ECCCC = LHS%ECCCC
      RES%EDDDD = LHS%EDDDD
      RES%EEEEE = LHS%EEEEE
      RES%EFFFF = LHS%EFFFF
      RES%EGGGG = LHS%EGGGG
      RES%EHHHH = LHS%EHHHH
      RES%EIIII = LHS%EIIII
      RES%EJJJJ = LHS%EJJJJ
      RES%EKKKK = LHS%EKKKK
      RES%ELLLL = LHS%ELLLL
      RES%EMMMM = LHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111
      RES%E22222 = LHS%E22222
      RES%E33333 = LHS%E33333
      RES%E44444 = LHS%E44444
      RES%E55555 = LHS%E55555
      RES%E66666 = LHS%E66666
      RES%E77777 = LHS%E77777
      RES%E88888 = LHS%E88888
      RES%E99999 = LHS%E99999
      RES%EAAAAA = LHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH
      RES%EIIIII = LHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM

   END FUNCTION DONUMM22N5_ADD_OR_SV

   FUNCTION DONUMM22N5_SUB_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111
      RES%E222 = LHS%E222 - RHS%E222
      RES%E333 = LHS%E333 - RHS%E333
      RES%E444 = LHS%E444 - RHS%E444
      RES%E555 = LHS%E555 - RHS%E555
      RES%E666 = LHS%E666 - RHS%E666
      RES%E777 = LHS%E777 - RHS%E777
      RES%E888 = LHS%E888 - RHS%E888
      RES%E999 = LHS%E999 - RHS%E999
      RES%EAAA = LHS%EAAA - RHS%EAAA
      RES%EBBB = LHS%EBBB - RHS%EBBB
      RES%ECCC = LHS%ECCC - RHS%ECCC
      RES%EDDD = LHS%EDDD - RHS%EDDD
      RES%EEEE = LHS%EEEE - RHS%EEEE
      RES%EFFF = LHS%EFFF - RHS%EFFF
      RES%EGGG = LHS%EGGG - RHS%EGGG
      RES%EHHH = LHS%EHHH - RHS%EHHH
      RES%EIII = LHS%EIII - RHS%EIII
      RES%EJJJ = LHS%EJJJ - RHS%EJJJ
      RES%EKKK = LHS%EKKK - RHS%EKKK
      RES%ELLL = LHS%ELLL - RHS%ELLL
      RES%EMMM = LHS%EMMM - RHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111 - RHS%E1111
      RES%E2222 = LHS%E2222 - RHS%E2222
      RES%E3333 = LHS%E3333 - RHS%E3333
      RES%E4444 = LHS%E4444 - RHS%E4444
      RES%E5555 = LHS%E5555 - RHS%E5555
      RES%E6666 = LHS%E6666 - RHS%E6666
      RES%E7777 = LHS%E7777 - RHS%E7777
      RES%E8888 = LHS%E8888 - RHS%E8888
      RES%E9999 = LHS%E9999 - RHS%E9999
      RES%EAAAA = LHS%EAAAA - RHS%EAAAA
      RES%EBBBB = LHS%EBBBB - RHS%EBBBB
      RES%ECCCC = LHS%ECCCC - RHS%ECCCC
      RES%EDDDD = LHS%EDDDD - RHS%EDDDD
      RES%EEEEE = LHS%EEEEE - RHS%EEEEE
      RES%EFFFF = LHS%EFFFF - RHS%EFFFF
      RES%EGGGG = LHS%EGGGG - RHS%EGGGG
      RES%EHHHH = LHS%EHHHH - RHS%EHHHH
      RES%EIIII = LHS%EIIII - RHS%EIIII
      RES%EJJJJ = LHS%EJJJJ - RHS%EJJJJ
      RES%EKKKK = LHS%EKKKK - RHS%EKKKK
      RES%ELLLL = LHS%ELLLL - RHS%ELLLL
      RES%EMMMM = LHS%EMMMM - RHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111 - RHS%E11111
      RES%E22222 = LHS%E22222 - RHS%E22222
      RES%E33333 = LHS%E33333 - RHS%E33333
      RES%E44444 = LHS%E44444 - RHS%E44444
      RES%E55555 = LHS%E55555 - RHS%E55555
      RES%E66666 = LHS%E66666 - RHS%E66666
      RES%E77777 = LHS%E77777 - RHS%E77777
      RES%E88888 = LHS%E88888 - RHS%E88888
      RES%E99999 = LHS%E99999 - RHS%E99999
      RES%EAAAAA = LHS%EAAAAA - RHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB - RHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC - RHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD - RHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE - RHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF - RHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG - RHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH - RHS%EHHHHH
      RES%EIIIII = LHS%EIIIII - RHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ - RHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK - RHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL - RHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM - RHS%EMMMMM

   END FUNCTION DONUMM22N5_SUB_OO_SV

   FUNCTION DONUMM22N5_SUB_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1)) 

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

      ! Order 3
      RES%E111 =  - RHS%E111
      RES%E222 =  - RHS%E222
      RES%E333 =  - RHS%E333
      RES%E444 =  - RHS%E444
      RES%E555 =  - RHS%E555
      RES%E666 =  - RHS%E666
      RES%E777 =  - RHS%E777
      RES%E888 =  - RHS%E888
      RES%E999 =  - RHS%E999
      RES%EAAA =  - RHS%EAAA
      RES%EBBB =  - RHS%EBBB
      RES%ECCC =  - RHS%ECCC
      RES%EDDD =  - RHS%EDDD
      RES%EEEE =  - RHS%EEEE
      RES%EFFF =  - RHS%EFFF
      RES%EGGG =  - RHS%EGGG
      RES%EHHH =  - RHS%EHHH
      RES%EIII =  - RHS%EIII
      RES%EJJJ =  - RHS%EJJJ
      RES%EKKK =  - RHS%EKKK
      RES%ELLL =  - RHS%ELLL
      RES%EMMM =  - RHS%EMMM

      ! Order 4
      RES%E1111 =  - RHS%E1111
      RES%E2222 =  - RHS%E2222
      RES%E3333 =  - RHS%E3333
      RES%E4444 =  - RHS%E4444
      RES%E5555 =  - RHS%E5555
      RES%E6666 =  - RHS%E6666
      RES%E7777 =  - RHS%E7777
      RES%E8888 =  - RHS%E8888
      RES%E9999 =  - RHS%E9999
      RES%EAAAA =  - RHS%EAAAA
      RES%EBBBB =  - RHS%EBBBB
      RES%ECCCC =  - RHS%ECCCC
      RES%EDDDD =  - RHS%EDDDD
      RES%EEEEE =  - RHS%EEEEE
      RES%EFFFF =  - RHS%EFFFF
      RES%EGGGG =  - RHS%EGGGG
      RES%EHHHH =  - RHS%EHHHH
      RES%EIIII =  - RHS%EIIII
      RES%EJJJJ =  - RHS%EJJJJ
      RES%EKKKK =  - RHS%EKKKK
      RES%ELLLL =  - RHS%ELLLL
      RES%EMMMM =  - RHS%EMMMM

      ! Order 5
      RES%E11111 =  - RHS%E11111
      RES%E22222 =  - RHS%E22222
      RES%E33333 =  - RHS%E33333
      RES%E44444 =  - RHS%E44444
      RES%E55555 =  - RHS%E55555
      RES%E66666 =  - RHS%E66666
      RES%E77777 =  - RHS%E77777
      RES%E88888 =  - RHS%E88888
      RES%E99999 =  - RHS%E99999
      RES%EAAAAA =  - RHS%EAAAAA
      RES%EBBBBB =  - RHS%EBBBBB
      RES%ECCCCC =  - RHS%ECCCCC
      RES%EDDDDD =  - RHS%EDDDDD
      RES%EEEEEE =  - RHS%EEEEEE
      RES%EFFFFF =  - RHS%EFFFFF
      RES%EGGGGG =  - RHS%EGGGGG
      RES%EHHHHH =  - RHS%EHHHHH
      RES%EIIIII =  - RHS%EIIIII
      RES%EJJJJJ =  - RHS%EJJJJJ
      RES%EKKKKK =  - RHS%EKKKKK
      RES%ELLLLL =  - RHS%ELLLLL
      RES%EMMMMM =  - RHS%EMMMMM

   END FUNCTION DONUMM22N5_SUB_RO_SV

   FUNCTION DONUMM22N5_SUB_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777
      RES%E888 = LHS%E888
      RES%E999 = LHS%E999
      RES%EAAA = LHS%EAAA
      RES%EBBB = LHS%EBBB
      RES%ECCC = LHS%ECCC
      RES%EDDD = LHS%EDDD
      RES%EEEE = LHS%EEEE
      RES%EFFF = LHS%EFFF
      RES%EGGG = LHS%EGGG
      RES%EHHH = LHS%EHHH
      RES%EIII = LHS%EIII
      RES%EJJJ = LHS%EJJJ
      RES%EKKK = LHS%EKKK
      RES%ELLL = LHS%ELLL
      RES%EMMM = LHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111
      RES%E2222 = LHS%E2222
      RES%E3333 = LHS%E3333
      RES%E4444 = LHS%E4444
      RES%E5555 = LHS%E5555
      RES%E6666 = LHS%E6666
      RES%E7777 = LHS%E7777
      RES%E8888 = LHS%E8888
      RES%E9999 = LHS%E9999
      RES%EAAAA = LHS%EAAAA
      RES%EBBBB = LHS%EBBBB
      RES%ECCCC = LHS%ECCCC
      RES%EDDDD = LHS%EDDDD
      RES%EEEEE = LHS%EEEEE
      RES%EFFFF = LHS%EFFFF
      RES%EGGGG = LHS%EGGGG
      RES%EHHHH = LHS%EHHHH
      RES%EIIII = LHS%EIIII
      RES%EJJJJ = LHS%EJJJJ
      RES%EKKKK = LHS%EKKKK
      RES%ELLLL = LHS%ELLLL
      RES%EMMMM = LHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111
      RES%E22222 = LHS%E22222
      RES%E33333 = LHS%E33333
      RES%E44444 = LHS%E44444
      RES%E55555 = LHS%E55555
      RES%E66666 = LHS%E66666
      RES%E77777 = LHS%E77777
      RES%E88888 = LHS%E88888
      RES%E99999 = LHS%E99999
      RES%EAAAAA = LHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH
      RES%EIIIII = LHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM

   END FUNCTION DONUMM22N5_SUB_OR_SV

   FUNCTION DONUMM22N5_MUL_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 5
      RES%E11111 = LHS%R*RHS%E11111 + LHS%E11111*RHS%R +  &
                LHS%E1*RHS%E1111 + LHS%E1111*RHS%E1 + LHS%E11*RHS%E111 + LHS%E111*RHS%E11
      RES%E22222 = LHS%R*RHS%E22222 + LHS%E22222*RHS%R +  &
                LHS%E2*RHS%E2222 + LHS%E2222*RHS%E2 + LHS%E22*RHS%E222 + LHS%E222*RHS%E22
      RES%E33333 = LHS%R*RHS%E33333 + LHS%E33333*RHS%R +  &
                LHS%E3*RHS%E3333 + LHS%E3333*RHS%E3 + LHS%E33*RHS%E333 + LHS%E333*RHS%E33
      RES%E44444 = LHS%R*RHS%E44444 + LHS%E44444*RHS%R +  &
                LHS%E4*RHS%E4444 + LHS%E4444*RHS%E4 + LHS%E44*RHS%E444 + LHS%E444*RHS%E44
      RES%E55555 = LHS%R*RHS%E55555 + LHS%E55555*RHS%R +  &
                LHS%E5*RHS%E5555 + LHS%E5555*RHS%E5 + LHS%E55*RHS%E555 + LHS%E555*RHS%E55
      RES%E66666 = LHS%R*RHS%E66666 + LHS%E66666*RHS%R +  &
                LHS%E6*RHS%E6666 + LHS%E6666*RHS%E6 + LHS%E66*RHS%E666 + LHS%E666*RHS%E66
      RES%E77777 = LHS%R*RHS%E77777 + LHS%E77777*RHS%R +  &
                LHS%E7*RHS%E7777 + LHS%E7777*RHS%E7 + LHS%E77*RHS%E777 + LHS%E777*RHS%E77
      RES%E88888 = LHS%R*RHS%E88888 + LHS%E88888*RHS%R +  &
                LHS%E8*RHS%E8888 + LHS%E8888*RHS%E8 + LHS%E88*RHS%E888 + LHS%E888*RHS%E88
      RES%E99999 = LHS%R*RHS%E99999 + LHS%E99999*RHS%R +  &
                LHS%E9*RHS%E9999 + LHS%E9999*RHS%E9 + LHS%E99*RHS%E999 + LHS%E999*RHS%E99
      RES%EAAAAA = LHS%R*RHS%EAAAAA + LHS%EAAAAA*RHS%R +  &
                LHS%EA*RHS%EAAAA + LHS%EAAAA*RHS%EA + LHS%EAA*RHS%EAAA + LHS%EAAA*RHS%EAA
      RES%EBBBBB = LHS%R*RHS%EBBBBB + LHS%EBBBBB*RHS%R +  &
                LHS%EB*RHS%EBBBB + LHS%EBBBB*RHS%EB + LHS%EBB*RHS%EBBB + LHS%EBBB*RHS%EBB
      RES%ECCCCC = LHS%R*RHS%ECCCCC + LHS%ECCCCC*RHS%R +  &
                LHS%EC*RHS%ECCCC + LHS%ECCCC*RHS%EC + LHS%ECC*RHS%ECCC + LHS%ECCC*RHS%ECC
      RES%EDDDDD = LHS%R*RHS%EDDDDD + LHS%EDDDDD*RHS%R +  &
                LHS%ED*RHS%EDDDD + LHS%EDDDD*RHS%ED + LHS%EDD*RHS%EDDD + LHS%EDDD*RHS%EDD
      RES%EEEEEE = LHS%R*RHS%EEEEEE + LHS%EEEEEE*RHS%R +  &
                LHS%EE*RHS%EEEEE + LHS%EEEEE*RHS%EE + LHS%EEE*RHS%EEEE + LHS%EEEE*RHS%EEE
      RES%EFFFFF = LHS%R*RHS%EFFFFF + LHS%EFFFFF*RHS%R +  &
                LHS%EF*RHS%EFFFF + LHS%EFFFF*RHS%EF + LHS%EFF*RHS%EFFF + LHS%EFFF*RHS%EFF
      RES%EGGGGG = LHS%R*RHS%EGGGGG + LHS%EGGGGG*RHS%R +  &
                LHS%EG*RHS%EGGGG + LHS%EGGGG*RHS%EG + LHS%EGG*RHS%EGGG + LHS%EGGG*RHS%EGG
      RES%EHHHHH = LHS%R*RHS%EHHHHH + LHS%EHHHHH*RHS%R +  &
                LHS%EH*RHS%EHHHH + LHS%EHHHH*RHS%EH + LHS%EHH*RHS%EHHH + LHS%EHHH*RHS%EHH
      RES%EIIIII = LHS%R*RHS%EIIIII + LHS%EIIIII*RHS%R +  &
                LHS%EI*RHS%EIIII + LHS%EIIII*RHS%EI + LHS%EII*RHS%EIII + LHS%EIII*RHS%EII
      RES%EJJJJJ = LHS%R*RHS%EJJJJJ + LHS%EJJJJJ*RHS%R +  &
                LHS%EJ*RHS%EJJJJ + LHS%EJJJJ*RHS%EJ + LHS%EJJ*RHS%EJJJ + LHS%EJJJ*RHS%EJJ
      RES%EKKKKK = LHS%R*RHS%EKKKKK + LHS%EKKKKK*RHS%R +  &
                LHS%EK*RHS%EKKKK + LHS%EKKKK*RHS%EK + LHS%EKK*RHS%EKKK + LHS%EKKK*RHS%EKK
      RES%ELLLLL = LHS%R*RHS%ELLLLL + LHS%ELLLLL*RHS%R +  &
                LHS%EL*RHS%ELLLL + LHS%ELLLL*RHS%EL + LHS%ELL*RHS%ELLL + LHS%ELLL*RHS%ELL
      RES%EMMMMM = LHS%R*RHS%EMMMMM + LHS%EMMMMM*RHS%R +  &
                LHS%EM*RHS%EMMMM + LHS%EMMMM*RHS%EM + LHS%EMM*RHS%EMMM + LHS%EMMM*RHS%EMM
      ! Order 4
      RES%E1111 = LHS%R*RHS%E1111 + LHS%E1111*RHS%R +  &
               LHS%E1*RHS%E111 + LHS%E111*RHS%E1 + LHS%E11*RHS%E11
      RES%E2222 = LHS%R*RHS%E2222 + LHS%E2222*RHS%R +  &
               LHS%E2*RHS%E222 + LHS%E222*RHS%E2 + LHS%E22*RHS%E22
      RES%E3333 = LHS%R*RHS%E3333 + LHS%E3333*RHS%R +  &
               LHS%E3*RHS%E333 + LHS%E333*RHS%E3 + LHS%E33*RHS%E33
      RES%E4444 = LHS%R*RHS%E4444 + LHS%E4444*RHS%R +  &
               LHS%E4*RHS%E444 + LHS%E444*RHS%E4 + LHS%E44*RHS%E44
      RES%E5555 = LHS%R*RHS%E5555 + LHS%E5555*RHS%R +  &
               LHS%E5*RHS%E555 + LHS%E555*RHS%E5 + LHS%E55*RHS%E55
      RES%E6666 = LHS%R*RHS%E6666 + LHS%E6666*RHS%R +  &
               LHS%E6*RHS%E666 + LHS%E666*RHS%E6 + LHS%E66*RHS%E66
      RES%E7777 = LHS%R*RHS%E7777 + LHS%E7777*RHS%R +  &
               LHS%E7*RHS%E777 + LHS%E777*RHS%E7 + LHS%E77*RHS%E77
      RES%E8888 = LHS%R*RHS%E8888 + LHS%E8888*RHS%R +  &
               LHS%E8*RHS%E888 + LHS%E888*RHS%E8 + LHS%E88*RHS%E88
      RES%E9999 = LHS%R*RHS%E9999 + LHS%E9999*RHS%R +  &
               LHS%E9*RHS%E999 + LHS%E999*RHS%E9 + LHS%E99*RHS%E99
      RES%EAAAA = LHS%R*RHS%EAAAA + LHS%EAAAA*RHS%R +  &
               LHS%EA*RHS%EAAA + LHS%EAAA*RHS%EA + LHS%EAA*RHS%EAA
      RES%EBBBB = LHS%R*RHS%EBBBB + LHS%EBBBB*RHS%R +  &
               LHS%EB*RHS%EBBB + LHS%EBBB*RHS%EB + LHS%EBB*RHS%EBB
      RES%ECCCC = LHS%R*RHS%ECCCC + LHS%ECCCC*RHS%R +  &
               LHS%EC*RHS%ECCC + LHS%ECCC*RHS%EC + LHS%ECC*RHS%ECC
      RES%EDDDD = LHS%R*RHS%EDDDD + LHS%EDDDD*RHS%R +  &
               LHS%ED*RHS%EDDD + LHS%EDDD*RHS%ED + LHS%EDD*RHS%EDD
      RES%EEEEE = LHS%R*RHS%EEEEE + LHS%EEEEE*RHS%R +  &
               LHS%EE*RHS%EEEE + LHS%EEEE*RHS%EE + LHS%EEE*RHS%EEE
      RES%EFFFF = LHS%R*RHS%EFFFF + LHS%EFFFF*RHS%R +  &
               LHS%EF*RHS%EFFF + LHS%EFFF*RHS%EF + LHS%EFF*RHS%EFF
      RES%EGGGG = LHS%R*RHS%EGGGG + LHS%EGGGG*RHS%R +  &
               LHS%EG*RHS%EGGG + LHS%EGGG*RHS%EG + LHS%EGG*RHS%EGG
      RES%EHHHH = LHS%R*RHS%EHHHH + LHS%EHHHH*RHS%R +  &
               LHS%EH*RHS%EHHH + LHS%EHHH*RHS%EH + LHS%EHH*RHS%EHH
      RES%EIIII = LHS%R*RHS%EIIII + LHS%EIIII*RHS%R +  &
               LHS%EI*RHS%EIII + LHS%EIII*RHS%EI + LHS%EII*RHS%EII
      RES%EJJJJ = LHS%R*RHS%EJJJJ + LHS%EJJJJ*RHS%R +  &
               LHS%EJ*RHS%EJJJ + LHS%EJJJ*RHS%EJ + LHS%EJJ*RHS%EJJ
      RES%EKKKK = LHS%R*RHS%EKKKK + LHS%EKKKK*RHS%R +  &
               LHS%EK*RHS%EKKK + LHS%EKKK*RHS%EK + LHS%EKK*RHS%EKK
      RES%ELLLL = LHS%R*RHS%ELLLL + LHS%ELLLL*RHS%R +  &
               LHS%EL*RHS%ELLL + LHS%ELLL*RHS%EL + LHS%ELL*RHS%ELL
      RES%EMMMM = LHS%R*RHS%EMMMM + LHS%EMMMM*RHS%R +  &
               LHS%EM*RHS%EMMM + LHS%EMMM*RHS%EM + LHS%EMM*RHS%EMM
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
      RES%E888 = LHS%R*RHS%E888 + LHS%E888*RHS%R +  &
              LHS%E8*RHS%E88 + LHS%E88*RHS%E8
      RES%E999 = LHS%R*RHS%E999 + LHS%E999*RHS%R +  &
              LHS%E9*RHS%E99 + LHS%E99*RHS%E9
      RES%EAAA = LHS%R*RHS%EAAA + LHS%EAAA*RHS%R +  &
              LHS%EA*RHS%EAA + LHS%EAA*RHS%EA
      RES%EBBB = LHS%R*RHS%EBBB + LHS%EBBB*RHS%R +  &
              LHS%EB*RHS%EBB + LHS%EBB*RHS%EB
      RES%ECCC = LHS%R*RHS%ECCC + LHS%ECCC*RHS%R +  &
              LHS%EC*RHS%ECC + LHS%ECC*RHS%EC
      RES%EDDD = LHS%R*RHS%EDDD + LHS%EDDD*RHS%R +  &
              LHS%ED*RHS%EDD + LHS%EDD*RHS%ED
      RES%EEEE = LHS%R*RHS%EEEE + LHS%EEEE*RHS%R +  &
              LHS%EE*RHS%EEE + LHS%EEE*RHS%EE
      RES%EFFF = LHS%R*RHS%EFFF + LHS%EFFF*RHS%R +  &
              LHS%EF*RHS%EFF + LHS%EFF*RHS%EF
      RES%EGGG = LHS%R*RHS%EGGG + LHS%EGGG*RHS%R +  &
              LHS%EG*RHS%EGG + LHS%EGG*RHS%EG
      RES%EHHH = LHS%R*RHS%EHHH + LHS%EHHH*RHS%R +  &
              LHS%EH*RHS%EHH + LHS%EHH*RHS%EH
      RES%EIII = LHS%R*RHS%EIII + LHS%EIII*RHS%R +  &
              LHS%EI*RHS%EII + LHS%EII*RHS%EI
      RES%EJJJ = LHS%R*RHS%EJJJ + LHS%EJJJ*RHS%R +  &
              LHS%EJ*RHS%EJJ + LHS%EJJ*RHS%EJ
      RES%EKKK = LHS%R*RHS%EKKK + LHS%EKKK*RHS%R +  &
              LHS%EK*RHS%EKK + LHS%EKK*RHS%EK
      RES%ELLL = LHS%R*RHS%ELLL + LHS%ELLL*RHS%R +  &
              LHS%EL*RHS%ELL + LHS%ELL*RHS%EL
      RES%EMMM = LHS%R*RHS%EMMM + LHS%EMMM*RHS%R +  &
              LHS%EM*RHS%EMM + LHS%EMM*RHS%EM
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

   END FUNCTION DONUMM22N5_MUL_OO_SV

   FUNCTION DONUMM22N5_MUL_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1)) 

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

      ! Order 3
      RES%E111 = LHS*RHS%E111
      RES%E222 = LHS*RHS%E222
      RES%E333 = LHS*RHS%E333
      RES%E444 = LHS*RHS%E444
      RES%E555 = LHS*RHS%E555
      RES%E666 = LHS*RHS%E666
      RES%E777 = LHS*RHS%E777
      RES%E888 = LHS*RHS%E888
      RES%E999 = LHS*RHS%E999
      RES%EAAA = LHS*RHS%EAAA
      RES%EBBB = LHS*RHS%EBBB
      RES%ECCC = LHS*RHS%ECCC
      RES%EDDD = LHS*RHS%EDDD
      RES%EEEE = LHS*RHS%EEEE
      RES%EFFF = LHS*RHS%EFFF
      RES%EGGG = LHS*RHS%EGGG
      RES%EHHH = LHS*RHS%EHHH
      RES%EIII = LHS*RHS%EIII
      RES%EJJJ = LHS*RHS%EJJJ
      RES%EKKK = LHS*RHS%EKKK
      RES%ELLL = LHS*RHS%ELLL
      RES%EMMM = LHS*RHS%EMMM

      ! Order 4
      RES%E1111 = LHS*RHS%E1111
      RES%E2222 = LHS*RHS%E2222
      RES%E3333 = LHS*RHS%E3333
      RES%E4444 = LHS*RHS%E4444
      RES%E5555 = LHS*RHS%E5555
      RES%E6666 = LHS*RHS%E6666
      RES%E7777 = LHS*RHS%E7777
      RES%E8888 = LHS*RHS%E8888
      RES%E9999 = LHS*RHS%E9999
      RES%EAAAA = LHS*RHS%EAAAA
      RES%EBBBB = LHS*RHS%EBBBB
      RES%ECCCC = LHS*RHS%ECCCC
      RES%EDDDD = LHS*RHS%EDDDD
      RES%EEEEE = LHS*RHS%EEEEE
      RES%EFFFF = LHS*RHS%EFFFF
      RES%EGGGG = LHS*RHS%EGGGG
      RES%EHHHH = LHS*RHS%EHHHH
      RES%EIIII = LHS*RHS%EIIII
      RES%EJJJJ = LHS*RHS%EJJJJ
      RES%EKKKK = LHS*RHS%EKKKK
      RES%ELLLL = LHS*RHS%ELLLL
      RES%EMMMM = LHS*RHS%EMMMM

      ! Order 5
      RES%E11111 = LHS*RHS%E11111
      RES%E22222 = LHS*RHS%E22222
      RES%E33333 = LHS*RHS%E33333
      RES%E44444 = LHS*RHS%E44444
      RES%E55555 = LHS*RHS%E55555
      RES%E66666 = LHS*RHS%E66666
      RES%E77777 = LHS*RHS%E77777
      RES%E88888 = LHS*RHS%E88888
      RES%E99999 = LHS*RHS%E99999
      RES%EAAAAA = LHS*RHS%EAAAAA
      RES%EBBBBB = LHS*RHS%EBBBBB
      RES%ECCCCC = LHS*RHS%ECCCCC
      RES%EDDDDD = LHS*RHS%EDDDDD
      RES%EEEEEE = LHS*RHS%EEEEEE
      RES%EFFFFF = LHS*RHS%EFFFFF
      RES%EGGGGG = LHS*RHS%EGGGGG
      RES%EHHHHH = LHS*RHS%EHHHHH
      RES%EIIIII = LHS*RHS%EIIIII
      RES%EJJJJJ = LHS*RHS%EJJJJJ
      RES%EKKKKK = LHS*RHS%EKKKKK
      RES%ELLLLL = LHS*RHS%ELLLLL
      RES%EMMMMM = LHS*RHS%EMMMMM

   END FUNCTION DONUMM22N5_MUL_RO_SV

   FUNCTION DONUMM22N5_MUL_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111*RHS
      RES%E222 = LHS%E222*RHS
      RES%E333 = LHS%E333*RHS
      RES%E444 = LHS%E444*RHS
      RES%E555 = LHS%E555*RHS
      RES%E666 = LHS%E666*RHS
      RES%E777 = LHS%E777*RHS
      RES%E888 = LHS%E888*RHS
      RES%E999 = LHS%E999*RHS
      RES%EAAA = LHS%EAAA*RHS
      RES%EBBB = LHS%EBBB*RHS
      RES%ECCC = LHS%ECCC*RHS
      RES%EDDD = LHS%EDDD*RHS
      RES%EEEE = LHS%EEEE*RHS
      RES%EFFF = LHS%EFFF*RHS
      RES%EGGG = LHS%EGGG*RHS
      RES%EHHH = LHS%EHHH*RHS
      RES%EIII = LHS%EIII*RHS
      RES%EJJJ = LHS%EJJJ*RHS
      RES%EKKK = LHS%EKKK*RHS
      RES%ELLL = LHS%ELLL*RHS
      RES%EMMM = LHS%EMMM*RHS

      ! Order 4
      RES%E1111 = LHS%E1111*RHS
      RES%E2222 = LHS%E2222*RHS
      RES%E3333 = LHS%E3333*RHS
      RES%E4444 = LHS%E4444*RHS
      RES%E5555 = LHS%E5555*RHS
      RES%E6666 = LHS%E6666*RHS
      RES%E7777 = LHS%E7777*RHS
      RES%E8888 = LHS%E8888*RHS
      RES%E9999 = LHS%E9999*RHS
      RES%EAAAA = LHS%EAAAA*RHS
      RES%EBBBB = LHS%EBBBB*RHS
      RES%ECCCC = LHS%ECCCC*RHS
      RES%EDDDD = LHS%EDDDD*RHS
      RES%EEEEE = LHS%EEEEE*RHS
      RES%EFFFF = LHS%EFFFF*RHS
      RES%EGGGG = LHS%EGGGG*RHS
      RES%EHHHH = LHS%EHHHH*RHS
      RES%EIIII = LHS%EIIII*RHS
      RES%EJJJJ = LHS%EJJJJ*RHS
      RES%EKKKK = LHS%EKKKK*RHS
      RES%ELLLL = LHS%ELLLL*RHS
      RES%EMMMM = LHS%EMMMM*RHS

      ! Order 5
      RES%E11111 = LHS%E11111*RHS
      RES%E22222 = LHS%E22222*RHS
      RES%E33333 = LHS%E33333*RHS
      RES%E44444 = LHS%E44444*RHS
      RES%E55555 = LHS%E55555*RHS
      RES%E66666 = LHS%E66666*RHS
      RES%E77777 = LHS%E77777*RHS
      RES%E88888 = LHS%E88888*RHS
      RES%E99999 = LHS%E99999*RHS
      RES%EAAAAA = LHS%EAAAAA*RHS
      RES%EBBBBB = LHS%EBBBBB*RHS
      RES%ECCCCC = LHS%ECCCCC*RHS
      RES%EDDDDD = LHS%EDDDDD*RHS
      RES%EEEEEE = LHS%EEEEEE*RHS
      RES%EFFFFF = LHS%EFFFFF*RHS
      RES%EGGGGG = LHS%EGGGGG*RHS
      RES%EHHHHH = LHS%EHHHHH*RHS
      RES%EIIIII = LHS%EIIIII*RHS
      RES%EJJJJJ = LHS%EJJJJJ*RHS
      RES%EKKKKK = LHS%EKKKKK*RHS
      RES%ELLLLL = LHS%ELLLLL*RHS
      RES%EMMMMM = LHS%EMMMMM*RHS

   END FUNCTION DONUMM22N5_MUL_OR_SV

   FUNCTION DONUMM22N5_ADD_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111
      RES%E222 = LHS%E222 + RHS%E222
      RES%E333 = LHS%E333 + RHS%E333
      RES%E444 = LHS%E444 + RHS%E444
      RES%E555 = LHS%E555 + RHS%E555
      RES%E666 = LHS%E666 + RHS%E666
      RES%E777 = LHS%E777 + RHS%E777
      RES%E888 = LHS%E888 + RHS%E888
      RES%E999 = LHS%E999 + RHS%E999
      RES%EAAA = LHS%EAAA + RHS%EAAA
      RES%EBBB = LHS%EBBB + RHS%EBBB
      RES%ECCC = LHS%ECCC + RHS%ECCC
      RES%EDDD = LHS%EDDD + RHS%EDDD
      RES%EEEE = LHS%EEEE + RHS%EEEE
      RES%EFFF = LHS%EFFF + RHS%EFFF
      RES%EGGG = LHS%EGGG + RHS%EGGG
      RES%EHHH = LHS%EHHH + RHS%EHHH
      RES%EIII = LHS%EIII + RHS%EIII
      RES%EJJJ = LHS%EJJJ + RHS%EJJJ
      RES%EKKK = LHS%EKKK + RHS%EKKK
      RES%ELLL = LHS%ELLL + RHS%ELLL
      RES%EMMM = LHS%EMMM + RHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111 + RHS%E1111
      RES%E2222 = LHS%E2222 + RHS%E2222
      RES%E3333 = LHS%E3333 + RHS%E3333
      RES%E4444 = LHS%E4444 + RHS%E4444
      RES%E5555 = LHS%E5555 + RHS%E5555
      RES%E6666 = LHS%E6666 + RHS%E6666
      RES%E7777 = LHS%E7777 + RHS%E7777
      RES%E8888 = LHS%E8888 + RHS%E8888
      RES%E9999 = LHS%E9999 + RHS%E9999
      RES%EAAAA = LHS%EAAAA + RHS%EAAAA
      RES%EBBBB = LHS%EBBBB + RHS%EBBBB
      RES%ECCCC = LHS%ECCCC + RHS%ECCCC
      RES%EDDDD = LHS%EDDDD + RHS%EDDDD
      RES%EEEEE = LHS%EEEEE + RHS%EEEEE
      RES%EFFFF = LHS%EFFFF + RHS%EFFFF
      RES%EGGGG = LHS%EGGGG + RHS%EGGGG
      RES%EHHHH = LHS%EHHHH + RHS%EHHHH
      RES%EIIII = LHS%EIIII + RHS%EIIII
      RES%EJJJJ = LHS%EJJJJ + RHS%EJJJJ
      RES%EKKKK = LHS%EKKKK + RHS%EKKKK
      RES%ELLLL = LHS%ELLLL + RHS%ELLLL
      RES%EMMMM = LHS%EMMMM + RHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111 + RHS%E11111
      RES%E22222 = LHS%E22222 + RHS%E22222
      RES%E33333 = LHS%E33333 + RHS%E33333
      RES%E44444 = LHS%E44444 + RHS%E44444
      RES%E55555 = LHS%E55555 + RHS%E55555
      RES%E66666 = LHS%E66666 + RHS%E66666
      RES%E77777 = LHS%E77777 + RHS%E77777
      RES%E88888 = LHS%E88888 + RHS%E88888
      RES%E99999 = LHS%E99999 + RHS%E99999
      RES%EAAAAA = LHS%EAAAAA + RHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB + RHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC + RHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD + RHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE + RHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF + RHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG + RHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH + RHS%EHHHHH
      RES%EIIIII = LHS%EIIIII + RHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ + RHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK + RHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL + RHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM + RHS%EMMMMM

   END FUNCTION DONUMM22N5_ADD_OO_SM

   FUNCTION DONUMM22N5_ADD_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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

      ! Order 3
      RES%E111 =  + RHS%E111
      RES%E222 =  + RHS%E222
      RES%E333 =  + RHS%E333
      RES%E444 =  + RHS%E444
      RES%E555 =  + RHS%E555
      RES%E666 =  + RHS%E666
      RES%E777 =  + RHS%E777
      RES%E888 =  + RHS%E888
      RES%E999 =  + RHS%E999
      RES%EAAA =  + RHS%EAAA
      RES%EBBB =  + RHS%EBBB
      RES%ECCC =  + RHS%ECCC
      RES%EDDD =  + RHS%EDDD
      RES%EEEE =  + RHS%EEEE
      RES%EFFF =  + RHS%EFFF
      RES%EGGG =  + RHS%EGGG
      RES%EHHH =  + RHS%EHHH
      RES%EIII =  + RHS%EIII
      RES%EJJJ =  + RHS%EJJJ
      RES%EKKK =  + RHS%EKKK
      RES%ELLL =  + RHS%ELLL
      RES%EMMM =  + RHS%EMMM

      ! Order 4
      RES%E1111 =  + RHS%E1111
      RES%E2222 =  + RHS%E2222
      RES%E3333 =  + RHS%E3333
      RES%E4444 =  + RHS%E4444
      RES%E5555 =  + RHS%E5555
      RES%E6666 =  + RHS%E6666
      RES%E7777 =  + RHS%E7777
      RES%E8888 =  + RHS%E8888
      RES%E9999 =  + RHS%E9999
      RES%EAAAA =  + RHS%EAAAA
      RES%EBBBB =  + RHS%EBBBB
      RES%ECCCC =  + RHS%ECCCC
      RES%EDDDD =  + RHS%EDDDD
      RES%EEEEE =  + RHS%EEEEE
      RES%EFFFF =  + RHS%EFFFF
      RES%EGGGG =  + RHS%EGGGG
      RES%EHHHH =  + RHS%EHHHH
      RES%EIIII =  + RHS%EIIII
      RES%EJJJJ =  + RHS%EJJJJ
      RES%EKKKK =  + RHS%EKKKK
      RES%ELLLL =  + RHS%ELLLL
      RES%EMMMM =  + RHS%EMMMM

      ! Order 5
      RES%E11111 =  + RHS%E11111
      RES%E22222 =  + RHS%E22222
      RES%E33333 =  + RHS%E33333
      RES%E44444 =  + RHS%E44444
      RES%E55555 =  + RHS%E55555
      RES%E66666 =  + RHS%E66666
      RES%E77777 =  + RHS%E77777
      RES%E88888 =  + RHS%E88888
      RES%E99999 =  + RHS%E99999
      RES%EAAAAA =  + RHS%EAAAAA
      RES%EBBBBB =  + RHS%EBBBBB
      RES%ECCCCC =  + RHS%ECCCCC
      RES%EDDDDD =  + RHS%EDDDDD
      RES%EEEEEE =  + RHS%EEEEEE
      RES%EFFFFF =  + RHS%EFFFFF
      RES%EGGGGG =  + RHS%EGGGGG
      RES%EHHHHH =  + RHS%EHHHHH
      RES%EIIIII =  + RHS%EIIIII
      RES%EJJJJJ =  + RHS%EJJJJJ
      RES%EKKKKK =  + RHS%EKKKKK
      RES%ELLLLL =  + RHS%ELLLLL
      RES%EMMMMM =  + RHS%EMMMMM

   END FUNCTION DONUMM22N5_ADD_RO_SM

   FUNCTION DONUMM22N5_ADD_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777
      RES%E888 = LHS%E888
      RES%E999 = LHS%E999
      RES%EAAA = LHS%EAAA
      RES%EBBB = LHS%EBBB
      RES%ECCC = LHS%ECCC
      RES%EDDD = LHS%EDDD
      RES%EEEE = LHS%EEEE
      RES%EFFF = LHS%EFFF
      RES%EGGG = LHS%EGGG
      RES%EHHH = LHS%EHHH
      RES%EIII = LHS%EIII
      RES%EJJJ = LHS%EJJJ
      RES%EKKK = LHS%EKKK
      RES%ELLL = LHS%ELLL
      RES%EMMM = LHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111
      RES%E2222 = LHS%E2222
      RES%E3333 = LHS%E3333
      RES%E4444 = LHS%E4444
      RES%E5555 = LHS%E5555
      RES%E6666 = LHS%E6666
      RES%E7777 = LHS%E7777
      RES%E8888 = LHS%E8888
      RES%E9999 = LHS%E9999
      RES%EAAAA = LHS%EAAAA
      RES%EBBBB = LHS%EBBBB
      RES%ECCCC = LHS%ECCCC
      RES%EDDDD = LHS%EDDDD
      RES%EEEEE = LHS%EEEEE
      RES%EFFFF = LHS%EFFFF
      RES%EGGGG = LHS%EGGGG
      RES%EHHHH = LHS%EHHHH
      RES%EIIII = LHS%EIIII
      RES%EJJJJ = LHS%EJJJJ
      RES%EKKKK = LHS%EKKKK
      RES%ELLLL = LHS%ELLLL
      RES%EMMMM = LHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111
      RES%E22222 = LHS%E22222
      RES%E33333 = LHS%E33333
      RES%E44444 = LHS%E44444
      RES%E55555 = LHS%E55555
      RES%E66666 = LHS%E66666
      RES%E77777 = LHS%E77777
      RES%E88888 = LHS%E88888
      RES%E99999 = LHS%E99999
      RES%EAAAAA = LHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH
      RES%EIIIII = LHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM

   END FUNCTION DONUMM22N5_ADD_OR_SM

   FUNCTION DONUMM22N5_SUB_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111
      RES%E222 = LHS%E222 - RHS%E222
      RES%E333 = LHS%E333 - RHS%E333
      RES%E444 = LHS%E444 - RHS%E444
      RES%E555 = LHS%E555 - RHS%E555
      RES%E666 = LHS%E666 - RHS%E666
      RES%E777 = LHS%E777 - RHS%E777
      RES%E888 = LHS%E888 - RHS%E888
      RES%E999 = LHS%E999 - RHS%E999
      RES%EAAA = LHS%EAAA - RHS%EAAA
      RES%EBBB = LHS%EBBB - RHS%EBBB
      RES%ECCC = LHS%ECCC - RHS%ECCC
      RES%EDDD = LHS%EDDD - RHS%EDDD
      RES%EEEE = LHS%EEEE - RHS%EEEE
      RES%EFFF = LHS%EFFF - RHS%EFFF
      RES%EGGG = LHS%EGGG - RHS%EGGG
      RES%EHHH = LHS%EHHH - RHS%EHHH
      RES%EIII = LHS%EIII - RHS%EIII
      RES%EJJJ = LHS%EJJJ - RHS%EJJJ
      RES%EKKK = LHS%EKKK - RHS%EKKK
      RES%ELLL = LHS%ELLL - RHS%ELLL
      RES%EMMM = LHS%EMMM - RHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111 - RHS%E1111
      RES%E2222 = LHS%E2222 - RHS%E2222
      RES%E3333 = LHS%E3333 - RHS%E3333
      RES%E4444 = LHS%E4444 - RHS%E4444
      RES%E5555 = LHS%E5555 - RHS%E5555
      RES%E6666 = LHS%E6666 - RHS%E6666
      RES%E7777 = LHS%E7777 - RHS%E7777
      RES%E8888 = LHS%E8888 - RHS%E8888
      RES%E9999 = LHS%E9999 - RHS%E9999
      RES%EAAAA = LHS%EAAAA - RHS%EAAAA
      RES%EBBBB = LHS%EBBBB - RHS%EBBBB
      RES%ECCCC = LHS%ECCCC - RHS%ECCCC
      RES%EDDDD = LHS%EDDDD - RHS%EDDDD
      RES%EEEEE = LHS%EEEEE - RHS%EEEEE
      RES%EFFFF = LHS%EFFFF - RHS%EFFFF
      RES%EGGGG = LHS%EGGGG - RHS%EGGGG
      RES%EHHHH = LHS%EHHHH - RHS%EHHHH
      RES%EIIII = LHS%EIIII - RHS%EIIII
      RES%EJJJJ = LHS%EJJJJ - RHS%EJJJJ
      RES%EKKKK = LHS%EKKKK - RHS%EKKKK
      RES%ELLLL = LHS%ELLLL - RHS%ELLLL
      RES%EMMMM = LHS%EMMMM - RHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111 - RHS%E11111
      RES%E22222 = LHS%E22222 - RHS%E22222
      RES%E33333 = LHS%E33333 - RHS%E33333
      RES%E44444 = LHS%E44444 - RHS%E44444
      RES%E55555 = LHS%E55555 - RHS%E55555
      RES%E66666 = LHS%E66666 - RHS%E66666
      RES%E77777 = LHS%E77777 - RHS%E77777
      RES%E88888 = LHS%E88888 - RHS%E88888
      RES%E99999 = LHS%E99999 - RHS%E99999
      RES%EAAAAA = LHS%EAAAAA - RHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB - RHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC - RHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD - RHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE - RHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF - RHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG - RHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH - RHS%EHHHHH
      RES%EIIIII = LHS%EIIIII - RHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ - RHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK - RHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL - RHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM - RHS%EMMMMM

   END FUNCTION DONUMM22N5_SUB_OO_SM

   FUNCTION DONUMM22N5_SUB_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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

      ! Order 3
      RES%E111 =  - RHS%E111
      RES%E222 =  - RHS%E222
      RES%E333 =  - RHS%E333
      RES%E444 =  - RHS%E444
      RES%E555 =  - RHS%E555
      RES%E666 =  - RHS%E666
      RES%E777 =  - RHS%E777
      RES%E888 =  - RHS%E888
      RES%E999 =  - RHS%E999
      RES%EAAA =  - RHS%EAAA
      RES%EBBB =  - RHS%EBBB
      RES%ECCC =  - RHS%ECCC
      RES%EDDD =  - RHS%EDDD
      RES%EEEE =  - RHS%EEEE
      RES%EFFF =  - RHS%EFFF
      RES%EGGG =  - RHS%EGGG
      RES%EHHH =  - RHS%EHHH
      RES%EIII =  - RHS%EIII
      RES%EJJJ =  - RHS%EJJJ
      RES%EKKK =  - RHS%EKKK
      RES%ELLL =  - RHS%ELLL
      RES%EMMM =  - RHS%EMMM

      ! Order 4
      RES%E1111 =  - RHS%E1111
      RES%E2222 =  - RHS%E2222
      RES%E3333 =  - RHS%E3333
      RES%E4444 =  - RHS%E4444
      RES%E5555 =  - RHS%E5555
      RES%E6666 =  - RHS%E6666
      RES%E7777 =  - RHS%E7777
      RES%E8888 =  - RHS%E8888
      RES%E9999 =  - RHS%E9999
      RES%EAAAA =  - RHS%EAAAA
      RES%EBBBB =  - RHS%EBBBB
      RES%ECCCC =  - RHS%ECCCC
      RES%EDDDD =  - RHS%EDDDD
      RES%EEEEE =  - RHS%EEEEE
      RES%EFFFF =  - RHS%EFFFF
      RES%EGGGG =  - RHS%EGGGG
      RES%EHHHH =  - RHS%EHHHH
      RES%EIIII =  - RHS%EIIII
      RES%EJJJJ =  - RHS%EJJJJ
      RES%EKKKK =  - RHS%EKKKK
      RES%ELLLL =  - RHS%ELLLL
      RES%EMMMM =  - RHS%EMMMM

      ! Order 5
      RES%E11111 =  - RHS%E11111
      RES%E22222 =  - RHS%E22222
      RES%E33333 =  - RHS%E33333
      RES%E44444 =  - RHS%E44444
      RES%E55555 =  - RHS%E55555
      RES%E66666 =  - RHS%E66666
      RES%E77777 =  - RHS%E77777
      RES%E88888 =  - RHS%E88888
      RES%E99999 =  - RHS%E99999
      RES%EAAAAA =  - RHS%EAAAAA
      RES%EBBBBB =  - RHS%EBBBBB
      RES%ECCCCC =  - RHS%ECCCCC
      RES%EDDDDD =  - RHS%EDDDDD
      RES%EEEEEE =  - RHS%EEEEEE
      RES%EFFFFF =  - RHS%EFFFFF
      RES%EGGGGG =  - RHS%EGGGGG
      RES%EHHHHH =  - RHS%EHHHHH
      RES%EIIIII =  - RHS%EIIIII
      RES%EJJJJJ =  - RHS%EJJJJJ
      RES%EKKKKK =  - RHS%EKKKKK
      RES%ELLLLL =  - RHS%ELLLLL
      RES%EMMMMM =  - RHS%EMMMMM

   END FUNCTION DONUMM22N5_SUB_RO_SM

   FUNCTION DONUMM22N5_SUB_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777
      RES%E888 = LHS%E888
      RES%E999 = LHS%E999
      RES%EAAA = LHS%EAAA
      RES%EBBB = LHS%EBBB
      RES%ECCC = LHS%ECCC
      RES%EDDD = LHS%EDDD
      RES%EEEE = LHS%EEEE
      RES%EFFF = LHS%EFFF
      RES%EGGG = LHS%EGGG
      RES%EHHH = LHS%EHHH
      RES%EIII = LHS%EIII
      RES%EJJJ = LHS%EJJJ
      RES%EKKK = LHS%EKKK
      RES%ELLL = LHS%ELLL
      RES%EMMM = LHS%EMMM

      ! Order 4
      RES%E1111 = LHS%E1111
      RES%E2222 = LHS%E2222
      RES%E3333 = LHS%E3333
      RES%E4444 = LHS%E4444
      RES%E5555 = LHS%E5555
      RES%E6666 = LHS%E6666
      RES%E7777 = LHS%E7777
      RES%E8888 = LHS%E8888
      RES%E9999 = LHS%E9999
      RES%EAAAA = LHS%EAAAA
      RES%EBBBB = LHS%EBBBB
      RES%ECCCC = LHS%ECCCC
      RES%EDDDD = LHS%EDDDD
      RES%EEEEE = LHS%EEEEE
      RES%EFFFF = LHS%EFFFF
      RES%EGGGG = LHS%EGGGG
      RES%EHHHH = LHS%EHHHH
      RES%EIIII = LHS%EIIII
      RES%EJJJJ = LHS%EJJJJ
      RES%EKKKK = LHS%EKKKK
      RES%ELLLL = LHS%ELLLL
      RES%EMMMM = LHS%EMMMM

      ! Order 5
      RES%E11111 = LHS%E11111
      RES%E22222 = LHS%E22222
      RES%E33333 = LHS%E33333
      RES%E44444 = LHS%E44444
      RES%E55555 = LHS%E55555
      RES%E66666 = LHS%E66666
      RES%E77777 = LHS%E77777
      RES%E88888 = LHS%E88888
      RES%E99999 = LHS%E99999
      RES%EAAAAA = LHS%EAAAAA
      RES%EBBBBB = LHS%EBBBBB
      RES%ECCCCC = LHS%ECCCCC
      RES%EDDDDD = LHS%EDDDDD
      RES%EEEEEE = LHS%EEEEEE
      RES%EFFFFF = LHS%EFFFFF
      RES%EGGGGG = LHS%EGGGGG
      RES%EHHHHH = LHS%EHHHHH
      RES%EIIIII = LHS%EIIIII
      RES%EJJJJJ = LHS%EJJJJJ
      RES%EKKKKK = LHS%EKKKKK
      RES%ELLLLL = LHS%ELLLLL
      RES%EMMMMM = LHS%EMMMMM

   END FUNCTION DONUMM22N5_SUB_OR_SM

   FUNCTION DONUMM22N5_MUL_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 5
      RES%E11111 = LHS%R*RHS%E11111 + LHS%E11111*RHS%R +  &
                LHS%E1*RHS%E1111 + LHS%E1111*RHS%E1 + LHS%E11*RHS%E111 + LHS%E111*RHS%E11
      RES%E22222 = LHS%R*RHS%E22222 + LHS%E22222*RHS%R +  &
                LHS%E2*RHS%E2222 + LHS%E2222*RHS%E2 + LHS%E22*RHS%E222 + LHS%E222*RHS%E22
      RES%E33333 = LHS%R*RHS%E33333 + LHS%E33333*RHS%R +  &
                LHS%E3*RHS%E3333 + LHS%E3333*RHS%E3 + LHS%E33*RHS%E333 + LHS%E333*RHS%E33
      RES%E44444 = LHS%R*RHS%E44444 + LHS%E44444*RHS%R +  &
                LHS%E4*RHS%E4444 + LHS%E4444*RHS%E4 + LHS%E44*RHS%E444 + LHS%E444*RHS%E44
      RES%E55555 = LHS%R*RHS%E55555 + LHS%E55555*RHS%R +  &
                LHS%E5*RHS%E5555 + LHS%E5555*RHS%E5 + LHS%E55*RHS%E555 + LHS%E555*RHS%E55
      RES%E66666 = LHS%R*RHS%E66666 + LHS%E66666*RHS%R +  &
                LHS%E6*RHS%E6666 + LHS%E6666*RHS%E6 + LHS%E66*RHS%E666 + LHS%E666*RHS%E66
      RES%E77777 = LHS%R*RHS%E77777 + LHS%E77777*RHS%R +  &
                LHS%E7*RHS%E7777 + LHS%E7777*RHS%E7 + LHS%E77*RHS%E777 + LHS%E777*RHS%E77
      RES%E88888 = LHS%R*RHS%E88888 + LHS%E88888*RHS%R +  &
                LHS%E8*RHS%E8888 + LHS%E8888*RHS%E8 + LHS%E88*RHS%E888 + LHS%E888*RHS%E88
      RES%E99999 = LHS%R*RHS%E99999 + LHS%E99999*RHS%R +  &
                LHS%E9*RHS%E9999 + LHS%E9999*RHS%E9 + LHS%E99*RHS%E999 + LHS%E999*RHS%E99
      RES%EAAAAA = LHS%R*RHS%EAAAAA + LHS%EAAAAA*RHS%R +  &
                LHS%EA*RHS%EAAAA + LHS%EAAAA*RHS%EA + LHS%EAA*RHS%EAAA + LHS%EAAA*RHS%EAA
      RES%EBBBBB = LHS%R*RHS%EBBBBB + LHS%EBBBBB*RHS%R +  &
                LHS%EB*RHS%EBBBB + LHS%EBBBB*RHS%EB + LHS%EBB*RHS%EBBB + LHS%EBBB*RHS%EBB
      RES%ECCCCC = LHS%R*RHS%ECCCCC + LHS%ECCCCC*RHS%R +  &
                LHS%EC*RHS%ECCCC + LHS%ECCCC*RHS%EC + LHS%ECC*RHS%ECCC + LHS%ECCC*RHS%ECC
      RES%EDDDDD = LHS%R*RHS%EDDDDD + LHS%EDDDDD*RHS%R +  &
                LHS%ED*RHS%EDDDD + LHS%EDDDD*RHS%ED + LHS%EDD*RHS%EDDD + LHS%EDDD*RHS%EDD
      RES%EEEEEE = LHS%R*RHS%EEEEEE + LHS%EEEEEE*RHS%R +  &
                LHS%EE*RHS%EEEEE + LHS%EEEEE*RHS%EE + LHS%EEE*RHS%EEEE + LHS%EEEE*RHS%EEE
      RES%EFFFFF = LHS%R*RHS%EFFFFF + LHS%EFFFFF*RHS%R +  &
                LHS%EF*RHS%EFFFF + LHS%EFFFF*RHS%EF + LHS%EFF*RHS%EFFF + LHS%EFFF*RHS%EFF
      RES%EGGGGG = LHS%R*RHS%EGGGGG + LHS%EGGGGG*RHS%R +  &
                LHS%EG*RHS%EGGGG + LHS%EGGGG*RHS%EG + LHS%EGG*RHS%EGGG + LHS%EGGG*RHS%EGG
      RES%EHHHHH = LHS%R*RHS%EHHHHH + LHS%EHHHHH*RHS%R +  &
                LHS%EH*RHS%EHHHH + LHS%EHHHH*RHS%EH + LHS%EHH*RHS%EHHH + LHS%EHHH*RHS%EHH
      RES%EIIIII = LHS%R*RHS%EIIIII + LHS%EIIIII*RHS%R +  &
                LHS%EI*RHS%EIIII + LHS%EIIII*RHS%EI + LHS%EII*RHS%EIII + LHS%EIII*RHS%EII
      RES%EJJJJJ = LHS%R*RHS%EJJJJJ + LHS%EJJJJJ*RHS%R +  &
                LHS%EJ*RHS%EJJJJ + LHS%EJJJJ*RHS%EJ + LHS%EJJ*RHS%EJJJ + LHS%EJJJ*RHS%EJJ
      RES%EKKKKK = LHS%R*RHS%EKKKKK + LHS%EKKKKK*RHS%R +  &
                LHS%EK*RHS%EKKKK + LHS%EKKKK*RHS%EK + LHS%EKK*RHS%EKKK + LHS%EKKK*RHS%EKK
      RES%ELLLLL = LHS%R*RHS%ELLLLL + LHS%ELLLLL*RHS%R +  &
                LHS%EL*RHS%ELLLL + LHS%ELLLL*RHS%EL + LHS%ELL*RHS%ELLL + LHS%ELLL*RHS%ELL
      RES%EMMMMM = LHS%R*RHS%EMMMMM + LHS%EMMMMM*RHS%R +  &
                LHS%EM*RHS%EMMMM + LHS%EMMMM*RHS%EM + LHS%EMM*RHS%EMMM + LHS%EMMM*RHS%EMM
      ! Order 4
      RES%E1111 = LHS%R*RHS%E1111 + LHS%E1111*RHS%R +  &
               LHS%E1*RHS%E111 + LHS%E111*RHS%E1 + LHS%E11*RHS%E11
      RES%E2222 = LHS%R*RHS%E2222 + LHS%E2222*RHS%R +  &
               LHS%E2*RHS%E222 + LHS%E222*RHS%E2 + LHS%E22*RHS%E22
      RES%E3333 = LHS%R*RHS%E3333 + LHS%E3333*RHS%R +  &
               LHS%E3*RHS%E333 + LHS%E333*RHS%E3 + LHS%E33*RHS%E33
      RES%E4444 = LHS%R*RHS%E4444 + LHS%E4444*RHS%R +  &
               LHS%E4*RHS%E444 + LHS%E444*RHS%E4 + LHS%E44*RHS%E44
      RES%E5555 = LHS%R*RHS%E5555 + LHS%E5555*RHS%R +  &
               LHS%E5*RHS%E555 + LHS%E555*RHS%E5 + LHS%E55*RHS%E55
      RES%E6666 = LHS%R*RHS%E6666 + LHS%E6666*RHS%R +  &
               LHS%E6*RHS%E666 + LHS%E666*RHS%E6 + LHS%E66*RHS%E66
      RES%E7777 = LHS%R*RHS%E7777 + LHS%E7777*RHS%R +  &
               LHS%E7*RHS%E777 + LHS%E777*RHS%E7 + LHS%E77*RHS%E77
      RES%E8888 = LHS%R*RHS%E8888 + LHS%E8888*RHS%R +  &
               LHS%E8*RHS%E888 + LHS%E888*RHS%E8 + LHS%E88*RHS%E88
      RES%E9999 = LHS%R*RHS%E9999 + LHS%E9999*RHS%R +  &
               LHS%E9*RHS%E999 + LHS%E999*RHS%E9 + LHS%E99*RHS%E99
      RES%EAAAA = LHS%R*RHS%EAAAA + LHS%EAAAA*RHS%R +  &
               LHS%EA*RHS%EAAA + LHS%EAAA*RHS%EA + LHS%EAA*RHS%EAA
      RES%EBBBB = LHS%R*RHS%EBBBB + LHS%EBBBB*RHS%R +  &
               LHS%EB*RHS%EBBB + LHS%EBBB*RHS%EB + LHS%EBB*RHS%EBB
      RES%ECCCC = LHS%R*RHS%ECCCC + LHS%ECCCC*RHS%R +  &
               LHS%EC*RHS%ECCC + LHS%ECCC*RHS%EC + LHS%ECC*RHS%ECC
      RES%EDDDD = LHS%R*RHS%EDDDD + LHS%EDDDD*RHS%R +  &
               LHS%ED*RHS%EDDD + LHS%EDDD*RHS%ED + LHS%EDD*RHS%EDD
      RES%EEEEE = LHS%R*RHS%EEEEE + LHS%EEEEE*RHS%R +  &
               LHS%EE*RHS%EEEE + LHS%EEEE*RHS%EE + LHS%EEE*RHS%EEE
      RES%EFFFF = LHS%R*RHS%EFFFF + LHS%EFFFF*RHS%R +  &
               LHS%EF*RHS%EFFF + LHS%EFFF*RHS%EF + LHS%EFF*RHS%EFF
      RES%EGGGG = LHS%R*RHS%EGGGG + LHS%EGGGG*RHS%R +  &
               LHS%EG*RHS%EGGG + LHS%EGGG*RHS%EG + LHS%EGG*RHS%EGG
      RES%EHHHH = LHS%R*RHS%EHHHH + LHS%EHHHH*RHS%R +  &
               LHS%EH*RHS%EHHH + LHS%EHHH*RHS%EH + LHS%EHH*RHS%EHH
      RES%EIIII = LHS%R*RHS%EIIII + LHS%EIIII*RHS%R +  &
               LHS%EI*RHS%EIII + LHS%EIII*RHS%EI + LHS%EII*RHS%EII
      RES%EJJJJ = LHS%R*RHS%EJJJJ + LHS%EJJJJ*RHS%R +  &
               LHS%EJ*RHS%EJJJ + LHS%EJJJ*RHS%EJ + LHS%EJJ*RHS%EJJ
      RES%EKKKK = LHS%R*RHS%EKKKK + LHS%EKKKK*RHS%R +  &
               LHS%EK*RHS%EKKK + LHS%EKKK*RHS%EK + LHS%EKK*RHS%EKK
      RES%ELLLL = LHS%R*RHS%ELLLL + LHS%ELLLL*RHS%R +  &
               LHS%EL*RHS%ELLL + LHS%ELLL*RHS%EL + LHS%ELL*RHS%ELL
      RES%EMMMM = LHS%R*RHS%EMMMM + LHS%EMMMM*RHS%R +  &
               LHS%EM*RHS%EMMM + LHS%EMMM*RHS%EM + LHS%EMM*RHS%EMM
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
      RES%E888 = LHS%R*RHS%E888 + LHS%E888*RHS%R +  &
              LHS%E8*RHS%E88 + LHS%E88*RHS%E8
      RES%E999 = LHS%R*RHS%E999 + LHS%E999*RHS%R +  &
              LHS%E9*RHS%E99 + LHS%E99*RHS%E9
      RES%EAAA = LHS%R*RHS%EAAA + LHS%EAAA*RHS%R +  &
              LHS%EA*RHS%EAA + LHS%EAA*RHS%EA
      RES%EBBB = LHS%R*RHS%EBBB + LHS%EBBB*RHS%R +  &
              LHS%EB*RHS%EBB + LHS%EBB*RHS%EB
      RES%ECCC = LHS%R*RHS%ECCC + LHS%ECCC*RHS%R +  &
              LHS%EC*RHS%ECC + LHS%ECC*RHS%EC
      RES%EDDD = LHS%R*RHS%EDDD + LHS%EDDD*RHS%R +  &
              LHS%ED*RHS%EDD + LHS%EDD*RHS%ED
      RES%EEEE = LHS%R*RHS%EEEE + LHS%EEEE*RHS%R +  &
              LHS%EE*RHS%EEE + LHS%EEE*RHS%EE
      RES%EFFF = LHS%R*RHS%EFFF + LHS%EFFF*RHS%R +  &
              LHS%EF*RHS%EFF + LHS%EFF*RHS%EF
      RES%EGGG = LHS%R*RHS%EGGG + LHS%EGGG*RHS%R +  &
              LHS%EG*RHS%EGG + LHS%EGG*RHS%EG
      RES%EHHH = LHS%R*RHS%EHHH + LHS%EHHH*RHS%R +  &
              LHS%EH*RHS%EHH + LHS%EHH*RHS%EH
      RES%EIII = LHS%R*RHS%EIII + LHS%EIII*RHS%R +  &
              LHS%EI*RHS%EII + LHS%EII*RHS%EI
      RES%EJJJ = LHS%R*RHS%EJJJ + LHS%EJJJ*RHS%R +  &
              LHS%EJ*RHS%EJJ + LHS%EJJ*RHS%EJ
      RES%EKKK = LHS%R*RHS%EKKK + LHS%EKKK*RHS%R +  &
              LHS%EK*RHS%EKK + LHS%EKK*RHS%EK
      RES%ELLL = LHS%R*RHS%ELLL + LHS%ELLL*RHS%R +  &
              LHS%EL*RHS%ELL + LHS%ELL*RHS%EL
      RES%EMMM = LHS%R*RHS%EMMM + LHS%EMMM*RHS%R +  &
              LHS%EM*RHS%EMM + LHS%EMM*RHS%EM
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

   END FUNCTION DONUMM22N5_MUL_OO_SM

   FUNCTION DONUMM22N5_MUL_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM22N5), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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

      ! Order 3
      RES%E111 = LHS*RHS%E111
      RES%E222 = LHS*RHS%E222
      RES%E333 = LHS*RHS%E333
      RES%E444 = LHS*RHS%E444
      RES%E555 = LHS*RHS%E555
      RES%E666 = LHS*RHS%E666
      RES%E777 = LHS*RHS%E777
      RES%E888 = LHS*RHS%E888
      RES%E999 = LHS*RHS%E999
      RES%EAAA = LHS*RHS%EAAA
      RES%EBBB = LHS*RHS%EBBB
      RES%ECCC = LHS*RHS%ECCC
      RES%EDDD = LHS*RHS%EDDD
      RES%EEEE = LHS*RHS%EEEE
      RES%EFFF = LHS*RHS%EFFF
      RES%EGGG = LHS*RHS%EGGG
      RES%EHHH = LHS*RHS%EHHH
      RES%EIII = LHS*RHS%EIII
      RES%EJJJ = LHS*RHS%EJJJ
      RES%EKKK = LHS*RHS%EKKK
      RES%ELLL = LHS*RHS%ELLL
      RES%EMMM = LHS*RHS%EMMM

      ! Order 4
      RES%E1111 = LHS*RHS%E1111
      RES%E2222 = LHS*RHS%E2222
      RES%E3333 = LHS*RHS%E3333
      RES%E4444 = LHS*RHS%E4444
      RES%E5555 = LHS*RHS%E5555
      RES%E6666 = LHS*RHS%E6666
      RES%E7777 = LHS*RHS%E7777
      RES%E8888 = LHS*RHS%E8888
      RES%E9999 = LHS*RHS%E9999
      RES%EAAAA = LHS*RHS%EAAAA
      RES%EBBBB = LHS*RHS%EBBBB
      RES%ECCCC = LHS*RHS%ECCCC
      RES%EDDDD = LHS*RHS%EDDDD
      RES%EEEEE = LHS*RHS%EEEEE
      RES%EFFFF = LHS*RHS%EFFFF
      RES%EGGGG = LHS*RHS%EGGGG
      RES%EHHHH = LHS*RHS%EHHHH
      RES%EIIII = LHS*RHS%EIIII
      RES%EJJJJ = LHS*RHS%EJJJJ
      RES%EKKKK = LHS*RHS%EKKKK
      RES%ELLLL = LHS*RHS%ELLLL
      RES%EMMMM = LHS*RHS%EMMMM

      ! Order 5
      RES%E11111 = LHS*RHS%E11111
      RES%E22222 = LHS*RHS%E22222
      RES%E33333 = LHS*RHS%E33333
      RES%E44444 = LHS*RHS%E44444
      RES%E55555 = LHS*RHS%E55555
      RES%E66666 = LHS*RHS%E66666
      RES%E77777 = LHS*RHS%E77777
      RES%E88888 = LHS*RHS%E88888
      RES%E99999 = LHS*RHS%E99999
      RES%EAAAAA = LHS*RHS%EAAAAA
      RES%EBBBBB = LHS*RHS%EBBBBB
      RES%ECCCCC = LHS*RHS%ECCCCC
      RES%EDDDDD = LHS*RHS%EDDDDD
      RES%EEEEEE = LHS*RHS%EEEEEE
      RES%EFFFFF = LHS*RHS%EFFFFF
      RES%EGGGGG = LHS*RHS%EGGGGG
      RES%EHHHHH = LHS*RHS%EHHHHH
      RES%EIIIII = LHS*RHS%EIIIII
      RES%EJJJJJ = LHS*RHS%EJJJJJ
      RES%EKKKKK = LHS*RHS%EKKKKK
      RES%ELLLLL = LHS*RHS%ELLLLL
      RES%EMMMMM = LHS*RHS%EMMMMM

   END FUNCTION DONUMM22N5_MUL_RO_SM

   FUNCTION DONUMM22N5_MUL_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N5) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111*RHS
      RES%E222 = LHS%E222*RHS
      RES%E333 = LHS%E333*RHS
      RES%E444 = LHS%E444*RHS
      RES%E555 = LHS%E555*RHS
      RES%E666 = LHS%E666*RHS
      RES%E777 = LHS%E777*RHS
      RES%E888 = LHS%E888*RHS
      RES%E999 = LHS%E999*RHS
      RES%EAAA = LHS%EAAA*RHS
      RES%EBBB = LHS%EBBB*RHS
      RES%ECCC = LHS%ECCC*RHS
      RES%EDDD = LHS%EDDD*RHS
      RES%EEEE = LHS%EEEE*RHS
      RES%EFFF = LHS%EFFF*RHS
      RES%EGGG = LHS%EGGG*RHS
      RES%EHHH = LHS%EHHH*RHS
      RES%EIII = LHS%EIII*RHS
      RES%EJJJ = LHS%EJJJ*RHS
      RES%EKKK = LHS%EKKK*RHS
      RES%ELLL = LHS%ELLL*RHS
      RES%EMMM = LHS%EMMM*RHS

      ! Order 4
      RES%E1111 = LHS%E1111*RHS
      RES%E2222 = LHS%E2222*RHS
      RES%E3333 = LHS%E3333*RHS
      RES%E4444 = LHS%E4444*RHS
      RES%E5555 = LHS%E5555*RHS
      RES%E6666 = LHS%E6666*RHS
      RES%E7777 = LHS%E7777*RHS
      RES%E8888 = LHS%E8888*RHS
      RES%E9999 = LHS%E9999*RHS
      RES%EAAAA = LHS%EAAAA*RHS
      RES%EBBBB = LHS%EBBBB*RHS
      RES%ECCCC = LHS%ECCCC*RHS
      RES%EDDDD = LHS%EDDDD*RHS
      RES%EEEEE = LHS%EEEEE*RHS
      RES%EFFFF = LHS%EFFFF*RHS
      RES%EGGGG = LHS%EGGGG*RHS
      RES%EHHHH = LHS%EHHHH*RHS
      RES%EIIII = LHS%EIIII*RHS
      RES%EJJJJ = LHS%EJJJJ*RHS
      RES%EKKKK = LHS%EKKKK*RHS
      RES%ELLLL = LHS%ELLLL*RHS
      RES%EMMMM = LHS%EMMMM*RHS

      ! Order 5
      RES%E11111 = LHS%E11111*RHS
      RES%E22222 = LHS%E22222*RHS
      RES%E33333 = LHS%E33333*RHS
      RES%E44444 = LHS%E44444*RHS
      RES%E55555 = LHS%E55555*RHS
      RES%E66666 = LHS%E66666*RHS
      RES%E77777 = LHS%E77777*RHS
      RES%E88888 = LHS%E88888*RHS
      RES%E99999 = LHS%E99999*RHS
      RES%EAAAAA = LHS%EAAAAA*RHS
      RES%EBBBBB = LHS%EBBBBB*RHS
      RES%ECCCCC = LHS%ECCCCC*RHS
      RES%EDDDDD = LHS%EDDDDD*RHS
      RES%EEEEEE = LHS%EEEEEE*RHS
      RES%EFFFFF = LHS%EFFFFF*RHS
      RES%EGGGGG = LHS%EGGGGG*RHS
      RES%EHHHHH = LHS%EHHHHH*RHS
      RES%EIIIII = LHS%EIIIII*RHS
      RES%EJJJJJ = LHS%EJJJJJ*RHS
      RES%EKKKKK = LHS%EKKKKK*RHS
      RES%ELLLLL = LHS%ELLLLL*RHS
      RES%EMMMMM = LHS%EMMMMM*RHS

   END FUNCTION DONUMM22N5_MUL_OR_SM

ELEMENTAL    FUNCTION DONUMM22N5_GEM_OOO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: A 
      TYPE(DONUMM22N5), INTENT(IN) :: B 
      TYPE(DONUMM22N5), INTENT(IN) :: C 
      TYPE(DONUMM22N5) :: RES 

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
      RES%E888 = C%E888 + A%R*B%E888 + A%E888*B%R + A%E8*B%E88 &
               + A%E88*B%E8
      RES%E999 = C%E999 + A%R*B%E999 + A%E999*B%R + A%E9*B%E99 &
               + A%E99*B%E9
      RES%EAAA = C%EAAA + A%R*B%EAAA + A%EAAA*B%R + A%EA*B%EAA &
               + A%EAA*B%EA
      RES%EBBB = C%EBBB + A%R*B%EBBB + A%EBBB*B%R + A%EB*B%EBB &
               + A%EBB*B%EB
      RES%ECCC = C%ECCC + A%R*B%ECCC + A%ECCC*B%R + A%EC*B%ECC &
               + A%ECC*B%EC
      RES%EDDD = C%EDDD + A%R*B%EDDD + A%EDDD*B%R + A%ED*B%EDD &
               + A%EDD*B%ED
      RES%EEEE = C%EEEE + A%R*B%EEEE + A%EEEE*B%R + A%EE*B%EEE &
               + A%EEE*B%EE
      RES%EFFF = C%EFFF + A%R*B%EFFF + A%EFFF*B%R + A%EF*B%EFF &
               + A%EFF*B%EF
      RES%EGGG = C%EGGG + A%R*B%EGGG + A%EGGG*B%R + A%EG*B%EGG &
               + A%EGG*B%EG
      RES%EHHH = C%EHHH + A%R*B%EHHH + A%EHHH*B%R + A%EH*B%EHH &
               + A%EHH*B%EH
      RES%EIII = C%EIII + A%R*B%EIII + A%EIII*B%R + A%EI*B%EII &
               + A%EII*B%EI
      RES%EJJJ = C%EJJJ + A%R*B%EJJJ + A%EJJJ*B%R + A%EJ*B%EJJ &
               + A%EJJ*B%EJ
      RES%EKKK = C%EKKK + A%R*B%EKKK + A%EKKK*B%R + A%EK*B%EKK &
               + A%EKK*B%EK
      RES%ELLL = C%ELLL + A%R*B%ELLL + A%ELLL*B%R + A%EL*B%ELL &
               + A%ELL*B%EL
      RES%EMMM = C%EMMM + A%R*B%EMMM + A%EMMM*B%R + A%EM*B%EMM &
               + A%EMM*B%EM

      ! Order 4
      RES%E1111 = C%E1111 + A%R*B%E1111 + A%E1111*B%R + A%E1*B%E111 &
                + A%E111*B%E1 + A%E11*B%E11
      RES%E2222 = C%E2222 + A%R*B%E2222 + A%E2222*B%R + A%E2*B%E222 &
                + A%E222*B%E2 + A%E22*B%E22
      RES%E3333 = C%E3333 + A%R*B%E3333 + A%E3333*B%R + A%E3*B%E333 &
                + A%E333*B%E3 + A%E33*B%E33
      RES%E4444 = C%E4444 + A%R*B%E4444 + A%E4444*B%R + A%E4*B%E444 &
                + A%E444*B%E4 + A%E44*B%E44
      RES%E5555 = C%E5555 + A%R*B%E5555 + A%E5555*B%R + A%E5*B%E555 &
                + A%E555*B%E5 + A%E55*B%E55
      RES%E6666 = C%E6666 + A%R*B%E6666 + A%E6666*B%R + A%E6*B%E666 &
                + A%E666*B%E6 + A%E66*B%E66
      RES%E7777 = C%E7777 + A%R*B%E7777 + A%E7777*B%R + A%E7*B%E777 &
                + A%E777*B%E7 + A%E77*B%E77
      RES%E8888 = C%E8888 + A%R*B%E8888 + A%E8888*B%R + A%E8*B%E888 &
                + A%E888*B%E8 + A%E88*B%E88
      RES%E9999 = C%E9999 + A%R*B%E9999 + A%E9999*B%R + A%E9*B%E999 &
                + A%E999*B%E9 + A%E99*B%E99
      RES%EAAAA = C%EAAAA + A%R*B%EAAAA + A%EAAAA*B%R + A%EA*B%EAAA &
                + A%EAAA*B%EA + A%EAA*B%EAA
      RES%EBBBB = C%EBBBB + A%R*B%EBBBB + A%EBBBB*B%R + A%EB*B%EBBB &
                + A%EBBB*B%EB + A%EBB*B%EBB
      RES%ECCCC = C%ECCCC + A%R*B%ECCCC + A%ECCCC*B%R + A%EC*B%ECCC &
                + A%ECCC*B%EC + A%ECC*B%ECC
      RES%EDDDD = C%EDDDD + A%R*B%EDDDD + A%EDDDD*B%R + A%ED*B%EDDD &
                + A%EDDD*B%ED + A%EDD*B%EDD
      RES%EEEEE = C%EEEEE + A%R*B%EEEEE + A%EEEEE*B%R + A%EE*B%EEEE &
                + A%EEEE*B%EE + A%EEE*B%EEE
      RES%EFFFF = C%EFFFF + A%R*B%EFFFF + A%EFFFF*B%R + A%EF*B%EFFF &
                + A%EFFF*B%EF + A%EFF*B%EFF
      RES%EGGGG = C%EGGGG + A%R*B%EGGGG + A%EGGGG*B%R + A%EG*B%EGGG &
                + A%EGGG*B%EG + A%EGG*B%EGG
      RES%EHHHH = C%EHHHH + A%R*B%EHHHH + A%EHHHH*B%R + A%EH*B%EHHH &
                + A%EHHH*B%EH + A%EHH*B%EHH
      RES%EIIII = C%EIIII + A%R*B%EIIII + A%EIIII*B%R + A%EI*B%EIII &
                + A%EIII*B%EI + A%EII*B%EII
      RES%EJJJJ = C%EJJJJ + A%R*B%EJJJJ + A%EJJJJ*B%R + A%EJ*B%EJJJ &
                + A%EJJJ*B%EJ + A%EJJ*B%EJJ
      RES%EKKKK = C%EKKKK + A%R*B%EKKKK + A%EKKKK*B%R + A%EK*B%EKKK &
                + A%EKKK*B%EK + A%EKK*B%EKK
      RES%ELLLL = C%ELLLL + A%R*B%ELLLL + A%ELLLL*B%R + A%EL*B%ELLL &
                + A%ELLL*B%EL + A%ELL*B%ELL
      RES%EMMMM = C%EMMMM + A%R*B%EMMMM + A%EMMMM*B%R + A%EM*B%EMMM &
                + A%EMMM*B%EM + A%EMM*B%EMM

      ! Order 5
      RES%E11111 = C%E11111 + A%R*B%E11111 + A%E11111*B%R + A%E1*B%E1111 &
                 + A%E1111*B%E1 + A%E11*B%E111 + A%E111*B%E11
      RES%E22222 = C%E22222 + A%R*B%E22222 + A%E22222*B%R + A%E2*B%E2222 &
                 + A%E2222*B%E2 + A%E22*B%E222 + A%E222*B%E22
      RES%E33333 = C%E33333 + A%R*B%E33333 + A%E33333*B%R + A%E3*B%E3333 &
                 + A%E3333*B%E3 + A%E33*B%E333 + A%E333*B%E33
      RES%E44444 = C%E44444 + A%R*B%E44444 + A%E44444*B%R + A%E4*B%E4444 &
                 + A%E4444*B%E4 + A%E44*B%E444 + A%E444*B%E44
      RES%E55555 = C%E55555 + A%R*B%E55555 + A%E55555*B%R + A%E5*B%E5555 &
                 + A%E5555*B%E5 + A%E55*B%E555 + A%E555*B%E55
      RES%E66666 = C%E66666 + A%R*B%E66666 + A%E66666*B%R + A%E6*B%E6666 &
                 + A%E6666*B%E6 + A%E66*B%E666 + A%E666*B%E66
      RES%E77777 = C%E77777 + A%R*B%E77777 + A%E77777*B%R + A%E7*B%E7777 &
                 + A%E7777*B%E7 + A%E77*B%E777 + A%E777*B%E77
      RES%E88888 = C%E88888 + A%R*B%E88888 + A%E88888*B%R + A%E8*B%E8888 &
                 + A%E8888*B%E8 + A%E88*B%E888 + A%E888*B%E88
      RES%E99999 = C%E99999 + A%R*B%E99999 + A%E99999*B%R + A%E9*B%E9999 &
                 + A%E9999*B%E9 + A%E99*B%E999 + A%E999*B%E99
      RES%EAAAAA = C%EAAAAA + A%R*B%EAAAAA + A%EAAAAA*B%R + A%EA*B%EAAAA &
                 + A%EAAAA*B%EA + A%EAA*B%EAAA + A%EAAA*B%EAA
      RES%EBBBBB = C%EBBBBB + A%R*B%EBBBBB + A%EBBBBB*B%R + A%EB*B%EBBBB &
                 + A%EBBBB*B%EB + A%EBB*B%EBBB + A%EBBB*B%EBB
      RES%ECCCCC = C%ECCCCC + A%R*B%ECCCCC + A%ECCCCC*B%R + A%EC*B%ECCCC &
                 + A%ECCCC*B%EC + A%ECC*B%ECCC + A%ECCC*B%ECC
      RES%EDDDDD = C%EDDDDD + A%R*B%EDDDDD + A%EDDDDD*B%R + A%ED*B%EDDDD &
                 + A%EDDDD*B%ED + A%EDD*B%EDDD + A%EDDD*B%EDD
      RES%EEEEEE = C%EEEEEE + A%R*B%EEEEEE + A%EEEEEE*B%R + A%EE*B%EEEEE &
                 + A%EEEEE*B%EE + A%EEE*B%EEEE + A%EEEE*B%EEE
      RES%EFFFFF = C%EFFFFF + A%R*B%EFFFFF + A%EFFFFF*B%R + A%EF*B%EFFFF &
                 + A%EFFFF*B%EF + A%EFF*B%EFFF + A%EFFF*B%EFF
      RES%EGGGGG = C%EGGGGG + A%R*B%EGGGGG + A%EGGGGG*B%R + A%EG*B%EGGGG &
                 + A%EGGGG*B%EG + A%EGG*B%EGGG + A%EGGG*B%EGG
      RES%EHHHHH = C%EHHHHH + A%R*B%EHHHHH + A%EHHHHH*B%R + A%EH*B%EHHHH &
                 + A%EHHHH*B%EH + A%EHH*B%EHHH + A%EHHH*B%EHH
      RES%EIIIII = C%EIIIII + A%R*B%EIIIII + A%EIIIII*B%R + A%EI*B%EIIII &
                 + A%EIIII*B%EI + A%EII*B%EIII + A%EIII*B%EII
      RES%EJJJJJ = C%EJJJJJ + A%R*B%EJJJJJ + A%EJJJJJ*B%R + A%EJ*B%EJJJJ &
                 + A%EJJJJ*B%EJ + A%EJJ*B%EJJJ + A%EJJJ*B%EJJ
      RES%EKKKKK = C%EKKKKK + A%R*B%EKKKKK + A%EKKKKK*B%R + A%EK*B%EKKKK &
                 + A%EKKKK*B%EK + A%EKK*B%EKKK + A%EKKK*B%EKK
      RES%ELLLLL = C%ELLLLL + A%R*B%ELLLLL + A%ELLLLL*B%R + A%EL*B%ELLLL &
                 + A%ELLLL*B%EL + A%ELL*B%ELLL + A%ELLL*B%ELL
      RES%EMMMMM = C%EMMMMM + A%R*B%EMMMMM + A%EMMMMM*B%R + A%EM*B%EMMMM &
                 + A%EMMMM*B%EM + A%EMM*B%EMMM + A%EMMM*B%EMM

   END FUNCTION DONUMM22N5_GEM_OOO

ELEMENTAL    FUNCTION DONUMM22N5_GEM_ROO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: A 
      TYPE(DONUMM22N5), INTENT(IN) :: B 
      TYPE(DONUMM22N5), INTENT(IN) :: C 
      TYPE(DONUMM22N5) :: RES 

      !  General multiplication like function 'A*B + C'
      ! Order 5
      RES%E11111 = C%E11111 + A*B%E11111
      RES%E22222 = C%E22222 + A*B%E22222
      RES%E33333 = C%E33333 + A*B%E33333
      RES%E44444 = C%E44444 + A*B%E44444
      RES%E55555 = C%E55555 + A*B%E55555
      RES%E66666 = C%E66666 + A*B%E66666
      RES%E77777 = C%E77777 + A*B%E77777
      RES%E88888 = C%E88888 + A*B%E88888
      RES%E99999 = C%E99999 + A*B%E99999
      RES%EAAAAA = C%EAAAAA + A*B%EAAAAA
      RES%EBBBBB = C%EBBBBB + A*B%EBBBBB
      RES%ECCCCC = C%ECCCCC + A*B%ECCCCC
      RES%EDDDDD = C%EDDDDD + A*B%EDDDDD
      RES%EEEEEE = C%EEEEEE + A*B%EEEEEE
      RES%EFFFFF = C%EFFFFF + A*B%EFFFFF
      RES%EGGGGG = C%EGGGGG + A*B%EGGGGG
      RES%EHHHHH = C%EHHHHH + A*B%EHHHHH
      RES%EIIIII = C%EIIIII + A*B%EIIIII
      RES%EJJJJJ = C%EJJJJJ + A*B%EJJJJJ
      RES%EKKKKK = C%EKKKKK + A*B%EKKKKK
      RES%ELLLLL = C%ELLLLL + A*B%ELLLLL
      RES%EMMMMM = C%EMMMMM + A*B%EMMMMM
      ! Order 4
      RES%E1111 = C%E1111 + A*B%E1111
      RES%E2222 = C%E2222 + A*B%E2222
      RES%E3333 = C%E3333 + A*B%E3333
      RES%E4444 = C%E4444 + A*B%E4444
      RES%E5555 = C%E5555 + A*B%E5555
      RES%E6666 = C%E6666 + A*B%E6666
      RES%E7777 = C%E7777 + A*B%E7777
      RES%E8888 = C%E8888 + A*B%E8888
      RES%E9999 = C%E9999 + A*B%E9999
      RES%EAAAA = C%EAAAA + A*B%EAAAA
      RES%EBBBB = C%EBBBB + A*B%EBBBB
      RES%ECCCC = C%ECCCC + A*B%ECCCC
      RES%EDDDD = C%EDDDD + A*B%EDDDD
      RES%EEEEE = C%EEEEE + A*B%EEEEE
      RES%EFFFF = C%EFFFF + A*B%EFFFF
      RES%EGGGG = C%EGGGG + A*B%EGGGG
      RES%EHHHH = C%EHHHH + A*B%EHHHH
      RES%EIIII = C%EIIII + A*B%EIIII
      RES%EJJJJ = C%EJJJJ + A*B%EJJJJ
      RES%EKKKK = C%EKKKK + A*B%EKKKK
      RES%ELLLL = C%ELLLL + A*B%ELLLL
      RES%EMMMM = C%EMMMM + A*B%EMMMM
      ! Order 3
      RES%E111 = C%E111 + A*B%E111
      RES%E222 = C%E222 + A*B%E222
      RES%E333 = C%E333 + A*B%E333
      RES%E444 = C%E444 + A*B%E444
      RES%E555 = C%E555 + A*B%E555
      RES%E666 = C%E666 + A*B%E666
      RES%E777 = C%E777 + A*B%E777
      RES%E888 = C%E888 + A*B%E888
      RES%E999 = C%E999 + A*B%E999
      RES%EAAA = C%EAAA + A*B%EAAA
      RES%EBBB = C%EBBB + A*B%EBBB
      RES%ECCC = C%ECCC + A*B%ECCC
      RES%EDDD = C%EDDD + A*B%EDDD
      RES%EEEE = C%EEEE + A*B%EEEE
      RES%EFFF = C%EFFF + A*B%EFFF
      RES%EGGG = C%EGGG + A*B%EGGG
      RES%EHHH = C%EHHH + A*B%EHHH
      RES%EIII = C%EIII + A*B%EIII
      RES%EJJJ = C%EJJJ + A*B%EJJJ
      RES%EKKK = C%EKKK + A*B%EKKK
      RES%ELLL = C%ELLL + A*B%ELLL
      RES%EMMM = C%EMMM + A*B%EMMM
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

   END FUNCTION DONUMM22N5_GEM_ROO

ELEMENTAL    FUNCTION DONUMM22N5_GEM_ORO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: A 
      REAL(DP), INTENT(IN) :: B 
      TYPE(DONUMM22N5), INTENT(IN) :: C 
      TYPE(DONUMM22N5) :: RES 

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

      ! Order 3
      RES%E111 = C%E111 + A%E111*B
      RES%E222 = C%E222 + A%E222*B
      RES%E333 = C%E333 + A%E333*B
      RES%E444 = C%E444 + A%E444*B
      RES%E555 = C%E555 + A%E555*B
      RES%E666 = C%E666 + A%E666*B
      RES%E777 = C%E777 + A%E777*B
      RES%E888 = C%E888 + A%E888*B
      RES%E999 = C%E999 + A%E999*B
      RES%EAAA = C%EAAA + A%EAAA*B
      RES%EBBB = C%EBBB + A%EBBB*B
      RES%ECCC = C%ECCC + A%ECCC*B
      RES%EDDD = C%EDDD + A%EDDD*B
      RES%EEEE = C%EEEE + A%EEEE*B
      RES%EFFF = C%EFFF + A%EFFF*B
      RES%EGGG = C%EGGG + A%EGGG*B
      RES%EHHH = C%EHHH + A%EHHH*B
      RES%EIII = C%EIII + A%EIII*B
      RES%EJJJ = C%EJJJ + A%EJJJ*B
      RES%EKKK = C%EKKK + A%EKKK*B
      RES%ELLL = C%ELLL + A%ELLL*B
      RES%EMMM = C%EMMM + A%EMMM*B

      ! Order 4
      RES%E1111 = C%E1111 + A%E1111*B
      RES%E2222 = C%E2222 + A%E2222*B
      RES%E3333 = C%E3333 + A%E3333*B
      RES%E4444 = C%E4444 + A%E4444*B
      RES%E5555 = C%E5555 + A%E5555*B
      RES%E6666 = C%E6666 + A%E6666*B
      RES%E7777 = C%E7777 + A%E7777*B
      RES%E8888 = C%E8888 + A%E8888*B
      RES%E9999 = C%E9999 + A%E9999*B
      RES%EAAAA = C%EAAAA + A%EAAAA*B
      RES%EBBBB = C%EBBBB + A%EBBBB*B
      RES%ECCCC = C%ECCCC + A%ECCCC*B
      RES%EDDDD = C%EDDDD + A%EDDDD*B
      RES%EEEEE = C%EEEEE + A%EEEEE*B
      RES%EFFFF = C%EFFFF + A%EFFFF*B
      RES%EGGGG = C%EGGGG + A%EGGGG*B
      RES%EHHHH = C%EHHHH + A%EHHHH*B
      RES%EIIII = C%EIIII + A%EIIII*B
      RES%EJJJJ = C%EJJJJ + A%EJJJJ*B
      RES%EKKKK = C%EKKKK + A%EKKKK*B
      RES%ELLLL = C%ELLLL + A%ELLLL*B
      RES%EMMMM = C%EMMMM + A%EMMMM*B

      ! Order 5
      RES%E11111 = C%E11111 + A%E11111*B
      RES%E22222 = C%E22222 + A%E22222*B
      RES%E33333 = C%E33333 + A%E33333*B
      RES%E44444 = C%E44444 + A%E44444*B
      RES%E55555 = C%E55555 + A%E55555*B
      RES%E66666 = C%E66666 + A%E66666*B
      RES%E77777 = C%E77777 + A%E77777*B
      RES%E88888 = C%E88888 + A%E88888*B
      RES%E99999 = C%E99999 + A%E99999*B
      RES%EAAAAA = C%EAAAAA + A%EAAAAA*B
      RES%EBBBBB = C%EBBBBB + A%EBBBBB*B
      RES%ECCCCC = C%ECCCCC + A%ECCCCC*B
      RES%EDDDDD = C%EDDDDD + A%EDDDDD*B
      RES%EEEEEE = C%EEEEEE + A%EEEEEE*B
      RES%EFFFFF = C%EFFFFF + A%EFFFFF*B
      RES%EGGGGG = C%EGGGGG + A%EGGGGG*B
      RES%EHHHHH = C%EHHHHH + A%EHHHHH*B
      RES%EIIIII = C%EIIIII + A%EIIIII*B
      RES%EJJJJJ = C%EJJJJJ + A%EJJJJJ*B
      RES%EKKKKK = C%EKKKKK + A%EKKKKK*B
      RES%ELLLLL = C%ELLLLL + A%ELLLLL*B
      RES%EMMMMM = C%EMMMMM + A%EMMMMM*B

   END FUNCTION DONUMM22N5_GEM_ORO

   FUNCTION DONUMM22N5_MATMUL_DONUMM22N5(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N5), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      !  Multiplication like function 'MATMUL(lhs,rhs)'
      ! Order 5
      res%E11111 = MATMUL(lhs%R,rhs%E11111) + MATMUL(lhs%E11111,rhs%R) +  &
                MATMUL(lhs%E1,rhs%E1111) + MATMUL(lhs%E1111,rhs%E1) + MATMUL(lhs%E11,rhs%E111) + MATMUL(lhs%E111,rhs%E11)
      res%E22222 = MATMUL(lhs%R,rhs%E22222) + MATMUL(lhs%E22222,rhs%R) +  &
                MATMUL(lhs%E2,rhs%E2222) + MATMUL(lhs%E2222,rhs%E2) + MATMUL(lhs%E22,rhs%E222) + MATMUL(lhs%E222,rhs%E22)
      res%E33333 = MATMUL(lhs%R,rhs%E33333) + MATMUL(lhs%E33333,rhs%R) +  &
                MATMUL(lhs%E3,rhs%E3333) + MATMUL(lhs%E3333,rhs%E3) + MATMUL(lhs%E33,rhs%E333) + MATMUL(lhs%E333,rhs%E33)
      res%E44444 = MATMUL(lhs%R,rhs%E44444) + MATMUL(lhs%E44444,rhs%R) +  &
                MATMUL(lhs%E4,rhs%E4444) + MATMUL(lhs%E4444,rhs%E4) + MATMUL(lhs%E44,rhs%E444) + MATMUL(lhs%E444,rhs%E44)
      res%E55555 = MATMUL(lhs%R,rhs%E55555) + MATMUL(lhs%E55555,rhs%R) +  &
                MATMUL(lhs%E5,rhs%E5555) + MATMUL(lhs%E5555,rhs%E5) + MATMUL(lhs%E55,rhs%E555) + MATMUL(lhs%E555,rhs%E55)
      res%E66666 = MATMUL(lhs%R,rhs%E66666) + MATMUL(lhs%E66666,rhs%R) +  &
                MATMUL(lhs%E6,rhs%E6666) + MATMUL(lhs%E6666,rhs%E6) + MATMUL(lhs%E66,rhs%E666) + MATMUL(lhs%E666,rhs%E66)
      res%E77777 = MATMUL(lhs%R,rhs%E77777) + MATMUL(lhs%E77777,rhs%R) +  &
                MATMUL(lhs%E7,rhs%E7777) + MATMUL(lhs%E7777,rhs%E7) + MATMUL(lhs%E77,rhs%E777) + MATMUL(lhs%E777,rhs%E77)
      res%E88888 = MATMUL(lhs%R,rhs%E88888) + MATMUL(lhs%E88888,rhs%R) +  &
                MATMUL(lhs%E8,rhs%E8888) + MATMUL(lhs%E8888,rhs%E8) + MATMUL(lhs%E88,rhs%E888) + MATMUL(lhs%E888,rhs%E88)
      res%E99999 = MATMUL(lhs%R,rhs%E99999) + MATMUL(lhs%E99999,rhs%R) +  &
                MATMUL(lhs%E9,rhs%E9999) + MATMUL(lhs%E9999,rhs%E9) + MATMUL(lhs%E99,rhs%E999) + MATMUL(lhs%E999,rhs%E99)
      res%EAAAAA = MATMUL(lhs%R,rhs%EAAAAA) + MATMUL(lhs%EAAAAA,rhs%R) +  &
                MATMUL(lhs%EA,rhs%EAAAA) + MATMUL(lhs%EAAAA,rhs%EA) + MATMUL(lhs%EAA,rhs%EAAA) + MATMUL(lhs%EAAA,rhs%EAA)
      res%EBBBBB = MATMUL(lhs%R,rhs%EBBBBB) + MATMUL(lhs%EBBBBB,rhs%R) +  &
                MATMUL(lhs%EB,rhs%EBBBB) + MATMUL(lhs%EBBBB,rhs%EB) + MATMUL(lhs%EBB,rhs%EBBB) + MATMUL(lhs%EBBB,rhs%EBB)
      res%ECCCCC = MATMUL(lhs%R,rhs%ECCCCC) + MATMUL(lhs%ECCCCC,rhs%R) +  &
                MATMUL(lhs%EC,rhs%ECCCC) + MATMUL(lhs%ECCCC,rhs%EC) + MATMUL(lhs%ECC,rhs%ECCC) + MATMUL(lhs%ECCC,rhs%ECC)
      res%EDDDDD = MATMUL(lhs%R,rhs%EDDDDD) + MATMUL(lhs%EDDDDD,rhs%R) +  &
                MATMUL(lhs%ED,rhs%EDDDD) + MATMUL(lhs%EDDDD,rhs%ED) + MATMUL(lhs%EDD,rhs%EDDD) + MATMUL(lhs%EDDD,rhs%EDD)
      res%EEEEEE = MATMUL(lhs%R,rhs%EEEEEE) + MATMUL(lhs%EEEEEE,rhs%R) +  &
                MATMUL(lhs%EE,rhs%EEEEE) + MATMUL(lhs%EEEEE,rhs%EE) + MATMUL(lhs%EEE,rhs%EEEE) + MATMUL(lhs%EEEE,rhs%EEE)
      res%EFFFFF = MATMUL(lhs%R,rhs%EFFFFF) + MATMUL(lhs%EFFFFF,rhs%R) +  &
                MATMUL(lhs%EF,rhs%EFFFF) + MATMUL(lhs%EFFFF,rhs%EF) + MATMUL(lhs%EFF,rhs%EFFF) + MATMUL(lhs%EFFF,rhs%EFF)
      res%EGGGGG = MATMUL(lhs%R,rhs%EGGGGG) + MATMUL(lhs%EGGGGG,rhs%R) +  &
                MATMUL(lhs%EG,rhs%EGGGG) + MATMUL(lhs%EGGGG,rhs%EG) + MATMUL(lhs%EGG,rhs%EGGG) + MATMUL(lhs%EGGG,rhs%EGG)
      res%EHHHHH = MATMUL(lhs%R,rhs%EHHHHH) + MATMUL(lhs%EHHHHH,rhs%R) +  &
                MATMUL(lhs%EH,rhs%EHHHH) + MATMUL(lhs%EHHHH,rhs%EH) + MATMUL(lhs%EHH,rhs%EHHH) + MATMUL(lhs%EHHH,rhs%EHH)
      res%EIIIII = MATMUL(lhs%R,rhs%EIIIII) + MATMUL(lhs%EIIIII,rhs%R) +  &
                MATMUL(lhs%EI,rhs%EIIII) + MATMUL(lhs%EIIII,rhs%EI) + MATMUL(lhs%EII,rhs%EIII) + MATMUL(lhs%EIII,rhs%EII)
      res%EJJJJJ = MATMUL(lhs%R,rhs%EJJJJJ) + MATMUL(lhs%EJJJJJ,rhs%R) +  &
                MATMUL(lhs%EJ,rhs%EJJJJ) + MATMUL(lhs%EJJJJ,rhs%EJ) + MATMUL(lhs%EJJ,rhs%EJJJ) + MATMUL(lhs%EJJJ,rhs%EJJ)
      res%EKKKKK = MATMUL(lhs%R,rhs%EKKKKK) + MATMUL(lhs%EKKKKK,rhs%R) +  &
                MATMUL(lhs%EK,rhs%EKKKK) + MATMUL(lhs%EKKKK,rhs%EK) + MATMUL(lhs%EKK,rhs%EKKK) + MATMUL(lhs%EKKK,rhs%EKK)
      res%ELLLLL = MATMUL(lhs%R,rhs%ELLLLL) + MATMUL(lhs%ELLLLL,rhs%R) +  &
                MATMUL(lhs%EL,rhs%ELLLL) + MATMUL(lhs%ELLLL,rhs%EL) + MATMUL(lhs%ELL,rhs%ELLL) + MATMUL(lhs%ELLL,rhs%ELL)
      res%EMMMMM = MATMUL(lhs%R,rhs%EMMMMM) + MATMUL(lhs%EMMMMM,rhs%R) +  &
                MATMUL(lhs%EM,rhs%EMMMM) + MATMUL(lhs%EMMMM,rhs%EM) + MATMUL(lhs%EMM,rhs%EMMM) + MATMUL(lhs%EMMM,rhs%EMM)
      ! Order 4
      res%E1111 = MATMUL(lhs%R,rhs%E1111) + MATMUL(lhs%E1111,rhs%R) +  &
               MATMUL(lhs%E1,rhs%E111) + MATMUL(lhs%E111,rhs%E1) + MATMUL(lhs%E11,rhs%E11)
      res%E2222 = MATMUL(lhs%R,rhs%E2222) + MATMUL(lhs%E2222,rhs%R) +  &
               MATMUL(lhs%E2,rhs%E222) + MATMUL(lhs%E222,rhs%E2) + MATMUL(lhs%E22,rhs%E22)
      res%E3333 = MATMUL(lhs%R,rhs%E3333) + MATMUL(lhs%E3333,rhs%R) +  &
               MATMUL(lhs%E3,rhs%E333) + MATMUL(lhs%E333,rhs%E3) + MATMUL(lhs%E33,rhs%E33)
      res%E4444 = MATMUL(lhs%R,rhs%E4444) + MATMUL(lhs%E4444,rhs%R) +  &
               MATMUL(lhs%E4,rhs%E444) + MATMUL(lhs%E444,rhs%E4) + MATMUL(lhs%E44,rhs%E44)
      res%E5555 = MATMUL(lhs%R,rhs%E5555) + MATMUL(lhs%E5555,rhs%R) +  &
               MATMUL(lhs%E5,rhs%E555) + MATMUL(lhs%E555,rhs%E5) + MATMUL(lhs%E55,rhs%E55)
      res%E6666 = MATMUL(lhs%R,rhs%E6666) + MATMUL(lhs%E6666,rhs%R) +  &
               MATMUL(lhs%E6,rhs%E666) + MATMUL(lhs%E666,rhs%E6) + MATMUL(lhs%E66,rhs%E66)
      res%E7777 = MATMUL(lhs%R,rhs%E7777) + MATMUL(lhs%E7777,rhs%R) +  &
               MATMUL(lhs%E7,rhs%E777) + MATMUL(lhs%E777,rhs%E7) + MATMUL(lhs%E77,rhs%E77)
      res%E8888 = MATMUL(lhs%R,rhs%E8888) + MATMUL(lhs%E8888,rhs%R) +  &
               MATMUL(lhs%E8,rhs%E888) + MATMUL(lhs%E888,rhs%E8) + MATMUL(lhs%E88,rhs%E88)
      res%E9999 = MATMUL(lhs%R,rhs%E9999) + MATMUL(lhs%E9999,rhs%R) +  &
               MATMUL(lhs%E9,rhs%E999) + MATMUL(lhs%E999,rhs%E9) + MATMUL(lhs%E99,rhs%E99)
      res%EAAAA = MATMUL(lhs%R,rhs%EAAAA) + MATMUL(lhs%EAAAA,rhs%R) +  &
               MATMUL(lhs%EA,rhs%EAAA) + MATMUL(lhs%EAAA,rhs%EA) + MATMUL(lhs%EAA,rhs%EAA)
      res%EBBBB = MATMUL(lhs%R,rhs%EBBBB) + MATMUL(lhs%EBBBB,rhs%R) +  &
               MATMUL(lhs%EB,rhs%EBBB) + MATMUL(lhs%EBBB,rhs%EB) + MATMUL(lhs%EBB,rhs%EBB)
      res%ECCCC = MATMUL(lhs%R,rhs%ECCCC) + MATMUL(lhs%ECCCC,rhs%R) +  &
               MATMUL(lhs%EC,rhs%ECCC) + MATMUL(lhs%ECCC,rhs%EC) + MATMUL(lhs%ECC,rhs%ECC)
      res%EDDDD = MATMUL(lhs%R,rhs%EDDDD) + MATMUL(lhs%EDDDD,rhs%R) +  &
               MATMUL(lhs%ED,rhs%EDDD) + MATMUL(lhs%EDDD,rhs%ED) + MATMUL(lhs%EDD,rhs%EDD)
      res%EEEEE = MATMUL(lhs%R,rhs%EEEEE) + MATMUL(lhs%EEEEE,rhs%R) +  &
               MATMUL(lhs%EE,rhs%EEEE) + MATMUL(lhs%EEEE,rhs%EE) + MATMUL(lhs%EEE,rhs%EEE)
      res%EFFFF = MATMUL(lhs%R,rhs%EFFFF) + MATMUL(lhs%EFFFF,rhs%R) +  &
               MATMUL(lhs%EF,rhs%EFFF) + MATMUL(lhs%EFFF,rhs%EF) + MATMUL(lhs%EFF,rhs%EFF)
      res%EGGGG = MATMUL(lhs%R,rhs%EGGGG) + MATMUL(lhs%EGGGG,rhs%R) +  &
               MATMUL(lhs%EG,rhs%EGGG) + MATMUL(lhs%EGGG,rhs%EG) + MATMUL(lhs%EGG,rhs%EGG)
      res%EHHHH = MATMUL(lhs%R,rhs%EHHHH) + MATMUL(lhs%EHHHH,rhs%R) +  &
               MATMUL(lhs%EH,rhs%EHHH) + MATMUL(lhs%EHHH,rhs%EH) + MATMUL(lhs%EHH,rhs%EHH)
      res%EIIII = MATMUL(lhs%R,rhs%EIIII) + MATMUL(lhs%EIIII,rhs%R) +  &
               MATMUL(lhs%EI,rhs%EIII) + MATMUL(lhs%EIII,rhs%EI) + MATMUL(lhs%EII,rhs%EII)
      res%EJJJJ = MATMUL(lhs%R,rhs%EJJJJ) + MATMUL(lhs%EJJJJ,rhs%R) +  &
               MATMUL(lhs%EJ,rhs%EJJJ) + MATMUL(lhs%EJJJ,rhs%EJ) + MATMUL(lhs%EJJ,rhs%EJJ)
      res%EKKKK = MATMUL(lhs%R,rhs%EKKKK) + MATMUL(lhs%EKKKK,rhs%R) +  &
               MATMUL(lhs%EK,rhs%EKKK) + MATMUL(lhs%EKKK,rhs%EK) + MATMUL(lhs%EKK,rhs%EKK)
      res%ELLLL = MATMUL(lhs%R,rhs%ELLLL) + MATMUL(lhs%ELLLL,rhs%R) +  &
               MATMUL(lhs%EL,rhs%ELLL) + MATMUL(lhs%ELLL,rhs%EL) + MATMUL(lhs%ELL,rhs%ELL)
      res%EMMMM = MATMUL(lhs%R,rhs%EMMMM) + MATMUL(lhs%EMMMM,rhs%R) +  &
               MATMUL(lhs%EM,rhs%EMMM) + MATMUL(lhs%EMMM,rhs%EM) + MATMUL(lhs%EMM,rhs%EMM)
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
      res%E888 = MATMUL(lhs%R,rhs%E888) + MATMUL(lhs%E888,rhs%R) +  &
              MATMUL(lhs%E8,rhs%E88) + MATMUL(lhs%E88,rhs%E8)
      res%E999 = MATMUL(lhs%R,rhs%E999) + MATMUL(lhs%E999,rhs%R) +  &
              MATMUL(lhs%E9,rhs%E99) + MATMUL(lhs%E99,rhs%E9)
      res%EAAA = MATMUL(lhs%R,rhs%EAAA) + MATMUL(lhs%EAAA,rhs%R) +  &
              MATMUL(lhs%EA,rhs%EAA) + MATMUL(lhs%EAA,rhs%EA)
      res%EBBB = MATMUL(lhs%R,rhs%EBBB) + MATMUL(lhs%EBBB,rhs%R) +  &
              MATMUL(lhs%EB,rhs%EBB) + MATMUL(lhs%EBB,rhs%EB)
      res%ECCC = MATMUL(lhs%R,rhs%ECCC) + MATMUL(lhs%ECCC,rhs%R) +  &
              MATMUL(lhs%EC,rhs%ECC) + MATMUL(lhs%ECC,rhs%EC)
      res%EDDD = MATMUL(lhs%R,rhs%EDDD) + MATMUL(lhs%EDDD,rhs%R) +  &
              MATMUL(lhs%ED,rhs%EDD) + MATMUL(lhs%EDD,rhs%ED)
      res%EEEE = MATMUL(lhs%R,rhs%EEEE) + MATMUL(lhs%EEEE,rhs%R) +  &
              MATMUL(lhs%EE,rhs%EEE) + MATMUL(lhs%EEE,rhs%EE)
      res%EFFF = MATMUL(lhs%R,rhs%EFFF) + MATMUL(lhs%EFFF,rhs%R) +  &
              MATMUL(lhs%EF,rhs%EFF) + MATMUL(lhs%EFF,rhs%EF)
      res%EGGG = MATMUL(lhs%R,rhs%EGGG) + MATMUL(lhs%EGGG,rhs%R) +  &
              MATMUL(lhs%EG,rhs%EGG) + MATMUL(lhs%EGG,rhs%EG)
      res%EHHH = MATMUL(lhs%R,rhs%EHHH) + MATMUL(lhs%EHHH,rhs%R) +  &
              MATMUL(lhs%EH,rhs%EHH) + MATMUL(lhs%EHH,rhs%EH)
      res%EIII = MATMUL(lhs%R,rhs%EIII) + MATMUL(lhs%EIII,rhs%R) +  &
              MATMUL(lhs%EI,rhs%EII) + MATMUL(lhs%EII,rhs%EI)
      res%EJJJ = MATMUL(lhs%R,rhs%EJJJ) + MATMUL(lhs%EJJJ,rhs%R) +  &
              MATMUL(lhs%EJ,rhs%EJJ) + MATMUL(lhs%EJJ,rhs%EJ)
      res%EKKK = MATMUL(lhs%R,rhs%EKKK) + MATMUL(lhs%EKKK,rhs%R) +  &
              MATMUL(lhs%EK,rhs%EKK) + MATMUL(lhs%EKK,rhs%EK)
      res%ELLL = MATMUL(lhs%R,rhs%ELLL) + MATMUL(lhs%ELLL,rhs%R) +  &
              MATMUL(lhs%EL,rhs%ELL) + MATMUL(lhs%ELL,rhs%EL)
      res%EMMM = MATMUL(lhs%R,rhs%EMMM) + MATMUL(lhs%EMMM,rhs%R) +  &
              MATMUL(lhs%EM,rhs%EMM) + MATMUL(lhs%EMM,rhs%EM)
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

   END FUNCTION DONUMM22N5_MATMUL_DONUMM22N5

   FUNCTION R_MATMUL_DONUMM22N5(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N5), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1),SIZE(RHS,2))

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

      ! Order 3
      res%E111 = MATMUL(lhs,rhs%E111)
      res%E222 = MATMUL(lhs,rhs%E222)
      res%E333 = MATMUL(lhs,rhs%E333)
      res%E444 = MATMUL(lhs,rhs%E444)
      res%E555 = MATMUL(lhs,rhs%E555)
      res%E666 = MATMUL(lhs,rhs%E666)
      res%E777 = MATMUL(lhs,rhs%E777)
      res%E888 = MATMUL(lhs,rhs%E888)
      res%E999 = MATMUL(lhs,rhs%E999)
      res%EAAA = MATMUL(lhs,rhs%EAAA)
      res%EBBB = MATMUL(lhs,rhs%EBBB)
      res%ECCC = MATMUL(lhs,rhs%ECCC)
      res%EDDD = MATMUL(lhs,rhs%EDDD)
      res%EEEE = MATMUL(lhs,rhs%EEEE)
      res%EFFF = MATMUL(lhs,rhs%EFFF)
      res%EGGG = MATMUL(lhs,rhs%EGGG)
      res%EHHH = MATMUL(lhs,rhs%EHHH)
      res%EIII = MATMUL(lhs,rhs%EIII)
      res%EJJJ = MATMUL(lhs,rhs%EJJJ)
      res%EKKK = MATMUL(lhs,rhs%EKKK)
      res%ELLL = MATMUL(lhs,rhs%ELLL)
      res%EMMM = MATMUL(lhs,rhs%EMMM)

      ! Order 4
      res%E1111 = MATMUL(lhs,rhs%E1111)
      res%E2222 = MATMUL(lhs,rhs%E2222)
      res%E3333 = MATMUL(lhs,rhs%E3333)
      res%E4444 = MATMUL(lhs,rhs%E4444)
      res%E5555 = MATMUL(lhs,rhs%E5555)
      res%E6666 = MATMUL(lhs,rhs%E6666)
      res%E7777 = MATMUL(lhs,rhs%E7777)
      res%E8888 = MATMUL(lhs,rhs%E8888)
      res%E9999 = MATMUL(lhs,rhs%E9999)
      res%EAAAA = MATMUL(lhs,rhs%EAAAA)
      res%EBBBB = MATMUL(lhs,rhs%EBBBB)
      res%ECCCC = MATMUL(lhs,rhs%ECCCC)
      res%EDDDD = MATMUL(lhs,rhs%EDDDD)
      res%EEEEE = MATMUL(lhs,rhs%EEEEE)
      res%EFFFF = MATMUL(lhs,rhs%EFFFF)
      res%EGGGG = MATMUL(lhs,rhs%EGGGG)
      res%EHHHH = MATMUL(lhs,rhs%EHHHH)
      res%EIIII = MATMUL(lhs,rhs%EIIII)
      res%EJJJJ = MATMUL(lhs,rhs%EJJJJ)
      res%EKKKK = MATMUL(lhs,rhs%EKKKK)
      res%ELLLL = MATMUL(lhs,rhs%ELLLL)
      res%EMMMM = MATMUL(lhs,rhs%EMMMM)

      ! Order 5
      res%E11111 = MATMUL(lhs,rhs%E11111)
      res%E22222 = MATMUL(lhs,rhs%E22222)
      res%E33333 = MATMUL(lhs,rhs%E33333)
      res%E44444 = MATMUL(lhs,rhs%E44444)
      res%E55555 = MATMUL(lhs,rhs%E55555)
      res%E66666 = MATMUL(lhs,rhs%E66666)
      res%E77777 = MATMUL(lhs,rhs%E77777)
      res%E88888 = MATMUL(lhs,rhs%E88888)
      res%E99999 = MATMUL(lhs,rhs%E99999)
      res%EAAAAA = MATMUL(lhs,rhs%EAAAAA)
      res%EBBBBB = MATMUL(lhs,rhs%EBBBBB)
      res%ECCCCC = MATMUL(lhs,rhs%ECCCCC)
      res%EDDDDD = MATMUL(lhs,rhs%EDDDDD)
      res%EEEEEE = MATMUL(lhs,rhs%EEEEEE)
      res%EFFFFF = MATMUL(lhs,rhs%EFFFFF)
      res%EGGGGG = MATMUL(lhs,rhs%EGGGGG)
      res%EHHHHH = MATMUL(lhs,rhs%EHHHHH)
      res%EIIIII = MATMUL(lhs,rhs%EIIIII)
      res%EJJJJJ = MATMUL(lhs,rhs%EJJJJJ)
      res%EKKKKK = MATMUL(lhs,rhs%EKKKKK)
      res%ELLLLL = MATMUL(lhs,rhs%ELLLLL)
      res%EMMMMM = MATMUL(lhs,rhs%EMMMMM)

   END FUNCTION R_MATMUL_DONUMM22N5

   FUNCTION DONUMM22N5_MATMUL_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM22N5) :: RES(SIZE(LHS,1),SIZE(RHS,2))

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

      ! Order 3
      res%E111 = MATMUL(lhs%E111,rhs)
      res%E222 = MATMUL(lhs%E222,rhs)
      res%E333 = MATMUL(lhs%E333,rhs)
      res%E444 = MATMUL(lhs%E444,rhs)
      res%E555 = MATMUL(lhs%E555,rhs)
      res%E666 = MATMUL(lhs%E666,rhs)
      res%E777 = MATMUL(lhs%E777,rhs)
      res%E888 = MATMUL(lhs%E888,rhs)
      res%E999 = MATMUL(lhs%E999,rhs)
      res%EAAA = MATMUL(lhs%EAAA,rhs)
      res%EBBB = MATMUL(lhs%EBBB,rhs)
      res%ECCC = MATMUL(lhs%ECCC,rhs)
      res%EDDD = MATMUL(lhs%EDDD,rhs)
      res%EEEE = MATMUL(lhs%EEEE,rhs)
      res%EFFF = MATMUL(lhs%EFFF,rhs)
      res%EGGG = MATMUL(lhs%EGGG,rhs)
      res%EHHH = MATMUL(lhs%EHHH,rhs)
      res%EIII = MATMUL(lhs%EIII,rhs)
      res%EJJJ = MATMUL(lhs%EJJJ,rhs)
      res%EKKK = MATMUL(lhs%EKKK,rhs)
      res%ELLL = MATMUL(lhs%ELLL,rhs)
      res%EMMM = MATMUL(lhs%EMMM,rhs)

      ! Order 4
      res%E1111 = MATMUL(lhs%E1111,rhs)
      res%E2222 = MATMUL(lhs%E2222,rhs)
      res%E3333 = MATMUL(lhs%E3333,rhs)
      res%E4444 = MATMUL(lhs%E4444,rhs)
      res%E5555 = MATMUL(lhs%E5555,rhs)
      res%E6666 = MATMUL(lhs%E6666,rhs)
      res%E7777 = MATMUL(lhs%E7777,rhs)
      res%E8888 = MATMUL(lhs%E8888,rhs)
      res%E9999 = MATMUL(lhs%E9999,rhs)
      res%EAAAA = MATMUL(lhs%EAAAA,rhs)
      res%EBBBB = MATMUL(lhs%EBBBB,rhs)
      res%ECCCC = MATMUL(lhs%ECCCC,rhs)
      res%EDDDD = MATMUL(lhs%EDDDD,rhs)
      res%EEEEE = MATMUL(lhs%EEEEE,rhs)
      res%EFFFF = MATMUL(lhs%EFFFF,rhs)
      res%EGGGG = MATMUL(lhs%EGGGG,rhs)
      res%EHHHH = MATMUL(lhs%EHHHH,rhs)
      res%EIIII = MATMUL(lhs%EIIII,rhs)
      res%EJJJJ = MATMUL(lhs%EJJJJ,rhs)
      res%EKKKK = MATMUL(lhs%EKKKK,rhs)
      res%ELLLL = MATMUL(lhs%ELLLL,rhs)
      res%EMMMM = MATMUL(lhs%EMMMM,rhs)

      ! Order 5
      res%E11111 = MATMUL(lhs%E11111,rhs)
      res%E22222 = MATMUL(lhs%E22222,rhs)
      res%E33333 = MATMUL(lhs%E33333,rhs)
      res%E44444 = MATMUL(lhs%E44444,rhs)
      res%E55555 = MATMUL(lhs%E55555,rhs)
      res%E66666 = MATMUL(lhs%E66666,rhs)
      res%E77777 = MATMUL(lhs%E77777,rhs)
      res%E88888 = MATMUL(lhs%E88888,rhs)
      res%E99999 = MATMUL(lhs%E99999,rhs)
      res%EAAAAA = MATMUL(lhs%EAAAAA,rhs)
      res%EBBBBB = MATMUL(lhs%EBBBBB,rhs)
      res%ECCCCC = MATMUL(lhs%ECCCCC,rhs)
      res%EDDDDD = MATMUL(lhs%EDDDDD,rhs)
      res%EEEEEE = MATMUL(lhs%EEEEEE,rhs)
      res%EFFFFF = MATMUL(lhs%EFFFFF,rhs)
      res%EGGGGG = MATMUL(lhs%EGGGGG,rhs)
      res%EHHHHH = MATMUL(lhs%EHHHHH,rhs)
      res%EIIIII = MATMUL(lhs%EIIIII,rhs)
      res%EJJJJJ = MATMUL(lhs%EJJJJJ,rhs)
      res%EKKKKK = MATMUL(lhs%EKKKKK,rhs)
      res%ELLLLL = MATMUL(lhs%ELLLLL,rhs)
      res%EMMMMM = MATMUL(lhs%EMMMMM,rhs)

   END FUNCTION DONUMM22N5_MATMUL_R

   FUNCTION DONUMM22N5_DOT_PRODUCT_DONUMM22N5(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:)
      TYPE(DONUMM22N5), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(DONUMM22N5) :: RES

      !  Multiplication like function 'DOT_PRODUCT(lhs,rhs)'
      ! Order 5
      res%E11111 = DOT_PRODUCT(lhs%R,rhs%E11111) + DOT_PRODUCT(lhs%E11111,rhs%R) +  &
                DOT_PRODUCT(lhs%E1,rhs%E1111) + DOT_PRODUCT(lhs%E1111,rhs%E1) + DOT_PRODUCT(lhs%E11,rhs%E111) + DOT_PRODUCT(lhs%E111,rhs%E11)
      res%E22222 = DOT_PRODUCT(lhs%R,rhs%E22222) + DOT_PRODUCT(lhs%E22222,rhs%R) +  &
                DOT_PRODUCT(lhs%E2,rhs%E2222) + DOT_PRODUCT(lhs%E2222,rhs%E2) + DOT_PRODUCT(lhs%E22,rhs%E222) + DOT_PRODUCT(lhs%E222,rhs%E22)
      res%E33333 = DOT_PRODUCT(lhs%R,rhs%E33333) + DOT_PRODUCT(lhs%E33333,rhs%R) +  &
                DOT_PRODUCT(lhs%E3,rhs%E3333) + DOT_PRODUCT(lhs%E3333,rhs%E3) + DOT_PRODUCT(lhs%E33,rhs%E333) + DOT_PRODUCT(lhs%E333,rhs%E33)
      res%E44444 = DOT_PRODUCT(lhs%R,rhs%E44444) + DOT_PRODUCT(lhs%E44444,rhs%R) +  &
                DOT_PRODUCT(lhs%E4,rhs%E4444) + DOT_PRODUCT(lhs%E4444,rhs%E4) + DOT_PRODUCT(lhs%E44,rhs%E444) + DOT_PRODUCT(lhs%E444,rhs%E44)
      res%E55555 = DOT_PRODUCT(lhs%R,rhs%E55555) + DOT_PRODUCT(lhs%E55555,rhs%R) +  &
                DOT_PRODUCT(lhs%E5,rhs%E5555) + DOT_PRODUCT(lhs%E5555,rhs%E5) + DOT_PRODUCT(lhs%E55,rhs%E555) + DOT_PRODUCT(lhs%E555,rhs%E55)
      res%E66666 = DOT_PRODUCT(lhs%R,rhs%E66666) + DOT_PRODUCT(lhs%E66666,rhs%R) +  &
                DOT_PRODUCT(lhs%E6,rhs%E6666) + DOT_PRODUCT(lhs%E6666,rhs%E6) + DOT_PRODUCT(lhs%E66,rhs%E666) + DOT_PRODUCT(lhs%E666,rhs%E66)
      res%E77777 = DOT_PRODUCT(lhs%R,rhs%E77777) + DOT_PRODUCT(lhs%E77777,rhs%R) +  &
                DOT_PRODUCT(lhs%E7,rhs%E7777) + DOT_PRODUCT(lhs%E7777,rhs%E7) + DOT_PRODUCT(lhs%E77,rhs%E777) + DOT_PRODUCT(lhs%E777,rhs%E77)
      res%E88888 = DOT_PRODUCT(lhs%R,rhs%E88888) + DOT_PRODUCT(lhs%E88888,rhs%R) +  &
                DOT_PRODUCT(lhs%E8,rhs%E8888) + DOT_PRODUCT(lhs%E8888,rhs%E8) + DOT_PRODUCT(lhs%E88,rhs%E888) + DOT_PRODUCT(lhs%E888,rhs%E88)
      res%E99999 = DOT_PRODUCT(lhs%R,rhs%E99999) + DOT_PRODUCT(lhs%E99999,rhs%R) +  &
                DOT_PRODUCT(lhs%E9,rhs%E9999) + DOT_PRODUCT(lhs%E9999,rhs%E9) + DOT_PRODUCT(lhs%E99,rhs%E999) + DOT_PRODUCT(lhs%E999,rhs%E99)
      res%EAAAAA = DOT_PRODUCT(lhs%R,rhs%EAAAAA) + DOT_PRODUCT(lhs%EAAAAA,rhs%R) +  &
                DOT_PRODUCT(lhs%EA,rhs%EAAAA) + DOT_PRODUCT(lhs%EAAAA,rhs%EA) + DOT_PRODUCT(lhs%EAA,rhs%EAAA) + DOT_PRODUCT(lhs%EAAA,rhs%EAA)
      res%EBBBBB = DOT_PRODUCT(lhs%R,rhs%EBBBBB) + DOT_PRODUCT(lhs%EBBBBB,rhs%R) +  &
                DOT_PRODUCT(lhs%EB,rhs%EBBBB) + DOT_PRODUCT(lhs%EBBBB,rhs%EB) + DOT_PRODUCT(lhs%EBB,rhs%EBBB) + DOT_PRODUCT(lhs%EBBB,rhs%EBB)
      res%ECCCCC = DOT_PRODUCT(lhs%R,rhs%ECCCCC) + DOT_PRODUCT(lhs%ECCCCC,rhs%R) +  &
                DOT_PRODUCT(lhs%EC,rhs%ECCCC) + DOT_PRODUCT(lhs%ECCCC,rhs%EC) + DOT_PRODUCT(lhs%ECC,rhs%ECCC) + DOT_PRODUCT(lhs%ECCC,rhs%ECC)
      res%EDDDDD = DOT_PRODUCT(lhs%R,rhs%EDDDDD) + DOT_PRODUCT(lhs%EDDDDD,rhs%R) +  &
                DOT_PRODUCT(lhs%ED,rhs%EDDDD) + DOT_PRODUCT(lhs%EDDDD,rhs%ED) + DOT_PRODUCT(lhs%EDD,rhs%EDDD) + DOT_PRODUCT(lhs%EDDD,rhs%EDD)
      res%EEEEEE = DOT_PRODUCT(lhs%R,rhs%EEEEEE) + DOT_PRODUCT(lhs%EEEEEE,rhs%R) +  &
                DOT_PRODUCT(lhs%EE,rhs%EEEEE) + DOT_PRODUCT(lhs%EEEEE,rhs%EE) + DOT_PRODUCT(lhs%EEE,rhs%EEEE) + DOT_PRODUCT(lhs%EEEE,rhs%EEE)
      res%EFFFFF = DOT_PRODUCT(lhs%R,rhs%EFFFFF) + DOT_PRODUCT(lhs%EFFFFF,rhs%R) +  &
                DOT_PRODUCT(lhs%EF,rhs%EFFFF) + DOT_PRODUCT(lhs%EFFFF,rhs%EF) + DOT_PRODUCT(lhs%EFF,rhs%EFFF) + DOT_PRODUCT(lhs%EFFF,rhs%EFF)
      res%EGGGGG = DOT_PRODUCT(lhs%R,rhs%EGGGGG) + DOT_PRODUCT(lhs%EGGGGG,rhs%R) +  &
                DOT_PRODUCT(lhs%EG,rhs%EGGGG) + DOT_PRODUCT(lhs%EGGGG,rhs%EG) + DOT_PRODUCT(lhs%EGG,rhs%EGGG) + DOT_PRODUCT(lhs%EGGG,rhs%EGG)
      res%EHHHHH = DOT_PRODUCT(lhs%R,rhs%EHHHHH) + DOT_PRODUCT(lhs%EHHHHH,rhs%R) +  &
                DOT_PRODUCT(lhs%EH,rhs%EHHHH) + DOT_PRODUCT(lhs%EHHHH,rhs%EH) + DOT_PRODUCT(lhs%EHH,rhs%EHHH) + DOT_PRODUCT(lhs%EHHH,rhs%EHH)
      res%EIIIII = DOT_PRODUCT(lhs%R,rhs%EIIIII) + DOT_PRODUCT(lhs%EIIIII,rhs%R) +  &
                DOT_PRODUCT(lhs%EI,rhs%EIIII) + DOT_PRODUCT(lhs%EIIII,rhs%EI) + DOT_PRODUCT(lhs%EII,rhs%EIII) + DOT_PRODUCT(lhs%EIII,rhs%EII)
      res%EJJJJJ = DOT_PRODUCT(lhs%R,rhs%EJJJJJ) + DOT_PRODUCT(lhs%EJJJJJ,rhs%R) +  &
                DOT_PRODUCT(lhs%EJ,rhs%EJJJJ) + DOT_PRODUCT(lhs%EJJJJ,rhs%EJ) + DOT_PRODUCT(lhs%EJJ,rhs%EJJJ) + DOT_PRODUCT(lhs%EJJJ,rhs%EJJ)
      res%EKKKKK = DOT_PRODUCT(lhs%R,rhs%EKKKKK) + DOT_PRODUCT(lhs%EKKKKK,rhs%R) +  &
                DOT_PRODUCT(lhs%EK,rhs%EKKKK) + DOT_PRODUCT(lhs%EKKKK,rhs%EK) + DOT_PRODUCT(lhs%EKK,rhs%EKKK) + DOT_PRODUCT(lhs%EKKK,rhs%EKK)
      res%ELLLLL = DOT_PRODUCT(lhs%R,rhs%ELLLLL) + DOT_PRODUCT(lhs%ELLLLL,rhs%R) +  &
                DOT_PRODUCT(lhs%EL,rhs%ELLLL) + DOT_PRODUCT(lhs%ELLLL,rhs%EL) + DOT_PRODUCT(lhs%ELL,rhs%ELLL) + DOT_PRODUCT(lhs%ELLL,rhs%ELL)
      res%EMMMMM = DOT_PRODUCT(lhs%R,rhs%EMMMMM) + DOT_PRODUCT(lhs%EMMMMM,rhs%R) +  &
                DOT_PRODUCT(lhs%EM,rhs%EMMMM) + DOT_PRODUCT(lhs%EMMMM,rhs%EM) + DOT_PRODUCT(lhs%EMM,rhs%EMMM) + DOT_PRODUCT(lhs%EMMM,rhs%EMM)
      ! Order 4
      res%E1111 = DOT_PRODUCT(lhs%R,rhs%E1111) + DOT_PRODUCT(lhs%E1111,rhs%R) +  &
               DOT_PRODUCT(lhs%E1,rhs%E111) + DOT_PRODUCT(lhs%E111,rhs%E1) + DOT_PRODUCT(lhs%E11,rhs%E11)
      res%E2222 = DOT_PRODUCT(lhs%R,rhs%E2222) + DOT_PRODUCT(lhs%E2222,rhs%R) +  &
               DOT_PRODUCT(lhs%E2,rhs%E222) + DOT_PRODUCT(lhs%E222,rhs%E2) + DOT_PRODUCT(lhs%E22,rhs%E22)
      res%E3333 = DOT_PRODUCT(lhs%R,rhs%E3333) + DOT_PRODUCT(lhs%E3333,rhs%R) +  &
               DOT_PRODUCT(lhs%E3,rhs%E333) + DOT_PRODUCT(lhs%E333,rhs%E3) + DOT_PRODUCT(lhs%E33,rhs%E33)
      res%E4444 = DOT_PRODUCT(lhs%R,rhs%E4444) + DOT_PRODUCT(lhs%E4444,rhs%R) +  &
               DOT_PRODUCT(lhs%E4,rhs%E444) + DOT_PRODUCT(lhs%E444,rhs%E4) + DOT_PRODUCT(lhs%E44,rhs%E44)
      res%E5555 = DOT_PRODUCT(lhs%R,rhs%E5555) + DOT_PRODUCT(lhs%E5555,rhs%R) +  &
               DOT_PRODUCT(lhs%E5,rhs%E555) + DOT_PRODUCT(lhs%E555,rhs%E5) + DOT_PRODUCT(lhs%E55,rhs%E55)
      res%E6666 = DOT_PRODUCT(lhs%R,rhs%E6666) + DOT_PRODUCT(lhs%E6666,rhs%R) +  &
               DOT_PRODUCT(lhs%E6,rhs%E666) + DOT_PRODUCT(lhs%E666,rhs%E6) + DOT_PRODUCT(lhs%E66,rhs%E66)
      res%E7777 = DOT_PRODUCT(lhs%R,rhs%E7777) + DOT_PRODUCT(lhs%E7777,rhs%R) +  &
               DOT_PRODUCT(lhs%E7,rhs%E777) + DOT_PRODUCT(lhs%E777,rhs%E7) + DOT_PRODUCT(lhs%E77,rhs%E77)
      res%E8888 = DOT_PRODUCT(lhs%R,rhs%E8888) + DOT_PRODUCT(lhs%E8888,rhs%R) +  &
               DOT_PRODUCT(lhs%E8,rhs%E888) + DOT_PRODUCT(lhs%E888,rhs%E8) + DOT_PRODUCT(lhs%E88,rhs%E88)
      res%E9999 = DOT_PRODUCT(lhs%R,rhs%E9999) + DOT_PRODUCT(lhs%E9999,rhs%R) +  &
               DOT_PRODUCT(lhs%E9,rhs%E999) + DOT_PRODUCT(lhs%E999,rhs%E9) + DOT_PRODUCT(lhs%E99,rhs%E99)
      res%EAAAA = DOT_PRODUCT(lhs%R,rhs%EAAAA) + DOT_PRODUCT(lhs%EAAAA,rhs%R) +  &
               DOT_PRODUCT(lhs%EA,rhs%EAAA) + DOT_PRODUCT(lhs%EAAA,rhs%EA) + DOT_PRODUCT(lhs%EAA,rhs%EAA)
      res%EBBBB = DOT_PRODUCT(lhs%R,rhs%EBBBB) + DOT_PRODUCT(lhs%EBBBB,rhs%R) +  &
               DOT_PRODUCT(lhs%EB,rhs%EBBB) + DOT_PRODUCT(lhs%EBBB,rhs%EB) + DOT_PRODUCT(lhs%EBB,rhs%EBB)
      res%ECCCC = DOT_PRODUCT(lhs%R,rhs%ECCCC) + DOT_PRODUCT(lhs%ECCCC,rhs%R) +  &
               DOT_PRODUCT(lhs%EC,rhs%ECCC) + DOT_PRODUCT(lhs%ECCC,rhs%EC) + DOT_PRODUCT(lhs%ECC,rhs%ECC)
      res%EDDDD = DOT_PRODUCT(lhs%R,rhs%EDDDD) + DOT_PRODUCT(lhs%EDDDD,rhs%R) +  &
               DOT_PRODUCT(lhs%ED,rhs%EDDD) + DOT_PRODUCT(lhs%EDDD,rhs%ED) + DOT_PRODUCT(lhs%EDD,rhs%EDD)
      res%EEEEE = DOT_PRODUCT(lhs%R,rhs%EEEEE) + DOT_PRODUCT(lhs%EEEEE,rhs%R) +  &
               DOT_PRODUCT(lhs%EE,rhs%EEEE) + DOT_PRODUCT(lhs%EEEE,rhs%EE) + DOT_PRODUCT(lhs%EEE,rhs%EEE)
      res%EFFFF = DOT_PRODUCT(lhs%R,rhs%EFFFF) + DOT_PRODUCT(lhs%EFFFF,rhs%R) +  &
               DOT_PRODUCT(lhs%EF,rhs%EFFF) + DOT_PRODUCT(lhs%EFFF,rhs%EF) + DOT_PRODUCT(lhs%EFF,rhs%EFF)
      res%EGGGG = DOT_PRODUCT(lhs%R,rhs%EGGGG) + DOT_PRODUCT(lhs%EGGGG,rhs%R) +  &
               DOT_PRODUCT(lhs%EG,rhs%EGGG) + DOT_PRODUCT(lhs%EGGG,rhs%EG) + DOT_PRODUCT(lhs%EGG,rhs%EGG)
      res%EHHHH = DOT_PRODUCT(lhs%R,rhs%EHHHH) + DOT_PRODUCT(lhs%EHHHH,rhs%R) +  &
               DOT_PRODUCT(lhs%EH,rhs%EHHH) + DOT_PRODUCT(lhs%EHHH,rhs%EH) + DOT_PRODUCT(lhs%EHH,rhs%EHH)
      res%EIIII = DOT_PRODUCT(lhs%R,rhs%EIIII) + DOT_PRODUCT(lhs%EIIII,rhs%R) +  &
               DOT_PRODUCT(lhs%EI,rhs%EIII) + DOT_PRODUCT(lhs%EIII,rhs%EI) + DOT_PRODUCT(lhs%EII,rhs%EII)
      res%EJJJJ = DOT_PRODUCT(lhs%R,rhs%EJJJJ) + DOT_PRODUCT(lhs%EJJJJ,rhs%R) +  &
               DOT_PRODUCT(lhs%EJ,rhs%EJJJ) + DOT_PRODUCT(lhs%EJJJ,rhs%EJ) + DOT_PRODUCT(lhs%EJJ,rhs%EJJ)
      res%EKKKK = DOT_PRODUCT(lhs%R,rhs%EKKKK) + DOT_PRODUCT(lhs%EKKKK,rhs%R) +  &
               DOT_PRODUCT(lhs%EK,rhs%EKKK) + DOT_PRODUCT(lhs%EKKK,rhs%EK) + DOT_PRODUCT(lhs%EKK,rhs%EKK)
      res%ELLLL = DOT_PRODUCT(lhs%R,rhs%ELLLL) + DOT_PRODUCT(lhs%ELLLL,rhs%R) +  &
               DOT_PRODUCT(lhs%EL,rhs%ELLL) + DOT_PRODUCT(lhs%ELLL,rhs%EL) + DOT_PRODUCT(lhs%ELL,rhs%ELL)
      res%EMMMM = DOT_PRODUCT(lhs%R,rhs%EMMMM) + DOT_PRODUCT(lhs%EMMMM,rhs%R) +  &
               DOT_PRODUCT(lhs%EM,rhs%EMMM) + DOT_PRODUCT(lhs%EMMM,rhs%EM) + DOT_PRODUCT(lhs%EMM,rhs%EMM)
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
      res%E888 = DOT_PRODUCT(lhs%R,rhs%E888) + DOT_PRODUCT(lhs%E888,rhs%R) +  &
              DOT_PRODUCT(lhs%E8,rhs%E88) + DOT_PRODUCT(lhs%E88,rhs%E8)
      res%E999 = DOT_PRODUCT(lhs%R,rhs%E999) + DOT_PRODUCT(lhs%E999,rhs%R) +  &
              DOT_PRODUCT(lhs%E9,rhs%E99) + DOT_PRODUCT(lhs%E99,rhs%E9)
      res%EAAA = DOT_PRODUCT(lhs%R,rhs%EAAA) + DOT_PRODUCT(lhs%EAAA,rhs%R) +  &
              DOT_PRODUCT(lhs%EA,rhs%EAA) + DOT_PRODUCT(lhs%EAA,rhs%EA)
      res%EBBB = DOT_PRODUCT(lhs%R,rhs%EBBB) + DOT_PRODUCT(lhs%EBBB,rhs%R) +  &
              DOT_PRODUCT(lhs%EB,rhs%EBB) + DOT_PRODUCT(lhs%EBB,rhs%EB)
      res%ECCC = DOT_PRODUCT(lhs%R,rhs%ECCC) + DOT_PRODUCT(lhs%ECCC,rhs%R) +  &
              DOT_PRODUCT(lhs%EC,rhs%ECC) + DOT_PRODUCT(lhs%ECC,rhs%EC)
      res%EDDD = DOT_PRODUCT(lhs%R,rhs%EDDD) + DOT_PRODUCT(lhs%EDDD,rhs%R) +  &
              DOT_PRODUCT(lhs%ED,rhs%EDD) + DOT_PRODUCT(lhs%EDD,rhs%ED)
      res%EEEE = DOT_PRODUCT(lhs%R,rhs%EEEE) + DOT_PRODUCT(lhs%EEEE,rhs%R) +  &
              DOT_PRODUCT(lhs%EE,rhs%EEE) + DOT_PRODUCT(lhs%EEE,rhs%EE)
      res%EFFF = DOT_PRODUCT(lhs%R,rhs%EFFF) + DOT_PRODUCT(lhs%EFFF,rhs%R) +  &
              DOT_PRODUCT(lhs%EF,rhs%EFF) + DOT_PRODUCT(lhs%EFF,rhs%EF)
      res%EGGG = DOT_PRODUCT(lhs%R,rhs%EGGG) + DOT_PRODUCT(lhs%EGGG,rhs%R) +  &
              DOT_PRODUCT(lhs%EG,rhs%EGG) + DOT_PRODUCT(lhs%EGG,rhs%EG)
      res%EHHH = DOT_PRODUCT(lhs%R,rhs%EHHH) + DOT_PRODUCT(lhs%EHHH,rhs%R) +  &
              DOT_PRODUCT(lhs%EH,rhs%EHH) + DOT_PRODUCT(lhs%EHH,rhs%EH)
      res%EIII = DOT_PRODUCT(lhs%R,rhs%EIII) + DOT_PRODUCT(lhs%EIII,rhs%R) +  &
              DOT_PRODUCT(lhs%EI,rhs%EII) + DOT_PRODUCT(lhs%EII,rhs%EI)
      res%EJJJ = DOT_PRODUCT(lhs%R,rhs%EJJJ) + DOT_PRODUCT(lhs%EJJJ,rhs%R) +  &
              DOT_PRODUCT(lhs%EJ,rhs%EJJ) + DOT_PRODUCT(lhs%EJJ,rhs%EJ)
      res%EKKK = DOT_PRODUCT(lhs%R,rhs%EKKK) + DOT_PRODUCT(lhs%EKKK,rhs%R) +  &
              DOT_PRODUCT(lhs%EK,rhs%EKK) + DOT_PRODUCT(lhs%EKK,rhs%EK)
      res%ELLL = DOT_PRODUCT(lhs%R,rhs%ELLL) + DOT_PRODUCT(lhs%ELLL,rhs%R) +  &
              DOT_PRODUCT(lhs%EL,rhs%ELL) + DOT_PRODUCT(lhs%ELL,rhs%EL)
      res%EMMM = DOT_PRODUCT(lhs%R,rhs%EMMM) + DOT_PRODUCT(lhs%EMMM,rhs%R) +  &
              DOT_PRODUCT(lhs%EM,rhs%EMM) + DOT_PRODUCT(lhs%EMM,rhs%EM)
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

   END FUNCTION DONUMM22N5_DOT_PRODUCT_DONUMM22N5

   FUNCTION R_DOT_PRODUCT_DONUMM22N5(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(DONUMM22N5), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(DONUMM22N5) :: RES

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

      ! Order 3
      res%E111 = DOT_PRODUCT(lhs,rhs%E111)
      res%E222 = DOT_PRODUCT(lhs,rhs%E222)
      res%E333 = DOT_PRODUCT(lhs,rhs%E333)
      res%E444 = DOT_PRODUCT(lhs,rhs%E444)
      res%E555 = DOT_PRODUCT(lhs,rhs%E555)
      res%E666 = DOT_PRODUCT(lhs,rhs%E666)
      res%E777 = DOT_PRODUCT(lhs,rhs%E777)
      res%E888 = DOT_PRODUCT(lhs,rhs%E888)
      res%E999 = DOT_PRODUCT(lhs,rhs%E999)
      res%EAAA = DOT_PRODUCT(lhs,rhs%EAAA)
      res%EBBB = DOT_PRODUCT(lhs,rhs%EBBB)
      res%ECCC = DOT_PRODUCT(lhs,rhs%ECCC)
      res%EDDD = DOT_PRODUCT(lhs,rhs%EDDD)
      res%EEEE = DOT_PRODUCT(lhs,rhs%EEEE)
      res%EFFF = DOT_PRODUCT(lhs,rhs%EFFF)
      res%EGGG = DOT_PRODUCT(lhs,rhs%EGGG)
      res%EHHH = DOT_PRODUCT(lhs,rhs%EHHH)
      res%EIII = DOT_PRODUCT(lhs,rhs%EIII)
      res%EJJJ = DOT_PRODUCT(lhs,rhs%EJJJ)
      res%EKKK = DOT_PRODUCT(lhs,rhs%EKKK)
      res%ELLL = DOT_PRODUCT(lhs,rhs%ELLL)
      res%EMMM = DOT_PRODUCT(lhs,rhs%EMMM)

      ! Order 4
      res%E1111 = DOT_PRODUCT(lhs,rhs%E1111)
      res%E2222 = DOT_PRODUCT(lhs,rhs%E2222)
      res%E3333 = DOT_PRODUCT(lhs,rhs%E3333)
      res%E4444 = DOT_PRODUCT(lhs,rhs%E4444)
      res%E5555 = DOT_PRODUCT(lhs,rhs%E5555)
      res%E6666 = DOT_PRODUCT(lhs,rhs%E6666)
      res%E7777 = DOT_PRODUCT(lhs,rhs%E7777)
      res%E8888 = DOT_PRODUCT(lhs,rhs%E8888)
      res%E9999 = DOT_PRODUCT(lhs,rhs%E9999)
      res%EAAAA = DOT_PRODUCT(lhs,rhs%EAAAA)
      res%EBBBB = DOT_PRODUCT(lhs,rhs%EBBBB)
      res%ECCCC = DOT_PRODUCT(lhs,rhs%ECCCC)
      res%EDDDD = DOT_PRODUCT(lhs,rhs%EDDDD)
      res%EEEEE = DOT_PRODUCT(lhs,rhs%EEEEE)
      res%EFFFF = DOT_PRODUCT(lhs,rhs%EFFFF)
      res%EGGGG = DOT_PRODUCT(lhs,rhs%EGGGG)
      res%EHHHH = DOT_PRODUCT(lhs,rhs%EHHHH)
      res%EIIII = DOT_PRODUCT(lhs,rhs%EIIII)
      res%EJJJJ = DOT_PRODUCT(lhs,rhs%EJJJJ)
      res%EKKKK = DOT_PRODUCT(lhs,rhs%EKKKK)
      res%ELLLL = DOT_PRODUCT(lhs,rhs%ELLLL)
      res%EMMMM = DOT_PRODUCT(lhs,rhs%EMMMM)

      ! Order 5
      res%E11111 = DOT_PRODUCT(lhs,rhs%E11111)
      res%E22222 = DOT_PRODUCT(lhs,rhs%E22222)
      res%E33333 = DOT_PRODUCT(lhs,rhs%E33333)
      res%E44444 = DOT_PRODUCT(lhs,rhs%E44444)
      res%E55555 = DOT_PRODUCT(lhs,rhs%E55555)
      res%E66666 = DOT_PRODUCT(lhs,rhs%E66666)
      res%E77777 = DOT_PRODUCT(lhs,rhs%E77777)
      res%E88888 = DOT_PRODUCT(lhs,rhs%E88888)
      res%E99999 = DOT_PRODUCT(lhs,rhs%E99999)
      res%EAAAAA = DOT_PRODUCT(lhs,rhs%EAAAAA)
      res%EBBBBB = DOT_PRODUCT(lhs,rhs%EBBBBB)
      res%ECCCCC = DOT_PRODUCT(lhs,rhs%ECCCCC)
      res%EDDDDD = DOT_PRODUCT(lhs,rhs%EDDDDD)
      res%EEEEEE = DOT_PRODUCT(lhs,rhs%EEEEEE)
      res%EFFFFF = DOT_PRODUCT(lhs,rhs%EFFFFF)
      res%EGGGGG = DOT_PRODUCT(lhs,rhs%EGGGGG)
      res%EHHHHH = DOT_PRODUCT(lhs,rhs%EHHHHH)
      res%EIIIII = DOT_PRODUCT(lhs,rhs%EIIIII)
      res%EJJJJJ = DOT_PRODUCT(lhs,rhs%EJJJJJ)
      res%EKKKKK = DOT_PRODUCT(lhs,rhs%EKKKKK)
      res%ELLLLL = DOT_PRODUCT(lhs,rhs%ELLLLL)
      res%EMMMMM = DOT_PRODUCT(lhs,rhs%EMMMMM)

   END FUNCTION R_DOT_PRODUCT_DONUMM22N5

   FUNCTION DONUMM22N5_DOT_PRODUCT_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(DONUMM22N5) :: RES

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

      ! Order 3
      res%E111 = DOT_PRODUCT(lhs%E111,rhs)
      res%E222 = DOT_PRODUCT(lhs%E222,rhs)
      res%E333 = DOT_PRODUCT(lhs%E333,rhs)
      res%E444 = DOT_PRODUCT(lhs%E444,rhs)
      res%E555 = DOT_PRODUCT(lhs%E555,rhs)
      res%E666 = DOT_PRODUCT(lhs%E666,rhs)
      res%E777 = DOT_PRODUCT(lhs%E777,rhs)
      res%E888 = DOT_PRODUCT(lhs%E888,rhs)
      res%E999 = DOT_PRODUCT(lhs%E999,rhs)
      res%EAAA = DOT_PRODUCT(lhs%EAAA,rhs)
      res%EBBB = DOT_PRODUCT(lhs%EBBB,rhs)
      res%ECCC = DOT_PRODUCT(lhs%ECCC,rhs)
      res%EDDD = DOT_PRODUCT(lhs%EDDD,rhs)
      res%EEEE = DOT_PRODUCT(lhs%EEEE,rhs)
      res%EFFF = DOT_PRODUCT(lhs%EFFF,rhs)
      res%EGGG = DOT_PRODUCT(lhs%EGGG,rhs)
      res%EHHH = DOT_PRODUCT(lhs%EHHH,rhs)
      res%EIII = DOT_PRODUCT(lhs%EIII,rhs)
      res%EJJJ = DOT_PRODUCT(lhs%EJJJ,rhs)
      res%EKKK = DOT_PRODUCT(lhs%EKKK,rhs)
      res%ELLL = DOT_PRODUCT(lhs%ELLL,rhs)
      res%EMMM = DOT_PRODUCT(lhs%EMMM,rhs)

      ! Order 4
      res%E1111 = DOT_PRODUCT(lhs%E1111,rhs)
      res%E2222 = DOT_PRODUCT(lhs%E2222,rhs)
      res%E3333 = DOT_PRODUCT(lhs%E3333,rhs)
      res%E4444 = DOT_PRODUCT(lhs%E4444,rhs)
      res%E5555 = DOT_PRODUCT(lhs%E5555,rhs)
      res%E6666 = DOT_PRODUCT(lhs%E6666,rhs)
      res%E7777 = DOT_PRODUCT(lhs%E7777,rhs)
      res%E8888 = DOT_PRODUCT(lhs%E8888,rhs)
      res%E9999 = DOT_PRODUCT(lhs%E9999,rhs)
      res%EAAAA = DOT_PRODUCT(lhs%EAAAA,rhs)
      res%EBBBB = DOT_PRODUCT(lhs%EBBBB,rhs)
      res%ECCCC = DOT_PRODUCT(lhs%ECCCC,rhs)
      res%EDDDD = DOT_PRODUCT(lhs%EDDDD,rhs)
      res%EEEEE = DOT_PRODUCT(lhs%EEEEE,rhs)
      res%EFFFF = DOT_PRODUCT(lhs%EFFFF,rhs)
      res%EGGGG = DOT_PRODUCT(lhs%EGGGG,rhs)
      res%EHHHH = DOT_PRODUCT(lhs%EHHHH,rhs)
      res%EIIII = DOT_PRODUCT(lhs%EIIII,rhs)
      res%EJJJJ = DOT_PRODUCT(lhs%EJJJJ,rhs)
      res%EKKKK = DOT_PRODUCT(lhs%EKKKK,rhs)
      res%ELLLL = DOT_PRODUCT(lhs%ELLLL,rhs)
      res%EMMMM = DOT_PRODUCT(lhs%EMMMM,rhs)

      ! Order 5
      res%E11111 = DOT_PRODUCT(lhs%E11111,rhs)
      res%E22222 = DOT_PRODUCT(lhs%E22222,rhs)
      res%E33333 = DOT_PRODUCT(lhs%E33333,rhs)
      res%E44444 = DOT_PRODUCT(lhs%E44444,rhs)
      res%E55555 = DOT_PRODUCT(lhs%E55555,rhs)
      res%E66666 = DOT_PRODUCT(lhs%E66666,rhs)
      res%E77777 = DOT_PRODUCT(lhs%E77777,rhs)
      res%E88888 = DOT_PRODUCT(lhs%E88888,rhs)
      res%E99999 = DOT_PRODUCT(lhs%E99999,rhs)
      res%EAAAAA = DOT_PRODUCT(lhs%EAAAAA,rhs)
      res%EBBBBB = DOT_PRODUCT(lhs%EBBBBB,rhs)
      res%ECCCCC = DOT_PRODUCT(lhs%ECCCCC,rhs)
      res%EDDDDD = DOT_PRODUCT(lhs%EDDDDD,rhs)
      res%EEEEEE = DOT_PRODUCT(lhs%EEEEEE,rhs)
      res%EFFFFF = DOT_PRODUCT(lhs%EFFFFF,rhs)
      res%EGGGGG = DOT_PRODUCT(lhs%EGGGGG,rhs)
      res%EHHHHH = DOT_PRODUCT(lhs%EHHHHH,rhs)
      res%EIIIII = DOT_PRODUCT(lhs%EIIIII,rhs)
      res%EJJJJJ = DOT_PRODUCT(lhs%EJJJJJ,rhs)
      res%EKKKKK = DOT_PRODUCT(lhs%EKKKKK,rhs)
      res%ELLLLL = DOT_PRODUCT(lhs%ELLLLL,rhs)
      res%EMMMMM = DOT_PRODUCT(lhs%EMMMMM,rhs)

   END FUNCTION DONUMM22N5_DOT_PRODUCT_R

   FUNCTION DONUMM22N5_TRANSPOSE(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM22N5) :: RES (SIZE(LHS,2),SIZE(LHS,1))

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
      ! Order 3
      RES%E111 = TRANSPOSE(LHS%E111)
      RES%E222 = TRANSPOSE(LHS%E222)
      RES%E333 = TRANSPOSE(LHS%E333)
      RES%E444 = TRANSPOSE(LHS%E444)
      RES%E555 = TRANSPOSE(LHS%E555)
      RES%E666 = TRANSPOSE(LHS%E666)
      RES%E777 = TRANSPOSE(LHS%E777)
      RES%E888 = TRANSPOSE(LHS%E888)
      RES%E999 = TRANSPOSE(LHS%E999)
      RES%EAAA = TRANSPOSE(LHS%EAAA)
      RES%EBBB = TRANSPOSE(LHS%EBBB)
      RES%ECCC = TRANSPOSE(LHS%ECCC)
      RES%EDDD = TRANSPOSE(LHS%EDDD)
      RES%EEEE = TRANSPOSE(LHS%EEEE)
      RES%EFFF = TRANSPOSE(LHS%EFFF)
      RES%EGGG = TRANSPOSE(LHS%EGGG)
      RES%EHHH = TRANSPOSE(LHS%EHHH)
      RES%EIII = TRANSPOSE(LHS%EIII)
      RES%EJJJ = TRANSPOSE(LHS%EJJJ)
      RES%EKKK = TRANSPOSE(LHS%EKKK)
      RES%ELLL = TRANSPOSE(LHS%ELLL)
      RES%EMMM = TRANSPOSE(LHS%EMMM)
      ! Order 4
      RES%E1111 = TRANSPOSE(LHS%E1111)
      RES%E2222 = TRANSPOSE(LHS%E2222)
      RES%E3333 = TRANSPOSE(LHS%E3333)
      RES%E4444 = TRANSPOSE(LHS%E4444)
      RES%E5555 = TRANSPOSE(LHS%E5555)
      RES%E6666 = TRANSPOSE(LHS%E6666)
      RES%E7777 = TRANSPOSE(LHS%E7777)
      RES%E8888 = TRANSPOSE(LHS%E8888)
      RES%E9999 = TRANSPOSE(LHS%E9999)
      RES%EAAAA = TRANSPOSE(LHS%EAAAA)
      RES%EBBBB = TRANSPOSE(LHS%EBBBB)
      RES%ECCCC = TRANSPOSE(LHS%ECCCC)
      RES%EDDDD = TRANSPOSE(LHS%EDDDD)
      RES%EEEEE = TRANSPOSE(LHS%EEEEE)
      RES%EFFFF = TRANSPOSE(LHS%EFFFF)
      RES%EGGGG = TRANSPOSE(LHS%EGGGG)
      RES%EHHHH = TRANSPOSE(LHS%EHHHH)
      RES%EIIII = TRANSPOSE(LHS%EIIII)
      RES%EJJJJ = TRANSPOSE(LHS%EJJJJ)
      RES%EKKKK = TRANSPOSE(LHS%EKKKK)
      RES%ELLLL = TRANSPOSE(LHS%ELLLL)
      RES%EMMMM = TRANSPOSE(LHS%EMMMM)
      ! Order 5
      RES%E11111 = TRANSPOSE(LHS%E11111)
      RES%E22222 = TRANSPOSE(LHS%E22222)
      RES%E33333 = TRANSPOSE(LHS%E33333)
      RES%E44444 = TRANSPOSE(LHS%E44444)
      RES%E55555 = TRANSPOSE(LHS%E55555)
      RES%E66666 = TRANSPOSE(LHS%E66666)
      RES%E77777 = TRANSPOSE(LHS%E77777)
      RES%E88888 = TRANSPOSE(LHS%E88888)
      RES%E99999 = TRANSPOSE(LHS%E99999)
      RES%EAAAAA = TRANSPOSE(LHS%EAAAAA)
      RES%EBBBBB = TRANSPOSE(LHS%EBBBBB)
      RES%ECCCCC = TRANSPOSE(LHS%ECCCCC)
      RES%EDDDDD = TRANSPOSE(LHS%EDDDDD)
      RES%EEEEEE = TRANSPOSE(LHS%EEEEEE)
      RES%EFFFFF = TRANSPOSE(LHS%EFFFFF)
      RES%EGGGGG = TRANSPOSE(LHS%EGGGGG)
      RES%EHHHHH = TRANSPOSE(LHS%EHHHHH)
      RES%EIIIII = TRANSPOSE(LHS%EIIIII)
      RES%EJJJJJ = TRANSPOSE(LHS%EJJJJJ)
      RES%EKKKKK = TRANSPOSE(LHS%EKKKKK)
      RES%ELLLLL = TRANSPOSE(LHS%ELLLLL)
      RES%EMMMMM = TRANSPOSE(LHS%EMMMMM)

   END FUNCTION DONUMM22N5_TRANSPOSE

! FUNCTION DONUMM22N5_TO_CR_MAT_S(VAL) RESULT(RES)
!       IMPLICIT NONE
!       TYPE(DONUMM22N5), INTENT(IN) :: VAL
!       REAL(DP) :: RES(NUM_IM_DIR,NUM_IM_DIR) 
!       INTEGER :: NCOLS=1, NROWS=1


!       ! R x R -> R (1, 1)
!       RES(1+NROWS*0:NROWS*1,1+NCOLS*0:NCOLS*1) = VAL%R
!       ! R x E1 -> E1 (2, 2)
!       RES(1+NROWS*1:NROWS*2,1+NCOLS*1:NCOLS*2) = VAL%R
!       ! E1 x R -> E1 (2, 1)
!       RES(1+NROWS*1:NROWS*2,1+NCOLS*0:NCOLS*1) = VAL%E1
!       ! R x E2 -> E2 (3, 3)
!       RES(1+NROWS*2:NROWS*3,1+NCOLS*2:NCOLS*3) = VAL%R
!       ! E2 x R -> E2 (3, 1)
!       RES(1+NROWS*2:NROWS*3,1+NCOLS*0:NCOLS*1) = VAL%E2
!       ! R x E3 -> E3 (4, 4)
!       RES(1+NROWS*3:NROWS*4,1+NCOLS*3:NCOLS*4) = VAL%R
!       ! E3 x R -> E3 (4, 1)
!       RES(1+NROWS*3:NROWS*4,1+NCOLS*0:NCOLS*1) = VAL%E3
!       ! R x E4 -> E4 (5, 5)
!       RES(1+NROWS*4:NROWS*5,1+NCOLS*4:NCOLS*5) = VAL%R
!       ! E4 x R -> E4 (5, 1)
!       RES(1+NROWS*4:NROWS*5,1+NCOLS*0:NCOLS*1) = VAL%E4
!       ! R x E5 -> E5 (6, 6)
!       RES(1+NROWS*5:NROWS*6,1+NCOLS*5:NCOLS*6) = VAL%R
!       ! E5 x R -> E5 (6, 1)
!       RES(1+NROWS*5:NROWS*6,1+NCOLS*0:NCOLS*1) = VAL%E5
!       ! R x E6 -> E6 (7, 7)
!       RES(1+NROWS*6:NROWS*7,1+NCOLS*6:NCOLS*7) = VAL%R
!       ! E6 x R -> E6 (7, 1)
!       RES(1+NROWS*6:NROWS*7,1+NCOLS*0:NCOLS*1) = VAL%E6
!       ! R x E7 -> E7 (8, 8)
!       RES(1+NROWS*7:NROWS*8,1+NCOLS*7:NCOLS*8) = VAL%R
!       ! E7 x R -> E7 (8, 1)
!       RES(1+NROWS*7:NROWS*8,1+NCOLS*0:NCOLS*1) = VAL%E7
!       ! R x E8 -> E8 (9, 9)
!       RES(1+NROWS*8:NROWS*9,1+NCOLS*8:NCOLS*9) = VAL%R
!       ! E8 x R -> E8 (9, 1)
!       RES(1+NROWS*8:NROWS*9,1+NCOLS*0:NCOLS*1) = VAL%E8
!       ! R x E9 -> E9 (10, 10)
!       RES(1+NROWS*9:NROWS*10,1+NCOLS*9:NCOLS*10) = VAL%R
!       ! E9 x R -> E9 (10, 1)
!       RES(1+NROWS*9:NROWS*10,1+NCOLS*0:NCOLS*1) = VAL%E9
!       ! R x EA -> EA (11, 11)
!       RES(1+NROWS*10:NROWS*11,1+NCOLS*10:NCOLS*11) = VAL%R
!       ! EA x R -> EA (11, 1)
!       RES(1+NROWS*10:NROWS*11,1+NCOLS*0:NCOLS*1) = VAL%EA
!       ! R x EB -> EB (12, 12)
!       RES(1+NROWS*11:NROWS*12,1+NCOLS*11:NCOLS*12) = VAL%R
!       ! EB x R -> EB (12, 1)
!       RES(1+NROWS*11:NROWS*12,1+NCOLS*0:NCOLS*1) = VAL%EB
!       ! R x EC -> EC (13, 13)
!       RES(1+NROWS*12:NROWS*13,1+NCOLS*12:NCOLS*13) = VAL%R
!       ! EC x R -> EC (13, 1)
!       RES(1+NROWS*12:NROWS*13,1+NCOLS*0:NCOLS*1) = VAL%EC
!       ! R x ED -> ED (14, 14)
!       RES(1+NROWS*13:NROWS*14,1+NCOLS*13:NCOLS*14) = VAL%R
!       ! ED x R -> ED (14, 1)
!       RES(1+NROWS*13:NROWS*14,1+NCOLS*0:NCOLS*1) = VAL%ED
!       ! R x EE -> EE (15, 15)
!       RES(1+NROWS*14:NROWS*15,1+NCOLS*14:NCOLS*15) = VAL%R
!       ! EE x R -> EE (15, 1)
!       RES(1+NROWS*14:NROWS*15,1+NCOLS*0:NCOLS*1) = VAL%EE
!       ! R x EF -> EF (16, 16)
!       RES(1+NROWS*15:NROWS*16,1+NCOLS*15:NCOLS*16) = VAL%R
!       ! EF x R -> EF (16, 1)
!       RES(1+NROWS*15:NROWS*16,1+NCOLS*0:NCOLS*1) = VAL%EF
!       ! R x EG -> EG (17, 17)
!       RES(1+NROWS*16:NROWS*17,1+NCOLS*16:NCOLS*17) = VAL%R
!       ! EG x R -> EG (17, 1)
!       RES(1+NROWS*16:NROWS*17,1+NCOLS*0:NCOLS*1) = VAL%EG
!       ! R x EH -> EH (18, 18)
!       RES(1+NROWS*17:NROWS*18,1+NCOLS*17:NCOLS*18) = VAL%R
!       ! EH x R -> EH (18, 1)
!       RES(1+NROWS*17:NROWS*18,1+NCOLS*0:NCOLS*1) = VAL%EH
!       ! R x EI -> EI (19, 19)
!       RES(1+NROWS*18:NROWS*19,1+NCOLS*18:NCOLS*19) = VAL%R
!       ! EI x R -> EI (19, 1)
!       RES(1+NROWS*18:NROWS*19,1+NCOLS*0:NCOLS*1) = VAL%EI
!       ! R x EJ -> EJ (20, 20)
!       RES(1+NROWS*19:NROWS*20,1+NCOLS*19:NCOLS*20) = VAL%R
!       ! EJ x R -> EJ (20, 1)
!       RES(1+NROWS*19:NROWS*20,1+NCOLS*0:NCOLS*1) = VAL%EJ
!       ! R x EK -> EK (21, 21)
!       RES(1+NROWS*20:NROWS*21,1+NCOLS*20:NCOLS*21) = VAL%R
!       ! EK x R -> EK (21, 1)
!       RES(1+NROWS*20:NROWS*21,1+NCOLS*0:NCOLS*1) = VAL%EK
!       ! R x EL -> EL (22, 22)
!       RES(1+NROWS*21:NROWS*22,1+NCOLS*21:NCOLS*22) = VAL%R
!       ! EL x R -> EL (22, 1)
!       RES(1+NROWS*21:NROWS*22,1+NCOLS*0:NCOLS*1) = VAL%EL
!       ! R x EM -> EM (23, 23)
!       RES(1+NROWS*22:NROWS*23,1+NCOLS*22:NCOLS*23) = VAL%R
!       ! EM x R -> EM (23, 1)
!       RES(1+NROWS*22:NROWS*23,1+NCOLS*0:NCOLS*1) = VAL%EM
!       ! R x E11 -> E11 (24, 24)
!       RES(1+NROWS*23:NROWS*24,1+NCOLS*23:NCOLS*24) = VAL%R
!       ! E11 x R -> E11 (24, 1)
!       RES(1+NROWS*23:NROWS*24,1+NCOLS*0:NCOLS*1) = VAL%E11
!       ! E1 x E1 -> E11 (24, 2)
!       RES(1+NROWS*23:NROWS*24,1+NCOLS*1:NCOLS*2) = VAL%E1
!       ! R x E22 -> E22 (25, 25)
!       RES(1+NROWS*24:NROWS*25,1+NCOLS*24:NCOLS*25) = VAL%R
!       ! E22 x R -> E22 (25, 1)
!       RES(1+NROWS*24:NROWS*25,1+NCOLS*0:NCOLS*1) = VAL%E22
!       ! E2 x E2 -> E22 (25, 3)
!       RES(1+NROWS*24:NROWS*25,1+NCOLS*2:NCOLS*3) = VAL%E2
!       ! R x E33 -> E33 (26, 26)
!       RES(1+NROWS*25:NROWS*26,1+NCOLS*25:NCOLS*26) = VAL%R
!       ! E33 x R -> E33 (26, 1)
!       RES(1+NROWS*25:NROWS*26,1+NCOLS*0:NCOLS*1) = VAL%E33
!       ! E3 x E3 -> E33 (26, 4)
!       RES(1+NROWS*25:NROWS*26,1+NCOLS*3:NCOLS*4) = VAL%E3
!       ! R x E44 -> E44 (27, 27)
!       RES(1+NROWS*26:NROWS*27,1+NCOLS*26:NCOLS*27) = VAL%R
!       ! E44 x R -> E44 (27, 1)
!       RES(1+NROWS*26:NROWS*27,1+NCOLS*0:NCOLS*1) = VAL%E44
!       ! E4 x E4 -> E44 (27, 5)
!       RES(1+NROWS*26:NROWS*27,1+NCOLS*4:NCOLS*5) = VAL%E4
!       ! R x E55 -> E55 (28, 28)
!       RES(1+NROWS*27:NROWS*28,1+NCOLS*27:NCOLS*28) = VAL%R
!       ! E55 x R -> E55 (28, 1)
!       RES(1+NROWS*27:NROWS*28,1+NCOLS*0:NCOLS*1) = VAL%E55
!       ! E5 x E5 -> E55 (28, 6)
!       RES(1+NROWS*27:NROWS*28,1+NCOLS*5:NCOLS*6) = VAL%E5
!       ! R x E66 -> E66 (29, 29)
!       RES(1+NROWS*28:NROWS*29,1+NCOLS*28:NCOLS*29) = VAL%R
!       ! E66 x R -> E66 (29, 1)
!       RES(1+NROWS*28:NROWS*29,1+NCOLS*0:NCOLS*1) = VAL%E66
!       ! E6 x E6 -> E66 (29, 7)
!       RES(1+NROWS*28:NROWS*29,1+NCOLS*6:NCOLS*7) = VAL%E6
!       ! R x E77 -> E77 (30, 30)
!       RES(1+NROWS*29:NROWS*30,1+NCOLS*29:NCOLS*30) = VAL%R
!       ! E77 x R -> E77 (30, 1)
!       RES(1+NROWS*29:NROWS*30,1+NCOLS*0:NCOLS*1) = VAL%E77
!       ! E7 x E7 -> E77 (30, 8)
!       RES(1+NROWS*29:NROWS*30,1+NCOLS*7:NCOLS*8) = VAL%E7
!       ! R x E88 -> E88 (31, 31)
!       RES(1+NROWS*30:NROWS*31,1+NCOLS*30:NCOLS*31) = VAL%R
!       ! E88 x R -> E88 (31, 1)
!       RES(1+NROWS*30:NROWS*31,1+NCOLS*0:NCOLS*1) = VAL%E88
!       ! E8 x E8 -> E88 (31, 9)
!       RES(1+NROWS*30:NROWS*31,1+NCOLS*8:NCOLS*9) = VAL%E8
!       ! R x E99 -> E99 (32, 32)
!       RES(1+NROWS*31:NROWS*32,1+NCOLS*31:NCOLS*32) = VAL%R
!       ! E99 x R -> E99 (32, 1)
!       RES(1+NROWS*31:NROWS*32,1+NCOLS*0:NCOLS*1) = VAL%E99
!       ! E9 x E9 -> E99 (32, 10)
!       RES(1+NROWS*31:NROWS*32,1+NCOLS*9:NCOLS*10) = VAL%E9
!       ! R x EAA -> EAA (33, 33)
!       RES(1+NROWS*32:NROWS*33,1+NCOLS*32:NCOLS*33) = VAL%R
!       ! EAA x R -> EAA (33, 1)
!       RES(1+NROWS*32:NROWS*33,1+NCOLS*0:NCOLS*1) = VAL%EAA
!       ! EA x EA -> EAA (33, 11)
!       RES(1+NROWS*32:NROWS*33,1+NCOLS*10:NCOLS*11) = VAL%EA
!       ! R x EBB -> EBB (34, 34)
!       RES(1+NROWS*33:NROWS*34,1+NCOLS*33:NCOLS*34) = VAL%R
!       ! EBB x R -> EBB (34, 1)
!       RES(1+NROWS*33:NROWS*34,1+NCOLS*0:NCOLS*1) = VAL%EBB
!       ! EB x EB -> EBB (34, 12)
!       RES(1+NROWS*33:NROWS*34,1+NCOLS*11:NCOLS*12) = VAL%EB
!       ! R x ECC -> ECC (35, 35)
!       RES(1+NROWS*34:NROWS*35,1+NCOLS*34:NCOLS*35) = VAL%R
!       ! ECC x R -> ECC (35, 1)
!       RES(1+NROWS*34:NROWS*35,1+NCOLS*0:NCOLS*1) = VAL%ECC
!       ! EC x EC -> ECC (35, 13)
!       RES(1+NROWS*34:NROWS*35,1+NCOLS*12:NCOLS*13) = VAL%EC
!       ! R x EDD -> EDD (36, 36)
!       RES(1+NROWS*35:NROWS*36,1+NCOLS*35:NCOLS*36) = VAL%R
!       ! EDD x R -> EDD (36, 1)
!       RES(1+NROWS*35:NROWS*36,1+NCOLS*0:NCOLS*1) = VAL%EDD
!       ! ED x ED -> EDD (36, 14)
!       RES(1+NROWS*35:NROWS*36,1+NCOLS*13:NCOLS*14) = VAL%ED
!       ! R x EEE -> EEE (37, 37)
!       RES(1+NROWS*36:NROWS*37,1+NCOLS*36:NCOLS*37) = VAL%R
!       ! EEE x R -> EEE (37, 1)
!       RES(1+NROWS*36:NROWS*37,1+NCOLS*0:NCOLS*1) = VAL%EEE
!       ! EE x EE -> EEE (37, 15)
!       RES(1+NROWS*36:NROWS*37,1+NCOLS*14:NCOLS*15) = VAL%EE
!       ! R x EFF -> EFF (38, 38)
!       RES(1+NROWS*37:NROWS*38,1+NCOLS*37:NCOLS*38) = VAL%R
!       ! EFF x R -> EFF (38, 1)
!       RES(1+NROWS*37:NROWS*38,1+NCOLS*0:NCOLS*1) = VAL%EFF
!       ! EF x EF -> EFF (38, 16)
!       RES(1+NROWS*37:NROWS*38,1+NCOLS*15:NCOLS*16) = VAL%EF
!       ! R x EGG -> EGG (39, 39)
!       RES(1+NROWS*38:NROWS*39,1+NCOLS*38:NCOLS*39) = VAL%R
!       ! EGG x R -> EGG (39, 1)
!       RES(1+NROWS*38:NROWS*39,1+NCOLS*0:NCOLS*1) = VAL%EGG
!       ! EG x EG -> EGG (39, 17)
!       RES(1+NROWS*38:NROWS*39,1+NCOLS*16:NCOLS*17) = VAL%EG
!       ! R x EHH -> EHH (40, 40)
!       RES(1+NROWS*39:NROWS*40,1+NCOLS*39:NCOLS*40) = VAL%R
!       ! EHH x R -> EHH (40, 1)
!       RES(1+NROWS*39:NROWS*40,1+NCOLS*0:NCOLS*1) = VAL%EHH
!       ! EH x EH -> EHH (40, 18)
!       RES(1+NROWS*39:NROWS*40,1+NCOLS*17:NCOLS*18) = VAL%EH
!       ! R x EII -> EII (41, 41)
!       RES(1+NROWS*40:NROWS*41,1+NCOLS*40:NCOLS*41) = VAL%R
!       ! EII x R -> EII (41, 1)
!       RES(1+NROWS*40:NROWS*41,1+NCOLS*0:NCOLS*1) = VAL%EII
!       ! EI x EI -> EII (41, 19)
!       RES(1+NROWS*40:NROWS*41,1+NCOLS*18:NCOLS*19) = VAL%EI
!       ! R x EJJ -> EJJ (42, 42)
!       RES(1+NROWS*41:NROWS*42,1+NCOLS*41:NCOLS*42) = VAL%R
!       ! EJJ x R -> EJJ (42, 1)
!       RES(1+NROWS*41:NROWS*42,1+NCOLS*0:NCOLS*1) = VAL%EJJ
!       ! EJ x EJ -> EJJ (42, 20)
!       RES(1+NROWS*41:NROWS*42,1+NCOLS*19:NCOLS*20) = VAL%EJ
!       ! R x EKK -> EKK (43, 43)
!       RES(1+NROWS*42:NROWS*43,1+NCOLS*42:NCOLS*43) = VAL%R
!       ! EKK x R -> EKK (43, 1)
!       RES(1+NROWS*42:NROWS*43,1+NCOLS*0:NCOLS*1) = VAL%EKK
!       ! EK x EK -> EKK (43, 21)
!       RES(1+NROWS*42:NROWS*43,1+NCOLS*20:NCOLS*21) = VAL%EK
!       ! R x ELL -> ELL (44, 44)
!       RES(1+NROWS*43:NROWS*44,1+NCOLS*43:NCOLS*44) = VAL%R
!       ! ELL x R -> ELL (44, 1)
!       RES(1+NROWS*43:NROWS*44,1+NCOLS*0:NCOLS*1) = VAL%ELL
!       ! EL x EL -> ELL (44, 22)
!       RES(1+NROWS*43:NROWS*44,1+NCOLS*21:NCOLS*22) = VAL%EL
!       ! R x EMM -> EMM (45, 45)
!       RES(1+NROWS*44:NROWS*45,1+NCOLS*44:NCOLS*45) = VAL%R
!       ! EMM x R -> EMM (45, 1)
!       RES(1+NROWS*44:NROWS*45,1+NCOLS*0:NCOLS*1) = VAL%EMM
!       ! EM x EM -> EMM (45, 23)
!       RES(1+NROWS*44:NROWS*45,1+NCOLS*22:NCOLS*23) = VAL%EM
!       ! R x E111 -> E111 (46, 46)
!       RES(1+NROWS*45:NROWS*46,1+NCOLS*45:NCOLS*46) = VAL%R
!       ! E111 x R -> E111 (46, 1)
!       RES(1+NROWS*45:NROWS*46,1+NCOLS*0:NCOLS*1) = VAL%E111
!       ! E1 x E11 -> E111 (46, 24)
!       RES(1+NROWS*45:NROWS*46,1+NCOLS*23:NCOLS*24) = VAL%E1
!       ! E11 x E1 -> E111 (46, 2)
!       RES(1+NROWS*45:NROWS*46,1+NCOLS*1:NCOLS*2) = VAL%E11
!       ! R x E222 -> E222 (47, 47)
!       RES(1+NROWS*46:NROWS*47,1+NCOLS*46:NCOLS*47) = VAL%R
!       ! E222 x R -> E222 (47, 1)
!       RES(1+NROWS*46:NROWS*47,1+NCOLS*0:NCOLS*1) = VAL%E222
!       ! E2 x E22 -> E222 (47, 25)
!       RES(1+NROWS*46:NROWS*47,1+NCOLS*24:NCOLS*25) = VAL%E2
!       ! E22 x E2 -> E222 (47, 3)
!       RES(1+NROWS*46:NROWS*47,1+NCOLS*2:NCOLS*3) = VAL%E22
!       ! R x E333 -> E333 (48, 48)
!       RES(1+NROWS*47:NROWS*48,1+NCOLS*47:NCOLS*48) = VAL%R
!       ! E333 x R -> E333 (48, 1)
!       RES(1+NROWS*47:NROWS*48,1+NCOLS*0:NCOLS*1) = VAL%E333
!       ! E3 x E33 -> E333 (48, 26)
!       RES(1+NROWS*47:NROWS*48,1+NCOLS*25:NCOLS*26) = VAL%E3
!       ! E33 x E3 -> E333 (48, 4)
!       RES(1+NROWS*47:NROWS*48,1+NCOLS*3:NCOLS*4) = VAL%E33
!       ! R x E444 -> E444 (49, 49)
!       RES(1+NROWS*48:NROWS*49,1+NCOLS*48:NCOLS*49) = VAL%R
!       ! E444 x R -> E444 (49, 1)
!       RES(1+NROWS*48:NROWS*49,1+NCOLS*0:NCOLS*1) = VAL%E444
!       ! E4 x E44 -> E444 (49, 27)
!       RES(1+NROWS*48:NROWS*49,1+NCOLS*26:NCOLS*27) = VAL%E4
!       ! E44 x E4 -> E444 (49, 5)
!       RES(1+NROWS*48:NROWS*49,1+NCOLS*4:NCOLS*5) = VAL%E44
!       ! R x E555 -> E555 (50, 50)
!       RES(1+NROWS*49:NROWS*50,1+NCOLS*49:NCOLS*50) = VAL%R
!       ! E555 x R -> E555 (50, 1)
!       RES(1+NROWS*49:NROWS*50,1+NCOLS*0:NCOLS*1) = VAL%E555
!       ! E5 x E55 -> E555 (50, 28)
!       RES(1+NROWS*49:NROWS*50,1+NCOLS*27:NCOLS*28) = VAL%E5
!       ! E55 x E5 -> E555 (50, 6)
!       RES(1+NROWS*49:NROWS*50,1+NCOLS*5:NCOLS*6) = VAL%E55
!       ! R x E666 -> E666 (51, 51)
!       RES(1+NROWS*50:NROWS*51,1+NCOLS*50:NCOLS*51) = VAL%R
!       ! E666 x R -> E666 (51, 1)
!       RES(1+NROWS*50:NROWS*51,1+NCOLS*0:NCOLS*1) = VAL%E666
!       ! E6 x E66 -> E666 (51, 29)
!       RES(1+NROWS*50:NROWS*51,1+NCOLS*28:NCOLS*29) = VAL%E6
!       ! E66 x E6 -> E666 (51, 7)
!       RES(1+NROWS*50:NROWS*51,1+NCOLS*6:NCOLS*7) = VAL%E66
!       ! R x E777 -> E777 (52, 52)
!       RES(1+NROWS*51:NROWS*52,1+NCOLS*51:NCOLS*52) = VAL%R
!       ! E777 x R -> E777 (52, 1)
!       RES(1+NROWS*51:NROWS*52,1+NCOLS*0:NCOLS*1) = VAL%E777
!       ! E7 x E77 -> E777 (52, 30)
!       RES(1+NROWS*51:NROWS*52,1+NCOLS*29:NCOLS*30) = VAL%E7
!       ! E77 x E7 -> E777 (52, 8)
!       RES(1+NROWS*51:NROWS*52,1+NCOLS*7:NCOLS*8) = VAL%E77
!       ! R x E888 -> E888 (53, 53)
!       RES(1+NROWS*52:NROWS*53,1+NCOLS*52:NCOLS*53) = VAL%R
!       ! E888 x R -> E888 (53, 1)
!       RES(1+NROWS*52:NROWS*53,1+NCOLS*0:NCOLS*1) = VAL%E888
!       ! E8 x E88 -> E888 (53, 31)
!       RES(1+NROWS*52:NROWS*53,1+NCOLS*30:NCOLS*31) = VAL%E8
!       ! E88 x E8 -> E888 (53, 9)
!       RES(1+NROWS*52:NROWS*53,1+NCOLS*8:NCOLS*9) = VAL%E88
!       ! R x E999 -> E999 (54, 54)
!       RES(1+NROWS*53:NROWS*54,1+NCOLS*53:NCOLS*54) = VAL%R
!       ! E999 x R -> E999 (54, 1)
!       RES(1+NROWS*53:NROWS*54,1+NCOLS*0:NCOLS*1) = VAL%E999
!       ! E9 x E99 -> E999 (54, 32)
!       RES(1+NROWS*53:NROWS*54,1+NCOLS*31:NCOLS*32) = VAL%E9
!       ! E99 x E9 -> E999 (54, 10)
!       RES(1+NROWS*53:NROWS*54,1+NCOLS*9:NCOLS*10) = VAL%E99
!       ! R x EAAA -> EAAA (55, 55)
!       RES(1+NROWS*54:NROWS*55,1+NCOLS*54:NCOLS*55) = VAL%R
!       ! EAAA x R -> EAAA (55, 1)
!       RES(1+NROWS*54:NROWS*55,1+NCOLS*0:NCOLS*1) = VAL%EAAA
!       ! EA x EAA -> EAAA (55, 33)
!       RES(1+NROWS*54:NROWS*55,1+NCOLS*32:NCOLS*33) = VAL%EA
!       ! EAA x EA -> EAAA (55, 11)
!       RES(1+NROWS*54:NROWS*55,1+NCOLS*10:NCOLS*11) = VAL%EAA
!       ! R x EBBB -> EBBB (56, 56)
!       RES(1+NROWS*55:NROWS*56,1+NCOLS*55:NCOLS*56) = VAL%R
!       ! EBBB x R -> EBBB (56, 1)
!       RES(1+NROWS*55:NROWS*56,1+NCOLS*0:NCOLS*1) = VAL%EBBB
!       ! EB x EBB -> EBBB (56, 34)
!       RES(1+NROWS*55:NROWS*56,1+NCOLS*33:NCOLS*34) = VAL%EB
!       ! EBB x EB -> EBBB (56, 12)
!       RES(1+NROWS*55:NROWS*56,1+NCOLS*11:NCOLS*12) = VAL%EBB
!       ! R x ECCC -> ECCC (57, 57)
!       RES(1+NROWS*56:NROWS*57,1+NCOLS*56:NCOLS*57) = VAL%R
!       ! ECCC x R -> ECCC (57, 1)
!       RES(1+NROWS*56:NROWS*57,1+NCOLS*0:NCOLS*1) = VAL%ECCC
!       ! EC x ECC -> ECCC (57, 35)
!       RES(1+NROWS*56:NROWS*57,1+NCOLS*34:NCOLS*35) = VAL%EC
!       ! ECC x EC -> ECCC (57, 13)
!       RES(1+NROWS*56:NROWS*57,1+NCOLS*12:NCOLS*13) = VAL%ECC
!       ! R x EDDD -> EDDD (58, 58)
!       RES(1+NROWS*57:NROWS*58,1+NCOLS*57:NCOLS*58) = VAL%R
!       ! EDDD x R -> EDDD (58, 1)
!       RES(1+NROWS*57:NROWS*58,1+NCOLS*0:NCOLS*1) = VAL%EDDD
!       ! ED x EDD -> EDDD (58, 36)
!       RES(1+NROWS*57:NROWS*58,1+NCOLS*35:NCOLS*36) = VAL%ED
!       ! EDD x ED -> EDDD (58, 14)
!       RES(1+NROWS*57:NROWS*58,1+NCOLS*13:NCOLS*14) = VAL%EDD
!       ! R x EEEE -> EEEE (59, 59)
!       RES(1+NROWS*58:NROWS*59,1+NCOLS*58:NCOLS*59) = VAL%R
!       ! EEEE x R -> EEEE (59, 1)
!       RES(1+NROWS*58:NROWS*59,1+NCOLS*0:NCOLS*1) = VAL%EEEE
!       ! EE x EEE -> EEEE (59, 37)
!       RES(1+NROWS*58:NROWS*59,1+NCOLS*36:NCOLS*37) = VAL%EE
!       ! EEE x EE -> EEEE (59, 15)
!       RES(1+NROWS*58:NROWS*59,1+NCOLS*14:NCOLS*15) = VAL%EEE
!       ! R x EFFF -> EFFF (60, 60)
!       RES(1+NROWS*59:NROWS*60,1+NCOLS*59:NCOLS*60) = VAL%R
!       ! EFFF x R -> EFFF (60, 1)
!       RES(1+NROWS*59:NROWS*60,1+NCOLS*0:NCOLS*1) = VAL%EFFF
!       ! EF x EFF -> EFFF (60, 38)
!       RES(1+NROWS*59:NROWS*60,1+NCOLS*37:NCOLS*38) = VAL%EF
!       ! EFF x EF -> EFFF (60, 16)
!       RES(1+NROWS*59:NROWS*60,1+NCOLS*15:NCOLS*16) = VAL%EFF
!       ! R x EGGG -> EGGG (61, 61)
!       RES(1+NROWS*60:NROWS*61,1+NCOLS*60:NCOLS*61) = VAL%R
!       ! EGGG x R -> EGGG (61, 1)
!       RES(1+NROWS*60:NROWS*61,1+NCOLS*0:NCOLS*1) = VAL%EGGG
!       ! EG x EGG -> EGGG (61, 39)
!       RES(1+NROWS*60:NROWS*61,1+NCOLS*38:NCOLS*39) = VAL%EG
!       ! EGG x EG -> EGGG (61, 17)
!       RES(1+NROWS*60:NROWS*61,1+NCOLS*16:NCOLS*17) = VAL%EGG
!       ! R x EHHH -> EHHH (62, 62)
!       RES(1+NROWS*61:NROWS*62,1+NCOLS*61:NCOLS*62) = VAL%R
!       ! EHHH x R -> EHHH (62, 1)
!       RES(1+NROWS*61:NROWS*62,1+NCOLS*0:NCOLS*1) = VAL%EHHH
!       ! EH x EHH -> EHHH (62, 40)
!       RES(1+NROWS*61:NROWS*62,1+NCOLS*39:NCOLS*40) = VAL%EH
!       ! EHH x EH -> EHHH (62, 18)
!       RES(1+NROWS*61:NROWS*62,1+NCOLS*17:NCOLS*18) = VAL%EHH
!       ! R x EIII -> EIII (63, 63)
!       RES(1+NROWS*62:NROWS*63,1+NCOLS*62:NCOLS*63) = VAL%R
!       ! EIII x R -> EIII (63, 1)
!       RES(1+NROWS*62:NROWS*63,1+NCOLS*0:NCOLS*1) = VAL%EIII
!       ! EI x EII -> EIII (63, 41)
!       RES(1+NROWS*62:NROWS*63,1+NCOLS*40:NCOLS*41) = VAL%EI
!       ! EII x EI -> EIII (63, 19)
!       RES(1+NROWS*62:NROWS*63,1+NCOLS*18:NCOLS*19) = VAL%EII
!       ! R x EJJJ -> EJJJ (64, 64)
!       RES(1+NROWS*63:NROWS*64,1+NCOLS*63:NCOLS*64) = VAL%R
!       ! EJJJ x R -> EJJJ (64, 1)
!       RES(1+NROWS*63:NROWS*64,1+NCOLS*0:NCOLS*1) = VAL%EJJJ
!       ! EJ x EJJ -> EJJJ (64, 42)
!       RES(1+NROWS*63:NROWS*64,1+NCOLS*41:NCOLS*42) = VAL%EJ
!       ! EJJ x EJ -> EJJJ (64, 20)
!       RES(1+NROWS*63:NROWS*64,1+NCOLS*19:NCOLS*20) = VAL%EJJ
!       ! R x EKKK -> EKKK (65, 65)
!       RES(1+NROWS*64:NROWS*65,1+NCOLS*64:NCOLS*65) = VAL%R
!       ! EKKK x R -> EKKK (65, 1)
!       RES(1+NROWS*64:NROWS*65,1+NCOLS*0:NCOLS*1) = VAL%EKKK
!       ! EK x EKK -> EKKK (65, 43)
!       RES(1+NROWS*64:NROWS*65,1+NCOLS*42:NCOLS*43) = VAL%EK
!       ! EKK x EK -> EKKK (65, 21)
!       RES(1+NROWS*64:NROWS*65,1+NCOLS*20:NCOLS*21) = VAL%EKK
!       ! R x ELLL -> ELLL (66, 66)
!       RES(1+NROWS*65:NROWS*66,1+NCOLS*65:NCOLS*66) = VAL%R
!       ! ELLL x R -> ELLL (66, 1)
!       RES(1+NROWS*65:NROWS*66,1+NCOLS*0:NCOLS*1) = VAL%ELLL
!       ! EL x ELL -> ELLL (66, 44)
!       RES(1+NROWS*65:NROWS*66,1+NCOLS*43:NCOLS*44) = VAL%EL
!       ! ELL x EL -> ELLL (66, 22)
!       RES(1+NROWS*65:NROWS*66,1+NCOLS*21:NCOLS*22) = VAL%ELL
!       ! R x EMMM -> EMMM (67, 67)
!       RES(1+NROWS*66:NROWS*67,1+NCOLS*66:NCOLS*67) = VAL%R
!       ! EMMM x R -> EMMM (67, 1)
!       RES(1+NROWS*66:NROWS*67,1+NCOLS*0:NCOLS*1) = VAL%EMMM
!       ! EM x EMM -> EMMM (67, 45)
!       RES(1+NROWS*66:NROWS*67,1+NCOLS*44:NCOLS*45) = VAL%EM
!       ! EMM x EM -> EMMM (67, 23)
!       RES(1+NROWS*66:NROWS*67,1+NCOLS*22:NCOLS*23) = VAL%EMM
!       ! R x E1111 -> E1111 (68, 68)
!       RES(1+NROWS*67:NROWS*68,1+NCOLS*67:NCOLS*68) = VAL%R
!       ! E1111 x R -> E1111 (68, 1)
!       RES(1+NROWS*67:NROWS*68,1+NCOLS*0:NCOLS*1) = VAL%E1111
!       ! E1 x E111 -> E1111 (68, 46)
!       RES(1+NROWS*67:NROWS*68,1+NCOLS*45:NCOLS*46) = VAL%E1
!       ! E111 x E1 -> E1111 (68, 2)
!       RES(1+NROWS*67:NROWS*68,1+NCOLS*1:NCOLS*2) = VAL%E111
!       ! E11 x E11 -> E1111 (68, 24)
!       RES(1+NROWS*67:NROWS*68,1+NCOLS*23:NCOLS*24) = VAL%E11
!       ! R x E2222 -> E2222 (69, 69)
!       RES(1+NROWS*68:NROWS*69,1+NCOLS*68:NCOLS*69) = VAL%R
!       ! E2222 x R -> E2222 (69, 1)
!       RES(1+NROWS*68:NROWS*69,1+NCOLS*0:NCOLS*1) = VAL%E2222
!       ! E2 x E222 -> E2222 (69, 47)
!       RES(1+NROWS*68:NROWS*69,1+NCOLS*46:NCOLS*47) = VAL%E2
!       ! E222 x E2 -> E2222 (69, 3)
!       RES(1+NROWS*68:NROWS*69,1+NCOLS*2:NCOLS*3) = VAL%E222
!       ! E22 x E22 -> E2222 (69, 25)
!       RES(1+NROWS*68:NROWS*69,1+NCOLS*24:NCOLS*25) = VAL%E22
!       ! R x E3333 -> E3333 (70, 70)
!       RES(1+NROWS*69:NROWS*70,1+NCOLS*69:NCOLS*70) = VAL%R
!       ! E3333 x R -> E3333 (70, 1)
!       RES(1+NROWS*69:NROWS*70,1+NCOLS*0:NCOLS*1) = VAL%E3333
!       ! E3 x E333 -> E3333 (70, 48)
!       RES(1+NROWS*69:NROWS*70,1+NCOLS*47:NCOLS*48) = VAL%E3
!       ! E333 x E3 -> E3333 (70, 4)
!       RES(1+NROWS*69:NROWS*70,1+NCOLS*3:NCOLS*4) = VAL%E333
!       ! E33 x E33 -> E3333 (70, 26)
!       RES(1+NROWS*69:NROWS*70,1+NCOLS*25:NCOLS*26) = VAL%E33
!       ! R x E4444 -> E4444 (71, 71)
!       RES(1+NROWS*70:NROWS*71,1+NCOLS*70:NCOLS*71) = VAL%R
!       ! E4444 x R -> E4444 (71, 1)
!       RES(1+NROWS*70:NROWS*71,1+NCOLS*0:NCOLS*1) = VAL%E4444
!       ! E4 x E444 -> E4444 (71, 49)
!       RES(1+NROWS*70:NROWS*71,1+NCOLS*48:NCOLS*49) = VAL%E4
!       ! E444 x E4 -> E4444 (71, 5)
!       RES(1+NROWS*70:NROWS*71,1+NCOLS*4:NCOLS*5) = VAL%E444
!       ! E44 x E44 -> E4444 (71, 27)
!       RES(1+NROWS*70:NROWS*71,1+NCOLS*26:NCOLS*27) = VAL%E44
!       ! R x E5555 -> E5555 (72, 72)
!       RES(1+NROWS*71:NROWS*72,1+NCOLS*71:NCOLS*72) = VAL%R
!       ! E5555 x R -> E5555 (72, 1)
!       RES(1+NROWS*71:NROWS*72,1+NCOLS*0:NCOLS*1) = VAL%E5555
!       ! E5 x E555 -> E5555 (72, 50)
!       RES(1+NROWS*71:NROWS*72,1+NCOLS*49:NCOLS*50) = VAL%E5
!       ! E555 x E5 -> E5555 (72, 6)
!       RES(1+NROWS*71:NROWS*72,1+NCOLS*5:NCOLS*6) = VAL%E555
!       ! E55 x E55 -> E5555 (72, 28)
!       RES(1+NROWS*71:NROWS*72,1+NCOLS*27:NCOLS*28) = VAL%E55
!       ! R x E6666 -> E6666 (73, 73)
!       RES(1+NROWS*72:NROWS*73,1+NCOLS*72:NCOLS*73) = VAL%R
!       ! E6666 x R -> E6666 (73, 1)
!       RES(1+NROWS*72:NROWS*73,1+NCOLS*0:NCOLS*1) = VAL%E6666
!       ! E6 x E666 -> E6666 (73, 51)
!       RES(1+NROWS*72:NROWS*73,1+NCOLS*50:NCOLS*51) = VAL%E6
!       ! E666 x E6 -> E6666 (73, 7)
!       RES(1+NROWS*72:NROWS*73,1+NCOLS*6:NCOLS*7) = VAL%E666
!       ! E66 x E66 -> E6666 (73, 29)
!       RES(1+NROWS*72:NROWS*73,1+NCOLS*28:NCOLS*29) = VAL%E66
!       ! R x E7777 -> E7777 (74, 74)
!       RES(1+NROWS*73:NROWS*74,1+NCOLS*73:NCOLS*74) = VAL%R
!       ! E7777 x R -> E7777 (74, 1)
!       RES(1+NROWS*73:NROWS*74,1+NCOLS*0:NCOLS*1) = VAL%E7777
!       ! E7 x E777 -> E7777 (74, 52)
!       RES(1+NROWS*73:NROWS*74,1+NCOLS*51:NCOLS*52) = VAL%E7
!       ! E777 x E7 -> E7777 (74, 8)
!       RES(1+NROWS*73:NROWS*74,1+NCOLS*7:NCOLS*8) = VAL%E777
!       ! E77 x E77 -> E7777 (74, 30)
!       RES(1+NROWS*73:NROWS*74,1+NCOLS*29:NCOLS*30) = VAL%E77
!       ! R x E8888 -> E8888 (75, 75)
!       RES(1+NROWS*74:NROWS*75,1+NCOLS*74:NCOLS*75) = VAL%R
!       ! E8888 x R -> E8888 (75, 1)
!       RES(1+NROWS*74:NROWS*75,1+NCOLS*0:NCOLS*1) = VAL%E8888
!       ! E8 x E888 -> E8888 (75, 53)
!       RES(1+NROWS*74:NROWS*75,1+NCOLS*52:NCOLS*53) = VAL%E8
!       ! E888 x E8 -> E8888 (75, 9)
!       RES(1+NROWS*74:NROWS*75,1+NCOLS*8:NCOLS*9) = VAL%E888
!       ! E88 x E88 -> E8888 (75, 31)
!       RES(1+NROWS*74:NROWS*75,1+NCOLS*30:NCOLS*31) = VAL%E88
!       ! R x E9999 -> E9999 (76, 76)
!       RES(1+NROWS*75:NROWS*76,1+NCOLS*75:NCOLS*76) = VAL%R
!       ! E9999 x R -> E9999 (76, 1)
!       RES(1+NROWS*75:NROWS*76,1+NCOLS*0:NCOLS*1) = VAL%E9999
!       ! E9 x E999 -> E9999 (76, 54)
!       RES(1+NROWS*75:NROWS*76,1+NCOLS*53:NCOLS*54) = VAL%E9
!       ! E999 x E9 -> E9999 (76, 10)
!       RES(1+NROWS*75:NROWS*76,1+NCOLS*9:NCOLS*10) = VAL%E999
!       ! E99 x E99 -> E9999 (76, 32)
!       RES(1+NROWS*75:NROWS*76,1+NCOLS*31:NCOLS*32) = VAL%E99
!       ! R x EAAAA -> EAAAA (77, 77)
!       RES(1+NROWS*76:NROWS*77,1+NCOLS*76:NCOLS*77) = VAL%R
!       ! EAAAA x R -> EAAAA (77, 1)
!       RES(1+NROWS*76:NROWS*77,1+NCOLS*0:NCOLS*1) = VAL%EAAAA
!       ! EA x EAAA -> EAAAA (77, 55)
!       RES(1+NROWS*76:NROWS*77,1+NCOLS*54:NCOLS*55) = VAL%EA
!       ! EAAA x EA -> EAAAA (77, 11)
!       RES(1+NROWS*76:NROWS*77,1+NCOLS*10:NCOLS*11) = VAL%EAAA
!       ! EAA x EAA -> EAAAA (77, 33)
!       RES(1+NROWS*76:NROWS*77,1+NCOLS*32:NCOLS*33) = VAL%EAA
!       ! R x EBBBB -> EBBBB (78, 78)
!       RES(1+NROWS*77:NROWS*78,1+NCOLS*77:NCOLS*78) = VAL%R
!       ! EBBBB x R -> EBBBB (78, 1)
!       RES(1+NROWS*77:NROWS*78,1+NCOLS*0:NCOLS*1) = VAL%EBBBB
!       ! EB x EBBB -> EBBBB (78, 56)
!       RES(1+NROWS*77:NROWS*78,1+NCOLS*55:NCOLS*56) = VAL%EB
!       ! EBBB x EB -> EBBBB (78, 12)
!       RES(1+NROWS*77:NROWS*78,1+NCOLS*11:NCOLS*12) = VAL%EBBB
!       ! EBB x EBB -> EBBBB (78, 34)
!       RES(1+NROWS*77:NROWS*78,1+NCOLS*33:NCOLS*34) = VAL%EBB
!       ! R x ECCCC -> ECCCC (79, 79)
!       RES(1+NROWS*78:NROWS*79,1+NCOLS*78:NCOLS*79) = VAL%R
!       ! ECCCC x R -> ECCCC (79, 1)
!       RES(1+NROWS*78:NROWS*79,1+NCOLS*0:NCOLS*1) = VAL%ECCCC
!       ! EC x ECCC -> ECCCC (79, 57)
!       RES(1+NROWS*78:NROWS*79,1+NCOLS*56:NCOLS*57) = VAL%EC
!       ! ECCC x EC -> ECCCC (79, 13)
!       RES(1+NROWS*78:NROWS*79,1+NCOLS*12:NCOLS*13) = VAL%ECCC
!       ! ECC x ECC -> ECCCC (79, 35)
!       RES(1+NROWS*78:NROWS*79,1+NCOLS*34:NCOLS*35) = VAL%ECC
!       ! R x EDDDD -> EDDDD (80, 80)
!       RES(1+NROWS*79:NROWS*80,1+NCOLS*79:NCOLS*80) = VAL%R
!       ! EDDDD x R -> EDDDD (80, 1)
!       RES(1+NROWS*79:NROWS*80,1+NCOLS*0:NCOLS*1) = VAL%EDDDD
!       ! ED x EDDD -> EDDDD (80, 58)
!       RES(1+NROWS*79:NROWS*80,1+NCOLS*57:NCOLS*58) = VAL%ED
!       ! EDDD x ED -> EDDDD (80, 14)
!       RES(1+NROWS*79:NROWS*80,1+NCOLS*13:NCOLS*14) = VAL%EDDD
!       ! EDD x EDD -> EDDDD (80, 36)
!       RES(1+NROWS*79:NROWS*80,1+NCOLS*35:NCOLS*36) = VAL%EDD
!       ! R x EEEEE -> EEEEE (81, 81)
!       RES(1+NROWS*80:NROWS*81,1+NCOLS*80:NCOLS*81) = VAL%R
!       ! EEEEE x R -> EEEEE (81, 1)
!       RES(1+NROWS*80:NROWS*81,1+NCOLS*0:NCOLS*1) = VAL%EEEEE
!       ! EE x EEEE -> EEEEE (81, 59)
!       RES(1+NROWS*80:NROWS*81,1+NCOLS*58:NCOLS*59) = VAL%EE
!       ! EEEE x EE -> EEEEE (81, 15)
!       RES(1+NROWS*80:NROWS*81,1+NCOLS*14:NCOLS*15) = VAL%EEEE
!       ! EEE x EEE -> EEEEE (81, 37)
!       RES(1+NROWS*80:NROWS*81,1+NCOLS*36:NCOLS*37) = VAL%EEE
!       ! R x EFFFF -> EFFFF (82, 82)
!       RES(1+NROWS*81:NROWS*82,1+NCOLS*81:NCOLS*82) = VAL%R
!       ! EFFFF x R -> EFFFF (82, 1)
!       RES(1+NROWS*81:NROWS*82,1+NCOLS*0:NCOLS*1) = VAL%EFFFF
!       ! EF x EFFF -> EFFFF (82, 60)
!       RES(1+NROWS*81:NROWS*82,1+NCOLS*59:NCOLS*60) = VAL%EF
!       ! EFFF x EF -> EFFFF (82, 16)
!       RES(1+NROWS*81:NROWS*82,1+NCOLS*15:NCOLS*16) = VAL%EFFF
!       ! EFF x EFF -> EFFFF (82, 38)
!       RES(1+NROWS*81:NROWS*82,1+NCOLS*37:NCOLS*38) = VAL%EFF
!       ! R x EGGGG -> EGGGG (83, 83)
!       RES(1+NROWS*82:NROWS*83,1+NCOLS*82:NCOLS*83) = VAL%R
!       ! EGGGG x R -> EGGGG (83, 1)
!       RES(1+NROWS*82:NROWS*83,1+NCOLS*0:NCOLS*1) = VAL%EGGGG
!       ! EG x EGGG -> EGGGG (83, 61)
!       RES(1+NROWS*82:NROWS*83,1+NCOLS*60:NCOLS*61) = VAL%EG
!       ! EGGG x EG -> EGGGG (83, 17)
!       RES(1+NROWS*82:NROWS*83,1+NCOLS*16:NCOLS*17) = VAL%EGGG
!       ! EGG x EGG -> EGGGG (83, 39)
!       RES(1+NROWS*82:NROWS*83,1+NCOLS*38:NCOLS*39) = VAL%EGG
!       ! R x EHHHH -> EHHHH (84, 84)
!       RES(1+NROWS*83:NROWS*84,1+NCOLS*83:NCOLS*84) = VAL%R
!       ! EHHHH x R -> EHHHH (84, 1)
!       RES(1+NROWS*83:NROWS*84,1+NCOLS*0:NCOLS*1) = VAL%EHHHH
!       ! EH x EHHH -> EHHHH (84, 62)
!       RES(1+NROWS*83:NROWS*84,1+NCOLS*61:NCOLS*62) = VAL%EH
!       ! EHHH x EH -> EHHHH (84, 18)
!       RES(1+NROWS*83:NROWS*84,1+NCOLS*17:NCOLS*18) = VAL%EHHH
!       ! EHH x EHH -> EHHHH (84, 40)
!       RES(1+NROWS*83:NROWS*84,1+NCOLS*39:NCOLS*40) = VAL%EHH
!       ! R x EIIII -> EIIII (85, 85)
!       RES(1+NROWS*84:NROWS*85,1+NCOLS*84:NCOLS*85) = VAL%R
!       ! EIIII x R -> EIIII (85, 1)
!       RES(1+NROWS*84:NROWS*85,1+NCOLS*0:NCOLS*1) = VAL%EIIII
!       ! EI x EIII -> EIIII (85, 63)
!       RES(1+NROWS*84:NROWS*85,1+NCOLS*62:NCOLS*63) = VAL%EI
!       ! EIII x EI -> EIIII (85, 19)
!       RES(1+NROWS*84:NROWS*85,1+NCOLS*18:NCOLS*19) = VAL%EIII
!       ! EII x EII -> EIIII (85, 41)
!       RES(1+NROWS*84:NROWS*85,1+NCOLS*40:NCOLS*41) = VAL%EII
!       ! R x EJJJJ -> EJJJJ (86, 86)
!       RES(1+NROWS*85:NROWS*86,1+NCOLS*85:NCOLS*86) = VAL%R
!       ! EJJJJ x R -> EJJJJ (86, 1)
!       RES(1+NROWS*85:NROWS*86,1+NCOLS*0:NCOLS*1) = VAL%EJJJJ
!       ! EJ x EJJJ -> EJJJJ (86, 64)
!       RES(1+NROWS*85:NROWS*86,1+NCOLS*63:NCOLS*64) = VAL%EJ
!       ! EJJJ x EJ -> EJJJJ (86, 20)
!       RES(1+NROWS*85:NROWS*86,1+NCOLS*19:NCOLS*20) = VAL%EJJJ
!       ! EJJ x EJJ -> EJJJJ (86, 42)
!       RES(1+NROWS*85:NROWS*86,1+NCOLS*41:NCOLS*42) = VAL%EJJ
!       ! R x EKKKK -> EKKKK (87, 87)
!       RES(1+NROWS*86:NROWS*87,1+NCOLS*86:NCOLS*87) = VAL%R
!       ! EKKKK x R -> EKKKK (87, 1)
!       RES(1+NROWS*86:NROWS*87,1+NCOLS*0:NCOLS*1) = VAL%EKKKK
!       ! EK x EKKK -> EKKKK (87, 65)
!       RES(1+NROWS*86:NROWS*87,1+NCOLS*64:NCOLS*65) = VAL%EK
!       ! EKKK x EK -> EKKKK (87, 21)
!       RES(1+NROWS*86:NROWS*87,1+NCOLS*20:NCOLS*21) = VAL%EKKK
!       ! EKK x EKK -> EKKKK (87, 43)
!       RES(1+NROWS*86:NROWS*87,1+NCOLS*42:NCOLS*43) = VAL%EKK
!       ! R x ELLLL -> ELLLL (88, 88)
!       RES(1+NROWS*87:NROWS*88,1+NCOLS*87:NCOLS*88) = VAL%R
!       ! ELLLL x R -> ELLLL (88, 1)
!       RES(1+NROWS*87:NROWS*88,1+NCOLS*0:NCOLS*1) = VAL%ELLLL
!       ! EL x ELLL -> ELLLL (88, 66)
!       RES(1+NROWS*87:NROWS*88,1+NCOLS*65:NCOLS*66) = VAL%EL
!       ! ELLL x EL -> ELLLL (88, 22)
!       RES(1+NROWS*87:NROWS*88,1+NCOLS*21:NCOLS*22) = VAL%ELLL
!       ! ELL x ELL -> ELLLL (88, 44)
!       RES(1+NROWS*87:NROWS*88,1+NCOLS*43:NCOLS*44) = VAL%ELL
!       ! R x EMMMM -> EMMMM (89, 89)
!       RES(1+NROWS*88:NROWS*89,1+NCOLS*88:NCOLS*89) = VAL%R
!       ! EMMMM x R -> EMMMM (89, 1)
!       RES(1+NROWS*88:NROWS*89,1+NCOLS*0:NCOLS*1) = VAL%EMMMM
!       ! EM x EMMM -> EMMMM (89, 67)
!       RES(1+NROWS*88:NROWS*89,1+NCOLS*66:NCOLS*67) = VAL%EM
!       ! EMMM x EM -> EMMMM (89, 23)
!       RES(1+NROWS*88:NROWS*89,1+NCOLS*22:NCOLS*23) = VAL%EMMM
!       ! EMM x EMM -> EMMMM (89, 45)
!       RES(1+NROWS*88:NROWS*89,1+NCOLS*44:NCOLS*45) = VAL%EMM
!       ! R x E11111 -> E11111 (90, 90)
!       RES(1+NROWS*89:NROWS*90,1+NCOLS*89:NCOLS*90) = VAL%R
!       ! E11111 x R -> E11111 (90, 1)
!       RES(1+NROWS*89:NROWS*90,1+NCOLS*0:NCOLS*1) = VAL%E11111
!       ! E1 x E1111 -> E11111 (90, 68)
!       RES(1+NROWS*89:NROWS*90,1+NCOLS*67:NCOLS*68) = VAL%E1
!       ! E1111 x E1 -> E11111 (90, 2)
!       RES(1+NROWS*89:NROWS*90,1+NCOLS*1:NCOLS*2) = VAL%E1111
!       ! E11 x E111 -> E11111 (90, 46)
!       RES(1+NROWS*89:NROWS*90,1+NCOLS*45:NCOLS*46) = VAL%E11
!       ! E111 x E11 -> E11111 (90, 24)
!       RES(1+NROWS*89:NROWS*90,1+NCOLS*23:NCOLS*24) = VAL%E111
!       ! R x E22222 -> E22222 (91, 91)
!       RES(1+NROWS*90:NROWS*91,1+NCOLS*90:NCOLS*91) = VAL%R
!       ! E22222 x R -> E22222 (91, 1)
!       RES(1+NROWS*90:NROWS*91,1+NCOLS*0:NCOLS*1) = VAL%E22222
!       ! E2 x E2222 -> E22222 (91, 69)
!       RES(1+NROWS*90:NROWS*91,1+NCOLS*68:NCOLS*69) = VAL%E2
!       ! E2222 x E2 -> E22222 (91, 3)
!       RES(1+NROWS*90:NROWS*91,1+NCOLS*2:NCOLS*3) = VAL%E2222
!       ! E22 x E222 -> E22222 (91, 47)
!       RES(1+NROWS*90:NROWS*91,1+NCOLS*46:NCOLS*47) = VAL%E22
!       ! E222 x E22 -> E22222 (91, 25)
!       RES(1+NROWS*90:NROWS*91,1+NCOLS*24:NCOLS*25) = VAL%E222
!       ! R x E33333 -> E33333 (92, 92)
!       RES(1+NROWS*91:NROWS*92,1+NCOLS*91:NCOLS*92) = VAL%R
!       ! E33333 x R -> E33333 (92, 1)
!       RES(1+NROWS*91:NROWS*92,1+NCOLS*0:NCOLS*1) = VAL%E33333
!       ! E3 x E3333 -> E33333 (92, 70)
!       RES(1+NROWS*91:NROWS*92,1+NCOLS*69:NCOLS*70) = VAL%E3
!       ! E3333 x E3 -> E33333 (92, 4)
!       RES(1+NROWS*91:NROWS*92,1+NCOLS*3:NCOLS*4) = VAL%E3333
!       ! E33 x E333 -> E33333 (92, 48)
!       RES(1+NROWS*91:NROWS*92,1+NCOLS*47:NCOLS*48) = VAL%E33
!       ! E333 x E33 -> E33333 (92, 26)
!       RES(1+NROWS*91:NROWS*92,1+NCOLS*25:NCOLS*26) = VAL%E333
!       ! R x E44444 -> E44444 (93, 93)
!       RES(1+NROWS*92:NROWS*93,1+NCOLS*92:NCOLS*93) = VAL%R
!       ! E44444 x R -> E44444 (93, 1)
!       RES(1+NROWS*92:NROWS*93,1+NCOLS*0:NCOLS*1) = VAL%E44444
!       ! E4 x E4444 -> E44444 (93, 71)
!       RES(1+NROWS*92:NROWS*93,1+NCOLS*70:NCOLS*71) = VAL%E4
!       ! E4444 x E4 -> E44444 (93, 5)
!       RES(1+NROWS*92:NROWS*93,1+NCOLS*4:NCOLS*5) = VAL%E4444
!       ! E44 x E444 -> E44444 (93, 49)
!       RES(1+NROWS*92:NROWS*93,1+NCOLS*48:NCOLS*49) = VAL%E44
!       ! E444 x E44 -> E44444 (93, 27)
!       RES(1+NROWS*92:NROWS*93,1+NCOLS*26:NCOLS*27) = VAL%E444
!       ! R x E55555 -> E55555 (94, 94)
!       RES(1+NROWS*93:NROWS*94,1+NCOLS*93:NCOLS*94) = VAL%R
!       ! E55555 x R -> E55555 (94, 1)
!       RES(1+NROWS*93:NROWS*94,1+NCOLS*0:NCOLS*1) = VAL%E55555
!       ! E5 x E5555 -> E55555 (94, 72)
!       RES(1+NROWS*93:NROWS*94,1+NCOLS*71:NCOLS*72) = VAL%E5
!       ! E5555 x E5 -> E55555 (94, 6)
!       RES(1+NROWS*93:NROWS*94,1+NCOLS*5:NCOLS*6) = VAL%E5555
!       ! E55 x E555 -> E55555 (94, 50)
!       RES(1+NROWS*93:NROWS*94,1+NCOLS*49:NCOLS*50) = VAL%E55
!       ! E555 x E55 -> E55555 (94, 28)
!       RES(1+NROWS*93:NROWS*94,1+NCOLS*27:NCOLS*28) = VAL%E555
!       ! R x E66666 -> E66666 (95, 95)
!       RES(1+NROWS*94:NROWS*95,1+NCOLS*94:NCOLS*95) = VAL%R
!       ! E66666 x R -> E66666 (95, 1)
!       RES(1+NROWS*94:NROWS*95,1+NCOLS*0:NCOLS*1) = VAL%E66666
!       ! E6 x E6666 -> E66666 (95, 73)
!       RES(1+NROWS*94:NROWS*95,1+NCOLS*72:NCOLS*73) = VAL%E6
!       ! E6666 x E6 -> E66666 (95, 7)
!       RES(1+NROWS*94:NROWS*95,1+NCOLS*6:NCOLS*7) = VAL%E6666
!       ! E66 x E666 -> E66666 (95, 51)
!       RES(1+NROWS*94:NROWS*95,1+NCOLS*50:NCOLS*51) = VAL%E66
!       ! E666 x E66 -> E66666 (95, 29)
!       RES(1+NROWS*94:NROWS*95,1+NCOLS*28:NCOLS*29) = VAL%E666
!       ! R x E77777 -> E77777 (96, 96)
!       RES(1+NROWS*95:NROWS*96,1+NCOLS*95:NCOLS*96) = VAL%R
!       ! E77777 x R -> E77777 (96, 1)
!       RES(1+NROWS*95:NROWS*96,1+NCOLS*0:NCOLS*1) = VAL%E77777
!       ! E7 x E7777 -> E77777 (96, 74)
!       RES(1+NROWS*95:NROWS*96,1+NCOLS*73:NCOLS*74) = VAL%E7
!       ! E7777 x E7 -> E77777 (96, 8)
!       RES(1+NROWS*95:NROWS*96,1+NCOLS*7:NCOLS*8) = VAL%E7777
!       ! E77 x E777 -> E77777 (96, 52)
!       RES(1+NROWS*95:NROWS*96,1+NCOLS*51:NCOLS*52) = VAL%E77
!       ! E777 x E77 -> E77777 (96, 30)
!       RES(1+NROWS*95:NROWS*96,1+NCOLS*29:NCOLS*30) = VAL%E777
!       ! R x E88888 -> E88888 (97, 97)
!       RES(1+NROWS*96:NROWS*97,1+NCOLS*96:NCOLS*97) = VAL%R
!       ! E88888 x R -> E88888 (97, 1)
!       RES(1+NROWS*96:NROWS*97,1+NCOLS*0:NCOLS*1) = VAL%E88888
!       ! E8 x E8888 -> E88888 (97, 75)
!       RES(1+NROWS*96:NROWS*97,1+NCOLS*74:NCOLS*75) = VAL%E8
!       ! E8888 x E8 -> E88888 (97, 9)
!       RES(1+NROWS*96:NROWS*97,1+NCOLS*8:NCOLS*9) = VAL%E8888
!       ! E88 x E888 -> E88888 (97, 53)
!       RES(1+NROWS*96:NROWS*97,1+NCOLS*52:NCOLS*53) = VAL%E88
!       ! E888 x E88 -> E88888 (97, 31)
!       RES(1+NROWS*96:NROWS*97,1+NCOLS*30:NCOLS*31) = VAL%E888
!       ! R x E99999 -> E99999 (98, 98)
!       RES(1+NROWS*97:NROWS*98,1+NCOLS*97:NCOLS*98) = VAL%R
!       ! E99999 x R -> E99999 (98, 1)
!       RES(1+NROWS*97:NROWS*98,1+NCOLS*0:NCOLS*1) = VAL%E99999
!       ! E9 x E9999 -> E99999 (98, 76)
!       RES(1+NROWS*97:NROWS*98,1+NCOLS*75:NCOLS*76) = VAL%E9
!       ! E9999 x E9 -> E99999 (98, 10)
!       RES(1+NROWS*97:NROWS*98,1+NCOLS*9:NCOLS*10) = VAL%E9999
!       ! E99 x E999 -> E99999 (98, 54)
!       RES(1+NROWS*97:NROWS*98,1+NCOLS*53:NCOLS*54) = VAL%E99
!       ! E999 x E99 -> E99999 (98, 32)
!       RES(1+NROWS*97:NROWS*98,1+NCOLS*31:NCOLS*32) = VAL%E999
!       ! R x EAAAAA -> EAAAAA (99, 99)
!       RES(1+NROWS*98:NROWS*99,1+NCOLS*98:NCOLS*99) = VAL%R
!       ! EAAAAA x R -> EAAAAA (99, 1)
!       RES(1+NROWS*98:NROWS*99,1+NCOLS*0:NCOLS*1) = VAL%EAAAAA
!       ! EA x EAAAA -> EAAAAA (99, 77)
!       RES(1+NROWS*98:NROWS*99,1+NCOLS*76:NCOLS*77) = VAL%EA
!       ! EAAAA x EA -> EAAAAA (99, 11)
!       RES(1+NROWS*98:NROWS*99,1+NCOLS*10:NCOLS*11) = VAL%EAAAA
!       ! EAA x EAAA -> EAAAAA (99, 55)
!       RES(1+NROWS*98:NROWS*99,1+NCOLS*54:NCOLS*55) = VAL%EAA
!       ! EAAA x EAA -> EAAAAA (99, 33)
!       RES(1+NROWS*98:NROWS*99,1+NCOLS*32:NCOLS*33) = VAL%EAAA
!       ! R x EBBBBB -> EBBBBB (100, 100)
!       RES(1+NROWS*99:NROWS*100,1+NCOLS*99:NCOLS*100) = VAL%R
!       ! EBBBBB x R -> EBBBBB (100, 1)
!       RES(1+NROWS*99:NROWS*100,1+NCOLS*0:NCOLS*1) = VAL%EBBBBB
!       ! EB x EBBBB -> EBBBBB (100, 78)
!       RES(1+NROWS*99:NROWS*100,1+NCOLS*77:NCOLS*78) = VAL%EB
!       ! EBBBB x EB -> EBBBBB (100, 12)
!       RES(1+NROWS*99:NROWS*100,1+NCOLS*11:NCOLS*12) = VAL%EBBBB
!       ! EBB x EBBB -> EBBBBB (100, 56)
!       RES(1+NROWS*99:NROWS*100,1+NCOLS*55:NCOLS*56) = VAL%EBB
!       ! EBBB x EBB -> EBBBBB (100, 34)
!       RES(1+NROWS*99:NROWS*100,1+NCOLS*33:NCOLS*34) = VAL%EBBB
!       ! R x ECCCCC -> ECCCCC (101, 101)
!       RES(1+NROWS*100:NROWS*101,1+NCOLS*100:NCOLS*101) = VAL%R
!       ! ECCCCC x R -> ECCCCC (101, 1)
!       RES(1+NROWS*100:NROWS*101,1+NCOLS*0:NCOLS*1) = VAL%ECCCCC
!       ! EC x ECCCC -> ECCCCC (101, 79)
!       RES(1+NROWS*100:NROWS*101,1+NCOLS*78:NCOLS*79) = VAL%EC
!       ! ECCCC x EC -> ECCCCC (101, 13)
!       RES(1+NROWS*100:NROWS*101,1+NCOLS*12:NCOLS*13) = VAL%ECCCC
!       ! ECC x ECCC -> ECCCCC (101, 57)
!       RES(1+NROWS*100:NROWS*101,1+NCOLS*56:NCOLS*57) = VAL%ECC
!       ! ECCC x ECC -> ECCCCC (101, 35)
!       RES(1+NROWS*100:NROWS*101,1+NCOLS*34:NCOLS*35) = VAL%ECCC
!       ! R x EDDDDD -> EDDDDD (102, 102)
!       RES(1+NROWS*101:NROWS*102,1+NCOLS*101:NCOLS*102) = VAL%R
!       ! EDDDDD x R -> EDDDDD (102, 1)
!       RES(1+NROWS*101:NROWS*102,1+NCOLS*0:NCOLS*1) = VAL%EDDDDD
!       ! ED x EDDDD -> EDDDDD (102, 80)
!       RES(1+NROWS*101:NROWS*102,1+NCOLS*79:NCOLS*80) = VAL%ED
!       ! EDDDD x ED -> EDDDDD (102, 14)
!       RES(1+NROWS*101:NROWS*102,1+NCOLS*13:NCOLS*14) = VAL%EDDDD
!       ! EDD x EDDD -> EDDDDD (102, 58)
!       RES(1+NROWS*101:NROWS*102,1+NCOLS*57:NCOLS*58) = VAL%EDD
!       ! EDDD x EDD -> EDDDDD (102, 36)
!       RES(1+NROWS*101:NROWS*102,1+NCOLS*35:NCOLS*36) = VAL%EDDD
!       ! R x EEEEEE -> EEEEEE (103, 103)
!       RES(1+NROWS*102:NROWS*103,1+NCOLS*102:NCOLS*103) = VAL%R
!       ! EEEEEE x R -> EEEEEE (103, 1)
!       RES(1+NROWS*102:NROWS*103,1+NCOLS*0:NCOLS*1) = VAL%EEEEEE
!       ! EE x EEEEE -> EEEEEE (103, 81)
!       RES(1+NROWS*102:NROWS*103,1+NCOLS*80:NCOLS*81) = VAL%EE
!       ! EEEEE x EE -> EEEEEE (103, 15)
!       RES(1+NROWS*102:NROWS*103,1+NCOLS*14:NCOLS*15) = VAL%EEEEE
!       ! EEE x EEEE -> EEEEEE (103, 59)
!       RES(1+NROWS*102:NROWS*103,1+NCOLS*58:NCOLS*59) = VAL%EEE
!       ! EEEE x EEE -> EEEEEE (103, 37)
!       RES(1+NROWS*102:NROWS*103,1+NCOLS*36:NCOLS*37) = VAL%EEEE
!       ! R x EFFFFF -> EFFFFF (104, 104)
!       RES(1+NROWS*103:NROWS*104,1+NCOLS*103:NCOLS*104) = VAL%R
!       ! EFFFFF x R -> EFFFFF (104, 1)
!       RES(1+NROWS*103:NROWS*104,1+NCOLS*0:NCOLS*1) = VAL%EFFFFF
!       ! EF x EFFFF -> EFFFFF (104, 82)
!       RES(1+NROWS*103:NROWS*104,1+NCOLS*81:NCOLS*82) = VAL%EF
!       ! EFFFF x EF -> EFFFFF (104, 16)
!       RES(1+NROWS*103:NROWS*104,1+NCOLS*15:NCOLS*16) = VAL%EFFFF
!       ! EFF x EFFF -> EFFFFF (104, 60)
!       RES(1+NROWS*103:NROWS*104,1+NCOLS*59:NCOLS*60) = VAL%EFF
!       ! EFFF x EFF -> EFFFFF (104, 38)
!       RES(1+NROWS*103:NROWS*104,1+NCOLS*37:NCOLS*38) = VAL%EFFF
!       ! R x EGGGGG -> EGGGGG (105, 105)
!       RES(1+NROWS*104:NROWS*105,1+NCOLS*104:NCOLS*105) = VAL%R
!       ! EGGGGG x R -> EGGGGG (105, 1)
!       RES(1+NROWS*104:NROWS*105,1+NCOLS*0:NCOLS*1) = VAL%EGGGGG
!       ! EG x EGGGG -> EGGGGG (105, 83)
!       RES(1+NROWS*104:NROWS*105,1+NCOLS*82:NCOLS*83) = VAL%EG
!       ! EGGGG x EG -> EGGGGG (105, 17)
!       RES(1+NROWS*104:NROWS*105,1+NCOLS*16:NCOLS*17) = VAL%EGGGG
!       ! EGG x EGGG -> EGGGGG (105, 61)
!       RES(1+NROWS*104:NROWS*105,1+NCOLS*60:NCOLS*61) = VAL%EGG
!       ! EGGG x EGG -> EGGGGG (105, 39)
!       RES(1+NROWS*104:NROWS*105,1+NCOLS*38:NCOLS*39) = VAL%EGGG
!       ! R x EHHHHH -> EHHHHH (106, 106)
!       RES(1+NROWS*105:NROWS*106,1+NCOLS*105:NCOLS*106) = VAL%R
!       ! EHHHHH x R -> EHHHHH (106, 1)
!       RES(1+NROWS*105:NROWS*106,1+NCOLS*0:NCOLS*1) = VAL%EHHHHH
!       ! EH x EHHHH -> EHHHHH (106, 84)
!       RES(1+NROWS*105:NROWS*106,1+NCOLS*83:NCOLS*84) = VAL%EH
!       ! EHHHH x EH -> EHHHHH (106, 18)
!       RES(1+NROWS*105:NROWS*106,1+NCOLS*17:NCOLS*18) = VAL%EHHHH
!       ! EHH x EHHH -> EHHHHH (106, 62)
!       RES(1+NROWS*105:NROWS*106,1+NCOLS*61:NCOLS*62) = VAL%EHH
!       ! EHHH x EHH -> EHHHHH (106, 40)
!       RES(1+NROWS*105:NROWS*106,1+NCOLS*39:NCOLS*40) = VAL%EHHH
!       ! R x EIIIII -> EIIIII (107, 107)
!       RES(1+NROWS*106:NROWS*107,1+NCOLS*106:NCOLS*107) = VAL%R
!       ! EIIIII x R -> EIIIII (107, 1)
!       RES(1+NROWS*106:NROWS*107,1+NCOLS*0:NCOLS*1) = VAL%EIIIII
!       ! EI x EIIII -> EIIIII (107, 85)
!       RES(1+NROWS*106:NROWS*107,1+NCOLS*84:NCOLS*85) = VAL%EI
!       ! EIIII x EI -> EIIIII (107, 19)
!       RES(1+NROWS*106:NROWS*107,1+NCOLS*18:NCOLS*19) = VAL%EIIII
!       ! EII x EIII -> EIIIII (107, 63)
!       RES(1+NROWS*106:NROWS*107,1+NCOLS*62:NCOLS*63) = VAL%EII
!       ! EIII x EII -> EIIIII (107, 41)
!       RES(1+NROWS*106:NROWS*107,1+NCOLS*40:NCOLS*41) = VAL%EIII
!       ! R x EJJJJJ -> EJJJJJ (108, 108)
!       RES(1+NROWS*107:NROWS*108,1+NCOLS*107:NCOLS*108) = VAL%R
!       ! EJJJJJ x R -> EJJJJJ (108, 1)
!       RES(1+NROWS*107:NROWS*108,1+NCOLS*0:NCOLS*1) = VAL%EJJJJJ
!       ! EJ x EJJJJ -> EJJJJJ (108, 86)
!       RES(1+NROWS*107:NROWS*108,1+NCOLS*85:NCOLS*86) = VAL%EJ
!       ! EJJJJ x EJ -> EJJJJJ (108, 20)
!       RES(1+NROWS*107:NROWS*108,1+NCOLS*19:NCOLS*20) = VAL%EJJJJ
!       ! EJJ x EJJJ -> EJJJJJ (108, 64)
!       RES(1+NROWS*107:NROWS*108,1+NCOLS*63:NCOLS*64) = VAL%EJJ
!       ! EJJJ x EJJ -> EJJJJJ (108, 42)
!       RES(1+NROWS*107:NROWS*108,1+NCOLS*41:NCOLS*42) = VAL%EJJJ
!       ! R x EKKKKK -> EKKKKK (109, 109)
!       RES(1+NROWS*108:NROWS*109,1+NCOLS*108:NCOLS*109) = VAL%R
!       ! EKKKKK x R -> EKKKKK (109, 1)
!       RES(1+NROWS*108:NROWS*109,1+NCOLS*0:NCOLS*1) = VAL%EKKKKK
!       ! EK x EKKKK -> EKKKKK (109, 87)
!       RES(1+NROWS*108:NROWS*109,1+NCOLS*86:NCOLS*87) = VAL%EK
!       ! EKKKK x EK -> EKKKKK (109, 21)
!       RES(1+NROWS*108:NROWS*109,1+NCOLS*20:NCOLS*21) = VAL%EKKKK
!       ! EKK x EKKK -> EKKKKK (109, 65)
!       RES(1+NROWS*108:NROWS*109,1+NCOLS*64:NCOLS*65) = VAL%EKK
!       ! EKKK x EKK -> EKKKKK (109, 43)
!       RES(1+NROWS*108:NROWS*109,1+NCOLS*42:NCOLS*43) = VAL%EKKK
!       ! R x ELLLLL -> ELLLLL (110, 110)
!       RES(1+NROWS*109:NROWS*110,1+NCOLS*109:NCOLS*110) = VAL%R
!       ! ELLLLL x R -> ELLLLL (110, 1)
!       RES(1+NROWS*109:NROWS*110,1+NCOLS*0:NCOLS*1) = VAL%ELLLLL
!       ! EL x ELLLL -> ELLLLL (110, 88)
!       RES(1+NROWS*109:NROWS*110,1+NCOLS*87:NCOLS*88) = VAL%EL
!       ! ELLLL x EL -> ELLLLL (110, 22)
!       RES(1+NROWS*109:NROWS*110,1+NCOLS*21:NCOLS*22) = VAL%ELLLL
!       ! ELL x ELLL -> ELLLLL (110, 66)
!       RES(1+NROWS*109:NROWS*110,1+NCOLS*65:NCOLS*66) = VAL%ELL
!       ! ELLL x ELL -> ELLLLL (110, 44)
!       RES(1+NROWS*109:NROWS*110,1+NCOLS*43:NCOLS*44) = VAL%ELLL
!       ! R x EMMMMM -> EMMMMM (111, 111)
!       RES(1+NROWS*110:NROWS*111,1+NCOLS*110:NCOLS*111) = VAL%R
!       ! EMMMMM x R -> EMMMMM (111, 1)
!       RES(1+NROWS*110:NROWS*111,1+NCOLS*0:NCOLS*1) = VAL%EMMMMM
!       ! EM x EMMMM -> EMMMMM (111, 89)
!       RES(1+NROWS*110:NROWS*111,1+NCOLS*88:NCOLS*89) = VAL%EM
!       ! EMMMM x EM -> EMMMMM (111, 23)
!       RES(1+NROWS*110:NROWS*111,1+NCOLS*22:NCOLS*23) = VAL%EMMMM
!       ! EMM x EMMM -> EMMMMM (111, 67)
!       RES(1+NROWS*110:NROWS*111,1+NCOLS*66:NCOLS*67) = VAL%EMM
!       ! EMMM x EMM -> EMMMMM (111, 45)
!       RES(1+NROWS*110:NROWS*111,1+NCOLS*44:NCOLS*45) = VAL%EMMM
!    END FUNCTION DONUMM22N5_TO_CR_MAT_S

! FUNCTION DONUMM22N5_TO_CR_MAT_V(VAL) RESULT(RES)
!       IMPLICIT NONE
!       TYPE(DONUMM22N5), INTENT(IN) :: VAL(:)
!       REAL(DP) :: RES(NUM_IM_DIR*SIZE(VAL,1),NUM_IM_DIR) 
!       INTEGER :: NCOLS=1, NROWS=1

!       NROWS = SIZE(VAL,1)

!       ! R x R -> R (1, 1)
!       RES(1+NROWS*0:NROWS*1,1) = VAL%R
!       ! R x E1 -> E1 (2, 2)
!       RES(1+NROWS*1:NROWS*2,2) = VAL%R
!       ! E1 x R -> E1 (2, 1)
!       RES(1+NROWS*1:NROWS*2,1) = VAL%E1
!       ! R x E2 -> E2 (3, 3)
!       RES(1+NROWS*2:NROWS*3,3) = VAL%R
!       ! E2 x R -> E2 (3, 1)
!       RES(1+NROWS*2:NROWS*3,1) = VAL%E2
!       ! R x E3 -> E3 (4, 4)
!       RES(1+NROWS*3:NROWS*4,4) = VAL%R
!       ! E3 x R -> E3 (4, 1)
!       RES(1+NROWS*3:NROWS*4,1) = VAL%E3
!       ! R x E4 -> E4 (5, 5)
!       RES(1+NROWS*4:NROWS*5,5) = VAL%R
!       ! E4 x R -> E4 (5, 1)
!       RES(1+NROWS*4:NROWS*5,1) = VAL%E4
!       ! R x E5 -> E5 (6, 6)
!       RES(1+NROWS*5:NROWS*6,6) = VAL%R
!       ! E5 x R -> E5 (6, 1)
!       RES(1+NROWS*5:NROWS*6,1) = VAL%E5
!       ! R x E6 -> E6 (7, 7)
!       RES(1+NROWS*6:NROWS*7,7) = VAL%R
!       ! E6 x R -> E6 (7, 1)
!       RES(1+NROWS*6:NROWS*7,1) = VAL%E6
!       ! R x E7 -> E7 (8, 8)
!       RES(1+NROWS*7:NROWS*8,8) = VAL%R
!       ! E7 x R -> E7 (8, 1)
!       RES(1+NROWS*7:NROWS*8,1) = VAL%E7
!       ! R x E8 -> E8 (9, 9)
!       RES(1+NROWS*8:NROWS*9,9) = VAL%R
!       ! E8 x R -> E8 (9, 1)
!       RES(1+NROWS*8:NROWS*9,1) = VAL%E8
!       ! R x E9 -> E9 (10, 10)
!       RES(1+NROWS*9:NROWS*10,10) = VAL%R
!       ! E9 x R -> E9 (10, 1)
!       RES(1+NROWS*9:NROWS*10,1) = VAL%E9
!       ! R x EA -> EA (11, 11)
!       RES(1+NROWS*10:NROWS*11,11) = VAL%R
!       ! EA x R -> EA (11, 1)
!       RES(1+NROWS*10:NROWS*11,1) = VAL%EA
!       ! R x EB -> EB (12, 12)
!       RES(1+NROWS*11:NROWS*12,12) = VAL%R
!       ! EB x R -> EB (12, 1)
!       RES(1+NROWS*11:NROWS*12,1) = VAL%EB
!       ! R x EC -> EC (13, 13)
!       RES(1+NROWS*12:NROWS*13,13) = VAL%R
!       ! EC x R -> EC (13, 1)
!       RES(1+NROWS*12:NROWS*13,1) = VAL%EC
!       ! R x ED -> ED (14, 14)
!       RES(1+NROWS*13:NROWS*14,14) = VAL%R
!       ! ED x R -> ED (14, 1)
!       RES(1+NROWS*13:NROWS*14,1) = VAL%ED
!       ! R x EE -> EE (15, 15)
!       RES(1+NROWS*14:NROWS*15,15) = VAL%R
!       ! EE x R -> EE (15, 1)
!       RES(1+NROWS*14:NROWS*15,1) = VAL%EE
!       ! R x EF -> EF (16, 16)
!       RES(1+NROWS*15:NROWS*16,16) = VAL%R
!       ! EF x R -> EF (16, 1)
!       RES(1+NROWS*15:NROWS*16,1) = VAL%EF
!       ! R x EG -> EG (17, 17)
!       RES(1+NROWS*16:NROWS*17,17) = VAL%R
!       ! EG x R -> EG (17, 1)
!       RES(1+NROWS*16:NROWS*17,1) = VAL%EG
!       ! R x EH -> EH (18, 18)
!       RES(1+NROWS*17:NROWS*18,18) = VAL%R
!       ! EH x R -> EH (18, 1)
!       RES(1+NROWS*17:NROWS*18,1) = VAL%EH
!       ! R x EI -> EI (19, 19)
!       RES(1+NROWS*18:NROWS*19,19) = VAL%R
!       ! EI x R -> EI (19, 1)
!       RES(1+NROWS*18:NROWS*19,1) = VAL%EI
!       ! R x EJ -> EJ (20, 20)
!       RES(1+NROWS*19:NROWS*20,20) = VAL%R
!       ! EJ x R -> EJ (20, 1)
!       RES(1+NROWS*19:NROWS*20,1) = VAL%EJ
!       ! R x EK -> EK (21, 21)
!       RES(1+NROWS*20:NROWS*21,21) = VAL%R
!       ! EK x R -> EK (21, 1)
!       RES(1+NROWS*20:NROWS*21,1) = VAL%EK
!       ! R x EL -> EL (22, 22)
!       RES(1+NROWS*21:NROWS*22,22) = VAL%R
!       ! EL x R -> EL (22, 1)
!       RES(1+NROWS*21:NROWS*22,1) = VAL%EL
!       ! R x EM -> EM (23, 23)
!       RES(1+NROWS*22:NROWS*23,23) = VAL%R
!       ! EM x R -> EM (23, 1)
!       RES(1+NROWS*22:NROWS*23,1) = VAL%EM
!       ! R x E11 -> E11 (24, 24)
!       RES(1+NROWS*23:NROWS*24,24) = VAL%R
!       ! E11 x R -> E11 (24, 1)
!       RES(1+NROWS*23:NROWS*24,1) = VAL%E11
!       ! E1 x E1 -> E11 (24, 2)
!       RES(1+NROWS*23:NROWS*24,2) = VAL%E1
!       ! R x E22 -> E22 (25, 25)
!       RES(1+NROWS*24:NROWS*25,25) = VAL%R
!       ! E22 x R -> E22 (25, 1)
!       RES(1+NROWS*24:NROWS*25,1) = VAL%E22
!       ! E2 x E2 -> E22 (25, 3)
!       RES(1+NROWS*24:NROWS*25,3) = VAL%E2
!       ! R x E33 -> E33 (26, 26)
!       RES(1+NROWS*25:NROWS*26,26) = VAL%R
!       ! E33 x R -> E33 (26, 1)
!       RES(1+NROWS*25:NROWS*26,1) = VAL%E33
!       ! E3 x E3 -> E33 (26, 4)
!       RES(1+NROWS*25:NROWS*26,4) = VAL%E3
!       ! R x E44 -> E44 (27, 27)
!       RES(1+NROWS*26:NROWS*27,27) = VAL%R
!       ! E44 x R -> E44 (27, 1)
!       RES(1+NROWS*26:NROWS*27,1) = VAL%E44
!       ! E4 x E4 -> E44 (27, 5)
!       RES(1+NROWS*26:NROWS*27,5) = VAL%E4
!       ! R x E55 -> E55 (28, 28)
!       RES(1+NROWS*27:NROWS*28,28) = VAL%R
!       ! E55 x R -> E55 (28, 1)
!       RES(1+NROWS*27:NROWS*28,1) = VAL%E55
!       ! E5 x E5 -> E55 (28, 6)
!       RES(1+NROWS*27:NROWS*28,6) = VAL%E5
!       ! R x E66 -> E66 (29, 29)
!       RES(1+NROWS*28:NROWS*29,29) = VAL%R
!       ! E66 x R -> E66 (29, 1)
!       RES(1+NROWS*28:NROWS*29,1) = VAL%E66
!       ! E6 x E6 -> E66 (29, 7)
!       RES(1+NROWS*28:NROWS*29,7) = VAL%E6
!       ! R x E77 -> E77 (30, 30)
!       RES(1+NROWS*29:NROWS*30,30) = VAL%R
!       ! E77 x R -> E77 (30, 1)
!       RES(1+NROWS*29:NROWS*30,1) = VAL%E77
!       ! E7 x E7 -> E77 (30, 8)
!       RES(1+NROWS*29:NROWS*30,8) = VAL%E7
!       ! R x E88 -> E88 (31, 31)
!       RES(1+NROWS*30:NROWS*31,31) = VAL%R
!       ! E88 x R -> E88 (31, 1)
!       RES(1+NROWS*30:NROWS*31,1) = VAL%E88
!       ! E8 x E8 -> E88 (31, 9)
!       RES(1+NROWS*30:NROWS*31,9) = VAL%E8
!       ! R x E99 -> E99 (32, 32)
!       RES(1+NROWS*31:NROWS*32,32) = VAL%R
!       ! E99 x R -> E99 (32, 1)
!       RES(1+NROWS*31:NROWS*32,1) = VAL%E99
!       ! E9 x E9 -> E99 (32, 10)
!       RES(1+NROWS*31:NROWS*32,10) = VAL%E9
!       ! R x EAA -> EAA (33, 33)
!       RES(1+NROWS*32:NROWS*33,33) = VAL%R
!       ! EAA x R -> EAA (33, 1)
!       RES(1+NROWS*32:NROWS*33,1) = VAL%EAA
!       ! EA x EA -> EAA (33, 11)
!       RES(1+NROWS*32:NROWS*33,11) = VAL%EA
!       ! R x EBB -> EBB (34, 34)
!       RES(1+NROWS*33:NROWS*34,34) = VAL%R
!       ! EBB x R -> EBB (34, 1)
!       RES(1+NROWS*33:NROWS*34,1) = VAL%EBB
!       ! EB x EB -> EBB (34, 12)
!       RES(1+NROWS*33:NROWS*34,12) = VAL%EB
!       ! R x ECC -> ECC (35, 35)
!       RES(1+NROWS*34:NROWS*35,35) = VAL%R
!       ! ECC x R -> ECC (35, 1)
!       RES(1+NROWS*34:NROWS*35,1) = VAL%ECC
!       ! EC x EC -> ECC (35, 13)
!       RES(1+NROWS*34:NROWS*35,13) = VAL%EC
!       ! R x EDD -> EDD (36, 36)
!       RES(1+NROWS*35:NROWS*36,36) = VAL%R
!       ! EDD x R -> EDD (36, 1)
!       RES(1+NROWS*35:NROWS*36,1) = VAL%EDD
!       ! ED x ED -> EDD (36, 14)
!       RES(1+NROWS*35:NROWS*36,14) = VAL%ED
!       ! R x EEE -> EEE (37, 37)
!       RES(1+NROWS*36:NROWS*37,37) = VAL%R
!       ! EEE x R -> EEE (37, 1)
!       RES(1+NROWS*36:NROWS*37,1) = VAL%EEE
!       ! EE x EE -> EEE (37, 15)
!       RES(1+NROWS*36:NROWS*37,15) = VAL%EE
!       ! R x EFF -> EFF (38, 38)
!       RES(1+NROWS*37:NROWS*38,38) = VAL%R
!       ! EFF x R -> EFF (38, 1)
!       RES(1+NROWS*37:NROWS*38,1) = VAL%EFF
!       ! EF x EF -> EFF (38, 16)
!       RES(1+NROWS*37:NROWS*38,16) = VAL%EF
!       ! R x EGG -> EGG (39, 39)
!       RES(1+NROWS*38:NROWS*39,39) = VAL%R
!       ! EGG x R -> EGG (39, 1)
!       RES(1+NROWS*38:NROWS*39,1) = VAL%EGG
!       ! EG x EG -> EGG (39, 17)
!       RES(1+NROWS*38:NROWS*39,17) = VAL%EG
!       ! R x EHH -> EHH (40, 40)
!       RES(1+NROWS*39:NROWS*40,40) = VAL%R
!       ! EHH x R -> EHH (40, 1)
!       RES(1+NROWS*39:NROWS*40,1) = VAL%EHH
!       ! EH x EH -> EHH (40, 18)
!       RES(1+NROWS*39:NROWS*40,18) = VAL%EH
!       ! R x EII -> EII (41, 41)
!       RES(1+NROWS*40:NROWS*41,41) = VAL%R
!       ! EII x R -> EII (41, 1)
!       RES(1+NROWS*40:NROWS*41,1) = VAL%EII
!       ! EI x EI -> EII (41, 19)
!       RES(1+NROWS*40:NROWS*41,19) = VAL%EI
!       ! R x EJJ -> EJJ (42, 42)
!       RES(1+NROWS*41:NROWS*42,42) = VAL%R
!       ! EJJ x R -> EJJ (42, 1)
!       RES(1+NROWS*41:NROWS*42,1) = VAL%EJJ
!       ! EJ x EJ -> EJJ (42, 20)
!       RES(1+NROWS*41:NROWS*42,20) = VAL%EJ
!       ! R x EKK -> EKK (43, 43)
!       RES(1+NROWS*42:NROWS*43,43) = VAL%R
!       ! EKK x R -> EKK (43, 1)
!       RES(1+NROWS*42:NROWS*43,1) = VAL%EKK
!       ! EK x EK -> EKK (43, 21)
!       RES(1+NROWS*42:NROWS*43,21) = VAL%EK
!       ! R x ELL -> ELL (44, 44)
!       RES(1+NROWS*43:NROWS*44,44) = VAL%R
!       ! ELL x R -> ELL (44, 1)
!       RES(1+NROWS*43:NROWS*44,1) = VAL%ELL
!       ! EL x EL -> ELL (44, 22)
!       RES(1+NROWS*43:NROWS*44,22) = VAL%EL
!       ! R x EMM -> EMM (45, 45)
!       RES(1+NROWS*44:NROWS*45,45) = VAL%R
!       ! EMM x R -> EMM (45, 1)
!       RES(1+NROWS*44:NROWS*45,1) = VAL%EMM
!       ! EM x EM -> EMM (45, 23)
!       RES(1+NROWS*44:NROWS*45,23) = VAL%EM
!       ! R x E111 -> E111 (46, 46)
!       RES(1+NROWS*45:NROWS*46,46) = VAL%R
!       ! E111 x R -> E111 (46, 1)
!       RES(1+NROWS*45:NROWS*46,1) = VAL%E111
!       ! E1 x E11 -> E111 (46, 24)
!       RES(1+NROWS*45:NROWS*46,24) = VAL%E1
!       ! E11 x E1 -> E111 (46, 2)
!       RES(1+NROWS*45:NROWS*46,2) = VAL%E11
!       ! R x E222 -> E222 (47, 47)
!       RES(1+NROWS*46:NROWS*47,47) = VAL%R
!       ! E222 x R -> E222 (47, 1)
!       RES(1+NROWS*46:NROWS*47,1) = VAL%E222
!       ! E2 x E22 -> E222 (47, 25)
!       RES(1+NROWS*46:NROWS*47,25) = VAL%E2
!       ! E22 x E2 -> E222 (47, 3)
!       RES(1+NROWS*46:NROWS*47,3) = VAL%E22
!       ! R x E333 -> E333 (48, 48)
!       RES(1+NROWS*47:NROWS*48,48) = VAL%R
!       ! E333 x R -> E333 (48, 1)
!       RES(1+NROWS*47:NROWS*48,1) = VAL%E333
!       ! E3 x E33 -> E333 (48, 26)
!       RES(1+NROWS*47:NROWS*48,26) = VAL%E3
!       ! E33 x E3 -> E333 (48, 4)
!       RES(1+NROWS*47:NROWS*48,4) = VAL%E33
!       ! R x E444 -> E444 (49, 49)
!       RES(1+NROWS*48:NROWS*49,49) = VAL%R
!       ! E444 x R -> E444 (49, 1)
!       RES(1+NROWS*48:NROWS*49,1) = VAL%E444
!       ! E4 x E44 -> E444 (49, 27)
!       RES(1+NROWS*48:NROWS*49,27) = VAL%E4
!       ! E44 x E4 -> E444 (49, 5)
!       RES(1+NROWS*48:NROWS*49,5) = VAL%E44
!       ! R x E555 -> E555 (50, 50)
!       RES(1+NROWS*49:NROWS*50,50) = VAL%R
!       ! E555 x R -> E555 (50, 1)
!       RES(1+NROWS*49:NROWS*50,1) = VAL%E555
!       ! E5 x E55 -> E555 (50, 28)
!       RES(1+NROWS*49:NROWS*50,28) = VAL%E5
!       ! E55 x E5 -> E555 (50, 6)
!       RES(1+NROWS*49:NROWS*50,6) = VAL%E55
!       ! R x E666 -> E666 (51, 51)
!       RES(1+NROWS*50:NROWS*51,51) = VAL%R
!       ! E666 x R -> E666 (51, 1)
!       RES(1+NROWS*50:NROWS*51,1) = VAL%E666
!       ! E6 x E66 -> E666 (51, 29)
!       RES(1+NROWS*50:NROWS*51,29) = VAL%E6
!       ! E66 x E6 -> E666 (51, 7)
!       RES(1+NROWS*50:NROWS*51,7) = VAL%E66
!       ! R x E777 -> E777 (52, 52)
!       RES(1+NROWS*51:NROWS*52,52) = VAL%R
!       ! E777 x R -> E777 (52, 1)
!       RES(1+NROWS*51:NROWS*52,1) = VAL%E777
!       ! E7 x E77 -> E777 (52, 30)
!       RES(1+NROWS*51:NROWS*52,30) = VAL%E7
!       ! E77 x E7 -> E777 (52, 8)
!       RES(1+NROWS*51:NROWS*52,8) = VAL%E77
!       ! R x E888 -> E888 (53, 53)
!       RES(1+NROWS*52:NROWS*53,53) = VAL%R
!       ! E888 x R -> E888 (53, 1)
!       RES(1+NROWS*52:NROWS*53,1) = VAL%E888
!       ! E8 x E88 -> E888 (53, 31)
!       RES(1+NROWS*52:NROWS*53,31) = VAL%E8
!       ! E88 x E8 -> E888 (53, 9)
!       RES(1+NROWS*52:NROWS*53,9) = VAL%E88
!       ! R x E999 -> E999 (54, 54)
!       RES(1+NROWS*53:NROWS*54,54) = VAL%R
!       ! E999 x R -> E999 (54, 1)
!       RES(1+NROWS*53:NROWS*54,1) = VAL%E999
!       ! E9 x E99 -> E999 (54, 32)
!       RES(1+NROWS*53:NROWS*54,32) = VAL%E9
!       ! E99 x E9 -> E999 (54, 10)
!       RES(1+NROWS*53:NROWS*54,10) = VAL%E99
!       ! R x EAAA -> EAAA (55, 55)
!       RES(1+NROWS*54:NROWS*55,55) = VAL%R
!       ! EAAA x R -> EAAA (55, 1)
!       RES(1+NROWS*54:NROWS*55,1) = VAL%EAAA
!       ! EA x EAA -> EAAA (55, 33)
!       RES(1+NROWS*54:NROWS*55,33) = VAL%EA
!       ! EAA x EA -> EAAA (55, 11)
!       RES(1+NROWS*54:NROWS*55,11) = VAL%EAA
!       ! R x EBBB -> EBBB (56, 56)
!       RES(1+NROWS*55:NROWS*56,56) = VAL%R
!       ! EBBB x R -> EBBB (56, 1)
!       RES(1+NROWS*55:NROWS*56,1) = VAL%EBBB
!       ! EB x EBB -> EBBB (56, 34)
!       RES(1+NROWS*55:NROWS*56,34) = VAL%EB
!       ! EBB x EB -> EBBB (56, 12)
!       RES(1+NROWS*55:NROWS*56,12) = VAL%EBB
!       ! R x ECCC -> ECCC (57, 57)
!       RES(1+NROWS*56:NROWS*57,57) = VAL%R
!       ! ECCC x R -> ECCC (57, 1)
!       RES(1+NROWS*56:NROWS*57,1) = VAL%ECCC
!       ! EC x ECC -> ECCC (57, 35)
!       RES(1+NROWS*56:NROWS*57,35) = VAL%EC
!       ! ECC x EC -> ECCC (57, 13)
!       RES(1+NROWS*56:NROWS*57,13) = VAL%ECC
!       ! R x EDDD -> EDDD (58, 58)
!       RES(1+NROWS*57:NROWS*58,58) = VAL%R
!       ! EDDD x R -> EDDD (58, 1)
!       RES(1+NROWS*57:NROWS*58,1) = VAL%EDDD
!       ! ED x EDD -> EDDD (58, 36)
!       RES(1+NROWS*57:NROWS*58,36) = VAL%ED
!       ! EDD x ED -> EDDD (58, 14)
!       RES(1+NROWS*57:NROWS*58,14) = VAL%EDD
!       ! R x EEEE -> EEEE (59, 59)
!       RES(1+NROWS*58:NROWS*59,59) = VAL%R
!       ! EEEE x R -> EEEE (59, 1)
!       RES(1+NROWS*58:NROWS*59,1) = VAL%EEEE
!       ! EE x EEE -> EEEE (59, 37)
!       RES(1+NROWS*58:NROWS*59,37) = VAL%EE
!       ! EEE x EE -> EEEE (59, 15)
!       RES(1+NROWS*58:NROWS*59,15) = VAL%EEE
!       ! R x EFFF -> EFFF (60, 60)
!       RES(1+NROWS*59:NROWS*60,60) = VAL%R
!       ! EFFF x R -> EFFF (60, 1)
!       RES(1+NROWS*59:NROWS*60,1) = VAL%EFFF
!       ! EF x EFF -> EFFF (60, 38)
!       RES(1+NROWS*59:NROWS*60,38) = VAL%EF
!       ! EFF x EF -> EFFF (60, 16)
!       RES(1+NROWS*59:NROWS*60,16) = VAL%EFF
!       ! R x EGGG -> EGGG (61, 61)
!       RES(1+NROWS*60:NROWS*61,61) = VAL%R
!       ! EGGG x R -> EGGG (61, 1)
!       RES(1+NROWS*60:NROWS*61,1) = VAL%EGGG
!       ! EG x EGG -> EGGG (61, 39)
!       RES(1+NROWS*60:NROWS*61,39) = VAL%EG
!       ! EGG x EG -> EGGG (61, 17)
!       RES(1+NROWS*60:NROWS*61,17) = VAL%EGG
!       ! R x EHHH -> EHHH (62, 62)
!       RES(1+NROWS*61:NROWS*62,62) = VAL%R
!       ! EHHH x R -> EHHH (62, 1)
!       RES(1+NROWS*61:NROWS*62,1) = VAL%EHHH
!       ! EH x EHH -> EHHH (62, 40)
!       RES(1+NROWS*61:NROWS*62,40) = VAL%EH
!       ! EHH x EH -> EHHH (62, 18)
!       RES(1+NROWS*61:NROWS*62,18) = VAL%EHH
!       ! R x EIII -> EIII (63, 63)
!       RES(1+NROWS*62:NROWS*63,63) = VAL%R
!       ! EIII x R -> EIII (63, 1)
!       RES(1+NROWS*62:NROWS*63,1) = VAL%EIII
!       ! EI x EII -> EIII (63, 41)
!       RES(1+NROWS*62:NROWS*63,41) = VAL%EI
!       ! EII x EI -> EIII (63, 19)
!       RES(1+NROWS*62:NROWS*63,19) = VAL%EII
!       ! R x EJJJ -> EJJJ (64, 64)
!       RES(1+NROWS*63:NROWS*64,64) = VAL%R
!       ! EJJJ x R -> EJJJ (64, 1)
!       RES(1+NROWS*63:NROWS*64,1) = VAL%EJJJ
!       ! EJ x EJJ -> EJJJ (64, 42)
!       RES(1+NROWS*63:NROWS*64,42) = VAL%EJ
!       ! EJJ x EJ -> EJJJ (64, 20)
!       RES(1+NROWS*63:NROWS*64,20) = VAL%EJJ
!       ! R x EKKK -> EKKK (65, 65)
!       RES(1+NROWS*64:NROWS*65,65) = VAL%R
!       ! EKKK x R -> EKKK (65, 1)
!       RES(1+NROWS*64:NROWS*65,1) = VAL%EKKK
!       ! EK x EKK -> EKKK (65, 43)
!       RES(1+NROWS*64:NROWS*65,43) = VAL%EK
!       ! EKK x EK -> EKKK (65, 21)
!       RES(1+NROWS*64:NROWS*65,21) = VAL%EKK
!       ! R x ELLL -> ELLL (66, 66)
!       RES(1+NROWS*65:NROWS*66,66) = VAL%R
!       ! ELLL x R -> ELLL (66, 1)
!       RES(1+NROWS*65:NROWS*66,1) = VAL%ELLL
!       ! EL x ELL -> ELLL (66, 44)
!       RES(1+NROWS*65:NROWS*66,44) = VAL%EL
!       ! ELL x EL -> ELLL (66, 22)
!       RES(1+NROWS*65:NROWS*66,22) = VAL%ELL
!       ! R x EMMM -> EMMM (67, 67)
!       RES(1+NROWS*66:NROWS*67,67) = VAL%R
!       ! EMMM x R -> EMMM (67, 1)
!       RES(1+NROWS*66:NROWS*67,1) = VAL%EMMM
!       ! EM x EMM -> EMMM (67, 45)
!       RES(1+NROWS*66:NROWS*67,45) = VAL%EM
!       ! EMM x EM -> EMMM (67, 23)
!       RES(1+NROWS*66:NROWS*67,23) = VAL%EMM
!       ! R x E1111 -> E1111 (68, 68)
!       RES(1+NROWS*67:NROWS*68,68) = VAL%R
!       ! E1111 x R -> E1111 (68, 1)
!       RES(1+NROWS*67:NROWS*68,1) = VAL%E1111
!       ! E1 x E111 -> E1111 (68, 46)
!       RES(1+NROWS*67:NROWS*68,46) = VAL%E1
!       ! E111 x E1 -> E1111 (68, 2)
!       RES(1+NROWS*67:NROWS*68,2) = VAL%E111
!       ! E11 x E11 -> E1111 (68, 24)
!       RES(1+NROWS*67:NROWS*68,24) = VAL%E11
!       ! R x E2222 -> E2222 (69, 69)
!       RES(1+NROWS*68:NROWS*69,69) = VAL%R
!       ! E2222 x R -> E2222 (69, 1)
!       RES(1+NROWS*68:NROWS*69,1) = VAL%E2222
!       ! E2 x E222 -> E2222 (69, 47)
!       RES(1+NROWS*68:NROWS*69,47) = VAL%E2
!       ! E222 x E2 -> E2222 (69, 3)
!       RES(1+NROWS*68:NROWS*69,3) = VAL%E222
!       ! E22 x E22 -> E2222 (69, 25)
!       RES(1+NROWS*68:NROWS*69,25) = VAL%E22
!       ! R x E3333 -> E3333 (70, 70)
!       RES(1+NROWS*69:NROWS*70,70) = VAL%R
!       ! E3333 x R -> E3333 (70, 1)
!       RES(1+NROWS*69:NROWS*70,1) = VAL%E3333
!       ! E3 x E333 -> E3333 (70, 48)
!       RES(1+NROWS*69:NROWS*70,48) = VAL%E3
!       ! E333 x E3 -> E3333 (70, 4)
!       RES(1+NROWS*69:NROWS*70,4) = VAL%E333
!       ! E33 x E33 -> E3333 (70, 26)
!       RES(1+NROWS*69:NROWS*70,26) = VAL%E33
!       ! R x E4444 -> E4444 (71, 71)
!       RES(1+NROWS*70:NROWS*71,71) = VAL%R
!       ! E4444 x R -> E4444 (71, 1)
!       RES(1+NROWS*70:NROWS*71,1) = VAL%E4444
!       ! E4 x E444 -> E4444 (71, 49)
!       RES(1+NROWS*70:NROWS*71,49) = VAL%E4
!       ! E444 x E4 -> E4444 (71, 5)
!       RES(1+NROWS*70:NROWS*71,5) = VAL%E444
!       ! E44 x E44 -> E4444 (71, 27)
!       RES(1+NROWS*70:NROWS*71,27) = VAL%E44
!       ! R x E5555 -> E5555 (72, 72)
!       RES(1+NROWS*71:NROWS*72,72) = VAL%R
!       ! E5555 x R -> E5555 (72, 1)
!       RES(1+NROWS*71:NROWS*72,1) = VAL%E5555
!       ! E5 x E555 -> E5555 (72, 50)
!       RES(1+NROWS*71:NROWS*72,50) = VAL%E5
!       ! E555 x E5 -> E5555 (72, 6)
!       RES(1+NROWS*71:NROWS*72,6) = VAL%E555
!       ! E55 x E55 -> E5555 (72, 28)
!       RES(1+NROWS*71:NROWS*72,28) = VAL%E55
!       ! R x E6666 -> E6666 (73, 73)
!       RES(1+NROWS*72:NROWS*73,73) = VAL%R
!       ! E6666 x R -> E6666 (73, 1)
!       RES(1+NROWS*72:NROWS*73,1) = VAL%E6666
!       ! E6 x E666 -> E6666 (73, 51)
!       RES(1+NROWS*72:NROWS*73,51) = VAL%E6
!       ! E666 x E6 -> E6666 (73, 7)
!       RES(1+NROWS*72:NROWS*73,7) = VAL%E666
!       ! E66 x E66 -> E6666 (73, 29)
!       RES(1+NROWS*72:NROWS*73,29) = VAL%E66
!       ! R x E7777 -> E7777 (74, 74)
!       RES(1+NROWS*73:NROWS*74,74) = VAL%R
!       ! E7777 x R -> E7777 (74, 1)
!       RES(1+NROWS*73:NROWS*74,1) = VAL%E7777
!       ! E7 x E777 -> E7777 (74, 52)
!       RES(1+NROWS*73:NROWS*74,52) = VAL%E7
!       ! E777 x E7 -> E7777 (74, 8)
!       RES(1+NROWS*73:NROWS*74,8) = VAL%E777
!       ! E77 x E77 -> E7777 (74, 30)
!       RES(1+NROWS*73:NROWS*74,30) = VAL%E77
!       ! R x E8888 -> E8888 (75, 75)
!       RES(1+NROWS*74:NROWS*75,75) = VAL%R
!       ! E8888 x R -> E8888 (75, 1)
!       RES(1+NROWS*74:NROWS*75,1) = VAL%E8888
!       ! E8 x E888 -> E8888 (75, 53)
!       RES(1+NROWS*74:NROWS*75,53) = VAL%E8
!       ! E888 x E8 -> E8888 (75, 9)
!       RES(1+NROWS*74:NROWS*75,9) = VAL%E888
!       ! E88 x E88 -> E8888 (75, 31)
!       RES(1+NROWS*74:NROWS*75,31) = VAL%E88
!       ! R x E9999 -> E9999 (76, 76)
!       RES(1+NROWS*75:NROWS*76,76) = VAL%R
!       ! E9999 x R -> E9999 (76, 1)
!       RES(1+NROWS*75:NROWS*76,1) = VAL%E9999
!       ! E9 x E999 -> E9999 (76, 54)
!       RES(1+NROWS*75:NROWS*76,54) = VAL%E9
!       ! E999 x E9 -> E9999 (76, 10)
!       RES(1+NROWS*75:NROWS*76,10) = VAL%E999
!       ! E99 x E99 -> E9999 (76, 32)
!       RES(1+NROWS*75:NROWS*76,32) = VAL%E99
!       ! R x EAAAA -> EAAAA (77, 77)
!       RES(1+NROWS*76:NROWS*77,77) = VAL%R
!       ! EAAAA x R -> EAAAA (77, 1)
!       RES(1+NROWS*76:NROWS*77,1) = VAL%EAAAA
!       ! EA x EAAA -> EAAAA (77, 55)
!       RES(1+NROWS*76:NROWS*77,55) = VAL%EA
!       ! EAAA x EA -> EAAAA (77, 11)
!       RES(1+NROWS*76:NROWS*77,11) = VAL%EAAA
!       ! EAA x EAA -> EAAAA (77, 33)
!       RES(1+NROWS*76:NROWS*77,33) = VAL%EAA
!       ! R x EBBBB -> EBBBB (78, 78)
!       RES(1+NROWS*77:NROWS*78,78) = VAL%R
!       ! EBBBB x R -> EBBBB (78, 1)
!       RES(1+NROWS*77:NROWS*78,1) = VAL%EBBBB
!       ! EB x EBBB -> EBBBB (78, 56)
!       RES(1+NROWS*77:NROWS*78,56) = VAL%EB
!       ! EBBB x EB -> EBBBB (78, 12)
!       RES(1+NROWS*77:NROWS*78,12) = VAL%EBBB
!       ! EBB x EBB -> EBBBB (78, 34)
!       RES(1+NROWS*77:NROWS*78,34) = VAL%EBB
!       ! R x ECCCC -> ECCCC (79, 79)
!       RES(1+NROWS*78:NROWS*79,79) = VAL%R
!       ! ECCCC x R -> ECCCC (79, 1)
!       RES(1+NROWS*78:NROWS*79,1) = VAL%ECCCC
!       ! EC x ECCC -> ECCCC (79, 57)
!       RES(1+NROWS*78:NROWS*79,57) = VAL%EC
!       ! ECCC x EC -> ECCCC (79, 13)
!       RES(1+NROWS*78:NROWS*79,13) = VAL%ECCC
!       ! ECC x ECC -> ECCCC (79, 35)
!       RES(1+NROWS*78:NROWS*79,35) = VAL%ECC
!       ! R x EDDDD -> EDDDD (80, 80)
!       RES(1+NROWS*79:NROWS*80,80) = VAL%R
!       ! EDDDD x R -> EDDDD (80, 1)
!       RES(1+NROWS*79:NROWS*80,1) = VAL%EDDDD
!       ! ED x EDDD -> EDDDD (80, 58)
!       RES(1+NROWS*79:NROWS*80,58) = VAL%ED
!       ! EDDD x ED -> EDDDD (80, 14)
!       RES(1+NROWS*79:NROWS*80,14) = VAL%EDDD
!       ! EDD x EDD -> EDDDD (80, 36)
!       RES(1+NROWS*79:NROWS*80,36) = VAL%EDD
!       ! R x EEEEE -> EEEEE (81, 81)
!       RES(1+NROWS*80:NROWS*81,81) = VAL%R
!       ! EEEEE x R -> EEEEE (81, 1)
!       RES(1+NROWS*80:NROWS*81,1) = VAL%EEEEE
!       ! EE x EEEE -> EEEEE (81, 59)
!       RES(1+NROWS*80:NROWS*81,59) = VAL%EE
!       ! EEEE x EE -> EEEEE (81, 15)
!       RES(1+NROWS*80:NROWS*81,15) = VAL%EEEE
!       ! EEE x EEE -> EEEEE (81, 37)
!       RES(1+NROWS*80:NROWS*81,37) = VAL%EEE
!       ! R x EFFFF -> EFFFF (82, 82)
!       RES(1+NROWS*81:NROWS*82,82) = VAL%R
!       ! EFFFF x R -> EFFFF (82, 1)
!       RES(1+NROWS*81:NROWS*82,1) = VAL%EFFFF
!       ! EF x EFFF -> EFFFF (82, 60)
!       RES(1+NROWS*81:NROWS*82,60) = VAL%EF
!       ! EFFF x EF -> EFFFF (82, 16)
!       RES(1+NROWS*81:NROWS*82,16) = VAL%EFFF
!       ! EFF x EFF -> EFFFF (82, 38)
!       RES(1+NROWS*81:NROWS*82,38) = VAL%EFF
!       ! R x EGGGG -> EGGGG (83, 83)
!       RES(1+NROWS*82:NROWS*83,83) = VAL%R
!       ! EGGGG x R -> EGGGG (83, 1)
!       RES(1+NROWS*82:NROWS*83,1) = VAL%EGGGG
!       ! EG x EGGG -> EGGGG (83, 61)
!       RES(1+NROWS*82:NROWS*83,61) = VAL%EG
!       ! EGGG x EG -> EGGGG (83, 17)
!       RES(1+NROWS*82:NROWS*83,17) = VAL%EGGG
!       ! EGG x EGG -> EGGGG (83, 39)
!       RES(1+NROWS*82:NROWS*83,39) = VAL%EGG
!       ! R x EHHHH -> EHHHH (84, 84)
!       RES(1+NROWS*83:NROWS*84,84) = VAL%R
!       ! EHHHH x R -> EHHHH (84, 1)
!       RES(1+NROWS*83:NROWS*84,1) = VAL%EHHHH
!       ! EH x EHHH -> EHHHH (84, 62)
!       RES(1+NROWS*83:NROWS*84,62) = VAL%EH
!       ! EHHH x EH -> EHHHH (84, 18)
!       RES(1+NROWS*83:NROWS*84,18) = VAL%EHHH
!       ! EHH x EHH -> EHHHH (84, 40)
!       RES(1+NROWS*83:NROWS*84,40) = VAL%EHH
!       ! R x EIIII -> EIIII (85, 85)
!       RES(1+NROWS*84:NROWS*85,85) = VAL%R
!       ! EIIII x R -> EIIII (85, 1)
!       RES(1+NROWS*84:NROWS*85,1) = VAL%EIIII
!       ! EI x EIII -> EIIII (85, 63)
!       RES(1+NROWS*84:NROWS*85,63) = VAL%EI
!       ! EIII x EI -> EIIII (85, 19)
!       RES(1+NROWS*84:NROWS*85,19) = VAL%EIII
!       ! EII x EII -> EIIII (85, 41)
!       RES(1+NROWS*84:NROWS*85,41) = VAL%EII
!       ! R x EJJJJ -> EJJJJ (86, 86)
!       RES(1+NROWS*85:NROWS*86,86) = VAL%R
!       ! EJJJJ x R -> EJJJJ (86, 1)
!       RES(1+NROWS*85:NROWS*86,1) = VAL%EJJJJ
!       ! EJ x EJJJ -> EJJJJ (86, 64)
!       RES(1+NROWS*85:NROWS*86,64) = VAL%EJ
!       ! EJJJ x EJ -> EJJJJ (86, 20)
!       RES(1+NROWS*85:NROWS*86,20) = VAL%EJJJ
!       ! EJJ x EJJ -> EJJJJ (86, 42)
!       RES(1+NROWS*85:NROWS*86,42) = VAL%EJJ
!       ! R x EKKKK -> EKKKK (87, 87)
!       RES(1+NROWS*86:NROWS*87,87) = VAL%R
!       ! EKKKK x R -> EKKKK (87, 1)
!       RES(1+NROWS*86:NROWS*87,1) = VAL%EKKKK
!       ! EK x EKKK -> EKKKK (87, 65)
!       RES(1+NROWS*86:NROWS*87,65) = VAL%EK
!       ! EKKK x EK -> EKKKK (87, 21)
!       RES(1+NROWS*86:NROWS*87,21) = VAL%EKKK
!       ! EKK x EKK -> EKKKK (87, 43)
!       RES(1+NROWS*86:NROWS*87,43) = VAL%EKK
!       ! R x ELLLL -> ELLLL (88, 88)
!       RES(1+NROWS*87:NROWS*88,88) = VAL%R
!       ! ELLLL x R -> ELLLL (88, 1)
!       RES(1+NROWS*87:NROWS*88,1) = VAL%ELLLL
!       ! EL x ELLL -> ELLLL (88, 66)
!       RES(1+NROWS*87:NROWS*88,66) = VAL%EL
!       ! ELLL x EL -> ELLLL (88, 22)
!       RES(1+NROWS*87:NROWS*88,22) = VAL%ELLL
!       ! ELL x ELL -> ELLLL (88, 44)
!       RES(1+NROWS*87:NROWS*88,44) = VAL%ELL
!       ! R x EMMMM -> EMMMM (89, 89)
!       RES(1+NROWS*88:NROWS*89,89) = VAL%R
!       ! EMMMM x R -> EMMMM (89, 1)
!       RES(1+NROWS*88:NROWS*89,1) = VAL%EMMMM
!       ! EM x EMMM -> EMMMM (89, 67)
!       RES(1+NROWS*88:NROWS*89,67) = VAL%EM
!       ! EMMM x EM -> EMMMM (89, 23)
!       RES(1+NROWS*88:NROWS*89,23) = VAL%EMMM
!       ! EMM x EMM -> EMMMM (89, 45)
!       RES(1+NROWS*88:NROWS*89,45) = VAL%EMM
!       ! R x E11111 -> E11111 (90, 90)
!       RES(1+NROWS*89:NROWS*90,90) = VAL%R
!       ! E11111 x R -> E11111 (90, 1)
!       RES(1+NROWS*89:NROWS*90,1) = VAL%E11111
!       ! E1 x E1111 -> E11111 (90, 68)
!       RES(1+NROWS*89:NROWS*90,68) = VAL%E1
!       ! E1111 x E1 -> E11111 (90, 2)
!       RES(1+NROWS*89:NROWS*90,2) = VAL%E1111
!       ! E11 x E111 -> E11111 (90, 46)
!       RES(1+NROWS*89:NROWS*90,46) = VAL%E11
!       ! E111 x E11 -> E11111 (90, 24)
!       RES(1+NROWS*89:NROWS*90,24) = VAL%E111
!       ! R x E22222 -> E22222 (91, 91)
!       RES(1+NROWS*90:NROWS*91,91) = VAL%R
!       ! E22222 x R -> E22222 (91, 1)
!       RES(1+NROWS*90:NROWS*91,1) = VAL%E22222
!       ! E2 x E2222 -> E22222 (91, 69)
!       RES(1+NROWS*90:NROWS*91,69) = VAL%E2
!       ! E2222 x E2 -> E22222 (91, 3)
!       RES(1+NROWS*90:NROWS*91,3) = VAL%E2222
!       ! E22 x E222 -> E22222 (91, 47)
!       RES(1+NROWS*90:NROWS*91,47) = VAL%E22
!       ! E222 x E22 -> E22222 (91, 25)
!       RES(1+NROWS*90:NROWS*91,25) = VAL%E222
!       ! R x E33333 -> E33333 (92, 92)
!       RES(1+NROWS*91:NROWS*92,92) = VAL%R
!       ! E33333 x R -> E33333 (92, 1)
!       RES(1+NROWS*91:NROWS*92,1) = VAL%E33333
!       ! E3 x E3333 -> E33333 (92, 70)
!       RES(1+NROWS*91:NROWS*92,70) = VAL%E3
!       ! E3333 x E3 -> E33333 (92, 4)
!       RES(1+NROWS*91:NROWS*92,4) = VAL%E3333
!       ! E33 x E333 -> E33333 (92, 48)
!       RES(1+NROWS*91:NROWS*92,48) = VAL%E33
!       ! E333 x E33 -> E33333 (92, 26)
!       RES(1+NROWS*91:NROWS*92,26) = VAL%E333
!       ! R x E44444 -> E44444 (93, 93)
!       RES(1+NROWS*92:NROWS*93,93) = VAL%R
!       ! E44444 x R -> E44444 (93, 1)
!       RES(1+NROWS*92:NROWS*93,1) = VAL%E44444
!       ! E4 x E4444 -> E44444 (93, 71)
!       RES(1+NROWS*92:NROWS*93,71) = VAL%E4
!       ! E4444 x E4 -> E44444 (93, 5)
!       RES(1+NROWS*92:NROWS*93,5) = VAL%E4444
!       ! E44 x E444 -> E44444 (93, 49)
!       RES(1+NROWS*92:NROWS*93,49) = VAL%E44
!       ! E444 x E44 -> E44444 (93, 27)
!       RES(1+NROWS*92:NROWS*93,27) = VAL%E444
!       ! R x E55555 -> E55555 (94, 94)
!       RES(1+NROWS*93:NROWS*94,94) = VAL%R
!       ! E55555 x R -> E55555 (94, 1)
!       RES(1+NROWS*93:NROWS*94,1) = VAL%E55555
!       ! E5 x E5555 -> E55555 (94, 72)
!       RES(1+NROWS*93:NROWS*94,72) = VAL%E5
!       ! E5555 x E5 -> E55555 (94, 6)
!       RES(1+NROWS*93:NROWS*94,6) = VAL%E5555
!       ! E55 x E555 -> E55555 (94, 50)
!       RES(1+NROWS*93:NROWS*94,50) = VAL%E55
!       ! E555 x E55 -> E55555 (94, 28)
!       RES(1+NROWS*93:NROWS*94,28) = VAL%E555
!       ! R x E66666 -> E66666 (95, 95)
!       RES(1+NROWS*94:NROWS*95,95) = VAL%R
!       ! E66666 x R -> E66666 (95, 1)
!       RES(1+NROWS*94:NROWS*95,1) = VAL%E66666
!       ! E6 x E6666 -> E66666 (95, 73)
!       RES(1+NROWS*94:NROWS*95,73) = VAL%E6
!       ! E6666 x E6 -> E66666 (95, 7)
!       RES(1+NROWS*94:NROWS*95,7) = VAL%E6666
!       ! E66 x E666 -> E66666 (95, 51)
!       RES(1+NROWS*94:NROWS*95,51) = VAL%E66
!       ! E666 x E66 -> E66666 (95, 29)
!       RES(1+NROWS*94:NROWS*95,29) = VAL%E666
!       ! R x E77777 -> E77777 (96, 96)
!       RES(1+NROWS*95:NROWS*96,96) = VAL%R
!       ! E77777 x R -> E77777 (96, 1)
!       RES(1+NROWS*95:NROWS*96,1) = VAL%E77777
!       ! E7 x E7777 -> E77777 (96, 74)
!       RES(1+NROWS*95:NROWS*96,74) = VAL%E7
!       ! E7777 x E7 -> E77777 (96, 8)
!       RES(1+NROWS*95:NROWS*96,8) = VAL%E7777
!       ! E77 x E777 -> E77777 (96, 52)
!       RES(1+NROWS*95:NROWS*96,52) = VAL%E77
!       ! E777 x E77 -> E77777 (96, 30)
!       RES(1+NROWS*95:NROWS*96,30) = VAL%E777
!       ! R x E88888 -> E88888 (97, 97)
!       RES(1+NROWS*96:NROWS*97,97) = VAL%R
!       ! E88888 x R -> E88888 (97, 1)
!       RES(1+NROWS*96:NROWS*97,1) = VAL%E88888
!       ! E8 x E8888 -> E88888 (97, 75)
!       RES(1+NROWS*96:NROWS*97,75) = VAL%E8
!       ! E8888 x E8 -> E88888 (97, 9)
!       RES(1+NROWS*96:NROWS*97,9) = VAL%E8888
!       ! E88 x E888 -> E88888 (97, 53)
!       RES(1+NROWS*96:NROWS*97,53) = VAL%E88
!       ! E888 x E88 -> E88888 (97, 31)
!       RES(1+NROWS*96:NROWS*97,31) = VAL%E888
!       ! R x E99999 -> E99999 (98, 98)
!       RES(1+NROWS*97:NROWS*98,98) = VAL%R
!       ! E99999 x R -> E99999 (98, 1)
!       RES(1+NROWS*97:NROWS*98,1) = VAL%E99999
!       ! E9 x E9999 -> E99999 (98, 76)
!       RES(1+NROWS*97:NROWS*98,76) = VAL%E9
!       ! E9999 x E9 -> E99999 (98, 10)
!       RES(1+NROWS*97:NROWS*98,10) = VAL%E9999
!       ! E99 x E999 -> E99999 (98, 54)
!       RES(1+NROWS*97:NROWS*98,54) = VAL%E99
!       ! E999 x E99 -> E99999 (98, 32)
!       RES(1+NROWS*97:NROWS*98,32) = VAL%E999
!       ! R x EAAAAA -> EAAAAA (99, 99)
!       RES(1+NROWS*98:NROWS*99,99) = VAL%R
!       ! EAAAAA x R -> EAAAAA (99, 1)
!       RES(1+NROWS*98:NROWS*99,1) = VAL%EAAAAA
!       ! EA x EAAAA -> EAAAAA (99, 77)
!       RES(1+NROWS*98:NROWS*99,77) = VAL%EA
!       ! EAAAA x EA -> EAAAAA (99, 11)
!       RES(1+NROWS*98:NROWS*99,11) = VAL%EAAAA
!       ! EAA x EAAA -> EAAAAA (99, 55)
!       RES(1+NROWS*98:NROWS*99,55) = VAL%EAA
!       ! EAAA x EAA -> EAAAAA (99, 33)
!       RES(1+NROWS*98:NROWS*99,33) = VAL%EAAA
!       ! R x EBBBBB -> EBBBBB (100, 100)
!       RES(1+NROWS*99:NROWS*100,100) = VAL%R
!       ! EBBBBB x R -> EBBBBB (100, 1)
!       RES(1+NROWS*99:NROWS*100,1) = VAL%EBBBBB
!       ! EB x EBBBB -> EBBBBB (100, 78)
!       RES(1+NROWS*99:NROWS*100,78) = VAL%EB
!       ! EBBBB x EB -> EBBBBB (100, 12)
!       RES(1+NROWS*99:NROWS*100,12) = VAL%EBBBB
!       ! EBB x EBBB -> EBBBBB (100, 56)
!       RES(1+NROWS*99:NROWS*100,56) = VAL%EBB
!       ! EBBB x EBB -> EBBBBB (100, 34)
!       RES(1+NROWS*99:NROWS*100,34) = VAL%EBBB
!       ! R x ECCCCC -> ECCCCC (101, 101)
!       RES(1+NROWS*100:NROWS*101,101) = VAL%R
!       ! ECCCCC x R -> ECCCCC (101, 1)
!       RES(1+NROWS*100:NROWS*101,1) = VAL%ECCCCC
!       ! EC x ECCCC -> ECCCCC (101, 79)
!       RES(1+NROWS*100:NROWS*101,79) = VAL%EC
!       ! ECCCC x EC -> ECCCCC (101, 13)
!       RES(1+NROWS*100:NROWS*101,13) = VAL%ECCCC
!       ! ECC x ECCC -> ECCCCC (101, 57)
!       RES(1+NROWS*100:NROWS*101,57) = VAL%ECC
!       ! ECCC x ECC -> ECCCCC (101, 35)
!       RES(1+NROWS*100:NROWS*101,35) = VAL%ECCC
!       ! R x EDDDDD -> EDDDDD (102, 102)
!       RES(1+NROWS*101:NROWS*102,102) = VAL%R
!       ! EDDDDD x R -> EDDDDD (102, 1)
!       RES(1+NROWS*101:NROWS*102,1) = VAL%EDDDDD
!       ! ED x EDDDD -> EDDDDD (102, 80)
!       RES(1+NROWS*101:NROWS*102,80) = VAL%ED
!       ! EDDDD x ED -> EDDDDD (102, 14)
!       RES(1+NROWS*101:NROWS*102,14) = VAL%EDDDD
!       ! EDD x EDDD -> EDDDDD (102, 58)
!       RES(1+NROWS*101:NROWS*102,58) = VAL%EDD
!       ! EDDD x EDD -> EDDDDD (102, 36)
!       RES(1+NROWS*101:NROWS*102,36) = VAL%EDDD
!       ! R x EEEEEE -> EEEEEE (103, 103)
!       RES(1+NROWS*102:NROWS*103,103) = VAL%R
!       ! EEEEEE x R -> EEEEEE (103, 1)
!       RES(1+NROWS*102:NROWS*103,1) = VAL%EEEEEE
!       ! EE x EEEEE -> EEEEEE (103, 81)
!       RES(1+NROWS*102:NROWS*103,81) = VAL%EE
!       ! EEEEE x EE -> EEEEEE (103, 15)
!       RES(1+NROWS*102:NROWS*103,15) = VAL%EEEEE
!       ! EEE x EEEE -> EEEEEE (103, 59)
!       RES(1+NROWS*102:NROWS*103,59) = VAL%EEE
!       ! EEEE x EEE -> EEEEEE (103, 37)
!       RES(1+NROWS*102:NROWS*103,37) = VAL%EEEE
!       ! R x EFFFFF -> EFFFFF (104, 104)
!       RES(1+NROWS*103:NROWS*104,104) = VAL%R
!       ! EFFFFF x R -> EFFFFF (104, 1)
!       RES(1+NROWS*103:NROWS*104,1) = VAL%EFFFFF
!       ! EF x EFFFF -> EFFFFF (104, 82)
!       RES(1+NROWS*103:NROWS*104,82) = VAL%EF
!       ! EFFFF x EF -> EFFFFF (104, 16)
!       RES(1+NROWS*103:NROWS*104,16) = VAL%EFFFF
!       ! EFF x EFFF -> EFFFFF (104, 60)
!       RES(1+NROWS*103:NROWS*104,60) = VAL%EFF
!       ! EFFF x EFF -> EFFFFF (104, 38)
!       RES(1+NROWS*103:NROWS*104,38) = VAL%EFFF
!       ! R x EGGGGG -> EGGGGG (105, 105)
!       RES(1+NROWS*104:NROWS*105,105) = VAL%R
!       ! EGGGGG x R -> EGGGGG (105, 1)
!       RES(1+NROWS*104:NROWS*105,1) = VAL%EGGGGG
!       ! EG x EGGGG -> EGGGGG (105, 83)
!       RES(1+NROWS*104:NROWS*105,83) = VAL%EG
!       ! EGGGG x EG -> EGGGGG (105, 17)
!       RES(1+NROWS*104:NROWS*105,17) = VAL%EGGGG
!       ! EGG x EGGG -> EGGGGG (105, 61)
!       RES(1+NROWS*104:NROWS*105,61) = VAL%EGG
!       ! EGGG x EGG -> EGGGGG (105, 39)
!       RES(1+NROWS*104:NROWS*105,39) = VAL%EGGG
!       ! R x EHHHHH -> EHHHHH (106, 106)
!       RES(1+NROWS*105:NROWS*106,106) = VAL%R
!       ! EHHHHH x R -> EHHHHH (106, 1)
!       RES(1+NROWS*105:NROWS*106,1) = VAL%EHHHHH
!       ! EH x EHHHH -> EHHHHH (106, 84)
!       RES(1+NROWS*105:NROWS*106,84) = VAL%EH
!       ! EHHHH x EH -> EHHHHH (106, 18)
!       RES(1+NROWS*105:NROWS*106,18) = VAL%EHHHH
!       ! EHH x EHHH -> EHHHHH (106, 62)
!       RES(1+NROWS*105:NROWS*106,62) = VAL%EHH
!       ! EHHH x EHH -> EHHHHH (106, 40)
!       RES(1+NROWS*105:NROWS*106,40) = VAL%EHHH
!       ! R x EIIIII -> EIIIII (107, 107)
!       RES(1+NROWS*106:NROWS*107,107) = VAL%R
!       ! EIIIII x R -> EIIIII (107, 1)
!       RES(1+NROWS*106:NROWS*107,1) = VAL%EIIIII
!       ! EI x EIIII -> EIIIII (107, 85)
!       RES(1+NROWS*106:NROWS*107,85) = VAL%EI
!       ! EIIII x EI -> EIIIII (107, 19)
!       RES(1+NROWS*106:NROWS*107,19) = VAL%EIIII
!       ! EII x EIII -> EIIIII (107, 63)
!       RES(1+NROWS*106:NROWS*107,63) = VAL%EII
!       ! EIII x EII -> EIIIII (107, 41)
!       RES(1+NROWS*106:NROWS*107,41) = VAL%EIII
!       ! R x EJJJJJ -> EJJJJJ (108, 108)
!       RES(1+NROWS*107:NROWS*108,108) = VAL%R
!       ! EJJJJJ x R -> EJJJJJ (108, 1)
!       RES(1+NROWS*107:NROWS*108,1) = VAL%EJJJJJ
!       ! EJ x EJJJJ -> EJJJJJ (108, 86)
!       RES(1+NROWS*107:NROWS*108,86) = VAL%EJ
!       ! EJJJJ x EJ -> EJJJJJ (108, 20)
!       RES(1+NROWS*107:NROWS*108,20) = VAL%EJJJJ
!       ! EJJ x EJJJ -> EJJJJJ (108, 64)
!       RES(1+NROWS*107:NROWS*108,64) = VAL%EJJ
!       ! EJJJ x EJJ -> EJJJJJ (108, 42)
!       RES(1+NROWS*107:NROWS*108,42) = VAL%EJJJ
!       ! R x EKKKKK -> EKKKKK (109, 109)
!       RES(1+NROWS*108:NROWS*109,109) = VAL%R
!       ! EKKKKK x R -> EKKKKK (109, 1)
!       RES(1+NROWS*108:NROWS*109,1) = VAL%EKKKKK
!       ! EK x EKKKK -> EKKKKK (109, 87)
!       RES(1+NROWS*108:NROWS*109,87) = VAL%EK
!       ! EKKKK x EK -> EKKKKK (109, 21)
!       RES(1+NROWS*108:NROWS*109,21) = VAL%EKKKK
!       ! EKK x EKKK -> EKKKKK (109, 65)
!       RES(1+NROWS*108:NROWS*109,65) = VAL%EKK
!       ! EKKK x EKK -> EKKKKK (109, 43)
!       RES(1+NROWS*108:NROWS*109,43) = VAL%EKKK
!       ! R x ELLLLL -> ELLLLL (110, 110)
!       RES(1+NROWS*109:NROWS*110,110) = VAL%R
!       ! ELLLLL x R -> ELLLLL (110, 1)
!       RES(1+NROWS*109:NROWS*110,1) = VAL%ELLLLL
!       ! EL x ELLLL -> ELLLLL (110, 88)
!       RES(1+NROWS*109:NROWS*110,88) = VAL%EL
!       ! ELLLL x EL -> ELLLLL (110, 22)
!       RES(1+NROWS*109:NROWS*110,22) = VAL%ELLLL
!       ! ELL x ELLL -> ELLLLL (110, 66)
!       RES(1+NROWS*109:NROWS*110,66) = VAL%ELL
!       ! ELLL x ELL -> ELLLLL (110, 44)
!       RES(1+NROWS*109:NROWS*110,44) = VAL%ELLL
!       ! R x EMMMMM -> EMMMMM (111, 111)
!       RES(1+NROWS*110:NROWS*111,111) = VAL%R
!       ! EMMMMM x R -> EMMMMM (111, 1)
!       RES(1+NROWS*110:NROWS*111,1) = VAL%EMMMMM
!       ! EM x EMMMM -> EMMMMM (111, 89)
!       RES(1+NROWS*110:NROWS*111,89) = VAL%EM
!       ! EMMMM x EM -> EMMMMM (111, 23)
!       RES(1+NROWS*110:NROWS*111,23) = VAL%EMMMM
!       ! EMM x EMMM -> EMMMMM (111, 67)
!       RES(1+NROWS*110:NROWS*111,67) = VAL%EMM
!       ! EMMM x EMM -> EMMMMM (111, 45)
!       RES(1+NROWS*110:NROWS*111,45) = VAL%EMMM
!    END FUNCTION DONUMM22N5_TO_CR_MAT_V

! FUNCTION DONUMM22N5_TO_CR_MAT_M(VAL) RESULT(RES)
!       IMPLICIT NONE
!       TYPE(DONUMM22N5), INTENT(IN) :: VAL(:,:)
!       REAL(DP) :: RES(NUM_IM_DIR*SIZE(VAL,1),NUM_IM_DIR*SIZE(VAL,2)) 
!       INTEGER :: NCOLS=1, NROWS=1

!       NCOLS = SIZE(VAL,1)
!       NROWS = SIZE(VAL,2)

!       ! R x R -> R (1, 1)
!       RES(1+NROWS*0:NROWS*1,1+NCOLS*0:NCOLS*1) = VAL%R
!       ! R x E1 -> E1 (2, 2)
!       RES(1+NROWS*1:NROWS*2,1+NCOLS*1:NCOLS*2) = VAL%R
!       ! E1 x R -> E1 (2, 1)
!       RES(1+NROWS*1:NROWS*2,1+NCOLS*0:NCOLS*1) = VAL%E1
!       ! R x E2 -> E2 (3, 3)
!       RES(1+NROWS*2:NROWS*3,1+NCOLS*2:NCOLS*3) = VAL%R
!       ! E2 x R -> E2 (3, 1)
!       RES(1+NROWS*2:NROWS*3,1+NCOLS*0:NCOLS*1) = VAL%E2
!       ! R x E3 -> E3 (4, 4)
!       RES(1+NROWS*3:NROWS*4,1+NCOLS*3:NCOLS*4) = VAL%R
!       ! E3 x R -> E3 (4, 1)
!       RES(1+NROWS*3:NROWS*4,1+NCOLS*0:NCOLS*1) = VAL%E3
!       ! R x E4 -> E4 (5, 5)
!       RES(1+NROWS*4:NROWS*5,1+NCOLS*4:NCOLS*5) = VAL%R
!       ! E4 x R -> E4 (5, 1)
!       RES(1+NROWS*4:NROWS*5,1+NCOLS*0:NCOLS*1) = VAL%E4
!       ! R x E5 -> E5 (6, 6)
!       RES(1+NROWS*5:NROWS*6,1+NCOLS*5:NCOLS*6) = VAL%R
!       ! E5 x R -> E5 (6, 1)
!       RES(1+NROWS*5:NROWS*6,1+NCOLS*0:NCOLS*1) = VAL%E5
!       ! R x E6 -> E6 (7, 7)
!       RES(1+NROWS*6:NROWS*7,1+NCOLS*6:NCOLS*7) = VAL%R
!       ! E6 x R -> E6 (7, 1)
!       RES(1+NROWS*6:NROWS*7,1+NCOLS*0:NCOLS*1) = VAL%E6
!       ! R x E7 -> E7 (8, 8)
!       RES(1+NROWS*7:NROWS*8,1+NCOLS*7:NCOLS*8) = VAL%R
!       ! E7 x R -> E7 (8, 1)
!       RES(1+NROWS*7:NROWS*8,1+NCOLS*0:NCOLS*1) = VAL%E7
!       ! R x E8 -> E8 (9, 9)
!       RES(1+NROWS*8:NROWS*9,1+NCOLS*8:NCOLS*9) = VAL%R
!       ! E8 x R -> E8 (9, 1)
!       RES(1+NROWS*8:NROWS*9,1+NCOLS*0:NCOLS*1) = VAL%E8
!       ! R x E9 -> E9 (10, 10)
!       RES(1+NROWS*9:NROWS*10,1+NCOLS*9:NCOLS*10) = VAL%R
!       ! E9 x R -> E9 (10, 1)
!       RES(1+NROWS*9:NROWS*10,1+NCOLS*0:NCOLS*1) = VAL%E9
!       ! R x EA -> EA (11, 11)
!       RES(1+NROWS*10:NROWS*11,1+NCOLS*10:NCOLS*11) = VAL%R
!       ! EA x R -> EA (11, 1)
!       RES(1+NROWS*10:NROWS*11,1+NCOLS*0:NCOLS*1) = VAL%EA
!       ! R x EB -> EB (12, 12)
!       RES(1+NROWS*11:NROWS*12,1+NCOLS*11:NCOLS*12) = VAL%R
!       ! EB x R -> EB (12, 1)
!       RES(1+NROWS*11:NROWS*12,1+NCOLS*0:NCOLS*1) = VAL%EB
!       ! R x EC -> EC (13, 13)
!       RES(1+NROWS*12:NROWS*13,1+NCOLS*12:NCOLS*13) = VAL%R
!       ! EC x R -> EC (13, 1)
!       RES(1+NROWS*12:NROWS*13,1+NCOLS*0:NCOLS*1) = VAL%EC
!       ! R x ED -> ED (14, 14)
!       RES(1+NROWS*13:NROWS*14,1+NCOLS*13:NCOLS*14) = VAL%R
!       ! ED x R -> ED (14, 1)
!       RES(1+NROWS*13:NROWS*14,1+NCOLS*0:NCOLS*1) = VAL%ED
!       ! R x EE -> EE (15, 15)
!       RES(1+NROWS*14:NROWS*15,1+NCOLS*14:NCOLS*15) = VAL%R
!       ! EE x R -> EE (15, 1)
!       RES(1+NROWS*14:NROWS*15,1+NCOLS*0:NCOLS*1) = VAL%EE
!       ! R x EF -> EF (16, 16)
!       RES(1+NROWS*15:NROWS*16,1+NCOLS*15:NCOLS*16) = VAL%R
!       ! EF x R -> EF (16, 1)
!       RES(1+NROWS*15:NROWS*16,1+NCOLS*0:NCOLS*1) = VAL%EF
!       ! R x EG -> EG (17, 17)
!       RES(1+NROWS*16:NROWS*17,1+NCOLS*16:NCOLS*17) = VAL%R
!       ! EG x R -> EG (17, 1)
!       RES(1+NROWS*16:NROWS*17,1+NCOLS*0:NCOLS*1) = VAL%EG
!       ! R x EH -> EH (18, 18)
!       RES(1+NROWS*17:NROWS*18,1+NCOLS*17:NCOLS*18) = VAL%R
!       ! EH x R -> EH (18, 1)
!       RES(1+NROWS*17:NROWS*18,1+NCOLS*0:NCOLS*1) = VAL%EH
!       ! R x EI -> EI (19, 19)
!       RES(1+NROWS*18:NROWS*19,1+NCOLS*18:NCOLS*19) = VAL%R
!       ! EI x R -> EI (19, 1)
!       RES(1+NROWS*18:NROWS*19,1+NCOLS*0:NCOLS*1) = VAL%EI
!       ! R x EJ -> EJ (20, 20)
!       RES(1+NROWS*19:NROWS*20,1+NCOLS*19:NCOLS*20) = VAL%R
!       ! EJ x R -> EJ (20, 1)
!       RES(1+NROWS*19:NROWS*20,1+NCOLS*0:NCOLS*1) = VAL%EJ
!       ! R x EK -> EK (21, 21)
!       RES(1+NROWS*20:NROWS*21,1+NCOLS*20:NCOLS*21) = VAL%R
!       ! EK x R -> EK (21, 1)
!       RES(1+NROWS*20:NROWS*21,1+NCOLS*0:NCOLS*1) = VAL%EK
!       ! R x EL -> EL (22, 22)
!       RES(1+NROWS*21:NROWS*22,1+NCOLS*21:NCOLS*22) = VAL%R
!       ! EL x R -> EL (22, 1)
!       RES(1+NROWS*21:NROWS*22,1+NCOLS*0:NCOLS*1) = VAL%EL
!       ! R x EM -> EM (23, 23)
!       RES(1+NROWS*22:NROWS*23,1+NCOLS*22:NCOLS*23) = VAL%R
!       ! EM x R -> EM (23, 1)
!       RES(1+NROWS*22:NROWS*23,1+NCOLS*0:NCOLS*1) = VAL%EM
!       ! R x E11 -> E11 (24, 24)
!       RES(1+NROWS*23:NROWS*24,1+NCOLS*23:NCOLS*24) = VAL%R
!       ! E11 x R -> E11 (24, 1)
!       RES(1+NROWS*23:NROWS*24,1+NCOLS*0:NCOLS*1) = VAL%E11
!       ! E1 x E1 -> E11 (24, 2)
!       RES(1+NROWS*23:NROWS*24,1+NCOLS*1:NCOLS*2) = VAL%E1
!       ! R x E22 -> E22 (25, 25)
!       RES(1+NROWS*24:NROWS*25,1+NCOLS*24:NCOLS*25) = VAL%R
!       ! E22 x R -> E22 (25, 1)
!       RES(1+NROWS*24:NROWS*25,1+NCOLS*0:NCOLS*1) = VAL%E22
!       ! E2 x E2 -> E22 (25, 3)
!       RES(1+NROWS*24:NROWS*25,1+NCOLS*2:NCOLS*3) = VAL%E2
!       ! R x E33 -> E33 (26, 26)
!       RES(1+NROWS*25:NROWS*26,1+NCOLS*25:NCOLS*26) = VAL%R
!       ! E33 x R -> E33 (26, 1)
!       RES(1+NROWS*25:NROWS*26,1+NCOLS*0:NCOLS*1) = VAL%E33
!       ! E3 x E3 -> E33 (26, 4)
!       RES(1+NROWS*25:NROWS*26,1+NCOLS*3:NCOLS*4) = VAL%E3
!       ! R x E44 -> E44 (27, 27)
!       RES(1+NROWS*26:NROWS*27,1+NCOLS*26:NCOLS*27) = VAL%R
!       ! E44 x R -> E44 (27, 1)
!       RES(1+NROWS*26:NROWS*27,1+NCOLS*0:NCOLS*1) = VAL%E44
!       ! E4 x E4 -> E44 (27, 5)
!       RES(1+NROWS*26:NROWS*27,1+NCOLS*4:NCOLS*5) = VAL%E4
!       ! R x E55 -> E55 (28, 28)
!       RES(1+NROWS*27:NROWS*28,1+NCOLS*27:NCOLS*28) = VAL%R
!       ! E55 x R -> E55 (28, 1)
!       RES(1+NROWS*27:NROWS*28,1+NCOLS*0:NCOLS*1) = VAL%E55
!       ! E5 x E5 -> E55 (28, 6)
!       RES(1+NROWS*27:NROWS*28,1+NCOLS*5:NCOLS*6) = VAL%E5
!       ! R x E66 -> E66 (29, 29)
!       RES(1+NROWS*28:NROWS*29,1+NCOLS*28:NCOLS*29) = VAL%R
!       ! E66 x R -> E66 (29, 1)
!       RES(1+NROWS*28:NROWS*29,1+NCOLS*0:NCOLS*1) = VAL%E66
!       ! E6 x E6 -> E66 (29, 7)
!       RES(1+NROWS*28:NROWS*29,1+NCOLS*6:NCOLS*7) = VAL%E6
!       ! R x E77 -> E77 (30, 30)
!       RES(1+NROWS*29:NROWS*30,1+NCOLS*29:NCOLS*30) = VAL%R
!       ! E77 x R -> E77 (30, 1)
!       RES(1+NROWS*29:NROWS*30,1+NCOLS*0:NCOLS*1) = VAL%E77
!       ! E7 x E7 -> E77 (30, 8)
!       RES(1+NROWS*29:NROWS*30,1+NCOLS*7:NCOLS*8) = VAL%E7
!       ! R x E88 -> E88 (31, 31)
!       RES(1+NROWS*30:NROWS*31,1+NCOLS*30:NCOLS*31) = VAL%R
!       ! E88 x R -> E88 (31, 1)
!       RES(1+NROWS*30:NROWS*31,1+NCOLS*0:NCOLS*1) = VAL%E88
!       ! E8 x E8 -> E88 (31, 9)
!       RES(1+NROWS*30:NROWS*31,1+NCOLS*8:NCOLS*9) = VAL%E8
!       ! R x E99 -> E99 (32, 32)
!       RES(1+NROWS*31:NROWS*32,1+NCOLS*31:NCOLS*32) = VAL%R
!       ! E99 x R -> E99 (32, 1)
!       RES(1+NROWS*31:NROWS*32,1+NCOLS*0:NCOLS*1) = VAL%E99
!       ! E9 x E9 -> E99 (32, 10)
!       RES(1+NROWS*31:NROWS*32,1+NCOLS*9:NCOLS*10) = VAL%E9
!       ! R x EAA -> EAA (33, 33)
!       RES(1+NROWS*32:NROWS*33,1+NCOLS*32:NCOLS*33) = VAL%R
!       ! EAA x R -> EAA (33, 1)
!       RES(1+NROWS*32:NROWS*33,1+NCOLS*0:NCOLS*1) = VAL%EAA
!       ! EA x EA -> EAA (33, 11)
!       RES(1+NROWS*32:NROWS*33,1+NCOLS*10:NCOLS*11) = VAL%EA
!       ! R x EBB -> EBB (34, 34)
!       RES(1+NROWS*33:NROWS*34,1+NCOLS*33:NCOLS*34) = VAL%R
!       ! EBB x R -> EBB (34, 1)
!       RES(1+NROWS*33:NROWS*34,1+NCOLS*0:NCOLS*1) = VAL%EBB
!       ! EB x EB -> EBB (34, 12)
!       RES(1+NROWS*33:NROWS*34,1+NCOLS*11:NCOLS*12) = VAL%EB
!       ! R x ECC -> ECC (35, 35)
!       RES(1+NROWS*34:NROWS*35,1+NCOLS*34:NCOLS*35) = VAL%R
!       ! ECC x R -> ECC (35, 1)
!       RES(1+NROWS*34:NROWS*35,1+NCOLS*0:NCOLS*1) = VAL%ECC
!       ! EC x EC -> ECC (35, 13)
!       RES(1+NROWS*34:NROWS*35,1+NCOLS*12:NCOLS*13) = VAL%EC
!       ! R x EDD -> EDD (36, 36)
!       RES(1+NROWS*35:NROWS*36,1+NCOLS*35:NCOLS*36) = VAL%R
!       ! EDD x R -> EDD (36, 1)
!       RES(1+NROWS*35:NROWS*36,1+NCOLS*0:NCOLS*1) = VAL%EDD
!       ! ED x ED -> EDD (36, 14)
!       RES(1+NROWS*35:NROWS*36,1+NCOLS*13:NCOLS*14) = VAL%ED
!       ! R x EEE -> EEE (37, 37)
!       RES(1+NROWS*36:NROWS*37,1+NCOLS*36:NCOLS*37) = VAL%R
!       ! EEE x R -> EEE (37, 1)
!       RES(1+NROWS*36:NROWS*37,1+NCOLS*0:NCOLS*1) = VAL%EEE
!       ! EE x EE -> EEE (37, 15)
!       RES(1+NROWS*36:NROWS*37,1+NCOLS*14:NCOLS*15) = VAL%EE
!       ! R x EFF -> EFF (38, 38)
!       RES(1+NROWS*37:NROWS*38,1+NCOLS*37:NCOLS*38) = VAL%R
!       ! EFF x R -> EFF (38, 1)
!       RES(1+NROWS*37:NROWS*38,1+NCOLS*0:NCOLS*1) = VAL%EFF
!       ! EF x EF -> EFF (38, 16)
!       RES(1+NROWS*37:NROWS*38,1+NCOLS*15:NCOLS*16) = VAL%EF
!       ! R x EGG -> EGG (39, 39)
!       RES(1+NROWS*38:NROWS*39,1+NCOLS*38:NCOLS*39) = VAL%R
!       ! EGG x R -> EGG (39, 1)
!       RES(1+NROWS*38:NROWS*39,1+NCOLS*0:NCOLS*1) = VAL%EGG
!       ! EG x EG -> EGG (39, 17)
!       RES(1+NROWS*38:NROWS*39,1+NCOLS*16:NCOLS*17) = VAL%EG
!       ! R x EHH -> EHH (40, 40)
!       RES(1+NROWS*39:NROWS*40,1+NCOLS*39:NCOLS*40) = VAL%R
!       ! EHH x R -> EHH (40, 1)
!       RES(1+NROWS*39:NROWS*40,1+NCOLS*0:NCOLS*1) = VAL%EHH
!       ! EH x EH -> EHH (40, 18)
!       RES(1+NROWS*39:NROWS*40,1+NCOLS*17:NCOLS*18) = VAL%EH
!       ! R x EII -> EII (41, 41)
!       RES(1+NROWS*40:NROWS*41,1+NCOLS*40:NCOLS*41) = VAL%R
!       ! EII x R -> EII (41, 1)
!       RES(1+NROWS*40:NROWS*41,1+NCOLS*0:NCOLS*1) = VAL%EII
!       ! EI x EI -> EII (41, 19)
!       RES(1+NROWS*40:NROWS*41,1+NCOLS*18:NCOLS*19) = VAL%EI
!       ! R x EJJ -> EJJ (42, 42)
!       RES(1+NROWS*41:NROWS*42,1+NCOLS*41:NCOLS*42) = VAL%R
!       ! EJJ x R -> EJJ (42, 1)
!       RES(1+NROWS*41:NROWS*42,1+NCOLS*0:NCOLS*1) = VAL%EJJ
!       ! EJ x EJ -> EJJ (42, 20)
!       RES(1+NROWS*41:NROWS*42,1+NCOLS*19:NCOLS*20) = VAL%EJ
!       ! R x EKK -> EKK (43, 43)
!       RES(1+NROWS*42:NROWS*43,1+NCOLS*42:NCOLS*43) = VAL%R
!       ! EKK x R -> EKK (43, 1)
!       RES(1+NROWS*42:NROWS*43,1+NCOLS*0:NCOLS*1) = VAL%EKK
!       ! EK x EK -> EKK (43, 21)
!       RES(1+NROWS*42:NROWS*43,1+NCOLS*20:NCOLS*21) = VAL%EK
!       ! R x ELL -> ELL (44, 44)
!       RES(1+NROWS*43:NROWS*44,1+NCOLS*43:NCOLS*44) = VAL%R
!       ! ELL x R -> ELL (44, 1)
!       RES(1+NROWS*43:NROWS*44,1+NCOLS*0:NCOLS*1) = VAL%ELL
!       ! EL x EL -> ELL (44, 22)
!       RES(1+NROWS*43:NROWS*44,1+NCOLS*21:NCOLS*22) = VAL%EL
!       ! R x EMM -> EMM (45, 45)
!       RES(1+NROWS*44:NROWS*45,1+NCOLS*44:NCOLS*45) = VAL%R
!       ! EMM x R -> EMM (45, 1)
!       RES(1+NROWS*44:NROWS*45,1+NCOLS*0:NCOLS*1) = VAL%EMM
!       ! EM x EM -> EMM (45, 23)
!       RES(1+NROWS*44:NROWS*45,1+NCOLS*22:NCOLS*23) = VAL%EM
!       ! R x E111 -> E111 (46, 46)
!       RES(1+NROWS*45:NROWS*46,1+NCOLS*45:NCOLS*46) = VAL%R
!       ! E111 x R -> E111 (46, 1)
!       RES(1+NROWS*45:NROWS*46,1+NCOLS*0:NCOLS*1) = VAL%E111
!       ! E1 x E11 -> E111 (46, 24)
!       RES(1+NROWS*45:NROWS*46,1+NCOLS*23:NCOLS*24) = VAL%E1
!       ! E11 x E1 -> E111 (46, 2)
!       RES(1+NROWS*45:NROWS*46,1+NCOLS*1:NCOLS*2) = VAL%E11
!       ! R x E222 -> E222 (47, 47)
!       RES(1+NROWS*46:NROWS*47,1+NCOLS*46:NCOLS*47) = VAL%R
!       ! E222 x R -> E222 (47, 1)
!       RES(1+NROWS*46:NROWS*47,1+NCOLS*0:NCOLS*1) = VAL%E222
!       ! E2 x E22 -> E222 (47, 25)
!       RES(1+NROWS*46:NROWS*47,1+NCOLS*24:NCOLS*25) = VAL%E2
!       ! E22 x E2 -> E222 (47, 3)
!       RES(1+NROWS*46:NROWS*47,1+NCOLS*2:NCOLS*3) = VAL%E22
!       ! R x E333 -> E333 (48, 48)
!       RES(1+NROWS*47:NROWS*48,1+NCOLS*47:NCOLS*48) = VAL%R
!       ! E333 x R -> E333 (48, 1)
!       RES(1+NROWS*47:NROWS*48,1+NCOLS*0:NCOLS*1) = VAL%E333
!       ! E3 x E33 -> E333 (48, 26)
!       RES(1+NROWS*47:NROWS*48,1+NCOLS*25:NCOLS*26) = VAL%E3
!       ! E33 x E3 -> E333 (48, 4)
!       RES(1+NROWS*47:NROWS*48,1+NCOLS*3:NCOLS*4) = VAL%E33
!       ! R x E444 -> E444 (49, 49)
!       RES(1+NROWS*48:NROWS*49,1+NCOLS*48:NCOLS*49) = VAL%R
!       ! E444 x R -> E444 (49, 1)
!       RES(1+NROWS*48:NROWS*49,1+NCOLS*0:NCOLS*1) = VAL%E444
!       ! E4 x E44 -> E444 (49, 27)
!       RES(1+NROWS*48:NROWS*49,1+NCOLS*26:NCOLS*27) = VAL%E4
!       ! E44 x E4 -> E444 (49, 5)
!       RES(1+NROWS*48:NROWS*49,1+NCOLS*4:NCOLS*5) = VAL%E44
!       ! R x E555 -> E555 (50, 50)
!       RES(1+NROWS*49:NROWS*50,1+NCOLS*49:NCOLS*50) = VAL%R
!       ! E555 x R -> E555 (50, 1)
!       RES(1+NROWS*49:NROWS*50,1+NCOLS*0:NCOLS*1) = VAL%E555
!       ! E5 x E55 -> E555 (50, 28)
!       RES(1+NROWS*49:NROWS*50,1+NCOLS*27:NCOLS*28) = VAL%E5
!       ! E55 x E5 -> E555 (50, 6)
!       RES(1+NROWS*49:NROWS*50,1+NCOLS*5:NCOLS*6) = VAL%E55
!       ! R x E666 -> E666 (51, 51)
!       RES(1+NROWS*50:NROWS*51,1+NCOLS*50:NCOLS*51) = VAL%R
!       ! E666 x R -> E666 (51, 1)
!       RES(1+NROWS*50:NROWS*51,1+NCOLS*0:NCOLS*1) = VAL%E666
!       ! E6 x E66 -> E666 (51, 29)
!       RES(1+NROWS*50:NROWS*51,1+NCOLS*28:NCOLS*29) = VAL%E6
!       ! E66 x E6 -> E666 (51, 7)
!       RES(1+NROWS*50:NROWS*51,1+NCOLS*6:NCOLS*7) = VAL%E66
!       ! R x E777 -> E777 (52, 52)
!       RES(1+NROWS*51:NROWS*52,1+NCOLS*51:NCOLS*52) = VAL%R
!       ! E777 x R -> E777 (52, 1)
!       RES(1+NROWS*51:NROWS*52,1+NCOLS*0:NCOLS*1) = VAL%E777
!       ! E7 x E77 -> E777 (52, 30)
!       RES(1+NROWS*51:NROWS*52,1+NCOLS*29:NCOLS*30) = VAL%E7
!       ! E77 x E7 -> E777 (52, 8)
!       RES(1+NROWS*51:NROWS*52,1+NCOLS*7:NCOLS*8) = VAL%E77
!       ! R x E888 -> E888 (53, 53)
!       RES(1+NROWS*52:NROWS*53,1+NCOLS*52:NCOLS*53) = VAL%R
!       ! E888 x R -> E888 (53, 1)
!       RES(1+NROWS*52:NROWS*53,1+NCOLS*0:NCOLS*1) = VAL%E888
!       ! E8 x E88 -> E888 (53, 31)
!       RES(1+NROWS*52:NROWS*53,1+NCOLS*30:NCOLS*31) = VAL%E8
!       ! E88 x E8 -> E888 (53, 9)
!       RES(1+NROWS*52:NROWS*53,1+NCOLS*8:NCOLS*9) = VAL%E88
!       ! R x E999 -> E999 (54, 54)
!       RES(1+NROWS*53:NROWS*54,1+NCOLS*53:NCOLS*54) = VAL%R
!       ! E999 x R -> E999 (54, 1)
!       RES(1+NROWS*53:NROWS*54,1+NCOLS*0:NCOLS*1) = VAL%E999
!       ! E9 x E99 -> E999 (54, 32)
!       RES(1+NROWS*53:NROWS*54,1+NCOLS*31:NCOLS*32) = VAL%E9
!       ! E99 x E9 -> E999 (54, 10)
!       RES(1+NROWS*53:NROWS*54,1+NCOLS*9:NCOLS*10) = VAL%E99
!       ! R x EAAA -> EAAA (55, 55)
!       RES(1+NROWS*54:NROWS*55,1+NCOLS*54:NCOLS*55) = VAL%R
!       ! EAAA x R -> EAAA (55, 1)
!       RES(1+NROWS*54:NROWS*55,1+NCOLS*0:NCOLS*1) = VAL%EAAA
!       ! EA x EAA -> EAAA (55, 33)
!       RES(1+NROWS*54:NROWS*55,1+NCOLS*32:NCOLS*33) = VAL%EA
!       ! EAA x EA -> EAAA (55, 11)
!       RES(1+NROWS*54:NROWS*55,1+NCOLS*10:NCOLS*11) = VAL%EAA
!       ! R x EBBB -> EBBB (56, 56)
!       RES(1+NROWS*55:NROWS*56,1+NCOLS*55:NCOLS*56) = VAL%R
!       ! EBBB x R -> EBBB (56, 1)
!       RES(1+NROWS*55:NROWS*56,1+NCOLS*0:NCOLS*1) = VAL%EBBB
!       ! EB x EBB -> EBBB (56, 34)
!       RES(1+NROWS*55:NROWS*56,1+NCOLS*33:NCOLS*34) = VAL%EB
!       ! EBB x EB -> EBBB (56, 12)
!       RES(1+NROWS*55:NROWS*56,1+NCOLS*11:NCOLS*12) = VAL%EBB
!       ! R x ECCC -> ECCC (57, 57)
!       RES(1+NROWS*56:NROWS*57,1+NCOLS*56:NCOLS*57) = VAL%R
!       ! ECCC x R -> ECCC (57, 1)
!       RES(1+NROWS*56:NROWS*57,1+NCOLS*0:NCOLS*1) = VAL%ECCC
!       ! EC x ECC -> ECCC (57, 35)
!       RES(1+NROWS*56:NROWS*57,1+NCOLS*34:NCOLS*35) = VAL%EC
!       ! ECC x EC -> ECCC (57, 13)
!       RES(1+NROWS*56:NROWS*57,1+NCOLS*12:NCOLS*13) = VAL%ECC
!       ! R x EDDD -> EDDD (58, 58)
!       RES(1+NROWS*57:NROWS*58,1+NCOLS*57:NCOLS*58) = VAL%R
!       ! EDDD x R -> EDDD (58, 1)
!       RES(1+NROWS*57:NROWS*58,1+NCOLS*0:NCOLS*1) = VAL%EDDD
!       ! ED x EDD -> EDDD (58, 36)
!       RES(1+NROWS*57:NROWS*58,1+NCOLS*35:NCOLS*36) = VAL%ED
!       ! EDD x ED -> EDDD (58, 14)
!       RES(1+NROWS*57:NROWS*58,1+NCOLS*13:NCOLS*14) = VAL%EDD
!       ! R x EEEE -> EEEE (59, 59)
!       RES(1+NROWS*58:NROWS*59,1+NCOLS*58:NCOLS*59) = VAL%R
!       ! EEEE x R -> EEEE (59, 1)
!       RES(1+NROWS*58:NROWS*59,1+NCOLS*0:NCOLS*1) = VAL%EEEE
!       ! EE x EEE -> EEEE (59, 37)
!       RES(1+NROWS*58:NROWS*59,1+NCOLS*36:NCOLS*37) = VAL%EE
!       ! EEE x EE -> EEEE (59, 15)
!       RES(1+NROWS*58:NROWS*59,1+NCOLS*14:NCOLS*15) = VAL%EEE
!       ! R x EFFF -> EFFF (60, 60)
!       RES(1+NROWS*59:NROWS*60,1+NCOLS*59:NCOLS*60) = VAL%R
!       ! EFFF x R -> EFFF (60, 1)
!       RES(1+NROWS*59:NROWS*60,1+NCOLS*0:NCOLS*1) = VAL%EFFF
!       ! EF x EFF -> EFFF (60, 38)
!       RES(1+NROWS*59:NROWS*60,1+NCOLS*37:NCOLS*38) = VAL%EF
!       ! EFF x EF -> EFFF (60, 16)
!       RES(1+NROWS*59:NROWS*60,1+NCOLS*15:NCOLS*16) = VAL%EFF
!       ! R x EGGG -> EGGG (61, 61)
!       RES(1+NROWS*60:NROWS*61,1+NCOLS*60:NCOLS*61) = VAL%R
!       ! EGGG x R -> EGGG (61, 1)
!       RES(1+NROWS*60:NROWS*61,1+NCOLS*0:NCOLS*1) = VAL%EGGG
!       ! EG x EGG -> EGGG (61, 39)
!       RES(1+NROWS*60:NROWS*61,1+NCOLS*38:NCOLS*39) = VAL%EG
!       ! EGG x EG -> EGGG (61, 17)
!       RES(1+NROWS*60:NROWS*61,1+NCOLS*16:NCOLS*17) = VAL%EGG
!       ! R x EHHH -> EHHH (62, 62)
!       RES(1+NROWS*61:NROWS*62,1+NCOLS*61:NCOLS*62) = VAL%R
!       ! EHHH x R -> EHHH (62, 1)
!       RES(1+NROWS*61:NROWS*62,1+NCOLS*0:NCOLS*1) = VAL%EHHH
!       ! EH x EHH -> EHHH (62, 40)
!       RES(1+NROWS*61:NROWS*62,1+NCOLS*39:NCOLS*40) = VAL%EH
!       ! EHH x EH -> EHHH (62, 18)
!       RES(1+NROWS*61:NROWS*62,1+NCOLS*17:NCOLS*18) = VAL%EHH
!       ! R x EIII -> EIII (63, 63)
!       RES(1+NROWS*62:NROWS*63,1+NCOLS*62:NCOLS*63) = VAL%R
!       ! EIII x R -> EIII (63, 1)
!       RES(1+NROWS*62:NROWS*63,1+NCOLS*0:NCOLS*1) = VAL%EIII
!       ! EI x EII -> EIII (63, 41)
!       RES(1+NROWS*62:NROWS*63,1+NCOLS*40:NCOLS*41) = VAL%EI
!       ! EII x EI -> EIII (63, 19)
!       RES(1+NROWS*62:NROWS*63,1+NCOLS*18:NCOLS*19) = VAL%EII
!       ! R x EJJJ -> EJJJ (64, 64)
!       RES(1+NROWS*63:NROWS*64,1+NCOLS*63:NCOLS*64) = VAL%R
!       ! EJJJ x R -> EJJJ (64, 1)
!       RES(1+NROWS*63:NROWS*64,1+NCOLS*0:NCOLS*1) = VAL%EJJJ
!       ! EJ x EJJ -> EJJJ (64, 42)
!       RES(1+NROWS*63:NROWS*64,1+NCOLS*41:NCOLS*42) = VAL%EJ
!       ! EJJ x EJ -> EJJJ (64, 20)
!       RES(1+NROWS*63:NROWS*64,1+NCOLS*19:NCOLS*20) = VAL%EJJ
!       ! R x EKKK -> EKKK (65, 65)
!       RES(1+NROWS*64:NROWS*65,1+NCOLS*64:NCOLS*65) = VAL%R
!       ! EKKK x R -> EKKK (65, 1)
!       RES(1+NROWS*64:NROWS*65,1+NCOLS*0:NCOLS*1) = VAL%EKKK
!       ! EK x EKK -> EKKK (65, 43)
!       RES(1+NROWS*64:NROWS*65,1+NCOLS*42:NCOLS*43) = VAL%EK
!       ! EKK x EK -> EKKK (65, 21)
!       RES(1+NROWS*64:NROWS*65,1+NCOLS*20:NCOLS*21) = VAL%EKK
!       ! R x ELLL -> ELLL (66, 66)
!       RES(1+NROWS*65:NROWS*66,1+NCOLS*65:NCOLS*66) = VAL%R
!       ! ELLL x R -> ELLL (66, 1)
!       RES(1+NROWS*65:NROWS*66,1+NCOLS*0:NCOLS*1) = VAL%ELLL
!       ! EL x ELL -> ELLL (66, 44)
!       RES(1+NROWS*65:NROWS*66,1+NCOLS*43:NCOLS*44) = VAL%EL
!       ! ELL x EL -> ELLL (66, 22)
!       RES(1+NROWS*65:NROWS*66,1+NCOLS*21:NCOLS*22) = VAL%ELL
!       ! R x EMMM -> EMMM (67, 67)
!       RES(1+NROWS*66:NROWS*67,1+NCOLS*66:NCOLS*67) = VAL%R
!       ! EMMM x R -> EMMM (67, 1)
!       RES(1+NROWS*66:NROWS*67,1+NCOLS*0:NCOLS*1) = VAL%EMMM
!       ! EM x EMM -> EMMM (67, 45)
!       RES(1+NROWS*66:NROWS*67,1+NCOLS*44:NCOLS*45) = VAL%EM
!       ! EMM x EM -> EMMM (67, 23)
!       RES(1+NROWS*66:NROWS*67,1+NCOLS*22:NCOLS*23) = VAL%EMM
!       ! R x E1111 -> E1111 (68, 68)
!       RES(1+NROWS*67:NROWS*68,1+NCOLS*67:NCOLS*68) = VAL%R
!       ! E1111 x R -> E1111 (68, 1)
!       RES(1+NROWS*67:NROWS*68,1+NCOLS*0:NCOLS*1) = VAL%E1111
!       ! E1 x E111 -> E1111 (68, 46)
!       RES(1+NROWS*67:NROWS*68,1+NCOLS*45:NCOLS*46) = VAL%E1
!       ! E111 x E1 -> E1111 (68, 2)
!       RES(1+NROWS*67:NROWS*68,1+NCOLS*1:NCOLS*2) = VAL%E111
!       ! E11 x E11 -> E1111 (68, 24)
!       RES(1+NROWS*67:NROWS*68,1+NCOLS*23:NCOLS*24) = VAL%E11
!       ! R x E2222 -> E2222 (69, 69)
!       RES(1+NROWS*68:NROWS*69,1+NCOLS*68:NCOLS*69) = VAL%R
!       ! E2222 x R -> E2222 (69, 1)
!       RES(1+NROWS*68:NROWS*69,1+NCOLS*0:NCOLS*1) = VAL%E2222
!       ! E2 x E222 -> E2222 (69, 47)
!       RES(1+NROWS*68:NROWS*69,1+NCOLS*46:NCOLS*47) = VAL%E2
!       ! E222 x E2 -> E2222 (69, 3)
!       RES(1+NROWS*68:NROWS*69,1+NCOLS*2:NCOLS*3) = VAL%E222
!       ! E22 x E22 -> E2222 (69, 25)
!       RES(1+NROWS*68:NROWS*69,1+NCOLS*24:NCOLS*25) = VAL%E22
!       ! R x E3333 -> E3333 (70, 70)
!       RES(1+NROWS*69:NROWS*70,1+NCOLS*69:NCOLS*70) = VAL%R
!       ! E3333 x R -> E3333 (70, 1)
!       RES(1+NROWS*69:NROWS*70,1+NCOLS*0:NCOLS*1) = VAL%E3333
!       ! E3 x E333 -> E3333 (70, 48)
!       RES(1+NROWS*69:NROWS*70,1+NCOLS*47:NCOLS*48) = VAL%E3
!       ! E333 x E3 -> E3333 (70, 4)
!       RES(1+NROWS*69:NROWS*70,1+NCOLS*3:NCOLS*4) = VAL%E333
!       ! E33 x E33 -> E3333 (70, 26)
!       RES(1+NROWS*69:NROWS*70,1+NCOLS*25:NCOLS*26) = VAL%E33
!       ! R x E4444 -> E4444 (71, 71)
!       RES(1+NROWS*70:NROWS*71,1+NCOLS*70:NCOLS*71) = VAL%R
!       ! E4444 x R -> E4444 (71, 1)
!       RES(1+NROWS*70:NROWS*71,1+NCOLS*0:NCOLS*1) = VAL%E4444
!       ! E4 x E444 -> E4444 (71, 49)
!       RES(1+NROWS*70:NROWS*71,1+NCOLS*48:NCOLS*49) = VAL%E4
!       ! E444 x E4 -> E4444 (71, 5)
!       RES(1+NROWS*70:NROWS*71,1+NCOLS*4:NCOLS*5) = VAL%E444
!       ! E44 x E44 -> E4444 (71, 27)
!       RES(1+NROWS*70:NROWS*71,1+NCOLS*26:NCOLS*27) = VAL%E44
!       ! R x E5555 -> E5555 (72, 72)
!       RES(1+NROWS*71:NROWS*72,1+NCOLS*71:NCOLS*72) = VAL%R
!       ! E5555 x R -> E5555 (72, 1)
!       RES(1+NROWS*71:NROWS*72,1+NCOLS*0:NCOLS*1) = VAL%E5555
!       ! E5 x E555 -> E5555 (72, 50)
!       RES(1+NROWS*71:NROWS*72,1+NCOLS*49:NCOLS*50) = VAL%E5
!       ! E555 x E5 -> E5555 (72, 6)
!       RES(1+NROWS*71:NROWS*72,1+NCOLS*5:NCOLS*6) = VAL%E555
!       ! E55 x E55 -> E5555 (72, 28)
!       RES(1+NROWS*71:NROWS*72,1+NCOLS*27:NCOLS*28) = VAL%E55
!       ! R x E6666 -> E6666 (73, 73)
!       RES(1+NROWS*72:NROWS*73,1+NCOLS*72:NCOLS*73) = VAL%R
!       ! E6666 x R -> E6666 (73, 1)
!       RES(1+NROWS*72:NROWS*73,1+NCOLS*0:NCOLS*1) = VAL%E6666
!       ! E6 x E666 -> E6666 (73, 51)
!       RES(1+NROWS*72:NROWS*73,1+NCOLS*50:NCOLS*51) = VAL%E6
!       ! E666 x E6 -> E6666 (73, 7)
!       RES(1+NROWS*72:NROWS*73,1+NCOLS*6:NCOLS*7) = VAL%E666
!       ! E66 x E66 -> E6666 (73, 29)
!       RES(1+NROWS*72:NROWS*73,1+NCOLS*28:NCOLS*29) = VAL%E66
!       ! R x E7777 -> E7777 (74, 74)
!       RES(1+NROWS*73:NROWS*74,1+NCOLS*73:NCOLS*74) = VAL%R
!       ! E7777 x R -> E7777 (74, 1)
!       RES(1+NROWS*73:NROWS*74,1+NCOLS*0:NCOLS*1) = VAL%E7777
!       ! E7 x E777 -> E7777 (74, 52)
!       RES(1+NROWS*73:NROWS*74,1+NCOLS*51:NCOLS*52) = VAL%E7
!       ! E777 x E7 -> E7777 (74, 8)
!       RES(1+NROWS*73:NROWS*74,1+NCOLS*7:NCOLS*8) = VAL%E777
!       ! E77 x E77 -> E7777 (74, 30)
!       RES(1+NROWS*73:NROWS*74,1+NCOLS*29:NCOLS*30) = VAL%E77
!       ! R x E8888 -> E8888 (75, 75)
!       RES(1+NROWS*74:NROWS*75,1+NCOLS*74:NCOLS*75) = VAL%R
!       ! E8888 x R -> E8888 (75, 1)
!       RES(1+NROWS*74:NROWS*75,1+NCOLS*0:NCOLS*1) = VAL%E8888
!       ! E8 x E888 -> E8888 (75, 53)
!       RES(1+NROWS*74:NROWS*75,1+NCOLS*52:NCOLS*53) = VAL%E8
!       ! E888 x E8 -> E8888 (75, 9)
!       RES(1+NROWS*74:NROWS*75,1+NCOLS*8:NCOLS*9) = VAL%E888
!       ! E88 x E88 -> E8888 (75, 31)
!       RES(1+NROWS*74:NROWS*75,1+NCOLS*30:NCOLS*31) = VAL%E88
!       ! R x E9999 -> E9999 (76, 76)
!       RES(1+NROWS*75:NROWS*76,1+NCOLS*75:NCOLS*76) = VAL%R
!       ! E9999 x R -> E9999 (76, 1)
!       RES(1+NROWS*75:NROWS*76,1+NCOLS*0:NCOLS*1) = VAL%E9999
!       ! E9 x E999 -> E9999 (76, 54)
!       RES(1+NROWS*75:NROWS*76,1+NCOLS*53:NCOLS*54) = VAL%E9
!       ! E999 x E9 -> E9999 (76, 10)
!       RES(1+NROWS*75:NROWS*76,1+NCOLS*9:NCOLS*10) = VAL%E999
!       ! E99 x E99 -> E9999 (76, 32)
!       RES(1+NROWS*75:NROWS*76,1+NCOLS*31:NCOLS*32) = VAL%E99
!       ! R x EAAAA -> EAAAA (77, 77)
!       RES(1+NROWS*76:NROWS*77,1+NCOLS*76:NCOLS*77) = VAL%R
!       ! EAAAA x R -> EAAAA (77, 1)
!       RES(1+NROWS*76:NROWS*77,1+NCOLS*0:NCOLS*1) = VAL%EAAAA
!       ! EA x EAAA -> EAAAA (77, 55)
!       RES(1+NROWS*76:NROWS*77,1+NCOLS*54:NCOLS*55) = VAL%EA
!       ! EAAA x EA -> EAAAA (77, 11)
!       RES(1+NROWS*76:NROWS*77,1+NCOLS*10:NCOLS*11) = VAL%EAAA
!       ! EAA x EAA -> EAAAA (77, 33)
!       RES(1+NROWS*76:NROWS*77,1+NCOLS*32:NCOLS*33) = VAL%EAA
!       ! R x EBBBB -> EBBBB (78, 78)
!       RES(1+NROWS*77:NROWS*78,1+NCOLS*77:NCOLS*78) = VAL%R
!       ! EBBBB x R -> EBBBB (78, 1)
!       RES(1+NROWS*77:NROWS*78,1+NCOLS*0:NCOLS*1) = VAL%EBBBB
!       ! EB x EBBB -> EBBBB (78, 56)
!       RES(1+NROWS*77:NROWS*78,1+NCOLS*55:NCOLS*56) = VAL%EB
!       ! EBBB x EB -> EBBBB (78, 12)
!       RES(1+NROWS*77:NROWS*78,1+NCOLS*11:NCOLS*12) = VAL%EBBB
!       ! EBB x EBB -> EBBBB (78, 34)
!       RES(1+NROWS*77:NROWS*78,1+NCOLS*33:NCOLS*34) = VAL%EBB
!       ! R x ECCCC -> ECCCC (79, 79)
!       RES(1+NROWS*78:NROWS*79,1+NCOLS*78:NCOLS*79) = VAL%R
!       ! ECCCC x R -> ECCCC (79, 1)
!       RES(1+NROWS*78:NROWS*79,1+NCOLS*0:NCOLS*1) = VAL%ECCCC
!       ! EC x ECCC -> ECCCC (79, 57)
!       RES(1+NROWS*78:NROWS*79,1+NCOLS*56:NCOLS*57) = VAL%EC
!       ! ECCC x EC -> ECCCC (79, 13)
!       RES(1+NROWS*78:NROWS*79,1+NCOLS*12:NCOLS*13) = VAL%ECCC
!       ! ECC x ECC -> ECCCC (79, 35)
!       RES(1+NROWS*78:NROWS*79,1+NCOLS*34:NCOLS*35) = VAL%ECC
!       ! R x EDDDD -> EDDDD (80, 80)
!       RES(1+NROWS*79:NROWS*80,1+NCOLS*79:NCOLS*80) = VAL%R
!       ! EDDDD x R -> EDDDD (80, 1)
!       RES(1+NROWS*79:NROWS*80,1+NCOLS*0:NCOLS*1) = VAL%EDDDD
!       ! ED x EDDD -> EDDDD (80, 58)
!       RES(1+NROWS*79:NROWS*80,1+NCOLS*57:NCOLS*58) = VAL%ED
!       ! EDDD x ED -> EDDDD (80, 14)
!       RES(1+NROWS*79:NROWS*80,1+NCOLS*13:NCOLS*14) = VAL%EDDD
!       ! EDD x EDD -> EDDDD (80, 36)
!       RES(1+NROWS*79:NROWS*80,1+NCOLS*35:NCOLS*36) = VAL%EDD
!       ! R x EEEEE -> EEEEE (81, 81)
!       RES(1+NROWS*80:NROWS*81,1+NCOLS*80:NCOLS*81) = VAL%R
!       ! EEEEE x R -> EEEEE (81, 1)
!       RES(1+NROWS*80:NROWS*81,1+NCOLS*0:NCOLS*1) = VAL%EEEEE
!       ! EE x EEEE -> EEEEE (81, 59)
!       RES(1+NROWS*80:NROWS*81,1+NCOLS*58:NCOLS*59) = VAL%EE
!       ! EEEE x EE -> EEEEE (81, 15)
!       RES(1+NROWS*80:NROWS*81,1+NCOLS*14:NCOLS*15) = VAL%EEEE
!       ! EEE x EEE -> EEEEE (81, 37)
!       RES(1+NROWS*80:NROWS*81,1+NCOLS*36:NCOLS*37) = VAL%EEE
!       ! R x EFFFF -> EFFFF (82, 82)
!       RES(1+NROWS*81:NROWS*82,1+NCOLS*81:NCOLS*82) = VAL%R
!       ! EFFFF x R -> EFFFF (82, 1)
!       RES(1+NROWS*81:NROWS*82,1+NCOLS*0:NCOLS*1) = VAL%EFFFF
!       ! EF x EFFF -> EFFFF (82, 60)
!       RES(1+NROWS*81:NROWS*82,1+NCOLS*59:NCOLS*60) = VAL%EF
!       ! EFFF x EF -> EFFFF (82, 16)
!       RES(1+NROWS*81:NROWS*82,1+NCOLS*15:NCOLS*16) = VAL%EFFF
!       ! EFF x EFF -> EFFFF (82, 38)
!       RES(1+NROWS*81:NROWS*82,1+NCOLS*37:NCOLS*38) = VAL%EFF
!       ! R x EGGGG -> EGGGG (83, 83)
!       RES(1+NROWS*82:NROWS*83,1+NCOLS*82:NCOLS*83) = VAL%R
!       ! EGGGG x R -> EGGGG (83, 1)
!       RES(1+NROWS*82:NROWS*83,1+NCOLS*0:NCOLS*1) = VAL%EGGGG
!       ! EG x EGGG -> EGGGG (83, 61)
!       RES(1+NROWS*82:NROWS*83,1+NCOLS*60:NCOLS*61) = VAL%EG
!       ! EGGG x EG -> EGGGG (83, 17)
!       RES(1+NROWS*82:NROWS*83,1+NCOLS*16:NCOLS*17) = VAL%EGGG
!       ! EGG x EGG -> EGGGG (83, 39)
!       RES(1+NROWS*82:NROWS*83,1+NCOLS*38:NCOLS*39) = VAL%EGG
!       ! R x EHHHH -> EHHHH (84, 84)
!       RES(1+NROWS*83:NROWS*84,1+NCOLS*83:NCOLS*84) = VAL%R
!       ! EHHHH x R -> EHHHH (84, 1)
!       RES(1+NROWS*83:NROWS*84,1+NCOLS*0:NCOLS*1) = VAL%EHHHH
!       ! EH x EHHH -> EHHHH (84, 62)
!       RES(1+NROWS*83:NROWS*84,1+NCOLS*61:NCOLS*62) = VAL%EH
!       ! EHHH x EH -> EHHHH (84, 18)
!       RES(1+NROWS*83:NROWS*84,1+NCOLS*17:NCOLS*18) = VAL%EHHH
!       ! EHH x EHH -> EHHHH (84, 40)
!       RES(1+NROWS*83:NROWS*84,1+NCOLS*39:NCOLS*40) = VAL%EHH
!       ! R x EIIII -> EIIII (85, 85)
!       RES(1+NROWS*84:NROWS*85,1+NCOLS*84:NCOLS*85) = VAL%R
!       ! EIIII x R -> EIIII (85, 1)
!       RES(1+NROWS*84:NROWS*85,1+NCOLS*0:NCOLS*1) = VAL%EIIII
!       ! EI x EIII -> EIIII (85, 63)
!       RES(1+NROWS*84:NROWS*85,1+NCOLS*62:NCOLS*63) = VAL%EI
!       ! EIII x EI -> EIIII (85, 19)
!       RES(1+NROWS*84:NROWS*85,1+NCOLS*18:NCOLS*19) = VAL%EIII
!       ! EII x EII -> EIIII (85, 41)
!       RES(1+NROWS*84:NROWS*85,1+NCOLS*40:NCOLS*41) = VAL%EII
!       ! R x EJJJJ -> EJJJJ (86, 86)
!       RES(1+NROWS*85:NROWS*86,1+NCOLS*85:NCOLS*86) = VAL%R
!       ! EJJJJ x R -> EJJJJ (86, 1)
!       RES(1+NROWS*85:NROWS*86,1+NCOLS*0:NCOLS*1) = VAL%EJJJJ
!       ! EJ x EJJJ -> EJJJJ (86, 64)
!       RES(1+NROWS*85:NROWS*86,1+NCOLS*63:NCOLS*64) = VAL%EJ
!       ! EJJJ x EJ -> EJJJJ (86, 20)
!       RES(1+NROWS*85:NROWS*86,1+NCOLS*19:NCOLS*20) = VAL%EJJJ
!       ! EJJ x EJJ -> EJJJJ (86, 42)
!       RES(1+NROWS*85:NROWS*86,1+NCOLS*41:NCOLS*42) = VAL%EJJ
!       ! R x EKKKK -> EKKKK (87, 87)
!       RES(1+NROWS*86:NROWS*87,1+NCOLS*86:NCOLS*87) = VAL%R
!       ! EKKKK x R -> EKKKK (87, 1)
!       RES(1+NROWS*86:NROWS*87,1+NCOLS*0:NCOLS*1) = VAL%EKKKK
!       ! EK x EKKK -> EKKKK (87, 65)
!       RES(1+NROWS*86:NROWS*87,1+NCOLS*64:NCOLS*65) = VAL%EK
!       ! EKKK x EK -> EKKKK (87, 21)
!       RES(1+NROWS*86:NROWS*87,1+NCOLS*20:NCOLS*21) = VAL%EKKK
!       ! EKK x EKK -> EKKKK (87, 43)
!       RES(1+NROWS*86:NROWS*87,1+NCOLS*42:NCOLS*43) = VAL%EKK
!       ! R x ELLLL -> ELLLL (88, 88)
!       RES(1+NROWS*87:NROWS*88,1+NCOLS*87:NCOLS*88) = VAL%R
!       ! ELLLL x R -> ELLLL (88, 1)
!       RES(1+NROWS*87:NROWS*88,1+NCOLS*0:NCOLS*1) = VAL%ELLLL
!       ! EL x ELLL -> ELLLL (88, 66)
!       RES(1+NROWS*87:NROWS*88,1+NCOLS*65:NCOLS*66) = VAL%EL
!       ! ELLL x EL -> ELLLL (88, 22)
!       RES(1+NROWS*87:NROWS*88,1+NCOLS*21:NCOLS*22) = VAL%ELLL
!       ! ELL x ELL -> ELLLL (88, 44)
!       RES(1+NROWS*87:NROWS*88,1+NCOLS*43:NCOLS*44) = VAL%ELL
!       ! R x EMMMM -> EMMMM (89, 89)
!       RES(1+NROWS*88:NROWS*89,1+NCOLS*88:NCOLS*89) = VAL%R
!       ! EMMMM x R -> EMMMM (89, 1)
!       RES(1+NROWS*88:NROWS*89,1+NCOLS*0:NCOLS*1) = VAL%EMMMM
!       ! EM x EMMM -> EMMMM (89, 67)
!       RES(1+NROWS*88:NROWS*89,1+NCOLS*66:NCOLS*67) = VAL%EM
!       ! EMMM x EM -> EMMMM (89, 23)
!       RES(1+NROWS*88:NROWS*89,1+NCOLS*22:NCOLS*23) = VAL%EMMM
!       ! EMM x EMM -> EMMMM (89, 45)
!       RES(1+NROWS*88:NROWS*89,1+NCOLS*44:NCOLS*45) = VAL%EMM
!       ! R x E11111 -> E11111 (90, 90)
!       RES(1+NROWS*89:NROWS*90,1+NCOLS*89:NCOLS*90) = VAL%R
!       ! E11111 x R -> E11111 (90, 1)
!       RES(1+NROWS*89:NROWS*90,1+NCOLS*0:NCOLS*1) = VAL%E11111
!       ! E1 x E1111 -> E11111 (90, 68)
!       RES(1+NROWS*89:NROWS*90,1+NCOLS*67:NCOLS*68) = VAL%E1
!       ! E1111 x E1 -> E11111 (90, 2)
!       RES(1+NROWS*89:NROWS*90,1+NCOLS*1:NCOLS*2) = VAL%E1111
!       ! E11 x E111 -> E11111 (90, 46)
!       RES(1+NROWS*89:NROWS*90,1+NCOLS*45:NCOLS*46) = VAL%E11
!       ! E111 x E11 -> E11111 (90, 24)
!       RES(1+NROWS*89:NROWS*90,1+NCOLS*23:NCOLS*24) = VAL%E111
!       ! R x E22222 -> E22222 (91, 91)
!       RES(1+NROWS*90:NROWS*91,1+NCOLS*90:NCOLS*91) = VAL%R
!       ! E22222 x R -> E22222 (91, 1)
!       RES(1+NROWS*90:NROWS*91,1+NCOLS*0:NCOLS*1) = VAL%E22222
!       ! E2 x E2222 -> E22222 (91, 69)
!       RES(1+NROWS*90:NROWS*91,1+NCOLS*68:NCOLS*69) = VAL%E2
!       ! E2222 x E2 -> E22222 (91, 3)
!       RES(1+NROWS*90:NROWS*91,1+NCOLS*2:NCOLS*3) = VAL%E2222
!       ! E22 x E222 -> E22222 (91, 47)
!       RES(1+NROWS*90:NROWS*91,1+NCOLS*46:NCOLS*47) = VAL%E22
!       ! E222 x E22 -> E22222 (91, 25)
!       RES(1+NROWS*90:NROWS*91,1+NCOLS*24:NCOLS*25) = VAL%E222
!       ! R x E33333 -> E33333 (92, 92)
!       RES(1+NROWS*91:NROWS*92,1+NCOLS*91:NCOLS*92) = VAL%R
!       ! E33333 x R -> E33333 (92, 1)
!       RES(1+NROWS*91:NROWS*92,1+NCOLS*0:NCOLS*1) = VAL%E33333
!       ! E3 x E3333 -> E33333 (92, 70)
!       RES(1+NROWS*91:NROWS*92,1+NCOLS*69:NCOLS*70) = VAL%E3
!       ! E3333 x E3 -> E33333 (92, 4)
!       RES(1+NROWS*91:NROWS*92,1+NCOLS*3:NCOLS*4) = VAL%E3333
!       ! E33 x E333 -> E33333 (92, 48)
!       RES(1+NROWS*91:NROWS*92,1+NCOLS*47:NCOLS*48) = VAL%E33
!       ! E333 x E33 -> E33333 (92, 26)
!       RES(1+NROWS*91:NROWS*92,1+NCOLS*25:NCOLS*26) = VAL%E333
!       ! R x E44444 -> E44444 (93, 93)
!       RES(1+NROWS*92:NROWS*93,1+NCOLS*92:NCOLS*93) = VAL%R
!       ! E44444 x R -> E44444 (93, 1)
!       RES(1+NROWS*92:NROWS*93,1+NCOLS*0:NCOLS*1) = VAL%E44444
!       ! E4 x E4444 -> E44444 (93, 71)
!       RES(1+NROWS*92:NROWS*93,1+NCOLS*70:NCOLS*71) = VAL%E4
!       ! E4444 x E4 -> E44444 (93, 5)
!       RES(1+NROWS*92:NROWS*93,1+NCOLS*4:NCOLS*5) = VAL%E4444
!       ! E44 x E444 -> E44444 (93, 49)
!       RES(1+NROWS*92:NROWS*93,1+NCOLS*48:NCOLS*49) = VAL%E44
!       ! E444 x E44 -> E44444 (93, 27)
!       RES(1+NROWS*92:NROWS*93,1+NCOLS*26:NCOLS*27) = VAL%E444
!       ! R x E55555 -> E55555 (94, 94)
!       RES(1+NROWS*93:NROWS*94,1+NCOLS*93:NCOLS*94) = VAL%R
!       ! E55555 x R -> E55555 (94, 1)
!       RES(1+NROWS*93:NROWS*94,1+NCOLS*0:NCOLS*1) = VAL%E55555
!       ! E5 x E5555 -> E55555 (94, 72)
!       RES(1+NROWS*93:NROWS*94,1+NCOLS*71:NCOLS*72) = VAL%E5
!       ! E5555 x E5 -> E55555 (94, 6)
!       RES(1+NROWS*93:NROWS*94,1+NCOLS*5:NCOLS*6) = VAL%E5555
!       ! E55 x E555 -> E55555 (94, 50)
!       RES(1+NROWS*93:NROWS*94,1+NCOLS*49:NCOLS*50) = VAL%E55
!       ! E555 x E55 -> E55555 (94, 28)
!       RES(1+NROWS*93:NROWS*94,1+NCOLS*27:NCOLS*28) = VAL%E555
!       ! R x E66666 -> E66666 (95, 95)
!       RES(1+NROWS*94:NROWS*95,1+NCOLS*94:NCOLS*95) = VAL%R
!       ! E66666 x R -> E66666 (95, 1)
!       RES(1+NROWS*94:NROWS*95,1+NCOLS*0:NCOLS*1) = VAL%E66666
!       ! E6 x E6666 -> E66666 (95, 73)
!       RES(1+NROWS*94:NROWS*95,1+NCOLS*72:NCOLS*73) = VAL%E6
!       ! E6666 x E6 -> E66666 (95, 7)
!       RES(1+NROWS*94:NROWS*95,1+NCOLS*6:NCOLS*7) = VAL%E6666
!       ! E66 x E666 -> E66666 (95, 51)
!       RES(1+NROWS*94:NROWS*95,1+NCOLS*50:NCOLS*51) = VAL%E66
!       ! E666 x E66 -> E66666 (95, 29)
!       RES(1+NROWS*94:NROWS*95,1+NCOLS*28:NCOLS*29) = VAL%E666
!       ! R x E77777 -> E77777 (96, 96)
!       RES(1+NROWS*95:NROWS*96,1+NCOLS*95:NCOLS*96) = VAL%R
!       ! E77777 x R -> E77777 (96, 1)
!       RES(1+NROWS*95:NROWS*96,1+NCOLS*0:NCOLS*1) = VAL%E77777
!       ! E7 x E7777 -> E77777 (96, 74)
!       RES(1+NROWS*95:NROWS*96,1+NCOLS*73:NCOLS*74) = VAL%E7
!       ! E7777 x E7 -> E77777 (96, 8)
!       RES(1+NROWS*95:NROWS*96,1+NCOLS*7:NCOLS*8) = VAL%E7777
!       ! E77 x E777 -> E77777 (96, 52)
!       RES(1+NROWS*95:NROWS*96,1+NCOLS*51:NCOLS*52) = VAL%E77
!       ! E777 x E77 -> E77777 (96, 30)
!       RES(1+NROWS*95:NROWS*96,1+NCOLS*29:NCOLS*30) = VAL%E777
!       ! R x E88888 -> E88888 (97, 97)
!       RES(1+NROWS*96:NROWS*97,1+NCOLS*96:NCOLS*97) = VAL%R
!       ! E88888 x R -> E88888 (97, 1)
!       RES(1+NROWS*96:NROWS*97,1+NCOLS*0:NCOLS*1) = VAL%E88888
!       ! E8 x E8888 -> E88888 (97, 75)
!       RES(1+NROWS*96:NROWS*97,1+NCOLS*74:NCOLS*75) = VAL%E8
!       ! E8888 x E8 -> E88888 (97, 9)
!       RES(1+NROWS*96:NROWS*97,1+NCOLS*8:NCOLS*9) = VAL%E8888
!       ! E88 x E888 -> E88888 (97, 53)
!       RES(1+NROWS*96:NROWS*97,1+NCOLS*52:NCOLS*53) = VAL%E88
!       ! E888 x E88 -> E88888 (97, 31)
!       RES(1+NROWS*96:NROWS*97,1+NCOLS*30:NCOLS*31) = VAL%E888
!       ! R x E99999 -> E99999 (98, 98)
!       RES(1+NROWS*97:NROWS*98,1+NCOLS*97:NCOLS*98) = VAL%R
!       ! E99999 x R -> E99999 (98, 1)
!       RES(1+NROWS*97:NROWS*98,1+NCOLS*0:NCOLS*1) = VAL%E99999
!       ! E9 x E9999 -> E99999 (98, 76)
!       RES(1+NROWS*97:NROWS*98,1+NCOLS*75:NCOLS*76) = VAL%E9
!       ! E9999 x E9 -> E99999 (98, 10)
!       RES(1+NROWS*97:NROWS*98,1+NCOLS*9:NCOLS*10) = VAL%E9999
!       ! E99 x E999 -> E99999 (98, 54)
!       RES(1+NROWS*97:NROWS*98,1+NCOLS*53:NCOLS*54) = VAL%E99
!       ! E999 x E99 -> E99999 (98, 32)
!       RES(1+NROWS*97:NROWS*98,1+NCOLS*31:NCOLS*32) = VAL%E999
!       ! R x EAAAAA -> EAAAAA (99, 99)
!       RES(1+NROWS*98:NROWS*99,1+NCOLS*98:NCOLS*99) = VAL%R
!       ! EAAAAA x R -> EAAAAA (99, 1)
!       RES(1+NROWS*98:NROWS*99,1+NCOLS*0:NCOLS*1) = VAL%EAAAAA
!       ! EA x EAAAA -> EAAAAA (99, 77)
!       RES(1+NROWS*98:NROWS*99,1+NCOLS*76:NCOLS*77) = VAL%EA
!       ! EAAAA x EA -> EAAAAA (99, 11)
!       RES(1+NROWS*98:NROWS*99,1+NCOLS*10:NCOLS*11) = VAL%EAAAA
!       ! EAA x EAAA -> EAAAAA (99, 55)
!       RES(1+NROWS*98:NROWS*99,1+NCOLS*54:NCOLS*55) = VAL%EAA
!       ! EAAA x EAA -> EAAAAA (99, 33)
!       RES(1+NROWS*98:NROWS*99,1+NCOLS*32:NCOLS*33) = VAL%EAAA
!       ! R x EBBBBB -> EBBBBB (100, 100)
!       RES(1+NROWS*99:NROWS*100,1+NCOLS*99:NCOLS*100) = VAL%R
!       ! EBBBBB x R -> EBBBBB (100, 1)
!       RES(1+NROWS*99:NROWS*100,1+NCOLS*0:NCOLS*1) = VAL%EBBBBB
!       ! EB x EBBBB -> EBBBBB (100, 78)
!       RES(1+NROWS*99:NROWS*100,1+NCOLS*77:NCOLS*78) = VAL%EB
!       ! EBBBB x EB -> EBBBBB (100, 12)
!       RES(1+NROWS*99:NROWS*100,1+NCOLS*11:NCOLS*12) = VAL%EBBBB
!       ! EBB x EBBB -> EBBBBB (100, 56)
!       RES(1+NROWS*99:NROWS*100,1+NCOLS*55:NCOLS*56) = VAL%EBB
!       ! EBBB x EBB -> EBBBBB (100, 34)
!       RES(1+NROWS*99:NROWS*100,1+NCOLS*33:NCOLS*34) = VAL%EBBB
!       ! R x ECCCCC -> ECCCCC (101, 101)
!       RES(1+NROWS*100:NROWS*101,1+NCOLS*100:NCOLS*101) = VAL%R
!       ! ECCCCC x R -> ECCCCC (101, 1)
!       RES(1+NROWS*100:NROWS*101,1+NCOLS*0:NCOLS*1) = VAL%ECCCCC
!       ! EC x ECCCC -> ECCCCC (101, 79)
!       RES(1+NROWS*100:NROWS*101,1+NCOLS*78:NCOLS*79) = VAL%EC
!       ! ECCCC x EC -> ECCCCC (101, 13)
!       RES(1+NROWS*100:NROWS*101,1+NCOLS*12:NCOLS*13) = VAL%ECCCC
!       ! ECC x ECCC -> ECCCCC (101, 57)
!       RES(1+NROWS*100:NROWS*101,1+NCOLS*56:NCOLS*57) = VAL%ECC
!       ! ECCC x ECC -> ECCCCC (101, 35)
!       RES(1+NROWS*100:NROWS*101,1+NCOLS*34:NCOLS*35) = VAL%ECCC
!       ! R x EDDDDD -> EDDDDD (102, 102)
!       RES(1+NROWS*101:NROWS*102,1+NCOLS*101:NCOLS*102) = VAL%R
!       ! EDDDDD x R -> EDDDDD (102, 1)
!       RES(1+NROWS*101:NROWS*102,1+NCOLS*0:NCOLS*1) = VAL%EDDDDD
!       ! ED x EDDDD -> EDDDDD (102, 80)
!       RES(1+NROWS*101:NROWS*102,1+NCOLS*79:NCOLS*80) = VAL%ED
!       ! EDDDD x ED -> EDDDDD (102, 14)
!       RES(1+NROWS*101:NROWS*102,1+NCOLS*13:NCOLS*14) = VAL%EDDDD
!       ! EDD x EDDD -> EDDDDD (102, 58)
!       RES(1+NROWS*101:NROWS*102,1+NCOLS*57:NCOLS*58) = VAL%EDD
!       ! EDDD x EDD -> EDDDDD (102, 36)
!       RES(1+NROWS*101:NROWS*102,1+NCOLS*35:NCOLS*36) = VAL%EDDD
!       ! R x EEEEEE -> EEEEEE (103, 103)
!       RES(1+NROWS*102:NROWS*103,1+NCOLS*102:NCOLS*103) = VAL%R
!       ! EEEEEE x R -> EEEEEE (103, 1)
!       RES(1+NROWS*102:NROWS*103,1+NCOLS*0:NCOLS*1) = VAL%EEEEEE
!       ! EE x EEEEE -> EEEEEE (103, 81)
!       RES(1+NROWS*102:NROWS*103,1+NCOLS*80:NCOLS*81) = VAL%EE
!       ! EEEEE x EE -> EEEEEE (103, 15)
!       RES(1+NROWS*102:NROWS*103,1+NCOLS*14:NCOLS*15) = VAL%EEEEE
!       ! EEE x EEEE -> EEEEEE (103, 59)
!       RES(1+NROWS*102:NROWS*103,1+NCOLS*58:NCOLS*59) = VAL%EEE
!       ! EEEE x EEE -> EEEEEE (103, 37)
!       RES(1+NROWS*102:NROWS*103,1+NCOLS*36:NCOLS*37) = VAL%EEEE
!       ! R x EFFFFF -> EFFFFF (104, 104)
!       RES(1+NROWS*103:NROWS*104,1+NCOLS*103:NCOLS*104) = VAL%R
!       ! EFFFFF x R -> EFFFFF (104, 1)
!       RES(1+NROWS*103:NROWS*104,1+NCOLS*0:NCOLS*1) = VAL%EFFFFF
!       ! EF x EFFFF -> EFFFFF (104, 82)
!       RES(1+NROWS*103:NROWS*104,1+NCOLS*81:NCOLS*82) = VAL%EF
!       ! EFFFF x EF -> EFFFFF (104, 16)
!       RES(1+NROWS*103:NROWS*104,1+NCOLS*15:NCOLS*16) = VAL%EFFFF
!       ! EFF x EFFF -> EFFFFF (104, 60)
!       RES(1+NROWS*103:NROWS*104,1+NCOLS*59:NCOLS*60) = VAL%EFF
!       ! EFFF x EFF -> EFFFFF (104, 38)
!       RES(1+NROWS*103:NROWS*104,1+NCOLS*37:NCOLS*38) = VAL%EFFF
!       ! R x EGGGGG -> EGGGGG (105, 105)
!       RES(1+NROWS*104:NROWS*105,1+NCOLS*104:NCOLS*105) = VAL%R
!       ! EGGGGG x R -> EGGGGG (105, 1)
!       RES(1+NROWS*104:NROWS*105,1+NCOLS*0:NCOLS*1) = VAL%EGGGGG
!       ! EG x EGGGG -> EGGGGG (105, 83)
!       RES(1+NROWS*104:NROWS*105,1+NCOLS*82:NCOLS*83) = VAL%EG
!       ! EGGGG x EG -> EGGGGG (105, 17)
!       RES(1+NROWS*104:NROWS*105,1+NCOLS*16:NCOLS*17) = VAL%EGGGG
!       ! EGG x EGGG -> EGGGGG (105, 61)
!       RES(1+NROWS*104:NROWS*105,1+NCOLS*60:NCOLS*61) = VAL%EGG
!       ! EGGG x EGG -> EGGGGG (105, 39)
!       RES(1+NROWS*104:NROWS*105,1+NCOLS*38:NCOLS*39) = VAL%EGGG
!       ! R x EHHHHH -> EHHHHH (106, 106)
!       RES(1+NROWS*105:NROWS*106,1+NCOLS*105:NCOLS*106) = VAL%R
!       ! EHHHHH x R -> EHHHHH (106, 1)
!       RES(1+NROWS*105:NROWS*106,1+NCOLS*0:NCOLS*1) = VAL%EHHHHH
!       ! EH x EHHHH -> EHHHHH (106, 84)
!       RES(1+NROWS*105:NROWS*106,1+NCOLS*83:NCOLS*84) = VAL%EH
!       ! EHHHH x EH -> EHHHHH (106, 18)
!       RES(1+NROWS*105:NROWS*106,1+NCOLS*17:NCOLS*18) = VAL%EHHHH
!       ! EHH x EHHH -> EHHHHH (106, 62)
!       RES(1+NROWS*105:NROWS*106,1+NCOLS*61:NCOLS*62) = VAL%EHH
!       ! EHHH x EHH -> EHHHHH (106, 40)
!       RES(1+NROWS*105:NROWS*106,1+NCOLS*39:NCOLS*40) = VAL%EHHH
!       ! R x EIIIII -> EIIIII (107, 107)
!       RES(1+NROWS*106:NROWS*107,1+NCOLS*106:NCOLS*107) = VAL%R
!       ! EIIIII x R -> EIIIII (107, 1)
!       RES(1+NROWS*106:NROWS*107,1+NCOLS*0:NCOLS*1) = VAL%EIIIII
!       ! EI x EIIII -> EIIIII (107, 85)
!       RES(1+NROWS*106:NROWS*107,1+NCOLS*84:NCOLS*85) = VAL%EI
!       ! EIIII x EI -> EIIIII (107, 19)
!       RES(1+NROWS*106:NROWS*107,1+NCOLS*18:NCOLS*19) = VAL%EIIII
!       ! EII x EIII -> EIIIII (107, 63)
!       RES(1+NROWS*106:NROWS*107,1+NCOLS*62:NCOLS*63) = VAL%EII
!       ! EIII x EII -> EIIIII (107, 41)
!       RES(1+NROWS*106:NROWS*107,1+NCOLS*40:NCOLS*41) = VAL%EIII
!       ! R x EJJJJJ -> EJJJJJ (108, 108)
!       RES(1+NROWS*107:NROWS*108,1+NCOLS*107:NCOLS*108) = VAL%R
!       ! EJJJJJ x R -> EJJJJJ (108, 1)
!       RES(1+NROWS*107:NROWS*108,1+NCOLS*0:NCOLS*1) = VAL%EJJJJJ
!       ! EJ x EJJJJ -> EJJJJJ (108, 86)
!       RES(1+NROWS*107:NROWS*108,1+NCOLS*85:NCOLS*86) = VAL%EJ
!       ! EJJJJ x EJ -> EJJJJJ (108, 20)
!       RES(1+NROWS*107:NROWS*108,1+NCOLS*19:NCOLS*20) = VAL%EJJJJ
!       ! EJJ x EJJJ -> EJJJJJ (108, 64)
!       RES(1+NROWS*107:NROWS*108,1+NCOLS*63:NCOLS*64) = VAL%EJJ
!       ! EJJJ x EJJ -> EJJJJJ (108, 42)
!       RES(1+NROWS*107:NROWS*108,1+NCOLS*41:NCOLS*42) = VAL%EJJJ
!       ! R x EKKKKK -> EKKKKK (109, 109)
!       RES(1+NROWS*108:NROWS*109,1+NCOLS*108:NCOLS*109) = VAL%R
!       ! EKKKKK x R -> EKKKKK (109, 1)
!       RES(1+NROWS*108:NROWS*109,1+NCOLS*0:NCOLS*1) = VAL%EKKKKK
!       ! EK x EKKKK -> EKKKKK (109, 87)
!       RES(1+NROWS*108:NROWS*109,1+NCOLS*86:NCOLS*87) = VAL%EK
!       ! EKKKK x EK -> EKKKKK (109, 21)
!       RES(1+NROWS*108:NROWS*109,1+NCOLS*20:NCOLS*21) = VAL%EKKKK
!       ! EKK x EKKK -> EKKKKK (109, 65)
!       RES(1+NROWS*108:NROWS*109,1+NCOLS*64:NCOLS*65) = VAL%EKK
!       ! EKKK x EKK -> EKKKKK (109, 43)
!       RES(1+NROWS*108:NROWS*109,1+NCOLS*42:NCOLS*43) = VAL%EKKK
!       ! R x ELLLLL -> ELLLLL (110, 110)
!       RES(1+NROWS*109:NROWS*110,1+NCOLS*109:NCOLS*110) = VAL%R
!       ! ELLLLL x R -> ELLLLL (110, 1)
!       RES(1+NROWS*109:NROWS*110,1+NCOLS*0:NCOLS*1) = VAL%ELLLLL
!       ! EL x ELLLL -> ELLLLL (110, 88)
!       RES(1+NROWS*109:NROWS*110,1+NCOLS*87:NCOLS*88) = VAL%EL
!       ! ELLLL x EL -> ELLLLL (110, 22)
!       RES(1+NROWS*109:NROWS*110,1+NCOLS*21:NCOLS*22) = VAL%ELLLL
!       ! ELL x ELLL -> ELLLLL (110, 66)
!       RES(1+NROWS*109:NROWS*110,1+NCOLS*65:NCOLS*66) = VAL%ELL
!       ! ELLL x ELL -> ELLLLL (110, 44)
!       RES(1+NROWS*109:NROWS*110,1+NCOLS*43:NCOLS*44) = VAL%ELLL
!       ! R x EMMMMM -> EMMMMM (111, 111)
!       RES(1+NROWS*110:NROWS*111,1+NCOLS*110:NCOLS*111) = VAL%R
!       ! EMMMMM x R -> EMMMMM (111, 1)
!       RES(1+NROWS*110:NROWS*111,1+NCOLS*0:NCOLS*1) = VAL%EMMMMM
!       ! EM x EMMMM -> EMMMMM (111, 89)
!       RES(1+NROWS*110:NROWS*111,1+NCOLS*88:NCOLS*89) = VAL%EM
!       ! EMMMM x EM -> EMMMMM (111, 23)
!       RES(1+NROWS*110:NROWS*111,1+NCOLS*22:NCOLS*23) = VAL%EMMMM
!       ! EMM x EMMM -> EMMMMM (111, 67)
!       RES(1+NROWS*110:NROWS*111,1+NCOLS*66:NCOLS*67) = VAL%EMM
!       ! EMMM x EMM -> EMMMMM (111, 45)
!       RES(1+NROWS*110:NROWS*111,1+NCOLS*44:NCOLS*45) = VAL%EMMM
!    END FUNCTION DONUMM22N5_TO_CR_MAT_M

      SUBROUTINE DONUMM22N5_SETIM_S(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(INOUT) :: VAL
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

      ! Order 3
      CASE(45)
         VAL%E111=RES
      CASE(46)
         VAL%E222=RES
      CASE(47)
         VAL%E333=RES
      CASE(48)
         VAL%E444=RES
      CASE(49)
         VAL%E555=RES
      CASE(50)
         VAL%E666=RES
      CASE(51)
         VAL%E777=RES
      CASE(52)
         VAL%E888=RES
      CASE(53)
         VAL%E999=RES
      CASE(54)
         VAL%EAAA=RES
      CASE(55)
         VAL%EBBB=RES
      CASE(56)
         VAL%ECCC=RES
      CASE(57)
         VAL%EDDD=RES
      CASE(58)
         VAL%EEEE=RES
      CASE(59)
         VAL%EFFF=RES
      CASE(60)
         VAL%EGGG=RES
      CASE(61)
         VAL%EHHH=RES
      CASE(62)
         VAL%EIII=RES
      CASE(63)
         VAL%EJJJ=RES
      CASE(64)
         VAL%EKKK=RES
      CASE(65)
         VAL%ELLL=RES
      CASE(66)
         VAL%EMMM=RES

      ! Order 4
      CASE(67)
         VAL%E1111=RES
      CASE(68)
         VAL%E2222=RES
      CASE(69)
         VAL%E3333=RES
      CASE(70)
         VAL%E4444=RES
      CASE(71)
         VAL%E5555=RES
      CASE(72)
         VAL%E6666=RES
      CASE(73)
         VAL%E7777=RES
      CASE(74)
         VAL%E8888=RES
      CASE(75)
         VAL%E9999=RES
      CASE(76)
         VAL%EAAAA=RES
      CASE(77)
         VAL%EBBBB=RES
      CASE(78)
         VAL%ECCCC=RES
      CASE(79)
         VAL%EDDDD=RES
      CASE(80)
         VAL%EEEEE=RES
      CASE(81)
         VAL%EFFFF=RES
      CASE(82)
         VAL%EGGGG=RES
      CASE(83)
         VAL%EHHHH=RES
      CASE(84)
         VAL%EIIII=RES
      CASE(85)
         VAL%EJJJJ=RES
      CASE(86)
         VAL%EKKKK=RES
      CASE(87)
         VAL%ELLLL=RES
      CASE(88)
         VAL%EMMMM=RES

      ! Order 5
      CASE(89)
         VAL%E11111=RES
      CASE(90)
         VAL%E22222=RES
      CASE(91)
         VAL%E33333=RES
      CASE(92)
         VAL%E44444=RES
      CASE(93)
         VAL%E55555=RES
      CASE(94)
         VAL%E66666=RES
      CASE(95)
         VAL%E77777=RES
      CASE(96)
         VAL%E88888=RES
      CASE(97)
         VAL%E99999=RES
      CASE(98)
         VAL%EAAAAA=RES
      CASE(99)
         VAL%EBBBBB=RES
      CASE(100)
         VAL%ECCCCC=RES
      CASE(101)
         VAL%EDDDDD=RES
      CASE(102)
         VAL%EEEEEE=RES
      CASE(103)
         VAL%EFFFFF=RES
      CASE(104)
         VAL%EGGGGG=RES
      CASE(105)
         VAL%EHHHHH=RES
      CASE(106)
         VAL%EIIIII=RES
      CASE(107)
         VAL%EJJJJJ=RES
      CASE(108)
         VAL%EKKKKK=RES
      CASE(109)
         VAL%ELLLLL=RES
      CASE(110)
         VAL%EMMMMM=RES

      END SELECT
   END SUBROUTINE DONUMM22N5_SETIM_S

      SUBROUTINE DONUMM22N5_SETIM_V(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(INOUT) :: VAL(:)
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

      ! Order 3
      CASE(45)
         VAL%E111=RES
      CASE(46)
         VAL%E222=RES
      CASE(47)
         VAL%E333=RES
      CASE(48)
         VAL%E444=RES
      CASE(49)
         VAL%E555=RES
      CASE(50)
         VAL%E666=RES
      CASE(51)
         VAL%E777=RES
      CASE(52)
         VAL%E888=RES
      CASE(53)
         VAL%E999=RES
      CASE(54)
         VAL%EAAA=RES
      CASE(55)
         VAL%EBBB=RES
      CASE(56)
         VAL%ECCC=RES
      CASE(57)
         VAL%EDDD=RES
      CASE(58)
         VAL%EEEE=RES
      CASE(59)
         VAL%EFFF=RES
      CASE(60)
         VAL%EGGG=RES
      CASE(61)
         VAL%EHHH=RES
      CASE(62)
         VAL%EIII=RES
      CASE(63)
         VAL%EJJJ=RES
      CASE(64)
         VAL%EKKK=RES
      CASE(65)
         VAL%ELLL=RES
      CASE(66)
         VAL%EMMM=RES

      ! Order 4
      CASE(67)
         VAL%E1111=RES
      CASE(68)
         VAL%E2222=RES
      CASE(69)
         VAL%E3333=RES
      CASE(70)
         VAL%E4444=RES
      CASE(71)
         VAL%E5555=RES
      CASE(72)
         VAL%E6666=RES
      CASE(73)
         VAL%E7777=RES
      CASE(74)
         VAL%E8888=RES
      CASE(75)
         VAL%E9999=RES
      CASE(76)
         VAL%EAAAA=RES
      CASE(77)
         VAL%EBBBB=RES
      CASE(78)
         VAL%ECCCC=RES
      CASE(79)
         VAL%EDDDD=RES
      CASE(80)
         VAL%EEEEE=RES
      CASE(81)
         VAL%EFFFF=RES
      CASE(82)
         VAL%EGGGG=RES
      CASE(83)
         VAL%EHHHH=RES
      CASE(84)
         VAL%EIIII=RES
      CASE(85)
         VAL%EJJJJ=RES
      CASE(86)
         VAL%EKKKK=RES
      CASE(87)
         VAL%ELLLL=RES
      CASE(88)
         VAL%EMMMM=RES

      ! Order 5
      CASE(89)
         VAL%E11111=RES
      CASE(90)
         VAL%E22222=RES
      CASE(91)
         VAL%E33333=RES
      CASE(92)
         VAL%E44444=RES
      CASE(93)
         VAL%E55555=RES
      CASE(94)
         VAL%E66666=RES
      CASE(95)
         VAL%E77777=RES
      CASE(96)
         VAL%E88888=RES
      CASE(97)
         VAL%E99999=RES
      CASE(98)
         VAL%EAAAAA=RES
      CASE(99)
         VAL%EBBBBB=RES
      CASE(100)
         VAL%ECCCCC=RES
      CASE(101)
         VAL%EDDDDD=RES
      CASE(102)
         VAL%EEEEEE=RES
      CASE(103)
         VAL%EFFFFF=RES
      CASE(104)
         VAL%EGGGGG=RES
      CASE(105)
         VAL%EHHHHH=RES
      CASE(106)
         VAL%EIIIII=RES
      CASE(107)
         VAL%EJJJJJ=RES
      CASE(108)
         VAL%EKKKKK=RES
      CASE(109)
         VAL%ELLLLL=RES
      CASE(110)
         VAL%EMMMMM=RES

      END SELECT
   END SUBROUTINE DONUMM22N5_SETIM_V

      SUBROUTINE DONUMM22N5_SETIM_M(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(INOUT) :: VAL(:,:)
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

      ! Order 3
      CASE(45)
         VAL%E111=RES
      CASE(46)
         VAL%E222=RES
      CASE(47)
         VAL%E333=RES
      CASE(48)
         VAL%E444=RES
      CASE(49)
         VAL%E555=RES
      CASE(50)
         VAL%E666=RES
      CASE(51)
         VAL%E777=RES
      CASE(52)
         VAL%E888=RES
      CASE(53)
         VAL%E999=RES
      CASE(54)
         VAL%EAAA=RES
      CASE(55)
         VAL%EBBB=RES
      CASE(56)
         VAL%ECCC=RES
      CASE(57)
         VAL%EDDD=RES
      CASE(58)
         VAL%EEEE=RES
      CASE(59)
         VAL%EFFF=RES
      CASE(60)
         VAL%EGGG=RES
      CASE(61)
         VAL%EHHH=RES
      CASE(62)
         VAL%EIII=RES
      CASE(63)
         VAL%EJJJ=RES
      CASE(64)
         VAL%EKKK=RES
      CASE(65)
         VAL%ELLL=RES
      CASE(66)
         VAL%EMMM=RES

      ! Order 4
      CASE(67)
         VAL%E1111=RES
      CASE(68)
         VAL%E2222=RES
      CASE(69)
         VAL%E3333=RES
      CASE(70)
         VAL%E4444=RES
      CASE(71)
         VAL%E5555=RES
      CASE(72)
         VAL%E6666=RES
      CASE(73)
         VAL%E7777=RES
      CASE(74)
         VAL%E8888=RES
      CASE(75)
         VAL%E9999=RES
      CASE(76)
         VAL%EAAAA=RES
      CASE(77)
         VAL%EBBBB=RES
      CASE(78)
         VAL%ECCCC=RES
      CASE(79)
         VAL%EDDDD=RES
      CASE(80)
         VAL%EEEEE=RES
      CASE(81)
         VAL%EFFFF=RES
      CASE(82)
         VAL%EGGGG=RES
      CASE(83)
         VAL%EHHHH=RES
      CASE(84)
         VAL%EIIII=RES
      CASE(85)
         VAL%EJJJJ=RES
      CASE(86)
         VAL%EKKKK=RES
      CASE(87)
         VAL%ELLLL=RES
      CASE(88)
         VAL%EMMMM=RES

      ! Order 5
      CASE(89)
         VAL%E11111=RES
      CASE(90)
         VAL%E22222=RES
      CASE(91)
         VAL%E33333=RES
      CASE(92)
         VAL%E44444=RES
      CASE(93)
         VAL%E55555=RES
      CASE(94)
         VAL%E66666=RES
      CASE(95)
         VAL%E77777=RES
      CASE(96)
         VAL%E88888=RES
      CASE(97)
         VAL%E99999=RES
      CASE(98)
         VAL%EAAAAA=RES
      CASE(99)
         VAL%EBBBBB=RES
      CASE(100)
         VAL%ECCCCC=RES
      CASE(101)
         VAL%EDDDDD=RES
      CASE(102)
         VAL%EEEEEE=RES
      CASE(103)
         VAL%EFFFFF=RES
      CASE(104)
         VAL%EGGGGG=RES
      CASE(105)
         VAL%EHHHHH=RES
      CASE(106)
         VAL%EIIIII=RES
      CASE(107)
         VAL%EJJJJJ=RES
      CASE(108)
         VAL%EKKKKK=RES
      CASE(109)
         VAL%ELLLLL=RES
      CASE(110)
         VAL%EMMMMM=RES

      END SELECT
   END SUBROUTINE DONUMM22N5_SETIM_M

FUNCTION DONUMM22N5_GETIM_S(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: VAL
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

      ! Order 3
      CASE(45)
         RES=VAL%E111
      CASE(46)
         RES=VAL%E222
      CASE(47)
         RES=VAL%E333
      CASE(48)
         RES=VAL%E444
      CASE(49)
         RES=VAL%E555
      CASE(50)
         RES=VAL%E666
      CASE(51)
         RES=VAL%E777
      CASE(52)
         RES=VAL%E888
      CASE(53)
         RES=VAL%E999
      CASE(54)
         RES=VAL%EAAA
      CASE(55)
         RES=VAL%EBBB
      CASE(56)
         RES=VAL%ECCC
      CASE(57)
         RES=VAL%EDDD
      CASE(58)
         RES=VAL%EEEE
      CASE(59)
         RES=VAL%EFFF
      CASE(60)
         RES=VAL%EGGG
      CASE(61)
         RES=VAL%EHHH
      CASE(62)
         RES=VAL%EIII
      CASE(63)
         RES=VAL%EJJJ
      CASE(64)
         RES=VAL%EKKK
      CASE(65)
         RES=VAL%ELLL
      CASE(66)
         RES=VAL%EMMM

      ! Order 4
      CASE(67)
         RES=VAL%E1111
      CASE(68)
         RES=VAL%E2222
      CASE(69)
         RES=VAL%E3333
      CASE(70)
         RES=VAL%E4444
      CASE(71)
         RES=VAL%E5555
      CASE(72)
         RES=VAL%E6666
      CASE(73)
         RES=VAL%E7777
      CASE(74)
         RES=VAL%E8888
      CASE(75)
         RES=VAL%E9999
      CASE(76)
         RES=VAL%EAAAA
      CASE(77)
         RES=VAL%EBBBB
      CASE(78)
         RES=VAL%ECCCC
      CASE(79)
         RES=VAL%EDDDD
      CASE(80)
         RES=VAL%EEEEE
      CASE(81)
         RES=VAL%EFFFF
      CASE(82)
         RES=VAL%EGGGG
      CASE(83)
         RES=VAL%EHHHH
      CASE(84)
         RES=VAL%EIIII
      CASE(85)
         RES=VAL%EJJJJ
      CASE(86)
         RES=VAL%EKKKK
      CASE(87)
         RES=VAL%ELLLL
      CASE(88)
         RES=VAL%EMMMM

      ! Order 5
      CASE(89)
         RES=VAL%E11111
      CASE(90)
         RES=VAL%E22222
      CASE(91)
         RES=VAL%E33333
      CASE(92)
         RES=VAL%E44444
      CASE(93)
         RES=VAL%E55555
      CASE(94)
         RES=VAL%E66666
      CASE(95)
         RES=VAL%E77777
      CASE(96)
         RES=VAL%E88888
      CASE(97)
         RES=VAL%E99999
      CASE(98)
         RES=VAL%EAAAAA
      CASE(99)
         RES=VAL%EBBBBB
      CASE(100)
         RES=VAL%ECCCCC
      CASE(101)
         RES=VAL%EDDDDD
      CASE(102)
         RES=VAL%EEEEEE
      CASE(103)
         RES=VAL%EFFFFF
      CASE(104)
         RES=VAL%EGGGGG
      CASE(105)
         RES=VAL%EHHHHH
      CASE(106)
         RES=VAL%EIIIII
      CASE(107)
         RES=VAL%EJJJJJ
      CASE(108)
         RES=VAL%EKKKKK
      CASE(109)
         RES=VAL%ELLLLL
      CASE(110)
         RES=VAL%EMMMMM

      END SELECT
   END FUNCTION DONUMM22N5_GETIM_S

FUNCTION DONUMM22N5_GETIM_V(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: VAL(:)
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

      ! Order 3
      CASE(45)
         RES=VAL%E111
      CASE(46)
         RES=VAL%E222
      CASE(47)
         RES=VAL%E333
      CASE(48)
         RES=VAL%E444
      CASE(49)
         RES=VAL%E555
      CASE(50)
         RES=VAL%E666
      CASE(51)
         RES=VAL%E777
      CASE(52)
         RES=VAL%E888
      CASE(53)
         RES=VAL%E999
      CASE(54)
         RES=VAL%EAAA
      CASE(55)
         RES=VAL%EBBB
      CASE(56)
         RES=VAL%ECCC
      CASE(57)
         RES=VAL%EDDD
      CASE(58)
         RES=VAL%EEEE
      CASE(59)
         RES=VAL%EFFF
      CASE(60)
         RES=VAL%EGGG
      CASE(61)
         RES=VAL%EHHH
      CASE(62)
         RES=VAL%EIII
      CASE(63)
         RES=VAL%EJJJ
      CASE(64)
         RES=VAL%EKKK
      CASE(65)
         RES=VAL%ELLL
      CASE(66)
         RES=VAL%EMMM

      ! Order 4
      CASE(67)
         RES=VAL%E1111
      CASE(68)
         RES=VAL%E2222
      CASE(69)
         RES=VAL%E3333
      CASE(70)
         RES=VAL%E4444
      CASE(71)
         RES=VAL%E5555
      CASE(72)
         RES=VAL%E6666
      CASE(73)
         RES=VAL%E7777
      CASE(74)
         RES=VAL%E8888
      CASE(75)
         RES=VAL%E9999
      CASE(76)
         RES=VAL%EAAAA
      CASE(77)
         RES=VAL%EBBBB
      CASE(78)
         RES=VAL%ECCCC
      CASE(79)
         RES=VAL%EDDDD
      CASE(80)
         RES=VAL%EEEEE
      CASE(81)
         RES=VAL%EFFFF
      CASE(82)
         RES=VAL%EGGGG
      CASE(83)
         RES=VAL%EHHHH
      CASE(84)
         RES=VAL%EIIII
      CASE(85)
         RES=VAL%EJJJJ
      CASE(86)
         RES=VAL%EKKKK
      CASE(87)
         RES=VAL%ELLLL
      CASE(88)
         RES=VAL%EMMMM

      ! Order 5
      CASE(89)
         RES=VAL%E11111
      CASE(90)
         RES=VAL%E22222
      CASE(91)
         RES=VAL%E33333
      CASE(92)
         RES=VAL%E44444
      CASE(93)
         RES=VAL%E55555
      CASE(94)
         RES=VAL%E66666
      CASE(95)
         RES=VAL%E77777
      CASE(96)
         RES=VAL%E88888
      CASE(97)
         RES=VAL%E99999
      CASE(98)
         RES=VAL%EAAAAA
      CASE(99)
         RES=VAL%EBBBBB
      CASE(100)
         RES=VAL%ECCCCC
      CASE(101)
         RES=VAL%EDDDDD
      CASE(102)
         RES=VAL%EEEEEE
      CASE(103)
         RES=VAL%EFFFFF
      CASE(104)
         RES=VAL%EGGGGG
      CASE(105)
         RES=VAL%EHHHHH
      CASE(106)
         RES=VAL%EIIIII
      CASE(107)
         RES=VAL%EJJJJJ
      CASE(108)
         RES=VAL%EKKKKK
      CASE(109)
         RES=VAL%ELLLLL
      CASE(110)
         RES=VAL%EMMMMM

      END SELECT
   END FUNCTION DONUMM22N5_GETIM_V

FUNCTION DONUMM22N5_GETIM_M(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: VAL(:,:)
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

      ! Order 3
      CASE(45)
         RES=VAL%E111
      CASE(46)
         RES=VAL%E222
      CASE(47)
         RES=VAL%E333
      CASE(48)
         RES=VAL%E444
      CASE(49)
         RES=VAL%E555
      CASE(50)
         RES=VAL%E666
      CASE(51)
         RES=VAL%E777
      CASE(52)
         RES=VAL%E888
      CASE(53)
         RES=VAL%E999
      CASE(54)
         RES=VAL%EAAA
      CASE(55)
         RES=VAL%EBBB
      CASE(56)
         RES=VAL%ECCC
      CASE(57)
         RES=VAL%EDDD
      CASE(58)
         RES=VAL%EEEE
      CASE(59)
         RES=VAL%EFFF
      CASE(60)
         RES=VAL%EGGG
      CASE(61)
         RES=VAL%EHHH
      CASE(62)
         RES=VAL%EIII
      CASE(63)
         RES=VAL%EJJJ
      CASE(64)
         RES=VAL%EKKK
      CASE(65)
         RES=VAL%ELLL
      CASE(66)
         RES=VAL%EMMM

      ! Order 4
      CASE(67)
         RES=VAL%E1111
      CASE(68)
         RES=VAL%E2222
      CASE(69)
         RES=VAL%E3333
      CASE(70)
         RES=VAL%E4444
      CASE(71)
         RES=VAL%E5555
      CASE(72)
         RES=VAL%E6666
      CASE(73)
         RES=VAL%E7777
      CASE(74)
         RES=VAL%E8888
      CASE(75)
         RES=VAL%E9999
      CASE(76)
         RES=VAL%EAAAA
      CASE(77)
         RES=VAL%EBBBB
      CASE(78)
         RES=VAL%ECCCC
      CASE(79)
         RES=VAL%EDDDD
      CASE(80)
         RES=VAL%EEEEE
      CASE(81)
         RES=VAL%EFFFF
      CASE(82)
         RES=VAL%EGGGG
      CASE(83)
         RES=VAL%EHHHH
      CASE(84)
         RES=VAL%EIIII
      CASE(85)
         RES=VAL%EJJJJ
      CASE(86)
         RES=VAL%EKKKK
      CASE(87)
         RES=VAL%ELLLL
      CASE(88)
         RES=VAL%EMMMM

      ! Order 5
      CASE(89)
         RES=VAL%E11111
      CASE(90)
         RES=VAL%E22222
      CASE(91)
         RES=VAL%E33333
      CASE(92)
         RES=VAL%E44444
      CASE(93)
         RES=VAL%E55555
      CASE(94)
         RES=VAL%E66666
      CASE(95)
         RES=VAL%E77777
      CASE(96)
         RES=VAL%E88888
      CASE(97)
         RES=VAL%E99999
      CASE(98)
         RES=VAL%EAAAAA
      CASE(99)
         RES=VAL%EBBBBB
      CASE(100)
         RES=VAL%ECCCCC
      CASE(101)
         RES=VAL%EDDDDD
      CASE(102)
         RES=VAL%EEEEEE
      CASE(103)
         RES=VAL%EFFFFF
      CASE(104)
         RES=VAL%EGGGGG
      CASE(105)
         RES=VAL%EHHHHH
      CASE(106)
         RES=VAL%EIIIII
      CASE(107)
         RES=VAL%EJJJJJ
      CASE(108)
         RES=VAL%EKKKKK
      CASE(109)
         RES=VAL%ELLLLL
      CASE(110)
         RES=VAL%EMMMMM

      END SELECT
   END FUNCTION DONUMM22N5_GETIM_M

   SUBROUTINE DONUMM22N5_PPRINT_S(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: VAR
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
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E888 * '
      CALL PPRINT(VAR%E888,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E999 * '
      CALL PPRINT(VAR%E999,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EAAA * '
      CALL PPRINT(VAR%EAAA,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EBBB * '
      CALL PPRINT(VAR%EBBB,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'ECCC * '
      CALL PPRINT(VAR%ECCC,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EDDD * '
      CALL PPRINT(VAR%EDDD,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EEEE * '
      CALL PPRINT(VAR%EEEE,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EFFF * '
      CALL PPRINT(VAR%EFFF,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EGGG * '
      CALL PPRINT(VAR%EGGG,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EHHH * '
      CALL PPRINT(VAR%EHHH,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EIII * '
      CALL PPRINT(VAR%EIII,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EJJJ * '
      CALL PPRINT(VAR%EJJJ,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EKKK * '
      CALL PPRINT(VAR%EKKK,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'ELLL * '
      CALL PPRINT(VAR%ELLL,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EMMM * '
      CALL PPRINT(VAR%EMMM,unit=unt,fmt=output_format)

      !  Order 4
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E1111 * '
      CALL PPRINT(VAR%E1111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E2222 * '
      CALL PPRINT(VAR%E2222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E3333 * '
      CALL PPRINT(VAR%E3333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E4444 * '
      CALL PPRINT(VAR%E4444,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E5555 * '
      CALL PPRINT(VAR%E5555,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E6666 * '
      CALL PPRINT(VAR%E6666,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E7777 * '
      CALL PPRINT(VAR%E7777,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E8888 * '
      CALL PPRINT(VAR%E8888,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E9999 * '
      CALL PPRINT(VAR%E9999,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EAAAA * '
      CALL PPRINT(VAR%EAAAA,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EBBBB * '
      CALL PPRINT(VAR%EBBBB,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'ECCCC * '
      CALL PPRINT(VAR%ECCCC,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EDDDD * '
      CALL PPRINT(VAR%EDDDD,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EEEEE * '
      CALL PPRINT(VAR%EEEEE,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EFFFF * '
      CALL PPRINT(VAR%EFFFF,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EGGGG * '
      CALL PPRINT(VAR%EGGGG,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EHHHH * '
      CALL PPRINT(VAR%EHHHH,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EIIII * '
      CALL PPRINT(VAR%EIIII,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EJJJJ * '
      CALL PPRINT(VAR%EJJJJ,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EKKKK * '
      CALL PPRINT(VAR%EKKKK,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'ELLLL * '
      CALL PPRINT(VAR%ELLLL,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EMMMM * '
      CALL PPRINT(VAR%EMMMM,unit=unt,fmt=output_format)

      !  Order 5
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E11111 * '
      CALL PPRINT(VAR%E11111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E22222 * '
      CALL PPRINT(VAR%E22222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E33333 * '
      CALL PPRINT(VAR%E33333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E44444 * '
      CALL PPRINT(VAR%E44444,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E55555 * '
      CALL PPRINT(VAR%E55555,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E66666 * '
      CALL PPRINT(VAR%E66666,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E77777 * '
      CALL PPRINT(VAR%E77777,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E88888 * '
      CALL PPRINT(VAR%E88888,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E99999 * '
      CALL PPRINT(VAR%E99999,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EAAAAA * '
      CALL PPRINT(VAR%EAAAAA,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EBBBBB * '
      CALL PPRINT(VAR%EBBBBB,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'ECCCCC * '
      CALL PPRINT(VAR%ECCCCC,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EDDDDD * '
      CALL PPRINT(VAR%EDDDDD,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EEEEEE * '
      CALL PPRINT(VAR%EEEEEE,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EFFFFF * '
      CALL PPRINT(VAR%EFFFFF,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EGGGGG * '
      CALL PPRINT(VAR%EGGGGG,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EHHHHH * '
      CALL PPRINT(VAR%EHHHHH,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EIIIII * '
      CALL PPRINT(VAR%EIIIII,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EJJJJJ * '
      CALL PPRINT(VAR%EJJJJJ,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EKKKKK * '
      CALL PPRINT(VAR%EKKKKK,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'ELLLLL * '
      CALL PPRINT(VAR%ELLLLL,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'EMMMMM * '
      CALL PPRINT(VAR%EMMMMM,unit=unt,fmt=output_format)


   END SUBROUTINE DONUMM22N5_PPRINT_S

   SUBROUTINE DONUMM22N5_PPRINT_V(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: VAR(:)
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
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E888 * '
      CALL PPRINT(VAR%E888,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E999 * '
      CALL PPRINT(VAR%E999,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EAAA * '
      CALL PPRINT(VAR%EAAA,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EBBB * '
      CALL PPRINT(VAR%EBBB,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ECCC * '
      CALL PPRINT(VAR%ECCC,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EDDD * '
      CALL PPRINT(VAR%EDDD,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EEEE * '
      CALL PPRINT(VAR%EEEE,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EFFF * '
      CALL PPRINT(VAR%EFFF,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EGGG * '
      CALL PPRINT(VAR%EGGG,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EHHH * '
      CALL PPRINT(VAR%EHHH,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EIII * '
      CALL PPRINT(VAR%EIII,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EJJJ * '
      CALL PPRINT(VAR%EJJJ,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EKKK * '
      CALL PPRINT(VAR%EKKK,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ELLL * '
      CALL PPRINT(VAR%ELLL,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EMMM * '
      CALL PPRINT(VAR%EMMM,unit=unt,fmt=output_format)

      !  Order 4
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E1111 * '
      CALL PPRINT(VAR%E1111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E2222 * '
      CALL PPRINT(VAR%E2222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E3333 * '
      CALL PPRINT(VAR%E3333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E4444 * '
      CALL PPRINT(VAR%E4444,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E5555 * '
      CALL PPRINT(VAR%E5555,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E6666 * '
      CALL PPRINT(VAR%E6666,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E7777 * '
      CALL PPRINT(VAR%E7777,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E8888 * '
      CALL PPRINT(VAR%E8888,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E9999 * '
      CALL PPRINT(VAR%E9999,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EAAAA * '
      CALL PPRINT(VAR%EAAAA,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EBBBB * '
      CALL PPRINT(VAR%EBBBB,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ECCCC * '
      CALL PPRINT(VAR%ECCCC,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EDDDD * '
      CALL PPRINT(VAR%EDDDD,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EEEEE * '
      CALL PPRINT(VAR%EEEEE,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EFFFF * '
      CALL PPRINT(VAR%EFFFF,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EGGGG * '
      CALL PPRINT(VAR%EGGGG,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EHHHH * '
      CALL PPRINT(VAR%EHHHH,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EIIII * '
      CALL PPRINT(VAR%EIIII,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EJJJJ * '
      CALL PPRINT(VAR%EJJJJ,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EKKKK * '
      CALL PPRINT(VAR%EKKKK,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ELLLL * '
      CALL PPRINT(VAR%ELLLL,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EMMMM * '
      CALL PPRINT(VAR%EMMMM,unit=unt,fmt=output_format)

      !  Order 5
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E11111 * '
      CALL PPRINT(VAR%E11111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E22222 * '
      CALL PPRINT(VAR%E22222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E33333 * '
      CALL PPRINT(VAR%E33333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E44444 * '
      CALL PPRINT(VAR%E44444,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E55555 * '
      CALL PPRINT(VAR%E55555,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E66666 * '
      CALL PPRINT(VAR%E66666,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E77777 * '
      CALL PPRINT(VAR%E77777,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E88888 * '
      CALL PPRINT(VAR%E88888,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E99999 * '
      CALL PPRINT(VAR%E99999,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EAAAAA * '
      CALL PPRINT(VAR%EAAAAA,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EBBBBB * '
      CALL PPRINT(VAR%EBBBBB,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ECCCCC * '
      CALL PPRINT(VAR%ECCCCC,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EDDDDD * '
      CALL PPRINT(VAR%EDDDDD,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EEEEEE * '
      CALL PPRINT(VAR%EEEEEE,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EFFFFF * '
      CALL PPRINT(VAR%EFFFFF,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EGGGGG * '
      CALL PPRINT(VAR%EGGGGG,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EHHHHH * '
      CALL PPRINT(VAR%EHHHHH,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EIIIII * '
      CALL PPRINT(VAR%EIIIII,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EJJJJJ * '
      CALL PPRINT(VAR%EJJJJJ,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EKKKKK * '
      CALL PPRINT(VAR%EKKKKK,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ELLLLL * '
      CALL PPRINT(VAR%ELLLLL,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EMMMMM * '
      CALL PPRINT(VAR%EMMMMM,unit=unt,fmt=output_format)


   END SUBROUTINE DONUMM22N5_PPRINT_V

   SUBROUTINE DONUMM22N5_PPRINT_M(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: VAR(:,:)
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
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E888 * '
      CALL PPRINT(VAR%E888,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E999 * '
      CALL PPRINT(VAR%E999,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EAAA * '
      CALL PPRINT(VAR%EAAA,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EBBB * '
      CALL PPRINT(VAR%EBBB,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ECCC * '
      CALL PPRINT(VAR%ECCC,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EDDD * '
      CALL PPRINT(VAR%EDDD,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EEEE * '
      CALL PPRINT(VAR%EEEE,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EFFF * '
      CALL PPRINT(VAR%EFFF,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EGGG * '
      CALL PPRINT(VAR%EGGG,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EHHH * '
      CALL PPRINT(VAR%EHHH,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EIII * '
      CALL PPRINT(VAR%EIII,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EJJJ * '
      CALL PPRINT(VAR%EJJJ,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EKKK * '
      CALL PPRINT(VAR%EKKK,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ELLL * '
      CALL PPRINT(VAR%ELLL,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EMMM * '
      CALL PPRINT(VAR%EMMM,unit=unt,fmt=output_format)

      !  Order 4
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E1111 * '
      CALL PPRINT(VAR%E1111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E2222 * '
      CALL PPRINT(VAR%E2222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E3333 * '
      CALL PPRINT(VAR%E3333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E4444 * '
      CALL PPRINT(VAR%E4444,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E5555 * '
      CALL PPRINT(VAR%E5555,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E6666 * '
      CALL PPRINT(VAR%E6666,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E7777 * '
      CALL PPRINT(VAR%E7777,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E8888 * '
      CALL PPRINT(VAR%E8888,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E9999 * '
      CALL PPRINT(VAR%E9999,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EAAAA * '
      CALL PPRINT(VAR%EAAAA,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EBBBB * '
      CALL PPRINT(VAR%EBBBB,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ECCCC * '
      CALL PPRINT(VAR%ECCCC,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EDDDD * '
      CALL PPRINT(VAR%EDDDD,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EEEEE * '
      CALL PPRINT(VAR%EEEEE,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EFFFF * '
      CALL PPRINT(VAR%EFFFF,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EGGGG * '
      CALL PPRINT(VAR%EGGGG,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EHHHH * '
      CALL PPRINT(VAR%EHHHH,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EIIII * '
      CALL PPRINT(VAR%EIIII,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EJJJJ * '
      CALL PPRINT(VAR%EJJJJ,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EKKKK * '
      CALL PPRINT(VAR%EKKKK,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ELLLL * '
      CALL PPRINT(VAR%ELLLL,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EMMMM * '
      CALL PPRINT(VAR%EMMMM,unit=unt,fmt=output_format)

      !  Order 5
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E11111 * '
      CALL PPRINT(VAR%E11111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E22222 * '
      CALL PPRINT(VAR%E22222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E33333 * '
      CALL PPRINT(VAR%E33333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E44444 * '
      CALL PPRINT(VAR%E44444,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E55555 * '
      CALL PPRINT(VAR%E55555,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E66666 * '
      CALL PPRINT(VAR%E66666,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E77777 * '
      CALL PPRINT(VAR%E77777,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E88888 * '
      CALL PPRINT(VAR%E88888,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E99999 * '
      CALL PPRINT(VAR%E99999,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EAAAAA * '
      CALL PPRINT(VAR%EAAAAA,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EBBBBB * '
      CALL PPRINT(VAR%EBBBBB,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ECCCCC * '
      CALL PPRINT(VAR%ECCCCC,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EDDDDD * '
      CALL PPRINT(VAR%EDDDDD,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EEEEEE * '
      CALL PPRINT(VAR%EEEEEE,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EFFFFF * '
      CALL PPRINT(VAR%EFFFFF,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EGGGGG * '
      CALL PPRINT(VAR%EGGGGG,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EHHHHH * '
      CALL PPRINT(VAR%EHHHHH,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EIIIII * '
      CALL PPRINT(VAR%EIIIII,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EJJJJJ * '
      CALL PPRINT(VAR%EJJJJJ,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EKKKKK * '
      CALL PPRINT(VAR%EKKKKK,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'ELLLLL * '
      CALL PPRINT(VAR%ELLLLL,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'EMMMMM * '
      CALL PPRINT(VAR%EMMMMM,unit=unt,fmt=output_format)


   END SUBROUTINE DONUMM22N5_PPRINT_M

   ELEMENTAL FUNCTION DONUMM22N5_FEVAL(X,DER0,DER1,DER2,DER3,DER4,DER5)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: FACTOR, COEF
      TYPE(DONUMM22N5), INTENT(IN)  :: X
      REAL(DP), INTENT(IN)  :: DER0,DER1,DER2,DER3,DER4,DER5
      TYPE(DONUMM22N5) :: RES
      TYPE(DONUMM22N5) :: DX, DX_P

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
      ! Order 5
      RES%E11111 = RES%E11111+COEF*DX_P%E11111
      RES%E22222 = RES%E22222+COEF*DX_P%E22222
      RES%E33333 = RES%E33333+COEF*DX_P%E33333
      RES%E44444 = RES%E44444+COEF*DX_P%E44444
      RES%E55555 = RES%E55555+COEF*DX_P%E55555
      RES%E66666 = RES%E66666+COEF*DX_P%E66666
      RES%E77777 = RES%E77777+COEF*DX_P%E77777
      RES%E88888 = RES%E88888+COEF*DX_P%E88888
      RES%E99999 = RES%E99999+COEF*DX_P%E99999
      RES%EAAAAA = RES%EAAAAA+COEF*DX_P%EAAAAA
      RES%EBBBBB = RES%EBBBBB+COEF*DX_P%EBBBBB
      RES%ECCCCC = RES%ECCCCC+COEF*DX_P%ECCCCC
      RES%EDDDDD = RES%EDDDDD+COEF*DX_P%EDDDDD
      RES%EEEEEE = RES%EEEEEE+COEF*DX_P%EEEEEE
      RES%EFFFFF = RES%EFFFFF+COEF*DX_P%EFFFFF
      RES%EGGGGG = RES%EGGGGG+COEF*DX_P%EGGGGG
      RES%EHHHHH = RES%EHHHHH+COEF*DX_P%EHHHHH
      RES%EIIIII = RES%EIIIII+COEF*DX_P%EIIIII
      RES%EJJJJJ = RES%EJJJJJ+COEF*DX_P%EJJJJJ
      RES%EKKKKK = RES%EKKKKK+COEF*DX_P%EKKKKK
      RES%ELLLLL = RES%ELLLLL+COEF*DX_P%ELLLLL
      RES%EMMMMM = RES%EMMMMM+COEF*DX_P%EMMMMM
      ! Order 4
      RES%E1111 = RES%E1111+COEF*DX_P%E1111
      RES%E2222 = RES%E2222+COEF*DX_P%E2222
      RES%E3333 = RES%E3333+COEF*DX_P%E3333
      RES%E4444 = RES%E4444+COEF*DX_P%E4444
      RES%E5555 = RES%E5555+COEF*DX_P%E5555
      RES%E6666 = RES%E6666+COEF*DX_P%E6666
      RES%E7777 = RES%E7777+COEF*DX_P%E7777
      RES%E8888 = RES%E8888+COEF*DX_P%E8888
      RES%E9999 = RES%E9999+COEF*DX_P%E9999
      RES%EAAAA = RES%EAAAA+COEF*DX_P%EAAAA
      RES%EBBBB = RES%EBBBB+COEF*DX_P%EBBBB
      RES%ECCCC = RES%ECCCC+COEF*DX_P%ECCCC
      RES%EDDDD = RES%EDDDD+COEF*DX_P%EDDDD
      RES%EEEEE = RES%EEEEE+COEF*DX_P%EEEEE
      RES%EFFFF = RES%EFFFF+COEF*DX_P%EFFFF
      RES%EGGGG = RES%EGGGG+COEF*DX_P%EGGGG
      RES%EHHHH = RES%EHHHH+COEF*DX_P%EHHHH
      RES%EIIII = RES%EIIII+COEF*DX_P%EIIII
      RES%EJJJJ = RES%EJJJJ+COEF*DX_P%EJJJJ
      RES%EKKKK = RES%EKKKK+COEF*DX_P%EKKKK
      RES%ELLLL = RES%ELLLL+COEF*DX_P%ELLLL
      RES%EMMMM = RES%EMMMM+COEF*DX_P%EMMMM
      ! Order 3
      RES%E111 = RES%E111+COEF*DX_P%E111
      RES%E222 = RES%E222+COEF*DX_P%E222
      RES%E333 = RES%E333+COEF*DX_P%E333
      RES%E444 = RES%E444+COEF*DX_P%E444
      RES%E555 = RES%E555+COEF*DX_P%E555
      RES%E666 = RES%E666+COEF*DX_P%E666
      RES%E777 = RES%E777+COEF*DX_P%E777
      RES%E888 = RES%E888+COEF*DX_P%E888
      RES%E999 = RES%E999+COEF*DX_P%E999
      RES%EAAA = RES%EAAA+COEF*DX_P%EAAA
      RES%EBBB = RES%EBBB+COEF*DX_P%EBBB
      RES%ECCC = RES%ECCC+COEF*DX_P%ECCC
      RES%EDDD = RES%EDDD+COEF*DX_P%EDDD
      RES%EEEE = RES%EEEE+COEF*DX_P%EEEE
      RES%EFFF = RES%EFFF+COEF*DX_P%EFFF
      RES%EGGG = RES%EGGG+COEF*DX_P%EGGG
      RES%EHHH = RES%EHHH+COEF*DX_P%EHHH
      RES%EIII = RES%EIII+COEF*DX_P%EIII
      RES%EJJJ = RES%EJJJ+COEF*DX_P%EJJJ
      RES%EKKK = RES%EKKK+COEF*DX_P%EKKK
      RES%ELLL = RES%ELLL+COEF*DX_P%ELLL
      RES%EMMM = RES%EMMM+COEF*DX_P%EMMM
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
      ! Order 5
      DX_P%E11111 = DX_P%E1*DX%E1111+DX_P%E1111*DX%E1+ &
                 DX_P%E11*DX%E111+DX_P%E111*DX%E11
      DX_P%E22222 = DX_P%E2*DX%E2222+DX_P%E2222*DX%E2+ &
                 DX_P%E22*DX%E222+DX_P%E222*DX%E22
      DX_P%E33333 = DX_P%E3*DX%E3333+DX_P%E3333*DX%E3+ &
                 DX_P%E33*DX%E333+DX_P%E333*DX%E33
      DX_P%E44444 = DX_P%E4*DX%E4444+DX_P%E4444*DX%E4+ &
                 DX_P%E44*DX%E444+DX_P%E444*DX%E44
      DX_P%E55555 = DX_P%E5*DX%E5555+DX_P%E5555*DX%E5+ &
                 DX_P%E55*DX%E555+DX_P%E555*DX%E55
      DX_P%E66666 = DX_P%E6*DX%E6666+DX_P%E6666*DX%E6+ &
                 DX_P%E66*DX%E666+DX_P%E666*DX%E66
      DX_P%E77777 = DX_P%E7*DX%E7777+DX_P%E7777*DX%E7+ &
                 DX_P%E77*DX%E777+DX_P%E777*DX%E77
      DX_P%E88888 = DX_P%E8*DX%E8888+DX_P%E8888*DX%E8+ &
                 DX_P%E88*DX%E888+DX_P%E888*DX%E88
      DX_P%E99999 = DX_P%E9*DX%E9999+DX_P%E9999*DX%E9+ &
                 DX_P%E99*DX%E999+DX_P%E999*DX%E99
      DX_P%EAAAAA = DX_P%EA*DX%EAAAA+DX_P%EAAAA*DX%EA+ &
                 DX_P%EAA*DX%EAAA+DX_P%EAAA*DX%EAA
      DX_P%EBBBBB = DX_P%EB*DX%EBBBB+DX_P%EBBBB*DX%EB+ &
                 DX_P%EBB*DX%EBBB+DX_P%EBBB*DX%EBB
      DX_P%ECCCCC = DX_P%EC*DX%ECCCC+DX_P%ECCCC*DX%EC+ &
                 DX_P%ECC*DX%ECCC+DX_P%ECCC*DX%ECC
      DX_P%EDDDDD = DX_P%ED*DX%EDDDD+DX_P%EDDDD*DX%ED+ &
                 DX_P%EDD*DX%EDDD+DX_P%EDDD*DX%EDD
      DX_P%EEEEEE = DX_P%EE*DX%EEEEE+DX_P%EEEEE*DX%EE+ &
                 DX_P%EEE*DX%EEEE+DX_P%EEEE*DX%EEE
      DX_P%EFFFFF = DX_P%EF*DX%EFFFF+DX_P%EFFFF*DX%EF+ &
                 DX_P%EFF*DX%EFFF+DX_P%EFFF*DX%EFF
      DX_P%EGGGGG = DX_P%EG*DX%EGGGG+DX_P%EGGGG*DX%EG+ &
                 DX_P%EGG*DX%EGGG+DX_P%EGGG*DX%EGG
      DX_P%EHHHHH = DX_P%EH*DX%EHHHH+DX_P%EHHHH*DX%EH+ &
                 DX_P%EHH*DX%EHHH+DX_P%EHHH*DX%EHH
      DX_P%EIIIII = DX_P%EI*DX%EIIII+DX_P%EIIII*DX%EI+ &
                 DX_P%EII*DX%EIII+DX_P%EIII*DX%EII
      DX_P%EJJJJJ = DX_P%EJ*DX%EJJJJ+DX_P%EJJJJ*DX%EJ+ &
                 DX_P%EJJ*DX%EJJJ+DX_P%EJJJ*DX%EJJ
      DX_P%EKKKKK = DX_P%EK*DX%EKKKK+DX_P%EKKKK*DX%EK+ &
                 DX_P%EKK*DX%EKKK+DX_P%EKKK*DX%EKK
      DX_P%ELLLLL = DX_P%EL*DX%ELLLL+DX_P%ELLLL*DX%EL+ &
                 DX_P%ELL*DX%ELLL+DX_P%ELLL*DX%ELL
      DX_P%EMMMMM = DX_P%EM*DX%EMMMM+DX_P%EMMMM*DX%EM+ &
                 DX_P%EMM*DX%EMMM+DX_P%EMMM*DX%EMM
      ! Order 4
      DX_P%E1111 = DX_P%E1*DX%E111+DX_P%E111*DX%E1+ &
                DX_P%E11*DX%E11
      DX_P%E2222 = DX_P%E2*DX%E222+DX_P%E222*DX%E2+ &
                DX_P%E22*DX%E22
      DX_P%E3333 = DX_P%E3*DX%E333+DX_P%E333*DX%E3+ &
                DX_P%E33*DX%E33
      DX_P%E4444 = DX_P%E4*DX%E444+DX_P%E444*DX%E4+ &
                DX_P%E44*DX%E44
      DX_P%E5555 = DX_P%E5*DX%E555+DX_P%E555*DX%E5+ &
                DX_P%E55*DX%E55
      DX_P%E6666 = DX_P%E6*DX%E666+DX_P%E666*DX%E6+ &
                DX_P%E66*DX%E66
      DX_P%E7777 = DX_P%E7*DX%E777+DX_P%E777*DX%E7+ &
                DX_P%E77*DX%E77
      DX_P%E8888 = DX_P%E8*DX%E888+DX_P%E888*DX%E8+ &
                DX_P%E88*DX%E88
      DX_P%E9999 = DX_P%E9*DX%E999+DX_P%E999*DX%E9+ &
                DX_P%E99*DX%E99
      DX_P%EAAAA = DX_P%EA*DX%EAAA+DX_P%EAAA*DX%EA+ &
                DX_P%EAA*DX%EAA
      DX_P%EBBBB = DX_P%EB*DX%EBBB+DX_P%EBBB*DX%EB+ &
                DX_P%EBB*DX%EBB
      DX_P%ECCCC = DX_P%EC*DX%ECCC+DX_P%ECCC*DX%EC+ &
                DX_P%ECC*DX%ECC
      DX_P%EDDDD = DX_P%ED*DX%EDDD+DX_P%EDDD*DX%ED+ &
                DX_P%EDD*DX%EDD
      DX_P%EEEEE = DX_P%EE*DX%EEEE+DX_P%EEEE*DX%EE+ &
                DX_P%EEE*DX%EEE
      DX_P%EFFFF = DX_P%EF*DX%EFFF+DX_P%EFFF*DX%EF+ &
                DX_P%EFF*DX%EFF
      DX_P%EGGGG = DX_P%EG*DX%EGGG+DX_P%EGGG*DX%EG+ &
                DX_P%EGG*DX%EGG
      DX_P%EHHHH = DX_P%EH*DX%EHHH+DX_P%EHHH*DX%EH+ &
                DX_P%EHH*DX%EHH
      DX_P%EIIII = DX_P%EI*DX%EIII+DX_P%EIII*DX%EI+ &
                DX_P%EII*DX%EII
      DX_P%EJJJJ = DX_P%EJ*DX%EJJJ+DX_P%EJJJ*DX%EJ+ &
                DX_P%EJJ*DX%EJJ
      DX_P%EKKKK = DX_P%EK*DX%EKKK+DX_P%EKKK*DX%EK+ &
                DX_P%EKK*DX%EKK
      DX_P%ELLLL = DX_P%EL*DX%ELLL+DX_P%ELLL*DX%EL+ &
                DX_P%ELL*DX%ELL
      DX_P%EMMMM = DX_P%EM*DX%EMMM+DX_P%EMMM*DX%EM+ &
                DX_P%EMM*DX%EMM
      ! Order 3
      DX_P%E111 = DX_P%E1*DX%E11+DX_P%E11*DX%E1
      DX_P%E222 = DX_P%E2*DX%E22+DX_P%E22*DX%E2
      DX_P%E333 = DX_P%E3*DX%E33+DX_P%E33*DX%E3
      DX_P%E444 = DX_P%E4*DX%E44+DX_P%E44*DX%E4
      DX_P%E555 = DX_P%E5*DX%E55+DX_P%E55*DX%E5
      DX_P%E666 = DX_P%E6*DX%E66+DX_P%E66*DX%E6
      DX_P%E777 = DX_P%E7*DX%E77+DX_P%E77*DX%E7
      DX_P%E888 = DX_P%E8*DX%E88+DX_P%E88*DX%E8
      DX_P%E999 = DX_P%E9*DX%E99+DX_P%E99*DX%E9
      DX_P%EAAA = DX_P%EA*DX%EAA+DX_P%EAA*DX%EA
      DX_P%EBBB = DX_P%EB*DX%EBB+DX_P%EBB*DX%EB
      DX_P%ECCC = DX_P%EC*DX%ECC+DX_P%ECC*DX%EC
      DX_P%EDDD = DX_P%ED*DX%EDD+DX_P%EDD*DX%ED
      DX_P%EEEE = DX_P%EE*DX%EEE+DX_P%EEE*DX%EE
      DX_P%EFFF = DX_P%EF*DX%EFF+DX_P%EFF*DX%EF
      DX_P%EGGG = DX_P%EG*DX%EGG+DX_P%EGG*DX%EG
      DX_P%EHHH = DX_P%EH*DX%EHH+DX_P%EHH*DX%EH
      DX_P%EIII = DX_P%EI*DX%EII+DX_P%EII*DX%EI
      DX_P%EJJJ = DX_P%EJ*DX%EJJ+DX_P%EJJ*DX%EJ
      DX_P%EKKK = DX_P%EK*DX%EKK+DX_P%EKK*DX%EK
      DX_P%ELLL = DX_P%EL*DX%ELL+DX_P%ELL*DX%EL
      DX_P%EMMM = DX_P%EM*DX%EMM+DX_P%EMM*DX%EM
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
      ! Order 5
      RES%E11111 = RES%E11111+COEF*DX_P%E11111
      RES%E22222 = RES%E22222+COEF*DX_P%E22222
      RES%E33333 = RES%E33333+COEF*DX_P%E33333
      RES%E44444 = RES%E44444+COEF*DX_P%E44444
      RES%E55555 = RES%E55555+COEF*DX_P%E55555
      RES%E66666 = RES%E66666+COEF*DX_P%E66666
      RES%E77777 = RES%E77777+COEF*DX_P%E77777
      RES%E88888 = RES%E88888+COEF*DX_P%E88888
      RES%E99999 = RES%E99999+COEF*DX_P%E99999
      RES%EAAAAA = RES%EAAAAA+COEF*DX_P%EAAAAA
      RES%EBBBBB = RES%EBBBBB+COEF*DX_P%EBBBBB
      RES%ECCCCC = RES%ECCCCC+COEF*DX_P%ECCCCC
      RES%EDDDDD = RES%EDDDDD+COEF*DX_P%EDDDDD
      RES%EEEEEE = RES%EEEEEE+COEF*DX_P%EEEEEE
      RES%EFFFFF = RES%EFFFFF+COEF*DX_P%EFFFFF
      RES%EGGGGG = RES%EGGGGG+COEF*DX_P%EGGGGG
      RES%EHHHHH = RES%EHHHHH+COEF*DX_P%EHHHHH
      RES%EIIIII = RES%EIIIII+COEF*DX_P%EIIIII
      RES%EJJJJJ = RES%EJJJJJ+COEF*DX_P%EJJJJJ
      RES%EKKKKK = RES%EKKKKK+COEF*DX_P%EKKKKK
      RES%ELLLLL = RES%ELLLLL+COEF*DX_P%ELLLLL
      RES%EMMMMM = RES%EMMMMM+COEF*DX_P%EMMMMM
      ! Order 4
      RES%E1111 = RES%E1111+COEF*DX_P%E1111
      RES%E2222 = RES%E2222+COEF*DX_P%E2222
      RES%E3333 = RES%E3333+COEF*DX_P%E3333
      RES%E4444 = RES%E4444+COEF*DX_P%E4444
      RES%E5555 = RES%E5555+COEF*DX_P%E5555
      RES%E6666 = RES%E6666+COEF*DX_P%E6666
      RES%E7777 = RES%E7777+COEF*DX_P%E7777
      RES%E8888 = RES%E8888+COEF*DX_P%E8888
      RES%E9999 = RES%E9999+COEF*DX_P%E9999
      RES%EAAAA = RES%EAAAA+COEF*DX_P%EAAAA
      RES%EBBBB = RES%EBBBB+COEF*DX_P%EBBBB
      RES%ECCCC = RES%ECCCC+COEF*DX_P%ECCCC
      RES%EDDDD = RES%EDDDD+COEF*DX_P%EDDDD
      RES%EEEEE = RES%EEEEE+COEF*DX_P%EEEEE
      RES%EFFFF = RES%EFFFF+COEF*DX_P%EFFFF
      RES%EGGGG = RES%EGGGG+COEF*DX_P%EGGGG
      RES%EHHHH = RES%EHHHH+COEF*DX_P%EHHHH
      RES%EIIII = RES%EIIII+COEF*DX_P%EIIII
      RES%EJJJJ = RES%EJJJJ+COEF*DX_P%EJJJJ
      RES%EKKKK = RES%EKKKK+COEF*DX_P%EKKKK
      RES%ELLLL = RES%ELLLL+COEF*DX_P%ELLLL
      RES%EMMMM = RES%EMMMM+COEF*DX_P%EMMMM
      ! Order 3
      RES%E111 = RES%E111+COEF*DX_P%E111
      RES%E222 = RES%E222+COEF*DX_P%E222
      RES%E333 = RES%E333+COEF*DX_P%E333
      RES%E444 = RES%E444+COEF*DX_P%E444
      RES%E555 = RES%E555+COEF*DX_P%E555
      RES%E666 = RES%E666+COEF*DX_P%E666
      RES%E777 = RES%E777+COEF*DX_P%E777
      RES%E888 = RES%E888+COEF*DX_P%E888
      RES%E999 = RES%E999+COEF*DX_P%E999
      RES%EAAA = RES%EAAA+COEF*DX_P%EAAA
      RES%EBBB = RES%EBBB+COEF*DX_P%EBBB
      RES%ECCC = RES%ECCC+COEF*DX_P%ECCC
      RES%EDDD = RES%EDDD+COEF*DX_P%EDDD
      RES%EEEE = RES%EEEE+COEF*DX_P%EEEE
      RES%EFFF = RES%EFFF+COEF*DX_P%EFFF
      RES%EGGG = RES%EGGG+COEF*DX_P%EGGG
      RES%EHHH = RES%EHHH+COEF*DX_P%EHHH
      RES%EIII = RES%EIII+COEF*DX_P%EIII
      RES%EJJJ = RES%EJJJ+COEF*DX_P%EJJJ
      RES%EKKK = RES%EKKK+COEF*DX_P%EKKK
      RES%ELLL = RES%ELLL+COEF*DX_P%ELLL
      RES%EMMM = RES%EMMM+COEF*DX_P%EMMM
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
      ! DX_P = DX_P * DX
      ! Order 5
      DX_P%E11111 = DX_P%E1111*DX%E1+DX_P%E11*DX%E111+ &
                 DX_P%E111*DX%E11
      DX_P%E22222 = DX_P%E2222*DX%E2+DX_P%E22*DX%E222+ &
                 DX_P%E222*DX%E22
      DX_P%E33333 = DX_P%E3333*DX%E3+DX_P%E33*DX%E333+ &
                 DX_P%E333*DX%E33
      DX_P%E44444 = DX_P%E4444*DX%E4+DX_P%E44*DX%E444+ &
                 DX_P%E444*DX%E44
      DX_P%E55555 = DX_P%E5555*DX%E5+DX_P%E55*DX%E555+ &
                 DX_P%E555*DX%E55
      DX_P%E66666 = DX_P%E6666*DX%E6+DX_P%E66*DX%E666+ &
                 DX_P%E666*DX%E66
      DX_P%E77777 = DX_P%E7777*DX%E7+DX_P%E77*DX%E777+ &
                 DX_P%E777*DX%E77
      DX_P%E88888 = DX_P%E8888*DX%E8+DX_P%E88*DX%E888+ &
                 DX_P%E888*DX%E88
      DX_P%E99999 = DX_P%E9999*DX%E9+DX_P%E99*DX%E999+ &
                 DX_P%E999*DX%E99
      DX_P%EAAAAA = DX_P%EAAAA*DX%EA+DX_P%EAA*DX%EAAA+ &
                 DX_P%EAAA*DX%EAA
      DX_P%EBBBBB = DX_P%EBBBB*DX%EB+DX_P%EBB*DX%EBBB+ &
                 DX_P%EBBB*DX%EBB
      DX_P%ECCCCC = DX_P%ECCCC*DX%EC+DX_P%ECC*DX%ECCC+ &
                 DX_P%ECCC*DX%ECC
      DX_P%EDDDDD = DX_P%EDDDD*DX%ED+DX_P%EDD*DX%EDDD+ &
                 DX_P%EDDD*DX%EDD
      DX_P%EEEEEE = DX_P%EEEEE*DX%EE+DX_P%EEE*DX%EEEE+ &
                 DX_P%EEEE*DX%EEE
      DX_P%EFFFFF = DX_P%EFFFF*DX%EF+DX_P%EFF*DX%EFFF+ &
                 DX_P%EFFF*DX%EFF
      DX_P%EGGGGG = DX_P%EGGGG*DX%EG+DX_P%EGG*DX%EGGG+ &
                 DX_P%EGGG*DX%EGG
      DX_P%EHHHHH = DX_P%EHHHH*DX%EH+DX_P%EHH*DX%EHHH+ &
                 DX_P%EHHH*DX%EHH
      DX_P%EIIIII = DX_P%EIIII*DX%EI+DX_P%EII*DX%EIII+ &
                 DX_P%EIII*DX%EII
      DX_P%EJJJJJ = DX_P%EJJJJ*DX%EJ+DX_P%EJJ*DX%EJJJ+ &
                 DX_P%EJJJ*DX%EJJ
      DX_P%EKKKKK = DX_P%EKKKK*DX%EK+DX_P%EKK*DX%EKKK+ &
                 DX_P%EKKK*DX%EKK
      DX_P%ELLLLL = DX_P%ELLLL*DX%EL+DX_P%ELL*DX%ELLL+ &
                 DX_P%ELLL*DX%ELL
      DX_P%EMMMMM = DX_P%EMMMM*DX%EM+DX_P%EMM*DX%EMMM+ &
                 DX_P%EMMM*DX%EMM
      ! Order 4
      DX_P%E1111 = DX_P%E111*DX%E1+DX_P%E11*DX%E11
      DX_P%E2222 = DX_P%E222*DX%E2+DX_P%E22*DX%E22
      DX_P%E3333 = DX_P%E333*DX%E3+DX_P%E33*DX%E33
      DX_P%E4444 = DX_P%E444*DX%E4+DX_P%E44*DX%E44
      DX_P%E5555 = DX_P%E555*DX%E5+DX_P%E55*DX%E55
      DX_P%E6666 = DX_P%E666*DX%E6+DX_P%E66*DX%E66
      DX_P%E7777 = DX_P%E777*DX%E7+DX_P%E77*DX%E77
      DX_P%E8888 = DX_P%E888*DX%E8+DX_P%E88*DX%E88
      DX_P%E9999 = DX_P%E999*DX%E9+DX_P%E99*DX%E99
      DX_P%EAAAA = DX_P%EAAA*DX%EA+DX_P%EAA*DX%EAA
      DX_P%EBBBB = DX_P%EBBB*DX%EB+DX_P%EBB*DX%EBB
      DX_P%ECCCC = DX_P%ECCC*DX%EC+DX_P%ECC*DX%ECC
      DX_P%EDDDD = DX_P%EDDD*DX%ED+DX_P%EDD*DX%EDD
      DX_P%EEEEE = DX_P%EEEE*DX%EE+DX_P%EEE*DX%EEE
      DX_P%EFFFF = DX_P%EFFF*DX%EF+DX_P%EFF*DX%EFF
      DX_P%EGGGG = DX_P%EGGG*DX%EG+DX_P%EGG*DX%EGG
      DX_P%EHHHH = DX_P%EHHH*DX%EH+DX_P%EHH*DX%EHH
      DX_P%EIIII = DX_P%EIII*DX%EI+DX_P%EII*DX%EII
      DX_P%EJJJJ = DX_P%EJJJ*DX%EJ+DX_P%EJJ*DX%EJJ
      DX_P%EKKKK = DX_P%EKKK*DX%EK+DX_P%EKK*DX%EKK
      DX_P%ELLLL = DX_P%ELLL*DX%EL+DX_P%ELL*DX%ELL
      DX_P%EMMMM = DX_P%EMMM*DX%EM+DX_P%EMM*DX%EMM
      ! Order 3
      DX_P%E111 = DX_P%E11*DX%E1
      DX_P%E222 = DX_P%E22*DX%E2
      DX_P%E333 = DX_P%E33*DX%E3
      DX_P%E444 = DX_P%E44*DX%E4
      DX_P%E555 = DX_P%E55*DX%E5
      DX_P%E666 = DX_P%E66*DX%E6
      DX_P%E777 = DX_P%E77*DX%E7
      DX_P%E888 = DX_P%E88*DX%E8
      DX_P%E999 = DX_P%E99*DX%E9
      DX_P%EAAA = DX_P%EAA*DX%EA
      DX_P%EBBB = DX_P%EBB*DX%EB
      DX_P%ECCC = DX_P%ECC*DX%EC
      DX_P%EDDD = DX_P%EDD*DX%ED
      DX_P%EEEE = DX_P%EEE*DX%EE
      DX_P%EFFF = DX_P%EFF*DX%EF
      DX_P%EGGG = DX_P%EGG*DX%EG
      DX_P%EHHH = DX_P%EHH*DX%EH
      DX_P%EIII = DX_P%EII*DX%EI
      DX_P%EJJJ = DX_P%EJJ*DX%EJ
      DX_P%EKKK = DX_P%EKK*DX%EK
      DX_P%ELLL = DX_P%ELL*DX%EL
      DX_P%EMMM = DX_P%EMM*DX%EM
      
      ! Sets order 3
      FACTOR = FACTOR * 3
      COEF = DER3 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 5
      RES%E11111 = RES%E11111+COEF*DX_P%E11111
      RES%E22222 = RES%E22222+COEF*DX_P%E22222
      RES%E33333 = RES%E33333+COEF*DX_P%E33333
      RES%E44444 = RES%E44444+COEF*DX_P%E44444
      RES%E55555 = RES%E55555+COEF*DX_P%E55555
      RES%E66666 = RES%E66666+COEF*DX_P%E66666
      RES%E77777 = RES%E77777+COEF*DX_P%E77777
      RES%E88888 = RES%E88888+COEF*DX_P%E88888
      RES%E99999 = RES%E99999+COEF*DX_P%E99999
      RES%EAAAAA = RES%EAAAAA+COEF*DX_P%EAAAAA
      RES%EBBBBB = RES%EBBBBB+COEF*DX_P%EBBBBB
      RES%ECCCCC = RES%ECCCCC+COEF*DX_P%ECCCCC
      RES%EDDDDD = RES%EDDDDD+COEF*DX_P%EDDDDD
      RES%EEEEEE = RES%EEEEEE+COEF*DX_P%EEEEEE
      RES%EFFFFF = RES%EFFFFF+COEF*DX_P%EFFFFF
      RES%EGGGGG = RES%EGGGGG+COEF*DX_P%EGGGGG
      RES%EHHHHH = RES%EHHHHH+COEF*DX_P%EHHHHH
      RES%EIIIII = RES%EIIIII+COEF*DX_P%EIIIII
      RES%EJJJJJ = RES%EJJJJJ+COEF*DX_P%EJJJJJ
      RES%EKKKKK = RES%EKKKKK+COEF*DX_P%EKKKKK
      RES%ELLLLL = RES%ELLLLL+COEF*DX_P%ELLLLL
      RES%EMMMMM = RES%EMMMMM+COEF*DX_P%EMMMMM
      ! Order 4
      RES%E1111 = RES%E1111+COEF*DX_P%E1111
      RES%E2222 = RES%E2222+COEF*DX_P%E2222
      RES%E3333 = RES%E3333+COEF*DX_P%E3333
      RES%E4444 = RES%E4444+COEF*DX_P%E4444
      RES%E5555 = RES%E5555+COEF*DX_P%E5555
      RES%E6666 = RES%E6666+COEF*DX_P%E6666
      RES%E7777 = RES%E7777+COEF*DX_P%E7777
      RES%E8888 = RES%E8888+COEF*DX_P%E8888
      RES%E9999 = RES%E9999+COEF*DX_P%E9999
      RES%EAAAA = RES%EAAAA+COEF*DX_P%EAAAA
      RES%EBBBB = RES%EBBBB+COEF*DX_P%EBBBB
      RES%ECCCC = RES%ECCCC+COEF*DX_P%ECCCC
      RES%EDDDD = RES%EDDDD+COEF*DX_P%EDDDD
      RES%EEEEE = RES%EEEEE+COEF*DX_P%EEEEE
      RES%EFFFF = RES%EFFFF+COEF*DX_P%EFFFF
      RES%EGGGG = RES%EGGGG+COEF*DX_P%EGGGG
      RES%EHHHH = RES%EHHHH+COEF*DX_P%EHHHH
      RES%EIIII = RES%EIIII+COEF*DX_P%EIIII
      RES%EJJJJ = RES%EJJJJ+COEF*DX_P%EJJJJ
      RES%EKKKK = RES%EKKKK+COEF*DX_P%EKKKK
      RES%ELLLL = RES%ELLLL+COEF*DX_P%ELLLL
      RES%EMMMM = RES%EMMMM+COEF*DX_P%EMMMM
      ! Order 3
      RES%E111 = RES%E111+COEF*DX_P%E111
      RES%E222 = RES%E222+COEF*DX_P%E222
      RES%E333 = RES%E333+COEF*DX_P%E333
      RES%E444 = RES%E444+COEF*DX_P%E444
      RES%E555 = RES%E555+COEF*DX_P%E555
      RES%E666 = RES%E666+COEF*DX_P%E666
      RES%E777 = RES%E777+COEF*DX_P%E777
      RES%E888 = RES%E888+COEF*DX_P%E888
      RES%E999 = RES%E999+COEF*DX_P%E999
      RES%EAAA = RES%EAAA+COEF*DX_P%EAAA
      RES%EBBB = RES%EBBB+COEF*DX_P%EBBB
      RES%ECCC = RES%ECCC+COEF*DX_P%ECCC
      RES%EDDD = RES%EDDD+COEF*DX_P%EDDD
      RES%EEEE = RES%EEEE+COEF*DX_P%EEEE
      RES%EFFF = RES%EFFF+COEF*DX_P%EFFF
      RES%EGGG = RES%EGGG+COEF*DX_P%EGGG
      RES%EHHH = RES%EHHH+COEF*DX_P%EHHH
      RES%EIII = RES%EIII+COEF*DX_P%EIII
      RES%EJJJ = RES%EJJJ+COEF*DX_P%EJJJ
      RES%EKKK = RES%EKKK+COEF*DX_P%EKKK
      RES%ELLL = RES%ELLL+COEF*DX_P%ELLL
      RES%EMMM = RES%EMMM+COEF*DX_P%EMMM
      ! DX_P = DX_P * DX
      ! Order 5
      DX_P%E11111 = DX_P%E1111*DX%E1+DX_P%E111*DX%E11
      DX_P%E22222 = DX_P%E2222*DX%E2+DX_P%E222*DX%E22
      DX_P%E33333 = DX_P%E3333*DX%E3+DX_P%E333*DX%E33
      DX_P%E44444 = DX_P%E4444*DX%E4+DX_P%E444*DX%E44
      DX_P%E55555 = DX_P%E5555*DX%E5+DX_P%E555*DX%E55
      DX_P%E66666 = DX_P%E6666*DX%E6+DX_P%E666*DX%E66
      DX_P%E77777 = DX_P%E7777*DX%E7+DX_P%E777*DX%E77
      DX_P%E88888 = DX_P%E8888*DX%E8+DX_P%E888*DX%E88
      DX_P%E99999 = DX_P%E9999*DX%E9+DX_P%E999*DX%E99
      DX_P%EAAAAA = DX_P%EAAAA*DX%EA+DX_P%EAAA*DX%EAA
      DX_P%EBBBBB = DX_P%EBBBB*DX%EB+DX_P%EBBB*DX%EBB
      DX_P%ECCCCC = DX_P%ECCCC*DX%EC+DX_P%ECCC*DX%ECC
      DX_P%EDDDDD = DX_P%EDDDD*DX%ED+DX_P%EDDD*DX%EDD
      DX_P%EEEEEE = DX_P%EEEEE*DX%EE+DX_P%EEEE*DX%EEE
      DX_P%EFFFFF = DX_P%EFFFF*DX%EF+DX_P%EFFF*DX%EFF
      DX_P%EGGGGG = DX_P%EGGGG*DX%EG+DX_P%EGGG*DX%EGG
      DX_P%EHHHHH = DX_P%EHHHH*DX%EH+DX_P%EHHH*DX%EHH
      DX_P%EIIIII = DX_P%EIIII*DX%EI+DX_P%EIII*DX%EII
      DX_P%EJJJJJ = DX_P%EJJJJ*DX%EJ+DX_P%EJJJ*DX%EJJ
      DX_P%EKKKKK = DX_P%EKKKK*DX%EK+DX_P%EKKK*DX%EKK
      DX_P%ELLLLL = DX_P%ELLLL*DX%EL+DX_P%ELLL*DX%ELL
      DX_P%EMMMMM = DX_P%EMMMM*DX%EM+DX_P%EMMM*DX%EMM
      ! Order 4
      DX_P%E1111 = DX_P%E111*DX%E1
      DX_P%E2222 = DX_P%E222*DX%E2
      DX_P%E3333 = DX_P%E333*DX%E3
      DX_P%E4444 = DX_P%E444*DX%E4
      DX_P%E5555 = DX_P%E555*DX%E5
      DX_P%E6666 = DX_P%E666*DX%E6
      DX_P%E7777 = DX_P%E777*DX%E7
      DX_P%E8888 = DX_P%E888*DX%E8
      DX_P%E9999 = DX_P%E999*DX%E9
      DX_P%EAAAA = DX_P%EAAA*DX%EA
      DX_P%EBBBB = DX_P%EBBB*DX%EB
      DX_P%ECCCC = DX_P%ECCC*DX%EC
      DX_P%EDDDD = DX_P%EDDD*DX%ED
      DX_P%EEEEE = DX_P%EEEE*DX%EE
      DX_P%EFFFF = DX_P%EFFF*DX%EF
      DX_P%EGGGG = DX_P%EGGG*DX%EG
      DX_P%EHHHH = DX_P%EHHH*DX%EH
      DX_P%EIIII = DX_P%EIII*DX%EI
      DX_P%EJJJJ = DX_P%EJJJ*DX%EJ
      DX_P%EKKKK = DX_P%EKKK*DX%EK
      DX_P%ELLLL = DX_P%ELLL*DX%EL
      DX_P%EMMMM = DX_P%EMMM*DX%EM
      
      ! Sets order 4
      FACTOR = FACTOR * 4
      COEF = DER4 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 5
      RES%E11111 = RES%E11111+COEF*DX_P%E11111
      RES%E22222 = RES%E22222+COEF*DX_P%E22222
      RES%E33333 = RES%E33333+COEF*DX_P%E33333
      RES%E44444 = RES%E44444+COEF*DX_P%E44444
      RES%E55555 = RES%E55555+COEF*DX_P%E55555
      RES%E66666 = RES%E66666+COEF*DX_P%E66666
      RES%E77777 = RES%E77777+COEF*DX_P%E77777
      RES%E88888 = RES%E88888+COEF*DX_P%E88888
      RES%E99999 = RES%E99999+COEF*DX_P%E99999
      RES%EAAAAA = RES%EAAAAA+COEF*DX_P%EAAAAA
      RES%EBBBBB = RES%EBBBBB+COEF*DX_P%EBBBBB
      RES%ECCCCC = RES%ECCCCC+COEF*DX_P%ECCCCC
      RES%EDDDDD = RES%EDDDDD+COEF*DX_P%EDDDDD
      RES%EEEEEE = RES%EEEEEE+COEF*DX_P%EEEEEE
      RES%EFFFFF = RES%EFFFFF+COEF*DX_P%EFFFFF
      RES%EGGGGG = RES%EGGGGG+COEF*DX_P%EGGGGG
      RES%EHHHHH = RES%EHHHHH+COEF*DX_P%EHHHHH
      RES%EIIIII = RES%EIIIII+COEF*DX_P%EIIIII
      RES%EJJJJJ = RES%EJJJJJ+COEF*DX_P%EJJJJJ
      RES%EKKKKK = RES%EKKKKK+COEF*DX_P%EKKKKK
      RES%ELLLLL = RES%ELLLLL+COEF*DX_P%ELLLLL
      RES%EMMMMM = RES%EMMMMM+COEF*DX_P%EMMMMM
      ! Order 4
      RES%E1111 = RES%E1111+COEF*DX_P%E1111
      RES%E2222 = RES%E2222+COEF*DX_P%E2222
      RES%E3333 = RES%E3333+COEF*DX_P%E3333
      RES%E4444 = RES%E4444+COEF*DX_P%E4444
      RES%E5555 = RES%E5555+COEF*DX_P%E5555
      RES%E6666 = RES%E6666+COEF*DX_P%E6666
      RES%E7777 = RES%E7777+COEF*DX_P%E7777
      RES%E8888 = RES%E8888+COEF*DX_P%E8888
      RES%E9999 = RES%E9999+COEF*DX_P%E9999
      RES%EAAAA = RES%EAAAA+COEF*DX_P%EAAAA
      RES%EBBBB = RES%EBBBB+COEF*DX_P%EBBBB
      RES%ECCCC = RES%ECCCC+COEF*DX_P%ECCCC
      RES%EDDDD = RES%EDDDD+COEF*DX_P%EDDDD
      RES%EEEEE = RES%EEEEE+COEF*DX_P%EEEEE
      RES%EFFFF = RES%EFFFF+COEF*DX_P%EFFFF
      RES%EGGGG = RES%EGGGG+COEF*DX_P%EGGGG
      RES%EHHHH = RES%EHHHH+COEF*DX_P%EHHHH
      RES%EIIII = RES%EIIII+COEF*DX_P%EIIII
      RES%EJJJJ = RES%EJJJJ+COEF*DX_P%EJJJJ
      RES%EKKKK = RES%EKKKK+COEF*DX_P%EKKKK
      RES%ELLLL = RES%ELLLL+COEF*DX_P%ELLLL
      RES%EMMMM = RES%EMMMM+COEF*DX_P%EMMMM
      ! DX_P = DX_P * DX
      ! Order 5
      DX_P%E11111 = DX_P%E1111*DX%E1
      DX_P%E22222 = DX_P%E2222*DX%E2
      DX_P%E33333 = DX_P%E3333*DX%E3
      DX_P%E44444 = DX_P%E4444*DX%E4
      DX_P%E55555 = DX_P%E5555*DX%E5
      DX_P%E66666 = DX_P%E6666*DX%E6
      DX_P%E77777 = DX_P%E7777*DX%E7
      DX_P%E88888 = DX_P%E8888*DX%E8
      DX_P%E99999 = DX_P%E9999*DX%E9
      DX_P%EAAAAA = DX_P%EAAAA*DX%EA
      DX_P%EBBBBB = DX_P%EBBBB*DX%EB
      DX_P%ECCCCC = DX_P%ECCCC*DX%EC
      DX_P%EDDDDD = DX_P%EDDDD*DX%ED
      DX_P%EEEEEE = DX_P%EEEEE*DX%EE
      DX_P%EFFFFF = DX_P%EFFFF*DX%EF
      DX_P%EGGGGG = DX_P%EGGGG*DX%EG
      DX_P%EHHHHH = DX_P%EHHHH*DX%EH
      DX_P%EIIIII = DX_P%EIIII*DX%EI
      DX_P%EJJJJJ = DX_P%EJJJJ*DX%EJ
      DX_P%EKKKKK = DX_P%EKKKK*DX%EK
      DX_P%ELLLLL = DX_P%ELLLL*DX%EL
      DX_P%EMMMMM = DX_P%EMMMM*DX%EM
      
      ! Sets order 5
      FACTOR = FACTOR * 5
      COEF = DER5 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 5
      RES%E11111 = RES%E11111+COEF*DX_P%E11111
      RES%E22222 = RES%E22222+COEF*DX_P%E22222
      RES%E33333 = RES%E33333+COEF*DX_P%E33333
      RES%E44444 = RES%E44444+COEF*DX_P%E44444
      RES%E55555 = RES%E55555+COEF*DX_P%E55555
      RES%E66666 = RES%E66666+COEF*DX_P%E66666
      RES%E77777 = RES%E77777+COEF*DX_P%E77777
      RES%E88888 = RES%E88888+COEF*DX_P%E88888
      RES%E99999 = RES%E99999+COEF*DX_P%E99999
      RES%EAAAAA = RES%EAAAAA+COEF*DX_P%EAAAAA
      RES%EBBBBB = RES%EBBBBB+COEF*DX_P%EBBBBB
      RES%ECCCCC = RES%ECCCCC+COEF*DX_P%ECCCCC
      RES%EDDDDD = RES%EDDDDD+COEF*DX_P%EDDDDD
      RES%EEEEEE = RES%EEEEEE+COEF*DX_P%EEEEEE
      RES%EFFFFF = RES%EFFFFF+COEF*DX_P%EFFFFF
      RES%EGGGGG = RES%EGGGGG+COEF*DX_P%EGGGGG
      RES%EHHHHH = RES%EHHHHH+COEF*DX_P%EHHHHH
      RES%EIIIII = RES%EIIIII+COEF*DX_P%EIIIII
      RES%EJJJJJ = RES%EJJJJJ+COEF*DX_P%EJJJJJ
      RES%EKKKKK = RES%EKKKKK+COEF*DX_P%EKKKKK
      RES%ELLLLL = RES%ELLLLL+COEF*DX_P%ELLLLL
      RES%EMMMMM = RES%EMMMMM+COEF*DX_P%EMMMMM
      
   END FUNCTION DONUMM22N5_FEVAL


  ! SUBROUTINE DONUMM22N5_PPRINT_M_R(X, FMT)
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

  ! END SUBROUTINE DONUMM22N5_PPRINT_M_R

  ! SUBROUTINE DONUMM22N5_PPRINT_V_R(X, FMT)
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

  ! END SUBROUTINE DONUMM22N5_PPRINT_V_R

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
  PURE FUNCTION DONUMM22N5_det2x2(A) RESULT(det)

    IMPLICIT NONE

    TYPE(DONUMM22N5), INTENT(IN) :: A(2,2)   !! Matrix
    TYPE(DONUMM22N5)             :: det

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
  PURE FUNCTION DONUMM22N5_det3x3(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(DONUMM22N5), INTENT(IN) :: A(3,3)   !! Matrix
    TYPE(DONUMM22N5)             :: det

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
  PURE FUNCTION DONUMM22N5_det4x4(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(DONUMM22N5), INTENT(IN) :: A(4,4)   !! Matrix
    TYPE(DONUMM22N5)             :: det

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
  PURE FUNCTION DONUMM22N5_cross3(a,b) RESULT(v)
      
    IMPLICIT NONE 

    TYPE(DONUMM22N5), DIMENSION (3),INTENT(IN) :: a,b
    TYPE(DONUMM22N5), DIMENSION (3) :: v
    
    v(1) = a(2) * b(3) - a(3) * b(2)
    v(2) = a(3) * b(1) - a(1) * b(3)
    v(3) = a(1) * b(2) - a(2) * b(1)

  END FUNCTION DONUMM22N5_cross3
  !===================================================================================================! 

  !***************************************************************************************************! 
  !> @brief Norm of a 3 element vector. # There is an intrinsic function named norm2.
  !!
  !! @param[in] a: Vector of 3 reals (rank 1).
  !! @param[in] b: Vector of 3 reals (rank 1).
  !!
  !***************************************************************************************************!
  FUNCTION DONUMM22N5_norm2_3(v) RESULT(n)
     
    IMPLICIT NONE 

    TYPE(DONUMM22N5), INTENT(IN) :: v(3)
    TYPE(DONUMM22N5) :: n
     
    n = SQRT( v(1)*v(1) + v(2)*v(2) + v(3)*v(3) )

  END FUNCTION DONUMM22N5_norm2_3
  !===================================================================================================! 

  ELEMENTAL FUNCTION DONUMM22N5_DIVISION_OO(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(DONUMM22N5), INTENT(IN) :: X
      TYPE(DONUMM22N5), INTENT(IN) :: Y
      TYPE(DONUMM22N5) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION DONUMM22N5_DIVISION_OO

  ELEMENTAL FUNCTION DONUMM22N5_DIVISION_OR(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(DONUMM22N5), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: Y
      TYPE(DONUMM22N5) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION DONUMM22N5_DIVISION_OR

  ELEMENTAL FUNCTION DONUMM22N5_DIVISION_RO(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      REAL(DP), INTENT(IN) :: X
      TYPE(DONUMM22N5), INTENT(IN) :: Y
      TYPE(DONUMM22N5) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION DONUMM22N5_DIVISION_RO

  ELEMENTAL FUNCTION DONUMM22N5_REAL(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: X
      REAL(DP) :: RES

      RES = X%R

  END FUNCTION DONUMM22N5_REAL

  FUNCTION DONUMM22N5_SQRT(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5), INTENT(IN) :: X
      TYPE(DONUMM22N5) :: RES

      RES = X**0.5_DP

  END FUNCTION DONUMM22N5_SQRT

   ELEMENTAL FUNCTION DONUMM22N5_TAN(X) RESULT(RES)

      TYPE(DONUMM22N5), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4,DER5
      TYPE(DONUMM22N5) :: RES
      
      DER0 = TAN(X%R)
      DER1 = TAN(X%R)**2 + 1
      DER2 = 2*(TAN(X%R)**2 + 1)*TAN(X%R)
      DER3 = 2*(TAN(X%R)**2 + 1)*(3*TAN(X%R)**2 + 1)
      DER4 = 8*(TAN(X%R)**2 + 1)*(3*TAN(X%R)**2 + 2)*TAN(X%R)
      DER5 = 8*(TAN(X%R)**2 + 1)*(2*(TAN(X%R)**2 + 1)**2 + 11*(TAN(X%R)**2 + 1 &
      )*TAN(X%R)**2 + 2*TAN(X%R)**4)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4,DER5)

   END FUNCTION DONUMM22N5_TAN

   ELEMENTAL FUNCTION DONUMM22N5_COS(X) RESULT(RES)

      TYPE(DONUMM22N5), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4,DER5
      TYPE(DONUMM22N5) :: RES
      
      DER0 = COS(X%R)
      DER1 = -SIN(X%R)
      DER2 = -COS(X%R)
      DER3 = SIN(X%R)
      DER4 = COS(X%R)
      DER5 = -SIN(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4,DER5)

   END FUNCTION DONUMM22N5_COS

   ELEMENTAL FUNCTION DONUMM22N5_SIN(X) RESULT(RES)

      TYPE(DONUMM22N5), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4,DER5
      TYPE(DONUMM22N5) :: RES
      
      DER0 = SIN(X%R)
      DER1 = COS(X%R)
      DER2 = -SIN(X%R)
      DER3 = -COS(X%R)
      DER4 = SIN(X%R)
      DER5 = COS(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4,DER5)

   END FUNCTION DONUMM22N5_SIN

   ELEMENTAL FUNCTION DONUMM22N5_ATAN(X) RESULT(RES)

      TYPE(DONUMM22N5), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4,DER5
      TYPE(DONUMM22N5) :: RES
      
      DER0 = ATAN(X%R)
      DER1 = 1D0/(X%R**2 + 1)
      DER2 = -2*X%R/(X%R**2 + 1)**2
      DER3 = 2*(4*X%R**2/(X%R**2 + 1) - 1)/(X%R**2 + 1)**2
      DER4 = 24*X%R*(-2*X%R**2/(X%R**2 + 1) + 1)/(X%R**2 + 1)**3
      DER5 = 24*(16*X%R**4/(X%R**2 + 1)**2 - 12*X%R**2/(X%R**2 + 1) + 1)/(X%R &
      **2 + 1)**3

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4,DER5)

   END FUNCTION DONUMM22N5_ATAN

   ELEMENTAL FUNCTION DONUMM22N5_ACOS(X) RESULT(RES)

      TYPE(DONUMM22N5), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4,DER5
      TYPE(DONUMM22N5) :: RES
      
      DER0 = ACOS(X%R)
      DER1 = -1/SQRT(1 - X%R**2)
      DER2 = -X%R/(1 - X%R**2)**(3.0D0/2.0D0)
      DER3 = -(3*X%R**2/(1 - X%R**2) + 1)/(1 - X%R**2)**(3.0D0/2.0D0)
      DER4 = -3*X%R*(5*X%R**2/(1 - X%R**2) + 3)/(1 - X%R**2)**(5.0D0/2.0D0)
      DER5 = -3*(35*X%R**4/(1 - X%R**2)**2 + 30*X%R**2/(1 - X%R**2) + 3)/(1 - &
      X%R**2)**(5.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4,DER5)

   END FUNCTION DONUMM22N5_ACOS

   ELEMENTAL FUNCTION DONUMM22N5_ASIN(X) RESULT(RES)

      TYPE(DONUMM22N5), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4,DER5
      TYPE(DONUMM22N5) :: RES
      
      DER0 = ASIN(X%R)
      DER1 = 1/SQRT(1 - X%R**2)
      DER2 = X%R/(1 - X%R**2)**(3.0D0/2.0D0)
      DER3 = (3*X%R**2/(1 - X%R**2) + 1)/(1 - X%R**2)**(3.0D0/2.0D0)
      DER4 = 3*X%R*(5*X%R**2/(1 - X%R**2) + 3)/(1 - X%R**2)**(5.0D0/2.0D0)
      DER5 = 3*(35*X%R**4/(1 - X%R**2)**2 + 30*X%R**2/(1 - X%R**2) + 3)/(1 - X &
      %R**2)**(5.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4,DER5)

   END FUNCTION DONUMM22N5_ASIN

   ELEMENTAL FUNCTION DONUMM22N5_TANH(X) RESULT(RES)

      TYPE(DONUMM22N5), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4,DER5
      TYPE(DONUMM22N5) :: RES
      
      DER0 = TANH(X%R)
      DER1 = 1 - TANH(X%R)**2
      DER2 = 2*(TANH(X%R)**2 - 1)*TANH(X%R)
      DER3 = -2*(TANH(X%R)**2 - 1)*(3*TANH(X%R)**2 - 1)
      DER4 = 8*(TANH(X%R)**2 - 1)*(3*TANH(X%R)**2 - 2)*TANH(X%R)
      DER5 = -8*(TANH(X%R)**2 - 1)*(2*(TANH(X%R)**2 - 1)**2 + 11*(TANH(X%R)**2 &
      - 1)*TANH(X%R)**2 + 2*TANH(X%R)**4)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4,DER5)

   END FUNCTION DONUMM22N5_TANH

   ELEMENTAL FUNCTION DONUMM22N5_COSH(X) RESULT(RES)

      TYPE(DONUMM22N5), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4,DER5
      TYPE(DONUMM22N5) :: RES
      
      DER0 = COSH(X%R)
      DER1 = SINH(X%R)
      DER2 = COSH(X%R)
      DER3 = SINH(X%R)
      DER4 = COSH(X%R)
      DER5 = SINH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4,DER5)

   END FUNCTION DONUMM22N5_COSH

   ELEMENTAL FUNCTION DONUMM22N5_SINH(X) RESULT(RES)

      TYPE(DONUMM22N5), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4,DER5
      TYPE(DONUMM22N5) :: RES
      
      DER0 = SINH(X%R)
      DER1 = COSH(X%R)
      DER2 = SINH(X%R)
      DER3 = COSH(X%R)
      DER4 = SINH(X%R)
      DER5 = COSH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4,DER5)

   END FUNCTION DONUMM22N5_SINH

   ELEMENTAL FUNCTION DONUMM22N5_EXP(X) RESULT(RES)

      TYPE(DONUMM22N5), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4,DER5
      TYPE(DONUMM22N5) :: RES
      
      DER0 = EXP(X%R)
      DER1 = EXP(X%R)
      DER2 = EXP(X%R)
      DER3 = EXP(X%R)
      DER4 = EXP(X%R)
      DER5 = EXP(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4,DER5)

   END FUNCTION DONUMM22N5_EXP

   ELEMENTAL FUNCTION DONUMM22N5_LOG(X) RESULT(RES)

      TYPE(DONUMM22N5), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4,DER5
      TYPE(DONUMM22N5) :: RES
      
      DER0 = LOG(X%R)
      DER1 = 1D0/X%R
      DER2 = -1/X%R**2
      DER3 = 2/X%R**3
      DER4 = -6/X%R**4
      DER5 = 24/X%R**5

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4,DER5)

   END FUNCTION DONUMM22N5_LOG

   ELEMENTAL FUNCTION DONUMM22N5_POW_OR(X,E) RESULT(RES)

      TYPE(DONUMM22N5), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4,DER5
      TYPE(DONUMM22N5) :: RES
      
      DER0=0.0d0
      DER1=0.0d0
      DER2=0.0d0
      DER3=0.0d0
      DER4=0.0d0
      DER5=0.0d0
      
      DER0 = X%R**E
      IF ((E-0)/=0.0d0) THEN
         DER1 = E*X%R**(E - 1)
         IF ((E-1)/=0.0d0) THEN
            DER2 = E*X%R**(E - 2)*(E - 1)
            IF ((E-2)/=0.0d0) THEN
               DER3 = E*X%R**(E - 3)*(E**2 - 3*E + 2)
               IF ((E-3)/=0.0d0) THEN
                  DER4 = E*X%R**(E - 4)*(E**3 - 6*E**2 + 11*E - 6)
                  IF ((E-4)/=0.0d0) THEN
                     DER5 = E*X%R**(E - 5)*(E**4 - 10*E**3 + 35*E**2 - 50*E + 24)
                  END IF
               END IF
            END IF
         END IF
      END IF

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4,DER5)

   END FUNCTION DONUMM22N5_POW_OR

   ELEMENTAL FUNCTION DONUMM22N5_POW_RO(E,X) RESULT(RES)

      TYPE(DONUMM22N5), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4,DER5
      TYPE(DONUMM22N5) :: RES
      
      
      DER0 = E**X%R
      DER1 = E**X%R*LOG(E)
      DER2 = E**X%R*LOG(E)**2
      DER3 = E**X%R*LOG(E)**3
      DER4 = E**X%R*LOG(E)**4
      DER5 = E**X%R*LOG(E)**5

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4,DER5)

   END FUNCTION DONUMM22N5_POW_RO

   ELEMENTAL FUNCTION DONUMM22N5_F2EVAL(X,Y,DER0_0,DER1_0,DER1_1, &
                                    DER2_0,DER2_1,DER2_2,DER3_0, &
                                    DER3_1,DER3_2,DER3_3,DER4_0, &
                                    DER4_1,DER4_2,DER4_3,DER4_4, &
                                    DER5_0,DER5_1,DER5_2,DER5_3, &
                                    DER5_4,DER5_5)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: COEF, DELTA
      TYPE(DONUMM22N5), INTENT(IN)  :: X,Y
      REAL(DP), INTENT(IN)  :: DER0_0,DER1_0,DER1_1, &
                               DER2_0,DER2_1,DER2_2,DER3_0, &
                               DER3_1,DER3_2,DER3_3,DER4_0, &
                               DER4_1,DER4_2,DER4_3,DER4_4, &
                               DER5_0,DER5_1,DER5_2,DER5_3, &
                               DER5_4,DER5_5
      TYPE(DONUMM22N5) :: RES
      TYPE(DONUMM22N5) :: DX, DY

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

      

      ! Set order 5
      COEF = DER5_0 / 120.0_DP
      RES = RES + COEF*DX*DX*DX*DX*DX

      COEF = DER5_1 / 24.0_DP
      RES = RES + COEF*DX*DX*DX*DX*DY

      COEF = DER5_2 / 12.0_DP
      RES = RES + COEF*DX*DX*DX*DY*DY

      COEF = DER5_3 / 12.0_DP
      RES = RES + COEF*DX*DX*DY*DY*DY

      COEF = DER5_4 / 24.0_DP
      RES = RES + COEF*DX*DY*DY*DY*DY

      COEF = DER5_5 / 120.0_DP
      RES = RES + COEF*DY*DY*DY*DY*DY

      

   END FUNCTION DONUMM22N5_F2EVAL


   ELEMENTAL FUNCTION DONUMM22N5_POW_OO(X,Y) RESULT(RES)

      TYPE(DONUMM22N5), INTENT(IN) :: X, Y
      REAL(DP) :: DER0_0,DER1_0,DER1_1,DER2_0,DER2_1,DER2_2,DER3_0,DER3_1,DER3_2,DER3_3,DER4_0,DER4_1,DER4_2,DER4_3,DER4_4,DER5_0,DER5_1,DER5_2,DER5_3,DER5_4,DER5_5
      TYPE(DONUMM22N5) :: RES
      
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
      DER5_0 = X%R**Y%R*Y%R*(Y%R**4 - 10*Y%R**3 + 35*Y%R**2 - 50*Y%R + 24)/X%R &
      **5
      DER5_1 = X%R**Y%R*(Y%R**4*LOG(X%R) - 6*Y%R**3*LOG(X%R) + 4*Y%R**3 + 11*Y &
      %R**2*LOG(X%R) - 18*Y%R**2 - 6*Y%R*LOG(X%R) + 22*Y%R - 6)/X%R**4
      DER5_2 = X%R**Y%R*(Y%R**3*LOG(X%R)**2 - 3*Y%R**2*LOG(X%R)**2 + 6*Y%R**2* &
      LOG(X%R) + 2*Y%R*LOG(X%R)**2 - 12*Y%R*LOG(X%R) + 6*Y%R + 4*LOG(X% &
      R) - 6)/X%R**3
      DER5_3 = X%R**Y%R*(Y%R**2*LOG(X%R)**2 - Y%R*LOG(X%R)**2 + 6*Y%R*LOG(X%R &
      ) - 3*LOG(X%R) + 6)*LOG(X%R)/X%R**2
      DER5_4 = X%R**Y%R*(Y%R*LOG(X%R) + 4)*LOG(X%R)**3/X%R
      DER5_5 = X%R**Y%R*LOG(X%R)**5

      RES = F2EVAL(X,Y,DER0_0,DER1_0,DER1_1,DER2_0,DER2_1,DER2_2,DER3_0,DER3_1,DER3_2,DER3_3,DER4_0,DER4_1,DER4_2,DER4_3,DER4_4,DER5_0,DER5_1,DER5_2,DER5_3,DER5_4,DER5_5)

   END FUNCTION DONUMM22N5_POW_OO


   FUNCTION DONUMM22N5_INV2X2(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5) , INTENT(IN) :: A(2,2) 
      TYPE(DONUMM22N5) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(DONUMM22N5) :: RES(SIZE(A,1),SIZE(A,2)) 

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
      RES%E888=-MATMUL(RES%R,(MATMUL(A%E888,RES%R)+MATMUL(A%E8,RES%E88)+&
              MATMUL(A%E88,RES%E8)))
      RES%E999=-MATMUL(RES%R,(MATMUL(A%E999,RES%R)+MATMUL(A%E9,RES%E99)+&
              MATMUL(A%E99,RES%E9)))
      RES%EAAA=-MATMUL(RES%R,(MATMUL(A%EAAA,RES%R)+MATMUL(A%EA,RES%EAA)+&
              MATMUL(A%EAA,RES%EA)))
      RES%EBBB=-MATMUL(RES%R,(MATMUL(A%EBBB,RES%R)+MATMUL(A%EB,RES%EBB)+&
              MATMUL(A%EBB,RES%EB)))
      RES%ECCC=-MATMUL(RES%R,(MATMUL(A%ECCC,RES%R)+MATMUL(A%EC,RES%ECC)+&
              MATMUL(A%ECC,RES%EC)))
      RES%EDDD=-MATMUL(RES%R,(MATMUL(A%EDDD,RES%R)+MATMUL(A%ED,RES%EDD)+&
              MATMUL(A%EDD,RES%ED)))
      RES%EEEE=-MATMUL(RES%R,(MATMUL(A%EEEE,RES%R)+MATMUL(A%EE,RES%EEE)+&
              MATMUL(A%EEE,RES%EE)))
      RES%EFFF=-MATMUL(RES%R,(MATMUL(A%EFFF,RES%R)+MATMUL(A%EF,RES%EFF)+&
              MATMUL(A%EFF,RES%EF)))
      RES%EGGG=-MATMUL(RES%R,(MATMUL(A%EGGG,RES%R)+MATMUL(A%EG,RES%EGG)+&
              MATMUL(A%EGG,RES%EG)))
      RES%EHHH=-MATMUL(RES%R,(MATMUL(A%EHHH,RES%R)+MATMUL(A%EH,RES%EHH)+&
              MATMUL(A%EHH,RES%EH)))
      RES%EIII=-MATMUL(RES%R,(MATMUL(A%EIII,RES%R)+MATMUL(A%EI,RES%EII)+&
              MATMUL(A%EII,RES%EI)))
      RES%EJJJ=-MATMUL(RES%R,(MATMUL(A%EJJJ,RES%R)+MATMUL(A%EJ,RES%EJJ)+&
              MATMUL(A%EJJ,RES%EJ)))
      RES%EKKK=-MATMUL(RES%R,(MATMUL(A%EKKK,RES%R)+MATMUL(A%EK,RES%EKK)+&
              MATMUL(A%EKK,RES%EK)))
      RES%ELLL=-MATMUL(RES%R,(MATMUL(A%ELLL,RES%R)+MATMUL(A%EL,RES%ELL)+&
              MATMUL(A%ELL,RES%EL)))
      RES%EMMM=-MATMUL(RES%R,(MATMUL(A%EMMM,RES%R)+MATMUL(A%EM,RES%EMM)+&
              MATMUL(A%EMM,RES%EM)))

      ! Order 4
      RES%E1111=-MATMUL(RES%R,(MATMUL(A%E1111,RES%R)+MATMUL(A%E1,RES%E111)+&
               MATMUL(A%E111,RES%E1)+MATMUL(A%E11,RES%E11)))
      RES%E2222=-MATMUL(RES%R,(MATMUL(A%E2222,RES%R)+MATMUL(A%E2,RES%E222)+&
               MATMUL(A%E222,RES%E2)+MATMUL(A%E22,RES%E22)))
      RES%E3333=-MATMUL(RES%R,(MATMUL(A%E3333,RES%R)+MATMUL(A%E3,RES%E333)+&
               MATMUL(A%E333,RES%E3)+MATMUL(A%E33,RES%E33)))
      RES%E4444=-MATMUL(RES%R,(MATMUL(A%E4444,RES%R)+MATMUL(A%E4,RES%E444)+&
               MATMUL(A%E444,RES%E4)+MATMUL(A%E44,RES%E44)))
      RES%E5555=-MATMUL(RES%R,(MATMUL(A%E5555,RES%R)+MATMUL(A%E5,RES%E555)+&
               MATMUL(A%E555,RES%E5)+MATMUL(A%E55,RES%E55)))
      RES%E6666=-MATMUL(RES%R,(MATMUL(A%E6666,RES%R)+MATMUL(A%E6,RES%E666)+&
               MATMUL(A%E666,RES%E6)+MATMUL(A%E66,RES%E66)))
      RES%E7777=-MATMUL(RES%R,(MATMUL(A%E7777,RES%R)+MATMUL(A%E7,RES%E777)+&
               MATMUL(A%E777,RES%E7)+MATMUL(A%E77,RES%E77)))
      RES%E8888=-MATMUL(RES%R,(MATMUL(A%E8888,RES%R)+MATMUL(A%E8,RES%E888)+&
               MATMUL(A%E888,RES%E8)+MATMUL(A%E88,RES%E88)))
      RES%E9999=-MATMUL(RES%R,(MATMUL(A%E9999,RES%R)+MATMUL(A%E9,RES%E999)+&
               MATMUL(A%E999,RES%E9)+MATMUL(A%E99,RES%E99)))
      RES%EAAAA=-MATMUL(RES%R,(MATMUL(A%EAAAA,RES%R)+MATMUL(A%EA,RES%EAAA)+&
               MATMUL(A%EAAA,RES%EA)+MATMUL(A%EAA,RES%EAA)))
      RES%EBBBB=-MATMUL(RES%R,(MATMUL(A%EBBBB,RES%R)+MATMUL(A%EB,RES%EBBB)+&
               MATMUL(A%EBBB,RES%EB)+MATMUL(A%EBB,RES%EBB)))
      RES%ECCCC=-MATMUL(RES%R,(MATMUL(A%ECCCC,RES%R)+MATMUL(A%EC,RES%ECCC)+&
               MATMUL(A%ECCC,RES%EC)+MATMUL(A%ECC,RES%ECC)))
      RES%EDDDD=-MATMUL(RES%R,(MATMUL(A%EDDDD,RES%R)+MATMUL(A%ED,RES%EDDD)+&
               MATMUL(A%EDDD,RES%ED)+MATMUL(A%EDD,RES%EDD)))
      RES%EEEEE=-MATMUL(RES%R,(MATMUL(A%EEEEE,RES%R)+MATMUL(A%EE,RES%EEEE)+&
               MATMUL(A%EEEE,RES%EE)+MATMUL(A%EEE,RES%EEE)))
      RES%EFFFF=-MATMUL(RES%R,(MATMUL(A%EFFFF,RES%R)+MATMUL(A%EF,RES%EFFF)+&
               MATMUL(A%EFFF,RES%EF)+MATMUL(A%EFF,RES%EFF)))
      RES%EGGGG=-MATMUL(RES%R,(MATMUL(A%EGGGG,RES%R)+MATMUL(A%EG,RES%EGGG)+&
               MATMUL(A%EGGG,RES%EG)+MATMUL(A%EGG,RES%EGG)))
      RES%EHHHH=-MATMUL(RES%R,(MATMUL(A%EHHHH,RES%R)+MATMUL(A%EH,RES%EHHH)+&
               MATMUL(A%EHHH,RES%EH)+MATMUL(A%EHH,RES%EHH)))
      RES%EIIII=-MATMUL(RES%R,(MATMUL(A%EIIII,RES%R)+MATMUL(A%EI,RES%EIII)+&
               MATMUL(A%EIII,RES%EI)+MATMUL(A%EII,RES%EII)))
      RES%EJJJJ=-MATMUL(RES%R,(MATMUL(A%EJJJJ,RES%R)+MATMUL(A%EJ,RES%EJJJ)+&
               MATMUL(A%EJJJ,RES%EJ)+MATMUL(A%EJJ,RES%EJJ)))
      RES%EKKKK=-MATMUL(RES%R,(MATMUL(A%EKKKK,RES%R)+MATMUL(A%EK,RES%EKKK)+&
               MATMUL(A%EKKK,RES%EK)+MATMUL(A%EKK,RES%EKK)))
      RES%ELLLL=-MATMUL(RES%R,(MATMUL(A%ELLLL,RES%R)+MATMUL(A%EL,RES%ELLL)+&
               MATMUL(A%ELLL,RES%EL)+MATMUL(A%ELL,RES%ELL)))
      RES%EMMMM=-MATMUL(RES%R,(MATMUL(A%EMMMM,RES%R)+MATMUL(A%EM,RES%EMMM)+&
               MATMUL(A%EMMM,RES%EM)+MATMUL(A%EMM,RES%EMM)))

      ! Order 5
      RES%E11111=-MATMUL(RES%R,(MATMUL(A%E11111,RES%R)+MATMUL(A%E1,RES%E1111)+&
                MATMUL(A%E1111,RES%E1)+MATMUL(A%E11,RES%E111)+MATMUL(A%E111,RES%E11)))
      RES%E22222=-MATMUL(RES%R,(MATMUL(A%E22222,RES%R)+MATMUL(A%E2,RES%E2222)+&
                MATMUL(A%E2222,RES%E2)+MATMUL(A%E22,RES%E222)+MATMUL(A%E222,RES%E22)))
      RES%E33333=-MATMUL(RES%R,(MATMUL(A%E33333,RES%R)+MATMUL(A%E3,RES%E3333)+&
                MATMUL(A%E3333,RES%E3)+MATMUL(A%E33,RES%E333)+MATMUL(A%E333,RES%E33)))
      RES%E44444=-MATMUL(RES%R,(MATMUL(A%E44444,RES%R)+MATMUL(A%E4,RES%E4444)+&
                MATMUL(A%E4444,RES%E4)+MATMUL(A%E44,RES%E444)+MATMUL(A%E444,RES%E44)))
      RES%E55555=-MATMUL(RES%R,(MATMUL(A%E55555,RES%R)+MATMUL(A%E5,RES%E5555)+&
                MATMUL(A%E5555,RES%E5)+MATMUL(A%E55,RES%E555)+MATMUL(A%E555,RES%E55)))
      RES%E66666=-MATMUL(RES%R,(MATMUL(A%E66666,RES%R)+MATMUL(A%E6,RES%E6666)+&
                MATMUL(A%E6666,RES%E6)+MATMUL(A%E66,RES%E666)+MATMUL(A%E666,RES%E66)))
      RES%E77777=-MATMUL(RES%R,(MATMUL(A%E77777,RES%R)+MATMUL(A%E7,RES%E7777)+&
                MATMUL(A%E7777,RES%E7)+MATMUL(A%E77,RES%E777)+MATMUL(A%E777,RES%E77)))
      RES%E88888=-MATMUL(RES%R,(MATMUL(A%E88888,RES%R)+MATMUL(A%E8,RES%E8888)+&
                MATMUL(A%E8888,RES%E8)+MATMUL(A%E88,RES%E888)+MATMUL(A%E888,RES%E88)))
      RES%E99999=-MATMUL(RES%R,(MATMUL(A%E99999,RES%R)+MATMUL(A%E9,RES%E9999)+&
                MATMUL(A%E9999,RES%E9)+MATMUL(A%E99,RES%E999)+MATMUL(A%E999,RES%E99)))
      RES%EAAAAA=-MATMUL(RES%R,(MATMUL(A%EAAAAA,RES%R)+MATMUL(A%EA,RES%EAAAA)+&
                MATMUL(A%EAAAA,RES%EA)+MATMUL(A%EAA,RES%EAAA)+MATMUL(A%EAAA,RES%EAA)))
      RES%EBBBBB=-MATMUL(RES%R,(MATMUL(A%EBBBBB,RES%R)+MATMUL(A%EB,RES%EBBBB)+&
                MATMUL(A%EBBBB,RES%EB)+MATMUL(A%EBB,RES%EBBB)+MATMUL(A%EBBB,RES%EBB)))
      RES%ECCCCC=-MATMUL(RES%R,(MATMUL(A%ECCCCC,RES%R)+MATMUL(A%EC,RES%ECCCC)+&
                MATMUL(A%ECCCC,RES%EC)+MATMUL(A%ECC,RES%ECCC)+MATMUL(A%ECCC,RES%ECC)))
      RES%EDDDDD=-MATMUL(RES%R,(MATMUL(A%EDDDDD,RES%R)+MATMUL(A%ED,RES%EDDDD)+&
                MATMUL(A%EDDDD,RES%ED)+MATMUL(A%EDD,RES%EDDD)+MATMUL(A%EDDD,RES%EDD)))
      RES%EEEEEE=-MATMUL(RES%R,(MATMUL(A%EEEEEE,RES%R)+MATMUL(A%EE,RES%EEEEE)+&
                MATMUL(A%EEEEE,RES%EE)+MATMUL(A%EEE,RES%EEEE)+MATMUL(A%EEEE,RES%EEE)))
      RES%EFFFFF=-MATMUL(RES%R,(MATMUL(A%EFFFFF,RES%R)+MATMUL(A%EF,RES%EFFFF)+&
                MATMUL(A%EFFFF,RES%EF)+MATMUL(A%EFF,RES%EFFF)+MATMUL(A%EFFF,RES%EFF)))
      RES%EGGGGG=-MATMUL(RES%R,(MATMUL(A%EGGGGG,RES%R)+MATMUL(A%EG,RES%EGGGG)+&
                MATMUL(A%EGGGG,RES%EG)+MATMUL(A%EGG,RES%EGGG)+MATMUL(A%EGGG,RES%EGG)))
      RES%EHHHHH=-MATMUL(RES%R,(MATMUL(A%EHHHHH,RES%R)+MATMUL(A%EH,RES%EHHHH)+&
                MATMUL(A%EHHHH,RES%EH)+MATMUL(A%EHH,RES%EHHH)+MATMUL(A%EHHH,RES%EHH)))
      RES%EIIIII=-MATMUL(RES%R,(MATMUL(A%EIIIII,RES%R)+MATMUL(A%EI,RES%EIIII)+&
                MATMUL(A%EIIII,RES%EI)+MATMUL(A%EII,RES%EIII)+MATMUL(A%EIII,RES%EII)))
      RES%EJJJJJ=-MATMUL(RES%R,(MATMUL(A%EJJJJJ,RES%R)+MATMUL(A%EJ,RES%EJJJJ)+&
                MATMUL(A%EJJJJ,RES%EJ)+MATMUL(A%EJJ,RES%EJJJ)+MATMUL(A%EJJJ,RES%EJJ)))
      RES%EKKKKK=-MATMUL(RES%R,(MATMUL(A%EKKKKK,RES%R)+MATMUL(A%EK,RES%EKKKK)+&
                MATMUL(A%EKKKK,RES%EK)+MATMUL(A%EKK,RES%EKKK)+MATMUL(A%EKKK,RES%EKK)))
      RES%ELLLLL=-MATMUL(RES%R,(MATMUL(A%ELLLLL,RES%R)+MATMUL(A%EL,RES%ELLLL)+&
                MATMUL(A%ELLLL,RES%EL)+MATMUL(A%ELL,RES%ELLL)+MATMUL(A%ELLL,RES%ELL)))
      RES%EMMMMM=-MATMUL(RES%R,(MATMUL(A%EMMMMM,RES%R)+MATMUL(A%EM,RES%EMMMM)+&
                MATMUL(A%EMMMM,RES%EM)+MATMUL(A%EMM,RES%EMMM)+MATMUL(A%EMMM,RES%EMM)))

   END FUNCTION DONUMM22N5_INV2X2

   FUNCTION DONUMM22N5_INV3X3(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5) , INTENT(IN) :: A(3,3) 
      TYPE(DONUMM22N5) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(DONUMM22N5) :: RES(SIZE(A,1),SIZE(A,2)) 

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
      RES%E888=-MATMUL(RES%R,(MATMUL(A%E888,RES%R)+MATMUL(A%E8,RES%E88)+&
              MATMUL(A%E88,RES%E8)))
      RES%E999=-MATMUL(RES%R,(MATMUL(A%E999,RES%R)+MATMUL(A%E9,RES%E99)+&
              MATMUL(A%E99,RES%E9)))
      RES%EAAA=-MATMUL(RES%R,(MATMUL(A%EAAA,RES%R)+MATMUL(A%EA,RES%EAA)+&
              MATMUL(A%EAA,RES%EA)))
      RES%EBBB=-MATMUL(RES%R,(MATMUL(A%EBBB,RES%R)+MATMUL(A%EB,RES%EBB)+&
              MATMUL(A%EBB,RES%EB)))
      RES%ECCC=-MATMUL(RES%R,(MATMUL(A%ECCC,RES%R)+MATMUL(A%EC,RES%ECC)+&
              MATMUL(A%ECC,RES%EC)))
      RES%EDDD=-MATMUL(RES%R,(MATMUL(A%EDDD,RES%R)+MATMUL(A%ED,RES%EDD)+&
              MATMUL(A%EDD,RES%ED)))
      RES%EEEE=-MATMUL(RES%R,(MATMUL(A%EEEE,RES%R)+MATMUL(A%EE,RES%EEE)+&
              MATMUL(A%EEE,RES%EE)))
      RES%EFFF=-MATMUL(RES%R,(MATMUL(A%EFFF,RES%R)+MATMUL(A%EF,RES%EFF)+&
              MATMUL(A%EFF,RES%EF)))
      RES%EGGG=-MATMUL(RES%R,(MATMUL(A%EGGG,RES%R)+MATMUL(A%EG,RES%EGG)+&
              MATMUL(A%EGG,RES%EG)))
      RES%EHHH=-MATMUL(RES%R,(MATMUL(A%EHHH,RES%R)+MATMUL(A%EH,RES%EHH)+&
              MATMUL(A%EHH,RES%EH)))
      RES%EIII=-MATMUL(RES%R,(MATMUL(A%EIII,RES%R)+MATMUL(A%EI,RES%EII)+&
              MATMUL(A%EII,RES%EI)))
      RES%EJJJ=-MATMUL(RES%R,(MATMUL(A%EJJJ,RES%R)+MATMUL(A%EJ,RES%EJJ)+&
              MATMUL(A%EJJ,RES%EJ)))
      RES%EKKK=-MATMUL(RES%R,(MATMUL(A%EKKK,RES%R)+MATMUL(A%EK,RES%EKK)+&
              MATMUL(A%EKK,RES%EK)))
      RES%ELLL=-MATMUL(RES%R,(MATMUL(A%ELLL,RES%R)+MATMUL(A%EL,RES%ELL)+&
              MATMUL(A%ELL,RES%EL)))
      RES%EMMM=-MATMUL(RES%R,(MATMUL(A%EMMM,RES%R)+MATMUL(A%EM,RES%EMM)+&
              MATMUL(A%EMM,RES%EM)))

      ! Order 4
      RES%E1111=-MATMUL(RES%R,(MATMUL(A%E1111,RES%R)+MATMUL(A%E1,RES%E111)+&
               MATMUL(A%E111,RES%E1)+MATMUL(A%E11,RES%E11)))
      RES%E2222=-MATMUL(RES%R,(MATMUL(A%E2222,RES%R)+MATMUL(A%E2,RES%E222)+&
               MATMUL(A%E222,RES%E2)+MATMUL(A%E22,RES%E22)))
      RES%E3333=-MATMUL(RES%R,(MATMUL(A%E3333,RES%R)+MATMUL(A%E3,RES%E333)+&
               MATMUL(A%E333,RES%E3)+MATMUL(A%E33,RES%E33)))
      RES%E4444=-MATMUL(RES%R,(MATMUL(A%E4444,RES%R)+MATMUL(A%E4,RES%E444)+&
               MATMUL(A%E444,RES%E4)+MATMUL(A%E44,RES%E44)))
      RES%E5555=-MATMUL(RES%R,(MATMUL(A%E5555,RES%R)+MATMUL(A%E5,RES%E555)+&
               MATMUL(A%E555,RES%E5)+MATMUL(A%E55,RES%E55)))
      RES%E6666=-MATMUL(RES%R,(MATMUL(A%E6666,RES%R)+MATMUL(A%E6,RES%E666)+&
               MATMUL(A%E666,RES%E6)+MATMUL(A%E66,RES%E66)))
      RES%E7777=-MATMUL(RES%R,(MATMUL(A%E7777,RES%R)+MATMUL(A%E7,RES%E777)+&
               MATMUL(A%E777,RES%E7)+MATMUL(A%E77,RES%E77)))
      RES%E8888=-MATMUL(RES%R,(MATMUL(A%E8888,RES%R)+MATMUL(A%E8,RES%E888)+&
               MATMUL(A%E888,RES%E8)+MATMUL(A%E88,RES%E88)))
      RES%E9999=-MATMUL(RES%R,(MATMUL(A%E9999,RES%R)+MATMUL(A%E9,RES%E999)+&
               MATMUL(A%E999,RES%E9)+MATMUL(A%E99,RES%E99)))
      RES%EAAAA=-MATMUL(RES%R,(MATMUL(A%EAAAA,RES%R)+MATMUL(A%EA,RES%EAAA)+&
               MATMUL(A%EAAA,RES%EA)+MATMUL(A%EAA,RES%EAA)))
      RES%EBBBB=-MATMUL(RES%R,(MATMUL(A%EBBBB,RES%R)+MATMUL(A%EB,RES%EBBB)+&
               MATMUL(A%EBBB,RES%EB)+MATMUL(A%EBB,RES%EBB)))
      RES%ECCCC=-MATMUL(RES%R,(MATMUL(A%ECCCC,RES%R)+MATMUL(A%EC,RES%ECCC)+&
               MATMUL(A%ECCC,RES%EC)+MATMUL(A%ECC,RES%ECC)))
      RES%EDDDD=-MATMUL(RES%R,(MATMUL(A%EDDDD,RES%R)+MATMUL(A%ED,RES%EDDD)+&
               MATMUL(A%EDDD,RES%ED)+MATMUL(A%EDD,RES%EDD)))
      RES%EEEEE=-MATMUL(RES%R,(MATMUL(A%EEEEE,RES%R)+MATMUL(A%EE,RES%EEEE)+&
               MATMUL(A%EEEE,RES%EE)+MATMUL(A%EEE,RES%EEE)))
      RES%EFFFF=-MATMUL(RES%R,(MATMUL(A%EFFFF,RES%R)+MATMUL(A%EF,RES%EFFF)+&
               MATMUL(A%EFFF,RES%EF)+MATMUL(A%EFF,RES%EFF)))
      RES%EGGGG=-MATMUL(RES%R,(MATMUL(A%EGGGG,RES%R)+MATMUL(A%EG,RES%EGGG)+&
               MATMUL(A%EGGG,RES%EG)+MATMUL(A%EGG,RES%EGG)))
      RES%EHHHH=-MATMUL(RES%R,(MATMUL(A%EHHHH,RES%R)+MATMUL(A%EH,RES%EHHH)+&
               MATMUL(A%EHHH,RES%EH)+MATMUL(A%EHH,RES%EHH)))
      RES%EIIII=-MATMUL(RES%R,(MATMUL(A%EIIII,RES%R)+MATMUL(A%EI,RES%EIII)+&
               MATMUL(A%EIII,RES%EI)+MATMUL(A%EII,RES%EII)))
      RES%EJJJJ=-MATMUL(RES%R,(MATMUL(A%EJJJJ,RES%R)+MATMUL(A%EJ,RES%EJJJ)+&
               MATMUL(A%EJJJ,RES%EJ)+MATMUL(A%EJJ,RES%EJJ)))
      RES%EKKKK=-MATMUL(RES%R,(MATMUL(A%EKKKK,RES%R)+MATMUL(A%EK,RES%EKKK)+&
               MATMUL(A%EKKK,RES%EK)+MATMUL(A%EKK,RES%EKK)))
      RES%ELLLL=-MATMUL(RES%R,(MATMUL(A%ELLLL,RES%R)+MATMUL(A%EL,RES%ELLL)+&
               MATMUL(A%ELLL,RES%EL)+MATMUL(A%ELL,RES%ELL)))
      RES%EMMMM=-MATMUL(RES%R,(MATMUL(A%EMMMM,RES%R)+MATMUL(A%EM,RES%EMMM)+&
               MATMUL(A%EMMM,RES%EM)+MATMUL(A%EMM,RES%EMM)))

      ! Order 5
      RES%E11111=-MATMUL(RES%R,(MATMUL(A%E11111,RES%R)+MATMUL(A%E1,RES%E1111)+&
                MATMUL(A%E1111,RES%E1)+MATMUL(A%E11,RES%E111)+MATMUL(A%E111,RES%E11)))
      RES%E22222=-MATMUL(RES%R,(MATMUL(A%E22222,RES%R)+MATMUL(A%E2,RES%E2222)+&
                MATMUL(A%E2222,RES%E2)+MATMUL(A%E22,RES%E222)+MATMUL(A%E222,RES%E22)))
      RES%E33333=-MATMUL(RES%R,(MATMUL(A%E33333,RES%R)+MATMUL(A%E3,RES%E3333)+&
                MATMUL(A%E3333,RES%E3)+MATMUL(A%E33,RES%E333)+MATMUL(A%E333,RES%E33)))
      RES%E44444=-MATMUL(RES%R,(MATMUL(A%E44444,RES%R)+MATMUL(A%E4,RES%E4444)+&
                MATMUL(A%E4444,RES%E4)+MATMUL(A%E44,RES%E444)+MATMUL(A%E444,RES%E44)))
      RES%E55555=-MATMUL(RES%R,(MATMUL(A%E55555,RES%R)+MATMUL(A%E5,RES%E5555)+&
                MATMUL(A%E5555,RES%E5)+MATMUL(A%E55,RES%E555)+MATMUL(A%E555,RES%E55)))
      RES%E66666=-MATMUL(RES%R,(MATMUL(A%E66666,RES%R)+MATMUL(A%E6,RES%E6666)+&
                MATMUL(A%E6666,RES%E6)+MATMUL(A%E66,RES%E666)+MATMUL(A%E666,RES%E66)))
      RES%E77777=-MATMUL(RES%R,(MATMUL(A%E77777,RES%R)+MATMUL(A%E7,RES%E7777)+&
                MATMUL(A%E7777,RES%E7)+MATMUL(A%E77,RES%E777)+MATMUL(A%E777,RES%E77)))
      RES%E88888=-MATMUL(RES%R,(MATMUL(A%E88888,RES%R)+MATMUL(A%E8,RES%E8888)+&
                MATMUL(A%E8888,RES%E8)+MATMUL(A%E88,RES%E888)+MATMUL(A%E888,RES%E88)))
      RES%E99999=-MATMUL(RES%R,(MATMUL(A%E99999,RES%R)+MATMUL(A%E9,RES%E9999)+&
                MATMUL(A%E9999,RES%E9)+MATMUL(A%E99,RES%E999)+MATMUL(A%E999,RES%E99)))
      RES%EAAAAA=-MATMUL(RES%R,(MATMUL(A%EAAAAA,RES%R)+MATMUL(A%EA,RES%EAAAA)+&
                MATMUL(A%EAAAA,RES%EA)+MATMUL(A%EAA,RES%EAAA)+MATMUL(A%EAAA,RES%EAA)))
      RES%EBBBBB=-MATMUL(RES%R,(MATMUL(A%EBBBBB,RES%R)+MATMUL(A%EB,RES%EBBBB)+&
                MATMUL(A%EBBBB,RES%EB)+MATMUL(A%EBB,RES%EBBB)+MATMUL(A%EBBB,RES%EBB)))
      RES%ECCCCC=-MATMUL(RES%R,(MATMUL(A%ECCCCC,RES%R)+MATMUL(A%EC,RES%ECCCC)+&
                MATMUL(A%ECCCC,RES%EC)+MATMUL(A%ECC,RES%ECCC)+MATMUL(A%ECCC,RES%ECC)))
      RES%EDDDDD=-MATMUL(RES%R,(MATMUL(A%EDDDDD,RES%R)+MATMUL(A%ED,RES%EDDDD)+&
                MATMUL(A%EDDDD,RES%ED)+MATMUL(A%EDD,RES%EDDD)+MATMUL(A%EDDD,RES%EDD)))
      RES%EEEEEE=-MATMUL(RES%R,(MATMUL(A%EEEEEE,RES%R)+MATMUL(A%EE,RES%EEEEE)+&
                MATMUL(A%EEEEE,RES%EE)+MATMUL(A%EEE,RES%EEEE)+MATMUL(A%EEEE,RES%EEE)))
      RES%EFFFFF=-MATMUL(RES%R,(MATMUL(A%EFFFFF,RES%R)+MATMUL(A%EF,RES%EFFFF)+&
                MATMUL(A%EFFFF,RES%EF)+MATMUL(A%EFF,RES%EFFF)+MATMUL(A%EFFF,RES%EFF)))
      RES%EGGGGG=-MATMUL(RES%R,(MATMUL(A%EGGGGG,RES%R)+MATMUL(A%EG,RES%EGGGG)+&
                MATMUL(A%EGGGG,RES%EG)+MATMUL(A%EGG,RES%EGGG)+MATMUL(A%EGGG,RES%EGG)))
      RES%EHHHHH=-MATMUL(RES%R,(MATMUL(A%EHHHHH,RES%R)+MATMUL(A%EH,RES%EHHHH)+&
                MATMUL(A%EHHHH,RES%EH)+MATMUL(A%EHH,RES%EHHH)+MATMUL(A%EHHH,RES%EHH)))
      RES%EIIIII=-MATMUL(RES%R,(MATMUL(A%EIIIII,RES%R)+MATMUL(A%EI,RES%EIIII)+&
                MATMUL(A%EIIII,RES%EI)+MATMUL(A%EII,RES%EIII)+MATMUL(A%EIII,RES%EII)))
      RES%EJJJJJ=-MATMUL(RES%R,(MATMUL(A%EJJJJJ,RES%R)+MATMUL(A%EJ,RES%EJJJJ)+&
                MATMUL(A%EJJJJ,RES%EJ)+MATMUL(A%EJJ,RES%EJJJ)+MATMUL(A%EJJJ,RES%EJJ)))
      RES%EKKKKK=-MATMUL(RES%R,(MATMUL(A%EKKKKK,RES%R)+MATMUL(A%EK,RES%EKKKK)+&
                MATMUL(A%EKKKK,RES%EK)+MATMUL(A%EKK,RES%EKKK)+MATMUL(A%EKKK,RES%EKK)))
      RES%ELLLLL=-MATMUL(RES%R,(MATMUL(A%ELLLLL,RES%R)+MATMUL(A%EL,RES%ELLLL)+&
                MATMUL(A%ELLLL,RES%EL)+MATMUL(A%ELL,RES%ELLL)+MATMUL(A%ELLL,RES%ELL)))
      RES%EMMMMM=-MATMUL(RES%R,(MATMUL(A%EMMMMM,RES%R)+MATMUL(A%EM,RES%EMMMM)+&
                MATMUL(A%EMMMM,RES%EM)+MATMUL(A%EMM,RES%EMMM)+MATMUL(A%EMMM,RES%EMM)))

   END FUNCTION DONUMM22N5_INV3X3

   FUNCTION DONUMM22N5_INV4X4(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM22N5) , INTENT(IN) :: A(4,4) 
      TYPE(DONUMM22N5) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(DONUMM22N5) :: RES(SIZE(A,1),SIZE(A,2)) 

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
      RES%E888=-MATMUL(RES%R,(MATMUL(A%E888,RES%R)+MATMUL(A%E8,RES%E88)+&
              MATMUL(A%E88,RES%E8)))
      RES%E999=-MATMUL(RES%R,(MATMUL(A%E999,RES%R)+MATMUL(A%E9,RES%E99)+&
              MATMUL(A%E99,RES%E9)))
      RES%EAAA=-MATMUL(RES%R,(MATMUL(A%EAAA,RES%R)+MATMUL(A%EA,RES%EAA)+&
              MATMUL(A%EAA,RES%EA)))
      RES%EBBB=-MATMUL(RES%R,(MATMUL(A%EBBB,RES%R)+MATMUL(A%EB,RES%EBB)+&
              MATMUL(A%EBB,RES%EB)))
      RES%ECCC=-MATMUL(RES%R,(MATMUL(A%ECCC,RES%R)+MATMUL(A%EC,RES%ECC)+&
              MATMUL(A%ECC,RES%EC)))
      RES%EDDD=-MATMUL(RES%R,(MATMUL(A%EDDD,RES%R)+MATMUL(A%ED,RES%EDD)+&
              MATMUL(A%EDD,RES%ED)))
      RES%EEEE=-MATMUL(RES%R,(MATMUL(A%EEEE,RES%R)+MATMUL(A%EE,RES%EEE)+&
              MATMUL(A%EEE,RES%EE)))
      RES%EFFF=-MATMUL(RES%R,(MATMUL(A%EFFF,RES%R)+MATMUL(A%EF,RES%EFF)+&
              MATMUL(A%EFF,RES%EF)))
      RES%EGGG=-MATMUL(RES%R,(MATMUL(A%EGGG,RES%R)+MATMUL(A%EG,RES%EGG)+&
              MATMUL(A%EGG,RES%EG)))
      RES%EHHH=-MATMUL(RES%R,(MATMUL(A%EHHH,RES%R)+MATMUL(A%EH,RES%EHH)+&
              MATMUL(A%EHH,RES%EH)))
      RES%EIII=-MATMUL(RES%R,(MATMUL(A%EIII,RES%R)+MATMUL(A%EI,RES%EII)+&
              MATMUL(A%EII,RES%EI)))
      RES%EJJJ=-MATMUL(RES%R,(MATMUL(A%EJJJ,RES%R)+MATMUL(A%EJ,RES%EJJ)+&
              MATMUL(A%EJJ,RES%EJ)))
      RES%EKKK=-MATMUL(RES%R,(MATMUL(A%EKKK,RES%R)+MATMUL(A%EK,RES%EKK)+&
              MATMUL(A%EKK,RES%EK)))
      RES%ELLL=-MATMUL(RES%R,(MATMUL(A%ELLL,RES%R)+MATMUL(A%EL,RES%ELL)+&
              MATMUL(A%ELL,RES%EL)))
      RES%EMMM=-MATMUL(RES%R,(MATMUL(A%EMMM,RES%R)+MATMUL(A%EM,RES%EMM)+&
              MATMUL(A%EMM,RES%EM)))

      ! Order 4
      RES%E1111=-MATMUL(RES%R,(MATMUL(A%E1111,RES%R)+MATMUL(A%E1,RES%E111)+&
               MATMUL(A%E111,RES%E1)+MATMUL(A%E11,RES%E11)))
      RES%E2222=-MATMUL(RES%R,(MATMUL(A%E2222,RES%R)+MATMUL(A%E2,RES%E222)+&
               MATMUL(A%E222,RES%E2)+MATMUL(A%E22,RES%E22)))
      RES%E3333=-MATMUL(RES%R,(MATMUL(A%E3333,RES%R)+MATMUL(A%E3,RES%E333)+&
               MATMUL(A%E333,RES%E3)+MATMUL(A%E33,RES%E33)))
      RES%E4444=-MATMUL(RES%R,(MATMUL(A%E4444,RES%R)+MATMUL(A%E4,RES%E444)+&
               MATMUL(A%E444,RES%E4)+MATMUL(A%E44,RES%E44)))
      RES%E5555=-MATMUL(RES%R,(MATMUL(A%E5555,RES%R)+MATMUL(A%E5,RES%E555)+&
               MATMUL(A%E555,RES%E5)+MATMUL(A%E55,RES%E55)))
      RES%E6666=-MATMUL(RES%R,(MATMUL(A%E6666,RES%R)+MATMUL(A%E6,RES%E666)+&
               MATMUL(A%E666,RES%E6)+MATMUL(A%E66,RES%E66)))
      RES%E7777=-MATMUL(RES%R,(MATMUL(A%E7777,RES%R)+MATMUL(A%E7,RES%E777)+&
               MATMUL(A%E777,RES%E7)+MATMUL(A%E77,RES%E77)))
      RES%E8888=-MATMUL(RES%R,(MATMUL(A%E8888,RES%R)+MATMUL(A%E8,RES%E888)+&
               MATMUL(A%E888,RES%E8)+MATMUL(A%E88,RES%E88)))
      RES%E9999=-MATMUL(RES%R,(MATMUL(A%E9999,RES%R)+MATMUL(A%E9,RES%E999)+&
               MATMUL(A%E999,RES%E9)+MATMUL(A%E99,RES%E99)))
      RES%EAAAA=-MATMUL(RES%R,(MATMUL(A%EAAAA,RES%R)+MATMUL(A%EA,RES%EAAA)+&
               MATMUL(A%EAAA,RES%EA)+MATMUL(A%EAA,RES%EAA)))
      RES%EBBBB=-MATMUL(RES%R,(MATMUL(A%EBBBB,RES%R)+MATMUL(A%EB,RES%EBBB)+&
               MATMUL(A%EBBB,RES%EB)+MATMUL(A%EBB,RES%EBB)))
      RES%ECCCC=-MATMUL(RES%R,(MATMUL(A%ECCCC,RES%R)+MATMUL(A%EC,RES%ECCC)+&
               MATMUL(A%ECCC,RES%EC)+MATMUL(A%ECC,RES%ECC)))
      RES%EDDDD=-MATMUL(RES%R,(MATMUL(A%EDDDD,RES%R)+MATMUL(A%ED,RES%EDDD)+&
               MATMUL(A%EDDD,RES%ED)+MATMUL(A%EDD,RES%EDD)))
      RES%EEEEE=-MATMUL(RES%R,(MATMUL(A%EEEEE,RES%R)+MATMUL(A%EE,RES%EEEE)+&
               MATMUL(A%EEEE,RES%EE)+MATMUL(A%EEE,RES%EEE)))
      RES%EFFFF=-MATMUL(RES%R,(MATMUL(A%EFFFF,RES%R)+MATMUL(A%EF,RES%EFFF)+&
               MATMUL(A%EFFF,RES%EF)+MATMUL(A%EFF,RES%EFF)))
      RES%EGGGG=-MATMUL(RES%R,(MATMUL(A%EGGGG,RES%R)+MATMUL(A%EG,RES%EGGG)+&
               MATMUL(A%EGGG,RES%EG)+MATMUL(A%EGG,RES%EGG)))
      RES%EHHHH=-MATMUL(RES%R,(MATMUL(A%EHHHH,RES%R)+MATMUL(A%EH,RES%EHHH)+&
               MATMUL(A%EHHH,RES%EH)+MATMUL(A%EHH,RES%EHH)))
      RES%EIIII=-MATMUL(RES%R,(MATMUL(A%EIIII,RES%R)+MATMUL(A%EI,RES%EIII)+&
               MATMUL(A%EIII,RES%EI)+MATMUL(A%EII,RES%EII)))
      RES%EJJJJ=-MATMUL(RES%R,(MATMUL(A%EJJJJ,RES%R)+MATMUL(A%EJ,RES%EJJJ)+&
               MATMUL(A%EJJJ,RES%EJ)+MATMUL(A%EJJ,RES%EJJ)))
      RES%EKKKK=-MATMUL(RES%R,(MATMUL(A%EKKKK,RES%R)+MATMUL(A%EK,RES%EKKK)+&
               MATMUL(A%EKKK,RES%EK)+MATMUL(A%EKK,RES%EKK)))
      RES%ELLLL=-MATMUL(RES%R,(MATMUL(A%ELLLL,RES%R)+MATMUL(A%EL,RES%ELLL)+&
               MATMUL(A%ELLL,RES%EL)+MATMUL(A%ELL,RES%ELL)))
      RES%EMMMM=-MATMUL(RES%R,(MATMUL(A%EMMMM,RES%R)+MATMUL(A%EM,RES%EMMM)+&
               MATMUL(A%EMMM,RES%EM)+MATMUL(A%EMM,RES%EMM)))

      ! Order 5
      RES%E11111=-MATMUL(RES%R,(MATMUL(A%E11111,RES%R)+MATMUL(A%E1,RES%E1111)+&
                MATMUL(A%E1111,RES%E1)+MATMUL(A%E11,RES%E111)+MATMUL(A%E111,RES%E11)))
      RES%E22222=-MATMUL(RES%R,(MATMUL(A%E22222,RES%R)+MATMUL(A%E2,RES%E2222)+&
                MATMUL(A%E2222,RES%E2)+MATMUL(A%E22,RES%E222)+MATMUL(A%E222,RES%E22)))
      RES%E33333=-MATMUL(RES%R,(MATMUL(A%E33333,RES%R)+MATMUL(A%E3,RES%E3333)+&
                MATMUL(A%E3333,RES%E3)+MATMUL(A%E33,RES%E333)+MATMUL(A%E333,RES%E33)))
      RES%E44444=-MATMUL(RES%R,(MATMUL(A%E44444,RES%R)+MATMUL(A%E4,RES%E4444)+&
                MATMUL(A%E4444,RES%E4)+MATMUL(A%E44,RES%E444)+MATMUL(A%E444,RES%E44)))
      RES%E55555=-MATMUL(RES%R,(MATMUL(A%E55555,RES%R)+MATMUL(A%E5,RES%E5555)+&
                MATMUL(A%E5555,RES%E5)+MATMUL(A%E55,RES%E555)+MATMUL(A%E555,RES%E55)))
      RES%E66666=-MATMUL(RES%R,(MATMUL(A%E66666,RES%R)+MATMUL(A%E6,RES%E6666)+&
                MATMUL(A%E6666,RES%E6)+MATMUL(A%E66,RES%E666)+MATMUL(A%E666,RES%E66)))
      RES%E77777=-MATMUL(RES%R,(MATMUL(A%E77777,RES%R)+MATMUL(A%E7,RES%E7777)+&
                MATMUL(A%E7777,RES%E7)+MATMUL(A%E77,RES%E777)+MATMUL(A%E777,RES%E77)))
      RES%E88888=-MATMUL(RES%R,(MATMUL(A%E88888,RES%R)+MATMUL(A%E8,RES%E8888)+&
                MATMUL(A%E8888,RES%E8)+MATMUL(A%E88,RES%E888)+MATMUL(A%E888,RES%E88)))
      RES%E99999=-MATMUL(RES%R,(MATMUL(A%E99999,RES%R)+MATMUL(A%E9,RES%E9999)+&
                MATMUL(A%E9999,RES%E9)+MATMUL(A%E99,RES%E999)+MATMUL(A%E999,RES%E99)))
      RES%EAAAAA=-MATMUL(RES%R,(MATMUL(A%EAAAAA,RES%R)+MATMUL(A%EA,RES%EAAAA)+&
                MATMUL(A%EAAAA,RES%EA)+MATMUL(A%EAA,RES%EAAA)+MATMUL(A%EAAA,RES%EAA)))
      RES%EBBBBB=-MATMUL(RES%R,(MATMUL(A%EBBBBB,RES%R)+MATMUL(A%EB,RES%EBBBB)+&
                MATMUL(A%EBBBB,RES%EB)+MATMUL(A%EBB,RES%EBBB)+MATMUL(A%EBBB,RES%EBB)))
      RES%ECCCCC=-MATMUL(RES%R,(MATMUL(A%ECCCCC,RES%R)+MATMUL(A%EC,RES%ECCCC)+&
                MATMUL(A%ECCCC,RES%EC)+MATMUL(A%ECC,RES%ECCC)+MATMUL(A%ECCC,RES%ECC)))
      RES%EDDDDD=-MATMUL(RES%R,(MATMUL(A%EDDDDD,RES%R)+MATMUL(A%ED,RES%EDDDD)+&
                MATMUL(A%EDDDD,RES%ED)+MATMUL(A%EDD,RES%EDDD)+MATMUL(A%EDDD,RES%EDD)))
      RES%EEEEEE=-MATMUL(RES%R,(MATMUL(A%EEEEEE,RES%R)+MATMUL(A%EE,RES%EEEEE)+&
                MATMUL(A%EEEEE,RES%EE)+MATMUL(A%EEE,RES%EEEE)+MATMUL(A%EEEE,RES%EEE)))
      RES%EFFFFF=-MATMUL(RES%R,(MATMUL(A%EFFFFF,RES%R)+MATMUL(A%EF,RES%EFFFF)+&
                MATMUL(A%EFFFF,RES%EF)+MATMUL(A%EFF,RES%EFFF)+MATMUL(A%EFFF,RES%EFF)))
      RES%EGGGGG=-MATMUL(RES%R,(MATMUL(A%EGGGGG,RES%R)+MATMUL(A%EG,RES%EGGGG)+&
                MATMUL(A%EGGGG,RES%EG)+MATMUL(A%EGG,RES%EGGG)+MATMUL(A%EGGG,RES%EGG)))
      RES%EHHHHH=-MATMUL(RES%R,(MATMUL(A%EHHHHH,RES%R)+MATMUL(A%EH,RES%EHHHH)+&
                MATMUL(A%EHHHH,RES%EH)+MATMUL(A%EHH,RES%EHHH)+MATMUL(A%EHHH,RES%EHH)))
      RES%EIIIII=-MATMUL(RES%R,(MATMUL(A%EIIIII,RES%R)+MATMUL(A%EI,RES%EIIII)+&
                MATMUL(A%EIIII,RES%EI)+MATMUL(A%EII,RES%EIII)+MATMUL(A%EIII,RES%EII)))
      RES%EJJJJJ=-MATMUL(RES%R,(MATMUL(A%EJJJJJ,RES%R)+MATMUL(A%EJ,RES%EJJJJ)+&
                MATMUL(A%EJJJJ,RES%EJ)+MATMUL(A%EJJ,RES%EJJJ)+MATMUL(A%EJJJ,RES%EJJ)))
      RES%EKKKKK=-MATMUL(RES%R,(MATMUL(A%EKKKKK,RES%R)+MATMUL(A%EK,RES%EKKKK)+&
                MATMUL(A%EKKKK,RES%EK)+MATMUL(A%EKK,RES%EKKK)+MATMUL(A%EKKK,RES%EKK)))
      RES%ELLLLL=-MATMUL(RES%R,(MATMUL(A%ELLLLL,RES%R)+MATMUL(A%EL,RES%ELLLL)+&
                MATMUL(A%ELLLL,RES%EL)+MATMUL(A%ELL,RES%ELLL)+MATMUL(A%ELLL,RES%ELL)))
      RES%EMMMMM=-MATMUL(RES%R,(MATMUL(A%EMMMMM,RES%R)+MATMUL(A%EM,RES%EMMMM)+&
                MATMUL(A%EMMMM,RES%EM)+MATMUL(A%EMM,RES%EMMM)+MATMUL(A%EMMM,RES%EMM)))

   END FUNCTION DONUMM22N5_INV4X4

END MODULE diagotim22n5
