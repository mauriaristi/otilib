MODULE otim7n3

   USE master_parameters
   USE real_utils

   IMPLICIT NONE

   INTEGER, PARAMETER :: num_im_dir = 120
   INTEGER, PARAMETER :: torder     = 3
   INTEGER, PARAMETER :: n_imdir_order(4) = [1,7,28,84]

   TYPE ONUMM7N3
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
     ! Order 3
     REAL(DP) :: E111
     REAL(DP) :: E112
     REAL(DP) :: E122
     REAL(DP) :: E222
     REAL(DP) :: E113
     REAL(DP) :: E123
     REAL(DP) :: E223
     REAL(DP) :: E133
     REAL(DP) :: E233
     REAL(DP) :: E333
     REAL(DP) :: E114
     REAL(DP) :: E124
     REAL(DP) :: E224
     REAL(DP) :: E134
     REAL(DP) :: E234
     REAL(DP) :: E334
     REAL(DP) :: E144
     REAL(DP) :: E244
     REAL(DP) :: E344
     REAL(DP) :: E444
     REAL(DP) :: E115
     REAL(DP) :: E125
     REAL(DP) :: E225
     REAL(DP) :: E135
     REAL(DP) :: E235
     REAL(DP) :: E335
     REAL(DP) :: E145
     REAL(DP) :: E245
     REAL(DP) :: E345
     REAL(DP) :: E445
     REAL(DP) :: E155
     REAL(DP) :: E255
     REAL(DP) :: E355
     REAL(DP) :: E455
     REAL(DP) :: E555
     REAL(DP) :: E116
     REAL(DP) :: E126
     REAL(DP) :: E226
     REAL(DP) :: E136
     REAL(DP) :: E236
     REAL(DP) :: E336
     REAL(DP) :: E146
     REAL(DP) :: E246
     REAL(DP) :: E346
     REAL(DP) :: E446
     REAL(DP) :: E156
     REAL(DP) :: E256
     REAL(DP) :: E356
     REAL(DP) :: E456
     REAL(DP) :: E556
     REAL(DP) :: E166
     REAL(DP) :: E266
     REAL(DP) :: E366
     REAL(DP) :: E466
     REAL(DP) :: E566
     REAL(DP) :: E666
     REAL(DP) :: E117
     REAL(DP) :: E127
     REAL(DP) :: E227
     REAL(DP) :: E137
     REAL(DP) :: E237
     REAL(DP) :: E337
     REAL(DP) :: E147
     REAL(DP) :: E247
     REAL(DP) :: E347
     REAL(DP) :: E447
     REAL(DP) :: E157
     REAL(DP) :: E257
     REAL(DP) :: E357
     REAL(DP) :: E457
     REAL(DP) :: E557
     REAL(DP) :: E167
     REAL(DP) :: E267
     REAL(DP) :: E367
     REAL(DP) :: E467
     REAL(DP) :: E567
     REAL(DP) :: E667
     REAL(DP) :: E177
     REAL(DP) :: E277
     REAL(DP) :: E377
     REAL(DP) :: E477
     REAL(DP) :: E577
     REAL(DP) :: E677
     REAL(DP) :: E777
   END TYPE ONUMM7N3

   ! Constant imaginary directions.
   ! Order 1
   TYPE(ONUMM7N3), PARAMETER :: E1 = ONUMM7N3(0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E2 = ONUMM7N3(0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E3 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E4 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E5 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E6 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E7 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   ! Order 2
   TYPE(ONUMM7N3), PARAMETER :: E11 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E12 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E22 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E13 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E23 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E33 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E14 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E24 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E34 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E44 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E15 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E25 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E35 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E45 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E55 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E16 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E26 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E36 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E46 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E56 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E66 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E17 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E27 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E37 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E47 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E57 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E67 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E77 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   ! Order 3
   TYPE(ONUMM7N3), PARAMETER :: E111 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E112 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E122 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E222 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E113 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E123 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E223 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E133 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E233 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E333 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E114 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E124 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E224 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E134 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E234 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E334 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E144 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E244 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E344 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E444 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E115 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E125 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E225 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E135 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E235 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E335 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E145 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E245 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E345 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E445 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E155 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E255 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E355 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E455 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E555 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E116 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E126 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E226 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E136 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E236 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E336 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E146 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E246 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E346 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E446 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E156 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E256 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E356 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E456 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E556 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E166 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E266 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E366 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E466 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E566 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E666 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E117 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E127 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E227 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E137 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E237 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E337 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E147 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E247 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E347 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E447 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E157 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E257 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E357 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E457 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E557 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E167 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E267 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E367 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E467 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E567 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E667 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E177 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E277 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E377 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E477 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E577 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E677 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp)
   TYPE(ONUMM7N3), PARAMETER :: E777 = ONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp)


   INTERFACE OPERATOR(*)
      MODULE PROCEDURE ONUMM7N3_MUL_OO_SS,ONUMM7N3_MUL_RO_SS,ONUMM7N3_MUL_OR_SS,ONUMM7N3_MUL_OO_VS,&
                       ONUMM7N3_MUL_RO_VS,ONUMM7N3_MUL_OR_VS,ONUMM7N3_MUL_OO_MS,ONUMM7N3_MUL_RO_MS,&
                       ONUMM7N3_MUL_OR_MS,ONUMM7N3_MUL_OO_SV,ONUMM7N3_MUL_RO_SV,ONUMM7N3_MUL_OR_SV,&
                       ONUMM7N3_MUL_OO_SM,ONUMM7N3_MUL_RO_SM,ONUMM7N3_MUL_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(+)
      MODULE PROCEDURE ONUMM7N3_ADD_OO_SS,ONUMM7N3_ADD_RO_SS,ONUMM7N3_ADD_OR_SS,ONUMM7N3_ADD_OO_VS,&
                       ONUMM7N3_ADD_RO_VS,ONUMM7N3_ADD_OR_VS,ONUMM7N3_ADD_OO_MS,ONUMM7N3_ADD_RO_MS,&
                       ONUMM7N3_ADD_OR_MS,ONUMM7N3_ADD_OO_SV,ONUMM7N3_ADD_RO_SV,ONUMM7N3_ADD_OR_SV,&
                       ONUMM7N3_ADD_OO_SM,ONUMM7N3_ADD_RO_SM,ONUMM7N3_ADD_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(-)
      MODULE PROCEDURE ONUMM7N3_NEG,ONUMM7N3_SUB_OO_SS,ONUMM7N3_SUB_RO_SS,ONUMM7N3_SUB_OR_SS,&
                       ONUMM7N3_SUB_OO_VS,ONUMM7N3_SUB_RO_VS,ONUMM7N3_SUB_OR_VS,ONUMM7N3_SUB_OO_MS,&
                       ONUMM7N3_SUB_RO_MS,ONUMM7N3_SUB_OR_MS,ONUMM7N3_SUB_OO_SV,ONUMM7N3_SUB_RO_SV,&
                       ONUMM7N3_SUB_OR_SV,ONUMM7N3_SUB_OO_SM,ONUMM7N3_SUB_RO_SM,ONUMM7N3_SUB_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(/)
      MODULE PROCEDURE ONUMM7N3_DIVISION_OO,ONUMM7N3_DIVISION_OR,ONUMM7N3_DIVISION_RO
   END INTERFACE

   INTERFACE ASSIGNMENT(=)
      MODULE PROCEDURE ONUMM7N3_ASSIGN_R
   END INTERFACE

   INTERFACE OPERATOR(**)
      MODULE PROCEDURE ONUMM7N3_POW_OR,ONUMM7N3_POW_RO,ONUMM7N3_POW_OO
   END INTERFACE

   INTERFACE PPRINT
      MODULE PROCEDURE ONUMM7N3_PPRINT_S,ONUMM7N3_PPRINT_V,ONUMM7N3_PPRINT_M
   END INTERFACE

   INTERFACE TRANSPOSE
      MODULE PROCEDURE ONUMM7N3_TRANSPOSE
   END INTERFACE

   INTERFACE MATMUL
      MODULE PROCEDURE ONUMM7N3_MATMUL_ONUMM7N3,R_MATMUL_ONUMM7N3,ONUMM7N3_MATMUL_R
   END INTERFACE

   INTERFACE DOT_PRODUCT
      MODULE PROCEDURE ONUMM7N3_DOT_PRODUCT_ONUMM7N3,R_DOT_PRODUCT_ONUMM7N3,ONUMM7N3_DOT_PRODUCT_R
   END INTERFACE

   INTERFACE UNFOLD
      MODULE PROCEDURE ONUMM7N3_TO_CR_MAT_S,ONUMM7N3_TO_CR_MAT_V,ONUMM7N3_TO_CR_MAT_M
   END INTERFACE

   INTERFACE TO_CR
      MODULE PROCEDURE ONUMM7N3_TO_CR_MAT_S,ONUMM7N3_TO_CR_MAT_V,ONUMM7N3_TO_CR_MAT_M
   END INTERFACE

   INTERFACE SIN
      MODULE PROCEDURE ONUMM7N3_SIN
   END INTERFACE

   INTERFACE COS
      MODULE PROCEDURE ONUMM7N3_COS
   END INTERFACE

   INTERFACE TAN
      MODULE PROCEDURE ONUMM7N3_TAN
   END INTERFACE

   INTERFACE ASIN
      MODULE PROCEDURE ONUMM7N3_ASIN
   END INTERFACE

   INTERFACE ACOS
      MODULE PROCEDURE ONUMM7N3_ACOS
   END INTERFACE

   INTERFACE ATAN
      MODULE PROCEDURE ONUMM7N3_ATAN
   END INTERFACE

   INTERFACE SINH
      MODULE PROCEDURE ONUMM7N3_SINH
   END INTERFACE

   INTERFACE COSH
      MODULE PROCEDURE ONUMM7N3_COSH
   END INTERFACE

   INTERFACE TANH
      MODULE PROCEDURE ONUMM7N3_TANH
   END INTERFACE

   INTERFACE SQRT
      MODULE PROCEDURE ONUMM7N3_SQRT
   END INTERFACE

   INTERFACE LOG
      MODULE PROCEDURE ONUMM7N3_LOG
   END INTERFACE

   INTERFACE EXP
      MODULE PROCEDURE ONUMM7N3_EXP
   END INTERFACE

   INTERFACE GEM
      MODULE PROCEDURE ONUMM7N3_GEM_OOO,ONUMM7N3_GEM_ROO,ONUMM7N3_GEM_ORO
   END INTERFACE

   INTERFACE FEVAL
      MODULE PROCEDURE ONUMM7N3_FEVAL
   END INTERFACE

   INTERFACE F2EVAL
      MODULE PROCEDURE ONUMM7N3_F2EVAL
   END INTERFACE

   INTERFACE REAL
      MODULE PROCEDURE ONUMM7N3_REAL
   END INTERFACE

   INTERFACE DET2X2
      MODULE PROCEDURE ONUMM7N3_det2x2
   END INTERFACE

   INTERFACE DET3X3
      MODULE PROCEDURE ONUMM7N3_det3x3
   END INTERFACE

   INTERFACE DET4X4
      MODULE PROCEDURE ONUMM7N3_det4x4
   END INTERFACE

   INTERFACE INV2X2
      MODULE PROCEDURE ONUMM7N3_INV2X2
   END INTERFACE

   INTERFACE INV3X3
      MODULE PROCEDURE ONUMM7N3_INV3X3
   END INTERFACE

   INTERFACE INV4X4
      MODULE PROCEDURE ONUMM7N3_INV4X4
   END INTERFACE

   INTERFACE GETIM
      MODULE PROCEDURE ONUMM7N3_GETIM_S,ONUMM7N3_GETIM_V,ONUMM7N3_GETIM_M
   END INTERFACE

   INTERFACE SETIM
      MODULE PROCEDURE ONUMM7N3_SETIM_S,ONUMM7N3_SETIM_V,ONUMM7N3_SETIM_M
   END INTERFACE

   CONTAINS

   ELEMENTAL SUBROUTINE ONUMM7N3_ASSIGN_R(RES,LHS)
      
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS 
      TYPE(ONUMM7N3), INTENT(OUT) :: RES 

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

      ! Order 3
      RES%E111 = 0.0_dp
      RES%E112 = 0.0_dp
      RES%E122 = 0.0_dp
      RES%E222 = 0.0_dp
      RES%E113 = 0.0_dp
      RES%E123 = 0.0_dp
      RES%E223 = 0.0_dp
      RES%E133 = 0.0_dp
      RES%E233 = 0.0_dp
      RES%E333 = 0.0_dp
      RES%E114 = 0.0_dp
      RES%E124 = 0.0_dp
      RES%E224 = 0.0_dp
      RES%E134 = 0.0_dp
      RES%E234 = 0.0_dp
      RES%E334 = 0.0_dp
      RES%E144 = 0.0_dp
      RES%E244 = 0.0_dp
      RES%E344 = 0.0_dp
      RES%E444 = 0.0_dp
      RES%E115 = 0.0_dp
      RES%E125 = 0.0_dp
      RES%E225 = 0.0_dp
      RES%E135 = 0.0_dp
      RES%E235 = 0.0_dp
      RES%E335 = 0.0_dp
      RES%E145 = 0.0_dp
      RES%E245 = 0.0_dp
      RES%E345 = 0.0_dp
      RES%E445 = 0.0_dp
      RES%E155 = 0.0_dp
      RES%E255 = 0.0_dp
      RES%E355 = 0.0_dp
      RES%E455 = 0.0_dp
      RES%E555 = 0.0_dp
      RES%E116 = 0.0_dp
      RES%E126 = 0.0_dp
      RES%E226 = 0.0_dp
      RES%E136 = 0.0_dp
      RES%E236 = 0.0_dp
      RES%E336 = 0.0_dp
      RES%E146 = 0.0_dp
      RES%E246 = 0.0_dp
      RES%E346 = 0.0_dp
      RES%E446 = 0.0_dp
      RES%E156 = 0.0_dp
      RES%E256 = 0.0_dp
      RES%E356 = 0.0_dp
      RES%E456 = 0.0_dp
      RES%E556 = 0.0_dp
      RES%E166 = 0.0_dp
      RES%E266 = 0.0_dp
      RES%E366 = 0.0_dp
      RES%E466 = 0.0_dp
      RES%E566 = 0.0_dp
      RES%E666 = 0.0_dp
      RES%E117 = 0.0_dp
      RES%E127 = 0.0_dp
      RES%E227 = 0.0_dp
      RES%E137 = 0.0_dp
      RES%E237 = 0.0_dp
      RES%E337 = 0.0_dp
      RES%E147 = 0.0_dp
      RES%E247 = 0.0_dp
      RES%E347 = 0.0_dp
      RES%E447 = 0.0_dp
      RES%E157 = 0.0_dp
      RES%E257 = 0.0_dp
      RES%E357 = 0.0_dp
      RES%E457 = 0.0_dp
      RES%E557 = 0.0_dp
      RES%E167 = 0.0_dp
      RES%E267 = 0.0_dp
      RES%E367 = 0.0_dp
      RES%E467 = 0.0_dp
      RES%E567 = 0.0_dp
      RES%E667 = 0.0_dp
      RES%E177 = 0.0_dp
      RES%E277 = 0.0_dp
      RES%E377 = 0.0_dp
      RES%E477 = 0.0_dp
      RES%E577 = 0.0_dp
      RES%E677 = 0.0_dp
      RES%E777 = 0.0_dp

   END SUBROUTINE ONUMM7N3_ASSIGN_R

   ELEMENTAL FUNCTION ONUMM7N3_NEG(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS 
      TYPE(ONUMM7N3) :: RES 

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
      ! Order 3
      RES%E111 = -LHS%E111
      RES%E112 = -LHS%E112
      RES%E122 = -LHS%E122
      RES%E222 = -LHS%E222
      RES%E113 = -LHS%E113
      RES%E123 = -LHS%E123
      RES%E223 = -LHS%E223
      RES%E133 = -LHS%E133
      RES%E233 = -LHS%E233
      RES%E333 = -LHS%E333
      RES%E114 = -LHS%E114
      RES%E124 = -LHS%E124
      RES%E224 = -LHS%E224
      RES%E134 = -LHS%E134
      RES%E234 = -LHS%E234
      RES%E334 = -LHS%E334
      RES%E144 = -LHS%E144
      RES%E244 = -LHS%E244
      RES%E344 = -LHS%E344
      RES%E444 = -LHS%E444
      RES%E115 = -LHS%E115
      RES%E125 = -LHS%E125
      RES%E225 = -LHS%E225
      RES%E135 = -LHS%E135
      RES%E235 = -LHS%E235
      RES%E335 = -LHS%E335
      RES%E145 = -LHS%E145
      RES%E245 = -LHS%E245
      RES%E345 = -LHS%E345
      RES%E445 = -LHS%E445
      RES%E155 = -LHS%E155
      RES%E255 = -LHS%E255
      RES%E355 = -LHS%E355
      RES%E455 = -LHS%E455
      RES%E555 = -LHS%E555
      RES%E116 = -LHS%E116
      RES%E126 = -LHS%E126
      RES%E226 = -LHS%E226
      RES%E136 = -LHS%E136
      RES%E236 = -LHS%E236
      RES%E336 = -LHS%E336
      RES%E146 = -LHS%E146
      RES%E246 = -LHS%E246
      RES%E346 = -LHS%E346
      RES%E446 = -LHS%E446
      RES%E156 = -LHS%E156
      RES%E256 = -LHS%E256
      RES%E356 = -LHS%E356
      RES%E456 = -LHS%E456
      RES%E556 = -LHS%E556
      RES%E166 = -LHS%E166
      RES%E266 = -LHS%E266
      RES%E366 = -LHS%E366
      RES%E466 = -LHS%E466
      RES%E566 = -LHS%E566
      RES%E666 = -LHS%E666
      RES%E117 = -LHS%E117
      RES%E127 = -LHS%E127
      RES%E227 = -LHS%E227
      RES%E137 = -LHS%E137
      RES%E237 = -LHS%E237
      RES%E337 = -LHS%E337
      RES%E147 = -LHS%E147
      RES%E247 = -LHS%E247
      RES%E347 = -LHS%E347
      RES%E447 = -LHS%E447
      RES%E157 = -LHS%E157
      RES%E257 = -LHS%E257
      RES%E357 = -LHS%E357
      RES%E457 = -LHS%E457
      RES%E557 = -LHS%E557
      RES%E167 = -LHS%E167
      RES%E267 = -LHS%E267
      RES%E367 = -LHS%E367
      RES%E467 = -LHS%E467
      RES%E567 = -LHS%E567
      RES%E667 = -LHS%E667
      RES%E177 = -LHS%E177
      RES%E277 = -LHS%E277
      RES%E377 = -LHS%E377
      RES%E477 = -LHS%E477
      RES%E577 = -LHS%E577
      RES%E677 = -LHS%E677
      RES%E777 = -LHS%E777

   END FUNCTION ONUMM7N3_NEG

   ELEMENTAL FUNCTION ONUMM7N3_ADD_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES 

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

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111
      RES%E112 = LHS%E112 + RHS%E112
      RES%E122 = LHS%E122 + RHS%E122
      RES%E222 = LHS%E222 + RHS%E222
      RES%E113 = LHS%E113 + RHS%E113
      RES%E123 = LHS%E123 + RHS%E123
      RES%E223 = LHS%E223 + RHS%E223
      RES%E133 = LHS%E133 + RHS%E133
      RES%E233 = LHS%E233 + RHS%E233
      RES%E333 = LHS%E333 + RHS%E333
      RES%E114 = LHS%E114 + RHS%E114
      RES%E124 = LHS%E124 + RHS%E124
      RES%E224 = LHS%E224 + RHS%E224
      RES%E134 = LHS%E134 + RHS%E134
      RES%E234 = LHS%E234 + RHS%E234
      RES%E334 = LHS%E334 + RHS%E334
      RES%E144 = LHS%E144 + RHS%E144
      RES%E244 = LHS%E244 + RHS%E244
      RES%E344 = LHS%E344 + RHS%E344
      RES%E444 = LHS%E444 + RHS%E444
      RES%E115 = LHS%E115 + RHS%E115
      RES%E125 = LHS%E125 + RHS%E125
      RES%E225 = LHS%E225 + RHS%E225
      RES%E135 = LHS%E135 + RHS%E135
      RES%E235 = LHS%E235 + RHS%E235
      RES%E335 = LHS%E335 + RHS%E335
      RES%E145 = LHS%E145 + RHS%E145
      RES%E245 = LHS%E245 + RHS%E245
      RES%E345 = LHS%E345 + RHS%E345
      RES%E445 = LHS%E445 + RHS%E445
      RES%E155 = LHS%E155 + RHS%E155
      RES%E255 = LHS%E255 + RHS%E255
      RES%E355 = LHS%E355 + RHS%E355
      RES%E455 = LHS%E455 + RHS%E455
      RES%E555 = LHS%E555 + RHS%E555
      RES%E116 = LHS%E116 + RHS%E116
      RES%E126 = LHS%E126 + RHS%E126
      RES%E226 = LHS%E226 + RHS%E226
      RES%E136 = LHS%E136 + RHS%E136
      RES%E236 = LHS%E236 + RHS%E236
      RES%E336 = LHS%E336 + RHS%E336
      RES%E146 = LHS%E146 + RHS%E146
      RES%E246 = LHS%E246 + RHS%E246
      RES%E346 = LHS%E346 + RHS%E346
      RES%E446 = LHS%E446 + RHS%E446
      RES%E156 = LHS%E156 + RHS%E156
      RES%E256 = LHS%E256 + RHS%E256
      RES%E356 = LHS%E356 + RHS%E356
      RES%E456 = LHS%E456 + RHS%E456
      RES%E556 = LHS%E556 + RHS%E556
      RES%E166 = LHS%E166 + RHS%E166
      RES%E266 = LHS%E266 + RHS%E266
      RES%E366 = LHS%E366 + RHS%E366
      RES%E466 = LHS%E466 + RHS%E466
      RES%E566 = LHS%E566 + RHS%E566
      RES%E666 = LHS%E666 + RHS%E666
      RES%E117 = LHS%E117 + RHS%E117
      RES%E127 = LHS%E127 + RHS%E127
      RES%E227 = LHS%E227 + RHS%E227
      RES%E137 = LHS%E137 + RHS%E137
      RES%E237 = LHS%E237 + RHS%E237
      RES%E337 = LHS%E337 + RHS%E337
      RES%E147 = LHS%E147 + RHS%E147
      RES%E247 = LHS%E247 + RHS%E247
      RES%E347 = LHS%E347 + RHS%E347
      RES%E447 = LHS%E447 + RHS%E447
      RES%E157 = LHS%E157 + RHS%E157
      RES%E257 = LHS%E257 + RHS%E257
      RES%E357 = LHS%E357 + RHS%E357
      RES%E457 = LHS%E457 + RHS%E457
      RES%E557 = LHS%E557 + RHS%E557
      RES%E167 = LHS%E167 + RHS%E167
      RES%E267 = LHS%E267 + RHS%E267
      RES%E367 = LHS%E367 + RHS%E367
      RES%E467 = LHS%E467 + RHS%E467
      RES%E567 = LHS%E567 + RHS%E567
      RES%E667 = LHS%E667 + RHS%E667
      RES%E177 = LHS%E177 + RHS%E177
      RES%E277 = LHS%E277 + RHS%E277
      RES%E377 = LHS%E377 + RHS%E377
      RES%E477 = LHS%E477 + RHS%E477
      RES%E577 = LHS%E577 + RHS%E577
      RES%E677 = LHS%E677 + RHS%E677
      RES%E777 = LHS%E777 + RHS%E777

   END FUNCTION ONUMM7N3_ADD_OO_SS

   ELEMENTAL FUNCTION ONUMM7N3_ADD_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES 

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

      ! Order 3
      RES%E111 =  + RHS%E111
      RES%E112 =  + RHS%E112
      RES%E122 =  + RHS%E122
      RES%E222 =  + RHS%E222
      RES%E113 =  + RHS%E113
      RES%E123 =  + RHS%E123
      RES%E223 =  + RHS%E223
      RES%E133 =  + RHS%E133
      RES%E233 =  + RHS%E233
      RES%E333 =  + RHS%E333
      RES%E114 =  + RHS%E114
      RES%E124 =  + RHS%E124
      RES%E224 =  + RHS%E224
      RES%E134 =  + RHS%E134
      RES%E234 =  + RHS%E234
      RES%E334 =  + RHS%E334
      RES%E144 =  + RHS%E144
      RES%E244 =  + RHS%E244
      RES%E344 =  + RHS%E344
      RES%E444 =  + RHS%E444
      RES%E115 =  + RHS%E115
      RES%E125 =  + RHS%E125
      RES%E225 =  + RHS%E225
      RES%E135 =  + RHS%E135
      RES%E235 =  + RHS%E235
      RES%E335 =  + RHS%E335
      RES%E145 =  + RHS%E145
      RES%E245 =  + RHS%E245
      RES%E345 =  + RHS%E345
      RES%E445 =  + RHS%E445
      RES%E155 =  + RHS%E155
      RES%E255 =  + RHS%E255
      RES%E355 =  + RHS%E355
      RES%E455 =  + RHS%E455
      RES%E555 =  + RHS%E555
      RES%E116 =  + RHS%E116
      RES%E126 =  + RHS%E126
      RES%E226 =  + RHS%E226
      RES%E136 =  + RHS%E136
      RES%E236 =  + RHS%E236
      RES%E336 =  + RHS%E336
      RES%E146 =  + RHS%E146
      RES%E246 =  + RHS%E246
      RES%E346 =  + RHS%E346
      RES%E446 =  + RHS%E446
      RES%E156 =  + RHS%E156
      RES%E256 =  + RHS%E256
      RES%E356 =  + RHS%E356
      RES%E456 =  + RHS%E456
      RES%E556 =  + RHS%E556
      RES%E166 =  + RHS%E166
      RES%E266 =  + RHS%E266
      RES%E366 =  + RHS%E366
      RES%E466 =  + RHS%E466
      RES%E566 =  + RHS%E566
      RES%E666 =  + RHS%E666
      RES%E117 =  + RHS%E117
      RES%E127 =  + RHS%E127
      RES%E227 =  + RHS%E227
      RES%E137 =  + RHS%E137
      RES%E237 =  + RHS%E237
      RES%E337 =  + RHS%E337
      RES%E147 =  + RHS%E147
      RES%E247 =  + RHS%E247
      RES%E347 =  + RHS%E347
      RES%E447 =  + RHS%E447
      RES%E157 =  + RHS%E157
      RES%E257 =  + RHS%E257
      RES%E357 =  + RHS%E357
      RES%E457 =  + RHS%E457
      RES%E557 =  + RHS%E557
      RES%E167 =  + RHS%E167
      RES%E267 =  + RHS%E267
      RES%E367 =  + RHS%E367
      RES%E467 =  + RHS%E467
      RES%E567 =  + RHS%E567
      RES%E667 =  + RHS%E667
      RES%E177 =  + RHS%E177
      RES%E277 =  + RHS%E277
      RES%E377 =  + RHS%E377
      RES%E477 =  + RHS%E477
      RES%E577 =  + RHS%E577
      RES%E677 =  + RHS%E677
      RES%E777 =  + RHS%E777

   END FUNCTION ONUMM7N3_ADD_RO_SS

   ELEMENTAL FUNCTION ONUMM7N3_ADD_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E112 = LHS%E112
      RES%E122 = LHS%E122
      RES%E222 = LHS%E222
      RES%E113 = LHS%E113
      RES%E123 = LHS%E123
      RES%E223 = LHS%E223
      RES%E133 = LHS%E133
      RES%E233 = LHS%E233
      RES%E333 = LHS%E333
      RES%E114 = LHS%E114
      RES%E124 = LHS%E124
      RES%E224 = LHS%E224
      RES%E134 = LHS%E134
      RES%E234 = LHS%E234
      RES%E334 = LHS%E334
      RES%E144 = LHS%E144
      RES%E244 = LHS%E244
      RES%E344 = LHS%E344
      RES%E444 = LHS%E444
      RES%E115 = LHS%E115
      RES%E125 = LHS%E125
      RES%E225 = LHS%E225
      RES%E135 = LHS%E135
      RES%E235 = LHS%E235
      RES%E335 = LHS%E335
      RES%E145 = LHS%E145
      RES%E245 = LHS%E245
      RES%E345 = LHS%E345
      RES%E445 = LHS%E445
      RES%E155 = LHS%E155
      RES%E255 = LHS%E255
      RES%E355 = LHS%E355
      RES%E455 = LHS%E455
      RES%E555 = LHS%E555
      RES%E116 = LHS%E116
      RES%E126 = LHS%E126
      RES%E226 = LHS%E226
      RES%E136 = LHS%E136
      RES%E236 = LHS%E236
      RES%E336 = LHS%E336
      RES%E146 = LHS%E146
      RES%E246 = LHS%E246
      RES%E346 = LHS%E346
      RES%E446 = LHS%E446
      RES%E156 = LHS%E156
      RES%E256 = LHS%E256
      RES%E356 = LHS%E356
      RES%E456 = LHS%E456
      RES%E556 = LHS%E556
      RES%E166 = LHS%E166
      RES%E266 = LHS%E266
      RES%E366 = LHS%E366
      RES%E466 = LHS%E466
      RES%E566 = LHS%E566
      RES%E666 = LHS%E666
      RES%E117 = LHS%E117
      RES%E127 = LHS%E127
      RES%E227 = LHS%E227
      RES%E137 = LHS%E137
      RES%E237 = LHS%E237
      RES%E337 = LHS%E337
      RES%E147 = LHS%E147
      RES%E247 = LHS%E247
      RES%E347 = LHS%E347
      RES%E447 = LHS%E447
      RES%E157 = LHS%E157
      RES%E257 = LHS%E257
      RES%E357 = LHS%E357
      RES%E457 = LHS%E457
      RES%E557 = LHS%E557
      RES%E167 = LHS%E167
      RES%E267 = LHS%E267
      RES%E367 = LHS%E367
      RES%E467 = LHS%E467
      RES%E567 = LHS%E567
      RES%E667 = LHS%E667
      RES%E177 = LHS%E177
      RES%E277 = LHS%E277
      RES%E377 = LHS%E377
      RES%E477 = LHS%E477
      RES%E577 = LHS%E577
      RES%E677 = LHS%E677
      RES%E777 = LHS%E777

   END FUNCTION ONUMM7N3_ADD_OR_SS

   ELEMENTAL FUNCTION ONUMM7N3_SUB_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES 

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

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111
      RES%E112 = LHS%E112 - RHS%E112
      RES%E122 = LHS%E122 - RHS%E122
      RES%E222 = LHS%E222 - RHS%E222
      RES%E113 = LHS%E113 - RHS%E113
      RES%E123 = LHS%E123 - RHS%E123
      RES%E223 = LHS%E223 - RHS%E223
      RES%E133 = LHS%E133 - RHS%E133
      RES%E233 = LHS%E233 - RHS%E233
      RES%E333 = LHS%E333 - RHS%E333
      RES%E114 = LHS%E114 - RHS%E114
      RES%E124 = LHS%E124 - RHS%E124
      RES%E224 = LHS%E224 - RHS%E224
      RES%E134 = LHS%E134 - RHS%E134
      RES%E234 = LHS%E234 - RHS%E234
      RES%E334 = LHS%E334 - RHS%E334
      RES%E144 = LHS%E144 - RHS%E144
      RES%E244 = LHS%E244 - RHS%E244
      RES%E344 = LHS%E344 - RHS%E344
      RES%E444 = LHS%E444 - RHS%E444
      RES%E115 = LHS%E115 - RHS%E115
      RES%E125 = LHS%E125 - RHS%E125
      RES%E225 = LHS%E225 - RHS%E225
      RES%E135 = LHS%E135 - RHS%E135
      RES%E235 = LHS%E235 - RHS%E235
      RES%E335 = LHS%E335 - RHS%E335
      RES%E145 = LHS%E145 - RHS%E145
      RES%E245 = LHS%E245 - RHS%E245
      RES%E345 = LHS%E345 - RHS%E345
      RES%E445 = LHS%E445 - RHS%E445
      RES%E155 = LHS%E155 - RHS%E155
      RES%E255 = LHS%E255 - RHS%E255
      RES%E355 = LHS%E355 - RHS%E355
      RES%E455 = LHS%E455 - RHS%E455
      RES%E555 = LHS%E555 - RHS%E555
      RES%E116 = LHS%E116 - RHS%E116
      RES%E126 = LHS%E126 - RHS%E126
      RES%E226 = LHS%E226 - RHS%E226
      RES%E136 = LHS%E136 - RHS%E136
      RES%E236 = LHS%E236 - RHS%E236
      RES%E336 = LHS%E336 - RHS%E336
      RES%E146 = LHS%E146 - RHS%E146
      RES%E246 = LHS%E246 - RHS%E246
      RES%E346 = LHS%E346 - RHS%E346
      RES%E446 = LHS%E446 - RHS%E446
      RES%E156 = LHS%E156 - RHS%E156
      RES%E256 = LHS%E256 - RHS%E256
      RES%E356 = LHS%E356 - RHS%E356
      RES%E456 = LHS%E456 - RHS%E456
      RES%E556 = LHS%E556 - RHS%E556
      RES%E166 = LHS%E166 - RHS%E166
      RES%E266 = LHS%E266 - RHS%E266
      RES%E366 = LHS%E366 - RHS%E366
      RES%E466 = LHS%E466 - RHS%E466
      RES%E566 = LHS%E566 - RHS%E566
      RES%E666 = LHS%E666 - RHS%E666
      RES%E117 = LHS%E117 - RHS%E117
      RES%E127 = LHS%E127 - RHS%E127
      RES%E227 = LHS%E227 - RHS%E227
      RES%E137 = LHS%E137 - RHS%E137
      RES%E237 = LHS%E237 - RHS%E237
      RES%E337 = LHS%E337 - RHS%E337
      RES%E147 = LHS%E147 - RHS%E147
      RES%E247 = LHS%E247 - RHS%E247
      RES%E347 = LHS%E347 - RHS%E347
      RES%E447 = LHS%E447 - RHS%E447
      RES%E157 = LHS%E157 - RHS%E157
      RES%E257 = LHS%E257 - RHS%E257
      RES%E357 = LHS%E357 - RHS%E357
      RES%E457 = LHS%E457 - RHS%E457
      RES%E557 = LHS%E557 - RHS%E557
      RES%E167 = LHS%E167 - RHS%E167
      RES%E267 = LHS%E267 - RHS%E267
      RES%E367 = LHS%E367 - RHS%E367
      RES%E467 = LHS%E467 - RHS%E467
      RES%E567 = LHS%E567 - RHS%E567
      RES%E667 = LHS%E667 - RHS%E667
      RES%E177 = LHS%E177 - RHS%E177
      RES%E277 = LHS%E277 - RHS%E277
      RES%E377 = LHS%E377 - RHS%E377
      RES%E477 = LHS%E477 - RHS%E477
      RES%E577 = LHS%E577 - RHS%E577
      RES%E677 = LHS%E677 - RHS%E677
      RES%E777 = LHS%E777 - RHS%E777

   END FUNCTION ONUMM7N3_SUB_OO_SS

   ELEMENTAL FUNCTION ONUMM7N3_SUB_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES 

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

      ! Order 3
      RES%E111 =  - RHS%E111
      RES%E112 =  - RHS%E112
      RES%E122 =  - RHS%E122
      RES%E222 =  - RHS%E222
      RES%E113 =  - RHS%E113
      RES%E123 =  - RHS%E123
      RES%E223 =  - RHS%E223
      RES%E133 =  - RHS%E133
      RES%E233 =  - RHS%E233
      RES%E333 =  - RHS%E333
      RES%E114 =  - RHS%E114
      RES%E124 =  - RHS%E124
      RES%E224 =  - RHS%E224
      RES%E134 =  - RHS%E134
      RES%E234 =  - RHS%E234
      RES%E334 =  - RHS%E334
      RES%E144 =  - RHS%E144
      RES%E244 =  - RHS%E244
      RES%E344 =  - RHS%E344
      RES%E444 =  - RHS%E444
      RES%E115 =  - RHS%E115
      RES%E125 =  - RHS%E125
      RES%E225 =  - RHS%E225
      RES%E135 =  - RHS%E135
      RES%E235 =  - RHS%E235
      RES%E335 =  - RHS%E335
      RES%E145 =  - RHS%E145
      RES%E245 =  - RHS%E245
      RES%E345 =  - RHS%E345
      RES%E445 =  - RHS%E445
      RES%E155 =  - RHS%E155
      RES%E255 =  - RHS%E255
      RES%E355 =  - RHS%E355
      RES%E455 =  - RHS%E455
      RES%E555 =  - RHS%E555
      RES%E116 =  - RHS%E116
      RES%E126 =  - RHS%E126
      RES%E226 =  - RHS%E226
      RES%E136 =  - RHS%E136
      RES%E236 =  - RHS%E236
      RES%E336 =  - RHS%E336
      RES%E146 =  - RHS%E146
      RES%E246 =  - RHS%E246
      RES%E346 =  - RHS%E346
      RES%E446 =  - RHS%E446
      RES%E156 =  - RHS%E156
      RES%E256 =  - RHS%E256
      RES%E356 =  - RHS%E356
      RES%E456 =  - RHS%E456
      RES%E556 =  - RHS%E556
      RES%E166 =  - RHS%E166
      RES%E266 =  - RHS%E266
      RES%E366 =  - RHS%E366
      RES%E466 =  - RHS%E466
      RES%E566 =  - RHS%E566
      RES%E666 =  - RHS%E666
      RES%E117 =  - RHS%E117
      RES%E127 =  - RHS%E127
      RES%E227 =  - RHS%E227
      RES%E137 =  - RHS%E137
      RES%E237 =  - RHS%E237
      RES%E337 =  - RHS%E337
      RES%E147 =  - RHS%E147
      RES%E247 =  - RHS%E247
      RES%E347 =  - RHS%E347
      RES%E447 =  - RHS%E447
      RES%E157 =  - RHS%E157
      RES%E257 =  - RHS%E257
      RES%E357 =  - RHS%E357
      RES%E457 =  - RHS%E457
      RES%E557 =  - RHS%E557
      RES%E167 =  - RHS%E167
      RES%E267 =  - RHS%E267
      RES%E367 =  - RHS%E367
      RES%E467 =  - RHS%E467
      RES%E567 =  - RHS%E567
      RES%E667 =  - RHS%E667
      RES%E177 =  - RHS%E177
      RES%E277 =  - RHS%E277
      RES%E377 =  - RHS%E377
      RES%E477 =  - RHS%E477
      RES%E577 =  - RHS%E577
      RES%E677 =  - RHS%E677
      RES%E777 =  - RHS%E777

   END FUNCTION ONUMM7N3_SUB_RO_SS

   ELEMENTAL FUNCTION ONUMM7N3_SUB_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E112 = LHS%E112
      RES%E122 = LHS%E122
      RES%E222 = LHS%E222
      RES%E113 = LHS%E113
      RES%E123 = LHS%E123
      RES%E223 = LHS%E223
      RES%E133 = LHS%E133
      RES%E233 = LHS%E233
      RES%E333 = LHS%E333
      RES%E114 = LHS%E114
      RES%E124 = LHS%E124
      RES%E224 = LHS%E224
      RES%E134 = LHS%E134
      RES%E234 = LHS%E234
      RES%E334 = LHS%E334
      RES%E144 = LHS%E144
      RES%E244 = LHS%E244
      RES%E344 = LHS%E344
      RES%E444 = LHS%E444
      RES%E115 = LHS%E115
      RES%E125 = LHS%E125
      RES%E225 = LHS%E225
      RES%E135 = LHS%E135
      RES%E235 = LHS%E235
      RES%E335 = LHS%E335
      RES%E145 = LHS%E145
      RES%E245 = LHS%E245
      RES%E345 = LHS%E345
      RES%E445 = LHS%E445
      RES%E155 = LHS%E155
      RES%E255 = LHS%E255
      RES%E355 = LHS%E355
      RES%E455 = LHS%E455
      RES%E555 = LHS%E555
      RES%E116 = LHS%E116
      RES%E126 = LHS%E126
      RES%E226 = LHS%E226
      RES%E136 = LHS%E136
      RES%E236 = LHS%E236
      RES%E336 = LHS%E336
      RES%E146 = LHS%E146
      RES%E246 = LHS%E246
      RES%E346 = LHS%E346
      RES%E446 = LHS%E446
      RES%E156 = LHS%E156
      RES%E256 = LHS%E256
      RES%E356 = LHS%E356
      RES%E456 = LHS%E456
      RES%E556 = LHS%E556
      RES%E166 = LHS%E166
      RES%E266 = LHS%E266
      RES%E366 = LHS%E366
      RES%E466 = LHS%E466
      RES%E566 = LHS%E566
      RES%E666 = LHS%E666
      RES%E117 = LHS%E117
      RES%E127 = LHS%E127
      RES%E227 = LHS%E227
      RES%E137 = LHS%E137
      RES%E237 = LHS%E237
      RES%E337 = LHS%E337
      RES%E147 = LHS%E147
      RES%E247 = LHS%E247
      RES%E347 = LHS%E347
      RES%E447 = LHS%E447
      RES%E157 = LHS%E157
      RES%E257 = LHS%E257
      RES%E357 = LHS%E357
      RES%E457 = LHS%E457
      RES%E557 = LHS%E557
      RES%E167 = LHS%E167
      RES%E267 = LHS%E267
      RES%E367 = LHS%E367
      RES%E467 = LHS%E467
      RES%E567 = LHS%E567
      RES%E667 = LHS%E667
      RES%E177 = LHS%E177
      RES%E277 = LHS%E277
      RES%E377 = LHS%E377
      RES%E477 = LHS%E477
      RES%E577 = LHS%E577
      RES%E677 = LHS%E677
      RES%E777 = LHS%E777

   END FUNCTION ONUMM7N3_SUB_OR_SS

   ELEMENTAL FUNCTION ONUMM7N3_MUL_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES 

      !  Multiplication like function 'LHS*RHS'
      ! Order 3
      RES%E111 = LHS%R*RHS%E111 + LHS%E111*RHS%R +  &
              LHS%E1*RHS%E11 + LHS%E11*RHS%E1
      RES%E112 = LHS%R*RHS%E112 + LHS%E112*RHS%R +  &
              LHS%E1*RHS%E12 + LHS%E12*RHS%E1 + LHS%E2*RHS%E11 + LHS%E11*RHS%E2
      RES%E122 = LHS%R*RHS%E122 + LHS%E122*RHS%R +  &
              LHS%E1*RHS%E22 + LHS%E22*RHS%E1 + LHS%E2*RHS%E12 + LHS%E12*RHS%E2
      RES%E222 = LHS%R*RHS%E222 + LHS%E222*RHS%R +  &
              LHS%E2*RHS%E22 + LHS%E22*RHS%E2
      RES%E113 = LHS%R*RHS%E113 + LHS%E113*RHS%R +  &
              LHS%E1*RHS%E13 + LHS%E13*RHS%E1 + LHS%E3*RHS%E11 + LHS%E11*RHS%E3
      RES%E123 = LHS%R*RHS%E123 + LHS%E123*RHS%R +  &
              LHS%E1*RHS%E23 + LHS%E23*RHS%E1 + LHS%E2*RHS%E13 +  &
              LHS%E13*RHS%E2 + LHS%E3*RHS%E12 + LHS%E12*RHS%E3
      RES%E223 = LHS%R*RHS%E223 + LHS%E223*RHS%R +  &
              LHS%E2*RHS%E23 + LHS%E23*RHS%E2 + LHS%E3*RHS%E22 + LHS%E22*RHS%E3
      RES%E133 = LHS%R*RHS%E133 + LHS%E133*RHS%R +  &
              LHS%E1*RHS%E33 + LHS%E33*RHS%E1 + LHS%E3*RHS%E13 + LHS%E13*RHS%E3
      RES%E233 = LHS%R*RHS%E233 + LHS%E233*RHS%R +  &
              LHS%E2*RHS%E33 + LHS%E33*RHS%E2 + LHS%E3*RHS%E23 + LHS%E23*RHS%E3
      RES%E333 = LHS%R*RHS%E333 + LHS%E333*RHS%R +  &
              LHS%E3*RHS%E33 + LHS%E33*RHS%E3
      RES%E114 = LHS%R*RHS%E114 + LHS%E114*RHS%R +  &
              LHS%E1*RHS%E14 + LHS%E14*RHS%E1 + LHS%E4*RHS%E11 + LHS%E11*RHS%E4
      RES%E124 = LHS%R*RHS%E124 + LHS%E124*RHS%R +  &
              LHS%E1*RHS%E24 + LHS%E24*RHS%E1 + LHS%E2*RHS%E14 +  &
              LHS%E14*RHS%E2 + LHS%E4*RHS%E12 + LHS%E12*RHS%E4
      RES%E224 = LHS%R*RHS%E224 + LHS%E224*RHS%R +  &
              LHS%E2*RHS%E24 + LHS%E24*RHS%E2 + LHS%E4*RHS%E22 + LHS%E22*RHS%E4
      RES%E134 = LHS%R*RHS%E134 + LHS%E134*RHS%R +  &
              LHS%E1*RHS%E34 + LHS%E34*RHS%E1 + LHS%E3*RHS%E14 +  &
              LHS%E14*RHS%E3 + LHS%E4*RHS%E13 + LHS%E13*RHS%E4
      RES%E234 = LHS%R*RHS%E234 + LHS%E234*RHS%R +  &
              LHS%E2*RHS%E34 + LHS%E34*RHS%E2 + LHS%E3*RHS%E24 +  &
              LHS%E24*RHS%E3 + LHS%E4*RHS%E23 + LHS%E23*RHS%E4
      RES%E334 = LHS%R*RHS%E334 + LHS%E334*RHS%R +  &
              LHS%E3*RHS%E34 + LHS%E34*RHS%E3 + LHS%E4*RHS%E33 + LHS%E33*RHS%E4
      RES%E144 = LHS%R*RHS%E144 + LHS%E144*RHS%R +  &
              LHS%E1*RHS%E44 + LHS%E44*RHS%E1 + LHS%E4*RHS%E14 + LHS%E14*RHS%E4
      RES%E244 = LHS%R*RHS%E244 + LHS%E244*RHS%R +  &
              LHS%E2*RHS%E44 + LHS%E44*RHS%E2 + LHS%E4*RHS%E24 + LHS%E24*RHS%E4
      RES%E344 = LHS%R*RHS%E344 + LHS%E344*RHS%R +  &
              LHS%E3*RHS%E44 + LHS%E44*RHS%E3 + LHS%E4*RHS%E34 + LHS%E34*RHS%E4
      RES%E444 = LHS%R*RHS%E444 + LHS%E444*RHS%R +  &
              LHS%E4*RHS%E44 + LHS%E44*RHS%E4
      RES%E115 = LHS%R*RHS%E115 + LHS%E115*RHS%R +  &
              LHS%E1*RHS%E15 + LHS%E15*RHS%E1 + LHS%E5*RHS%E11 + LHS%E11*RHS%E5
      RES%E125 = LHS%R*RHS%E125 + LHS%E125*RHS%R +  &
              LHS%E1*RHS%E25 + LHS%E25*RHS%E1 + LHS%E2*RHS%E15 +  &
              LHS%E15*RHS%E2 + LHS%E5*RHS%E12 + LHS%E12*RHS%E5
      RES%E225 = LHS%R*RHS%E225 + LHS%E225*RHS%R +  &
              LHS%E2*RHS%E25 + LHS%E25*RHS%E2 + LHS%E5*RHS%E22 + LHS%E22*RHS%E5
      RES%E135 = LHS%R*RHS%E135 + LHS%E135*RHS%R +  &
              LHS%E1*RHS%E35 + LHS%E35*RHS%E1 + LHS%E3*RHS%E15 +  &
              LHS%E15*RHS%E3 + LHS%E5*RHS%E13 + LHS%E13*RHS%E5
      RES%E235 = LHS%R*RHS%E235 + LHS%E235*RHS%R +  &
              LHS%E2*RHS%E35 + LHS%E35*RHS%E2 + LHS%E3*RHS%E25 +  &
              LHS%E25*RHS%E3 + LHS%E5*RHS%E23 + LHS%E23*RHS%E5
      RES%E335 = LHS%R*RHS%E335 + LHS%E335*RHS%R +  &
              LHS%E3*RHS%E35 + LHS%E35*RHS%E3 + LHS%E5*RHS%E33 + LHS%E33*RHS%E5
      RES%E145 = LHS%R*RHS%E145 + LHS%E145*RHS%R +  &
              LHS%E1*RHS%E45 + LHS%E45*RHS%E1 + LHS%E4*RHS%E15 +  &
              LHS%E15*RHS%E4 + LHS%E5*RHS%E14 + LHS%E14*RHS%E5
      RES%E245 = LHS%R*RHS%E245 + LHS%E245*RHS%R +  &
              LHS%E2*RHS%E45 + LHS%E45*RHS%E2 + LHS%E4*RHS%E25 +  &
              LHS%E25*RHS%E4 + LHS%E5*RHS%E24 + LHS%E24*RHS%E5
      RES%E345 = LHS%R*RHS%E345 + LHS%E345*RHS%R +  &
              LHS%E3*RHS%E45 + LHS%E45*RHS%E3 + LHS%E4*RHS%E35 +  &
              LHS%E35*RHS%E4 + LHS%E5*RHS%E34 + LHS%E34*RHS%E5
      RES%E445 = LHS%R*RHS%E445 + LHS%E445*RHS%R +  &
              LHS%E4*RHS%E45 + LHS%E45*RHS%E4 + LHS%E5*RHS%E44 + LHS%E44*RHS%E5
      RES%E155 = LHS%R*RHS%E155 + LHS%E155*RHS%R +  &
              LHS%E1*RHS%E55 + LHS%E55*RHS%E1 + LHS%E5*RHS%E15 + LHS%E15*RHS%E5
      RES%E255 = LHS%R*RHS%E255 + LHS%E255*RHS%R +  &
              LHS%E2*RHS%E55 + LHS%E55*RHS%E2 + LHS%E5*RHS%E25 + LHS%E25*RHS%E5
      RES%E355 = LHS%R*RHS%E355 + LHS%E355*RHS%R +  &
              LHS%E3*RHS%E55 + LHS%E55*RHS%E3 + LHS%E5*RHS%E35 + LHS%E35*RHS%E5
      RES%E455 = LHS%R*RHS%E455 + LHS%E455*RHS%R +  &
              LHS%E4*RHS%E55 + LHS%E55*RHS%E4 + LHS%E5*RHS%E45 + LHS%E45*RHS%E5
      RES%E555 = LHS%R*RHS%E555 + LHS%E555*RHS%R +  &
              LHS%E5*RHS%E55 + LHS%E55*RHS%E5
      RES%E116 = LHS%R*RHS%E116 + LHS%E116*RHS%R +  &
              LHS%E1*RHS%E16 + LHS%E16*RHS%E1 + LHS%E6*RHS%E11 + LHS%E11*RHS%E6
      RES%E126 = LHS%R*RHS%E126 + LHS%E126*RHS%R +  &
              LHS%E1*RHS%E26 + LHS%E26*RHS%E1 + LHS%E2*RHS%E16 +  &
              LHS%E16*RHS%E2 + LHS%E6*RHS%E12 + LHS%E12*RHS%E6
      RES%E226 = LHS%R*RHS%E226 + LHS%E226*RHS%R +  &
              LHS%E2*RHS%E26 + LHS%E26*RHS%E2 + LHS%E6*RHS%E22 + LHS%E22*RHS%E6
      RES%E136 = LHS%R*RHS%E136 + LHS%E136*RHS%R +  &
              LHS%E1*RHS%E36 + LHS%E36*RHS%E1 + LHS%E3*RHS%E16 +  &
              LHS%E16*RHS%E3 + LHS%E6*RHS%E13 + LHS%E13*RHS%E6
      RES%E236 = LHS%R*RHS%E236 + LHS%E236*RHS%R +  &
              LHS%E2*RHS%E36 + LHS%E36*RHS%E2 + LHS%E3*RHS%E26 +  &
              LHS%E26*RHS%E3 + LHS%E6*RHS%E23 + LHS%E23*RHS%E6
      RES%E336 = LHS%R*RHS%E336 + LHS%E336*RHS%R +  &
              LHS%E3*RHS%E36 + LHS%E36*RHS%E3 + LHS%E6*RHS%E33 + LHS%E33*RHS%E6
      RES%E146 = LHS%R*RHS%E146 + LHS%E146*RHS%R +  &
              LHS%E1*RHS%E46 + LHS%E46*RHS%E1 + LHS%E4*RHS%E16 +  &
              LHS%E16*RHS%E4 + LHS%E6*RHS%E14 + LHS%E14*RHS%E6
      RES%E246 = LHS%R*RHS%E246 + LHS%E246*RHS%R +  &
              LHS%E2*RHS%E46 + LHS%E46*RHS%E2 + LHS%E4*RHS%E26 +  &
              LHS%E26*RHS%E4 + LHS%E6*RHS%E24 + LHS%E24*RHS%E6
      RES%E346 = LHS%R*RHS%E346 + LHS%E346*RHS%R +  &
              LHS%E3*RHS%E46 + LHS%E46*RHS%E3 + LHS%E4*RHS%E36 +  &
              LHS%E36*RHS%E4 + LHS%E6*RHS%E34 + LHS%E34*RHS%E6
      RES%E446 = LHS%R*RHS%E446 + LHS%E446*RHS%R +  &
              LHS%E4*RHS%E46 + LHS%E46*RHS%E4 + LHS%E6*RHS%E44 + LHS%E44*RHS%E6
      RES%E156 = LHS%R*RHS%E156 + LHS%E156*RHS%R +  &
              LHS%E1*RHS%E56 + LHS%E56*RHS%E1 + LHS%E5*RHS%E16 +  &
              LHS%E16*RHS%E5 + LHS%E6*RHS%E15 + LHS%E15*RHS%E6
      RES%E256 = LHS%R*RHS%E256 + LHS%E256*RHS%R +  &
              LHS%E2*RHS%E56 + LHS%E56*RHS%E2 + LHS%E5*RHS%E26 +  &
              LHS%E26*RHS%E5 + LHS%E6*RHS%E25 + LHS%E25*RHS%E6
      RES%E356 = LHS%R*RHS%E356 + LHS%E356*RHS%R +  &
              LHS%E3*RHS%E56 + LHS%E56*RHS%E3 + LHS%E5*RHS%E36 +  &
              LHS%E36*RHS%E5 + LHS%E6*RHS%E35 + LHS%E35*RHS%E6
      RES%E456 = LHS%R*RHS%E456 + LHS%E456*RHS%R +  &
              LHS%E4*RHS%E56 + LHS%E56*RHS%E4 + LHS%E5*RHS%E46 +  &
              LHS%E46*RHS%E5 + LHS%E6*RHS%E45 + LHS%E45*RHS%E6
      RES%E556 = LHS%R*RHS%E556 + LHS%E556*RHS%R +  &
              LHS%E5*RHS%E56 + LHS%E56*RHS%E5 + LHS%E6*RHS%E55 + LHS%E55*RHS%E6
      RES%E166 = LHS%R*RHS%E166 + LHS%E166*RHS%R +  &
              LHS%E1*RHS%E66 + LHS%E66*RHS%E1 + LHS%E6*RHS%E16 + LHS%E16*RHS%E6
      RES%E266 = LHS%R*RHS%E266 + LHS%E266*RHS%R +  &
              LHS%E2*RHS%E66 + LHS%E66*RHS%E2 + LHS%E6*RHS%E26 + LHS%E26*RHS%E6
      RES%E366 = LHS%R*RHS%E366 + LHS%E366*RHS%R +  &
              LHS%E3*RHS%E66 + LHS%E66*RHS%E3 + LHS%E6*RHS%E36 + LHS%E36*RHS%E6
      RES%E466 = LHS%R*RHS%E466 + LHS%E466*RHS%R +  &
              LHS%E4*RHS%E66 + LHS%E66*RHS%E4 + LHS%E6*RHS%E46 + LHS%E46*RHS%E6
      RES%E566 = LHS%R*RHS%E566 + LHS%E566*RHS%R +  &
              LHS%E5*RHS%E66 + LHS%E66*RHS%E5 + LHS%E6*RHS%E56 + LHS%E56*RHS%E6
      RES%E666 = LHS%R*RHS%E666 + LHS%E666*RHS%R +  &
              LHS%E6*RHS%E66 + LHS%E66*RHS%E6
      RES%E117 = LHS%R*RHS%E117 + LHS%E117*RHS%R +  &
              LHS%E1*RHS%E17 + LHS%E17*RHS%E1 + LHS%E7*RHS%E11 + LHS%E11*RHS%E7
      RES%E127 = LHS%R*RHS%E127 + LHS%E127*RHS%R +  &
              LHS%E1*RHS%E27 + LHS%E27*RHS%E1 + LHS%E2*RHS%E17 +  &
              LHS%E17*RHS%E2 + LHS%E7*RHS%E12 + LHS%E12*RHS%E7
      RES%E227 = LHS%R*RHS%E227 + LHS%E227*RHS%R +  &
              LHS%E2*RHS%E27 + LHS%E27*RHS%E2 + LHS%E7*RHS%E22 + LHS%E22*RHS%E7
      RES%E137 = LHS%R*RHS%E137 + LHS%E137*RHS%R +  &
              LHS%E1*RHS%E37 + LHS%E37*RHS%E1 + LHS%E3*RHS%E17 +  &
              LHS%E17*RHS%E3 + LHS%E7*RHS%E13 + LHS%E13*RHS%E7
      RES%E237 = LHS%R*RHS%E237 + LHS%E237*RHS%R +  &
              LHS%E2*RHS%E37 + LHS%E37*RHS%E2 + LHS%E3*RHS%E27 +  &
              LHS%E27*RHS%E3 + LHS%E7*RHS%E23 + LHS%E23*RHS%E7
      RES%E337 = LHS%R*RHS%E337 + LHS%E337*RHS%R +  &
              LHS%E3*RHS%E37 + LHS%E37*RHS%E3 + LHS%E7*RHS%E33 + LHS%E33*RHS%E7
      RES%E147 = LHS%R*RHS%E147 + LHS%E147*RHS%R +  &
              LHS%E1*RHS%E47 + LHS%E47*RHS%E1 + LHS%E4*RHS%E17 +  &
              LHS%E17*RHS%E4 + LHS%E7*RHS%E14 + LHS%E14*RHS%E7
      RES%E247 = LHS%R*RHS%E247 + LHS%E247*RHS%R +  &
              LHS%E2*RHS%E47 + LHS%E47*RHS%E2 + LHS%E4*RHS%E27 +  &
              LHS%E27*RHS%E4 + LHS%E7*RHS%E24 + LHS%E24*RHS%E7
      RES%E347 = LHS%R*RHS%E347 + LHS%E347*RHS%R +  &
              LHS%E3*RHS%E47 + LHS%E47*RHS%E3 + LHS%E4*RHS%E37 +  &
              LHS%E37*RHS%E4 + LHS%E7*RHS%E34 + LHS%E34*RHS%E7
      RES%E447 = LHS%R*RHS%E447 + LHS%E447*RHS%R +  &
              LHS%E4*RHS%E47 + LHS%E47*RHS%E4 + LHS%E7*RHS%E44 + LHS%E44*RHS%E7
      RES%E157 = LHS%R*RHS%E157 + LHS%E157*RHS%R +  &
              LHS%E1*RHS%E57 + LHS%E57*RHS%E1 + LHS%E5*RHS%E17 +  &
              LHS%E17*RHS%E5 + LHS%E7*RHS%E15 + LHS%E15*RHS%E7
      RES%E257 = LHS%R*RHS%E257 + LHS%E257*RHS%R +  &
              LHS%E2*RHS%E57 + LHS%E57*RHS%E2 + LHS%E5*RHS%E27 +  &
              LHS%E27*RHS%E5 + LHS%E7*RHS%E25 + LHS%E25*RHS%E7
      RES%E357 = LHS%R*RHS%E357 + LHS%E357*RHS%R +  &
              LHS%E3*RHS%E57 + LHS%E57*RHS%E3 + LHS%E5*RHS%E37 +  &
              LHS%E37*RHS%E5 + LHS%E7*RHS%E35 + LHS%E35*RHS%E7
      RES%E457 = LHS%R*RHS%E457 + LHS%E457*RHS%R +  &
              LHS%E4*RHS%E57 + LHS%E57*RHS%E4 + LHS%E5*RHS%E47 +  &
              LHS%E47*RHS%E5 + LHS%E7*RHS%E45 + LHS%E45*RHS%E7
      RES%E557 = LHS%R*RHS%E557 + LHS%E557*RHS%R +  &
              LHS%E5*RHS%E57 + LHS%E57*RHS%E5 + LHS%E7*RHS%E55 + LHS%E55*RHS%E7
      RES%E167 = LHS%R*RHS%E167 + LHS%E167*RHS%R +  &
              LHS%E1*RHS%E67 + LHS%E67*RHS%E1 + LHS%E6*RHS%E17 +  &
              LHS%E17*RHS%E6 + LHS%E7*RHS%E16 + LHS%E16*RHS%E7
      RES%E267 = LHS%R*RHS%E267 + LHS%E267*RHS%R +  &
              LHS%E2*RHS%E67 + LHS%E67*RHS%E2 + LHS%E6*RHS%E27 +  &
              LHS%E27*RHS%E6 + LHS%E7*RHS%E26 + LHS%E26*RHS%E7
      RES%E367 = LHS%R*RHS%E367 + LHS%E367*RHS%R +  &
              LHS%E3*RHS%E67 + LHS%E67*RHS%E3 + LHS%E6*RHS%E37 +  &
              LHS%E37*RHS%E6 + LHS%E7*RHS%E36 + LHS%E36*RHS%E7
      RES%E467 = LHS%R*RHS%E467 + LHS%E467*RHS%R +  &
              LHS%E4*RHS%E67 + LHS%E67*RHS%E4 + LHS%E6*RHS%E47 +  &
              LHS%E47*RHS%E6 + LHS%E7*RHS%E46 + LHS%E46*RHS%E7
      RES%E567 = LHS%R*RHS%E567 + LHS%E567*RHS%R +  &
              LHS%E5*RHS%E67 + LHS%E67*RHS%E5 + LHS%E6*RHS%E57 +  &
              LHS%E57*RHS%E6 + LHS%E7*RHS%E56 + LHS%E56*RHS%E7
      RES%E667 = LHS%R*RHS%E667 + LHS%E667*RHS%R +  &
              LHS%E6*RHS%E67 + LHS%E67*RHS%E6 + LHS%E7*RHS%E66 + LHS%E66*RHS%E7
      RES%E177 = LHS%R*RHS%E177 + LHS%E177*RHS%R +  &
              LHS%E1*RHS%E77 + LHS%E77*RHS%E1 + LHS%E7*RHS%E17 + LHS%E17*RHS%E7
      RES%E277 = LHS%R*RHS%E277 + LHS%E277*RHS%R +  &
              LHS%E2*RHS%E77 + LHS%E77*RHS%E2 + LHS%E7*RHS%E27 + LHS%E27*RHS%E7
      RES%E377 = LHS%R*RHS%E377 + LHS%E377*RHS%R +  &
              LHS%E3*RHS%E77 + LHS%E77*RHS%E3 + LHS%E7*RHS%E37 + LHS%E37*RHS%E7
      RES%E477 = LHS%R*RHS%E477 + LHS%E477*RHS%R +  &
              LHS%E4*RHS%E77 + LHS%E77*RHS%E4 + LHS%E7*RHS%E47 + LHS%E47*RHS%E7
      RES%E577 = LHS%R*RHS%E577 + LHS%E577*RHS%R +  &
              LHS%E5*RHS%E77 + LHS%E77*RHS%E5 + LHS%E7*RHS%E57 + LHS%E57*RHS%E7
      RES%E677 = LHS%R*RHS%E677 + LHS%E677*RHS%R +  &
              LHS%E6*RHS%E77 + LHS%E77*RHS%E6 + LHS%E7*RHS%E67 + LHS%E67*RHS%E7
      RES%E777 = LHS%R*RHS%E777 + LHS%E777*RHS%R +  &
              LHS%E7*RHS%E77 + LHS%E77*RHS%E7
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

   END FUNCTION ONUMM7N3_MUL_OO_SS

   ELEMENTAL FUNCTION ONUMM7N3_MUL_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES 

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

      ! Order 3
      RES%E111 = LHS*RHS%E111
      RES%E112 = LHS*RHS%E112
      RES%E122 = LHS*RHS%E122
      RES%E222 = LHS*RHS%E222
      RES%E113 = LHS*RHS%E113
      RES%E123 = LHS*RHS%E123
      RES%E223 = LHS*RHS%E223
      RES%E133 = LHS*RHS%E133
      RES%E233 = LHS*RHS%E233
      RES%E333 = LHS*RHS%E333
      RES%E114 = LHS*RHS%E114
      RES%E124 = LHS*RHS%E124
      RES%E224 = LHS*RHS%E224
      RES%E134 = LHS*RHS%E134
      RES%E234 = LHS*RHS%E234
      RES%E334 = LHS*RHS%E334
      RES%E144 = LHS*RHS%E144
      RES%E244 = LHS*RHS%E244
      RES%E344 = LHS*RHS%E344
      RES%E444 = LHS*RHS%E444
      RES%E115 = LHS*RHS%E115
      RES%E125 = LHS*RHS%E125
      RES%E225 = LHS*RHS%E225
      RES%E135 = LHS*RHS%E135
      RES%E235 = LHS*RHS%E235
      RES%E335 = LHS*RHS%E335
      RES%E145 = LHS*RHS%E145
      RES%E245 = LHS*RHS%E245
      RES%E345 = LHS*RHS%E345
      RES%E445 = LHS*RHS%E445
      RES%E155 = LHS*RHS%E155
      RES%E255 = LHS*RHS%E255
      RES%E355 = LHS*RHS%E355
      RES%E455 = LHS*RHS%E455
      RES%E555 = LHS*RHS%E555
      RES%E116 = LHS*RHS%E116
      RES%E126 = LHS*RHS%E126
      RES%E226 = LHS*RHS%E226
      RES%E136 = LHS*RHS%E136
      RES%E236 = LHS*RHS%E236
      RES%E336 = LHS*RHS%E336
      RES%E146 = LHS*RHS%E146
      RES%E246 = LHS*RHS%E246
      RES%E346 = LHS*RHS%E346
      RES%E446 = LHS*RHS%E446
      RES%E156 = LHS*RHS%E156
      RES%E256 = LHS*RHS%E256
      RES%E356 = LHS*RHS%E356
      RES%E456 = LHS*RHS%E456
      RES%E556 = LHS*RHS%E556
      RES%E166 = LHS*RHS%E166
      RES%E266 = LHS*RHS%E266
      RES%E366 = LHS*RHS%E366
      RES%E466 = LHS*RHS%E466
      RES%E566 = LHS*RHS%E566
      RES%E666 = LHS*RHS%E666
      RES%E117 = LHS*RHS%E117
      RES%E127 = LHS*RHS%E127
      RES%E227 = LHS*RHS%E227
      RES%E137 = LHS*RHS%E137
      RES%E237 = LHS*RHS%E237
      RES%E337 = LHS*RHS%E337
      RES%E147 = LHS*RHS%E147
      RES%E247 = LHS*RHS%E247
      RES%E347 = LHS*RHS%E347
      RES%E447 = LHS*RHS%E447
      RES%E157 = LHS*RHS%E157
      RES%E257 = LHS*RHS%E257
      RES%E357 = LHS*RHS%E357
      RES%E457 = LHS*RHS%E457
      RES%E557 = LHS*RHS%E557
      RES%E167 = LHS*RHS%E167
      RES%E267 = LHS*RHS%E267
      RES%E367 = LHS*RHS%E367
      RES%E467 = LHS*RHS%E467
      RES%E567 = LHS*RHS%E567
      RES%E667 = LHS*RHS%E667
      RES%E177 = LHS*RHS%E177
      RES%E277 = LHS*RHS%E277
      RES%E377 = LHS*RHS%E377
      RES%E477 = LHS*RHS%E477
      RES%E577 = LHS*RHS%E577
      RES%E677 = LHS*RHS%E677
      RES%E777 = LHS*RHS%E777

   END FUNCTION ONUMM7N3_MUL_RO_SS

   ELEMENTAL FUNCTION ONUMM7N3_MUL_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES 

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

      ! Order 3
      RES%E111 = LHS%E111*RHS
      RES%E112 = LHS%E112*RHS
      RES%E122 = LHS%E122*RHS
      RES%E222 = LHS%E222*RHS
      RES%E113 = LHS%E113*RHS
      RES%E123 = LHS%E123*RHS
      RES%E223 = LHS%E223*RHS
      RES%E133 = LHS%E133*RHS
      RES%E233 = LHS%E233*RHS
      RES%E333 = LHS%E333*RHS
      RES%E114 = LHS%E114*RHS
      RES%E124 = LHS%E124*RHS
      RES%E224 = LHS%E224*RHS
      RES%E134 = LHS%E134*RHS
      RES%E234 = LHS%E234*RHS
      RES%E334 = LHS%E334*RHS
      RES%E144 = LHS%E144*RHS
      RES%E244 = LHS%E244*RHS
      RES%E344 = LHS%E344*RHS
      RES%E444 = LHS%E444*RHS
      RES%E115 = LHS%E115*RHS
      RES%E125 = LHS%E125*RHS
      RES%E225 = LHS%E225*RHS
      RES%E135 = LHS%E135*RHS
      RES%E235 = LHS%E235*RHS
      RES%E335 = LHS%E335*RHS
      RES%E145 = LHS%E145*RHS
      RES%E245 = LHS%E245*RHS
      RES%E345 = LHS%E345*RHS
      RES%E445 = LHS%E445*RHS
      RES%E155 = LHS%E155*RHS
      RES%E255 = LHS%E255*RHS
      RES%E355 = LHS%E355*RHS
      RES%E455 = LHS%E455*RHS
      RES%E555 = LHS%E555*RHS
      RES%E116 = LHS%E116*RHS
      RES%E126 = LHS%E126*RHS
      RES%E226 = LHS%E226*RHS
      RES%E136 = LHS%E136*RHS
      RES%E236 = LHS%E236*RHS
      RES%E336 = LHS%E336*RHS
      RES%E146 = LHS%E146*RHS
      RES%E246 = LHS%E246*RHS
      RES%E346 = LHS%E346*RHS
      RES%E446 = LHS%E446*RHS
      RES%E156 = LHS%E156*RHS
      RES%E256 = LHS%E256*RHS
      RES%E356 = LHS%E356*RHS
      RES%E456 = LHS%E456*RHS
      RES%E556 = LHS%E556*RHS
      RES%E166 = LHS%E166*RHS
      RES%E266 = LHS%E266*RHS
      RES%E366 = LHS%E366*RHS
      RES%E466 = LHS%E466*RHS
      RES%E566 = LHS%E566*RHS
      RES%E666 = LHS%E666*RHS
      RES%E117 = LHS%E117*RHS
      RES%E127 = LHS%E127*RHS
      RES%E227 = LHS%E227*RHS
      RES%E137 = LHS%E137*RHS
      RES%E237 = LHS%E237*RHS
      RES%E337 = LHS%E337*RHS
      RES%E147 = LHS%E147*RHS
      RES%E247 = LHS%E247*RHS
      RES%E347 = LHS%E347*RHS
      RES%E447 = LHS%E447*RHS
      RES%E157 = LHS%E157*RHS
      RES%E257 = LHS%E257*RHS
      RES%E357 = LHS%E357*RHS
      RES%E457 = LHS%E457*RHS
      RES%E557 = LHS%E557*RHS
      RES%E167 = LHS%E167*RHS
      RES%E267 = LHS%E267*RHS
      RES%E367 = LHS%E367*RHS
      RES%E467 = LHS%E467*RHS
      RES%E567 = LHS%E567*RHS
      RES%E667 = LHS%E667*RHS
      RES%E177 = LHS%E177*RHS
      RES%E277 = LHS%E277*RHS
      RES%E377 = LHS%E377*RHS
      RES%E477 = LHS%E477*RHS
      RES%E577 = LHS%E577*RHS
      RES%E677 = LHS%E677*RHS
      RES%E777 = LHS%E777*RHS

   END FUNCTION ONUMM7N3_MUL_OR_SS

   FUNCTION ONUMM7N3_ADD_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:)
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111
      RES%E112 = LHS%E112 + RHS%E112
      RES%E122 = LHS%E122 + RHS%E122
      RES%E222 = LHS%E222 + RHS%E222
      RES%E113 = LHS%E113 + RHS%E113
      RES%E123 = LHS%E123 + RHS%E123
      RES%E223 = LHS%E223 + RHS%E223
      RES%E133 = LHS%E133 + RHS%E133
      RES%E233 = LHS%E233 + RHS%E233
      RES%E333 = LHS%E333 + RHS%E333
      RES%E114 = LHS%E114 + RHS%E114
      RES%E124 = LHS%E124 + RHS%E124
      RES%E224 = LHS%E224 + RHS%E224
      RES%E134 = LHS%E134 + RHS%E134
      RES%E234 = LHS%E234 + RHS%E234
      RES%E334 = LHS%E334 + RHS%E334
      RES%E144 = LHS%E144 + RHS%E144
      RES%E244 = LHS%E244 + RHS%E244
      RES%E344 = LHS%E344 + RHS%E344
      RES%E444 = LHS%E444 + RHS%E444
      RES%E115 = LHS%E115 + RHS%E115
      RES%E125 = LHS%E125 + RHS%E125
      RES%E225 = LHS%E225 + RHS%E225
      RES%E135 = LHS%E135 + RHS%E135
      RES%E235 = LHS%E235 + RHS%E235
      RES%E335 = LHS%E335 + RHS%E335
      RES%E145 = LHS%E145 + RHS%E145
      RES%E245 = LHS%E245 + RHS%E245
      RES%E345 = LHS%E345 + RHS%E345
      RES%E445 = LHS%E445 + RHS%E445
      RES%E155 = LHS%E155 + RHS%E155
      RES%E255 = LHS%E255 + RHS%E255
      RES%E355 = LHS%E355 + RHS%E355
      RES%E455 = LHS%E455 + RHS%E455
      RES%E555 = LHS%E555 + RHS%E555
      RES%E116 = LHS%E116 + RHS%E116
      RES%E126 = LHS%E126 + RHS%E126
      RES%E226 = LHS%E226 + RHS%E226
      RES%E136 = LHS%E136 + RHS%E136
      RES%E236 = LHS%E236 + RHS%E236
      RES%E336 = LHS%E336 + RHS%E336
      RES%E146 = LHS%E146 + RHS%E146
      RES%E246 = LHS%E246 + RHS%E246
      RES%E346 = LHS%E346 + RHS%E346
      RES%E446 = LHS%E446 + RHS%E446
      RES%E156 = LHS%E156 + RHS%E156
      RES%E256 = LHS%E256 + RHS%E256
      RES%E356 = LHS%E356 + RHS%E356
      RES%E456 = LHS%E456 + RHS%E456
      RES%E556 = LHS%E556 + RHS%E556
      RES%E166 = LHS%E166 + RHS%E166
      RES%E266 = LHS%E266 + RHS%E266
      RES%E366 = LHS%E366 + RHS%E366
      RES%E466 = LHS%E466 + RHS%E466
      RES%E566 = LHS%E566 + RHS%E566
      RES%E666 = LHS%E666 + RHS%E666
      RES%E117 = LHS%E117 + RHS%E117
      RES%E127 = LHS%E127 + RHS%E127
      RES%E227 = LHS%E227 + RHS%E227
      RES%E137 = LHS%E137 + RHS%E137
      RES%E237 = LHS%E237 + RHS%E237
      RES%E337 = LHS%E337 + RHS%E337
      RES%E147 = LHS%E147 + RHS%E147
      RES%E247 = LHS%E247 + RHS%E247
      RES%E347 = LHS%E347 + RHS%E347
      RES%E447 = LHS%E447 + RHS%E447
      RES%E157 = LHS%E157 + RHS%E157
      RES%E257 = LHS%E257 + RHS%E257
      RES%E357 = LHS%E357 + RHS%E357
      RES%E457 = LHS%E457 + RHS%E457
      RES%E557 = LHS%E557 + RHS%E557
      RES%E167 = LHS%E167 + RHS%E167
      RES%E267 = LHS%E267 + RHS%E267
      RES%E367 = LHS%E367 + RHS%E367
      RES%E467 = LHS%E467 + RHS%E467
      RES%E567 = LHS%E567 + RHS%E567
      RES%E667 = LHS%E667 + RHS%E667
      RES%E177 = LHS%E177 + RHS%E177
      RES%E277 = LHS%E277 + RHS%E277
      RES%E377 = LHS%E377 + RHS%E377
      RES%E477 = LHS%E477 + RHS%E477
      RES%E577 = LHS%E577 + RHS%E577
      RES%E677 = LHS%E677 + RHS%E677
      RES%E777 = LHS%E777 + RHS%E777

   END FUNCTION ONUMM7N3_ADD_OO_VS

   FUNCTION ONUMM7N3_ADD_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1)) 

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

      ! Order 3
      RES%E111 =  + RHS%E111
      RES%E112 =  + RHS%E112
      RES%E122 =  + RHS%E122
      RES%E222 =  + RHS%E222
      RES%E113 =  + RHS%E113
      RES%E123 =  + RHS%E123
      RES%E223 =  + RHS%E223
      RES%E133 =  + RHS%E133
      RES%E233 =  + RHS%E233
      RES%E333 =  + RHS%E333
      RES%E114 =  + RHS%E114
      RES%E124 =  + RHS%E124
      RES%E224 =  + RHS%E224
      RES%E134 =  + RHS%E134
      RES%E234 =  + RHS%E234
      RES%E334 =  + RHS%E334
      RES%E144 =  + RHS%E144
      RES%E244 =  + RHS%E244
      RES%E344 =  + RHS%E344
      RES%E444 =  + RHS%E444
      RES%E115 =  + RHS%E115
      RES%E125 =  + RHS%E125
      RES%E225 =  + RHS%E225
      RES%E135 =  + RHS%E135
      RES%E235 =  + RHS%E235
      RES%E335 =  + RHS%E335
      RES%E145 =  + RHS%E145
      RES%E245 =  + RHS%E245
      RES%E345 =  + RHS%E345
      RES%E445 =  + RHS%E445
      RES%E155 =  + RHS%E155
      RES%E255 =  + RHS%E255
      RES%E355 =  + RHS%E355
      RES%E455 =  + RHS%E455
      RES%E555 =  + RHS%E555
      RES%E116 =  + RHS%E116
      RES%E126 =  + RHS%E126
      RES%E226 =  + RHS%E226
      RES%E136 =  + RHS%E136
      RES%E236 =  + RHS%E236
      RES%E336 =  + RHS%E336
      RES%E146 =  + RHS%E146
      RES%E246 =  + RHS%E246
      RES%E346 =  + RHS%E346
      RES%E446 =  + RHS%E446
      RES%E156 =  + RHS%E156
      RES%E256 =  + RHS%E256
      RES%E356 =  + RHS%E356
      RES%E456 =  + RHS%E456
      RES%E556 =  + RHS%E556
      RES%E166 =  + RHS%E166
      RES%E266 =  + RHS%E266
      RES%E366 =  + RHS%E366
      RES%E466 =  + RHS%E466
      RES%E566 =  + RHS%E566
      RES%E666 =  + RHS%E666
      RES%E117 =  + RHS%E117
      RES%E127 =  + RHS%E127
      RES%E227 =  + RHS%E227
      RES%E137 =  + RHS%E137
      RES%E237 =  + RHS%E237
      RES%E337 =  + RHS%E337
      RES%E147 =  + RHS%E147
      RES%E247 =  + RHS%E247
      RES%E347 =  + RHS%E347
      RES%E447 =  + RHS%E447
      RES%E157 =  + RHS%E157
      RES%E257 =  + RHS%E257
      RES%E357 =  + RHS%E357
      RES%E457 =  + RHS%E457
      RES%E557 =  + RHS%E557
      RES%E167 =  + RHS%E167
      RES%E267 =  + RHS%E267
      RES%E367 =  + RHS%E367
      RES%E467 =  + RHS%E467
      RES%E567 =  + RHS%E567
      RES%E667 =  + RHS%E667
      RES%E177 =  + RHS%E177
      RES%E277 =  + RHS%E277
      RES%E377 =  + RHS%E377
      RES%E477 =  + RHS%E477
      RES%E577 =  + RHS%E577
      RES%E677 =  + RHS%E677
      RES%E777 =  + RHS%E777

   END FUNCTION ONUMM7N3_ADD_RO_VS

   FUNCTION ONUMM7N3_ADD_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E112 = LHS%E112
      RES%E122 = LHS%E122
      RES%E222 = LHS%E222
      RES%E113 = LHS%E113
      RES%E123 = LHS%E123
      RES%E223 = LHS%E223
      RES%E133 = LHS%E133
      RES%E233 = LHS%E233
      RES%E333 = LHS%E333
      RES%E114 = LHS%E114
      RES%E124 = LHS%E124
      RES%E224 = LHS%E224
      RES%E134 = LHS%E134
      RES%E234 = LHS%E234
      RES%E334 = LHS%E334
      RES%E144 = LHS%E144
      RES%E244 = LHS%E244
      RES%E344 = LHS%E344
      RES%E444 = LHS%E444
      RES%E115 = LHS%E115
      RES%E125 = LHS%E125
      RES%E225 = LHS%E225
      RES%E135 = LHS%E135
      RES%E235 = LHS%E235
      RES%E335 = LHS%E335
      RES%E145 = LHS%E145
      RES%E245 = LHS%E245
      RES%E345 = LHS%E345
      RES%E445 = LHS%E445
      RES%E155 = LHS%E155
      RES%E255 = LHS%E255
      RES%E355 = LHS%E355
      RES%E455 = LHS%E455
      RES%E555 = LHS%E555
      RES%E116 = LHS%E116
      RES%E126 = LHS%E126
      RES%E226 = LHS%E226
      RES%E136 = LHS%E136
      RES%E236 = LHS%E236
      RES%E336 = LHS%E336
      RES%E146 = LHS%E146
      RES%E246 = LHS%E246
      RES%E346 = LHS%E346
      RES%E446 = LHS%E446
      RES%E156 = LHS%E156
      RES%E256 = LHS%E256
      RES%E356 = LHS%E356
      RES%E456 = LHS%E456
      RES%E556 = LHS%E556
      RES%E166 = LHS%E166
      RES%E266 = LHS%E266
      RES%E366 = LHS%E366
      RES%E466 = LHS%E466
      RES%E566 = LHS%E566
      RES%E666 = LHS%E666
      RES%E117 = LHS%E117
      RES%E127 = LHS%E127
      RES%E227 = LHS%E227
      RES%E137 = LHS%E137
      RES%E237 = LHS%E237
      RES%E337 = LHS%E337
      RES%E147 = LHS%E147
      RES%E247 = LHS%E247
      RES%E347 = LHS%E347
      RES%E447 = LHS%E447
      RES%E157 = LHS%E157
      RES%E257 = LHS%E257
      RES%E357 = LHS%E357
      RES%E457 = LHS%E457
      RES%E557 = LHS%E557
      RES%E167 = LHS%E167
      RES%E267 = LHS%E267
      RES%E367 = LHS%E367
      RES%E467 = LHS%E467
      RES%E567 = LHS%E567
      RES%E667 = LHS%E667
      RES%E177 = LHS%E177
      RES%E277 = LHS%E277
      RES%E377 = LHS%E377
      RES%E477 = LHS%E477
      RES%E577 = LHS%E577
      RES%E677 = LHS%E677
      RES%E777 = LHS%E777

   END FUNCTION ONUMM7N3_ADD_OR_VS

   FUNCTION ONUMM7N3_SUB_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:)
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111
      RES%E112 = LHS%E112 - RHS%E112
      RES%E122 = LHS%E122 - RHS%E122
      RES%E222 = LHS%E222 - RHS%E222
      RES%E113 = LHS%E113 - RHS%E113
      RES%E123 = LHS%E123 - RHS%E123
      RES%E223 = LHS%E223 - RHS%E223
      RES%E133 = LHS%E133 - RHS%E133
      RES%E233 = LHS%E233 - RHS%E233
      RES%E333 = LHS%E333 - RHS%E333
      RES%E114 = LHS%E114 - RHS%E114
      RES%E124 = LHS%E124 - RHS%E124
      RES%E224 = LHS%E224 - RHS%E224
      RES%E134 = LHS%E134 - RHS%E134
      RES%E234 = LHS%E234 - RHS%E234
      RES%E334 = LHS%E334 - RHS%E334
      RES%E144 = LHS%E144 - RHS%E144
      RES%E244 = LHS%E244 - RHS%E244
      RES%E344 = LHS%E344 - RHS%E344
      RES%E444 = LHS%E444 - RHS%E444
      RES%E115 = LHS%E115 - RHS%E115
      RES%E125 = LHS%E125 - RHS%E125
      RES%E225 = LHS%E225 - RHS%E225
      RES%E135 = LHS%E135 - RHS%E135
      RES%E235 = LHS%E235 - RHS%E235
      RES%E335 = LHS%E335 - RHS%E335
      RES%E145 = LHS%E145 - RHS%E145
      RES%E245 = LHS%E245 - RHS%E245
      RES%E345 = LHS%E345 - RHS%E345
      RES%E445 = LHS%E445 - RHS%E445
      RES%E155 = LHS%E155 - RHS%E155
      RES%E255 = LHS%E255 - RHS%E255
      RES%E355 = LHS%E355 - RHS%E355
      RES%E455 = LHS%E455 - RHS%E455
      RES%E555 = LHS%E555 - RHS%E555
      RES%E116 = LHS%E116 - RHS%E116
      RES%E126 = LHS%E126 - RHS%E126
      RES%E226 = LHS%E226 - RHS%E226
      RES%E136 = LHS%E136 - RHS%E136
      RES%E236 = LHS%E236 - RHS%E236
      RES%E336 = LHS%E336 - RHS%E336
      RES%E146 = LHS%E146 - RHS%E146
      RES%E246 = LHS%E246 - RHS%E246
      RES%E346 = LHS%E346 - RHS%E346
      RES%E446 = LHS%E446 - RHS%E446
      RES%E156 = LHS%E156 - RHS%E156
      RES%E256 = LHS%E256 - RHS%E256
      RES%E356 = LHS%E356 - RHS%E356
      RES%E456 = LHS%E456 - RHS%E456
      RES%E556 = LHS%E556 - RHS%E556
      RES%E166 = LHS%E166 - RHS%E166
      RES%E266 = LHS%E266 - RHS%E266
      RES%E366 = LHS%E366 - RHS%E366
      RES%E466 = LHS%E466 - RHS%E466
      RES%E566 = LHS%E566 - RHS%E566
      RES%E666 = LHS%E666 - RHS%E666
      RES%E117 = LHS%E117 - RHS%E117
      RES%E127 = LHS%E127 - RHS%E127
      RES%E227 = LHS%E227 - RHS%E227
      RES%E137 = LHS%E137 - RHS%E137
      RES%E237 = LHS%E237 - RHS%E237
      RES%E337 = LHS%E337 - RHS%E337
      RES%E147 = LHS%E147 - RHS%E147
      RES%E247 = LHS%E247 - RHS%E247
      RES%E347 = LHS%E347 - RHS%E347
      RES%E447 = LHS%E447 - RHS%E447
      RES%E157 = LHS%E157 - RHS%E157
      RES%E257 = LHS%E257 - RHS%E257
      RES%E357 = LHS%E357 - RHS%E357
      RES%E457 = LHS%E457 - RHS%E457
      RES%E557 = LHS%E557 - RHS%E557
      RES%E167 = LHS%E167 - RHS%E167
      RES%E267 = LHS%E267 - RHS%E267
      RES%E367 = LHS%E367 - RHS%E367
      RES%E467 = LHS%E467 - RHS%E467
      RES%E567 = LHS%E567 - RHS%E567
      RES%E667 = LHS%E667 - RHS%E667
      RES%E177 = LHS%E177 - RHS%E177
      RES%E277 = LHS%E277 - RHS%E277
      RES%E377 = LHS%E377 - RHS%E377
      RES%E477 = LHS%E477 - RHS%E477
      RES%E577 = LHS%E577 - RHS%E577
      RES%E677 = LHS%E677 - RHS%E677
      RES%E777 = LHS%E777 - RHS%E777

   END FUNCTION ONUMM7N3_SUB_OO_VS

   FUNCTION ONUMM7N3_SUB_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1)) 

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

      ! Order 3
      RES%E111 =  - RHS%E111
      RES%E112 =  - RHS%E112
      RES%E122 =  - RHS%E122
      RES%E222 =  - RHS%E222
      RES%E113 =  - RHS%E113
      RES%E123 =  - RHS%E123
      RES%E223 =  - RHS%E223
      RES%E133 =  - RHS%E133
      RES%E233 =  - RHS%E233
      RES%E333 =  - RHS%E333
      RES%E114 =  - RHS%E114
      RES%E124 =  - RHS%E124
      RES%E224 =  - RHS%E224
      RES%E134 =  - RHS%E134
      RES%E234 =  - RHS%E234
      RES%E334 =  - RHS%E334
      RES%E144 =  - RHS%E144
      RES%E244 =  - RHS%E244
      RES%E344 =  - RHS%E344
      RES%E444 =  - RHS%E444
      RES%E115 =  - RHS%E115
      RES%E125 =  - RHS%E125
      RES%E225 =  - RHS%E225
      RES%E135 =  - RHS%E135
      RES%E235 =  - RHS%E235
      RES%E335 =  - RHS%E335
      RES%E145 =  - RHS%E145
      RES%E245 =  - RHS%E245
      RES%E345 =  - RHS%E345
      RES%E445 =  - RHS%E445
      RES%E155 =  - RHS%E155
      RES%E255 =  - RHS%E255
      RES%E355 =  - RHS%E355
      RES%E455 =  - RHS%E455
      RES%E555 =  - RHS%E555
      RES%E116 =  - RHS%E116
      RES%E126 =  - RHS%E126
      RES%E226 =  - RHS%E226
      RES%E136 =  - RHS%E136
      RES%E236 =  - RHS%E236
      RES%E336 =  - RHS%E336
      RES%E146 =  - RHS%E146
      RES%E246 =  - RHS%E246
      RES%E346 =  - RHS%E346
      RES%E446 =  - RHS%E446
      RES%E156 =  - RHS%E156
      RES%E256 =  - RHS%E256
      RES%E356 =  - RHS%E356
      RES%E456 =  - RHS%E456
      RES%E556 =  - RHS%E556
      RES%E166 =  - RHS%E166
      RES%E266 =  - RHS%E266
      RES%E366 =  - RHS%E366
      RES%E466 =  - RHS%E466
      RES%E566 =  - RHS%E566
      RES%E666 =  - RHS%E666
      RES%E117 =  - RHS%E117
      RES%E127 =  - RHS%E127
      RES%E227 =  - RHS%E227
      RES%E137 =  - RHS%E137
      RES%E237 =  - RHS%E237
      RES%E337 =  - RHS%E337
      RES%E147 =  - RHS%E147
      RES%E247 =  - RHS%E247
      RES%E347 =  - RHS%E347
      RES%E447 =  - RHS%E447
      RES%E157 =  - RHS%E157
      RES%E257 =  - RHS%E257
      RES%E357 =  - RHS%E357
      RES%E457 =  - RHS%E457
      RES%E557 =  - RHS%E557
      RES%E167 =  - RHS%E167
      RES%E267 =  - RHS%E267
      RES%E367 =  - RHS%E367
      RES%E467 =  - RHS%E467
      RES%E567 =  - RHS%E567
      RES%E667 =  - RHS%E667
      RES%E177 =  - RHS%E177
      RES%E277 =  - RHS%E277
      RES%E377 =  - RHS%E377
      RES%E477 =  - RHS%E477
      RES%E577 =  - RHS%E577
      RES%E677 =  - RHS%E677
      RES%E777 =  - RHS%E777

   END FUNCTION ONUMM7N3_SUB_RO_VS

   FUNCTION ONUMM7N3_SUB_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E112 = LHS%E112
      RES%E122 = LHS%E122
      RES%E222 = LHS%E222
      RES%E113 = LHS%E113
      RES%E123 = LHS%E123
      RES%E223 = LHS%E223
      RES%E133 = LHS%E133
      RES%E233 = LHS%E233
      RES%E333 = LHS%E333
      RES%E114 = LHS%E114
      RES%E124 = LHS%E124
      RES%E224 = LHS%E224
      RES%E134 = LHS%E134
      RES%E234 = LHS%E234
      RES%E334 = LHS%E334
      RES%E144 = LHS%E144
      RES%E244 = LHS%E244
      RES%E344 = LHS%E344
      RES%E444 = LHS%E444
      RES%E115 = LHS%E115
      RES%E125 = LHS%E125
      RES%E225 = LHS%E225
      RES%E135 = LHS%E135
      RES%E235 = LHS%E235
      RES%E335 = LHS%E335
      RES%E145 = LHS%E145
      RES%E245 = LHS%E245
      RES%E345 = LHS%E345
      RES%E445 = LHS%E445
      RES%E155 = LHS%E155
      RES%E255 = LHS%E255
      RES%E355 = LHS%E355
      RES%E455 = LHS%E455
      RES%E555 = LHS%E555
      RES%E116 = LHS%E116
      RES%E126 = LHS%E126
      RES%E226 = LHS%E226
      RES%E136 = LHS%E136
      RES%E236 = LHS%E236
      RES%E336 = LHS%E336
      RES%E146 = LHS%E146
      RES%E246 = LHS%E246
      RES%E346 = LHS%E346
      RES%E446 = LHS%E446
      RES%E156 = LHS%E156
      RES%E256 = LHS%E256
      RES%E356 = LHS%E356
      RES%E456 = LHS%E456
      RES%E556 = LHS%E556
      RES%E166 = LHS%E166
      RES%E266 = LHS%E266
      RES%E366 = LHS%E366
      RES%E466 = LHS%E466
      RES%E566 = LHS%E566
      RES%E666 = LHS%E666
      RES%E117 = LHS%E117
      RES%E127 = LHS%E127
      RES%E227 = LHS%E227
      RES%E137 = LHS%E137
      RES%E237 = LHS%E237
      RES%E337 = LHS%E337
      RES%E147 = LHS%E147
      RES%E247 = LHS%E247
      RES%E347 = LHS%E347
      RES%E447 = LHS%E447
      RES%E157 = LHS%E157
      RES%E257 = LHS%E257
      RES%E357 = LHS%E357
      RES%E457 = LHS%E457
      RES%E557 = LHS%E557
      RES%E167 = LHS%E167
      RES%E267 = LHS%E267
      RES%E367 = LHS%E367
      RES%E467 = LHS%E467
      RES%E567 = LHS%E567
      RES%E667 = LHS%E667
      RES%E177 = LHS%E177
      RES%E277 = LHS%E277
      RES%E377 = LHS%E377
      RES%E477 = LHS%E477
      RES%E577 = LHS%E577
      RES%E677 = LHS%E677
      RES%E777 = LHS%E777

   END FUNCTION ONUMM7N3_SUB_OR_VS

   FUNCTION ONUMM7N3_MUL_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:)
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 3
      RES%E111 = LHS%R*RHS%E111 + LHS%E111*RHS%R +  &
              LHS%E1*RHS%E11 + LHS%E11*RHS%E1
      RES%E112 = LHS%R*RHS%E112 + LHS%E112*RHS%R +  &
              LHS%E1*RHS%E12 + LHS%E12*RHS%E1 + LHS%E2*RHS%E11 + LHS%E11*RHS%E2
      RES%E122 = LHS%R*RHS%E122 + LHS%E122*RHS%R +  &
              LHS%E1*RHS%E22 + LHS%E22*RHS%E1 + LHS%E2*RHS%E12 + LHS%E12*RHS%E2
      RES%E222 = LHS%R*RHS%E222 + LHS%E222*RHS%R +  &
              LHS%E2*RHS%E22 + LHS%E22*RHS%E2
      RES%E113 = LHS%R*RHS%E113 + LHS%E113*RHS%R +  &
              LHS%E1*RHS%E13 + LHS%E13*RHS%E1 + LHS%E3*RHS%E11 + LHS%E11*RHS%E3
      RES%E123 = LHS%R*RHS%E123 + LHS%E123*RHS%R +  &
              LHS%E1*RHS%E23 + LHS%E23*RHS%E1 + LHS%E2*RHS%E13 +  &
              LHS%E13*RHS%E2 + LHS%E3*RHS%E12 + LHS%E12*RHS%E3
      RES%E223 = LHS%R*RHS%E223 + LHS%E223*RHS%R +  &
              LHS%E2*RHS%E23 + LHS%E23*RHS%E2 + LHS%E3*RHS%E22 + LHS%E22*RHS%E3
      RES%E133 = LHS%R*RHS%E133 + LHS%E133*RHS%R +  &
              LHS%E1*RHS%E33 + LHS%E33*RHS%E1 + LHS%E3*RHS%E13 + LHS%E13*RHS%E3
      RES%E233 = LHS%R*RHS%E233 + LHS%E233*RHS%R +  &
              LHS%E2*RHS%E33 + LHS%E33*RHS%E2 + LHS%E3*RHS%E23 + LHS%E23*RHS%E3
      RES%E333 = LHS%R*RHS%E333 + LHS%E333*RHS%R +  &
              LHS%E3*RHS%E33 + LHS%E33*RHS%E3
      RES%E114 = LHS%R*RHS%E114 + LHS%E114*RHS%R +  &
              LHS%E1*RHS%E14 + LHS%E14*RHS%E1 + LHS%E4*RHS%E11 + LHS%E11*RHS%E4
      RES%E124 = LHS%R*RHS%E124 + LHS%E124*RHS%R +  &
              LHS%E1*RHS%E24 + LHS%E24*RHS%E1 + LHS%E2*RHS%E14 +  &
              LHS%E14*RHS%E2 + LHS%E4*RHS%E12 + LHS%E12*RHS%E4
      RES%E224 = LHS%R*RHS%E224 + LHS%E224*RHS%R +  &
              LHS%E2*RHS%E24 + LHS%E24*RHS%E2 + LHS%E4*RHS%E22 + LHS%E22*RHS%E4
      RES%E134 = LHS%R*RHS%E134 + LHS%E134*RHS%R +  &
              LHS%E1*RHS%E34 + LHS%E34*RHS%E1 + LHS%E3*RHS%E14 +  &
              LHS%E14*RHS%E3 + LHS%E4*RHS%E13 + LHS%E13*RHS%E4
      RES%E234 = LHS%R*RHS%E234 + LHS%E234*RHS%R +  &
              LHS%E2*RHS%E34 + LHS%E34*RHS%E2 + LHS%E3*RHS%E24 +  &
              LHS%E24*RHS%E3 + LHS%E4*RHS%E23 + LHS%E23*RHS%E4
      RES%E334 = LHS%R*RHS%E334 + LHS%E334*RHS%R +  &
              LHS%E3*RHS%E34 + LHS%E34*RHS%E3 + LHS%E4*RHS%E33 + LHS%E33*RHS%E4
      RES%E144 = LHS%R*RHS%E144 + LHS%E144*RHS%R +  &
              LHS%E1*RHS%E44 + LHS%E44*RHS%E1 + LHS%E4*RHS%E14 + LHS%E14*RHS%E4
      RES%E244 = LHS%R*RHS%E244 + LHS%E244*RHS%R +  &
              LHS%E2*RHS%E44 + LHS%E44*RHS%E2 + LHS%E4*RHS%E24 + LHS%E24*RHS%E4
      RES%E344 = LHS%R*RHS%E344 + LHS%E344*RHS%R +  &
              LHS%E3*RHS%E44 + LHS%E44*RHS%E3 + LHS%E4*RHS%E34 + LHS%E34*RHS%E4
      RES%E444 = LHS%R*RHS%E444 + LHS%E444*RHS%R +  &
              LHS%E4*RHS%E44 + LHS%E44*RHS%E4
      RES%E115 = LHS%R*RHS%E115 + LHS%E115*RHS%R +  &
              LHS%E1*RHS%E15 + LHS%E15*RHS%E1 + LHS%E5*RHS%E11 + LHS%E11*RHS%E5
      RES%E125 = LHS%R*RHS%E125 + LHS%E125*RHS%R +  &
              LHS%E1*RHS%E25 + LHS%E25*RHS%E1 + LHS%E2*RHS%E15 +  &
              LHS%E15*RHS%E2 + LHS%E5*RHS%E12 + LHS%E12*RHS%E5
      RES%E225 = LHS%R*RHS%E225 + LHS%E225*RHS%R +  &
              LHS%E2*RHS%E25 + LHS%E25*RHS%E2 + LHS%E5*RHS%E22 + LHS%E22*RHS%E5
      RES%E135 = LHS%R*RHS%E135 + LHS%E135*RHS%R +  &
              LHS%E1*RHS%E35 + LHS%E35*RHS%E1 + LHS%E3*RHS%E15 +  &
              LHS%E15*RHS%E3 + LHS%E5*RHS%E13 + LHS%E13*RHS%E5
      RES%E235 = LHS%R*RHS%E235 + LHS%E235*RHS%R +  &
              LHS%E2*RHS%E35 + LHS%E35*RHS%E2 + LHS%E3*RHS%E25 +  &
              LHS%E25*RHS%E3 + LHS%E5*RHS%E23 + LHS%E23*RHS%E5
      RES%E335 = LHS%R*RHS%E335 + LHS%E335*RHS%R +  &
              LHS%E3*RHS%E35 + LHS%E35*RHS%E3 + LHS%E5*RHS%E33 + LHS%E33*RHS%E5
      RES%E145 = LHS%R*RHS%E145 + LHS%E145*RHS%R +  &
              LHS%E1*RHS%E45 + LHS%E45*RHS%E1 + LHS%E4*RHS%E15 +  &
              LHS%E15*RHS%E4 + LHS%E5*RHS%E14 + LHS%E14*RHS%E5
      RES%E245 = LHS%R*RHS%E245 + LHS%E245*RHS%R +  &
              LHS%E2*RHS%E45 + LHS%E45*RHS%E2 + LHS%E4*RHS%E25 +  &
              LHS%E25*RHS%E4 + LHS%E5*RHS%E24 + LHS%E24*RHS%E5
      RES%E345 = LHS%R*RHS%E345 + LHS%E345*RHS%R +  &
              LHS%E3*RHS%E45 + LHS%E45*RHS%E3 + LHS%E4*RHS%E35 +  &
              LHS%E35*RHS%E4 + LHS%E5*RHS%E34 + LHS%E34*RHS%E5
      RES%E445 = LHS%R*RHS%E445 + LHS%E445*RHS%R +  &
              LHS%E4*RHS%E45 + LHS%E45*RHS%E4 + LHS%E5*RHS%E44 + LHS%E44*RHS%E5
      RES%E155 = LHS%R*RHS%E155 + LHS%E155*RHS%R +  &
              LHS%E1*RHS%E55 + LHS%E55*RHS%E1 + LHS%E5*RHS%E15 + LHS%E15*RHS%E5
      RES%E255 = LHS%R*RHS%E255 + LHS%E255*RHS%R +  &
              LHS%E2*RHS%E55 + LHS%E55*RHS%E2 + LHS%E5*RHS%E25 + LHS%E25*RHS%E5
      RES%E355 = LHS%R*RHS%E355 + LHS%E355*RHS%R +  &
              LHS%E3*RHS%E55 + LHS%E55*RHS%E3 + LHS%E5*RHS%E35 + LHS%E35*RHS%E5
      RES%E455 = LHS%R*RHS%E455 + LHS%E455*RHS%R +  &
              LHS%E4*RHS%E55 + LHS%E55*RHS%E4 + LHS%E5*RHS%E45 + LHS%E45*RHS%E5
      RES%E555 = LHS%R*RHS%E555 + LHS%E555*RHS%R +  &
              LHS%E5*RHS%E55 + LHS%E55*RHS%E5
      RES%E116 = LHS%R*RHS%E116 + LHS%E116*RHS%R +  &
              LHS%E1*RHS%E16 + LHS%E16*RHS%E1 + LHS%E6*RHS%E11 + LHS%E11*RHS%E6
      RES%E126 = LHS%R*RHS%E126 + LHS%E126*RHS%R +  &
              LHS%E1*RHS%E26 + LHS%E26*RHS%E1 + LHS%E2*RHS%E16 +  &
              LHS%E16*RHS%E2 + LHS%E6*RHS%E12 + LHS%E12*RHS%E6
      RES%E226 = LHS%R*RHS%E226 + LHS%E226*RHS%R +  &
              LHS%E2*RHS%E26 + LHS%E26*RHS%E2 + LHS%E6*RHS%E22 + LHS%E22*RHS%E6
      RES%E136 = LHS%R*RHS%E136 + LHS%E136*RHS%R +  &
              LHS%E1*RHS%E36 + LHS%E36*RHS%E1 + LHS%E3*RHS%E16 +  &
              LHS%E16*RHS%E3 + LHS%E6*RHS%E13 + LHS%E13*RHS%E6
      RES%E236 = LHS%R*RHS%E236 + LHS%E236*RHS%R +  &
              LHS%E2*RHS%E36 + LHS%E36*RHS%E2 + LHS%E3*RHS%E26 +  &
              LHS%E26*RHS%E3 + LHS%E6*RHS%E23 + LHS%E23*RHS%E6
      RES%E336 = LHS%R*RHS%E336 + LHS%E336*RHS%R +  &
              LHS%E3*RHS%E36 + LHS%E36*RHS%E3 + LHS%E6*RHS%E33 + LHS%E33*RHS%E6
      RES%E146 = LHS%R*RHS%E146 + LHS%E146*RHS%R +  &
              LHS%E1*RHS%E46 + LHS%E46*RHS%E1 + LHS%E4*RHS%E16 +  &
              LHS%E16*RHS%E4 + LHS%E6*RHS%E14 + LHS%E14*RHS%E6
      RES%E246 = LHS%R*RHS%E246 + LHS%E246*RHS%R +  &
              LHS%E2*RHS%E46 + LHS%E46*RHS%E2 + LHS%E4*RHS%E26 +  &
              LHS%E26*RHS%E4 + LHS%E6*RHS%E24 + LHS%E24*RHS%E6
      RES%E346 = LHS%R*RHS%E346 + LHS%E346*RHS%R +  &
              LHS%E3*RHS%E46 + LHS%E46*RHS%E3 + LHS%E4*RHS%E36 +  &
              LHS%E36*RHS%E4 + LHS%E6*RHS%E34 + LHS%E34*RHS%E6
      RES%E446 = LHS%R*RHS%E446 + LHS%E446*RHS%R +  &
              LHS%E4*RHS%E46 + LHS%E46*RHS%E4 + LHS%E6*RHS%E44 + LHS%E44*RHS%E6
      RES%E156 = LHS%R*RHS%E156 + LHS%E156*RHS%R +  &
              LHS%E1*RHS%E56 + LHS%E56*RHS%E1 + LHS%E5*RHS%E16 +  &
              LHS%E16*RHS%E5 + LHS%E6*RHS%E15 + LHS%E15*RHS%E6
      RES%E256 = LHS%R*RHS%E256 + LHS%E256*RHS%R +  &
              LHS%E2*RHS%E56 + LHS%E56*RHS%E2 + LHS%E5*RHS%E26 +  &
              LHS%E26*RHS%E5 + LHS%E6*RHS%E25 + LHS%E25*RHS%E6
      RES%E356 = LHS%R*RHS%E356 + LHS%E356*RHS%R +  &
              LHS%E3*RHS%E56 + LHS%E56*RHS%E3 + LHS%E5*RHS%E36 +  &
              LHS%E36*RHS%E5 + LHS%E6*RHS%E35 + LHS%E35*RHS%E6
      RES%E456 = LHS%R*RHS%E456 + LHS%E456*RHS%R +  &
              LHS%E4*RHS%E56 + LHS%E56*RHS%E4 + LHS%E5*RHS%E46 +  &
              LHS%E46*RHS%E5 + LHS%E6*RHS%E45 + LHS%E45*RHS%E6
      RES%E556 = LHS%R*RHS%E556 + LHS%E556*RHS%R +  &
              LHS%E5*RHS%E56 + LHS%E56*RHS%E5 + LHS%E6*RHS%E55 + LHS%E55*RHS%E6
      RES%E166 = LHS%R*RHS%E166 + LHS%E166*RHS%R +  &
              LHS%E1*RHS%E66 + LHS%E66*RHS%E1 + LHS%E6*RHS%E16 + LHS%E16*RHS%E6
      RES%E266 = LHS%R*RHS%E266 + LHS%E266*RHS%R +  &
              LHS%E2*RHS%E66 + LHS%E66*RHS%E2 + LHS%E6*RHS%E26 + LHS%E26*RHS%E6
      RES%E366 = LHS%R*RHS%E366 + LHS%E366*RHS%R +  &
              LHS%E3*RHS%E66 + LHS%E66*RHS%E3 + LHS%E6*RHS%E36 + LHS%E36*RHS%E6
      RES%E466 = LHS%R*RHS%E466 + LHS%E466*RHS%R +  &
              LHS%E4*RHS%E66 + LHS%E66*RHS%E4 + LHS%E6*RHS%E46 + LHS%E46*RHS%E6
      RES%E566 = LHS%R*RHS%E566 + LHS%E566*RHS%R +  &
              LHS%E5*RHS%E66 + LHS%E66*RHS%E5 + LHS%E6*RHS%E56 + LHS%E56*RHS%E6
      RES%E666 = LHS%R*RHS%E666 + LHS%E666*RHS%R +  &
              LHS%E6*RHS%E66 + LHS%E66*RHS%E6
      RES%E117 = LHS%R*RHS%E117 + LHS%E117*RHS%R +  &
              LHS%E1*RHS%E17 + LHS%E17*RHS%E1 + LHS%E7*RHS%E11 + LHS%E11*RHS%E7
      RES%E127 = LHS%R*RHS%E127 + LHS%E127*RHS%R +  &
              LHS%E1*RHS%E27 + LHS%E27*RHS%E1 + LHS%E2*RHS%E17 +  &
              LHS%E17*RHS%E2 + LHS%E7*RHS%E12 + LHS%E12*RHS%E7
      RES%E227 = LHS%R*RHS%E227 + LHS%E227*RHS%R +  &
              LHS%E2*RHS%E27 + LHS%E27*RHS%E2 + LHS%E7*RHS%E22 + LHS%E22*RHS%E7
      RES%E137 = LHS%R*RHS%E137 + LHS%E137*RHS%R +  &
              LHS%E1*RHS%E37 + LHS%E37*RHS%E1 + LHS%E3*RHS%E17 +  &
              LHS%E17*RHS%E3 + LHS%E7*RHS%E13 + LHS%E13*RHS%E7
      RES%E237 = LHS%R*RHS%E237 + LHS%E237*RHS%R +  &
              LHS%E2*RHS%E37 + LHS%E37*RHS%E2 + LHS%E3*RHS%E27 +  &
              LHS%E27*RHS%E3 + LHS%E7*RHS%E23 + LHS%E23*RHS%E7
      RES%E337 = LHS%R*RHS%E337 + LHS%E337*RHS%R +  &
              LHS%E3*RHS%E37 + LHS%E37*RHS%E3 + LHS%E7*RHS%E33 + LHS%E33*RHS%E7
      RES%E147 = LHS%R*RHS%E147 + LHS%E147*RHS%R +  &
              LHS%E1*RHS%E47 + LHS%E47*RHS%E1 + LHS%E4*RHS%E17 +  &
              LHS%E17*RHS%E4 + LHS%E7*RHS%E14 + LHS%E14*RHS%E7
      RES%E247 = LHS%R*RHS%E247 + LHS%E247*RHS%R +  &
              LHS%E2*RHS%E47 + LHS%E47*RHS%E2 + LHS%E4*RHS%E27 +  &
              LHS%E27*RHS%E4 + LHS%E7*RHS%E24 + LHS%E24*RHS%E7
      RES%E347 = LHS%R*RHS%E347 + LHS%E347*RHS%R +  &
              LHS%E3*RHS%E47 + LHS%E47*RHS%E3 + LHS%E4*RHS%E37 +  &
              LHS%E37*RHS%E4 + LHS%E7*RHS%E34 + LHS%E34*RHS%E7
      RES%E447 = LHS%R*RHS%E447 + LHS%E447*RHS%R +  &
              LHS%E4*RHS%E47 + LHS%E47*RHS%E4 + LHS%E7*RHS%E44 + LHS%E44*RHS%E7
      RES%E157 = LHS%R*RHS%E157 + LHS%E157*RHS%R +  &
              LHS%E1*RHS%E57 + LHS%E57*RHS%E1 + LHS%E5*RHS%E17 +  &
              LHS%E17*RHS%E5 + LHS%E7*RHS%E15 + LHS%E15*RHS%E7
      RES%E257 = LHS%R*RHS%E257 + LHS%E257*RHS%R +  &
              LHS%E2*RHS%E57 + LHS%E57*RHS%E2 + LHS%E5*RHS%E27 +  &
              LHS%E27*RHS%E5 + LHS%E7*RHS%E25 + LHS%E25*RHS%E7
      RES%E357 = LHS%R*RHS%E357 + LHS%E357*RHS%R +  &
              LHS%E3*RHS%E57 + LHS%E57*RHS%E3 + LHS%E5*RHS%E37 +  &
              LHS%E37*RHS%E5 + LHS%E7*RHS%E35 + LHS%E35*RHS%E7
      RES%E457 = LHS%R*RHS%E457 + LHS%E457*RHS%R +  &
              LHS%E4*RHS%E57 + LHS%E57*RHS%E4 + LHS%E5*RHS%E47 +  &
              LHS%E47*RHS%E5 + LHS%E7*RHS%E45 + LHS%E45*RHS%E7
      RES%E557 = LHS%R*RHS%E557 + LHS%E557*RHS%R +  &
              LHS%E5*RHS%E57 + LHS%E57*RHS%E5 + LHS%E7*RHS%E55 + LHS%E55*RHS%E7
      RES%E167 = LHS%R*RHS%E167 + LHS%E167*RHS%R +  &
              LHS%E1*RHS%E67 + LHS%E67*RHS%E1 + LHS%E6*RHS%E17 +  &
              LHS%E17*RHS%E6 + LHS%E7*RHS%E16 + LHS%E16*RHS%E7
      RES%E267 = LHS%R*RHS%E267 + LHS%E267*RHS%R +  &
              LHS%E2*RHS%E67 + LHS%E67*RHS%E2 + LHS%E6*RHS%E27 +  &
              LHS%E27*RHS%E6 + LHS%E7*RHS%E26 + LHS%E26*RHS%E7
      RES%E367 = LHS%R*RHS%E367 + LHS%E367*RHS%R +  &
              LHS%E3*RHS%E67 + LHS%E67*RHS%E3 + LHS%E6*RHS%E37 +  &
              LHS%E37*RHS%E6 + LHS%E7*RHS%E36 + LHS%E36*RHS%E7
      RES%E467 = LHS%R*RHS%E467 + LHS%E467*RHS%R +  &
              LHS%E4*RHS%E67 + LHS%E67*RHS%E4 + LHS%E6*RHS%E47 +  &
              LHS%E47*RHS%E6 + LHS%E7*RHS%E46 + LHS%E46*RHS%E7
      RES%E567 = LHS%R*RHS%E567 + LHS%E567*RHS%R +  &
              LHS%E5*RHS%E67 + LHS%E67*RHS%E5 + LHS%E6*RHS%E57 +  &
              LHS%E57*RHS%E6 + LHS%E7*RHS%E56 + LHS%E56*RHS%E7
      RES%E667 = LHS%R*RHS%E667 + LHS%E667*RHS%R +  &
              LHS%E6*RHS%E67 + LHS%E67*RHS%E6 + LHS%E7*RHS%E66 + LHS%E66*RHS%E7
      RES%E177 = LHS%R*RHS%E177 + LHS%E177*RHS%R +  &
              LHS%E1*RHS%E77 + LHS%E77*RHS%E1 + LHS%E7*RHS%E17 + LHS%E17*RHS%E7
      RES%E277 = LHS%R*RHS%E277 + LHS%E277*RHS%R +  &
              LHS%E2*RHS%E77 + LHS%E77*RHS%E2 + LHS%E7*RHS%E27 + LHS%E27*RHS%E7
      RES%E377 = LHS%R*RHS%E377 + LHS%E377*RHS%R +  &
              LHS%E3*RHS%E77 + LHS%E77*RHS%E3 + LHS%E7*RHS%E37 + LHS%E37*RHS%E7
      RES%E477 = LHS%R*RHS%E477 + LHS%E477*RHS%R +  &
              LHS%E4*RHS%E77 + LHS%E77*RHS%E4 + LHS%E7*RHS%E47 + LHS%E47*RHS%E7
      RES%E577 = LHS%R*RHS%E577 + LHS%E577*RHS%R +  &
              LHS%E5*RHS%E77 + LHS%E77*RHS%E5 + LHS%E7*RHS%E57 + LHS%E57*RHS%E7
      RES%E677 = LHS%R*RHS%E677 + LHS%E677*RHS%R +  &
              LHS%E6*RHS%E77 + LHS%E77*RHS%E6 + LHS%E7*RHS%E67 + LHS%E67*RHS%E7
      RES%E777 = LHS%R*RHS%E777 + LHS%E777*RHS%R +  &
              LHS%E7*RHS%E77 + LHS%E77*RHS%E7
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

   END FUNCTION ONUMM7N3_MUL_OO_VS

   FUNCTION ONUMM7N3_MUL_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1)) 

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

      ! Order 3
      RES%E111 = LHS*RHS%E111
      RES%E112 = LHS*RHS%E112
      RES%E122 = LHS*RHS%E122
      RES%E222 = LHS*RHS%E222
      RES%E113 = LHS*RHS%E113
      RES%E123 = LHS*RHS%E123
      RES%E223 = LHS*RHS%E223
      RES%E133 = LHS*RHS%E133
      RES%E233 = LHS*RHS%E233
      RES%E333 = LHS*RHS%E333
      RES%E114 = LHS*RHS%E114
      RES%E124 = LHS*RHS%E124
      RES%E224 = LHS*RHS%E224
      RES%E134 = LHS*RHS%E134
      RES%E234 = LHS*RHS%E234
      RES%E334 = LHS*RHS%E334
      RES%E144 = LHS*RHS%E144
      RES%E244 = LHS*RHS%E244
      RES%E344 = LHS*RHS%E344
      RES%E444 = LHS*RHS%E444
      RES%E115 = LHS*RHS%E115
      RES%E125 = LHS*RHS%E125
      RES%E225 = LHS*RHS%E225
      RES%E135 = LHS*RHS%E135
      RES%E235 = LHS*RHS%E235
      RES%E335 = LHS*RHS%E335
      RES%E145 = LHS*RHS%E145
      RES%E245 = LHS*RHS%E245
      RES%E345 = LHS*RHS%E345
      RES%E445 = LHS*RHS%E445
      RES%E155 = LHS*RHS%E155
      RES%E255 = LHS*RHS%E255
      RES%E355 = LHS*RHS%E355
      RES%E455 = LHS*RHS%E455
      RES%E555 = LHS*RHS%E555
      RES%E116 = LHS*RHS%E116
      RES%E126 = LHS*RHS%E126
      RES%E226 = LHS*RHS%E226
      RES%E136 = LHS*RHS%E136
      RES%E236 = LHS*RHS%E236
      RES%E336 = LHS*RHS%E336
      RES%E146 = LHS*RHS%E146
      RES%E246 = LHS*RHS%E246
      RES%E346 = LHS*RHS%E346
      RES%E446 = LHS*RHS%E446
      RES%E156 = LHS*RHS%E156
      RES%E256 = LHS*RHS%E256
      RES%E356 = LHS*RHS%E356
      RES%E456 = LHS*RHS%E456
      RES%E556 = LHS*RHS%E556
      RES%E166 = LHS*RHS%E166
      RES%E266 = LHS*RHS%E266
      RES%E366 = LHS*RHS%E366
      RES%E466 = LHS*RHS%E466
      RES%E566 = LHS*RHS%E566
      RES%E666 = LHS*RHS%E666
      RES%E117 = LHS*RHS%E117
      RES%E127 = LHS*RHS%E127
      RES%E227 = LHS*RHS%E227
      RES%E137 = LHS*RHS%E137
      RES%E237 = LHS*RHS%E237
      RES%E337 = LHS*RHS%E337
      RES%E147 = LHS*RHS%E147
      RES%E247 = LHS*RHS%E247
      RES%E347 = LHS*RHS%E347
      RES%E447 = LHS*RHS%E447
      RES%E157 = LHS*RHS%E157
      RES%E257 = LHS*RHS%E257
      RES%E357 = LHS*RHS%E357
      RES%E457 = LHS*RHS%E457
      RES%E557 = LHS*RHS%E557
      RES%E167 = LHS*RHS%E167
      RES%E267 = LHS*RHS%E267
      RES%E367 = LHS*RHS%E367
      RES%E467 = LHS*RHS%E467
      RES%E567 = LHS*RHS%E567
      RES%E667 = LHS*RHS%E667
      RES%E177 = LHS*RHS%E177
      RES%E277 = LHS*RHS%E277
      RES%E377 = LHS*RHS%E377
      RES%E477 = LHS*RHS%E477
      RES%E577 = LHS*RHS%E577
      RES%E677 = LHS*RHS%E677
      RES%E777 = LHS*RHS%E777

   END FUNCTION ONUMM7N3_MUL_RO_VS

   FUNCTION ONUMM7N3_MUL_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111*RHS
      RES%E112 = LHS%E112*RHS
      RES%E122 = LHS%E122*RHS
      RES%E222 = LHS%E222*RHS
      RES%E113 = LHS%E113*RHS
      RES%E123 = LHS%E123*RHS
      RES%E223 = LHS%E223*RHS
      RES%E133 = LHS%E133*RHS
      RES%E233 = LHS%E233*RHS
      RES%E333 = LHS%E333*RHS
      RES%E114 = LHS%E114*RHS
      RES%E124 = LHS%E124*RHS
      RES%E224 = LHS%E224*RHS
      RES%E134 = LHS%E134*RHS
      RES%E234 = LHS%E234*RHS
      RES%E334 = LHS%E334*RHS
      RES%E144 = LHS%E144*RHS
      RES%E244 = LHS%E244*RHS
      RES%E344 = LHS%E344*RHS
      RES%E444 = LHS%E444*RHS
      RES%E115 = LHS%E115*RHS
      RES%E125 = LHS%E125*RHS
      RES%E225 = LHS%E225*RHS
      RES%E135 = LHS%E135*RHS
      RES%E235 = LHS%E235*RHS
      RES%E335 = LHS%E335*RHS
      RES%E145 = LHS%E145*RHS
      RES%E245 = LHS%E245*RHS
      RES%E345 = LHS%E345*RHS
      RES%E445 = LHS%E445*RHS
      RES%E155 = LHS%E155*RHS
      RES%E255 = LHS%E255*RHS
      RES%E355 = LHS%E355*RHS
      RES%E455 = LHS%E455*RHS
      RES%E555 = LHS%E555*RHS
      RES%E116 = LHS%E116*RHS
      RES%E126 = LHS%E126*RHS
      RES%E226 = LHS%E226*RHS
      RES%E136 = LHS%E136*RHS
      RES%E236 = LHS%E236*RHS
      RES%E336 = LHS%E336*RHS
      RES%E146 = LHS%E146*RHS
      RES%E246 = LHS%E246*RHS
      RES%E346 = LHS%E346*RHS
      RES%E446 = LHS%E446*RHS
      RES%E156 = LHS%E156*RHS
      RES%E256 = LHS%E256*RHS
      RES%E356 = LHS%E356*RHS
      RES%E456 = LHS%E456*RHS
      RES%E556 = LHS%E556*RHS
      RES%E166 = LHS%E166*RHS
      RES%E266 = LHS%E266*RHS
      RES%E366 = LHS%E366*RHS
      RES%E466 = LHS%E466*RHS
      RES%E566 = LHS%E566*RHS
      RES%E666 = LHS%E666*RHS
      RES%E117 = LHS%E117*RHS
      RES%E127 = LHS%E127*RHS
      RES%E227 = LHS%E227*RHS
      RES%E137 = LHS%E137*RHS
      RES%E237 = LHS%E237*RHS
      RES%E337 = LHS%E337*RHS
      RES%E147 = LHS%E147*RHS
      RES%E247 = LHS%E247*RHS
      RES%E347 = LHS%E347*RHS
      RES%E447 = LHS%E447*RHS
      RES%E157 = LHS%E157*RHS
      RES%E257 = LHS%E257*RHS
      RES%E357 = LHS%E357*RHS
      RES%E457 = LHS%E457*RHS
      RES%E557 = LHS%E557*RHS
      RES%E167 = LHS%E167*RHS
      RES%E267 = LHS%E267*RHS
      RES%E367 = LHS%E367*RHS
      RES%E467 = LHS%E467*RHS
      RES%E567 = LHS%E567*RHS
      RES%E667 = LHS%E667*RHS
      RES%E177 = LHS%E177*RHS
      RES%E277 = LHS%E277*RHS
      RES%E377 = LHS%E377*RHS
      RES%E477 = LHS%E477*RHS
      RES%E577 = LHS%E577*RHS
      RES%E677 = LHS%E677*RHS
      RES%E777 = LHS%E777*RHS

   END FUNCTION ONUMM7N3_MUL_OR_VS

   FUNCTION ONUMM7N3_ADD_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111
      RES%E112 = LHS%E112 + RHS%E112
      RES%E122 = LHS%E122 + RHS%E122
      RES%E222 = LHS%E222 + RHS%E222
      RES%E113 = LHS%E113 + RHS%E113
      RES%E123 = LHS%E123 + RHS%E123
      RES%E223 = LHS%E223 + RHS%E223
      RES%E133 = LHS%E133 + RHS%E133
      RES%E233 = LHS%E233 + RHS%E233
      RES%E333 = LHS%E333 + RHS%E333
      RES%E114 = LHS%E114 + RHS%E114
      RES%E124 = LHS%E124 + RHS%E124
      RES%E224 = LHS%E224 + RHS%E224
      RES%E134 = LHS%E134 + RHS%E134
      RES%E234 = LHS%E234 + RHS%E234
      RES%E334 = LHS%E334 + RHS%E334
      RES%E144 = LHS%E144 + RHS%E144
      RES%E244 = LHS%E244 + RHS%E244
      RES%E344 = LHS%E344 + RHS%E344
      RES%E444 = LHS%E444 + RHS%E444
      RES%E115 = LHS%E115 + RHS%E115
      RES%E125 = LHS%E125 + RHS%E125
      RES%E225 = LHS%E225 + RHS%E225
      RES%E135 = LHS%E135 + RHS%E135
      RES%E235 = LHS%E235 + RHS%E235
      RES%E335 = LHS%E335 + RHS%E335
      RES%E145 = LHS%E145 + RHS%E145
      RES%E245 = LHS%E245 + RHS%E245
      RES%E345 = LHS%E345 + RHS%E345
      RES%E445 = LHS%E445 + RHS%E445
      RES%E155 = LHS%E155 + RHS%E155
      RES%E255 = LHS%E255 + RHS%E255
      RES%E355 = LHS%E355 + RHS%E355
      RES%E455 = LHS%E455 + RHS%E455
      RES%E555 = LHS%E555 + RHS%E555
      RES%E116 = LHS%E116 + RHS%E116
      RES%E126 = LHS%E126 + RHS%E126
      RES%E226 = LHS%E226 + RHS%E226
      RES%E136 = LHS%E136 + RHS%E136
      RES%E236 = LHS%E236 + RHS%E236
      RES%E336 = LHS%E336 + RHS%E336
      RES%E146 = LHS%E146 + RHS%E146
      RES%E246 = LHS%E246 + RHS%E246
      RES%E346 = LHS%E346 + RHS%E346
      RES%E446 = LHS%E446 + RHS%E446
      RES%E156 = LHS%E156 + RHS%E156
      RES%E256 = LHS%E256 + RHS%E256
      RES%E356 = LHS%E356 + RHS%E356
      RES%E456 = LHS%E456 + RHS%E456
      RES%E556 = LHS%E556 + RHS%E556
      RES%E166 = LHS%E166 + RHS%E166
      RES%E266 = LHS%E266 + RHS%E266
      RES%E366 = LHS%E366 + RHS%E366
      RES%E466 = LHS%E466 + RHS%E466
      RES%E566 = LHS%E566 + RHS%E566
      RES%E666 = LHS%E666 + RHS%E666
      RES%E117 = LHS%E117 + RHS%E117
      RES%E127 = LHS%E127 + RHS%E127
      RES%E227 = LHS%E227 + RHS%E227
      RES%E137 = LHS%E137 + RHS%E137
      RES%E237 = LHS%E237 + RHS%E237
      RES%E337 = LHS%E337 + RHS%E337
      RES%E147 = LHS%E147 + RHS%E147
      RES%E247 = LHS%E247 + RHS%E247
      RES%E347 = LHS%E347 + RHS%E347
      RES%E447 = LHS%E447 + RHS%E447
      RES%E157 = LHS%E157 + RHS%E157
      RES%E257 = LHS%E257 + RHS%E257
      RES%E357 = LHS%E357 + RHS%E357
      RES%E457 = LHS%E457 + RHS%E457
      RES%E557 = LHS%E557 + RHS%E557
      RES%E167 = LHS%E167 + RHS%E167
      RES%E267 = LHS%E267 + RHS%E267
      RES%E367 = LHS%E367 + RHS%E367
      RES%E467 = LHS%E467 + RHS%E467
      RES%E567 = LHS%E567 + RHS%E567
      RES%E667 = LHS%E667 + RHS%E667
      RES%E177 = LHS%E177 + RHS%E177
      RES%E277 = LHS%E277 + RHS%E277
      RES%E377 = LHS%E377 + RHS%E377
      RES%E477 = LHS%E477 + RHS%E477
      RES%E577 = LHS%E577 + RHS%E577
      RES%E677 = LHS%E677 + RHS%E677
      RES%E777 = LHS%E777 + RHS%E777

   END FUNCTION ONUMM7N3_ADD_OO_MS

   FUNCTION ONUMM7N3_ADD_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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

      ! Order 3
      RES%E111 =  + RHS%E111
      RES%E112 =  + RHS%E112
      RES%E122 =  + RHS%E122
      RES%E222 =  + RHS%E222
      RES%E113 =  + RHS%E113
      RES%E123 =  + RHS%E123
      RES%E223 =  + RHS%E223
      RES%E133 =  + RHS%E133
      RES%E233 =  + RHS%E233
      RES%E333 =  + RHS%E333
      RES%E114 =  + RHS%E114
      RES%E124 =  + RHS%E124
      RES%E224 =  + RHS%E224
      RES%E134 =  + RHS%E134
      RES%E234 =  + RHS%E234
      RES%E334 =  + RHS%E334
      RES%E144 =  + RHS%E144
      RES%E244 =  + RHS%E244
      RES%E344 =  + RHS%E344
      RES%E444 =  + RHS%E444
      RES%E115 =  + RHS%E115
      RES%E125 =  + RHS%E125
      RES%E225 =  + RHS%E225
      RES%E135 =  + RHS%E135
      RES%E235 =  + RHS%E235
      RES%E335 =  + RHS%E335
      RES%E145 =  + RHS%E145
      RES%E245 =  + RHS%E245
      RES%E345 =  + RHS%E345
      RES%E445 =  + RHS%E445
      RES%E155 =  + RHS%E155
      RES%E255 =  + RHS%E255
      RES%E355 =  + RHS%E355
      RES%E455 =  + RHS%E455
      RES%E555 =  + RHS%E555
      RES%E116 =  + RHS%E116
      RES%E126 =  + RHS%E126
      RES%E226 =  + RHS%E226
      RES%E136 =  + RHS%E136
      RES%E236 =  + RHS%E236
      RES%E336 =  + RHS%E336
      RES%E146 =  + RHS%E146
      RES%E246 =  + RHS%E246
      RES%E346 =  + RHS%E346
      RES%E446 =  + RHS%E446
      RES%E156 =  + RHS%E156
      RES%E256 =  + RHS%E256
      RES%E356 =  + RHS%E356
      RES%E456 =  + RHS%E456
      RES%E556 =  + RHS%E556
      RES%E166 =  + RHS%E166
      RES%E266 =  + RHS%E266
      RES%E366 =  + RHS%E366
      RES%E466 =  + RHS%E466
      RES%E566 =  + RHS%E566
      RES%E666 =  + RHS%E666
      RES%E117 =  + RHS%E117
      RES%E127 =  + RHS%E127
      RES%E227 =  + RHS%E227
      RES%E137 =  + RHS%E137
      RES%E237 =  + RHS%E237
      RES%E337 =  + RHS%E337
      RES%E147 =  + RHS%E147
      RES%E247 =  + RHS%E247
      RES%E347 =  + RHS%E347
      RES%E447 =  + RHS%E447
      RES%E157 =  + RHS%E157
      RES%E257 =  + RHS%E257
      RES%E357 =  + RHS%E357
      RES%E457 =  + RHS%E457
      RES%E557 =  + RHS%E557
      RES%E167 =  + RHS%E167
      RES%E267 =  + RHS%E267
      RES%E367 =  + RHS%E367
      RES%E467 =  + RHS%E467
      RES%E567 =  + RHS%E567
      RES%E667 =  + RHS%E667
      RES%E177 =  + RHS%E177
      RES%E277 =  + RHS%E277
      RES%E377 =  + RHS%E377
      RES%E477 =  + RHS%E477
      RES%E577 =  + RHS%E577
      RES%E677 =  + RHS%E677
      RES%E777 =  + RHS%E777

   END FUNCTION ONUMM7N3_ADD_RO_MS

   FUNCTION ONUMM7N3_ADD_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E112 = LHS%E112
      RES%E122 = LHS%E122
      RES%E222 = LHS%E222
      RES%E113 = LHS%E113
      RES%E123 = LHS%E123
      RES%E223 = LHS%E223
      RES%E133 = LHS%E133
      RES%E233 = LHS%E233
      RES%E333 = LHS%E333
      RES%E114 = LHS%E114
      RES%E124 = LHS%E124
      RES%E224 = LHS%E224
      RES%E134 = LHS%E134
      RES%E234 = LHS%E234
      RES%E334 = LHS%E334
      RES%E144 = LHS%E144
      RES%E244 = LHS%E244
      RES%E344 = LHS%E344
      RES%E444 = LHS%E444
      RES%E115 = LHS%E115
      RES%E125 = LHS%E125
      RES%E225 = LHS%E225
      RES%E135 = LHS%E135
      RES%E235 = LHS%E235
      RES%E335 = LHS%E335
      RES%E145 = LHS%E145
      RES%E245 = LHS%E245
      RES%E345 = LHS%E345
      RES%E445 = LHS%E445
      RES%E155 = LHS%E155
      RES%E255 = LHS%E255
      RES%E355 = LHS%E355
      RES%E455 = LHS%E455
      RES%E555 = LHS%E555
      RES%E116 = LHS%E116
      RES%E126 = LHS%E126
      RES%E226 = LHS%E226
      RES%E136 = LHS%E136
      RES%E236 = LHS%E236
      RES%E336 = LHS%E336
      RES%E146 = LHS%E146
      RES%E246 = LHS%E246
      RES%E346 = LHS%E346
      RES%E446 = LHS%E446
      RES%E156 = LHS%E156
      RES%E256 = LHS%E256
      RES%E356 = LHS%E356
      RES%E456 = LHS%E456
      RES%E556 = LHS%E556
      RES%E166 = LHS%E166
      RES%E266 = LHS%E266
      RES%E366 = LHS%E366
      RES%E466 = LHS%E466
      RES%E566 = LHS%E566
      RES%E666 = LHS%E666
      RES%E117 = LHS%E117
      RES%E127 = LHS%E127
      RES%E227 = LHS%E227
      RES%E137 = LHS%E137
      RES%E237 = LHS%E237
      RES%E337 = LHS%E337
      RES%E147 = LHS%E147
      RES%E247 = LHS%E247
      RES%E347 = LHS%E347
      RES%E447 = LHS%E447
      RES%E157 = LHS%E157
      RES%E257 = LHS%E257
      RES%E357 = LHS%E357
      RES%E457 = LHS%E457
      RES%E557 = LHS%E557
      RES%E167 = LHS%E167
      RES%E267 = LHS%E267
      RES%E367 = LHS%E367
      RES%E467 = LHS%E467
      RES%E567 = LHS%E567
      RES%E667 = LHS%E667
      RES%E177 = LHS%E177
      RES%E277 = LHS%E277
      RES%E377 = LHS%E377
      RES%E477 = LHS%E477
      RES%E577 = LHS%E577
      RES%E677 = LHS%E677
      RES%E777 = LHS%E777

   END FUNCTION ONUMM7N3_ADD_OR_MS

   FUNCTION ONUMM7N3_SUB_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111
      RES%E112 = LHS%E112 - RHS%E112
      RES%E122 = LHS%E122 - RHS%E122
      RES%E222 = LHS%E222 - RHS%E222
      RES%E113 = LHS%E113 - RHS%E113
      RES%E123 = LHS%E123 - RHS%E123
      RES%E223 = LHS%E223 - RHS%E223
      RES%E133 = LHS%E133 - RHS%E133
      RES%E233 = LHS%E233 - RHS%E233
      RES%E333 = LHS%E333 - RHS%E333
      RES%E114 = LHS%E114 - RHS%E114
      RES%E124 = LHS%E124 - RHS%E124
      RES%E224 = LHS%E224 - RHS%E224
      RES%E134 = LHS%E134 - RHS%E134
      RES%E234 = LHS%E234 - RHS%E234
      RES%E334 = LHS%E334 - RHS%E334
      RES%E144 = LHS%E144 - RHS%E144
      RES%E244 = LHS%E244 - RHS%E244
      RES%E344 = LHS%E344 - RHS%E344
      RES%E444 = LHS%E444 - RHS%E444
      RES%E115 = LHS%E115 - RHS%E115
      RES%E125 = LHS%E125 - RHS%E125
      RES%E225 = LHS%E225 - RHS%E225
      RES%E135 = LHS%E135 - RHS%E135
      RES%E235 = LHS%E235 - RHS%E235
      RES%E335 = LHS%E335 - RHS%E335
      RES%E145 = LHS%E145 - RHS%E145
      RES%E245 = LHS%E245 - RHS%E245
      RES%E345 = LHS%E345 - RHS%E345
      RES%E445 = LHS%E445 - RHS%E445
      RES%E155 = LHS%E155 - RHS%E155
      RES%E255 = LHS%E255 - RHS%E255
      RES%E355 = LHS%E355 - RHS%E355
      RES%E455 = LHS%E455 - RHS%E455
      RES%E555 = LHS%E555 - RHS%E555
      RES%E116 = LHS%E116 - RHS%E116
      RES%E126 = LHS%E126 - RHS%E126
      RES%E226 = LHS%E226 - RHS%E226
      RES%E136 = LHS%E136 - RHS%E136
      RES%E236 = LHS%E236 - RHS%E236
      RES%E336 = LHS%E336 - RHS%E336
      RES%E146 = LHS%E146 - RHS%E146
      RES%E246 = LHS%E246 - RHS%E246
      RES%E346 = LHS%E346 - RHS%E346
      RES%E446 = LHS%E446 - RHS%E446
      RES%E156 = LHS%E156 - RHS%E156
      RES%E256 = LHS%E256 - RHS%E256
      RES%E356 = LHS%E356 - RHS%E356
      RES%E456 = LHS%E456 - RHS%E456
      RES%E556 = LHS%E556 - RHS%E556
      RES%E166 = LHS%E166 - RHS%E166
      RES%E266 = LHS%E266 - RHS%E266
      RES%E366 = LHS%E366 - RHS%E366
      RES%E466 = LHS%E466 - RHS%E466
      RES%E566 = LHS%E566 - RHS%E566
      RES%E666 = LHS%E666 - RHS%E666
      RES%E117 = LHS%E117 - RHS%E117
      RES%E127 = LHS%E127 - RHS%E127
      RES%E227 = LHS%E227 - RHS%E227
      RES%E137 = LHS%E137 - RHS%E137
      RES%E237 = LHS%E237 - RHS%E237
      RES%E337 = LHS%E337 - RHS%E337
      RES%E147 = LHS%E147 - RHS%E147
      RES%E247 = LHS%E247 - RHS%E247
      RES%E347 = LHS%E347 - RHS%E347
      RES%E447 = LHS%E447 - RHS%E447
      RES%E157 = LHS%E157 - RHS%E157
      RES%E257 = LHS%E257 - RHS%E257
      RES%E357 = LHS%E357 - RHS%E357
      RES%E457 = LHS%E457 - RHS%E457
      RES%E557 = LHS%E557 - RHS%E557
      RES%E167 = LHS%E167 - RHS%E167
      RES%E267 = LHS%E267 - RHS%E267
      RES%E367 = LHS%E367 - RHS%E367
      RES%E467 = LHS%E467 - RHS%E467
      RES%E567 = LHS%E567 - RHS%E567
      RES%E667 = LHS%E667 - RHS%E667
      RES%E177 = LHS%E177 - RHS%E177
      RES%E277 = LHS%E277 - RHS%E277
      RES%E377 = LHS%E377 - RHS%E377
      RES%E477 = LHS%E477 - RHS%E477
      RES%E577 = LHS%E577 - RHS%E577
      RES%E677 = LHS%E677 - RHS%E677
      RES%E777 = LHS%E777 - RHS%E777

   END FUNCTION ONUMM7N3_SUB_OO_MS

   FUNCTION ONUMM7N3_SUB_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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

      ! Order 3
      RES%E111 =  - RHS%E111
      RES%E112 =  - RHS%E112
      RES%E122 =  - RHS%E122
      RES%E222 =  - RHS%E222
      RES%E113 =  - RHS%E113
      RES%E123 =  - RHS%E123
      RES%E223 =  - RHS%E223
      RES%E133 =  - RHS%E133
      RES%E233 =  - RHS%E233
      RES%E333 =  - RHS%E333
      RES%E114 =  - RHS%E114
      RES%E124 =  - RHS%E124
      RES%E224 =  - RHS%E224
      RES%E134 =  - RHS%E134
      RES%E234 =  - RHS%E234
      RES%E334 =  - RHS%E334
      RES%E144 =  - RHS%E144
      RES%E244 =  - RHS%E244
      RES%E344 =  - RHS%E344
      RES%E444 =  - RHS%E444
      RES%E115 =  - RHS%E115
      RES%E125 =  - RHS%E125
      RES%E225 =  - RHS%E225
      RES%E135 =  - RHS%E135
      RES%E235 =  - RHS%E235
      RES%E335 =  - RHS%E335
      RES%E145 =  - RHS%E145
      RES%E245 =  - RHS%E245
      RES%E345 =  - RHS%E345
      RES%E445 =  - RHS%E445
      RES%E155 =  - RHS%E155
      RES%E255 =  - RHS%E255
      RES%E355 =  - RHS%E355
      RES%E455 =  - RHS%E455
      RES%E555 =  - RHS%E555
      RES%E116 =  - RHS%E116
      RES%E126 =  - RHS%E126
      RES%E226 =  - RHS%E226
      RES%E136 =  - RHS%E136
      RES%E236 =  - RHS%E236
      RES%E336 =  - RHS%E336
      RES%E146 =  - RHS%E146
      RES%E246 =  - RHS%E246
      RES%E346 =  - RHS%E346
      RES%E446 =  - RHS%E446
      RES%E156 =  - RHS%E156
      RES%E256 =  - RHS%E256
      RES%E356 =  - RHS%E356
      RES%E456 =  - RHS%E456
      RES%E556 =  - RHS%E556
      RES%E166 =  - RHS%E166
      RES%E266 =  - RHS%E266
      RES%E366 =  - RHS%E366
      RES%E466 =  - RHS%E466
      RES%E566 =  - RHS%E566
      RES%E666 =  - RHS%E666
      RES%E117 =  - RHS%E117
      RES%E127 =  - RHS%E127
      RES%E227 =  - RHS%E227
      RES%E137 =  - RHS%E137
      RES%E237 =  - RHS%E237
      RES%E337 =  - RHS%E337
      RES%E147 =  - RHS%E147
      RES%E247 =  - RHS%E247
      RES%E347 =  - RHS%E347
      RES%E447 =  - RHS%E447
      RES%E157 =  - RHS%E157
      RES%E257 =  - RHS%E257
      RES%E357 =  - RHS%E357
      RES%E457 =  - RHS%E457
      RES%E557 =  - RHS%E557
      RES%E167 =  - RHS%E167
      RES%E267 =  - RHS%E267
      RES%E367 =  - RHS%E367
      RES%E467 =  - RHS%E467
      RES%E567 =  - RHS%E567
      RES%E667 =  - RHS%E667
      RES%E177 =  - RHS%E177
      RES%E277 =  - RHS%E277
      RES%E377 =  - RHS%E377
      RES%E477 =  - RHS%E477
      RES%E577 =  - RHS%E577
      RES%E677 =  - RHS%E677
      RES%E777 =  - RHS%E777

   END FUNCTION ONUMM7N3_SUB_RO_MS

   FUNCTION ONUMM7N3_SUB_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E112 = LHS%E112
      RES%E122 = LHS%E122
      RES%E222 = LHS%E222
      RES%E113 = LHS%E113
      RES%E123 = LHS%E123
      RES%E223 = LHS%E223
      RES%E133 = LHS%E133
      RES%E233 = LHS%E233
      RES%E333 = LHS%E333
      RES%E114 = LHS%E114
      RES%E124 = LHS%E124
      RES%E224 = LHS%E224
      RES%E134 = LHS%E134
      RES%E234 = LHS%E234
      RES%E334 = LHS%E334
      RES%E144 = LHS%E144
      RES%E244 = LHS%E244
      RES%E344 = LHS%E344
      RES%E444 = LHS%E444
      RES%E115 = LHS%E115
      RES%E125 = LHS%E125
      RES%E225 = LHS%E225
      RES%E135 = LHS%E135
      RES%E235 = LHS%E235
      RES%E335 = LHS%E335
      RES%E145 = LHS%E145
      RES%E245 = LHS%E245
      RES%E345 = LHS%E345
      RES%E445 = LHS%E445
      RES%E155 = LHS%E155
      RES%E255 = LHS%E255
      RES%E355 = LHS%E355
      RES%E455 = LHS%E455
      RES%E555 = LHS%E555
      RES%E116 = LHS%E116
      RES%E126 = LHS%E126
      RES%E226 = LHS%E226
      RES%E136 = LHS%E136
      RES%E236 = LHS%E236
      RES%E336 = LHS%E336
      RES%E146 = LHS%E146
      RES%E246 = LHS%E246
      RES%E346 = LHS%E346
      RES%E446 = LHS%E446
      RES%E156 = LHS%E156
      RES%E256 = LHS%E256
      RES%E356 = LHS%E356
      RES%E456 = LHS%E456
      RES%E556 = LHS%E556
      RES%E166 = LHS%E166
      RES%E266 = LHS%E266
      RES%E366 = LHS%E366
      RES%E466 = LHS%E466
      RES%E566 = LHS%E566
      RES%E666 = LHS%E666
      RES%E117 = LHS%E117
      RES%E127 = LHS%E127
      RES%E227 = LHS%E227
      RES%E137 = LHS%E137
      RES%E237 = LHS%E237
      RES%E337 = LHS%E337
      RES%E147 = LHS%E147
      RES%E247 = LHS%E247
      RES%E347 = LHS%E347
      RES%E447 = LHS%E447
      RES%E157 = LHS%E157
      RES%E257 = LHS%E257
      RES%E357 = LHS%E357
      RES%E457 = LHS%E457
      RES%E557 = LHS%E557
      RES%E167 = LHS%E167
      RES%E267 = LHS%E267
      RES%E367 = LHS%E367
      RES%E467 = LHS%E467
      RES%E567 = LHS%E567
      RES%E667 = LHS%E667
      RES%E177 = LHS%E177
      RES%E277 = LHS%E277
      RES%E377 = LHS%E377
      RES%E477 = LHS%E477
      RES%E577 = LHS%E577
      RES%E677 = LHS%E677
      RES%E777 = LHS%E777

   END FUNCTION ONUMM7N3_SUB_OR_MS

   FUNCTION ONUMM7N3_MUL_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 3
      RES%E111 = LHS%R*RHS%E111 + LHS%E111*RHS%R +  &
              LHS%E1*RHS%E11 + LHS%E11*RHS%E1
      RES%E112 = LHS%R*RHS%E112 + LHS%E112*RHS%R +  &
              LHS%E1*RHS%E12 + LHS%E12*RHS%E1 + LHS%E2*RHS%E11 + LHS%E11*RHS%E2
      RES%E122 = LHS%R*RHS%E122 + LHS%E122*RHS%R +  &
              LHS%E1*RHS%E22 + LHS%E22*RHS%E1 + LHS%E2*RHS%E12 + LHS%E12*RHS%E2
      RES%E222 = LHS%R*RHS%E222 + LHS%E222*RHS%R +  &
              LHS%E2*RHS%E22 + LHS%E22*RHS%E2
      RES%E113 = LHS%R*RHS%E113 + LHS%E113*RHS%R +  &
              LHS%E1*RHS%E13 + LHS%E13*RHS%E1 + LHS%E3*RHS%E11 + LHS%E11*RHS%E3
      RES%E123 = LHS%R*RHS%E123 + LHS%E123*RHS%R +  &
              LHS%E1*RHS%E23 + LHS%E23*RHS%E1 + LHS%E2*RHS%E13 +  &
              LHS%E13*RHS%E2 + LHS%E3*RHS%E12 + LHS%E12*RHS%E3
      RES%E223 = LHS%R*RHS%E223 + LHS%E223*RHS%R +  &
              LHS%E2*RHS%E23 + LHS%E23*RHS%E2 + LHS%E3*RHS%E22 + LHS%E22*RHS%E3
      RES%E133 = LHS%R*RHS%E133 + LHS%E133*RHS%R +  &
              LHS%E1*RHS%E33 + LHS%E33*RHS%E1 + LHS%E3*RHS%E13 + LHS%E13*RHS%E3
      RES%E233 = LHS%R*RHS%E233 + LHS%E233*RHS%R +  &
              LHS%E2*RHS%E33 + LHS%E33*RHS%E2 + LHS%E3*RHS%E23 + LHS%E23*RHS%E3
      RES%E333 = LHS%R*RHS%E333 + LHS%E333*RHS%R +  &
              LHS%E3*RHS%E33 + LHS%E33*RHS%E3
      RES%E114 = LHS%R*RHS%E114 + LHS%E114*RHS%R +  &
              LHS%E1*RHS%E14 + LHS%E14*RHS%E1 + LHS%E4*RHS%E11 + LHS%E11*RHS%E4
      RES%E124 = LHS%R*RHS%E124 + LHS%E124*RHS%R +  &
              LHS%E1*RHS%E24 + LHS%E24*RHS%E1 + LHS%E2*RHS%E14 +  &
              LHS%E14*RHS%E2 + LHS%E4*RHS%E12 + LHS%E12*RHS%E4
      RES%E224 = LHS%R*RHS%E224 + LHS%E224*RHS%R +  &
              LHS%E2*RHS%E24 + LHS%E24*RHS%E2 + LHS%E4*RHS%E22 + LHS%E22*RHS%E4
      RES%E134 = LHS%R*RHS%E134 + LHS%E134*RHS%R +  &
              LHS%E1*RHS%E34 + LHS%E34*RHS%E1 + LHS%E3*RHS%E14 +  &
              LHS%E14*RHS%E3 + LHS%E4*RHS%E13 + LHS%E13*RHS%E4
      RES%E234 = LHS%R*RHS%E234 + LHS%E234*RHS%R +  &
              LHS%E2*RHS%E34 + LHS%E34*RHS%E2 + LHS%E3*RHS%E24 +  &
              LHS%E24*RHS%E3 + LHS%E4*RHS%E23 + LHS%E23*RHS%E4
      RES%E334 = LHS%R*RHS%E334 + LHS%E334*RHS%R +  &
              LHS%E3*RHS%E34 + LHS%E34*RHS%E3 + LHS%E4*RHS%E33 + LHS%E33*RHS%E4
      RES%E144 = LHS%R*RHS%E144 + LHS%E144*RHS%R +  &
              LHS%E1*RHS%E44 + LHS%E44*RHS%E1 + LHS%E4*RHS%E14 + LHS%E14*RHS%E4
      RES%E244 = LHS%R*RHS%E244 + LHS%E244*RHS%R +  &
              LHS%E2*RHS%E44 + LHS%E44*RHS%E2 + LHS%E4*RHS%E24 + LHS%E24*RHS%E4
      RES%E344 = LHS%R*RHS%E344 + LHS%E344*RHS%R +  &
              LHS%E3*RHS%E44 + LHS%E44*RHS%E3 + LHS%E4*RHS%E34 + LHS%E34*RHS%E4
      RES%E444 = LHS%R*RHS%E444 + LHS%E444*RHS%R +  &
              LHS%E4*RHS%E44 + LHS%E44*RHS%E4
      RES%E115 = LHS%R*RHS%E115 + LHS%E115*RHS%R +  &
              LHS%E1*RHS%E15 + LHS%E15*RHS%E1 + LHS%E5*RHS%E11 + LHS%E11*RHS%E5
      RES%E125 = LHS%R*RHS%E125 + LHS%E125*RHS%R +  &
              LHS%E1*RHS%E25 + LHS%E25*RHS%E1 + LHS%E2*RHS%E15 +  &
              LHS%E15*RHS%E2 + LHS%E5*RHS%E12 + LHS%E12*RHS%E5
      RES%E225 = LHS%R*RHS%E225 + LHS%E225*RHS%R +  &
              LHS%E2*RHS%E25 + LHS%E25*RHS%E2 + LHS%E5*RHS%E22 + LHS%E22*RHS%E5
      RES%E135 = LHS%R*RHS%E135 + LHS%E135*RHS%R +  &
              LHS%E1*RHS%E35 + LHS%E35*RHS%E1 + LHS%E3*RHS%E15 +  &
              LHS%E15*RHS%E3 + LHS%E5*RHS%E13 + LHS%E13*RHS%E5
      RES%E235 = LHS%R*RHS%E235 + LHS%E235*RHS%R +  &
              LHS%E2*RHS%E35 + LHS%E35*RHS%E2 + LHS%E3*RHS%E25 +  &
              LHS%E25*RHS%E3 + LHS%E5*RHS%E23 + LHS%E23*RHS%E5
      RES%E335 = LHS%R*RHS%E335 + LHS%E335*RHS%R +  &
              LHS%E3*RHS%E35 + LHS%E35*RHS%E3 + LHS%E5*RHS%E33 + LHS%E33*RHS%E5
      RES%E145 = LHS%R*RHS%E145 + LHS%E145*RHS%R +  &
              LHS%E1*RHS%E45 + LHS%E45*RHS%E1 + LHS%E4*RHS%E15 +  &
              LHS%E15*RHS%E4 + LHS%E5*RHS%E14 + LHS%E14*RHS%E5
      RES%E245 = LHS%R*RHS%E245 + LHS%E245*RHS%R +  &
              LHS%E2*RHS%E45 + LHS%E45*RHS%E2 + LHS%E4*RHS%E25 +  &
              LHS%E25*RHS%E4 + LHS%E5*RHS%E24 + LHS%E24*RHS%E5
      RES%E345 = LHS%R*RHS%E345 + LHS%E345*RHS%R +  &
              LHS%E3*RHS%E45 + LHS%E45*RHS%E3 + LHS%E4*RHS%E35 +  &
              LHS%E35*RHS%E4 + LHS%E5*RHS%E34 + LHS%E34*RHS%E5
      RES%E445 = LHS%R*RHS%E445 + LHS%E445*RHS%R +  &
              LHS%E4*RHS%E45 + LHS%E45*RHS%E4 + LHS%E5*RHS%E44 + LHS%E44*RHS%E5
      RES%E155 = LHS%R*RHS%E155 + LHS%E155*RHS%R +  &
              LHS%E1*RHS%E55 + LHS%E55*RHS%E1 + LHS%E5*RHS%E15 + LHS%E15*RHS%E5
      RES%E255 = LHS%R*RHS%E255 + LHS%E255*RHS%R +  &
              LHS%E2*RHS%E55 + LHS%E55*RHS%E2 + LHS%E5*RHS%E25 + LHS%E25*RHS%E5
      RES%E355 = LHS%R*RHS%E355 + LHS%E355*RHS%R +  &
              LHS%E3*RHS%E55 + LHS%E55*RHS%E3 + LHS%E5*RHS%E35 + LHS%E35*RHS%E5
      RES%E455 = LHS%R*RHS%E455 + LHS%E455*RHS%R +  &
              LHS%E4*RHS%E55 + LHS%E55*RHS%E4 + LHS%E5*RHS%E45 + LHS%E45*RHS%E5
      RES%E555 = LHS%R*RHS%E555 + LHS%E555*RHS%R +  &
              LHS%E5*RHS%E55 + LHS%E55*RHS%E5
      RES%E116 = LHS%R*RHS%E116 + LHS%E116*RHS%R +  &
              LHS%E1*RHS%E16 + LHS%E16*RHS%E1 + LHS%E6*RHS%E11 + LHS%E11*RHS%E6
      RES%E126 = LHS%R*RHS%E126 + LHS%E126*RHS%R +  &
              LHS%E1*RHS%E26 + LHS%E26*RHS%E1 + LHS%E2*RHS%E16 +  &
              LHS%E16*RHS%E2 + LHS%E6*RHS%E12 + LHS%E12*RHS%E6
      RES%E226 = LHS%R*RHS%E226 + LHS%E226*RHS%R +  &
              LHS%E2*RHS%E26 + LHS%E26*RHS%E2 + LHS%E6*RHS%E22 + LHS%E22*RHS%E6
      RES%E136 = LHS%R*RHS%E136 + LHS%E136*RHS%R +  &
              LHS%E1*RHS%E36 + LHS%E36*RHS%E1 + LHS%E3*RHS%E16 +  &
              LHS%E16*RHS%E3 + LHS%E6*RHS%E13 + LHS%E13*RHS%E6
      RES%E236 = LHS%R*RHS%E236 + LHS%E236*RHS%R +  &
              LHS%E2*RHS%E36 + LHS%E36*RHS%E2 + LHS%E3*RHS%E26 +  &
              LHS%E26*RHS%E3 + LHS%E6*RHS%E23 + LHS%E23*RHS%E6
      RES%E336 = LHS%R*RHS%E336 + LHS%E336*RHS%R +  &
              LHS%E3*RHS%E36 + LHS%E36*RHS%E3 + LHS%E6*RHS%E33 + LHS%E33*RHS%E6
      RES%E146 = LHS%R*RHS%E146 + LHS%E146*RHS%R +  &
              LHS%E1*RHS%E46 + LHS%E46*RHS%E1 + LHS%E4*RHS%E16 +  &
              LHS%E16*RHS%E4 + LHS%E6*RHS%E14 + LHS%E14*RHS%E6
      RES%E246 = LHS%R*RHS%E246 + LHS%E246*RHS%R +  &
              LHS%E2*RHS%E46 + LHS%E46*RHS%E2 + LHS%E4*RHS%E26 +  &
              LHS%E26*RHS%E4 + LHS%E6*RHS%E24 + LHS%E24*RHS%E6
      RES%E346 = LHS%R*RHS%E346 + LHS%E346*RHS%R +  &
              LHS%E3*RHS%E46 + LHS%E46*RHS%E3 + LHS%E4*RHS%E36 +  &
              LHS%E36*RHS%E4 + LHS%E6*RHS%E34 + LHS%E34*RHS%E6
      RES%E446 = LHS%R*RHS%E446 + LHS%E446*RHS%R +  &
              LHS%E4*RHS%E46 + LHS%E46*RHS%E4 + LHS%E6*RHS%E44 + LHS%E44*RHS%E6
      RES%E156 = LHS%R*RHS%E156 + LHS%E156*RHS%R +  &
              LHS%E1*RHS%E56 + LHS%E56*RHS%E1 + LHS%E5*RHS%E16 +  &
              LHS%E16*RHS%E5 + LHS%E6*RHS%E15 + LHS%E15*RHS%E6
      RES%E256 = LHS%R*RHS%E256 + LHS%E256*RHS%R +  &
              LHS%E2*RHS%E56 + LHS%E56*RHS%E2 + LHS%E5*RHS%E26 +  &
              LHS%E26*RHS%E5 + LHS%E6*RHS%E25 + LHS%E25*RHS%E6
      RES%E356 = LHS%R*RHS%E356 + LHS%E356*RHS%R +  &
              LHS%E3*RHS%E56 + LHS%E56*RHS%E3 + LHS%E5*RHS%E36 +  &
              LHS%E36*RHS%E5 + LHS%E6*RHS%E35 + LHS%E35*RHS%E6
      RES%E456 = LHS%R*RHS%E456 + LHS%E456*RHS%R +  &
              LHS%E4*RHS%E56 + LHS%E56*RHS%E4 + LHS%E5*RHS%E46 +  &
              LHS%E46*RHS%E5 + LHS%E6*RHS%E45 + LHS%E45*RHS%E6
      RES%E556 = LHS%R*RHS%E556 + LHS%E556*RHS%R +  &
              LHS%E5*RHS%E56 + LHS%E56*RHS%E5 + LHS%E6*RHS%E55 + LHS%E55*RHS%E6
      RES%E166 = LHS%R*RHS%E166 + LHS%E166*RHS%R +  &
              LHS%E1*RHS%E66 + LHS%E66*RHS%E1 + LHS%E6*RHS%E16 + LHS%E16*RHS%E6
      RES%E266 = LHS%R*RHS%E266 + LHS%E266*RHS%R +  &
              LHS%E2*RHS%E66 + LHS%E66*RHS%E2 + LHS%E6*RHS%E26 + LHS%E26*RHS%E6
      RES%E366 = LHS%R*RHS%E366 + LHS%E366*RHS%R +  &
              LHS%E3*RHS%E66 + LHS%E66*RHS%E3 + LHS%E6*RHS%E36 + LHS%E36*RHS%E6
      RES%E466 = LHS%R*RHS%E466 + LHS%E466*RHS%R +  &
              LHS%E4*RHS%E66 + LHS%E66*RHS%E4 + LHS%E6*RHS%E46 + LHS%E46*RHS%E6
      RES%E566 = LHS%R*RHS%E566 + LHS%E566*RHS%R +  &
              LHS%E5*RHS%E66 + LHS%E66*RHS%E5 + LHS%E6*RHS%E56 + LHS%E56*RHS%E6
      RES%E666 = LHS%R*RHS%E666 + LHS%E666*RHS%R +  &
              LHS%E6*RHS%E66 + LHS%E66*RHS%E6
      RES%E117 = LHS%R*RHS%E117 + LHS%E117*RHS%R +  &
              LHS%E1*RHS%E17 + LHS%E17*RHS%E1 + LHS%E7*RHS%E11 + LHS%E11*RHS%E7
      RES%E127 = LHS%R*RHS%E127 + LHS%E127*RHS%R +  &
              LHS%E1*RHS%E27 + LHS%E27*RHS%E1 + LHS%E2*RHS%E17 +  &
              LHS%E17*RHS%E2 + LHS%E7*RHS%E12 + LHS%E12*RHS%E7
      RES%E227 = LHS%R*RHS%E227 + LHS%E227*RHS%R +  &
              LHS%E2*RHS%E27 + LHS%E27*RHS%E2 + LHS%E7*RHS%E22 + LHS%E22*RHS%E7
      RES%E137 = LHS%R*RHS%E137 + LHS%E137*RHS%R +  &
              LHS%E1*RHS%E37 + LHS%E37*RHS%E1 + LHS%E3*RHS%E17 +  &
              LHS%E17*RHS%E3 + LHS%E7*RHS%E13 + LHS%E13*RHS%E7
      RES%E237 = LHS%R*RHS%E237 + LHS%E237*RHS%R +  &
              LHS%E2*RHS%E37 + LHS%E37*RHS%E2 + LHS%E3*RHS%E27 +  &
              LHS%E27*RHS%E3 + LHS%E7*RHS%E23 + LHS%E23*RHS%E7
      RES%E337 = LHS%R*RHS%E337 + LHS%E337*RHS%R +  &
              LHS%E3*RHS%E37 + LHS%E37*RHS%E3 + LHS%E7*RHS%E33 + LHS%E33*RHS%E7
      RES%E147 = LHS%R*RHS%E147 + LHS%E147*RHS%R +  &
              LHS%E1*RHS%E47 + LHS%E47*RHS%E1 + LHS%E4*RHS%E17 +  &
              LHS%E17*RHS%E4 + LHS%E7*RHS%E14 + LHS%E14*RHS%E7
      RES%E247 = LHS%R*RHS%E247 + LHS%E247*RHS%R +  &
              LHS%E2*RHS%E47 + LHS%E47*RHS%E2 + LHS%E4*RHS%E27 +  &
              LHS%E27*RHS%E4 + LHS%E7*RHS%E24 + LHS%E24*RHS%E7
      RES%E347 = LHS%R*RHS%E347 + LHS%E347*RHS%R +  &
              LHS%E3*RHS%E47 + LHS%E47*RHS%E3 + LHS%E4*RHS%E37 +  &
              LHS%E37*RHS%E4 + LHS%E7*RHS%E34 + LHS%E34*RHS%E7
      RES%E447 = LHS%R*RHS%E447 + LHS%E447*RHS%R +  &
              LHS%E4*RHS%E47 + LHS%E47*RHS%E4 + LHS%E7*RHS%E44 + LHS%E44*RHS%E7
      RES%E157 = LHS%R*RHS%E157 + LHS%E157*RHS%R +  &
              LHS%E1*RHS%E57 + LHS%E57*RHS%E1 + LHS%E5*RHS%E17 +  &
              LHS%E17*RHS%E5 + LHS%E7*RHS%E15 + LHS%E15*RHS%E7
      RES%E257 = LHS%R*RHS%E257 + LHS%E257*RHS%R +  &
              LHS%E2*RHS%E57 + LHS%E57*RHS%E2 + LHS%E5*RHS%E27 +  &
              LHS%E27*RHS%E5 + LHS%E7*RHS%E25 + LHS%E25*RHS%E7
      RES%E357 = LHS%R*RHS%E357 + LHS%E357*RHS%R +  &
              LHS%E3*RHS%E57 + LHS%E57*RHS%E3 + LHS%E5*RHS%E37 +  &
              LHS%E37*RHS%E5 + LHS%E7*RHS%E35 + LHS%E35*RHS%E7
      RES%E457 = LHS%R*RHS%E457 + LHS%E457*RHS%R +  &
              LHS%E4*RHS%E57 + LHS%E57*RHS%E4 + LHS%E5*RHS%E47 +  &
              LHS%E47*RHS%E5 + LHS%E7*RHS%E45 + LHS%E45*RHS%E7
      RES%E557 = LHS%R*RHS%E557 + LHS%E557*RHS%R +  &
              LHS%E5*RHS%E57 + LHS%E57*RHS%E5 + LHS%E7*RHS%E55 + LHS%E55*RHS%E7
      RES%E167 = LHS%R*RHS%E167 + LHS%E167*RHS%R +  &
              LHS%E1*RHS%E67 + LHS%E67*RHS%E1 + LHS%E6*RHS%E17 +  &
              LHS%E17*RHS%E6 + LHS%E7*RHS%E16 + LHS%E16*RHS%E7
      RES%E267 = LHS%R*RHS%E267 + LHS%E267*RHS%R +  &
              LHS%E2*RHS%E67 + LHS%E67*RHS%E2 + LHS%E6*RHS%E27 +  &
              LHS%E27*RHS%E6 + LHS%E7*RHS%E26 + LHS%E26*RHS%E7
      RES%E367 = LHS%R*RHS%E367 + LHS%E367*RHS%R +  &
              LHS%E3*RHS%E67 + LHS%E67*RHS%E3 + LHS%E6*RHS%E37 +  &
              LHS%E37*RHS%E6 + LHS%E7*RHS%E36 + LHS%E36*RHS%E7
      RES%E467 = LHS%R*RHS%E467 + LHS%E467*RHS%R +  &
              LHS%E4*RHS%E67 + LHS%E67*RHS%E4 + LHS%E6*RHS%E47 +  &
              LHS%E47*RHS%E6 + LHS%E7*RHS%E46 + LHS%E46*RHS%E7
      RES%E567 = LHS%R*RHS%E567 + LHS%E567*RHS%R +  &
              LHS%E5*RHS%E67 + LHS%E67*RHS%E5 + LHS%E6*RHS%E57 +  &
              LHS%E57*RHS%E6 + LHS%E7*RHS%E56 + LHS%E56*RHS%E7
      RES%E667 = LHS%R*RHS%E667 + LHS%E667*RHS%R +  &
              LHS%E6*RHS%E67 + LHS%E67*RHS%E6 + LHS%E7*RHS%E66 + LHS%E66*RHS%E7
      RES%E177 = LHS%R*RHS%E177 + LHS%E177*RHS%R +  &
              LHS%E1*RHS%E77 + LHS%E77*RHS%E1 + LHS%E7*RHS%E17 + LHS%E17*RHS%E7
      RES%E277 = LHS%R*RHS%E277 + LHS%E277*RHS%R +  &
              LHS%E2*RHS%E77 + LHS%E77*RHS%E2 + LHS%E7*RHS%E27 + LHS%E27*RHS%E7
      RES%E377 = LHS%R*RHS%E377 + LHS%E377*RHS%R +  &
              LHS%E3*RHS%E77 + LHS%E77*RHS%E3 + LHS%E7*RHS%E37 + LHS%E37*RHS%E7
      RES%E477 = LHS%R*RHS%E477 + LHS%E477*RHS%R +  &
              LHS%E4*RHS%E77 + LHS%E77*RHS%E4 + LHS%E7*RHS%E47 + LHS%E47*RHS%E7
      RES%E577 = LHS%R*RHS%E577 + LHS%E577*RHS%R +  &
              LHS%E5*RHS%E77 + LHS%E77*RHS%E5 + LHS%E7*RHS%E57 + LHS%E57*RHS%E7
      RES%E677 = LHS%R*RHS%E677 + LHS%E677*RHS%R +  &
              LHS%E6*RHS%E77 + LHS%E77*RHS%E6 + LHS%E7*RHS%E67 + LHS%E67*RHS%E7
      RES%E777 = LHS%R*RHS%E777 + LHS%E777*RHS%R +  &
              LHS%E7*RHS%E77 + LHS%E77*RHS%E7
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

   END FUNCTION ONUMM7N3_MUL_OO_MS

   FUNCTION ONUMM7N3_MUL_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N3), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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

      ! Order 3
      RES%E111 = LHS*RHS%E111
      RES%E112 = LHS*RHS%E112
      RES%E122 = LHS*RHS%E122
      RES%E222 = LHS*RHS%E222
      RES%E113 = LHS*RHS%E113
      RES%E123 = LHS*RHS%E123
      RES%E223 = LHS*RHS%E223
      RES%E133 = LHS*RHS%E133
      RES%E233 = LHS*RHS%E233
      RES%E333 = LHS*RHS%E333
      RES%E114 = LHS*RHS%E114
      RES%E124 = LHS*RHS%E124
      RES%E224 = LHS*RHS%E224
      RES%E134 = LHS*RHS%E134
      RES%E234 = LHS*RHS%E234
      RES%E334 = LHS*RHS%E334
      RES%E144 = LHS*RHS%E144
      RES%E244 = LHS*RHS%E244
      RES%E344 = LHS*RHS%E344
      RES%E444 = LHS*RHS%E444
      RES%E115 = LHS*RHS%E115
      RES%E125 = LHS*RHS%E125
      RES%E225 = LHS*RHS%E225
      RES%E135 = LHS*RHS%E135
      RES%E235 = LHS*RHS%E235
      RES%E335 = LHS*RHS%E335
      RES%E145 = LHS*RHS%E145
      RES%E245 = LHS*RHS%E245
      RES%E345 = LHS*RHS%E345
      RES%E445 = LHS*RHS%E445
      RES%E155 = LHS*RHS%E155
      RES%E255 = LHS*RHS%E255
      RES%E355 = LHS*RHS%E355
      RES%E455 = LHS*RHS%E455
      RES%E555 = LHS*RHS%E555
      RES%E116 = LHS*RHS%E116
      RES%E126 = LHS*RHS%E126
      RES%E226 = LHS*RHS%E226
      RES%E136 = LHS*RHS%E136
      RES%E236 = LHS*RHS%E236
      RES%E336 = LHS*RHS%E336
      RES%E146 = LHS*RHS%E146
      RES%E246 = LHS*RHS%E246
      RES%E346 = LHS*RHS%E346
      RES%E446 = LHS*RHS%E446
      RES%E156 = LHS*RHS%E156
      RES%E256 = LHS*RHS%E256
      RES%E356 = LHS*RHS%E356
      RES%E456 = LHS*RHS%E456
      RES%E556 = LHS*RHS%E556
      RES%E166 = LHS*RHS%E166
      RES%E266 = LHS*RHS%E266
      RES%E366 = LHS*RHS%E366
      RES%E466 = LHS*RHS%E466
      RES%E566 = LHS*RHS%E566
      RES%E666 = LHS*RHS%E666
      RES%E117 = LHS*RHS%E117
      RES%E127 = LHS*RHS%E127
      RES%E227 = LHS*RHS%E227
      RES%E137 = LHS*RHS%E137
      RES%E237 = LHS*RHS%E237
      RES%E337 = LHS*RHS%E337
      RES%E147 = LHS*RHS%E147
      RES%E247 = LHS*RHS%E247
      RES%E347 = LHS*RHS%E347
      RES%E447 = LHS*RHS%E447
      RES%E157 = LHS*RHS%E157
      RES%E257 = LHS*RHS%E257
      RES%E357 = LHS*RHS%E357
      RES%E457 = LHS*RHS%E457
      RES%E557 = LHS*RHS%E557
      RES%E167 = LHS*RHS%E167
      RES%E267 = LHS*RHS%E267
      RES%E367 = LHS*RHS%E367
      RES%E467 = LHS*RHS%E467
      RES%E567 = LHS*RHS%E567
      RES%E667 = LHS*RHS%E667
      RES%E177 = LHS*RHS%E177
      RES%E277 = LHS*RHS%E277
      RES%E377 = LHS*RHS%E377
      RES%E477 = LHS*RHS%E477
      RES%E577 = LHS*RHS%E577
      RES%E677 = LHS*RHS%E677
      RES%E777 = LHS*RHS%E777

   END FUNCTION ONUMM7N3_MUL_RO_MS

   FUNCTION ONUMM7N3_MUL_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111*RHS
      RES%E112 = LHS%E112*RHS
      RES%E122 = LHS%E122*RHS
      RES%E222 = LHS%E222*RHS
      RES%E113 = LHS%E113*RHS
      RES%E123 = LHS%E123*RHS
      RES%E223 = LHS%E223*RHS
      RES%E133 = LHS%E133*RHS
      RES%E233 = LHS%E233*RHS
      RES%E333 = LHS%E333*RHS
      RES%E114 = LHS%E114*RHS
      RES%E124 = LHS%E124*RHS
      RES%E224 = LHS%E224*RHS
      RES%E134 = LHS%E134*RHS
      RES%E234 = LHS%E234*RHS
      RES%E334 = LHS%E334*RHS
      RES%E144 = LHS%E144*RHS
      RES%E244 = LHS%E244*RHS
      RES%E344 = LHS%E344*RHS
      RES%E444 = LHS%E444*RHS
      RES%E115 = LHS%E115*RHS
      RES%E125 = LHS%E125*RHS
      RES%E225 = LHS%E225*RHS
      RES%E135 = LHS%E135*RHS
      RES%E235 = LHS%E235*RHS
      RES%E335 = LHS%E335*RHS
      RES%E145 = LHS%E145*RHS
      RES%E245 = LHS%E245*RHS
      RES%E345 = LHS%E345*RHS
      RES%E445 = LHS%E445*RHS
      RES%E155 = LHS%E155*RHS
      RES%E255 = LHS%E255*RHS
      RES%E355 = LHS%E355*RHS
      RES%E455 = LHS%E455*RHS
      RES%E555 = LHS%E555*RHS
      RES%E116 = LHS%E116*RHS
      RES%E126 = LHS%E126*RHS
      RES%E226 = LHS%E226*RHS
      RES%E136 = LHS%E136*RHS
      RES%E236 = LHS%E236*RHS
      RES%E336 = LHS%E336*RHS
      RES%E146 = LHS%E146*RHS
      RES%E246 = LHS%E246*RHS
      RES%E346 = LHS%E346*RHS
      RES%E446 = LHS%E446*RHS
      RES%E156 = LHS%E156*RHS
      RES%E256 = LHS%E256*RHS
      RES%E356 = LHS%E356*RHS
      RES%E456 = LHS%E456*RHS
      RES%E556 = LHS%E556*RHS
      RES%E166 = LHS%E166*RHS
      RES%E266 = LHS%E266*RHS
      RES%E366 = LHS%E366*RHS
      RES%E466 = LHS%E466*RHS
      RES%E566 = LHS%E566*RHS
      RES%E666 = LHS%E666*RHS
      RES%E117 = LHS%E117*RHS
      RES%E127 = LHS%E127*RHS
      RES%E227 = LHS%E227*RHS
      RES%E137 = LHS%E137*RHS
      RES%E237 = LHS%E237*RHS
      RES%E337 = LHS%E337*RHS
      RES%E147 = LHS%E147*RHS
      RES%E247 = LHS%E247*RHS
      RES%E347 = LHS%E347*RHS
      RES%E447 = LHS%E447*RHS
      RES%E157 = LHS%E157*RHS
      RES%E257 = LHS%E257*RHS
      RES%E357 = LHS%E357*RHS
      RES%E457 = LHS%E457*RHS
      RES%E557 = LHS%E557*RHS
      RES%E167 = LHS%E167*RHS
      RES%E267 = LHS%E267*RHS
      RES%E367 = LHS%E367*RHS
      RES%E467 = LHS%E467*RHS
      RES%E567 = LHS%E567*RHS
      RES%E667 = LHS%E667*RHS
      RES%E177 = LHS%E177*RHS
      RES%E277 = LHS%E277*RHS
      RES%E377 = LHS%E377*RHS
      RES%E477 = LHS%E477*RHS
      RES%E577 = LHS%E577*RHS
      RES%E677 = LHS%E677*RHS
      RES%E777 = LHS%E777*RHS

   END FUNCTION ONUMM7N3_MUL_OR_MS

   FUNCTION ONUMM7N3_ADD_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111
      RES%E112 = LHS%E112 + RHS%E112
      RES%E122 = LHS%E122 + RHS%E122
      RES%E222 = LHS%E222 + RHS%E222
      RES%E113 = LHS%E113 + RHS%E113
      RES%E123 = LHS%E123 + RHS%E123
      RES%E223 = LHS%E223 + RHS%E223
      RES%E133 = LHS%E133 + RHS%E133
      RES%E233 = LHS%E233 + RHS%E233
      RES%E333 = LHS%E333 + RHS%E333
      RES%E114 = LHS%E114 + RHS%E114
      RES%E124 = LHS%E124 + RHS%E124
      RES%E224 = LHS%E224 + RHS%E224
      RES%E134 = LHS%E134 + RHS%E134
      RES%E234 = LHS%E234 + RHS%E234
      RES%E334 = LHS%E334 + RHS%E334
      RES%E144 = LHS%E144 + RHS%E144
      RES%E244 = LHS%E244 + RHS%E244
      RES%E344 = LHS%E344 + RHS%E344
      RES%E444 = LHS%E444 + RHS%E444
      RES%E115 = LHS%E115 + RHS%E115
      RES%E125 = LHS%E125 + RHS%E125
      RES%E225 = LHS%E225 + RHS%E225
      RES%E135 = LHS%E135 + RHS%E135
      RES%E235 = LHS%E235 + RHS%E235
      RES%E335 = LHS%E335 + RHS%E335
      RES%E145 = LHS%E145 + RHS%E145
      RES%E245 = LHS%E245 + RHS%E245
      RES%E345 = LHS%E345 + RHS%E345
      RES%E445 = LHS%E445 + RHS%E445
      RES%E155 = LHS%E155 + RHS%E155
      RES%E255 = LHS%E255 + RHS%E255
      RES%E355 = LHS%E355 + RHS%E355
      RES%E455 = LHS%E455 + RHS%E455
      RES%E555 = LHS%E555 + RHS%E555
      RES%E116 = LHS%E116 + RHS%E116
      RES%E126 = LHS%E126 + RHS%E126
      RES%E226 = LHS%E226 + RHS%E226
      RES%E136 = LHS%E136 + RHS%E136
      RES%E236 = LHS%E236 + RHS%E236
      RES%E336 = LHS%E336 + RHS%E336
      RES%E146 = LHS%E146 + RHS%E146
      RES%E246 = LHS%E246 + RHS%E246
      RES%E346 = LHS%E346 + RHS%E346
      RES%E446 = LHS%E446 + RHS%E446
      RES%E156 = LHS%E156 + RHS%E156
      RES%E256 = LHS%E256 + RHS%E256
      RES%E356 = LHS%E356 + RHS%E356
      RES%E456 = LHS%E456 + RHS%E456
      RES%E556 = LHS%E556 + RHS%E556
      RES%E166 = LHS%E166 + RHS%E166
      RES%E266 = LHS%E266 + RHS%E266
      RES%E366 = LHS%E366 + RHS%E366
      RES%E466 = LHS%E466 + RHS%E466
      RES%E566 = LHS%E566 + RHS%E566
      RES%E666 = LHS%E666 + RHS%E666
      RES%E117 = LHS%E117 + RHS%E117
      RES%E127 = LHS%E127 + RHS%E127
      RES%E227 = LHS%E227 + RHS%E227
      RES%E137 = LHS%E137 + RHS%E137
      RES%E237 = LHS%E237 + RHS%E237
      RES%E337 = LHS%E337 + RHS%E337
      RES%E147 = LHS%E147 + RHS%E147
      RES%E247 = LHS%E247 + RHS%E247
      RES%E347 = LHS%E347 + RHS%E347
      RES%E447 = LHS%E447 + RHS%E447
      RES%E157 = LHS%E157 + RHS%E157
      RES%E257 = LHS%E257 + RHS%E257
      RES%E357 = LHS%E357 + RHS%E357
      RES%E457 = LHS%E457 + RHS%E457
      RES%E557 = LHS%E557 + RHS%E557
      RES%E167 = LHS%E167 + RHS%E167
      RES%E267 = LHS%E267 + RHS%E267
      RES%E367 = LHS%E367 + RHS%E367
      RES%E467 = LHS%E467 + RHS%E467
      RES%E567 = LHS%E567 + RHS%E567
      RES%E667 = LHS%E667 + RHS%E667
      RES%E177 = LHS%E177 + RHS%E177
      RES%E277 = LHS%E277 + RHS%E277
      RES%E377 = LHS%E377 + RHS%E377
      RES%E477 = LHS%E477 + RHS%E477
      RES%E577 = LHS%E577 + RHS%E577
      RES%E677 = LHS%E677 + RHS%E677
      RES%E777 = LHS%E777 + RHS%E777

   END FUNCTION ONUMM7N3_ADD_OO_SV

   FUNCTION ONUMM7N3_ADD_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1)) 

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

      ! Order 3
      RES%E111 =  + RHS%E111
      RES%E112 =  + RHS%E112
      RES%E122 =  + RHS%E122
      RES%E222 =  + RHS%E222
      RES%E113 =  + RHS%E113
      RES%E123 =  + RHS%E123
      RES%E223 =  + RHS%E223
      RES%E133 =  + RHS%E133
      RES%E233 =  + RHS%E233
      RES%E333 =  + RHS%E333
      RES%E114 =  + RHS%E114
      RES%E124 =  + RHS%E124
      RES%E224 =  + RHS%E224
      RES%E134 =  + RHS%E134
      RES%E234 =  + RHS%E234
      RES%E334 =  + RHS%E334
      RES%E144 =  + RHS%E144
      RES%E244 =  + RHS%E244
      RES%E344 =  + RHS%E344
      RES%E444 =  + RHS%E444
      RES%E115 =  + RHS%E115
      RES%E125 =  + RHS%E125
      RES%E225 =  + RHS%E225
      RES%E135 =  + RHS%E135
      RES%E235 =  + RHS%E235
      RES%E335 =  + RHS%E335
      RES%E145 =  + RHS%E145
      RES%E245 =  + RHS%E245
      RES%E345 =  + RHS%E345
      RES%E445 =  + RHS%E445
      RES%E155 =  + RHS%E155
      RES%E255 =  + RHS%E255
      RES%E355 =  + RHS%E355
      RES%E455 =  + RHS%E455
      RES%E555 =  + RHS%E555
      RES%E116 =  + RHS%E116
      RES%E126 =  + RHS%E126
      RES%E226 =  + RHS%E226
      RES%E136 =  + RHS%E136
      RES%E236 =  + RHS%E236
      RES%E336 =  + RHS%E336
      RES%E146 =  + RHS%E146
      RES%E246 =  + RHS%E246
      RES%E346 =  + RHS%E346
      RES%E446 =  + RHS%E446
      RES%E156 =  + RHS%E156
      RES%E256 =  + RHS%E256
      RES%E356 =  + RHS%E356
      RES%E456 =  + RHS%E456
      RES%E556 =  + RHS%E556
      RES%E166 =  + RHS%E166
      RES%E266 =  + RHS%E266
      RES%E366 =  + RHS%E366
      RES%E466 =  + RHS%E466
      RES%E566 =  + RHS%E566
      RES%E666 =  + RHS%E666
      RES%E117 =  + RHS%E117
      RES%E127 =  + RHS%E127
      RES%E227 =  + RHS%E227
      RES%E137 =  + RHS%E137
      RES%E237 =  + RHS%E237
      RES%E337 =  + RHS%E337
      RES%E147 =  + RHS%E147
      RES%E247 =  + RHS%E247
      RES%E347 =  + RHS%E347
      RES%E447 =  + RHS%E447
      RES%E157 =  + RHS%E157
      RES%E257 =  + RHS%E257
      RES%E357 =  + RHS%E357
      RES%E457 =  + RHS%E457
      RES%E557 =  + RHS%E557
      RES%E167 =  + RHS%E167
      RES%E267 =  + RHS%E267
      RES%E367 =  + RHS%E367
      RES%E467 =  + RHS%E467
      RES%E567 =  + RHS%E567
      RES%E667 =  + RHS%E667
      RES%E177 =  + RHS%E177
      RES%E277 =  + RHS%E277
      RES%E377 =  + RHS%E377
      RES%E477 =  + RHS%E477
      RES%E577 =  + RHS%E577
      RES%E677 =  + RHS%E677
      RES%E777 =  + RHS%E777

   END FUNCTION ONUMM7N3_ADD_RO_SV

   FUNCTION ONUMM7N3_ADD_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E112 = LHS%E112
      RES%E122 = LHS%E122
      RES%E222 = LHS%E222
      RES%E113 = LHS%E113
      RES%E123 = LHS%E123
      RES%E223 = LHS%E223
      RES%E133 = LHS%E133
      RES%E233 = LHS%E233
      RES%E333 = LHS%E333
      RES%E114 = LHS%E114
      RES%E124 = LHS%E124
      RES%E224 = LHS%E224
      RES%E134 = LHS%E134
      RES%E234 = LHS%E234
      RES%E334 = LHS%E334
      RES%E144 = LHS%E144
      RES%E244 = LHS%E244
      RES%E344 = LHS%E344
      RES%E444 = LHS%E444
      RES%E115 = LHS%E115
      RES%E125 = LHS%E125
      RES%E225 = LHS%E225
      RES%E135 = LHS%E135
      RES%E235 = LHS%E235
      RES%E335 = LHS%E335
      RES%E145 = LHS%E145
      RES%E245 = LHS%E245
      RES%E345 = LHS%E345
      RES%E445 = LHS%E445
      RES%E155 = LHS%E155
      RES%E255 = LHS%E255
      RES%E355 = LHS%E355
      RES%E455 = LHS%E455
      RES%E555 = LHS%E555
      RES%E116 = LHS%E116
      RES%E126 = LHS%E126
      RES%E226 = LHS%E226
      RES%E136 = LHS%E136
      RES%E236 = LHS%E236
      RES%E336 = LHS%E336
      RES%E146 = LHS%E146
      RES%E246 = LHS%E246
      RES%E346 = LHS%E346
      RES%E446 = LHS%E446
      RES%E156 = LHS%E156
      RES%E256 = LHS%E256
      RES%E356 = LHS%E356
      RES%E456 = LHS%E456
      RES%E556 = LHS%E556
      RES%E166 = LHS%E166
      RES%E266 = LHS%E266
      RES%E366 = LHS%E366
      RES%E466 = LHS%E466
      RES%E566 = LHS%E566
      RES%E666 = LHS%E666
      RES%E117 = LHS%E117
      RES%E127 = LHS%E127
      RES%E227 = LHS%E227
      RES%E137 = LHS%E137
      RES%E237 = LHS%E237
      RES%E337 = LHS%E337
      RES%E147 = LHS%E147
      RES%E247 = LHS%E247
      RES%E347 = LHS%E347
      RES%E447 = LHS%E447
      RES%E157 = LHS%E157
      RES%E257 = LHS%E257
      RES%E357 = LHS%E357
      RES%E457 = LHS%E457
      RES%E557 = LHS%E557
      RES%E167 = LHS%E167
      RES%E267 = LHS%E267
      RES%E367 = LHS%E367
      RES%E467 = LHS%E467
      RES%E567 = LHS%E567
      RES%E667 = LHS%E667
      RES%E177 = LHS%E177
      RES%E277 = LHS%E277
      RES%E377 = LHS%E377
      RES%E477 = LHS%E477
      RES%E577 = LHS%E577
      RES%E677 = LHS%E677
      RES%E777 = LHS%E777

   END FUNCTION ONUMM7N3_ADD_OR_SV

   FUNCTION ONUMM7N3_SUB_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111
      RES%E112 = LHS%E112 - RHS%E112
      RES%E122 = LHS%E122 - RHS%E122
      RES%E222 = LHS%E222 - RHS%E222
      RES%E113 = LHS%E113 - RHS%E113
      RES%E123 = LHS%E123 - RHS%E123
      RES%E223 = LHS%E223 - RHS%E223
      RES%E133 = LHS%E133 - RHS%E133
      RES%E233 = LHS%E233 - RHS%E233
      RES%E333 = LHS%E333 - RHS%E333
      RES%E114 = LHS%E114 - RHS%E114
      RES%E124 = LHS%E124 - RHS%E124
      RES%E224 = LHS%E224 - RHS%E224
      RES%E134 = LHS%E134 - RHS%E134
      RES%E234 = LHS%E234 - RHS%E234
      RES%E334 = LHS%E334 - RHS%E334
      RES%E144 = LHS%E144 - RHS%E144
      RES%E244 = LHS%E244 - RHS%E244
      RES%E344 = LHS%E344 - RHS%E344
      RES%E444 = LHS%E444 - RHS%E444
      RES%E115 = LHS%E115 - RHS%E115
      RES%E125 = LHS%E125 - RHS%E125
      RES%E225 = LHS%E225 - RHS%E225
      RES%E135 = LHS%E135 - RHS%E135
      RES%E235 = LHS%E235 - RHS%E235
      RES%E335 = LHS%E335 - RHS%E335
      RES%E145 = LHS%E145 - RHS%E145
      RES%E245 = LHS%E245 - RHS%E245
      RES%E345 = LHS%E345 - RHS%E345
      RES%E445 = LHS%E445 - RHS%E445
      RES%E155 = LHS%E155 - RHS%E155
      RES%E255 = LHS%E255 - RHS%E255
      RES%E355 = LHS%E355 - RHS%E355
      RES%E455 = LHS%E455 - RHS%E455
      RES%E555 = LHS%E555 - RHS%E555
      RES%E116 = LHS%E116 - RHS%E116
      RES%E126 = LHS%E126 - RHS%E126
      RES%E226 = LHS%E226 - RHS%E226
      RES%E136 = LHS%E136 - RHS%E136
      RES%E236 = LHS%E236 - RHS%E236
      RES%E336 = LHS%E336 - RHS%E336
      RES%E146 = LHS%E146 - RHS%E146
      RES%E246 = LHS%E246 - RHS%E246
      RES%E346 = LHS%E346 - RHS%E346
      RES%E446 = LHS%E446 - RHS%E446
      RES%E156 = LHS%E156 - RHS%E156
      RES%E256 = LHS%E256 - RHS%E256
      RES%E356 = LHS%E356 - RHS%E356
      RES%E456 = LHS%E456 - RHS%E456
      RES%E556 = LHS%E556 - RHS%E556
      RES%E166 = LHS%E166 - RHS%E166
      RES%E266 = LHS%E266 - RHS%E266
      RES%E366 = LHS%E366 - RHS%E366
      RES%E466 = LHS%E466 - RHS%E466
      RES%E566 = LHS%E566 - RHS%E566
      RES%E666 = LHS%E666 - RHS%E666
      RES%E117 = LHS%E117 - RHS%E117
      RES%E127 = LHS%E127 - RHS%E127
      RES%E227 = LHS%E227 - RHS%E227
      RES%E137 = LHS%E137 - RHS%E137
      RES%E237 = LHS%E237 - RHS%E237
      RES%E337 = LHS%E337 - RHS%E337
      RES%E147 = LHS%E147 - RHS%E147
      RES%E247 = LHS%E247 - RHS%E247
      RES%E347 = LHS%E347 - RHS%E347
      RES%E447 = LHS%E447 - RHS%E447
      RES%E157 = LHS%E157 - RHS%E157
      RES%E257 = LHS%E257 - RHS%E257
      RES%E357 = LHS%E357 - RHS%E357
      RES%E457 = LHS%E457 - RHS%E457
      RES%E557 = LHS%E557 - RHS%E557
      RES%E167 = LHS%E167 - RHS%E167
      RES%E267 = LHS%E267 - RHS%E267
      RES%E367 = LHS%E367 - RHS%E367
      RES%E467 = LHS%E467 - RHS%E467
      RES%E567 = LHS%E567 - RHS%E567
      RES%E667 = LHS%E667 - RHS%E667
      RES%E177 = LHS%E177 - RHS%E177
      RES%E277 = LHS%E277 - RHS%E277
      RES%E377 = LHS%E377 - RHS%E377
      RES%E477 = LHS%E477 - RHS%E477
      RES%E577 = LHS%E577 - RHS%E577
      RES%E677 = LHS%E677 - RHS%E677
      RES%E777 = LHS%E777 - RHS%E777

   END FUNCTION ONUMM7N3_SUB_OO_SV

   FUNCTION ONUMM7N3_SUB_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1)) 

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

      ! Order 3
      RES%E111 =  - RHS%E111
      RES%E112 =  - RHS%E112
      RES%E122 =  - RHS%E122
      RES%E222 =  - RHS%E222
      RES%E113 =  - RHS%E113
      RES%E123 =  - RHS%E123
      RES%E223 =  - RHS%E223
      RES%E133 =  - RHS%E133
      RES%E233 =  - RHS%E233
      RES%E333 =  - RHS%E333
      RES%E114 =  - RHS%E114
      RES%E124 =  - RHS%E124
      RES%E224 =  - RHS%E224
      RES%E134 =  - RHS%E134
      RES%E234 =  - RHS%E234
      RES%E334 =  - RHS%E334
      RES%E144 =  - RHS%E144
      RES%E244 =  - RHS%E244
      RES%E344 =  - RHS%E344
      RES%E444 =  - RHS%E444
      RES%E115 =  - RHS%E115
      RES%E125 =  - RHS%E125
      RES%E225 =  - RHS%E225
      RES%E135 =  - RHS%E135
      RES%E235 =  - RHS%E235
      RES%E335 =  - RHS%E335
      RES%E145 =  - RHS%E145
      RES%E245 =  - RHS%E245
      RES%E345 =  - RHS%E345
      RES%E445 =  - RHS%E445
      RES%E155 =  - RHS%E155
      RES%E255 =  - RHS%E255
      RES%E355 =  - RHS%E355
      RES%E455 =  - RHS%E455
      RES%E555 =  - RHS%E555
      RES%E116 =  - RHS%E116
      RES%E126 =  - RHS%E126
      RES%E226 =  - RHS%E226
      RES%E136 =  - RHS%E136
      RES%E236 =  - RHS%E236
      RES%E336 =  - RHS%E336
      RES%E146 =  - RHS%E146
      RES%E246 =  - RHS%E246
      RES%E346 =  - RHS%E346
      RES%E446 =  - RHS%E446
      RES%E156 =  - RHS%E156
      RES%E256 =  - RHS%E256
      RES%E356 =  - RHS%E356
      RES%E456 =  - RHS%E456
      RES%E556 =  - RHS%E556
      RES%E166 =  - RHS%E166
      RES%E266 =  - RHS%E266
      RES%E366 =  - RHS%E366
      RES%E466 =  - RHS%E466
      RES%E566 =  - RHS%E566
      RES%E666 =  - RHS%E666
      RES%E117 =  - RHS%E117
      RES%E127 =  - RHS%E127
      RES%E227 =  - RHS%E227
      RES%E137 =  - RHS%E137
      RES%E237 =  - RHS%E237
      RES%E337 =  - RHS%E337
      RES%E147 =  - RHS%E147
      RES%E247 =  - RHS%E247
      RES%E347 =  - RHS%E347
      RES%E447 =  - RHS%E447
      RES%E157 =  - RHS%E157
      RES%E257 =  - RHS%E257
      RES%E357 =  - RHS%E357
      RES%E457 =  - RHS%E457
      RES%E557 =  - RHS%E557
      RES%E167 =  - RHS%E167
      RES%E267 =  - RHS%E267
      RES%E367 =  - RHS%E367
      RES%E467 =  - RHS%E467
      RES%E567 =  - RHS%E567
      RES%E667 =  - RHS%E667
      RES%E177 =  - RHS%E177
      RES%E277 =  - RHS%E277
      RES%E377 =  - RHS%E377
      RES%E477 =  - RHS%E477
      RES%E577 =  - RHS%E577
      RES%E677 =  - RHS%E677
      RES%E777 =  - RHS%E777

   END FUNCTION ONUMM7N3_SUB_RO_SV

   FUNCTION ONUMM7N3_SUB_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E112 = LHS%E112
      RES%E122 = LHS%E122
      RES%E222 = LHS%E222
      RES%E113 = LHS%E113
      RES%E123 = LHS%E123
      RES%E223 = LHS%E223
      RES%E133 = LHS%E133
      RES%E233 = LHS%E233
      RES%E333 = LHS%E333
      RES%E114 = LHS%E114
      RES%E124 = LHS%E124
      RES%E224 = LHS%E224
      RES%E134 = LHS%E134
      RES%E234 = LHS%E234
      RES%E334 = LHS%E334
      RES%E144 = LHS%E144
      RES%E244 = LHS%E244
      RES%E344 = LHS%E344
      RES%E444 = LHS%E444
      RES%E115 = LHS%E115
      RES%E125 = LHS%E125
      RES%E225 = LHS%E225
      RES%E135 = LHS%E135
      RES%E235 = LHS%E235
      RES%E335 = LHS%E335
      RES%E145 = LHS%E145
      RES%E245 = LHS%E245
      RES%E345 = LHS%E345
      RES%E445 = LHS%E445
      RES%E155 = LHS%E155
      RES%E255 = LHS%E255
      RES%E355 = LHS%E355
      RES%E455 = LHS%E455
      RES%E555 = LHS%E555
      RES%E116 = LHS%E116
      RES%E126 = LHS%E126
      RES%E226 = LHS%E226
      RES%E136 = LHS%E136
      RES%E236 = LHS%E236
      RES%E336 = LHS%E336
      RES%E146 = LHS%E146
      RES%E246 = LHS%E246
      RES%E346 = LHS%E346
      RES%E446 = LHS%E446
      RES%E156 = LHS%E156
      RES%E256 = LHS%E256
      RES%E356 = LHS%E356
      RES%E456 = LHS%E456
      RES%E556 = LHS%E556
      RES%E166 = LHS%E166
      RES%E266 = LHS%E266
      RES%E366 = LHS%E366
      RES%E466 = LHS%E466
      RES%E566 = LHS%E566
      RES%E666 = LHS%E666
      RES%E117 = LHS%E117
      RES%E127 = LHS%E127
      RES%E227 = LHS%E227
      RES%E137 = LHS%E137
      RES%E237 = LHS%E237
      RES%E337 = LHS%E337
      RES%E147 = LHS%E147
      RES%E247 = LHS%E247
      RES%E347 = LHS%E347
      RES%E447 = LHS%E447
      RES%E157 = LHS%E157
      RES%E257 = LHS%E257
      RES%E357 = LHS%E357
      RES%E457 = LHS%E457
      RES%E557 = LHS%E557
      RES%E167 = LHS%E167
      RES%E267 = LHS%E267
      RES%E367 = LHS%E367
      RES%E467 = LHS%E467
      RES%E567 = LHS%E567
      RES%E667 = LHS%E667
      RES%E177 = LHS%E177
      RES%E277 = LHS%E277
      RES%E377 = LHS%E377
      RES%E477 = LHS%E477
      RES%E577 = LHS%E577
      RES%E677 = LHS%E677
      RES%E777 = LHS%E777

   END FUNCTION ONUMM7N3_SUB_OR_SV

   FUNCTION ONUMM7N3_MUL_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 3
      RES%E111 = LHS%R*RHS%E111 + LHS%E111*RHS%R +  &
              LHS%E1*RHS%E11 + LHS%E11*RHS%E1
      RES%E112 = LHS%R*RHS%E112 + LHS%E112*RHS%R +  &
              LHS%E1*RHS%E12 + LHS%E12*RHS%E1 + LHS%E2*RHS%E11 + LHS%E11*RHS%E2
      RES%E122 = LHS%R*RHS%E122 + LHS%E122*RHS%R +  &
              LHS%E1*RHS%E22 + LHS%E22*RHS%E1 + LHS%E2*RHS%E12 + LHS%E12*RHS%E2
      RES%E222 = LHS%R*RHS%E222 + LHS%E222*RHS%R +  &
              LHS%E2*RHS%E22 + LHS%E22*RHS%E2
      RES%E113 = LHS%R*RHS%E113 + LHS%E113*RHS%R +  &
              LHS%E1*RHS%E13 + LHS%E13*RHS%E1 + LHS%E3*RHS%E11 + LHS%E11*RHS%E3
      RES%E123 = LHS%R*RHS%E123 + LHS%E123*RHS%R +  &
              LHS%E1*RHS%E23 + LHS%E23*RHS%E1 + LHS%E2*RHS%E13 +  &
              LHS%E13*RHS%E2 + LHS%E3*RHS%E12 + LHS%E12*RHS%E3
      RES%E223 = LHS%R*RHS%E223 + LHS%E223*RHS%R +  &
              LHS%E2*RHS%E23 + LHS%E23*RHS%E2 + LHS%E3*RHS%E22 + LHS%E22*RHS%E3
      RES%E133 = LHS%R*RHS%E133 + LHS%E133*RHS%R +  &
              LHS%E1*RHS%E33 + LHS%E33*RHS%E1 + LHS%E3*RHS%E13 + LHS%E13*RHS%E3
      RES%E233 = LHS%R*RHS%E233 + LHS%E233*RHS%R +  &
              LHS%E2*RHS%E33 + LHS%E33*RHS%E2 + LHS%E3*RHS%E23 + LHS%E23*RHS%E3
      RES%E333 = LHS%R*RHS%E333 + LHS%E333*RHS%R +  &
              LHS%E3*RHS%E33 + LHS%E33*RHS%E3
      RES%E114 = LHS%R*RHS%E114 + LHS%E114*RHS%R +  &
              LHS%E1*RHS%E14 + LHS%E14*RHS%E1 + LHS%E4*RHS%E11 + LHS%E11*RHS%E4
      RES%E124 = LHS%R*RHS%E124 + LHS%E124*RHS%R +  &
              LHS%E1*RHS%E24 + LHS%E24*RHS%E1 + LHS%E2*RHS%E14 +  &
              LHS%E14*RHS%E2 + LHS%E4*RHS%E12 + LHS%E12*RHS%E4
      RES%E224 = LHS%R*RHS%E224 + LHS%E224*RHS%R +  &
              LHS%E2*RHS%E24 + LHS%E24*RHS%E2 + LHS%E4*RHS%E22 + LHS%E22*RHS%E4
      RES%E134 = LHS%R*RHS%E134 + LHS%E134*RHS%R +  &
              LHS%E1*RHS%E34 + LHS%E34*RHS%E1 + LHS%E3*RHS%E14 +  &
              LHS%E14*RHS%E3 + LHS%E4*RHS%E13 + LHS%E13*RHS%E4
      RES%E234 = LHS%R*RHS%E234 + LHS%E234*RHS%R +  &
              LHS%E2*RHS%E34 + LHS%E34*RHS%E2 + LHS%E3*RHS%E24 +  &
              LHS%E24*RHS%E3 + LHS%E4*RHS%E23 + LHS%E23*RHS%E4
      RES%E334 = LHS%R*RHS%E334 + LHS%E334*RHS%R +  &
              LHS%E3*RHS%E34 + LHS%E34*RHS%E3 + LHS%E4*RHS%E33 + LHS%E33*RHS%E4
      RES%E144 = LHS%R*RHS%E144 + LHS%E144*RHS%R +  &
              LHS%E1*RHS%E44 + LHS%E44*RHS%E1 + LHS%E4*RHS%E14 + LHS%E14*RHS%E4
      RES%E244 = LHS%R*RHS%E244 + LHS%E244*RHS%R +  &
              LHS%E2*RHS%E44 + LHS%E44*RHS%E2 + LHS%E4*RHS%E24 + LHS%E24*RHS%E4
      RES%E344 = LHS%R*RHS%E344 + LHS%E344*RHS%R +  &
              LHS%E3*RHS%E44 + LHS%E44*RHS%E3 + LHS%E4*RHS%E34 + LHS%E34*RHS%E4
      RES%E444 = LHS%R*RHS%E444 + LHS%E444*RHS%R +  &
              LHS%E4*RHS%E44 + LHS%E44*RHS%E4
      RES%E115 = LHS%R*RHS%E115 + LHS%E115*RHS%R +  &
              LHS%E1*RHS%E15 + LHS%E15*RHS%E1 + LHS%E5*RHS%E11 + LHS%E11*RHS%E5
      RES%E125 = LHS%R*RHS%E125 + LHS%E125*RHS%R +  &
              LHS%E1*RHS%E25 + LHS%E25*RHS%E1 + LHS%E2*RHS%E15 +  &
              LHS%E15*RHS%E2 + LHS%E5*RHS%E12 + LHS%E12*RHS%E5
      RES%E225 = LHS%R*RHS%E225 + LHS%E225*RHS%R +  &
              LHS%E2*RHS%E25 + LHS%E25*RHS%E2 + LHS%E5*RHS%E22 + LHS%E22*RHS%E5
      RES%E135 = LHS%R*RHS%E135 + LHS%E135*RHS%R +  &
              LHS%E1*RHS%E35 + LHS%E35*RHS%E1 + LHS%E3*RHS%E15 +  &
              LHS%E15*RHS%E3 + LHS%E5*RHS%E13 + LHS%E13*RHS%E5
      RES%E235 = LHS%R*RHS%E235 + LHS%E235*RHS%R +  &
              LHS%E2*RHS%E35 + LHS%E35*RHS%E2 + LHS%E3*RHS%E25 +  &
              LHS%E25*RHS%E3 + LHS%E5*RHS%E23 + LHS%E23*RHS%E5
      RES%E335 = LHS%R*RHS%E335 + LHS%E335*RHS%R +  &
              LHS%E3*RHS%E35 + LHS%E35*RHS%E3 + LHS%E5*RHS%E33 + LHS%E33*RHS%E5
      RES%E145 = LHS%R*RHS%E145 + LHS%E145*RHS%R +  &
              LHS%E1*RHS%E45 + LHS%E45*RHS%E1 + LHS%E4*RHS%E15 +  &
              LHS%E15*RHS%E4 + LHS%E5*RHS%E14 + LHS%E14*RHS%E5
      RES%E245 = LHS%R*RHS%E245 + LHS%E245*RHS%R +  &
              LHS%E2*RHS%E45 + LHS%E45*RHS%E2 + LHS%E4*RHS%E25 +  &
              LHS%E25*RHS%E4 + LHS%E5*RHS%E24 + LHS%E24*RHS%E5
      RES%E345 = LHS%R*RHS%E345 + LHS%E345*RHS%R +  &
              LHS%E3*RHS%E45 + LHS%E45*RHS%E3 + LHS%E4*RHS%E35 +  &
              LHS%E35*RHS%E4 + LHS%E5*RHS%E34 + LHS%E34*RHS%E5
      RES%E445 = LHS%R*RHS%E445 + LHS%E445*RHS%R +  &
              LHS%E4*RHS%E45 + LHS%E45*RHS%E4 + LHS%E5*RHS%E44 + LHS%E44*RHS%E5
      RES%E155 = LHS%R*RHS%E155 + LHS%E155*RHS%R +  &
              LHS%E1*RHS%E55 + LHS%E55*RHS%E1 + LHS%E5*RHS%E15 + LHS%E15*RHS%E5
      RES%E255 = LHS%R*RHS%E255 + LHS%E255*RHS%R +  &
              LHS%E2*RHS%E55 + LHS%E55*RHS%E2 + LHS%E5*RHS%E25 + LHS%E25*RHS%E5
      RES%E355 = LHS%R*RHS%E355 + LHS%E355*RHS%R +  &
              LHS%E3*RHS%E55 + LHS%E55*RHS%E3 + LHS%E5*RHS%E35 + LHS%E35*RHS%E5
      RES%E455 = LHS%R*RHS%E455 + LHS%E455*RHS%R +  &
              LHS%E4*RHS%E55 + LHS%E55*RHS%E4 + LHS%E5*RHS%E45 + LHS%E45*RHS%E5
      RES%E555 = LHS%R*RHS%E555 + LHS%E555*RHS%R +  &
              LHS%E5*RHS%E55 + LHS%E55*RHS%E5
      RES%E116 = LHS%R*RHS%E116 + LHS%E116*RHS%R +  &
              LHS%E1*RHS%E16 + LHS%E16*RHS%E1 + LHS%E6*RHS%E11 + LHS%E11*RHS%E6
      RES%E126 = LHS%R*RHS%E126 + LHS%E126*RHS%R +  &
              LHS%E1*RHS%E26 + LHS%E26*RHS%E1 + LHS%E2*RHS%E16 +  &
              LHS%E16*RHS%E2 + LHS%E6*RHS%E12 + LHS%E12*RHS%E6
      RES%E226 = LHS%R*RHS%E226 + LHS%E226*RHS%R +  &
              LHS%E2*RHS%E26 + LHS%E26*RHS%E2 + LHS%E6*RHS%E22 + LHS%E22*RHS%E6
      RES%E136 = LHS%R*RHS%E136 + LHS%E136*RHS%R +  &
              LHS%E1*RHS%E36 + LHS%E36*RHS%E1 + LHS%E3*RHS%E16 +  &
              LHS%E16*RHS%E3 + LHS%E6*RHS%E13 + LHS%E13*RHS%E6
      RES%E236 = LHS%R*RHS%E236 + LHS%E236*RHS%R +  &
              LHS%E2*RHS%E36 + LHS%E36*RHS%E2 + LHS%E3*RHS%E26 +  &
              LHS%E26*RHS%E3 + LHS%E6*RHS%E23 + LHS%E23*RHS%E6
      RES%E336 = LHS%R*RHS%E336 + LHS%E336*RHS%R +  &
              LHS%E3*RHS%E36 + LHS%E36*RHS%E3 + LHS%E6*RHS%E33 + LHS%E33*RHS%E6
      RES%E146 = LHS%R*RHS%E146 + LHS%E146*RHS%R +  &
              LHS%E1*RHS%E46 + LHS%E46*RHS%E1 + LHS%E4*RHS%E16 +  &
              LHS%E16*RHS%E4 + LHS%E6*RHS%E14 + LHS%E14*RHS%E6
      RES%E246 = LHS%R*RHS%E246 + LHS%E246*RHS%R +  &
              LHS%E2*RHS%E46 + LHS%E46*RHS%E2 + LHS%E4*RHS%E26 +  &
              LHS%E26*RHS%E4 + LHS%E6*RHS%E24 + LHS%E24*RHS%E6
      RES%E346 = LHS%R*RHS%E346 + LHS%E346*RHS%R +  &
              LHS%E3*RHS%E46 + LHS%E46*RHS%E3 + LHS%E4*RHS%E36 +  &
              LHS%E36*RHS%E4 + LHS%E6*RHS%E34 + LHS%E34*RHS%E6
      RES%E446 = LHS%R*RHS%E446 + LHS%E446*RHS%R +  &
              LHS%E4*RHS%E46 + LHS%E46*RHS%E4 + LHS%E6*RHS%E44 + LHS%E44*RHS%E6
      RES%E156 = LHS%R*RHS%E156 + LHS%E156*RHS%R +  &
              LHS%E1*RHS%E56 + LHS%E56*RHS%E1 + LHS%E5*RHS%E16 +  &
              LHS%E16*RHS%E5 + LHS%E6*RHS%E15 + LHS%E15*RHS%E6
      RES%E256 = LHS%R*RHS%E256 + LHS%E256*RHS%R +  &
              LHS%E2*RHS%E56 + LHS%E56*RHS%E2 + LHS%E5*RHS%E26 +  &
              LHS%E26*RHS%E5 + LHS%E6*RHS%E25 + LHS%E25*RHS%E6
      RES%E356 = LHS%R*RHS%E356 + LHS%E356*RHS%R +  &
              LHS%E3*RHS%E56 + LHS%E56*RHS%E3 + LHS%E5*RHS%E36 +  &
              LHS%E36*RHS%E5 + LHS%E6*RHS%E35 + LHS%E35*RHS%E6
      RES%E456 = LHS%R*RHS%E456 + LHS%E456*RHS%R +  &
              LHS%E4*RHS%E56 + LHS%E56*RHS%E4 + LHS%E5*RHS%E46 +  &
              LHS%E46*RHS%E5 + LHS%E6*RHS%E45 + LHS%E45*RHS%E6
      RES%E556 = LHS%R*RHS%E556 + LHS%E556*RHS%R +  &
              LHS%E5*RHS%E56 + LHS%E56*RHS%E5 + LHS%E6*RHS%E55 + LHS%E55*RHS%E6
      RES%E166 = LHS%R*RHS%E166 + LHS%E166*RHS%R +  &
              LHS%E1*RHS%E66 + LHS%E66*RHS%E1 + LHS%E6*RHS%E16 + LHS%E16*RHS%E6
      RES%E266 = LHS%R*RHS%E266 + LHS%E266*RHS%R +  &
              LHS%E2*RHS%E66 + LHS%E66*RHS%E2 + LHS%E6*RHS%E26 + LHS%E26*RHS%E6
      RES%E366 = LHS%R*RHS%E366 + LHS%E366*RHS%R +  &
              LHS%E3*RHS%E66 + LHS%E66*RHS%E3 + LHS%E6*RHS%E36 + LHS%E36*RHS%E6
      RES%E466 = LHS%R*RHS%E466 + LHS%E466*RHS%R +  &
              LHS%E4*RHS%E66 + LHS%E66*RHS%E4 + LHS%E6*RHS%E46 + LHS%E46*RHS%E6
      RES%E566 = LHS%R*RHS%E566 + LHS%E566*RHS%R +  &
              LHS%E5*RHS%E66 + LHS%E66*RHS%E5 + LHS%E6*RHS%E56 + LHS%E56*RHS%E6
      RES%E666 = LHS%R*RHS%E666 + LHS%E666*RHS%R +  &
              LHS%E6*RHS%E66 + LHS%E66*RHS%E6
      RES%E117 = LHS%R*RHS%E117 + LHS%E117*RHS%R +  &
              LHS%E1*RHS%E17 + LHS%E17*RHS%E1 + LHS%E7*RHS%E11 + LHS%E11*RHS%E7
      RES%E127 = LHS%R*RHS%E127 + LHS%E127*RHS%R +  &
              LHS%E1*RHS%E27 + LHS%E27*RHS%E1 + LHS%E2*RHS%E17 +  &
              LHS%E17*RHS%E2 + LHS%E7*RHS%E12 + LHS%E12*RHS%E7
      RES%E227 = LHS%R*RHS%E227 + LHS%E227*RHS%R +  &
              LHS%E2*RHS%E27 + LHS%E27*RHS%E2 + LHS%E7*RHS%E22 + LHS%E22*RHS%E7
      RES%E137 = LHS%R*RHS%E137 + LHS%E137*RHS%R +  &
              LHS%E1*RHS%E37 + LHS%E37*RHS%E1 + LHS%E3*RHS%E17 +  &
              LHS%E17*RHS%E3 + LHS%E7*RHS%E13 + LHS%E13*RHS%E7
      RES%E237 = LHS%R*RHS%E237 + LHS%E237*RHS%R +  &
              LHS%E2*RHS%E37 + LHS%E37*RHS%E2 + LHS%E3*RHS%E27 +  &
              LHS%E27*RHS%E3 + LHS%E7*RHS%E23 + LHS%E23*RHS%E7
      RES%E337 = LHS%R*RHS%E337 + LHS%E337*RHS%R +  &
              LHS%E3*RHS%E37 + LHS%E37*RHS%E3 + LHS%E7*RHS%E33 + LHS%E33*RHS%E7
      RES%E147 = LHS%R*RHS%E147 + LHS%E147*RHS%R +  &
              LHS%E1*RHS%E47 + LHS%E47*RHS%E1 + LHS%E4*RHS%E17 +  &
              LHS%E17*RHS%E4 + LHS%E7*RHS%E14 + LHS%E14*RHS%E7
      RES%E247 = LHS%R*RHS%E247 + LHS%E247*RHS%R +  &
              LHS%E2*RHS%E47 + LHS%E47*RHS%E2 + LHS%E4*RHS%E27 +  &
              LHS%E27*RHS%E4 + LHS%E7*RHS%E24 + LHS%E24*RHS%E7
      RES%E347 = LHS%R*RHS%E347 + LHS%E347*RHS%R +  &
              LHS%E3*RHS%E47 + LHS%E47*RHS%E3 + LHS%E4*RHS%E37 +  &
              LHS%E37*RHS%E4 + LHS%E7*RHS%E34 + LHS%E34*RHS%E7
      RES%E447 = LHS%R*RHS%E447 + LHS%E447*RHS%R +  &
              LHS%E4*RHS%E47 + LHS%E47*RHS%E4 + LHS%E7*RHS%E44 + LHS%E44*RHS%E7
      RES%E157 = LHS%R*RHS%E157 + LHS%E157*RHS%R +  &
              LHS%E1*RHS%E57 + LHS%E57*RHS%E1 + LHS%E5*RHS%E17 +  &
              LHS%E17*RHS%E5 + LHS%E7*RHS%E15 + LHS%E15*RHS%E7
      RES%E257 = LHS%R*RHS%E257 + LHS%E257*RHS%R +  &
              LHS%E2*RHS%E57 + LHS%E57*RHS%E2 + LHS%E5*RHS%E27 +  &
              LHS%E27*RHS%E5 + LHS%E7*RHS%E25 + LHS%E25*RHS%E7
      RES%E357 = LHS%R*RHS%E357 + LHS%E357*RHS%R +  &
              LHS%E3*RHS%E57 + LHS%E57*RHS%E3 + LHS%E5*RHS%E37 +  &
              LHS%E37*RHS%E5 + LHS%E7*RHS%E35 + LHS%E35*RHS%E7
      RES%E457 = LHS%R*RHS%E457 + LHS%E457*RHS%R +  &
              LHS%E4*RHS%E57 + LHS%E57*RHS%E4 + LHS%E5*RHS%E47 +  &
              LHS%E47*RHS%E5 + LHS%E7*RHS%E45 + LHS%E45*RHS%E7
      RES%E557 = LHS%R*RHS%E557 + LHS%E557*RHS%R +  &
              LHS%E5*RHS%E57 + LHS%E57*RHS%E5 + LHS%E7*RHS%E55 + LHS%E55*RHS%E7
      RES%E167 = LHS%R*RHS%E167 + LHS%E167*RHS%R +  &
              LHS%E1*RHS%E67 + LHS%E67*RHS%E1 + LHS%E6*RHS%E17 +  &
              LHS%E17*RHS%E6 + LHS%E7*RHS%E16 + LHS%E16*RHS%E7
      RES%E267 = LHS%R*RHS%E267 + LHS%E267*RHS%R +  &
              LHS%E2*RHS%E67 + LHS%E67*RHS%E2 + LHS%E6*RHS%E27 +  &
              LHS%E27*RHS%E6 + LHS%E7*RHS%E26 + LHS%E26*RHS%E7
      RES%E367 = LHS%R*RHS%E367 + LHS%E367*RHS%R +  &
              LHS%E3*RHS%E67 + LHS%E67*RHS%E3 + LHS%E6*RHS%E37 +  &
              LHS%E37*RHS%E6 + LHS%E7*RHS%E36 + LHS%E36*RHS%E7
      RES%E467 = LHS%R*RHS%E467 + LHS%E467*RHS%R +  &
              LHS%E4*RHS%E67 + LHS%E67*RHS%E4 + LHS%E6*RHS%E47 +  &
              LHS%E47*RHS%E6 + LHS%E7*RHS%E46 + LHS%E46*RHS%E7
      RES%E567 = LHS%R*RHS%E567 + LHS%E567*RHS%R +  &
              LHS%E5*RHS%E67 + LHS%E67*RHS%E5 + LHS%E6*RHS%E57 +  &
              LHS%E57*RHS%E6 + LHS%E7*RHS%E56 + LHS%E56*RHS%E7
      RES%E667 = LHS%R*RHS%E667 + LHS%E667*RHS%R +  &
              LHS%E6*RHS%E67 + LHS%E67*RHS%E6 + LHS%E7*RHS%E66 + LHS%E66*RHS%E7
      RES%E177 = LHS%R*RHS%E177 + LHS%E177*RHS%R +  &
              LHS%E1*RHS%E77 + LHS%E77*RHS%E1 + LHS%E7*RHS%E17 + LHS%E17*RHS%E7
      RES%E277 = LHS%R*RHS%E277 + LHS%E277*RHS%R +  &
              LHS%E2*RHS%E77 + LHS%E77*RHS%E2 + LHS%E7*RHS%E27 + LHS%E27*RHS%E7
      RES%E377 = LHS%R*RHS%E377 + LHS%E377*RHS%R +  &
              LHS%E3*RHS%E77 + LHS%E77*RHS%E3 + LHS%E7*RHS%E37 + LHS%E37*RHS%E7
      RES%E477 = LHS%R*RHS%E477 + LHS%E477*RHS%R +  &
              LHS%E4*RHS%E77 + LHS%E77*RHS%E4 + LHS%E7*RHS%E47 + LHS%E47*RHS%E7
      RES%E577 = LHS%R*RHS%E577 + LHS%E577*RHS%R +  &
              LHS%E5*RHS%E77 + LHS%E77*RHS%E5 + LHS%E7*RHS%E57 + LHS%E57*RHS%E7
      RES%E677 = LHS%R*RHS%E677 + LHS%E677*RHS%R +  &
              LHS%E6*RHS%E77 + LHS%E77*RHS%E6 + LHS%E7*RHS%E67 + LHS%E67*RHS%E7
      RES%E777 = LHS%R*RHS%E777 + LHS%E777*RHS%R +  &
              LHS%E7*RHS%E77 + LHS%E77*RHS%E7
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

   END FUNCTION ONUMM7N3_MUL_OO_SV

   FUNCTION ONUMM7N3_MUL_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1)) 

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

      ! Order 3
      RES%E111 = LHS*RHS%E111
      RES%E112 = LHS*RHS%E112
      RES%E122 = LHS*RHS%E122
      RES%E222 = LHS*RHS%E222
      RES%E113 = LHS*RHS%E113
      RES%E123 = LHS*RHS%E123
      RES%E223 = LHS*RHS%E223
      RES%E133 = LHS*RHS%E133
      RES%E233 = LHS*RHS%E233
      RES%E333 = LHS*RHS%E333
      RES%E114 = LHS*RHS%E114
      RES%E124 = LHS*RHS%E124
      RES%E224 = LHS*RHS%E224
      RES%E134 = LHS*RHS%E134
      RES%E234 = LHS*RHS%E234
      RES%E334 = LHS*RHS%E334
      RES%E144 = LHS*RHS%E144
      RES%E244 = LHS*RHS%E244
      RES%E344 = LHS*RHS%E344
      RES%E444 = LHS*RHS%E444
      RES%E115 = LHS*RHS%E115
      RES%E125 = LHS*RHS%E125
      RES%E225 = LHS*RHS%E225
      RES%E135 = LHS*RHS%E135
      RES%E235 = LHS*RHS%E235
      RES%E335 = LHS*RHS%E335
      RES%E145 = LHS*RHS%E145
      RES%E245 = LHS*RHS%E245
      RES%E345 = LHS*RHS%E345
      RES%E445 = LHS*RHS%E445
      RES%E155 = LHS*RHS%E155
      RES%E255 = LHS*RHS%E255
      RES%E355 = LHS*RHS%E355
      RES%E455 = LHS*RHS%E455
      RES%E555 = LHS*RHS%E555
      RES%E116 = LHS*RHS%E116
      RES%E126 = LHS*RHS%E126
      RES%E226 = LHS*RHS%E226
      RES%E136 = LHS*RHS%E136
      RES%E236 = LHS*RHS%E236
      RES%E336 = LHS*RHS%E336
      RES%E146 = LHS*RHS%E146
      RES%E246 = LHS*RHS%E246
      RES%E346 = LHS*RHS%E346
      RES%E446 = LHS*RHS%E446
      RES%E156 = LHS*RHS%E156
      RES%E256 = LHS*RHS%E256
      RES%E356 = LHS*RHS%E356
      RES%E456 = LHS*RHS%E456
      RES%E556 = LHS*RHS%E556
      RES%E166 = LHS*RHS%E166
      RES%E266 = LHS*RHS%E266
      RES%E366 = LHS*RHS%E366
      RES%E466 = LHS*RHS%E466
      RES%E566 = LHS*RHS%E566
      RES%E666 = LHS*RHS%E666
      RES%E117 = LHS*RHS%E117
      RES%E127 = LHS*RHS%E127
      RES%E227 = LHS*RHS%E227
      RES%E137 = LHS*RHS%E137
      RES%E237 = LHS*RHS%E237
      RES%E337 = LHS*RHS%E337
      RES%E147 = LHS*RHS%E147
      RES%E247 = LHS*RHS%E247
      RES%E347 = LHS*RHS%E347
      RES%E447 = LHS*RHS%E447
      RES%E157 = LHS*RHS%E157
      RES%E257 = LHS*RHS%E257
      RES%E357 = LHS*RHS%E357
      RES%E457 = LHS*RHS%E457
      RES%E557 = LHS*RHS%E557
      RES%E167 = LHS*RHS%E167
      RES%E267 = LHS*RHS%E267
      RES%E367 = LHS*RHS%E367
      RES%E467 = LHS*RHS%E467
      RES%E567 = LHS*RHS%E567
      RES%E667 = LHS*RHS%E667
      RES%E177 = LHS*RHS%E177
      RES%E277 = LHS*RHS%E277
      RES%E377 = LHS*RHS%E377
      RES%E477 = LHS*RHS%E477
      RES%E577 = LHS*RHS%E577
      RES%E677 = LHS*RHS%E677
      RES%E777 = LHS*RHS%E777

   END FUNCTION ONUMM7N3_MUL_RO_SV

   FUNCTION ONUMM7N3_MUL_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1)) 

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

      ! Order 3
      RES%E111 = LHS%E111*RHS
      RES%E112 = LHS%E112*RHS
      RES%E122 = LHS%E122*RHS
      RES%E222 = LHS%E222*RHS
      RES%E113 = LHS%E113*RHS
      RES%E123 = LHS%E123*RHS
      RES%E223 = LHS%E223*RHS
      RES%E133 = LHS%E133*RHS
      RES%E233 = LHS%E233*RHS
      RES%E333 = LHS%E333*RHS
      RES%E114 = LHS%E114*RHS
      RES%E124 = LHS%E124*RHS
      RES%E224 = LHS%E224*RHS
      RES%E134 = LHS%E134*RHS
      RES%E234 = LHS%E234*RHS
      RES%E334 = LHS%E334*RHS
      RES%E144 = LHS%E144*RHS
      RES%E244 = LHS%E244*RHS
      RES%E344 = LHS%E344*RHS
      RES%E444 = LHS%E444*RHS
      RES%E115 = LHS%E115*RHS
      RES%E125 = LHS%E125*RHS
      RES%E225 = LHS%E225*RHS
      RES%E135 = LHS%E135*RHS
      RES%E235 = LHS%E235*RHS
      RES%E335 = LHS%E335*RHS
      RES%E145 = LHS%E145*RHS
      RES%E245 = LHS%E245*RHS
      RES%E345 = LHS%E345*RHS
      RES%E445 = LHS%E445*RHS
      RES%E155 = LHS%E155*RHS
      RES%E255 = LHS%E255*RHS
      RES%E355 = LHS%E355*RHS
      RES%E455 = LHS%E455*RHS
      RES%E555 = LHS%E555*RHS
      RES%E116 = LHS%E116*RHS
      RES%E126 = LHS%E126*RHS
      RES%E226 = LHS%E226*RHS
      RES%E136 = LHS%E136*RHS
      RES%E236 = LHS%E236*RHS
      RES%E336 = LHS%E336*RHS
      RES%E146 = LHS%E146*RHS
      RES%E246 = LHS%E246*RHS
      RES%E346 = LHS%E346*RHS
      RES%E446 = LHS%E446*RHS
      RES%E156 = LHS%E156*RHS
      RES%E256 = LHS%E256*RHS
      RES%E356 = LHS%E356*RHS
      RES%E456 = LHS%E456*RHS
      RES%E556 = LHS%E556*RHS
      RES%E166 = LHS%E166*RHS
      RES%E266 = LHS%E266*RHS
      RES%E366 = LHS%E366*RHS
      RES%E466 = LHS%E466*RHS
      RES%E566 = LHS%E566*RHS
      RES%E666 = LHS%E666*RHS
      RES%E117 = LHS%E117*RHS
      RES%E127 = LHS%E127*RHS
      RES%E227 = LHS%E227*RHS
      RES%E137 = LHS%E137*RHS
      RES%E237 = LHS%E237*RHS
      RES%E337 = LHS%E337*RHS
      RES%E147 = LHS%E147*RHS
      RES%E247 = LHS%E247*RHS
      RES%E347 = LHS%E347*RHS
      RES%E447 = LHS%E447*RHS
      RES%E157 = LHS%E157*RHS
      RES%E257 = LHS%E257*RHS
      RES%E357 = LHS%E357*RHS
      RES%E457 = LHS%E457*RHS
      RES%E557 = LHS%E557*RHS
      RES%E167 = LHS%E167*RHS
      RES%E267 = LHS%E267*RHS
      RES%E367 = LHS%E367*RHS
      RES%E467 = LHS%E467*RHS
      RES%E567 = LHS%E567*RHS
      RES%E667 = LHS%E667*RHS
      RES%E177 = LHS%E177*RHS
      RES%E277 = LHS%E277*RHS
      RES%E377 = LHS%E377*RHS
      RES%E477 = LHS%E477*RHS
      RES%E577 = LHS%E577*RHS
      RES%E677 = LHS%E677*RHS
      RES%E777 = LHS%E777*RHS

   END FUNCTION ONUMM7N3_MUL_OR_SV

   FUNCTION ONUMM7N3_ADD_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111
      RES%E112 = LHS%E112 + RHS%E112
      RES%E122 = LHS%E122 + RHS%E122
      RES%E222 = LHS%E222 + RHS%E222
      RES%E113 = LHS%E113 + RHS%E113
      RES%E123 = LHS%E123 + RHS%E123
      RES%E223 = LHS%E223 + RHS%E223
      RES%E133 = LHS%E133 + RHS%E133
      RES%E233 = LHS%E233 + RHS%E233
      RES%E333 = LHS%E333 + RHS%E333
      RES%E114 = LHS%E114 + RHS%E114
      RES%E124 = LHS%E124 + RHS%E124
      RES%E224 = LHS%E224 + RHS%E224
      RES%E134 = LHS%E134 + RHS%E134
      RES%E234 = LHS%E234 + RHS%E234
      RES%E334 = LHS%E334 + RHS%E334
      RES%E144 = LHS%E144 + RHS%E144
      RES%E244 = LHS%E244 + RHS%E244
      RES%E344 = LHS%E344 + RHS%E344
      RES%E444 = LHS%E444 + RHS%E444
      RES%E115 = LHS%E115 + RHS%E115
      RES%E125 = LHS%E125 + RHS%E125
      RES%E225 = LHS%E225 + RHS%E225
      RES%E135 = LHS%E135 + RHS%E135
      RES%E235 = LHS%E235 + RHS%E235
      RES%E335 = LHS%E335 + RHS%E335
      RES%E145 = LHS%E145 + RHS%E145
      RES%E245 = LHS%E245 + RHS%E245
      RES%E345 = LHS%E345 + RHS%E345
      RES%E445 = LHS%E445 + RHS%E445
      RES%E155 = LHS%E155 + RHS%E155
      RES%E255 = LHS%E255 + RHS%E255
      RES%E355 = LHS%E355 + RHS%E355
      RES%E455 = LHS%E455 + RHS%E455
      RES%E555 = LHS%E555 + RHS%E555
      RES%E116 = LHS%E116 + RHS%E116
      RES%E126 = LHS%E126 + RHS%E126
      RES%E226 = LHS%E226 + RHS%E226
      RES%E136 = LHS%E136 + RHS%E136
      RES%E236 = LHS%E236 + RHS%E236
      RES%E336 = LHS%E336 + RHS%E336
      RES%E146 = LHS%E146 + RHS%E146
      RES%E246 = LHS%E246 + RHS%E246
      RES%E346 = LHS%E346 + RHS%E346
      RES%E446 = LHS%E446 + RHS%E446
      RES%E156 = LHS%E156 + RHS%E156
      RES%E256 = LHS%E256 + RHS%E256
      RES%E356 = LHS%E356 + RHS%E356
      RES%E456 = LHS%E456 + RHS%E456
      RES%E556 = LHS%E556 + RHS%E556
      RES%E166 = LHS%E166 + RHS%E166
      RES%E266 = LHS%E266 + RHS%E266
      RES%E366 = LHS%E366 + RHS%E366
      RES%E466 = LHS%E466 + RHS%E466
      RES%E566 = LHS%E566 + RHS%E566
      RES%E666 = LHS%E666 + RHS%E666
      RES%E117 = LHS%E117 + RHS%E117
      RES%E127 = LHS%E127 + RHS%E127
      RES%E227 = LHS%E227 + RHS%E227
      RES%E137 = LHS%E137 + RHS%E137
      RES%E237 = LHS%E237 + RHS%E237
      RES%E337 = LHS%E337 + RHS%E337
      RES%E147 = LHS%E147 + RHS%E147
      RES%E247 = LHS%E247 + RHS%E247
      RES%E347 = LHS%E347 + RHS%E347
      RES%E447 = LHS%E447 + RHS%E447
      RES%E157 = LHS%E157 + RHS%E157
      RES%E257 = LHS%E257 + RHS%E257
      RES%E357 = LHS%E357 + RHS%E357
      RES%E457 = LHS%E457 + RHS%E457
      RES%E557 = LHS%E557 + RHS%E557
      RES%E167 = LHS%E167 + RHS%E167
      RES%E267 = LHS%E267 + RHS%E267
      RES%E367 = LHS%E367 + RHS%E367
      RES%E467 = LHS%E467 + RHS%E467
      RES%E567 = LHS%E567 + RHS%E567
      RES%E667 = LHS%E667 + RHS%E667
      RES%E177 = LHS%E177 + RHS%E177
      RES%E277 = LHS%E277 + RHS%E277
      RES%E377 = LHS%E377 + RHS%E377
      RES%E477 = LHS%E477 + RHS%E477
      RES%E577 = LHS%E577 + RHS%E577
      RES%E677 = LHS%E677 + RHS%E677
      RES%E777 = LHS%E777 + RHS%E777

   END FUNCTION ONUMM7N3_ADD_OO_SM

   FUNCTION ONUMM7N3_ADD_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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

      ! Order 3
      RES%E111 =  + RHS%E111
      RES%E112 =  + RHS%E112
      RES%E122 =  + RHS%E122
      RES%E222 =  + RHS%E222
      RES%E113 =  + RHS%E113
      RES%E123 =  + RHS%E123
      RES%E223 =  + RHS%E223
      RES%E133 =  + RHS%E133
      RES%E233 =  + RHS%E233
      RES%E333 =  + RHS%E333
      RES%E114 =  + RHS%E114
      RES%E124 =  + RHS%E124
      RES%E224 =  + RHS%E224
      RES%E134 =  + RHS%E134
      RES%E234 =  + RHS%E234
      RES%E334 =  + RHS%E334
      RES%E144 =  + RHS%E144
      RES%E244 =  + RHS%E244
      RES%E344 =  + RHS%E344
      RES%E444 =  + RHS%E444
      RES%E115 =  + RHS%E115
      RES%E125 =  + RHS%E125
      RES%E225 =  + RHS%E225
      RES%E135 =  + RHS%E135
      RES%E235 =  + RHS%E235
      RES%E335 =  + RHS%E335
      RES%E145 =  + RHS%E145
      RES%E245 =  + RHS%E245
      RES%E345 =  + RHS%E345
      RES%E445 =  + RHS%E445
      RES%E155 =  + RHS%E155
      RES%E255 =  + RHS%E255
      RES%E355 =  + RHS%E355
      RES%E455 =  + RHS%E455
      RES%E555 =  + RHS%E555
      RES%E116 =  + RHS%E116
      RES%E126 =  + RHS%E126
      RES%E226 =  + RHS%E226
      RES%E136 =  + RHS%E136
      RES%E236 =  + RHS%E236
      RES%E336 =  + RHS%E336
      RES%E146 =  + RHS%E146
      RES%E246 =  + RHS%E246
      RES%E346 =  + RHS%E346
      RES%E446 =  + RHS%E446
      RES%E156 =  + RHS%E156
      RES%E256 =  + RHS%E256
      RES%E356 =  + RHS%E356
      RES%E456 =  + RHS%E456
      RES%E556 =  + RHS%E556
      RES%E166 =  + RHS%E166
      RES%E266 =  + RHS%E266
      RES%E366 =  + RHS%E366
      RES%E466 =  + RHS%E466
      RES%E566 =  + RHS%E566
      RES%E666 =  + RHS%E666
      RES%E117 =  + RHS%E117
      RES%E127 =  + RHS%E127
      RES%E227 =  + RHS%E227
      RES%E137 =  + RHS%E137
      RES%E237 =  + RHS%E237
      RES%E337 =  + RHS%E337
      RES%E147 =  + RHS%E147
      RES%E247 =  + RHS%E247
      RES%E347 =  + RHS%E347
      RES%E447 =  + RHS%E447
      RES%E157 =  + RHS%E157
      RES%E257 =  + RHS%E257
      RES%E357 =  + RHS%E357
      RES%E457 =  + RHS%E457
      RES%E557 =  + RHS%E557
      RES%E167 =  + RHS%E167
      RES%E267 =  + RHS%E267
      RES%E367 =  + RHS%E367
      RES%E467 =  + RHS%E467
      RES%E567 =  + RHS%E567
      RES%E667 =  + RHS%E667
      RES%E177 =  + RHS%E177
      RES%E277 =  + RHS%E277
      RES%E377 =  + RHS%E377
      RES%E477 =  + RHS%E477
      RES%E577 =  + RHS%E577
      RES%E677 =  + RHS%E677
      RES%E777 =  + RHS%E777

   END FUNCTION ONUMM7N3_ADD_RO_SM

   FUNCTION ONUMM7N3_ADD_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E112 = LHS%E112
      RES%E122 = LHS%E122
      RES%E222 = LHS%E222
      RES%E113 = LHS%E113
      RES%E123 = LHS%E123
      RES%E223 = LHS%E223
      RES%E133 = LHS%E133
      RES%E233 = LHS%E233
      RES%E333 = LHS%E333
      RES%E114 = LHS%E114
      RES%E124 = LHS%E124
      RES%E224 = LHS%E224
      RES%E134 = LHS%E134
      RES%E234 = LHS%E234
      RES%E334 = LHS%E334
      RES%E144 = LHS%E144
      RES%E244 = LHS%E244
      RES%E344 = LHS%E344
      RES%E444 = LHS%E444
      RES%E115 = LHS%E115
      RES%E125 = LHS%E125
      RES%E225 = LHS%E225
      RES%E135 = LHS%E135
      RES%E235 = LHS%E235
      RES%E335 = LHS%E335
      RES%E145 = LHS%E145
      RES%E245 = LHS%E245
      RES%E345 = LHS%E345
      RES%E445 = LHS%E445
      RES%E155 = LHS%E155
      RES%E255 = LHS%E255
      RES%E355 = LHS%E355
      RES%E455 = LHS%E455
      RES%E555 = LHS%E555
      RES%E116 = LHS%E116
      RES%E126 = LHS%E126
      RES%E226 = LHS%E226
      RES%E136 = LHS%E136
      RES%E236 = LHS%E236
      RES%E336 = LHS%E336
      RES%E146 = LHS%E146
      RES%E246 = LHS%E246
      RES%E346 = LHS%E346
      RES%E446 = LHS%E446
      RES%E156 = LHS%E156
      RES%E256 = LHS%E256
      RES%E356 = LHS%E356
      RES%E456 = LHS%E456
      RES%E556 = LHS%E556
      RES%E166 = LHS%E166
      RES%E266 = LHS%E266
      RES%E366 = LHS%E366
      RES%E466 = LHS%E466
      RES%E566 = LHS%E566
      RES%E666 = LHS%E666
      RES%E117 = LHS%E117
      RES%E127 = LHS%E127
      RES%E227 = LHS%E227
      RES%E137 = LHS%E137
      RES%E237 = LHS%E237
      RES%E337 = LHS%E337
      RES%E147 = LHS%E147
      RES%E247 = LHS%E247
      RES%E347 = LHS%E347
      RES%E447 = LHS%E447
      RES%E157 = LHS%E157
      RES%E257 = LHS%E257
      RES%E357 = LHS%E357
      RES%E457 = LHS%E457
      RES%E557 = LHS%E557
      RES%E167 = LHS%E167
      RES%E267 = LHS%E267
      RES%E367 = LHS%E367
      RES%E467 = LHS%E467
      RES%E567 = LHS%E567
      RES%E667 = LHS%E667
      RES%E177 = LHS%E177
      RES%E277 = LHS%E277
      RES%E377 = LHS%E377
      RES%E477 = LHS%E477
      RES%E577 = LHS%E577
      RES%E677 = LHS%E677
      RES%E777 = LHS%E777

   END FUNCTION ONUMM7N3_ADD_OR_SM

   FUNCTION ONUMM7N3_SUB_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111
      RES%E112 = LHS%E112 - RHS%E112
      RES%E122 = LHS%E122 - RHS%E122
      RES%E222 = LHS%E222 - RHS%E222
      RES%E113 = LHS%E113 - RHS%E113
      RES%E123 = LHS%E123 - RHS%E123
      RES%E223 = LHS%E223 - RHS%E223
      RES%E133 = LHS%E133 - RHS%E133
      RES%E233 = LHS%E233 - RHS%E233
      RES%E333 = LHS%E333 - RHS%E333
      RES%E114 = LHS%E114 - RHS%E114
      RES%E124 = LHS%E124 - RHS%E124
      RES%E224 = LHS%E224 - RHS%E224
      RES%E134 = LHS%E134 - RHS%E134
      RES%E234 = LHS%E234 - RHS%E234
      RES%E334 = LHS%E334 - RHS%E334
      RES%E144 = LHS%E144 - RHS%E144
      RES%E244 = LHS%E244 - RHS%E244
      RES%E344 = LHS%E344 - RHS%E344
      RES%E444 = LHS%E444 - RHS%E444
      RES%E115 = LHS%E115 - RHS%E115
      RES%E125 = LHS%E125 - RHS%E125
      RES%E225 = LHS%E225 - RHS%E225
      RES%E135 = LHS%E135 - RHS%E135
      RES%E235 = LHS%E235 - RHS%E235
      RES%E335 = LHS%E335 - RHS%E335
      RES%E145 = LHS%E145 - RHS%E145
      RES%E245 = LHS%E245 - RHS%E245
      RES%E345 = LHS%E345 - RHS%E345
      RES%E445 = LHS%E445 - RHS%E445
      RES%E155 = LHS%E155 - RHS%E155
      RES%E255 = LHS%E255 - RHS%E255
      RES%E355 = LHS%E355 - RHS%E355
      RES%E455 = LHS%E455 - RHS%E455
      RES%E555 = LHS%E555 - RHS%E555
      RES%E116 = LHS%E116 - RHS%E116
      RES%E126 = LHS%E126 - RHS%E126
      RES%E226 = LHS%E226 - RHS%E226
      RES%E136 = LHS%E136 - RHS%E136
      RES%E236 = LHS%E236 - RHS%E236
      RES%E336 = LHS%E336 - RHS%E336
      RES%E146 = LHS%E146 - RHS%E146
      RES%E246 = LHS%E246 - RHS%E246
      RES%E346 = LHS%E346 - RHS%E346
      RES%E446 = LHS%E446 - RHS%E446
      RES%E156 = LHS%E156 - RHS%E156
      RES%E256 = LHS%E256 - RHS%E256
      RES%E356 = LHS%E356 - RHS%E356
      RES%E456 = LHS%E456 - RHS%E456
      RES%E556 = LHS%E556 - RHS%E556
      RES%E166 = LHS%E166 - RHS%E166
      RES%E266 = LHS%E266 - RHS%E266
      RES%E366 = LHS%E366 - RHS%E366
      RES%E466 = LHS%E466 - RHS%E466
      RES%E566 = LHS%E566 - RHS%E566
      RES%E666 = LHS%E666 - RHS%E666
      RES%E117 = LHS%E117 - RHS%E117
      RES%E127 = LHS%E127 - RHS%E127
      RES%E227 = LHS%E227 - RHS%E227
      RES%E137 = LHS%E137 - RHS%E137
      RES%E237 = LHS%E237 - RHS%E237
      RES%E337 = LHS%E337 - RHS%E337
      RES%E147 = LHS%E147 - RHS%E147
      RES%E247 = LHS%E247 - RHS%E247
      RES%E347 = LHS%E347 - RHS%E347
      RES%E447 = LHS%E447 - RHS%E447
      RES%E157 = LHS%E157 - RHS%E157
      RES%E257 = LHS%E257 - RHS%E257
      RES%E357 = LHS%E357 - RHS%E357
      RES%E457 = LHS%E457 - RHS%E457
      RES%E557 = LHS%E557 - RHS%E557
      RES%E167 = LHS%E167 - RHS%E167
      RES%E267 = LHS%E267 - RHS%E267
      RES%E367 = LHS%E367 - RHS%E367
      RES%E467 = LHS%E467 - RHS%E467
      RES%E567 = LHS%E567 - RHS%E567
      RES%E667 = LHS%E667 - RHS%E667
      RES%E177 = LHS%E177 - RHS%E177
      RES%E277 = LHS%E277 - RHS%E277
      RES%E377 = LHS%E377 - RHS%E377
      RES%E477 = LHS%E477 - RHS%E477
      RES%E577 = LHS%E577 - RHS%E577
      RES%E677 = LHS%E677 - RHS%E677
      RES%E777 = LHS%E777 - RHS%E777

   END FUNCTION ONUMM7N3_SUB_OO_SM

   FUNCTION ONUMM7N3_SUB_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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

      ! Order 3
      RES%E111 =  - RHS%E111
      RES%E112 =  - RHS%E112
      RES%E122 =  - RHS%E122
      RES%E222 =  - RHS%E222
      RES%E113 =  - RHS%E113
      RES%E123 =  - RHS%E123
      RES%E223 =  - RHS%E223
      RES%E133 =  - RHS%E133
      RES%E233 =  - RHS%E233
      RES%E333 =  - RHS%E333
      RES%E114 =  - RHS%E114
      RES%E124 =  - RHS%E124
      RES%E224 =  - RHS%E224
      RES%E134 =  - RHS%E134
      RES%E234 =  - RHS%E234
      RES%E334 =  - RHS%E334
      RES%E144 =  - RHS%E144
      RES%E244 =  - RHS%E244
      RES%E344 =  - RHS%E344
      RES%E444 =  - RHS%E444
      RES%E115 =  - RHS%E115
      RES%E125 =  - RHS%E125
      RES%E225 =  - RHS%E225
      RES%E135 =  - RHS%E135
      RES%E235 =  - RHS%E235
      RES%E335 =  - RHS%E335
      RES%E145 =  - RHS%E145
      RES%E245 =  - RHS%E245
      RES%E345 =  - RHS%E345
      RES%E445 =  - RHS%E445
      RES%E155 =  - RHS%E155
      RES%E255 =  - RHS%E255
      RES%E355 =  - RHS%E355
      RES%E455 =  - RHS%E455
      RES%E555 =  - RHS%E555
      RES%E116 =  - RHS%E116
      RES%E126 =  - RHS%E126
      RES%E226 =  - RHS%E226
      RES%E136 =  - RHS%E136
      RES%E236 =  - RHS%E236
      RES%E336 =  - RHS%E336
      RES%E146 =  - RHS%E146
      RES%E246 =  - RHS%E246
      RES%E346 =  - RHS%E346
      RES%E446 =  - RHS%E446
      RES%E156 =  - RHS%E156
      RES%E256 =  - RHS%E256
      RES%E356 =  - RHS%E356
      RES%E456 =  - RHS%E456
      RES%E556 =  - RHS%E556
      RES%E166 =  - RHS%E166
      RES%E266 =  - RHS%E266
      RES%E366 =  - RHS%E366
      RES%E466 =  - RHS%E466
      RES%E566 =  - RHS%E566
      RES%E666 =  - RHS%E666
      RES%E117 =  - RHS%E117
      RES%E127 =  - RHS%E127
      RES%E227 =  - RHS%E227
      RES%E137 =  - RHS%E137
      RES%E237 =  - RHS%E237
      RES%E337 =  - RHS%E337
      RES%E147 =  - RHS%E147
      RES%E247 =  - RHS%E247
      RES%E347 =  - RHS%E347
      RES%E447 =  - RHS%E447
      RES%E157 =  - RHS%E157
      RES%E257 =  - RHS%E257
      RES%E357 =  - RHS%E357
      RES%E457 =  - RHS%E457
      RES%E557 =  - RHS%E557
      RES%E167 =  - RHS%E167
      RES%E267 =  - RHS%E267
      RES%E367 =  - RHS%E367
      RES%E467 =  - RHS%E467
      RES%E567 =  - RHS%E567
      RES%E667 =  - RHS%E667
      RES%E177 =  - RHS%E177
      RES%E277 =  - RHS%E277
      RES%E377 =  - RHS%E377
      RES%E477 =  - RHS%E477
      RES%E577 =  - RHS%E577
      RES%E677 =  - RHS%E677
      RES%E777 =  - RHS%E777

   END FUNCTION ONUMM7N3_SUB_RO_SM

   FUNCTION ONUMM7N3_SUB_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111
      RES%E112 = LHS%E112
      RES%E122 = LHS%E122
      RES%E222 = LHS%E222
      RES%E113 = LHS%E113
      RES%E123 = LHS%E123
      RES%E223 = LHS%E223
      RES%E133 = LHS%E133
      RES%E233 = LHS%E233
      RES%E333 = LHS%E333
      RES%E114 = LHS%E114
      RES%E124 = LHS%E124
      RES%E224 = LHS%E224
      RES%E134 = LHS%E134
      RES%E234 = LHS%E234
      RES%E334 = LHS%E334
      RES%E144 = LHS%E144
      RES%E244 = LHS%E244
      RES%E344 = LHS%E344
      RES%E444 = LHS%E444
      RES%E115 = LHS%E115
      RES%E125 = LHS%E125
      RES%E225 = LHS%E225
      RES%E135 = LHS%E135
      RES%E235 = LHS%E235
      RES%E335 = LHS%E335
      RES%E145 = LHS%E145
      RES%E245 = LHS%E245
      RES%E345 = LHS%E345
      RES%E445 = LHS%E445
      RES%E155 = LHS%E155
      RES%E255 = LHS%E255
      RES%E355 = LHS%E355
      RES%E455 = LHS%E455
      RES%E555 = LHS%E555
      RES%E116 = LHS%E116
      RES%E126 = LHS%E126
      RES%E226 = LHS%E226
      RES%E136 = LHS%E136
      RES%E236 = LHS%E236
      RES%E336 = LHS%E336
      RES%E146 = LHS%E146
      RES%E246 = LHS%E246
      RES%E346 = LHS%E346
      RES%E446 = LHS%E446
      RES%E156 = LHS%E156
      RES%E256 = LHS%E256
      RES%E356 = LHS%E356
      RES%E456 = LHS%E456
      RES%E556 = LHS%E556
      RES%E166 = LHS%E166
      RES%E266 = LHS%E266
      RES%E366 = LHS%E366
      RES%E466 = LHS%E466
      RES%E566 = LHS%E566
      RES%E666 = LHS%E666
      RES%E117 = LHS%E117
      RES%E127 = LHS%E127
      RES%E227 = LHS%E227
      RES%E137 = LHS%E137
      RES%E237 = LHS%E237
      RES%E337 = LHS%E337
      RES%E147 = LHS%E147
      RES%E247 = LHS%E247
      RES%E347 = LHS%E347
      RES%E447 = LHS%E447
      RES%E157 = LHS%E157
      RES%E257 = LHS%E257
      RES%E357 = LHS%E357
      RES%E457 = LHS%E457
      RES%E557 = LHS%E557
      RES%E167 = LHS%E167
      RES%E267 = LHS%E267
      RES%E367 = LHS%E367
      RES%E467 = LHS%E467
      RES%E567 = LHS%E567
      RES%E667 = LHS%E667
      RES%E177 = LHS%E177
      RES%E277 = LHS%E277
      RES%E377 = LHS%E377
      RES%E477 = LHS%E477
      RES%E577 = LHS%E577
      RES%E677 = LHS%E677
      RES%E777 = LHS%E777

   END FUNCTION ONUMM7N3_SUB_OR_SM

   FUNCTION ONUMM7N3_MUL_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 3
      RES%E111 = LHS%R*RHS%E111 + LHS%E111*RHS%R +  &
              LHS%E1*RHS%E11 + LHS%E11*RHS%E1
      RES%E112 = LHS%R*RHS%E112 + LHS%E112*RHS%R +  &
              LHS%E1*RHS%E12 + LHS%E12*RHS%E1 + LHS%E2*RHS%E11 + LHS%E11*RHS%E2
      RES%E122 = LHS%R*RHS%E122 + LHS%E122*RHS%R +  &
              LHS%E1*RHS%E22 + LHS%E22*RHS%E1 + LHS%E2*RHS%E12 + LHS%E12*RHS%E2
      RES%E222 = LHS%R*RHS%E222 + LHS%E222*RHS%R +  &
              LHS%E2*RHS%E22 + LHS%E22*RHS%E2
      RES%E113 = LHS%R*RHS%E113 + LHS%E113*RHS%R +  &
              LHS%E1*RHS%E13 + LHS%E13*RHS%E1 + LHS%E3*RHS%E11 + LHS%E11*RHS%E3
      RES%E123 = LHS%R*RHS%E123 + LHS%E123*RHS%R +  &
              LHS%E1*RHS%E23 + LHS%E23*RHS%E1 + LHS%E2*RHS%E13 +  &
              LHS%E13*RHS%E2 + LHS%E3*RHS%E12 + LHS%E12*RHS%E3
      RES%E223 = LHS%R*RHS%E223 + LHS%E223*RHS%R +  &
              LHS%E2*RHS%E23 + LHS%E23*RHS%E2 + LHS%E3*RHS%E22 + LHS%E22*RHS%E3
      RES%E133 = LHS%R*RHS%E133 + LHS%E133*RHS%R +  &
              LHS%E1*RHS%E33 + LHS%E33*RHS%E1 + LHS%E3*RHS%E13 + LHS%E13*RHS%E3
      RES%E233 = LHS%R*RHS%E233 + LHS%E233*RHS%R +  &
              LHS%E2*RHS%E33 + LHS%E33*RHS%E2 + LHS%E3*RHS%E23 + LHS%E23*RHS%E3
      RES%E333 = LHS%R*RHS%E333 + LHS%E333*RHS%R +  &
              LHS%E3*RHS%E33 + LHS%E33*RHS%E3
      RES%E114 = LHS%R*RHS%E114 + LHS%E114*RHS%R +  &
              LHS%E1*RHS%E14 + LHS%E14*RHS%E1 + LHS%E4*RHS%E11 + LHS%E11*RHS%E4
      RES%E124 = LHS%R*RHS%E124 + LHS%E124*RHS%R +  &
              LHS%E1*RHS%E24 + LHS%E24*RHS%E1 + LHS%E2*RHS%E14 +  &
              LHS%E14*RHS%E2 + LHS%E4*RHS%E12 + LHS%E12*RHS%E4
      RES%E224 = LHS%R*RHS%E224 + LHS%E224*RHS%R +  &
              LHS%E2*RHS%E24 + LHS%E24*RHS%E2 + LHS%E4*RHS%E22 + LHS%E22*RHS%E4
      RES%E134 = LHS%R*RHS%E134 + LHS%E134*RHS%R +  &
              LHS%E1*RHS%E34 + LHS%E34*RHS%E1 + LHS%E3*RHS%E14 +  &
              LHS%E14*RHS%E3 + LHS%E4*RHS%E13 + LHS%E13*RHS%E4
      RES%E234 = LHS%R*RHS%E234 + LHS%E234*RHS%R +  &
              LHS%E2*RHS%E34 + LHS%E34*RHS%E2 + LHS%E3*RHS%E24 +  &
              LHS%E24*RHS%E3 + LHS%E4*RHS%E23 + LHS%E23*RHS%E4
      RES%E334 = LHS%R*RHS%E334 + LHS%E334*RHS%R +  &
              LHS%E3*RHS%E34 + LHS%E34*RHS%E3 + LHS%E4*RHS%E33 + LHS%E33*RHS%E4
      RES%E144 = LHS%R*RHS%E144 + LHS%E144*RHS%R +  &
              LHS%E1*RHS%E44 + LHS%E44*RHS%E1 + LHS%E4*RHS%E14 + LHS%E14*RHS%E4
      RES%E244 = LHS%R*RHS%E244 + LHS%E244*RHS%R +  &
              LHS%E2*RHS%E44 + LHS%E44*RHS%E2 + LHS%E4*RHS%E24 + LHS%E24*RHS%E4
      RES%E344 = LHS%R*RHS%E344 + LHS%E344*RHS%R +  &
              LHS%E3*RHS%E44 + LHS%E44*RHS%E3 + LHS%E4*RHS%E34 + LHS%E34*RHS%E4
      RES%E444 = LHS%R*RHS%E444 + LHS%E444*RHS%R +  &
              LHS%E4*RHS%E44 + LHS%E44*RHS%E4
      RES%E115 = LHS%R*RHS%E115 + LHS%E115*RHS%R +  &
              LHS%E1*RHS%E15 + LHS%E15*RHS%E1 + LHS%E5*RHS%E11 + LHS%E11*RHS%E5
      RES%E125 = LHS%R*RHS%E125 + LHS%E125*RHS%R +  &
              LHS%E1*RHS%E25 + LHS%E25*RHS%E1 + LHS%E2*RHS%E15 +  &
              LHS%E15*RHS%E2 + LHS%E5*RHS%E12 + LHS%E12*RHS%E5
      RES%E225 = LHS%R*RHS%E225 + LHS%E225*RHS%R +  &
              LHS%E2*RHS%E25 + LHS%E25*RHS%E2 + LHS%E5*RHS%E22 + LHS%E22*RHS%E5
      RES%E135 = LHS%R*RHS%E135 + LHS%E135*RHS%R +  &
              LHS%E1*RHS%E35 + LHS%E35*RHS%E1 + LHS%E3*RHS%E15 +  &
              LHS%E15*RHS%E3 + LHS%E5*RHS%E13 + LHS%E13*RHS%E5
      RES%E235 = LHS%R*RHS%E235 + LHS%E235*RHS%R +  &
              LHS%E2*RHS%E35 + LHS%E35*RHS%E2 + LHS%E3*RHS%E25 +  &
              LHS%E25*RHS%E3 + LHS%E5*RHS%E23 + LHS%E23*RHS%E5
      RES%E335 = LHS%R*RHS%E335 + LHS%E335*RHS%R +  &
              LHS%E3*RHS%E35 + LHS%E35*RHS%E3 + LHS%E5*RHS%E33 + LHS%E33*RHS%E5
      RES%E145 = LHS%R*RHS%E145 + LHS%E145*RHS%R +  &
              LHS%E1*RHS%E45 + LHS%E45*RHS%E1 + LHS%E4*RHS%E15 +  &
              LHS%E15*RHS%E4 + LHS%E5*RHS%E14 + LHS%E14*RHS%E5
      RES%E245 = LHS%R*RHS%E245 + LHS%E245*RHS%R +  &
              LHS%E2*RHS%E45 + LHS%E45*RHS%E2 + LHS%E4*RHS%E25 +  &
              LHS%E25*RHS%E4 + LHS%E5*RHS%E24 + LHS%E24*RHS%E5
      RES%E345 = LHS%R*RHS%E345 + LHS%E345*RHS%R +  &
              LHS%E3*RHS%E45 + LHS%E45*RHS%E3 + LHS%E4*RHS%E35 +  &
              LHS%E35*RHS%E4 + LHS%E5*RHS%E34 + LHS%E34*RHS%E5
      RES%E445 = LHS%R*RHS%E445 + LHS%E445*RHS%R +  &
              LHS%E4*RHS%E45 + LHS%E45*RHS%E4 + LHS%E5*RHS%E44 + LHS%E44*RHS%E5
      RES%E155 = LHS%R*RHS%E155 + LHS%E155*RHS%R +  &
              LHS%E1*RHS%E55 + LHS%E55*RHS%E1 + LHS%E5*RHS%E15 + LHS%E15*RHS%E5
      RES%E255 = LHS%R*RHS%E255 + LHS%E255*RHS%R +  &
              LHS%E2*RHS%E55 + LHS%E55*RHS%E2 + LHS%E5*RHS%E25 + LHS%E25*RHS%E5
      RES%E355 = LHS%R*RHS%E355 + LHS%E355*RHS%R +  &
              LHS%E3*RHS%E55 + LHS%E55*RHS%E3 + LHS%E5*RHS%E35 + LHS%E35*RHS%E5
      RES%E455 = LHS%R*RHS%E455 + LHS%E455*RHS%R +  &
              LHS%E4*RHS%E55 + LHS%E55*RHS%E4 + LHS%E5*RHS%E45 + LHS%E45*RHS%E5
      RES%E555 = LHS%R*RHS%E555 + LHS%E555*RHS%R +  &
              LHS%E5*RHS%E55 + LHS%E55*RHS%E5
      RES%E116 = LHS%R*RHS%E116 + LHS%E116*RHS%R +  &
              LHS%E1*RHS%E16 + LHS%E16*RHS%E1 + LHS%E6*RHS%E11 + LHS%E11*RHS%E6
      RES%E126 = LHS%R*RHS%E126 + LHS%E126*RHS%R +  &
              LHS%E1*RHS%E26 + LHS%E26*RHS%E1 + LHS%E2*RHS%E16 +  &
              LHS%E16*RHS%E2 + LHS%E6*RHS%E12 + LHS%E12*RHS%E6
      RES%E226 = LHS%R*RHS%E226 + LHS%E226*RHS%R +  &
              LHS%E2*RHS%E26 + LHS%E26*RHS%E2 + LHS%E6*RHS%E22 + LHS%E22*RHS%E6
      RES%E136 = LHS%R*RHS%E136 + LHS%E136*RHS%R +  &
              LHS%E1*RHS%E36 + LHS%E36*RHS%E1 + LHS%E3*RHS%E16 +  &
              LHS%E16*RHS%E3 + LHS%E6*RHS%E13 + LHS%E13*RHS%E6
      RES%E236 = LHS%R*RHS%E236 + LHS%E236*RHS%R +  &
              LHS%E2*RHS%E36 + LHS%E36*RHS%E2 + LHS%E3*RHS%E26 +  &
              LHS%E26*RHS%E3 + LHS%E6*RHS%E23 + LHS%E23*RHS%E6
      RES%E336 = LHS%R*RHS%E336 + LHS%E336*RHS%R +  &
              LHS%E3*RHS%E36 + LHS%E36*RHS%E3 + LHS%E6*RHS%E33 + LHS%E33*RHS%E6
      RES%E146 = LHS%R*RHS%E146 + LHS%E146*RHS%R +  &
              LHS%E1*RHS%E46 + LHS%E46*RHS%E1 + LHS%E4*RHS%E16 +  &
              LHS%E16*RHS%E4 + LHS%E6*RHS%E14 + LHS%E14*RHS%E6
      RES%E246 = LHS%R*RHS%E246 + LHS%E246*RHS%R +  &
              LHS%E2*RHS%E46 + LHS%E46*RHS%E2 + LHS%E4*RHS%E26 +  &
              LHS%E26*RHS%E4 + LHS%E6*RHS%E24 + LHS%E24*RHS%E6
      RES%E346 = LHS%R*RHS%E346 + LHS%E346*RHS%R +  &
              LHS%E3*RHS%E46 + LHS%E46*RHS%E3 + LHS%E4*RHS%E36 +  &
              LHS%E36*RHS%E4 + LHS%E6*RHS%E34 + LHS%E34*RHS%E6
      RES%E446 = LHS%R*RHS%E446 + LHS%E446*RHS%R +  &
              LHS%E4*RHS%E46 + LHS%E46*RHS%E4 + LHS%E6*RHS%E44 + LHS%E44*RHS%E6
      RES%E156 = LHS%R*RHS%E156 + LHS%E156*RHS%R +  &
              LHS%E1*RHS%E56 + LHS%E56*RHS%E1 + LHS%E5*RHS%E16 +  &
              LHS%E16*RHS%E5 + LHS%E6*RHS%E15 + LHS%E15*RHS%E6
      RES%E256 = LHS%R*RHS%E256 + LHS%E256*RHS%R +  &
              LHS%E2*RHS%E56 + LHS%E56*RHS%E2 + LHS%E5*RHS%E26 +  &
              LHS%E26*RHS%E5 + LHS%E6*RHS%E25 + LHS%E25*RHS%E6
      RES%E356 = LHS%R*RHS%E356 + LHS%E356*RHS%R +  &
              LHS%E3*RHS%E56 + LHS%E56*RHS%E3 + LHS%E5*RHS%E36 +  &
              LHS%E36*RHS%E5 + LHS%E6*RHS%E35 + LHS%E35*RHS%E6
      RES%E456 = LHS%R*RHS%E456 + LHS%E456*RHS%R +  &
              LHS%E4*RHS%E56 + LHS%E56*RHS%E4 + LHS%E5*RHS%E46 +  &
              LHS%E46*RHS%E5 + LHS%E6*RHS%E45 + LHS%E45*RHS%E6
      RES%E556 = LHS%R*RHS%E556 + LHS%E556*RHS%R +  &
              LHS%E5*RHS%E56 + LHS%E56*RHS%E5 + LHS%E6*RHS%E55 + LHS%E55*RHS%E6
      RES%E166 = LHS%R*RHS%E166 + LHS%E166*RHS%R +  &
              LHS%E1*RHS%E66 + LHS%E66*RHS%E1 + LHS%E6*RHS%E16 + LHS%E16*RHS%E6
      RES%E266 = LHS%R*RHS%E266 + LHS%E266*RHS%R +  &
              LHS%E2*RHS%E66 + LHS%E66*RHS%E2 + LHS%E6*RHS%E26 + LHS%E26*RHS%E6
      RES%E366 = LHS%R*RHS%E366 + LHS%E366*RHS%R +  &
              LHS%E3*RHS%E66 + LHS%E66*RHS%E3 + LHS%E6*RHS%E36 + LHS%E36*RHS%E6
      RES%E466 = LHS%R*RHS%E466 + LHS%E466*RHS%R +  &
              LHS%E4*RHS%E66 + LHS%E66*RHS%E4 + LHS%E6*RHS%E46 + LHS%E46*RHS%E6
      RES%E566 = LHS%R*RHS%E566 + LHS%E566*RHS%R +  &
              LHS%E5*RHS%E66 + LHS%E66*RHS%E5 + LHS%E6*RHS%E56 + LHS%E56*RHS%E6
      RES%E666 = LHS%R*RHS%E666 + LHS%E666*RHS%R +  &
              LHS%E6*RHS%E66 + LHS%E66*RHS%E6
      RES%E117 = LHS%R*RHS%E117 + LHS%E117*RHS%R +  &
              LHS%E1*RHS%E17 + LHS%E17*RHS%E1 + LHS%E7*RHS%E11 + LHS%E11*RHS%E7
      RES%E127 = LHS%R*RHS%E127 + LHS%E127*RHS%R +  &
              LHS%E1*RHS%E27 + LHS%E27*RHS%E1 + LHS%E2*RHS%E17 +  &
              LHS%E17*RHS%E2 + LHS%E7*RHS%E12 + LHS%E12*RHS%E7
      RES%E227 = LHS%R*RHS%E227 + LHS%E227*RHS%R +  &
              LHS%E2*RHS%E27 + LHS%E27*RHS%E2 + LHS%E7*RHS%E22 + LHS%E22*RHS%E7
      RES%E137 = LHS%R*RHS%E137 + LHS%E137*RHS%R +  &
              LHS%E1*RHS%E37 + LHS%E37*RHS%E1 + LHS%E3*RHS%E17 +  &
              LHS%E17*RHS%E3 + LHS%E7*RHS%E13 + LHS%E13*RHS%E7
      RES%E237 = LHS%R*RHS%E237 + LHS%E237*RHS%R +  &
              LHS%E2*RHS%E37 + LHS%E37*RHS%E2 + LHS%E3*RHS%E27 +  &
              LHS%E27*RHS%E3 + LHS%E7*RHS%E23 + LHS%E23*RHS%E7
      RES%E337 = LHS%R*RHS%E337 + LHS%E337*RHS%R +  &
              LHS%E3*RHS%E37 + LHS%E37*RHS%E3 + LHS%E7*RHS%E33 + LHS%E33*RHS%E7
      RES%E147 = LHS%R*RHS%E147 + LHS%E147*RHS%R +  &
              LHS%E1*RHS%E47 + LHS%E47*RHS%E1 + LHS%E4*RHS%E17 +  &
              LHS%E17*RHS%E4 + LHS%E7*RHS%E14 + LHS%E14*RHS%E7
      RES%E247 = LHS%R*RHS%E247 + LHS%E247*RHS%R +  &
              LHS%E2*RHS%E47 + LHS%E47*RHS%E2 + LHS%E4*RHS%E27 +  &
              LHS%E27*RHS%E4 + LHS%E7*RHS%E24 + LHS%E24*RHS%E7
      RES%E347 = LHS%R*RHS%E347 + LHS%E347*RHS%R +  &
              LHS%E3*RHS%E47 + LHS%E47*RHS%E3 + LHS%E4*RHS%E37 +  &
              LHS%E37*RHS%E4 + LHS%E7*RHS%E34 + LHS%E34*RHS%E7
      RES%E447 = LHS%R*RHS%E447 + LHS%E447*RHS%R +  &
              LHS%E4*RHS%E47 + LHS%E47*RHS%E4 + LHS%E7*RHS%E44 + LHS%E44*RHS%E7
      RES%E157 = LHS%R*RHS%E157 + LHS%E157*RHS%R +  &
              LHS%E1*RHS%E57 + LHS%E57*RHS%E1 + LHS%E5*RHS%E17 +  &
              LHS%E17*RHS%E5 + LHS%E7*RHS%E15 + LHS%E15*RHS%E7
      RES%E257 = LHS%R*RHS%E257 + LHS%E257*RHS%R +  &
              LHS%E2*RHS%E57 + LHS%E57*RHS%E2 + LHS%E5*RHS%E27 +  &
              LHS%E27*RHS%E5 + LHS%E7*RHS%E25 + LHS%E25*RHS%E7
      RES%E357 = LHS%R*RHS%E357 + LHS%E357*RHS%R +  &
              LHS%E3*RHS%E57 + LHS%E57*RHS%E3 + LHS%E5*RHS%E37 +  &
              LHS%E37*RHS%E5 + LHS%E7*RHS%E35 + LHS%E35*RHS%E7
      RES%E457 = LHS%R*RHS%E457 + LHS%E457*RHS%R +  &
              LHS%E4*RHS%E57 + LHS%E57*RHS%E4 + LHS%E5*RHS%E47 +  &
              LHS%E47*RHS%E5 + LHS%E7*RHS%E45 + LHS%E45*RHS%E7
      RES%E557 = LHS%R*RHS%E557 + LHS%E557*RHS%R +  &
              LHS%E5*RHS%E57 + LHS%E57*RHS%E5 + LHS%E7*RHS%E55 + LHS%E55*RHS%E7
      RES%E167 = LHS%R*RHS%E167 + LHS%E167*RHS%R +  &
              LHS%E1*RHS%E67 + LHS%E67*RHS%E1 + LHS%E6*RHS%E17 +  &
              LHS%E17*RHS%E6 + LHS%E7*RHS%E16 + LHS%E16*RHS%E7
      RES%E267 = LHS%R*RHS%E267 + LHS%E267*RHS%R +  &
              LHS%E2*RHS%E67 + LHS%E67*RHS%E2 + LHS%E6*RHS%E27 +  &
              LHS%E27*RHS%E6 + LHS%E7*RHS%E26 + LHS%E26*RHS%E7
      RES%E367 = LHS%R*RHS%E367 + LHS%E367*RHS%R +  &
              LHS%E3*RHS%E67 + LHS%E67*RHS%E3 + LHS%E6*RHS%E37 +  &
              LHS%E37*RHS%E6 + LHS%E7*RHS%E36 + LHS%E36*RHS%E7
      RES%E467 = LHS%R*RHS%E467 + LHS%E467*RHS%R +  &
              LHS%E4*RHS%E67 + LHS%E67*RHS%E4 + LHS%E6*RHS%E47 +  &
              LHS%E47*RHS%E6 + LHS%E7*RHS%E46 + LHS%E46*RHS%E7
      RES%E567 = LHS%R*RHS%E567 + LHS%E567*RHS%R +  &
              LHS%E5*RHS%E67 + LHS%E67*RHS%E5 + LHS%E6*RHS%E57 +  &
              LHS%E57*RHS%E6 + LHS%E7*RHS%E56 + LHS%E56*RHS%E7
      RES%E667 = LHS%R*RHS%E667 + LHS%E667*RHS%R +  &
              LHS%E6*RHS%E67 + LHS%E67*RHS%E6 + LHS%E7*RHS%E66 + LHS%E66*RHS%E7
      RES%E177 = LHS%R*RHS%E177 + LHS%E177*RHS%R +  &
              LHS%E1*RHS%E77 + LHS%E77*RHS%E1 + LHS%E7*RHS%E17 + LHS%E17*RHS%E7
      RES%E277 = LHS%R*RHS%E277 + LHS%E277*RHS%R +  &
              LHS%E2*RHS%E77 + LHS%E77*RHS%E2 + LHS%E7*RHS%E27 + LHS%E27*RHS%E7
      RES%E377 = LHS%R*RHS%E377 + LHS%E377*RHS%R +  &
              LHS%E3*RHS%E77 + LHS%E77*RHS%E3 + LHS%E7*RHS%E37 + LHS%E37*RHS%E7
      RES%E477 = LHS%R*RHS%E477 + LHS%E477*RHS%R +  &
              LHS%E4*RHS%E77 + LHS%E77*RHS%E4 + LHS%E7*RHS%E47 + LHS%E47*RHS%E7
      RES%E577 = LHS%R*RHS%E577 + LHS%E577*RHS%R +  &
              LHS%E5*RHS%E77 + LHS%E77*RHS%E5 + LHS%E7*RHS%E57 + LHS%E57*RHS%E7
      RES%E677 = LHS%R*RHS%E677 + LHS%E677*RHS%R +  &
              LHS%E6*RHS%E77 + LHS%E77*RHS%E6 + LHS%E7*RHS%E67 + LHS%E67*RHS%E7
      RES%E777 = LHS%R*RHS%E777 + LHS%E777*RHS%R +  &
              LHS%E7*RHS%E77 + LHS%E77*RHS%E7
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

   END FUNCTION ONUMM7N3_MUL_OO_SM

   FUNCTION ONUMM7N3_MUL_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM7N3), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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

      ! Order 3
      RES%E111 = LHS*RHS%E111
      RES%E112 = LHS*RHS%E112
      RES%E122 = LHS*RHS%E122
      RES%E222 = LHS*RHS%E222
      RES%E113 = LHS*RHS%E113
      RES%E123 = LHS*RHS%E123
      RES%E223 = LHS*RHS%E223
      RES%E133 = LHS*RHS%E133
      RES%E233 = LHS*RHS%E233
      RES%E333 = LHS*RHS%E333
      RES%E114 = LHS*RHS%E114
      RES%E124 = LHS*RHS%E124
      RES%E224 = LHS*RHS%E224
      RES%E134 = LHS*RHS%E134
      RES%E234 = LHS*RHS%E234
      RES%E334 = LHS*RHS%E334
      RES%E144 = LHS*RHS%E144
      RES%E244 = LHS*RHS%E244
      RES%E344 = LHS*RHS%E344
      RES%E444 = LHS*RHS%E444
      RES%E115 = LHS*RHS%E115
      RES%E125 = LHS*RHS%E125
      RES%E225 = LHS*RHS%E225
      RES%E135 = LHS*RHS%E135
      RES%E235 = LHS*RHS%E235
      RES%E335 = LHS*RHS%E335
      RES%E145 = LHS*RHS%E145
      RES%E245 = LHS*RHS%E245
      RES%E345 = LHS*RHS%E345
      RES%E445 = LHS*RHS%E445
      RES%E155 = LHS*RHS%E155
      RES%E255 = LHS*RHS%E255
      RES%E355 = LHS*RHS%E355
      RES%E455 = LHS*RHS%E455
      RES%E555 = LHS*RHS%E555
      RES%E116 = LHS*RHS%E116
      RES%E126 = LHS*RHS%E126
      RES%E226 = LHS*RHS%E226
      RES%E136 = LHS*RHS%E136
      RES%E236 = LHS*RHS%E236
      RES%E336 = LHS*RHS%E336
      RES%E146 = LHS*RHS%E146
      RES%E246 = LHS*RHS%E246
      RES%E346 = LHS*RHS%E346
      RES%E446 = LHS*RHS%E446
      RES%E156 = LHS*RHS%E156
      RES%E256 = LHS*RHS%E256
      RES%E356 = LHS*RHS%E356
      RES%E456 = LHS*RHS%E456
      RES%E556 = LHS*RHS%E556
      RES%E166 = LHS*RHS%E166
      RES%E266 = LHS*RHS%E266
      RES%E366 = LHS*RHS%E366
      RES%E466 = LHS*RHS%E466
      RES%E566 = LHS*RHS%E566
      RES%E666 = LHS*RHS%E666
      RES%E117 = LHS*RHS%E117
      RES%E127 = LHS*RHS%E127
      RES%E227 = LHS*RHS%E227
      RES%E137 = LHS*RHS%E137
      RES%E237 = LHS*RHS%E237
      RES%E337 = LHS*RHS%E337
      RES%E147 = LHS*RHS%E147
      RES%E247 = LHS*RHS%E247
      RES%E347 = LHS*RHS%E347
      RES%E447 = LHS*RHS%E447
      RES%E157 = LHS*RHS%E157
      RES%E257 = LHS*RHS%E257
      RES%E357 = LHS*RHS%E357
      RES%E457 = LHS*RHS%E457
      RES%E557 = LHS*RHS%E557
      RES%E167 = LHS*RHS%E167
      RES%E267 = LHS*RHS%E267
      RES%E367 = LHS*RHS%E367
      RES%E467 = LHS*RHS%E467
      RES%E567 = LHS*RHS%E567
      RES%E667 = LHS*RHS%E667
      RES%E177 = LHS*RHS%E177
      RES%E277 = LHS*RHS%E277
      RES%E377 = LHS*RHS%E377
      RES%E477 = LHS*RHS%E477
      RES%E577 = LHS*RHS%E577
      RES%E677 = LHS*RHS%E677
      RES%E777 = LHS*RHS%E777

   END FUNCTION ONUMM7N3_MUL_RO_SM

   FUNCTION ONUMM7N3_MUL_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

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

      ! Order 3
      RES%E111 = LHS%E111*RHS
      RES%E112 = LHS%E112*RHS
      RES%E122 = LHS%E122*RHS
      RES%E222 = LHS%E222*RHS
      RES%E113 = LHS%E113*RHS
      RES%E123 = LHS%E123*RHS
      RES%E223 = LHS%E223*RHS
      RES%E133 = LHS%E133*RHS
      RES%E233 = LHS%E233*RHS
      RES%E333 = LHS%E333*RHS
      RES%E114 = LHS%E114*RHS
      RES%E124 = LHS%E124*RHS
      RES%E224 = LHS%E224*RHS
      RES%E134 = LHS%E134*RHS
      RES%E234 = LHS%E234*RHS
      RES%E334 = LHS%E334*RHS
      RES%E144 = LHS%E144*RHS
      RES%E244 = LHS%E244*RHS
      RES%E344 = LHS%E344*RHS
      RES%E444 = LHS%E444*RHS
      RES%E115 = LHS%E115*RHS
      RES%E125 = LHS%E125*RHS
      RES%E225 = LHS%E225*RHS
      RES%E135 = LHS%E135*RHS
      RES%E235 = LHS%E235*RHS
      RES%E335 = LHS%E335*RHS
      RES%E145 = LHS%E145*RHS
      RES%E245 = LHS%E245*RHS
      RES%E345 = LHS%E345*RHS
      RES%E445 = LHS%E445*RHS
      RES%E155 = LHS%E155*RHS
      RES%E255 = LHS%E255*RHS
      RES%E355 = LHS%E355*RHS
      RES%E455 = LHS%E455*RHS
      RES%E555 = LHS%E555*RHS
      RES%E116 = LHS%E116*RHS
      RES%E126 = LHS%E126*RHS
      RES%E226 = LHS%E226*RHS
      RES%E136 = LHS%E136*RHS
      RES%E236 = LHS%E236*RHS
      RES%E336 = LHS%E336*RHS
      RES%E146 = LHS%E146*RHS
      RES%E246 = LHS%E246*RHS
      RES%E346 = LHS%E346*RHS
      RES%E446 = LHS%E446*RHS
      RES%E156 = LHS%E156*RHS
      RES%E256 = LHS%E256*RHS
      RES%E356 = LHS%E356*RHS
      RES%E456 = LHS%E456*RHS
      RES%E556 = LHS%E556*RHS
      RES%E166 = LHS%E166*RHS
      RES%E266 = LHS%E266*RHS
      RES%E366 = LHS%E366*RHS
      RES%E466 = LHS%E466*RHS
      RES%E566 = LHS%E566*RHS
      RES%E666 = LHS%E666*RHS
      RES%E117 = LHS%E117*RHS
      RES%E127 = LHS%E127*RHS
      RES%E227 = LHS%E227*RHS
      RES%E137 = LHS%E137*RHS
      RES%E237 = LHS%E237*RHS
      RES%E337 = LHS%E337*RHS
      RES%E147 = LHS%E147*RHS
      RES%E247 = LHS%E247*RHS
      RES%E347 = LHS%E347*RHS
      RES%E447 = LHS%E447*RHS
      RES%E157 = LHS%E157*RHS
      RES%E257 = LHS%E257*RHS
      RES%E357 = LHS%E357*RHS
      RES%E457 = LHS%E457*RHS
      RES%E557 = LHS%E557*RHS
      RES%E167 = LHS%E167*RHS
      RES%E267 = LHS%E267*RHS
      RES%E367 = LHS%E367*RHS
      RES%E467 = LHS%E467*RHS
      RES%E567 = LHS%E567*RHS
      RES%E667 = LHS%E667*RHS
      RES%E177 = LHS%E177*RHS
      RES%E277 = LHS%E277*RHS
      RES%E377 = LHS%E377*RHS
      RES%E477 = LHS%E477*RHS
      RES%E577 = LHS%E577*RHS
      RES%E677 = LHS%E677*RHS
      RES%E777 = LHS%E777*RHS

   END FUNCTION ONUMM7N3_MUL_OR_SM

ELEMENTAL    FUNCTION ONUMM7N3_GEM_OOO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: A 
      TYPE(ONUMM7N3), INTENT(IN) :: B 
      TYPE(ONUMM7N3), INTENT(IN) :: C 
      TYPE(ONUMM7N3) :: RES 

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

      ! Order 3
      RES%E111 = C%E111 + A%R*B%E111 + A%E111*B%R + A%E1*B%E11 &
               + A%E11*B%E1
      RES%E112 = C%E112 + A%R*B%E112 + A%E112*B%R + A%E1*B%E12 &
               + A%E12*B%E1 + A%E2*B%E11 + A%E11*B%E2
      RES%E122 = C%E122 + A%R*B%E122 + A%E122*B%R + A%E1*B%E22 &
               + A%E22*B%E1 + A%E2*B%E12 + A%E12*B%E2
      RES%E222 = C%E222 + A%R*B%E222 + A%E222*B%R + A%E2*B%E22 &
               + A%E22*B%E2
      RES%E113 = C%E113 + A%R*B%E113 + A%E113*B%R + A%E1*B%E13 &
               + A%E13*B%E1 + A%E3*B%E11 + A%E11*B%E3
      RES%E123 = C%E123 + A%R*B%E123 + A%E123*B%R + A%E1*B%E23 &
               + A%E23*B%E1 + A%E2*B%E13 + A%E13*B%E2 &
               + A%E3*B%E12 + A%E12*B%E3
      RES%E223 = C%E223 + A%R*B%E223 + A%E223*B%R + A%E2*B%E23 &
               + A%E23*B%E2 + A%E3*B%E22 + A%E22*B%E3
      RES%E133 = C%E133 + A%R*B%E133 + A%E133*B%R + A%E1*B%E33 &
               + A%E33*B%E1 + A%E3*B%E13 + A%E13*B%E3
      RES%E233 = C%E233 + A%R*B%E233 + A%E233*B%R + A%E2*B%E33 &
               + A%E33*B%E2 + A%E3*B%E23 + A%E23*B%E3
      RES%E333 = C%E333 + A%R*B%E333 + A%E333*B%R + A%E3*B%E33 &
               + A%E33*B%E3
      RES%E114 = C%E114 + A%R*B%E114 + A%E114*B%R + A%E1*B%E14 &
               + A%E14*B%E1 + A%E4*B%E11 + A%E11*B%E4
      RES%E124 = C%E124 + A%R*B%E124 + A%E124*B%R + A%E1*B%E24 &
               + A%E24*B%E1 + A%E2*B%E14 + A%E14*B%E2 &
               + A%E4*B%E12 + A%E12*B%E4
      RES%E224 = C%E224 + A%R*B%E224 + A%E224*B%R + A%E2*B%E24 &
               + A%E24*B%E2 + A%E4*B%E22 + A%E22*B%E4
      RES%E134 = C%E134 + A%R*B%E134 + A%E134*B%R + A%E1*B%E34 &
               + A%E34*B%E1 + A%E3*B%E14 + A%E14*B%E3 &
               + A%E4*B%E13 + A%E13*B%E4
      RES%E234 = C%E234 + A%R*B%E234 + A%E234*B%R + A%E2*B%E34 &
               + A%E34*B%E2 + A%E3*B%E24 + A%E24*B%E3 &
               + A%E4*B%E23 + A%E23*B%E4
      RES%E334 = C%E334 + A%R*B%E334 + A%E334*B%R + A%E3*B%E34 &
               + A%E34*B%E3 + A%E4*B%E33 + A%E33*B%E4
      RES%E144 = C%E144 + A%R*B%E144 + A%E144*B%R + A%E1*B%E44 &
               + A%E44*B%E1 + A%E4*B%E14 + A%E14*B%E4
      RES%E244 = C%E244 + A%R*B%E244 + A%E244*B%R + A%E2*B%E44 &
               + A%E44*B%E2 + A%E4*B%E24 + A%E24*B%E4
      RES%E344 = C%E344 + A%R*B%E344 + A%E344*B%R + A%E3*B%E44 &
               + A%E44*B%E3 + A%E4*B%E34 + A%E34*B%E4
      RES%E444 = C%E444 + A%R*B%E444 + A%E444*B%R + A%E4*B%E44 &
               + A%E44*B%E4
      RES%E115 = C%E115 + A%R*B%E115 + A%E115*B%R + A%E1*B%E15 &
               + A%E15*B%E1 + A%E5*B%E11 + A%E11*B%E5
      RES%E125 = C%E125 + A%R*B%E125 + A%E125*B%R + A%E1*B%E25 &
               + A%E25*B%E1 + A%E2*B%E15 + A%E15*B%E2 &
               + A%E5*B%E12 + A%E12*B%E5
      RES%E225 = C%E225 + A%R*B%E225 + A%E225*B%R + A%E2*B%E25 &
               + A%E25*B%E2 + A%E5*B%E22 + A%E22*B%E5
      RES%E135 = C%E135 + A%R*B%E135 + A%E135*B%R + A%E1*B%E35 &
               + A%E35*B%E1 + A%E3*B%E15 + A%E15*B%E3 &
               + A%E5*B%E13 + A%E13*B%E5
      RES%E235 = C%E235 + A%R*B%E235 + A%E235*B%R + A%E2*B%E35 &
               + A%E35*B%E2 + A%E3*B%E25 + A%E25*B%E3 &
               + A%E5*B%E23 + A%E23*B%E5
      RES%E335 = C%E335 + A%R*B%E335 + A%E335*B%R + A%E3*B%E35 &
               + A%E35*B%E3 + A%E5*B%E33 + A%E33*B%E5
      RES%E145 = C%E145 + A%R*B%E145 + A%E145*B%R + A%E1*B%E45 &
               + A%E45*B%E1 + A%E4*B%E15 + A%E15*B%E4 &
               + A%E5*B%E14 + A%E14*B%E5
      RES%E245 = C%E245 + A%R*B%E245 + A%E245*B%R + A%E2*B%E45 &
               + A%E45*B%E2 + A%E4*B%E25 + A%E25*B%E4 &
               + A%E5*B%E24 + A%E24*B%E5
      RES%E345 = C%E345 + A%R*B%E345 + A%E345*B%R + A%E3*B%E45 &
               + A%E45*B%E3 + A%E4*B%E35 + A%E35*B%E4 &
               + A%E5*B%E34 + A%E34*B%E5
      RES%E445 = C%E445 + A%R*B%E445 + A%E445*B%R + A%E4*B%E45 &
               + A%E45*B%E4 + A%E5*B%E44 + A%E44*B%E5
      RES%E155 = C%E155 + A%R*B%E155 + A%E155*B%R + A%E1*B%E55 &
               + A%E55*B%E1 + A%E5*B%E15 + A%E15*B%E5
      RES%E255 = C%E255 + A%R*B%E255 + A%E255*B%R + A%E2*B%E55 &
               + A%E55*B%E2 + A%E5*B%E25 + A%E25*B%E5
      RES%E355 = C%E355 + A%R*B%E355 + A%E355*B%R + A%E3*B%E55 &
               + A%E55*B%E3 + A%E5*B%E35 + A%E35*B%E5
      RES%E455 = C%E455 + A%R*B%E455 + A%E455*B%R + A%E4*B%E55 &
               + A%E55*B%E4 + A%E5*B%E45 + A%E45*B%E5
      RES%E555 = C%E555 + A%R*B%E555 + A%E555*B%R + A%E5*B%E55 &
               + A%E55*B%E5
      RES%E116 = C%E116 + A%R*B%E116 + A%E116*B%R + A%E1*B%E16 &
               + A%E16*B%E1 + A%E6*B%E11 + A%E11*B%E6
      RES%E126 = C%E126 + A%R*B%E126 + A%E126*B%R + A%E1*B%E26 &
               + A%E26*B%E1 + A%E2*B%E16 + A%E16*B%E2 &
               + A%E6*B%E12 + A%E12*B%E6
      RES%E226 = C%E226 + A%R*B%E226 + A%E226*B%R + A%E2*B%E26 &
               + A%E26*B%E2 + A%E6*B%E22 + A%E22*B%E6
      RES%E136 = C%E136 + A%R*B%E136 + A%E136*B%R + A%E1*B%E36 &
               + A%E36*B%E1 + A%E3*B%E16 + A%E16*B%E3 &
               + A%E6*B%E13 + A%E13*B%E6
      RES%E236 = C%E236 + A%R*B%E236 + A%E236*B%R + A%E2*B%E36 &
               + A%E36*B%E2 + A%E3*B%E26 + A%E26*B%E3 &
               + A%E6*B%E23 + A%E23*B%E6
      RES%E336 = C%E336 + A%R*B%E336 + A%E336*B%R + A%E3*B%E36 &
               + A%E36*B%E3 + A%E6*B%E33 + A%E33*B%E6
      RES%E146 = C%E146 + A%R*B%E146 + A%E146*B%R + A%E1*B%E46 &
               + A%E46*B%E1 + A%E4*B%E16 + A%E16*B%E4 &
               + A%E6*B%E14 + A%E14*B%E6
      RES%E246 = C%E246 + A%R*B%E246 + A%E246*B%R + A%E2*B%E46 &
               + A%E46*B%E2 + A%E4*B%E26 + A%E26*B%E4 &
               + A%E6*B%E24 + A%E24*B%E6
      RES%E346 = C%E346 + A%R*B%E346 + A%E346*B%R + A%E3*B%E46 &
               + A%E46*B%E3 + A%E4*B%E36 + A%E36*B%E4 &
               + A%E6*B%E34 + A%E34*B%E6
      RES%E446 = C%E446 + A%R*B%E446 + A%E446*B%R + A%E4*B%E46 &
               + A%E46*B%E4 + A%E6*B%E44 + A%E44*B%E6
      RES%E156 = C%E156 + A%R*B%E156 + A%E156*B%R + A%E1*B%E56 &
               + A%E56*B%E1 + A%E5*B%E16 + A%E16*B%E5 &
               + A%E6*B%E15 + A%E15*B%E6
      RES%E256 = C%E256 + A%R*B%E256 + A%E256*B%R + A%E2*B%E56 &
               + A%E56*B%E2 + A%E5*B%E26 + A%E26*B%E5 &
               + A%E6*B%E25 + A%E25*B%E6
      RES%E356 = C%E356 + A%R*B%E356 + A%E356*B%R + A%E3*B%E56 &
               + A%E56*B%E3 + A%E5*B%E36 + A%E36*B%E5 &
               + A%E6*B%E35 + A%E35*B%E6
      RES%E456 = C%E456 + A%R*B%E456 + A%E456*B%R + A%E4*B%E56 &
               + A%E56*B%E4 + A%E5*B%E46 + A%E46*B%E5 &
               + A%E6*B%E45 + A%E45*B%E6
      RES%E556 = C%E556 + A%R*B%E556 + A%E556*B%R + A%E5*B%E56 &
               + A%E56*B%E5 + A%E6*B%E55 + A%E55*B%E6
      RES%E166 = C%E166 + A%R*B%E166 + A%E166*B%R + A%E1*B%E66 &
               + A%E66*B%E1 + A%E6*B%E16 + A%E16*B%E6
      RES%E266 = C%E266 + A%R*B%E266 + A%E266*B%R + A%E2*B%E66 &
               + A%E66*B%E2 + A%E6*B%E26 + A%E26*B%E6
      RES%E366 = C%E366 + A%R*B%E366 + A%E366*B%R + A%E3*B%E66 &
               + A%E66*B%E3 + A%E6*B%E36 + A%E36*B%E6
      RES%E466 = C%E466 + A%R*B%E466 + A%E466*B%R + A%E4*B%E66 &
               + A%E66*B%E4 + A%E6*B%E46 + A%E46*B%E6
      RES%E566 = C%E566 + A%R*B%E566 + A%E566*B%R + A%E5*B%E66 &
               + A%E66*B%E5 + A%E6*B%E56 + A%E56*B%E6
      RES%E666 = C%E666 + A%R*B%E666 + A%E666*B%R + A%E6*B%E66 &
               + A%E66*B%E6
      RES%E117 = C%E117 + A%R*B%E117 + A%E117*B%R + A%E1*B%E17 &
               + A%E17*B%E1 + A%E7*B%E11 + A%E11*B%E7
      RES%E127 = C%E127 + A%R*B%E127 + A%E127*B%R + A%E1*B%E27 &
               + A%E27*B%E1 + A%E2*B%E17 + A%E17*B%E2 &
               + A%E7*B%E12 + A%E12*B%E7
      RES%E227 = C%E227 + A%R*B%E227 + A%E227*B%R + A%E2*B%E27 &
               + A%E27*B%E2 + A%E7*B%E22 + A%E22*B%E7
      RES%E137 = C%E137 + A%R*B%E137 + A%E137*B%R + A%E1*B%E37 &
               + A%E37*B%E1 + A%E3*B%E17 + A%E17*B%E3 &
               + A%E7*B%E13 + A%E13*B%E7
      RES%E237 = C%E237 + A%R*B%E237 + A%E237*B%R + A%E2*B%E37 &
               + A%E37*B%E2 + A%E3*B%E27 + A%E27*B%E3 &
               + A%E7*B%E23 + A%E23*B%E7
      RES%E337 = C%E337 + A%R*B%E337 + A%E337*B%R + A%E3*B%E37 &
               + A%E37*B%E3 + A%E7*B%E33 + A%E33*B%E7
      RES%E147 = C%E147 + A%R*B%E147 + A%E147*B%R + A%E1*B%E47 &
               + A%E47*B%E1 + A%E4*B%E17 + A%E17*B%E4 &
               + A%E7*B%E14 + A%E14*B%E7
      RES%E247 = C%E247 + A%R*B%E247 + A%E247*B%R + A%E2*B%E47 &
               + A%E47*B%E2 + A%E4*B%E27 + A%E27*B%E4 &
               + A%E7*B%E24 + A%E24*B%E7
      RES%E347 = C%E347 + A%R*B%E347 + A%E347*B%R + A%E3*B%E47 &
               + A%E47*B%E3 + A%E4*B%E37 + A%E37*B%E4 &
               + A%E7*B%E34 + A%E34*B%E7
      RES%E447 = C%E447 + A%R*B%E447 + A%E447*B%R + A%E4*B%E47 &
               + A%E47*B%E4 + A%E7*B%E44 + A%E44*B%E7
      RES%E157 = C%E157 + A%R*B%E157 + A%E157*B%R + A%E1*B%E57 &
               + A%E57*B%E1 + A%E5*B%E17 + A%E17*B%E5 &
               + A%E7*B%E15 + A%E15*B%E7
      RES%E257 = C%E257 + A%R*B%E257 + A%E257*B%R + A%E2*B%E57 &
               + A%E57*B%E2 + A%E5*B%E27 + A%E27*B%E5 &
               + A%E7*B%E25 + A%E25*B%E7
      RES%E357 = C%E357 + A%R*B%E357 + A%E357*B%R + A%E3*B%E57 &
               + A%E57*B%E3 + A%E5*B%E37 + A%E37*B%E5 &
               + A%E7*B%E35 + A%E35*B%E7
      RES%E457 = C%E457 + A%R*B%E457 + A%E457*B%R + A%E4*B%E57 &
               + A%E57*B%E4 + A%E5*B%E47 + A%E47*B%E5 &
               + A%E7*B%E45 + A%E45*B%E7
      RES%E557 = C%E557 + A%R*B%E557 + A%E557*B%R + A%E5*B%E57 &
               + A%E57*B%E5 + A%E7*B%E55 + A%E55*B%E7
      RES%E167 = C%E167 + A%R*B%E167 + A%E167*B%R + A%E1*B%E67 &
               + A%E67*B%E1 + A%E6*B%E17 + A%E17*B%E6 &
               + A%E7*B%E16 + A%E16*B%E7
      RES%E267 = C%E267 + A%R*B%E267 + A%E267*B%R + A%E2*B%E67 &
               + A%E67*B%E2 + A%E6*B%E27 + A%E27*B%E6 &
               + A%E7*B%E26 + A%E26*B%E7
      RES%E367 = C%E367 + A%R*B%E367 + A%E367*B%R + A%E3*B%E67 &
               + A%E67*B%E3 + A%E6*B%E37 + A%E37*B%E6 &
               + A%E7*B%E36 + A%E36*B%E7
      RES%E467 = C%E467 + A%R*B%E467 + A%E467*B%R + A%E4*B%E67 &
               + A%E67*B%E4 + A%E6*B%E47 + A%E47*B%E6 &
               + A%E7*B%E46 + A%E46*B%E7
      RES%E567 = C%E567 + A%R*B%E567 + A%E567*B%R + A%E5*B%E67 &
               + A%E67*B%E5 + A%E6*B%E57 + A%E57*B%E6 &
               + A%E7*B%E56 + A%E56*B%E7
      RES%E667 = C%E667 + A%R*B%E667 + A%E667*B%R + A%E6*B%E67 &
               + A%E67*B%E6 + A%E7*B%E66 + A%E66*B%E7
      RES%E177 = C%E177 + A%R*B%E177 + A%E177*B%R + A%E1*B%E77 &
               + A%E77*B%E1 + A%E7*B%E17 + A%E17*B%E7
      RES%E277 = C%E277 + A%R*B%E277 + A%E277*B%R + A%E2*B%E77 &
               + A%E77*B%E2 + A%E7*B%E27 + A%E27*B%E7
      RES%E377 = C%E377 + A%R*B%E377 + A%E377*B%R + A%E3*B%E77 &
               + A%E77*B%E3 + A%E7*B%E37 + A%E37*B%E7
      RES%E477 = C%E477 + A%R*B%E477 + A%E477*B%R + A%E4*B%E77 &
               + A%E77*B%E4 + A%E7*B%E47 + A%E47*B%E7
      RES%E577 = C%E577 + A%R*B%E577 + A%E577*B%R + A%E5*B%E77 &
               + A%E77*B%E5 + A%E7*B%E57 + A%E57*B%E7
      RES%E677 = C%E677 + A%R*B%E677 + A%E677*B%R + A%E6*B%E77 &
               + A%E77*B%E6 + A%E7*B%E67 + A%E67*B%E7
      RES%E777 = C%E777 + A%R*B%E777 + A%E777*B%R + A%E7*B%E77 &
               + A%E77*B%E7

   END FUNCTION ONUMM7N3_GEM_OOO

ELEMENTAL    FUNCTION ONUMM7N3_GEM_ROO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: A 
      TYPE(ONUMM7N3), INTENT(IN) :: B 
      TYPE(ONUMM7N3), INTENT(IN) :: C 
      TYPE(ONUMM7N3) :: RES 

      !  General multiplication like function 'A*B + C'
      ! Order 3
      RES%E111 = C%E111 + A*B%E111
      RES%E112 = C%E112 + A*B%E112
      RES%E122 = C%E122 + A*B%E122
      RES%E222 = C%E222 + A*B%E222
      RES%E113 = C%E113 + A*B%E113
      RES%E123 = C%E123 + A*B%E123
      RES%E223 = C%E223 + A*B%E223
      RES%E133 = C%E133 + A*B%E133
      RES%E233 = C%E233 + A*B%E233
      RES%E333 = C%E333 + A*B%E333
      RES%E114 = C%E114 + A*B%E114
      RES%E124 = C%E124 + A*B%E124
      RES%E224 = C%E224 + A*B%E224
      RES%E134 = C%E134 + A*B%E134
      RES%E234 = C%E234 + A*B%E234
      RES%E334 = C%E334 + A*B%E334
      RES%E144 = C%E144 + A*B%E144
      RES%E244 = C%E244 + A*B%E244
      RES%E344 = C%E344 + A*B%E344
      RES%E444 = C%E444 + A*B%E444
      RES%E115 = C%E115 + A*B%E115
      RES%E125 = C%E125 + A*B%E125
      RES%E225 = C%E225 + A*B%E225
      RES%E135 = C%E135 + A*B%E135
      RES%E235 = C%E235 + A*B%E235
      RES%E335 = C%E335 + A*B%E335
      RES%E145 = C%E145 + A*B%E145
      RES%E245 = C%E245 + A*B%E245
      RES%E345 = C%E345 + A*B%E345
      RES%E445 = C%E445 + A*B%E445
      RES%E155 = C%E155 + A*B%E155
      RES%E255 = C%E255 + A*B%E255
      RES%E355 = C%E355 + A*B%E355
      RES%E455 = C%E455 + A*B%E455
      RES%E555 = C%E555 + A*B%E555
      RES%E116 = C%E116 + A*B%E116
      RES%E126 = C%E126 + A*B%E126
      RES%E226 = C%E226 + A*B%E226
      RES%E136 = C%E136 + A*B%E136
      RES%E236 = C%E236 + A*B%E236
      RES%E336 = C%E336 + A*B%E336
      RES%E146 = C%E146 + A*B%E146
      RES%E246 = C%E246 + A*B%E246
      RES%E346 = C%E346 + A*B%E346
      RES%E446 = C%E446 + A*B%E446
      RES%E156 = C%E156 + A*B%E156
      RES%E256 = C%E256 + A*B%E256
      RES%E356 = C%E356 + A*B%E356
      RES%E456 = C%E456 + A*B%E456
      RES%E556 = C%E556 + A*B%E556
      RES%E166 = C%E166 + A*B%E166
      RES%E266 = C%E266 + A*B%E266
      RES%E366 = C%E366 + A*B%E366
      RES%E466 = C%E466 + A*B%E466
      RES%E566 = C%E566 + A*B%E566
      RES%E666 = C%E666 + A*B%E666
      RES%E117 = C%E117 + A*B%E117
      RES%E127 = C%E127 + A*B%E127
      RES%E227 = C%E227 + A*B%E227
      RES%E137 = C%E137 + A*B%E137
      RES%E237 = C%E237 + A*B%E237
      RES%E337 = C%E337 + A*B%E337
      RES%E147 = C%E147 + A*B%E147
      RES%E247 = C%E247 + A*B%E247
      RES%E347 = C%E347 + A*B%E347
      RES%E447 = C%E447 + A*B%E447
      RES%E157 = C%E157 + A*B%E157
      RES%E257 = C%E257 + A*B%E257
      RES%E357 = C%E357 + A*B%E357
      RES%E457 = C%E457 + A*B%E457
      RES%E557 = C%E557 + A*B%E557
      RES%E167 = C%E167 + A*B%E167
      RES%E267 = C%E267 + A*B%E267
      RES%E367 = C%E367 + A*B%E367
      RES%E467 = C%E467 + A*B%E467
      RES%E567 = C%E567 + A*B%E567
      RES%E667 = C%E667 + A*B%E667
      RES%E177 = C%E177 + A*B%E177
      RES%E277 = C%E277 + A*B%E277
      RES%E377 = C%E377 + A*B%E377
      RES%E477 = C%E477 + A*B%E477
      RES%E577 = C%E577 + A*B%E577
      RES%E677 = C%E677 + A*B%E677
      RES%E777 = C%E777 + A*B%E777
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

   END FUNCTION ONUMM7N3_GEM_ROO

ELEMENTAL    FUNCTION ONUMM7N3_GEM_ORO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: A 
      REAL(DP), INTENT(IN) :: B 
      TYPE(ONUMM7N3), INTENT(IN) :: C 
      TYPE(ONUMM7N3) :: RES 

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

      ! Order 3
      RES%E111 = C%E111 + A%E111*B
      RES%E112 = C%E112 + A%E112*B
      RES%E122 = C%E122 + A%E122*B
      RES%E222 = C%E222 + A%E222*B
      RES%E113 = C%E113 + A%E113*B
      RES%E123 = C%E123 + A%E123*B
      RES%E223 = C%E223 + A%E223*B
      RES%E133 = C%E133 + A%E133*B
      RES%E233 = C%E233 + A%E233*B
      RES%E333 = C%E333 + A%E333*B
      RES%E114 = C%E114 + A%E114*B
      RES%E124 = C%E124 + A%E124*B
      RES%E224 = C%E224 + A%E224*B
      RES%E134 = C%E134 + A%E134*B
      RES%E234 = C%E234 + A%E234*B
      RES%E334 = C%E334 + A%E334*B
      RES%E144 = C%E144 + A%E144*B
      RES%E244 = C%E244 + A%E244*B
      RES%E344 = C%E344 + A%E344*B
      RES%E444 = C%E444 + A%E444*B
      RES%E115 = C%E115 + A%E115*B
      RES%E125 = C%E125 + A%E125*B
      RES%E225 = C%E225 + A%E225*B
      RES%E135 = C%E135 + A%E135*B
      RES%E235 = C%E235 + A%E235*B
      RES%E335 = C%E335 + A%E335*B
      RES%E145 = C%E145 + A%E145*B
      RES%E245 = C%E245 + A%E245*B
      RES%E345 = C%E345 + A%E345*B
      RES%E445 = C%E445 + A%E445*B
      RES%E155 = C%E155 + A%E155*B
      RES%E255 = C%E255 + A%E255*B
      RES%E355 = C%E355 + A%E355*B
      RES%E455 = C%E455 + A%E455*B
      RES%E555 = C%E555 + A%E555*B
      RES%E116 = C%E116 + A%E116*B
      RES%E126 = C%E126 + A%E126*B
      RES%E226 = C%E226 + A%E226*B
      RES%E136 = C%E136 + A%E136*B
      RES%E236 = C%E236 + A%E236*B
      RES%E336 = C%E336 + A%E336*B
      RES%E146 = C%E146 + A%E146*B
      RES%E246 = C%E246 + A%E246*B
      RES%E346 = C%E346 + A%E346*B
      RES%E446 = C%E446 + A%E446*B
      RES%E156 = C%E156 + A%E156*B
      RES%E256 = C%E256 + A%E256*B
      RES%E356 = C%E356 + A%E356*B
      RES%E456 = C%E456 + A%E456*B
      RES%E556 = C%E556 + A%E556*B
      RES%E166 = C%E166 + A%E166*B
      RES%E266 = C%E266 + A%E266*B
      RES%E366 = C%E366 + A%E366*B
      RES%E466 = C%E466 + A%E466*B
      RES%E566 = C%E566 + A%E566*B
      RES%E666 = C%E666 + A%E666*B
      RES%E117 = C%E117 + A%E117*B
      RES%E127 = C%E127 + A%E127*B
      RES%E227 = C%E227 + A%E227*B
      RES%E137 = C%E137 + A%E137*B
      RES%E237 = C%E237 + A%E237*B
      RES%E337 = C%E337 + A%E337*B
      RES%E147 = C%E147 + A%E147*B
      RES%E247 = C%E247 + A%E247*B
      RES%E347 = C%E347 + A%E347*B
      RES%E447 = C%E447 + A%E447*B
      RES%E157 = C%E157 + A%E157*B
      RES%E257 = C%E257 + A%E257*B
      RES%E357 = C%E357 + A%E357*B
      RES%E457 = C%E457 + A%E457*B
      RES%E557 = C%E557 + A%E557*B
      RES%E167 = C%E167 + A%E167*B
      RES%E267 = C%E267 + A%E267*B
      RES%E367 = C%E367 + A%E367*B
      RES%E467 = C%E467 + A%E467*B
      RES%E567 = C%E567 + A%E567*B
      RES%E667 = C%E667 + A%E667*B
      RES%E177 = C%E177 + A%E177*B
      RES%E277 = C%E277 + A%E277*B
      RES%E377 = C%E377 + A%E377*B
      RES%E477 = C%E477 + A%E477*B
      RES%E577 = C%E577 + A%E577*B
      RES%E677 = C%E677 + A%E677*B
      RES%E777 = C%E777 + A%E777*B

   END FUNCTION ONUMM7N3_GEM_ORO

   FUNCTION ONUMM7N3_MATMUL_ONUMM7N3(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N3), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      !  Multiplication like function 'MATMUL(lhs,rhs)'
      ! Order 3
      res%E111 = MATMUL(lhs%R,rhs%E111) + MATMUL(lhs%E111,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E11) + MATMUL(lhs%E11,rhs%E1)
      res%E112 = MATMUL(lhs%R,rhs%E112) + MATMUL(lhs%E112,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E12) + MATMUL(lhs%E12,rhs%E1) + MATMUL(lhs%E2,rhs%E11) + MATMUL(lhs%E11,rhs%E2)
      res%E122 = MATMUL(lhs%R,rhs%E122) + MATMUL(lhs%E122,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E22) + MATMUL(lhs%E22,rhs%E1) + MATMUL(lhs%E2,rhs%E12) + MATMUL(lhs%E12,rhs%E2)
      res%E222 = MATMUL(lhs%R,rhs%E222) + MATMUL(lhs%E222,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E22) + MATMUL(lhs%E22,rhs%E2)
      res%E113 = MATMUL(lhs%R,rhs%E113) + MATMUL(lhs%E113,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E13) + MATMUL(lhs%E13,rhs%E1) + MATMUL(lhs%E3,rhs%E11) + MATMUL(lhs%E11,rhs%E3)
      res%E123 = MATMUL(lhs%R,rhs%E123) + MATMUL(lhs%E123,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E23) + MATMUL(lhs%E23,rhs%E1) + MATMUL(lhs%E2,rhs%E13) +  &
              MATMUL(lhs%E13,rhs%E2) + MATMUL(lhs%E3,rhs%E12) + MATMUL(lhs%E12,rhs%E3)
      res%E223 = MATMUL(lhs%R,rhs%E223) + MATMUL(lhs%E223,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E23) + MATMUL(lhs%E23,rhs%E2) + MATMUL(lhs%E3,rhs%E22) + MATMUL(lhs%E22,rhs%E3)
      res%E133 = MATMUL(lhs%R,rhs%E133) + MATMUL(lhs%E133,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E33) + MATMUL(lhs%E33,rhs%E1) + MATMUL(lhs%E3,rhs%E13) + MATMUL(lhs%E13,rhs%E3)
      res%E233 = MATMUL(lhs%R,rhs%E233) + MATMUL(lhs%E233,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E33) + MATMUL(lhs%E33,rhs%E2) + MATMUL(lhs%E3,rhs%E23) + MATMUL(lhs%E23,rhs%E3)
      res%E333 = MATMUL(lhs%R,rhs%E333) + MATMUL(lhs%E333,rhs%R) +  &
              MATMUL(lhs%E3,rhs%E33) + MATMUL(lhs%E33,rhs%E3)
      res%E114 = MATMUL(lhs%R,rhs%E114) + MATMUL(lhs%E114,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E14) + MATMUL(lhs%E14,rhs%E1) + MATMUL(lhs%E4,rhs%E11) + MATMUL(lhs%E11,rhs%E4)
      res%E124 = MATMUL(lhs%R,rhs%E124) + MATMUL(lhs%E124,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E24) + MATMUL(lhs%E24,rhs%E1) + MATMUL(lhs%E2,rhs%E14) +  &
              MATMUL(lhs%E14,rhs%E2) + MATMUL(lhs%E4,rhs%E12) + MATMUL(lhs%E12,rhs%E4)
      res%E224 = MATMUL(lhs%R,rhs%E224) + MATMUL(lhs%E224,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E24) + MATMUL(lhs%E24,rhs%E2) + MATMUL(lhs%E4,rhs%E22) + MATMUL(lhs%E22,rhs%E4)
      res%E134 = MATMUL(lhs%R,rhs%E134) + MATMUL(lhs%E134,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E34) + MATMUL(lhs%E34,rhs%E1) + MATMUL(lhs%E3,rhs%E14) +  &
              MATMUL(lhs%E14,rhs%E3) + MATMUL(lhs%E4,rhs%E13) + MATMUL(lhs%E13,rhs%E4)
      res%E234 = MATMUL(lhs%R,rhs%E234) + MATMUL(lhs%E234,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E34) + MATMUL(lhs%E34,rhs%E2) + MATMUL(lhs%E3,rhs%E24) +  &
              MATMUL(lhs%E24,rhs%E3) + MATMUL(lhs%E4,rhs%E23) + MATMUL(lhs%E23,rhs%E4)
      res%E334 = MATMUL(lhs%R,rhs%E334) + MATMUL(lhs%E334,rhs%R) +  &
              MATMUL(lhs%E3,rhs%E34) + MATMUL(lhs%E34,rhs%E3) + MATMUL(lhs%E4,rhs%E33) + MATMUL(lhs%E33,rhs%E4)
      res%E144 = MATMUL(lhs%R,rhs%E144) + MATMUL(lhs%E144,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E44) + MATMUL(lhs%E44,rhs%E1) + MATMUL(lhs%E4,rhs%E14) + MATMUL(lhs%E14,rhs%E4)
      res%E244 = MATMUL(lhs%R,rhs%E244) + MATMUL(lhs%E244,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E44) + MATMUL(lhs%E44,rhs%E2) + MATMUL(lhs%E4,rhs%E24) + MATMUL(lhs%E24,rhs%E4)
      res%E344 = MATMUL(lhs%R,rhs%E344) + MATMUL(lhs%E344,rhs%R) +  &
              MATMUL(lhs%E3,rhs%E44) + MATMUL(lhs%E44,rhs%E3) + MATMUL(lhs%E4,rhs%E34) + MATMUL(lhs%E34,rhs%E4)
      res%E444 = MATMUL(lhs%R,rhs%E444) + MATMUL(lhs%E444,rhs%R) +  &
              MATMUL(lhs%E4,rhs%E44) + MATMUL(lhs%E44,rhs%E4)
      res%E115 = MATMUL(lhs%R,rhs%E115) + MATMUL(lhs%E115,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E15) + MATMUL(lhs%E15,rhs%E1) + MATMUL(lhs%E5,rhs%E11) + MATMUL(lhs%E11,rhs%E5)
      res%E125 = MATMUL(lhs%R,rhs%E125) + MATMUL(lhs%E125,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E25) + MATMUL(lhs%E25,rhs%E1) + MATMUL(lhs%E2,rhs%E15) +  &
              MATMUL(lhs%E15,rhs%E2) + MATMUL(lhs%E5,rhs%E12) + MATMUL(lhs%E12,rhs%E5)
      res%E225 = MATMUL(lhs%R,rhs%E225) + MATMUL(lhs%E225,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E25) + MATMUL(lhs%E25,rhs%E2) + MATMUL(lhs%E5,rhs%E22) + MATMUL(lhs%E22,rhs%E5)
      res%E135 = MATMUL(lhs%R,rhs%E135) + MATMUL(lhs%E135,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E35) + MATMUL(lhs%E35,rhs%E1) + MATMUL(lhs%E3,rhs%E15) +  &
              MATMUL(lhs%E15,rhs%E3) + MATMUL(lhs%E5,rhs%E13) + MATMUL(lhs%E13,rhs%E5)
      res%E235 = MATMUL(lhs%R,rhs%E235) + MATMUL(lhs%E235,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E35) + MATMUL(lhs%E35,rhs%E2) + MATMUL(lhs%E3,rhs%E25) +  &
              MATMUL(lhs%E25,rhs%E3) + MATMUL(lhs%E5,rhs%E23) + MATMUL(lhs%E23,rhs%E5)
      res%E335 = MATMUL(lhs%R,rhs%E335) + MATMUL(lhs%E335,rhs%R) +  &
              MATMUL(lhs%E3,rhs%E35) + MATMUL(lhs%E35,rhs%E3) + MATMUL(lhs%E5,rhs%E33) + MATMUL(lhs%E33,rhs%E5)
      res%E145 = MATMUL(lhs%R,rhs%E145) + MATMUL(lhs%E145,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E45) + MATMUL(lhs%E45,rhs%E1) + MATMUL(lhs%E4,rhs%E15) +  &
              MATMUL(lhs%E15,rhs%E4) + MATMUL(lhs%E5,rhs%E14) + MATMUL(lhs%E14,rhs%E5)
      res%E245 = MATMUL(lhs%R,rhs%E245) + MATMUL(lhs%E245,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E45) + MATMUL(lhs%E45,rhs%E2) + MATMUL(lhs%E4,rhs%E25) +  &
              MATMUL(lhs%E25,rhs%E4) + MATMUL(lhs%E5,rhs%E24) + MATMUL(lhs%E24,rhs%E5)
      res%E345 = MATMUL(lhs%R,rhs%E345) + MATMUL(lhs%E345,rhs%R) +  &
              MATMUL(lhs%E3,rhs%E45) + MATMUL(lhs%E45,rhs%E3) + MATMUL(lhs%E4,rhs%E35) +  &
              MATMUL(lhs%E35,rhs%E4) + MATMUL(lhs%E5,rhs%E34) + MATMUL(lhs%E34,rhs%E5)
      res%E445 = MATMUL(lhs%R,rhs%E445) + MATMUL(lhs%E445,rhs%R) +  &
              MATMUL(lhs%E4,rhs%E45) + MATMUL(lhs%E45,rhs%E4) + MATMUL(lhs%E5,rhs%E44) + MATMUL(lhs%E44,rhs%E5)
      res%E155 = MATMUL(lhs%R,rhs%E155) + MATMUL(lhs%E155,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E55) + MATMUL(lhs%E55,rhs%E1) + MATMUL(lhs%E5,rhs%E15) + MATMUL(lhs%E15,rhs%E5)
      res%E255 = MATMUL(lhs%R,rhs%E255) + MATMUL(lhs%E255,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E55) + MATMUL(lhs%E55,rhs%E2) + MATMUL(lhs%E5,rhs%E25) + MATMUL(lhs%E25,rhs%E5)
      res%E355 = MATMUL(lhs%R,rhs%E355) + MATMUL(lhs%E355,rhs%R) +  &
              MATMUL(lhs%E3,rhs%E55) + MATMUL(lhs%E55,rhs%E3) + MATMUL(lhs%E5,rhs%E35) + MATMUL(lhs%E35,rhs%E5)
      res%E455 = MATMUL(lhs%R,rhs%E455) + MATMUL(lhs%E455,rhs%R) +  &
              MATMUL(lhs%E4,rhs%E55) + MATMUL(lhs%E55,rhs%E4) + MATMUL(lhs%E5,rhs%E45) + MATMUL(lhs%E45,rhs%E5)
      res%E555 = MATMUL(lhs%R,rhs%E555) + MATMUL(lhs%E555,rhs%R) +  &
              MATMUL(lhs%E5,rhs%E55) + MATMUL(lhs%E55,rhs%E5)
      res%E116 = MATMUL(lhs%R,rhs%E116) + MATMUL(lhs%E116,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E16) + MATMUL(lhs%E16,rhs%E1) + MATMUL(lhs%E6,rhs%E11) + MATMUL(lhs%E11,rhs%E6)
      res%E126 = MATMUL(lhs%R,rhs%E126) + MATMUL(lhs%E126,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E26) + MATMUL(lhs%E26,rhs%E1) + MATMUL(lhs%E2,rhs%E16) +  &
              MATMUL(lhs%E16,rhs%E2) + MATMUL(lhs%E6,rhs%E12) + MATMUL(lhs%E12,rhs%E6)
      res%E226 = MATMUL(lhs%R,rhs%E226) + MATMUL(lhs%E226,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E26) + MATMUL(lhs%E26,rhs%E2) + MATMUL(lhs%E6,rhs%E22) + MATMUL(lhs%E22,rhs%E6)
      res%E136 = MATMUL(lhs%R,rhs%E136) + MATMUL(lhs%E136,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E36) + MATMUL(lhs%E36,rhs%E1) + MATMUL(lhs%E3,rhs%E16) +  &
              MATMUL(lhs%E16,rhs%E3) + MATMUL(lhs%E6,rhs%E13) + MATMUL(lhs%E13,rhs%E6)
      res%E236 = MATMUL(lhs%R,rhs%E236) + MATMUL(lhs%E236,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E36) + MATMUL(lhs%E36,rhs%E2) + MATMUL(lhs%E3,rhs%E26) +  &
              MATMUL(lhs%E26,rhs%E3) + MATMUL(lhs%E6,rhs%E23) + MATMUL(lhs%E23,rhs%E6)
      res%E336 = MATMUL(lhs%R,rhs%E336) + MATMUL(lhs%E336,rhs%R) +  &
              MATMUL(lhs%E3,rhs%E36) + MATMUL(lhs%E36,rhs%E3) + MATMUL(lhs%E6,rhs%E33) + MATMUL(lhs%E33,rhs%E6)
      res%E146 = MATMUL(lhs%R,rhs%E146) + MATMUL(lhs%E146,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E46) + MATMUL(lhs%E46,rhs%E1) + MATMUL(lhs%E4,rhs%E16) +  &
              MATMUL(lhs%E16,rhs%E4) + MATMUL(lhs%E6,rhs%E14) + MATMUL(lhs%E14,rhs%E6)
      res%E246 = MATMUL(lhs%R,rhs%E246) + MATMUL(lhs%E246,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E46) + MATMUL(lhs%E46,rhs%E2) + MATMUL(lhs%E4,rhs%E26) +  &
              MATMUL(lhs%E26,rhs%E4) + MATMUL(lhs%E6,rhs%E24) + MATMUL(lhs%E24,rhs%E6)
      res%E346 = MATMUL(lhs%R,rhs%E346) + MATMUL(lhs%E346,rhs%R) +  &
              MATMUL(lhs%E3,rhs%E46) + MATMUL(lhs%E46,rhs%E3) + MATMUL(lhs%E4,rhs%E36) +  &
              MATMUL(lhs%E36,rhs%E4) + MATMUL(lhs%E6,rhs%E34) + MATMUL(lhs%E34,rhs%E6)
      res%E446 = MATMUL(lhs%R,rhs%E446) + MATMUL(lhs%E446,rhs%R) +  &
              MATMUL(lhs%E4,rhs%E46) + MATMUL(lhs%E46,rhs%E4) + MATMUL(lhs%E6,rhs%E44) + MATMUL(lhs%E44,rhs%E6)
      res%E156 = MATMUL(lhs%R,rhs%E156) + MATMUL(lhs%E156,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E56) + MATMUL(lhs%E56,rhs%E1) + MATMUL(lhs%E5,rhs%E16) +  &
              MATMUL(lhs%E16,rhs%E5) + MATMUL(lhs%E6,rhs%E15) + MATMUL(lhs%E15,rhs%E6)
      res%E256 = MATMUL(lhs%R,rhs%E256) + MATMUL(lhs%E256,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E56) + MATMUL(lhs%E56,rhs%E2) + MATMUL(lhs%E5,rhs%E26) +  &
              MATMUL(lhs%E26,rhs%E5) + MATMUL(lhs%E6,rhs%E25) + MATMUL(lhs%E25,rhs%E6)
      res%E356 = MATMUL(lhs%R,rhs%E356) + MATMUL(lhs%E356,rhs%R) +  &
              MATMUL(lhs%E3,rhs%E56) + MATMUL(lhs%E56,rhs%E3) + MATMUL(lhs%E5,rhs%E36) +  &
              MATMUL(lhs%E36,rhs%E5) + MATMUL(lhs%E6,rhs%E35) + MATMUL(lhs%E35,rhs%E6)
      res%E456 = MATMUL(lhs%R,rhs%E456) + MATMUL(lhs%E456,rhs%R) +  &
              MATMUL(lhs%E4,rhs%E56) + MATMUL(lhs%E56,rhs%E4) + MATMUL(lhs%E5,rhs%E46) +  &
              MATMUL(lhs%E46,rhs%E5) + MATMUL(lhs%E6,rhs%E45) + MATMUL(lhs%E45,rhs%E6)
      res%E556 = MATMUL(lhs%R,rhs%E556) + MATMUL(lhs%E556,rhs%R) +  &
              MATMUL(lhs%E5,rhs%E56) + MATMUL(lhs%E56,rhs%E5) + MATMUL(lhs%E6,rhs%E55) + MATMUL(lhs%E55,rhs%E6)
      res%E166 = MATMUL(lhs%R,rhs%E166) + MATMUL(lhs%E166,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E66) + MATMUL(lhs%E66,rhs%E1) + MATMUL(lhs%E6,rhs%E16) + MATMUL(lhs%E16,rhs%E6)
      res%E266 = MATMUL(lhs%R,rhs%E266) + MATMUL(lhs%E266,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E66) + MATMUL(lhs%E66,rhs%E2) + MATMUL(lhs%E6,rhs%E26) + MATMUL(lhs%E26,rhs%E6)
      res%E366 = MATMUL(lhs%R,rhs%E366) + MATMUL(lhs%E366,rhs%R) +  &
              MATMUL(lhs%E3,rhs%E66) + MATMUL(lhs%E66,rhs%E3) + MATMUL(lhs%E6,rhs%E36) + MATMUL(lhs%E36,rhs%E6)
      res%E466 = MATMUL(lhs%R,rhs%E466) + MATMUL(lhs%E466,rhs%R) +  &
              MATMUL(lhs%E4,rhs%E66) + MATMUL(lhs%E66,rhs%E4) + MATMUL(lhs%E6,rhs%E46) + MATMUL(lhs%E46,rhs%E6)
      res%E566 = MATMUL(lhs%R,rhs%E566) + MATMUL(lhs%E566,rhs%R) +  &
              MATMUL(lhs%E5,rhs%E66) + MATMUL(lhs%E66,rhs%E5) + MATMUL(lhs%E6,rhs%E56) + MATMUL(lhs%E56,rhs%E6)
      res%E666 = MATMUL(lhs%R,rhs%E666) + MATMUL(lhs%E666,rhs%R) +  &
              MATMUL(lhs%E6,rhs%E66) + MATMUL(lhs%E66,rhs%E6)
      res%E117 = MATMUL(lhs%R,rhs%E117) + MATMUL(lhs%E117,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E17) + MATMUL(lhs%E17,rhs%E1) + MATMUL(lhs%E7,rhs%E11) + MATMUL(lhs%E11,rhs%E7)
      res%E127 = MATMUL(lhs%R,rhs%E127) + MATMUL(lhs%E127,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E27) + MATMUL(lhs%E27,rhs%E1) + MATMUL(lhs%E2,rhs%E17) +  &
              MATMUL(lhs%E17,rhs%E2) + MATMUL(lhs%E7,rhs%E12) + MATMUL(lhs%E12,rhs%E7)
      res%E227 = MATMUL(lhs%R,rhs%E227) + MATMUL(lhs%E227,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E27) + MATMUL(lhs%E27,rhs%E2) + MATMUL(lhs%E7,rhs%E22) + MATMUL(lhs%E22,rhs%E7)
      res%E137 = MATMUL(lhs%R,rhs%E137) + MATMUL(lhs%E137,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E37) + MATMUL(lhs%E37,rhs%E1) + MATMUL(lhs%E3,rhs%E17) +  &
              MATMUL(lhs%E17,rhs%E3) + MATMUL(lhs%E7,rhs%E13) + MATMUL(lhs%E13,rhs%E7)
      res%E237 = MATMUL(lhs%R,rhs%E237) + MATMUL(lhs%E237,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E37) + MATMUL(lhs%E37,rhs%E2) + MATMUL(lhs%E3,rhs%E27) +  &
              MATMUL(lhs%E27,rhs%E3) + MATMUL(lhs%E7,rhs%E23) + MATMUL(lhs%E23,rhs%E7)
      res%E337 = MATMUL(lhs%R,rhs%E337) + MATMUL(lhs%E337,rhs%R) +  &
              MATMUL(lhs%E3,rhs%E37) + MATMUL(lhs%E37,rhs%E3) + MATMUL(lhs%E7,rhs%E33) + MATMUL(lhs%E33,rhs%E7)
      res%E147 = MATMUL(lhs%R,rhs%E147) + MATMUL(lhs%E147,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E47) + MATMUL(lhs%E47,rhs%E1) + MATMUL(lhs%E4,rhs%E17) +  &
              MATMUL(lhs%E17,rhs%E4) + MATMUL(lhs%E7,rhs%E14) + MATMUL(lhs%E14,rhs%E7)
      res%E247 = MATMUL(lhs%R,rhs%E247) + MATMUL(lhs%E247,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E47) + MATMUL(lhs%E47,rhs%E2) + MATMUL(lhs%E4,rhs%E27) +  &
              MATMUL(lhs%E27,rhs%E4) + MATMUL(lhs%E7,rhs%E24) + MATMUL(lhs%E24,rhs%E7)
      res%E347 = MATMUL(lhs%R,rhs%E347) + MATMUL(lhs%E347,rhs%R) +  &
              MATMUL(lhs%E3,rhs%E47) + MATMUL(lhs%E47,rhs%E3) + MATMUL(lhs%E4,rhs%E37) +  &
              MATMUL(lhs%E37,rhs%E4) + MATMUL(lhs%E7,rhs%E34) + MATMUL(lhs%E34,rhs%E7)
      res%E447 = MATMUL(lhs%R,rhs%E447) + MATMUL(lhs%E447,rhs%R) +  &
              MATMUL(lhs%E4,rhs%E47) + MATMUL(lhs%E47,rhs%E4) + MATMUL(lhs%E7,rhs%E44) + MATMUL(lhs%E44,rhs%E7)
      res%E157 = MATMUL(lhs%R,rhs%E157) + MATMUL(lhs%E157,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E57) + MATMUL(lhs%E57,rhs%E1) + MATMUL(lhs%E5,rhs%E17) +  &
              MATMUL(lhs%E17,rhs%E5) + MATMUL(lhs%E7,rhs%E15) + MATMUL(lhs%E15,rhs%E7)
      res%E257 = MATMUL(lhs%R,rhs%E257) + MATMUL(lhs%E257,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E57) + MATMUL(lhs%E57,rhs%E2) + MATMUL(lhs%E5,rhs%E27) +  &
              MATMUL(lhs%E27,rhs%E5) + MATMUL(lhs%E7,rhs%E25) + MATMUL(lhs%E25,rhs%E7)
      res%E357 = MATMUL(lhs%R,rhs%E357) + MATMUL(lhs%E357,rhs%R) +  &
              MATMUL(lhs%E3,rhs%E57) + MATMUL(lhs%E57,rhs%E3) + MATMUL(lhs%E5,rhs%E37) +  &
              MATMUL(lhs%E37,rhs%E5) + MATMUL(lhs%E7,rhs%E35) + MATMUL(lhs%E35,rhs%E7)
      res%E457 = MATMUL(lhs%R,rhs%E457) + MATMUL(lhs%E457,rhs%R) +  &
              MATMUL(lhs%E4,rhs%E57) + MATMUL(lhs%E57,rhs%E4) + MATMUL(lhs%E5,rhs%E47) +  &
              MATMUL(lhs%E47,rhs%E5) + MATMUL(lhs%E7,rhs%E45) + MATMUL(lhs%E45,rhs%E7)
      res%E557 = MATMUL(lhs%R,rhs%E557) + MATMUL(lhs%E557,rhs%R) +  &
              MATMUL(lhs%E5,rhs%E57) + MATMUL(lhs%E57,rhs%E5) + MATMUL(lhs%E7,rhs%E55) + MATMUL(lhs%E55,rhs%E7)
      res%E167 = MATMUL(lhs%R,rhs%E167) + MATMUL(lhs%E167,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E67) + MATMUL(lhs%E67,rhs%E1) + MATMUL(lhs%E6,rhs%E17) +  &
              MATMUL(lhs%E17,rhs%E6) + MATMUL(lhs%E7,rhs%E16) + MATMUL(lhs%E16,rhs%E7)
      res%E267 = MATMUL(lhs%R,rhs%E267) + MATMUL(lhs%E267,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E67) + MATMUL(lhs%E67,rhs%E2) + MATMUL(lhs%E6,rhs%E27) +  &
              MATMUL(lhs%E27,rhs%E6) + MATMUL(lhs%E7,rhs%E26) + MATMUL(lhs%E26,rhs%E7)
      res%E367 = MATMUL(lhs%R,rhs%E367) + MATMUL(lhs%E367,rhs%R) +  &
              MATMUL(lhs%E3,rhs%E67) + MATMUL(lhs%E67,rhs%E3) + MATMUL(lhs%E6,rhs%E37) +  &
              MATMUL(lhs%E37,rhs%E6) + MATMUL(lhs%E7,rhs%E36) + MATMUL(lhs%E36,rhs%E7)
      res%E467 = MATMUL(lhs%R,rhs%E467) + MATMUL(lhs%E467,rhs%R) +  &
              MATMUL(lhs%E4,rhs%E67) + MATMUL(lhs%E67,rhs%E4) + MATMUL(lhs%E6,rhs%E47) +  &
              MATMUL(lhs%E47,rhs%E6) + MATMUL(lhs%E7,rhs%E46) + MATMUL(lhs%E46,rhs%E7)
      res%E567 = MATMUL(lhs%R,rhs%E567) + MATMUL(lhs%E567,rhs%R) +  &
              MATMUL(lhs%E5,rhs%E67) + MATMUL(lhs%E67,rhs%E5) + MATMUL(lhs%E6,rhs%E57) +  &
              MATMUL(lhs%E57,rhs%E6) + MATMUL(lhs%E7,rhs%E56) + MATMUL(lhs%E56,rhs%E7)
      res%E667 = MATMUL(lhs%R,rhs%E667) + MATMUL(lhs%E667,rhs%R) +  &
              MATMUL(lhs%E6,rhs%E67) + MATMUL(lhs%E67,rhs%E6) + MATMUL(lhs%E7,rhs%E66) + MATMUL(lhs%E66,rhs%E7)
      res%E177 = MATMUL(lhs%R,rhs%E177) + MATMUL(lhs%E177,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E77) + MATMUL(lhs%E77,rhs%E1) + MATMUL(lhs%E7,rhs%E17) + MATMUL(lhs%E17,rhs%E7)
      res%E277 = MATMUL(lhs%R,rhs%E277) + MATMUL(lhs%E277,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E77) + MATMUL(lhs%E77,rhs%E2) + MATMUL(lhs%E7,rhs%E27) + MATMUL(lhs%E27,rhs%E7)
      res%E377 = MATMUL(lhs%R,rhs%E377) + MATMUL(lhs%E377,rhs%R) +  &
              MATMUL(lhs%E3,rhs%E77) + MATMUL(lhs%E77,rhs%E3) + MATMUL(lhs%E7,rhs%E37) + MATMUL(lhs%E37,rhs%E7)
      res%E477 = MATMUL(lhs%R,rhs%E477) + MATMUL(lhs%E477,rhs%R) +  &
              MATMUL(lhs%E4,rhs%E77) + MATMUL(lhs%E77,rhs%E4) + MATMUL(lhs%E7,rhs%E47) + MATMUL(lhs%E47,rhs%E7)
      res%E577 = MATMUL(lhs%R,rhs%E577) + MATMUL(lhs%E577,rhs%R) +  &
              MATMUL(lhs%E5,rhs%E77) + MATMUL(lhs%E77,rhs%E5) + MATMUL(lhs%E7,rhs%E57) + MATMUL(lhs%E57,rhs%E7)
      res%E677 = MATMUL(lhs%R,rhs%E677) + MATMUL(lhs%E677,rhs%R) +  &
              MATMUL(lhs%E6,rhs%E77) + MATMUL(lhs%E77,rhs%E6) + MATMUL(lhs%E7,rhs%E67) + MATMUL(lhs%E67,rhs%E7)
      res%E777 = MATMUL(lhs%R,rhs%E777) + MATMUL(lhs%E777,rhs%R) +  &
              MATMUL(lhs%E7,rhs%E77) + MATMUL(lhs%E77,rhs%E7)
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

   END FUNCTION ONUMM7N3_MATMUL_ONUMM7N3

   FUNCTION R_MATMUL_ONUMM7N3(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N3), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1),SIZE(RHS,2))

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

      ! Order 3
      res%E111 = MATMUL(lhs,rhs%E111)
      res%E112 = MATMUL(lhs,rhs%E112)
      res%E122 = MATMUL(lhs,rhs%E122)
      res%E222 = MATMUL(lhs,rhs%E222)
      res%E113 = MATMUL(lhs,rhs%E113)
      res%E123 = MATMUL(lhs,rhs%E123)
      res%E223 = MATMUL(lhs,rhs%E223)
      res%E133 = MATMUL(lhs,rhs%E133)
      res%E233 = MATMUL(lhs,rhs%E233)
      res%E333 = MATMUL(lhs,rhs%E333)
      res%E114 = MATMUL(lhs,rhs%E114)
      res%E124 = MATMUL(lhs,rhs%E124)
      res%E224 = MATMUL(lhs,rhs%E224)
      res%E134 = MATMUL(lhs,rhs%E134)
      res%E234 = MATMUL(lhs,rhs%E234)
      res%E334 = MATMUL(lhs,rhs%E334)
      res%E144 = MATMUL(lhs,rhs%E144)
      res%E244 = MATMUL(lhs,rhs%E244)
      res%E344 = MATMUL(lhs,rhs%E344)
      res%E444 = MATMUL(lhs,rhs%E444)
      res%E115 = MATMUL(lhs,rhs%E115)
      res%E125 = MATMUL(lhs,rhs%E125)
      res%E225 = MATMUL(lhs,rhs%E225)
      res%E135 = MATMUL(lhs,rhs%E135)
      res%E235 = MATMUL(lhs,rhs%E235)
      res%E335 = MATMUL(lhs,rhs%E335)
      res%E145 = MATMUL(lhs,rhs%E145)
      res%E245 = MATMUL(lhs,rhs%E245)
      res%E345 = MATMUL(lhs,rhs%E345)
      res%E445 = MATMUL(lhs,rhs%E445)
      res%E155 = MATMUL(lhs,rhs%E155)
      res%E255 = MATMUL(lhs,rhs%E255)
      res%E355 = MATMUL(lhs,rhs%E355)
      res%E455 = MATMUL(lhs,rhs%E455)
      res%E555 = MATMUL(lhs,rhs%E555)
      res%E116 = MATMUL(lhs,rhs%E116)
      res%E126 = MATMUL(lhs,rhs%E126)
      res%E226 = MATMUL(lhs,rhs%E226)
      res%E136 = MATMUL(lhs,rhs%E136)
      res%E236 = MATMUL(lhs,rhs%E236)
      res%E336 = MATMUL(lhs,rhs%E336)
      res%E146 = MATMUL(lhs,rhs%E146)
      res%E246 = MATMUL(lhs,rhs%E246)
      res%E346 = MATMUL(lhs,rhs%E346)
      res%E446 = MATMUL(lhs,rhs%E446)
      res%E156 = MATMUL(lhs,rhs%E156)
      res%E256 = MATMUL(lhs,rhs%E256)
      res%E356 = MATMUL(lhs,rhs%E356)
      res%E456 = MATMUL(lhs,rhs%E456)
      res%E556 = MATMUL(lhs,rhs%E556)
      res%E166 = MATMUL(lhs,rhs%E166)
      res%E266 = MATMUL(lhs,rhs%E266)
      res%E366 = MATMUL(lhs,rhs%E366)
      res%E466 = MATMUL(lhs,rhs%E466)
      res%E566 = MATMUL(lhs,rhs%E566)
      res%E666 = MATMUL(lhs,rhs%E666)
      res%E117 = MATMUL(lhs,rhs%E117)
      res%E127 = MATMUL(lhs,rhs%E127)
      res%E227 = MATMUL(lhs,rhs%E227)
      res%E137 = MATMUL(lhs,rhs%E137)
      res%E237 = MATMUL(lhs,rhs%E237)
      res%E337 = MATMUL(lhs,rhs%E337)
      res%E147 = MATMUL(lhs,rhs%E147)
      res%E247 = MATMUL(lhs,rhs%E247)
      res%E347 = MATMUL(lhs,rhs%E347)
      res%E447 = MATMUL(lhs,rhs%E447)
      res%E157 = MATMUL(lhs,rhs%E157)
      res%E257 = MATMUL(lhs,rhs%E257)
      res%E357 = MATMUL(lhs,rhs%E357)
      res%E457 = MATMUL(lhs,rhs%E457)
      res%E557 = MATMUL(lhs,rhs%E557)
      res%E167 = MATMUL(lhs,rhs%E167)
      res%E267 = MATMUL(lhs,rhs%E267)
      res%E367 = MATMUL(lhs,rhs%E367)
      res%E467 = MATMUL(lhs,rhs%E467)
      res%E567 = MATMUL(lhs,rhs%E567)
      res%E667 = MATMUL(lhs,rhs%E667)
      res%E177 = MATMUL(lhs,rhs%E177)
      res%E277 = MATMUL(lhs,rhs%E277)
      res%E377 = MATMUL(lhs,rhs%E377)
      res%E477 = MATMUL(lhs,rhs%E477)
      res%E577 = MATMUL(lhs,rhs%E577)
      res%E677 = MATMUL(lhs,rhs%E677)
      res%E777 = MATMUL(lhs,rhs%E777)

   END FUNCTION R_MATMUL_ONUMM7N3

   FUNCTION ONUMM7N3_MATMUL_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM7N3) :: RES(SIZE(LHS,1),SIZE(RHS,2))

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

      ! Order 3
      res%E111 = MATMUL(lhs%E111,rhs)
      res%E112 = MATMUL(lhs%E112,rhs)
      res%E122 = MATMUL(lhs%E122,rhs)
      res%E222 = MATMUL(lhs%E222,rhs)
      res%E113 = MATMUL(lhs%E113,rhs)
      res%E123 = MATMUL(lhs%E123,rhs)
      res%E223 = MATMUL(lhs%E223,rhs)
      res%E133 = MATMUL(lhs%E133,rhs)
      res%E233 = MATMUL(lhs%E233,rhs)
      res%E333 = MATMUL(lhs%E333,rhs)
      res%E114 = MATMUL(lhs%E114,rhs)
      res%E124 = MATMUL(lhs%E124,rhs)
      res%E224 = MATMUL(lhs%E224,rhs)
      res%E134 = MATMUL(lhs%E134,rhs)
      res%E234 = MATMUL(lhs%E234,rhs)
      res%E334 = MATMUL(lhs%E334,rhs)
      res%E144 = MATMUL(lhs%E144,rhs)
      res%E244 = MATMUL(lhs%E244,rhs)
      res%E344 = MATMUL(lhs%E344,rhs)
      res%E444 = MATMUL(lhs%E444,rhs)
      res%E115 = MATMUL(lhs%E115,rhs)
      res%E125 = MATMUL(lhs%E125,rhs)
      res%E225 = MATMUL(lhs%E225,rhs)
      res%E135 = MATMUL(lhs%E135,rhs)
      res%E235 = MATMUL(lhs%E235,rhs)
      res%E335 = MATMUL(lhs%E335,rhs)
      res%E145 = MATMUL(lhs%E145,rhs)
      res%E245 = MATMUL(lhs%E245,rhs)
      res%E345 = MATMUL(lhs%E345,rhs)
      res%E445 = MATMUL(lhs%E445,rhs)
      res%E155 = MATMUL(lhs%E155,rhs)
      res%E255 = MATMUL(lhs%E255,rhs)
      res%E355 = MATMUL(lhs%E355,rhs)
      res%E455 = MATMUL(lhs%E455,rhs)
      res%E555 = MATMUL(lhs%E555,rhs)
      res%E116 = MATMUL(lhs%E116,rhs)
      res%E126 = MATMUL(lhs%E126,rhs)
      res%E226 = MATMUL(lhs%E226,rhs)
      res%E136 = MATMUL(lhs%E136,rhs)
      res%E236 = MATMUL(lhs%E236,rhs)
      res%E336 = MATMUL(lhs%E336,rhs)
      res%E146 = MATMUL(lhs%E146,rhs)
      res%E246 = MATMUL(lhs%E246,rhs)
      res%E346 = MATMUL(lhs%E346,rhs)
      res%E446 = MATMUL(lhs%E446,rhs)
      res%E156 = MATMUL(lhs%E156,rhs)
      res%E256 = MATMUL(lhs%E256,rhs)
      res%E356 = MATMUL(lhs%E356,rhs)
      res%E456 = MATMUL(lhs%E456,rhs)
      res%E556 = MATMUL(lhs%E556,rhs)
      res%E166 = MATMUL(lhs%E166,rhs)
      res%E266 = MATMUL(lhs%E266,rhs)
      res%E366 = MATMUL(lhs%E366,rhs)
      res%E466 = MATMUL(lhs%E466,rhs)
      res%E566 = MATMUL(lhs%E566,rhs)
      res%E666 = MATMUL(lhs%E666,rhs)
      res%E117 = MATMUL(lhs%E117,rhs)
      res%E127 = MATMUL(lhs%E127,rhs)
      res%E227 = MATMUL(lhs%E227,rhs)
      res%E137 = MATMUL(lhs%E137,rhs)
      res%E237 = MATMUL(lhs%E237,rhs)
      res%E337 = MATMUL(lhs%E337,rhs)
      res%E147 = MATMUL(lhs%E147,rhs)
      res%E247 = MATMUL(lhs%E247,rhs)
      res%E347 = MATMUL(lhs%E347,rhs)
      res%E447 = MATMUL(lhs%E447,rhs)
      res%E157 = MATMUL(lhs%E157,rhs)
      res%E257 = MATMUL(lhs%E257,rhs)
      res%E357 = MATMUL(lhs%E357,rhs)
      res%E457 = MATMUL(lhs%E457,rhs)
      res%E557 = MATMUL(lhs%E557,rhs)
      res%E167 = MATMUL(lhs%E167,rhs)
      res%E267 = MATMUL(lhs%E267,rhs)
      res%E367 = MATMUL(lhs%E367,rhs)
      res%E467 = MATMUL(lhs%E467,rhs)
      res%E567 = MATMUL(lhs%E567,rhs)
      res%E667 = MATMUL(lhs%E667,rhs)
      res%E177 = MATMUL(lhs%E177,rhs)
      res%E277 = MATMUL(lhs%E277,rhs)
      res%E377 = MATMUL(lhs%E377,rhs)
      res%E477 = MATMUL(lhs%E477,rhs)
      res%E577 = MATMUL(lhs%E577,rhs)
      res%E677 = MATMUL(lhs%E677,rhs)
      res%E777 = MATMUL(lhs%E777,rhs)

   END FUNCTION ONUMM7N3_MATMUL_R

   FUNCTION ONUMM7N3_DOT_PRODUCT_ONUMM7N3(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:)
      TYPE(ONUMM7N3), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(ONUMM7N3) :: RES

      !  Multiplication like function 'DOT_PRODUCT(lhs,rhs)'
      ! Order 3
      res%E111 = DOT_PRODUCT(lhs%R,rhs%E111) + DOT_PRODUCT(lhs%E111,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E11) + DOT_PRODUCT(lhs%E11,rhs%E1)
      res%E112 = DOT_PRODUCT(lhs%R,rhs%E112) + DOT_PRODUCT(lhs%E112,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E12) + DOT_PRODUCT(lhs%E12,rhs%E1) + DOT_PRODUCT(lhs%E2,rhs%E11) + DOT_PRODUCT(lhs%E11,rhs%E2)
      res%E122 = DOT_PRODUCT(lhs%R,rhs%E122) + DOT_PRODUCT(lhs%E122,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E22) + DOT_PRODUCT(lhs%E22,rhs%E1) + DOT_PRODUCT(lhs%E2,rhs%E12) + DOT_PRODUCT(lhs%E12,rhs%E2)
      res%E222 = DOT_PRODUCT(lhs%R,rhs%E222) + DOT_PRODUCT(lhs%E222,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E22) + DOT_PRODUCT(lhs%E22,rhs%E2)
      res%E113 = DOT_PRODUCT(lhs%R,rhs%E113) + DOT_PRODUCT(lhs%E113,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E13) + DOT_PRODUCT(lhs%E13,rhs%E1) + DOT_PRODUCT(lhs%E3,rhs%E11) + DOT_PRODUCT(lhs%E11,rhs%E3)
      res%E123 = DOT_PRODUCT(lhs%R,rhs%E123) + DOT_PRODUCT(lhs%E123,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E23) + DOT_PRODUCT(lhs%E23,rhs%E1) + DOT_PRODUCT(lhs%E2,rhs%E13) +  &
              DOT_PRODUCT(lhs%E13,rhs%E2) + DOT_PRODUCT(lhs%E3,rhs%E12) + DOT_PRODUCT(lhs%E12,rhs%E3)
      res%E223 = DOT_PRODUCT(lhs%R,rhs%E223) + DOT_PRODUCT(lhs%E223,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E23) + DOT_PRODUCT(lhs%E23,rhs%E2) + DOT_PRODUCT(lhs%E3,rhs%E22) + DOT_PRODUCT(lhs%E22,rhs%E3)
      res%E133 = DOT_PRODUCT(lhs%R,rhs%E133) + DOT_PRODUCT(lhs%E133,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E33) + DOT_PRODUCT(lhs%E33,rhs%E1) + DOT_PRODUCT(lhs%E3,rhs%E13) + DOT_PRODUCT(lhs%E13,rhs%E3)
      res%E233 = DOT_PRODUCT(lhs%R,rhs%E233) + DOT_PRODUCT(lhs%E233,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E33) + DOT_PRODUCT(lhs%E33,rhs%E2) + DOT_PRODUCT(lhs%E3,rhs%E23) + DOT_PRODUCT(lhs%E23,rhs%E3)
      res%E333 = DOT_PRODUCT(lhs%R,rhs%E333) + DOT_PRODUCT(lhs%E333,rhs%R) +  &
              DOT_PRODUCT(lhs%E3,rhs%E33) + DOT_PRODUCT(lhs%E33,rhs%E3)
      res%E114 = DOT_PRODUCT(lhs%R,rhs%E114) + DOT_PRODUCT(lhs%E114,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E14) + DOT_PRODUCT(lhs%E14,rhs%E1) + DOT_PRODUCT(lhs%E4,rhs%E11) + DOT_PRODUCT(lhs%E11,rhs%E4)
      res%E124 = DOT_PRODUCT(lhs%R,rhs%E124) + DOT_PRODUCT(lhs%E124,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E24) + DOT_PRODUCT(lhs%E24,rhs%E1) + DOT_PRODUCT(lhs%E2,rhs%E14) +  &
              DOT_PRODUCT(lhs%E14,rhs%E2) + DOT_PRODUCT(lhs%E4,rhs%E12) + DOT_PRODUCT(lhs%E12,rhs%E4)
      res%E224 = DOT_PRODUCT(lhs%R,rhs%E224) + DOT_PRODUCT(lhs%E224,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E24) + DOT_PRODUCT(lhs%E24,rhs%E2) + DOT_PRODUCT(lhs%E4,rhs%E22) + DOT_PRODUCT(lhs%E22,rhs%E4)
      res%E134 = DOT_PRODUCT(lhs%R,rhs%E134) + DOT_PRODUCT(lhs%E134,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E34) + DOT_PRODUCT(lhs%E34,rhs%E1) + DOT_PRODUCT(lhs%E3,rhs%E14) +  &
              DOT_PRODUCT(lhs%E14,rhs%E3) + DOT_PRODUCT(lhs%E4,rhs%E13) + DOT_PRODUCT(lhs%E13,rhs%E4)
      res%E234 = DOT_PRODUCT(lhs%R,rhs%E234) + DOT_PRODUCT(lhs%E234,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E34) + DOT_PRODUCT(lhs%E34,rhs%E2) + DOT_PRODUCT(lhs%E3,rhs%E24) +  &
              DOT_PRODUCT(lhs%E24,rhs%E3) + DOT_PRODUCT(lhs%E4,rhs%E23) + DOT_PRODUCT(lhs%E23,rhs%E4)
      res%E334 = DOT_PRODUCT(lhs%R,rhs%E334) + DOT_PRODUCT(lhs%E334,rhs%R) +  &
              DOT_PRODUCT(lhs%E3,rhs%E34) + DOT_PRODUCT(lhs%E34,rhs%E3) + DOT_PRODUCT(lhs%E4,rhs%E33) + DOT_PRODUCT(lhs%E33,rhs%E4)
      res%E144 = DOT_PRODUCT(lhs%R,rhs%E144) + DOT_PRODUCT(lhs%E144,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E44) + DOT_PRODUCT(lhs%E44,rhs%E1) + DOT_PRODUCT(lhs%E4,rhs%E14) + DOT_PRODUCT(lhs%E14,rhs%E4)
      res%E244 = DOT_PRODUCT(lhs%R,rhs%E244) + DOT_PRODUCT(lhs%E244,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E44) + DOT_PRODUCT(lhs%E44,rhs%E2) + DOT_PRODUCT(lhs%E4,rhs%E24) + DOT_PRODUCT(lhs%E24,rhs%E4)
      res%E344 = DOT_PRODUCT(lhs%R,rhs%E344) + DOT_PRODUCT(lhs%E344,rhs%R) +  &
              DOT_PRODUCT(lhs%E3,rhs%E44) + DOT_PRODUCT(lhs%E44,rhs%E3) + DOT_PRODUCT(lhs%E4,rhs%E34) + DOT_PRODUCT(lhs%E34,rhs%E4)
      res%E444 = DOT_PRODUCT(lhs%R,rhs%E444) + DOT_PRODUCT(lhs%E444,rhs%R) +  &
              DOT_PRODUCT(lhs%E4,rhs%E44) + DOT_PRODUCT(lhs%E44,rhs%E4)
      res%E115 = DOT_PRODUCT(lhs%R,rhs%E115) + DOT_PRODUCT(lhs%E115,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E15) + DOT_PRODUCT(lhs%E15,rhs%E1) + DOT_PRODUCT(lhs%E5,rhs%E11) + DOT_PRODUCT(lhs%E11,rhs%E5)
      res%E125 = DOT_PRODUCT(lhs%R,rhs%E125) + DOT_PRODUCT(lhs%E125,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E25) + DOT_PRODUCT(lhs%E25,rhs%E1) + DOT_PRODUCT(lhs%E2,rhs%E15) +  &
              DOT_PRODUCT(lhs%E15,rhs%E2) + DOT_PRODUCT(lhs%E5,rhs%E12) + DOT_PRODUCT(lhs%E12,rhs%E5)
      res%E225 = DOT_PRODUCT(lhs%R,rhs%E225) + DOT_PRODUCT(lhs%E225,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E25) + DOT_PRODUCT(lhs%E25,rhs%E2) + DOT_PRODUCT(lhs%E5,rhs%E22) + DOT_PRODUCT(lhs%E22,rhs%E5)
      res%E135 = DOT_PRODUCT(lhs%R,rhs%E135) + DOT_PRODUCT(lhs%E135,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E35) + DOT_PRODUCT(lhs%E35,rhs%E1) + DOT_PRODUCT(lhs%E3,rhs%E15) +  &
              DOT_PRODUCT(lhs%E15,rhs%E3) + DOT_PRODUCT(lhs%E5,rhs%E13) + DOT_PRODUCT(lhs%E13,rhs%E5)
      res%E235 = DOT_PRODUCT(lhs%R,rhs%E235) + DOT_PRODUCT(lhs%E235,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E35) + DOT_PRODUCT(lhs%E35,rhs%E2) + DOT_PRODUCT(lhs%E3,rhs%E25) +  &
              DOT_PRODUCT(lhs%E25,rhs%E3) + DOT_PRODUCT(lhs%E5,rhs%E23) + DOT_PRODUCT(lhs%E23,rhs%E5)
      res%E335 = DOT_PRODUCT(lhs%R,rhs%E335) + DOT_PRODUCT(lhs%E335,rhs%R) +  &
              DOT_PRODUCT(lhs%E3,rhs%E35) + DOT_PRODUCT(lhs%E35,rhs%E3) + DOT_PRODUCT(lhs%E5,rhs%E33) + DOT_PRODUCT(lhs%E33,rhs%E5)
      res%E145 = DOT_PRODUCT(lhs%R,rhs%E145) + DOT_PRODUCT(lhs%E145,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E45) + DOT_PRODUCT(lhs%E45,rhs%E1) + DOT_PRODUCT(lhs%E4,rhs%E15) +  &
              DOT_PRODUCT(lhs%E15,rhs%E4) + DOT_PRODUCT(lhs%E5,rhs%E14) + DOT_PRODUCT(lhs%E14,rhs%E5)
      res%E245 = DOT_PRODUCT(lhs%R,rhs%E245) + DOT_PRODUCT(lhs%E245,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E45) + DOT_PRODUCT(lhs%E45,rhs%E2) + DOT_PRODUCT(lhs%E4,rhs%E25) +  &
              DOT_PRODUCT(lhs%E25,rhs%E4) + DOT_PRODUCT(lhs%E5,rhs%E24) + DOT_PRODUCT(lhs%E24,rhs%E5)
      res%E345 = DOT_PRODUCT(lhs%R,rhs%E345) + DOT_PRODUCT(lhs%E345,rhs%R) +  &
              DOT_PRODUCT(lhs%E3,rhs%E45) + DOT_PRODUCT(lhs%E45,rhs%E3) + DOT_PRODUCT(lhs%E4,rhs%E35) +  &
              DOT_PRODUCT(lhs%E35,rhs%E4) + DOT_PRODUCT(lhs%E5,rhs%E34) + DOT_PRODUCT(lhs%E34,rhs%E5)
      res%E445 = DOT_PRODUCT(lhs%R,rhs%E445) + DOT_PRODUCT(lhs%E445,rhs%R) +  &
              DOT_PRODUCT(lhs%E4,rhs%E45) + DOT_PRODUCT(lhs%E45,rhs%E4) + DOT_PRODUCT(lhs%E5,rhs%E44) + DOT_PRODUCT(lhs%E44,rhs%E5)
      res%E155 = DOT_PRODUCT(lhs%R,rhs%E155) + DOT_PRODUCT(lhs%E155,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E55) + DOT_PRODUCT(lhs%E55,rhs%E1) + DOT_PRODUCT(lhs%E5,rhs%E15) + DOT_PRODUCT(lhs%E15,rhs%E5)
      res%E255 = DOT_PRODUCT(lhs%R,rhs%E255) + DOT_PRODUCT(lhs%E255,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E55) + DOT_PRODUCT(lhs%E55,rhs%E2) + DOT_PRODUCT(lhs%E5,rhs%E25) + DOT_PRODUCT(lhs%E25,rhs%E5)
      res%E355 = DOT_PRODUCT(lhs%R,rhs%E355) + DOT_PRODUCT(lhs%E355,rhs%R) +  &
              DOT_PRODUCT(lhs%E3,rhs%E55) + DOT_PRODUCT(lhs%E55,rhs%E3) + DOT_PRODUCT(lhs%E5,rhs%E35) + DOT_PRODUCT(lhs%E35,rhs%E5)
      res%E455 = DOT_PRODUCT(lhs%R,rhs%E455) + DOT_PRODUCT(lhs%E455,rhs%R) +  &
              DOT_PRODUCT(lhs%E4,rhs%E55) + DOT_PRODUCT(lhs%E55,rhs%E4) + DOT_PRODUCT(lhs%E5,rhs%E45) + DOT_PRODUCT(lhs%E45,rhs%E5)
      res%E555 = DOT_PRODUCT(lhs%R,rhs%E555) + DOT_PRODUCT(lhs%E555,rhs%R) +  &
              DOT_PRODUCT(lhs%E5,rhs%E55) + DOT_PRODUCT(lhs%E55,rhs%E5)
      res%E116 = DOT_PRODUCT(lhs%R,rhs%E116) + DOT_PRODUCT(lhs%E116,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E16) + DOT_PRODUCT(lhs%E16,rhs%E1) + DOT_PRODUCT(lhs%E6,rhs%E11) + DOT_PRODUCT(lhs%E11,rhs%E6)
      res%E126 = DOT_PRODUCT(lhs%R,rhs%E126) + DOT_PRODUCT(lhs%E126,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E26) + DOT_PRODUCT(lhs%E26,rhs%E1) + DOT_PRODUCT(lhs%E2,rhs%E16) +  &
              DOT_PRODUCT(lhs%E16,rhs%E2) + DOT_PRODUCT(lhs%E6,rhs%E12) + DOT_PRODUCT(lhs%E12,rhs%E6)
      res%E226 = DOT_PRODUCT(lhs%R,rhs%E226) + DOT_PRODUCT(lhs%E226,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E26) + DOT_PRODUCT(lhs%E26,rhs%E2) + DOT_PRODUCT(lhs%E6,rhs%E22) + DOT_PRODUCT(lhs%E22,rhs%E6)
      res%E136 = DOT_PRODUCT(lhs%R,rhs%E136) + DOT_PRODUCT(lhs%E136,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E36) + DOT_PRODUCT(lhs%E36,rhs%E1) + DOT_PRODUCT(lhs%E3,rhs%E16) +  &
              DOT_PRODUCT(lhs%E16,rhs%E3) + DOT_PRODUCT(lhs%E6,rhs%E13) + DOT_PRODUCT(lhs%E13,rhs%E6)
      res%E236 = DOT_PRODUCT(lhs%R,rhs%E236) + DOT_PRODUCT(lhs%E236,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E36) + DOT_PRODUCT(lhs%E36,rhs%E2) + DOT_PRODUCT(lhs%E3,rhs%E26) +  &
              DOT_PRODUCT(lhs%E26,rhs%E3) + DOT_PRODUCT(lhs%E6,rhs%E23) + DOT_PRODUCT(lhs%E23,rhs%E6)
      res%E336 = DOT_PRODUCT(lhs%R,rhs%E336) + DOT_PRODUCT(lhs%E336,rhs%R) +  &
              DOT_PRODUCT(lhs%E3,rhs%E36) + DOT_PRODUCT(lhs%E36,rhs%E3) + DOT_PRODUCT(lhs%E6,rhs%E33) + DOT_PRODUCT(lhs%E33,rhs%E6)
      res%E146 = DOT_PRODUCT(lhs%R,rhs%E146) + DOT_PRODUCT(lhs%E146,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E46) + DOT_PRODUCT(lhs%E46,rhs%E1) + DOT_PRODUCT(lhs%E4,rhs%E16) +  &
              DOT_PRODUCT(lhs%E16,rhs%E4) + DOT_PRODUCT(lhs%E6,rhs%E14) + DOT_PRODUCT(lhs%E14,rhs%E6)
      res%E246 = DOT_PRODUCT(lhs%R,rhs%E246) + DOT_PRODUCT(lhs%E246,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E46) + DOT_PRODUCT(lhs%E46,rhs%E2) + DOT_PRODUCT(lhs%E4,rhs%E26) +  &
              DOT_PRODUCT(lhs%E26,rhs%E4) + DOT_PRODUCT(lhs%E6,rhs%E24) + DOT_PRODUCT(lhs%E24,rhs%E6)
      res%E346 = DOT_PRODUCT(lhs%R,rhs%E346) + DOT_PRODUCT(lhs%E346,rhs%R) +  &
              DOT_PRODUCT(lhs%E3,rhs%E46) + DOT_PRODUCT(lhs%E46,rhs%E3) + DOT_PRODUCT(lhs%E4,rhs%E36) +  &
              DOT_PRODUCT(lhs%E36,rhs%E4) + DOT_PRODUCT(lhs%E6,rhs%E34) + DOT_PRODUCT(lhs%E34,rhs%E6)
      res%E446 = DOT_PRODUCT(lhs%R,rhs%E446) + DOT_PRODUCT(lhs%E446,rhs%R) +  &
              DOT_PRODUCT(lhs%E4,rhs%E46) + DOT_PRODUCT(lhs%E46,rhs%E4) + DOT_PRODUCT(lhs%E6,rhs%E44) + DOT_PRODUCT(lhs%E44,rhs%E6)
      res%E156 = DOT_PRODUCT(lhs%R,rhs%E156) + DOT_PRODUCT(lhs%E156,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E56) + DOT_PRODUCT(lhs%E56,rhs%E1) + DOT_PRODUCT(lhs%E5,rhs%E16) +  &
              DOT_PRODUCT(lhs%E16,rhs%E5) + DOT_PRODUCT(lhs%E6,rhs%E15) + DOT_PRODUCT(lhs%E15,rhs%E6)
      res%E256 = DOT_PRODUCT(lhs%R,rhs%E256) + DOT_PRODUCT(lhs%E256,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E56) + DOT_PRODUCT(lhs%E56,rhs%E2) + DOT_PRODUCT(lhs%E5,rhs%E26) +  &
              DOT_PRODUCT(lhs%E26,rhs%E5) + DOT_PRODUCT(lhs%E6,rhs%E25) + DOT_PRODUCT(lhs%E25,rhs%E6)
      res%E356 = DOT_PRODUCT(lhs%R,rhs%E356) + DOT_PRODUCT(lhs%E356,rhs%R) +  &
              DOT_PRODUCT(lhs%E3,rhs%E56) + DOT_PRODUCT(lhs%E56,rhs%E3) + DOT_PRODUCT(lhs%E5,rhs%E36) +  &
              DOT_PRODUCT(lhs%E36,rhs%E5) + DOT_PRODUCT(lhs%E6,rhs%E35) + DOT_PRODUCT(lhs%E35,rhs%E6)
      res%E456 = DOT_PRODUCT(lhs%R,rhs%E456) + DOT_PRODUCT(lhs%E456,rhs%R) +  &
              DOT_PRODUCT(lhs%E4,rhs%E56) + DOT_PRODUCT(lhs%E56,rhs%E4) + DOT_PRODUCT(lhs%E5,rhs%E46) +  &
              DOT_PRODUCT(lhs%E46,rhs%E5) + DOT_PRODUCT(lhs%E6,rhs%E45) + DOT_PRODUCT(lhs%E45,rhs%E6)
      res%E556 = DOT_PRODUCT(lhs%R,rhs%E556) + DOT_PRODUCT(lhs%E556,rhs%R) +  &
              DOT_PRODUCT(lhs%E5,rhs%E56) + DOT_PRODUCT(lhs%E56,rhs%E5) + DOT_PRODUCT(lhs%E6,rhs%E55) + DOT_PRODUCT(lhs%E55,rhs%E6)
      res%E166 = DOT_PRODUCT(lhs%R,rhs%E166) + DOT_PRODUCT(lhs%E166,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E66) + DOT_PRODUCT(lhs%E66,rhs%E1) + DOT_PRODUCT(lhs%E6,rhs%E16) + DOT_PRODUCT(lhs%E16,rhs%E6)
      res%E266 = DOT_PRODUCT(lhs%R,rhs%E266) + DOT_PRODUCT(lhs%E266,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E66) + DOT_PRODUCT(lhs%E66,rhs%E2) + DOT_PRODUCT(lhs%E6,rhs%E26) + DOT_PRODUCT(lhs%E26,rhs%E6)
      res%E366 = DOT_PRODUCT(lhs%R,rhs%E366) + DOT_PRODUCT(lhs%E366,rhs%R) +  &
              DOT_PRODUCT(lhs%E3,rhs%E66) + DOT_PRODUCT(lhs%E66,rhs%E3) + DOT_PRODUCT(lhs%E6,rhs%E36) + DOT_PRODUCT(lhs%E36,rhs%E6)
      res%E466 = DOT_PRODUCT(lhs%R,rhs%E466) + DOT_PRODUCT(lhs%E466,rhs%R) +  &
              DOT_PRODUCT(lhs%E4,rhs%E66) + DOT_PRODUCT(lhs%E66,rhs%E4) + DOT_PRODUCT(lhs%E6,rhs%E46) + DOT_PRODUCT(lhs%E46,rhs%E6)
      res%E566 = DOT_PRODUCT(lhs%R,rhs%E566) + DOT_PRODUCT(lhs%E566,rhs%R) +  &
              DOT_PRODUCT(lhs%E5,rhs%E66) + DOT_PRODUCT(lhs%E66,rhs%E5) + DOT_PRODUCT(lhs%E6,rhs%E56) + DOT_PRODUCT(lhs%E56,rhs%E6)
      res%E666 = DOT_PRODUCT(lhs%R,rhs%E666) + DOT_PRODUCT(lhs%E666,rhs%R) +  &
              DOT_PRODUCT(lhs%E6,rhs%E66) + DOT_PRODUCT(lhs%E66,rhs%E6)
      res%E117 = DOT_PRODUCT(lhs%R,rhs%E117) + DOT_PRODUCT(lhs%E117,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E17) + DOT_PRODUCT(lhs%E17,rhs%E1) + DOT_PRODUCT(lhs%E7,rhs%E11) + DOT_PRODUCT(lhs%E11,rhs%E7)
      res%E127 = DOT_PRODUCT(lhs%R,rhs%E127) + DOT_PRODUCT(lhs%E127,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E27) + DOT_PRODUCT(lhs%E27,rhs%E1) + DOT_PRODUCT(lhs%E2,rhs%E17) +  &
              DOT_PRODUCT(lhs%E17,rhs%E2) + DOT_PRODUCT(lhs%E7,rhs%E12) + DOT_PRODUCT(lhs%E12,rhs%E7)
      res%E227 = DOT_PRODUCT(lhs%R,rhs%E227) + DOT_PRODUCT(lhs%E227,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E27) + DOT_PRODUCT(lhs%E27,rhs%E2) + DOT_PRODUCT(lhs%E7,rhs%E22) + DOT_PRODUCT(lhs%E22,rhs%E7)
      res%E137 = DOT_PRODUCT(lhs%R,rhs%E137) + DOT_PRODUCT(lhs%E137,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E37) + DOT_PRODUCT(lhs%E37,rhs%E1) + DOT_PRODUCT(lhs%E3,rhs%E17) +  &
              DOT_PRODUCT(lhs%E17,rhs%E3) + DOT_PRODUCT(lhs%E7,rhs%E13) + DOT_PRODUCT(lhs%E13,rhs%E7)
      res%E237 = DOT_PRODUCT(lhs%R,rhs%E237) + DOT_PRODUCT(lhs%E237,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E37) + DOT_PRODUCT(lhs%E37,rhs%E2) + DOT_PRODUCT(lhs%E3,rhs%E27) +  &
              DOT_PRODUCT(lhs%E27,rhs%E3) + DOT_PRODUCT(lhs%E7,rhs%E23) + DOT_PRODUCT(lhs%E23,rhs%E7)
      res%E337 = DOT_PRODUCT(lhs%R,rhs%E337) + DOT_PRODUCT(lhs%E337,rhs%R) +  &
              DOT_PRODUCT(lhs%E3,rhs%E37) + DOT_PRODUCT(lhs%E37,rhs%E3) + DOT_PRODUCT(lhs%E7,rhs%E33) + DOT_PRODUCT(lhs%E33,rhs%E7)
      res%E147 = DOT_PRODUCT(lhs%R,rhs%E147) + DOT_PRODUCT(lhs%E147,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E47) + DOT_PRODUCT(lhs%E47,rhs%E1) + DOT_PRODUCT(lhs%E4,rhs%E17) +  &
              DOT_PRODUCT(lhs%E17,rhs%E4) + DOT_PRODUCT(lhs%E7,rhs%E14) + DOT_PRODUCT(lhs%E14,rhs%E7)
      res%E247 = DOT_PRODUCT(lhs%R,rhs%E247) + DOT_PRODUCT(lhs%E247,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E47) + DOT_PRODUCT(lhs%E47,rhs%E2) + DOT_PRODUCT(lhs%E4,rhs%E27) +  &
              DOT_PRODUCT(lhs%E27,rhs%E4) + DOT_PRODUCT(lhs%E7,rhs%E24) + DOT_PRODUCT(lhs%E24,rhs%E7)
      res%E347 = DOT_PRODUCT(lhs%R,rhs%E347) + DOT_PRODUCT(lhs%E347,rhs%R) +  &
              DOT_PRODUCT(lhs%E3,rhs%E47) + DOT_PRODUCT(lhs%E47,rhs%E3) + DOT_PRODUCT(lhs%E4,rhs%E37) +  &
              DOT_PRODUCT(lhs%E37,rhs%E4) + DOT_PRODUCT(lhs%E7,rhs%E34) + DOT_PRODUCT(lhs%E34,rhs%E7)
      res%E447 = DOT_PRODUCT(lhs%R,rhs%E447) + DOT_PRODUCT(lhs%E447,rhs%R) +  &
              DOT_PRODUCT(lhs%E4,rhs%E47) + DOT_PRODUCT(lhs%E47,rhs%E4) + DOT_PRODUCT(lhs%E7,rhs%E44) + DOT_PRODUCT(lhs%E44,rhs%E7)
      res%E157 = DOT_PRODUCT(lhs%R,rhs%E157) + DOT_PRODUCT(lhs%E157,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E57) + DOT_PRODUCT(lhs%E57,rhs%E1) + DOT_PRODUCT(lhs%E5,rhs%E17) +  &
              DOT_PRODUCT(lhs%E17,rhs%E5) + DOT_PRODUCT(lhs%E7,rhs%E15) + DOT_PRODUCT(lhs%E15,rhs%E7)
      res%E257 = DOT_PRODUCT(lhs%R,rhs%E257) + DOT_PRODUCT(lhs%E257,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E57) + DOT_PRODUCT(lhs%E57,rhs%E2) + DOT_PRODUCT(lhs%E5,rhs%E27) +  &
              DOT_PRODUCT(lhs%E27,rhs%E5) + DOT_PRODUCT(lhs%E7,rhs%E25) + DOT_PRODUCT(lhs%E25,rhs%E7)
      res%E357 = DOT_PRODUCT(lhs%R,rhs%E357) + DOT_PRODUCT(lhs%E357,rhs%R) +  &
              DOT_PRODUCT(lhs%E3,rhs%E57) + DOT_PRODUCT(lhs%E57,rhs%E3) + DOT_PRODUCT(lhs%E5,rhs%E37) +  &
              DOT_PRODUCT(lhs%E37,rhs%E5) + DOT_PRODUCT(lhs%E7,rhs%E35) + DOT_PRODUCT(lhs%E35,rhs%E7)
      res%E457 = DOT_PRODUCT(lhs%R,rhs%E457) + DOT_PRODUCT(lhs%E457,rhs%R) +  &
              DOT_PRODUCT(lhs%E4,rhs%E57) + DOT_PRODUCT(lhs%E57,rhs%E4) + DOT_PRODUCT(lhs%E5,rhs%E47) +  &
              DOT_PRODUCT(lhs%E47,rhs%E5) + DOT_PRODUCT(lhs%E7,rhs%E45) + DOT_PRODUCT(lhs%E45,rhs%E7)
      res%E557 = DOT_PRODUCT(lhs%R,rhs%E557) + DOT_PRODUCT(lhs%E557,rhs%R) +  &
              DOT_PRODUCT(lhs%E5,rhs%E57) + DOT_PRODUCT(lhs%E57,rhs%E5) + DOT_PRODUCT(lhs%E7,rhs%E55) + DOT_PRODUCT(lhs%E55,rhs%E7)
      res%E167 = DOT_PRODUCT(lhs%R,rhs%E167) + DOT_PRODUCT(lhs%E167,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E67) + DOT_PRODUCT(lhs%E67,rhs%E1) + DOT_PRODUCT(lhs%E6,rhs%E17) +  &
              DOT_PRODUCT(lhs%E17,rhs%E6) + DOT_PRODUCT(lhs%E7,rhs%E16) + DOT_PRODUCT(lhs%E16,rhs%E7)
      res%E267 = DOT_PRODUCT(lhs%R,rhs%E267) + DOT_PRODUCT(lhs%E267,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E67) + DOT_PRODUCT(lhs%E67,rhs%E2) + DOT_PRODUCT(lhs%E6,rhs%E27) +  &
              DOT_PRODUCT(lhs%E27,rhs%E6) + DOT_PRODUCT(lhs%E7,rhs%E26) + DOT_PRODUCT(lhs%E26,rhs%E7)
      res%E367 = DOT_PRODUCT(lhs%R,rhs%E367) + DOT_PRODUCT(lhs%E367,rhs%R) +  &
              DOT_PRODUCT(lhs%E3,rhs%E67) + DOT_PRODUCT(lhs%E67,rhs%E3) + DOT_PRODUCT(lhs%E6,rhs%E37) +  &
              DOT_PRODUCT(lhs%E37,rhs%E6) + DOT_PRODUCT(lhs%E7,rhs%E36) + DOT_PRODUCT(lhs%E36,rhs%E7)
      res%E467 = DOT_PRODUCT(lhs%R,rhs%E467) + DOT_PRODUCT(lhs%E467,rhs%R) +  &
              DOT_PRODUCT(lhs%E4,rhs%E67) + DOT_PRODUCT(lhs%E67,rhs%E4) + DOT_PRODUCT(lhs%E6,rhs%E47) +  &
              DOT_PRODUCT(lhs%E47,rhs%E6) + DOT_PRODUCT(lhs%E7,rhs%E46) + DOT_PRODUCT(lhs%E46,rhs%E7)
      res%E567 = DOT_PRODUCT(lhs%R,rhs%E567) + DOT_PRODUCT(lhs%E567,rhs%R) +  &
              DOT_PRODUCT(lhs%E5,rhs%E67) + DOT_PRODUCT(lhs%E67,rhs%E5) + DOT_PRODUCT(lhs%E6,rhs%E57) +  &
              DOT_PRODUCT(lhs%E57,rhs%E6) + DOT_PRODUCT(lhs%E7,rhs%E56) + DOT_PRODUCT(lhs%E56,rhs%E7)
      res%E667 = DOT_PRODUCT(lhs%R,rhs%E667) + DOT_PRODUCT(lhs%E667,rhs%R) +  &
              DOT_PRODUCT(lhs%E6,rhs%E67) + DOT_PRODUCT(lhs%E67,rhs%E6) + DOT_PRODUCT(lhs%E7,rhs%E66) + DOT_PRODUCT(lhs%E66,rhs%E7)
      res%E177 = DOT_PRODUCT(lhs%R,rhs%E177) + DOT_PRODUCT(lhs%E177,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E77) + DOT_PRODUCT(lhs%E77,rhs%E1) + DOT_PRODUCT(lhs%E7,rhs%E17) + DOT_PRODUCT(lhs%E17,rhs%E7)
      res%E277 = DOT_PRODUCT(lhs%R,rhs%E277) + DOT_PRODUCT(lhs%E277,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E77) + DOT_PRODUCT(lhs%E77,rhs%E2) + DOT_PRODUCT(lhs%E7,rhs%E27) + DOT_PRODUCT(lhs%E27,rhs%E7)
      res%E377 = DOT_PRODUCT(lhs%R,rhs%E377) + DOT_PRODUCT(lhs%E377,rhs%R) +  &
              DOT_PRODUCT(lhs%E3,rhs%E77) + DOT_PRODUCT(lhs%E77,rhs%E3) + DOT_PRODUCT(lhs%E7,rhs%E37) + DOT_PRODUCT(lhs%E37,rhs%E7)
      res%E477 = DOT_PRODUCT(lhs%R,rhs%E477) + DOT_PRODUCT(lhs%E477,rhs%R) +  &
              DOT_PRODUCT(lhs%E4,rhs%E77) + DOT_PRODUCT(lhs%E77,rhs%E4) + DOT_PRODUCT(lhs%E7,rhs%E47) + DOT_PRODUCT(lhs%E47,rhs%E7)
      res%E577 = DOT_PRODUCT(lhs%R,rhs%E577) + DOT_PRODUCT(lhs%E577,rhs%R) +  &
              DOT_PRODUCT(lhs%E5,rhs%E77) + DOT_PRODUCT(lhs%E77,rhs%E5) + DOT_PRODUCT(lhs%E7,rhs%E57) + DOT_PRODUCT(lhs%E57,rhs%E7)
      res%E677 = DOT_PRODUCT(lhs%R,rhs%E677) + DOT_PRODUCT(lhs%E677,rhs%R) +  &
              DOT_PRODUCT(lhs%E6,rhs%E77) + DOT_PRODUCT(lhs%E77,rhs%E6) + DOT_PRODUCT(lhs%E7,rhs%E67) + DOT_PRODUCT(lhs%E67,rhs%E7)
      res%E777 = DOT_PRODUCT(lhs%R,rhs%E777) + DOT_PRODUCT(lhs%E777,rhs%R) +  &
              DOT_PRODUCT(lhs%E7,rhs%E77) + DOT_PRODUCT(lhs%E77,rhs%E7)
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

   END FUNCTION ONUMM7N3_DOT_PRODUCT_ONUMM7N3

   FUNCTION R_DOT_PRODUCT_ONUMM7N3(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(ONUMM7N3), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(ONUMM7N3) :: RES

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

      ! Order 3
      res%E111 = DOT_PRODUCT(lhs,rhs%E111)
      res%E112 = DOT_PRODUCT(lhs,rhs%E112)
      res%E122 = DOT_PRODUCT(lhs,rhs%E122)
      res%E222 = DOT_PRODUCT(lhs,rhs%E222)
      res%E113 = DOT_PRODUCT(lhs,rhs%E113)
      res%E123 = DOT_PRODUCT(lhs,rhs%E123)
      res%E223 = DOT_PRODUCT(lhs,rhs%E223)
      res%E133 = DOT_PRODUCT(lhs,rhs%E133)
      res%E233 = DOT_PRODUCT(lhs,rhs%E233)
      res%E333 = DOT_PRODUCT(lhs,rhs%E333)
      res%E114 = DOT_PRODUCT(lhs,rhs%E114)
      res%E124 = DOT_PRODUCT(lhs,rhs%E124)
      res%E224 = DOT_PRODUCT(lhs,rhs%E224)
      res%E134 = DOT_PRODUCT(lhs,rhs%E134)
      res%E234 = DOT_PRODUCT(lhs,rhs%E234)
      res%E334 = DOT_PRODUCT(lhs,rhs%E334)
      res%E144 = DOT_PRODUCT(lhs,rhs%E144)
      res%E244 = DOT_PRODUCT(lhs,rhs%E244)
      res%E344 = DOT_PRODUCT(lhs,rhs%E344)
      res%E444 = DOT_PRODUCT(lhs,rhs%E444)
      res%E115 = DOT_PRODUCT(lhs,rhs%E115)
      res%E125 = DOT_PRODUCT(lhs,rhs%E125)
      res%E225 = DOT_PRODUCT(lhs,rhs%E225)
      res%E135 = DOT_PRODUCT(lhs,rhs%E135)
      res%E235 = DOT_PRODUCT(lhs,rhs%E235)
      res%E335 = DOT_PRODUCT(lhs,rhs%E335)
      res%E145 = DOT_PRODUCT(lhs,rhs%E145)
      res%E245 = DOT_PRODUCT(lhs,rhs%E245)
      res%E345 = DOT_PRODUCT(lhs,rhs%E345)
      res%E445 = DOT_PRODUCT(lhs,rhs%E445)
      res%E155 = DOT_PRODUCT(lhs,rhs%E155)
      res%E255 = DOT_PRODUCT(lhs,rhs%E255)
      res%E355 = DOT_PRODUCT(lhs,rhs%E355)
      res%E455 = DOT_PRODUCT(lhs,rhs%E455)
      res%E555 = DOT_PRODUCT(lhs,rhs%E555)
      res%E116 = DOT_PRODUCT(lhs,rhs%E116)
      res%E126 = DOT_PRODUCT(lhs,rhs%E126)
      res%E226 = DOT_PRODUCT(lhs,rhs%E226)
      res%E136 = DOT_PRODUCT(lhs,rhs%E136)
      res%E236 = DOT_PRODUCT(lhs,rhs%E236)
      res%E336 = DOT_PRODUCT(lhs,rhs%E336)
      res%E146 = DOT_PRODUCT(lhs,rhs%E146)
      res%E246 = DOT_PRODUCT(lhs,rhs%E246)
      res%E346 = DOT_PRODUCT(lhs,rhs%E346)
      res%E446 = DOT_PRODUCT(lhs,rhs%E446)
      res%E156 = DOT_PRODUCT(lhs,rhs%E156)
      res%E256 = DOT_PRODUCT(lhs,rhs%E256)
      res%E356 = DOT_PRODUCT(lhs,rhs%E356)
      res%E456 = DOT_PRODUCT(lhs,rhs%E456)
      res%E556 = DOT_PRODUCT(lhs,rhs%E556)
      res%E166 = DOT_PRODUCT(lhs,rhs%E166)
      res%E266 = DOT_PRODUCT(lhs,rhs%E266)
      res%E366 = DOT_PRODUCT(lhs,rhs%E366)
      res%E466 = DOT_PRODUCT(lhs,rhs%E466)
      res%E566 = DOT_PRODUCT(lhs,rhs%E566)
      res%E666 = DOT_PRODUCT(lhs,rhs%E666)
      res%E117 = DOT_PRODUCT(lhs,rhs%E117)
      res%E127 = DOT_PRODUCT(lhs,rhs%E127)
      res%E227 = DOT_PRODUCT(lhs,rhs%E227)
      res%E137 = DOT_PRODUCT(lhs,rhs%E137)
      res%E237 = DOT_PRODUCT(lhs,rhs%E237)
      res%E337 = DOT_PRODUCT(lhs,rhs%E337)
      res%E147 = DOT_PRODUCT(lhs,rhs%E147)
      res%E247 = DOT_PRODUCT(lhs,rhs%E247)
      res%E347 = DOT_PRODUCT(lhs,rhs%E347)
      res%E447 = DOT_PRODUCT(lhs,rhs%E447)
      res%E157 = DOT_PRODUCT(lhs,rhs%E157)
      res%E257 = DOT_PRODUCT(lhs,rhs%E257)
      res%E357 = DOT_PRODUCT(lhs,rhs%E357)
      res%E457 = DOT_PRODUCT(lhs,rhs%E457)
      res%E557 = DOT_PRODUCT(lhs,rhs%E557)
      res%E167 = DOT_PRODUCT(lhs,rhs%E167)
      res%E267 = DOT_PRODUCT(lhs,rhs%E267)
      res%E367 = DOT_PRODUCT(lhs,rhs%E367)
      res%E467 = DOT_PRODUCT(lhs,rhs%E467)
      res%E567 = DOT_PRODUCT(lhs,rhs%E567)
      res%E667 = DOT_PRODUCT(lhs,rhs%E667)
      res%E177 = DOT_PRODUCT(lhs,rhs%E177)
      res%E277 = DOT_PRODUCT(lhs,rhs%E277)
      res%E377 = DOT_PRODUCT(lhs,rhs%E377)
      res%E477 = DOT_PRODUCT(lhs,rhs%E477)
      res%E577 = DOT_PRODUCT(lhs,rhs%E577)
      res%E677 = DOT_PRODUCT(lhs,rhs%E677)
      res%E777 = DOT_PRODUCT(lhs,rhs%E777)

   END FUNCTION R_DOT_PRODUCT_ONUMM7N3

   FUNCTION ONUMM7N3_DOT_PRODUCT_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(ONUMM7N3) :: RES

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

      ! Order 3
      res%E111 = DOT_PRODUCT(lhs%E111,rhs)
      res%E112 = DOT_PRODUCT(lhs%E112,rhs)
      res%E122 = DOT_PRODUCT(lhs%E122,rhs)
      res%E222 = DOT_PRODUCT(lhs%E222,rhs)
      res%E113 = DOT_PRODUCT(lhs%E113,rhs)
      res%E123 = DOT_PRODUCT(lhs%E123,rhs)
      res%E223 = DOT_PRODUCT(lhs%E223,rhs)
      res%E133 = DOT_PRODUCT(lhs%E133,rhs)
      res%E233 = DOT_PRODUCT(lhs%E233,rhs)
      res%E333 = DOT_PRODUCT(lhs%E333,rhs)
      res%E114 = DOT_PRODUCT(lhs%E114,rhs)
      res%E124 = DOT_PRODUCT(lhs%E124,rhs)
      res%E224 = DOT_PRODUCT(lhs%E224,rhs)
      res%E134 = DOT_PRODUCT(lhs%E134,rhs)
      res%E234 = DOT_PRODUCT(lhs%E234,rhs)
      res%E334 = DOT_PRODUCT(lhs%E334,rhs)
      res%E144 = DOT_PRODUCT(lhs%E144,rhs)
      res%E244 = DOT_PRODUCT(lhs%E244,rhs)
      res%E344 = DOT_PRODUCT(lhs%E344,rhs)
      res%E444 = DOT_PRODUCT(lhs%E444,rhs)
      res%E115 = DOT_PRODUCT(lhs%E115,rhs)
      res%E125 = DOT_PRODUCT(lhs%E125,rhs)
      res%E225 = DOT_PRODUCT(lhs%E225,rhs)
      res%E135 = DOT_PRODUCT(lhs%E135,rhs)
      res%E235 = DOT_PRODUCT(lhs%E235,rhs)
      res%E335 = DOT_PRODUCT(lhs%E335,rhs)
      res%E145 = DOT_PRODUCT(lhs%E145,rhs)
      res%E245 = DOT_PRODUCT(lhs%E245,rhs)
      res%E345 = DOT_PRODUCT(lhs%E345,rhs)
      res%E445 = DOT_PRODUCT(lhs%E445,rhs)
      res%E155 = DOT_PRODUCT(lhs%E155,rhs)
      res%E255 = DOT_PRODUCT(lhs%E255,rhs)
      res%E355 = DOT_PRODUCT(lhs%E355,rhs)
      res%E455 = DOT_PRODUCT(lhs%E455,rhs)
      res%E555 = DOT_PRODUCT(lhs%E555,rhs)
      res%E116 = DOT_PRODUCT(lhs%E116,rhs)
      res%E126 = DOT_PRODUCT(lhs%E126,rhs)
      res%E226 = DOT_PRODUCT(lhs%E226,rhs)
      res%E136 = DOT_PRODUCT(lhs%E136,rhs)
      res%E236 = DOT_PRODUCT(lhs%E236,rhs)
      res%E336 = DOT_PRODUCT(lhs%E336,rhs)
      res%E146 = DOT_PRODUCT(lhs%E146,rhs)
      res%E246 = DOT_PRODUCT(lhs%E246,rhs)
      res%E346 = DOT_PRODUCT(lhs%E346,rhs)
      res%E446 = DOT_PRODUCT(lhs%E446,rhs)
      res%E156 = DOT_PRODUCT(lhs%E156,rhs)
      res%E256 = DOT_PRODUCT(lhs%E256,rhs)
      res%E356 = DOT_PRODUCT(lhs%E356,rhs)
      res%E456 = DOT_PRODUCT(lhs%E456,rhs)
      res%E556 = DOT_PRODUCT(lhs%E556,rhs)
      res%E166 = DOT_PRODUCT(lhs%E166,rhs)
      res%E266 = DOT_PRODUCT(lhs%E266,rhs)
      res%E366 = DOT_PRODUCT(lhs%E366,rhs)
      res%E466 = DOT_PRODUCT(lhs%E466,rhs)
      res%E566 = DOT_PRODUCT(lhs%E566,rhs)
      res%E666 = DOT_PRODUCT(lhs%E666,rhs)
      res%E117 = DOT_PRODUCT(lhs%E117,rhs)
      res%E127 = DOT_PRODUCT(lhs%E127,rhs)
      res%E227 = DOT_PRODUCT(lhs%E227,rhs)
      res%E137 = DOT_PRODUCT(lhs%E137,rhs)
      res%E237 = DOT_PRODUCT(lhs%E237,rhs)
      res%E337 = DOT_PRODUCT(lhs%E337,rhs)
      res%E147 = DOT_PRODUCT(lhs%E147,rhs)
      res%E247 = DOT_PRODUCT(lhs%E247,rhs)
      res%E347 = DOT_PRODUCT(lhs%E347,rhs)
      res%E447 = DOT_PRODUCT(lhs%E447,rhs)
      res%E157 = DOT_PRODUCT(lhs%E157,rhs)
      res%E257 = DOT_PRODUCT(lhs%E257,rhs)
      res%E357 = DOT_PRODUCT(lhs%E357,rhs)
      res%E457 = DOT_PRODUCT(lhs%E457,rhs)
      res%E557 = DOT_PRODUCT(lhs%E557,rhs)
      res%E167 = DOT_PRODUCT(lhs%E167,rhs)
      res%E267 = DOT_PRODUCT(lhs%E267,rhs)
      res%E367 = DOT_PRODUCT(lhs%E367,rhs)
      res%E467 = DOT_PRODUCT(lhs%E467,rhs)
      res%E567 = DOT_PRODUCT(lhs%E567,rhs)
      res%E667 = DOT_PRODUCT(lhs%E667,rhs)
      res%E177 = DOT_PRODUCT(lhs%E177,rhs)
      res%E277 = DOT_PRODUCT(lhs%E277,rhs)
      res%E377 = DOT_PRODUCT(lhs%E377,rhs)
      res%E477 = DOT_PRODUCT(lhs%E477,rhs)
      res%E577 = DOT_PRODUCT(lhs%E577,rhs)
      res%E677 = DOT_PRODUCT(lhs%E677,rhs)
      res%E777 = DOT_PRODUCT(lhs%E777,rhs)

   END FUNCTION ONUMM7N3_DOT_PRODUCT_R

   FUNCTION ONUMM7N3_TRANSPOSE(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM7N3) :: RES (SIZE(LHS,2),SIZE(LHS,1))

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
      ! Order 3
      RES%E111 = TRANSPOSE(LHS%E111)
      RES%E112 = TRANSPOSE(LHS%E112)
      RES%E122 = TRANSPOSE(LHS%E122)
      RES%E222 = TRANSPOSE(LHS%E222)
      RES%E113 = TRANSPOSE(LHS%E113)
      RES%E123 = TRANSPOSE(LHS%E123)
      RES%E223 = TRANSPOSE(LHS%E223)
      RES%E133 = TRANSPOSE(LHS%E133)
      RES%E233 = TRANSPOSE(LHS%E233)
      RES%E333 = TRANSPOSE(LHS%E333)
      RES%E114 = TRANSPOSE(LHS%E114)
      RES%E124 = TRANSPOSE(LHS%E124)
      RES%E224 = TRANSPOSE(LHS%E224)
      RES%E134 = TRANSPOSE(LHS%E134)
      RES%E234 = TRANSPOSE(LHS%E234)
      RES%E334 = TRANSPOSE(LHS%E334)
      RES%E144 = TRANSPOSE(LHS%E144)
      RES%E244 = TRANSPOSE(LHS%E244)
      RES%E344 = TRANSPOSE(LHS%E344)
      RES%E444 = TRANSPOSE(LHS%E444)
      RES%E115 = TRANSPOSE(LHS%E115)
      RES%E125 = TRANSPOSE(LHS%E125)
      RES%E225 = TRANSPOSE(LHS%E225)
      RES%E135 = TRANSPOSE(LHS%E135)
      RES%E235 = TRANSPOSE(LHS%E235)
      RES%E335 = TRANSPOSE(LHS%E335)
      RES%E145 = TRANSPOSE(LHS%E145)
      RES%E245 = TRANSPOSE(LHS%E245)
      RES%E345 = TRANSPOSE(LHS%E345)
      RES%E445 = TRANSPOSE(LHS%E445)
      RES%E155 = TRANSPOSE(LHS%E155)
      RES%E255 = TRANSPOSE(LHS%E255)
      RES%E355 = TRANSPOSE(LHS%E355)
      RES%E455 = TRANSPOSE(LHS%E455)
      RES%E555 = TRANSPOSE(LHS%E555)
      RES%E116 = TRANSPOSE(LHS%E116)
      RES%E126 = TRANSPOSE(LHS%E126)
      RES%E226 = TRANSPOSE(LHS%E226)
      RES%E136 = TRANSPOSE(LHS%E136)
      RES%E236 = TRANSPOSE(LHS%E236)
      RES%E336 = TRANSPOSE(LHS%E336)
      RES%E146 = TRANSPOSE(LHS%E146)
      RES%E246 = TRANSPOSE(LHS%E246)
      RES%E346 = TRANSPOSE(LHS%E346)
      RES%E446 = TRANSPOSE(LHS%E446)
      RES%E156 = TRANSPOSE(LHS%E156)
      RES%E256 = TRANSPOSE(LHS%E256)
      RES%E356 = TRANSPOSE(LHS%E356)
      RES%E456 = TRANSPOSE(LHS%E456)
      RES%E556 = TRANSPOSE(LHS%E556)
      RES%E166 = TRANSPOSE(LHS%E166)
      RES%E266 = TRANSPOSE(LHS%E266)
      RES%E366 = TRANSPOSE(LHS%E366)
      RES%E466 = TRANSPOSE(LHS%E466)
      RES%E566 = TRANSPOSE(LHS%E566)
      RES%E666 = TRANSPOSE(LHS%E666)
      RES%E117 = TRANSPOSE(LHS%E117)
      RES%E127 = TRANSPOSE(LHS%E127)
      RES%E227 = TRANSPOSE(LHS%E227)
      RES%E137 = TRANSPOSE(LHS%E137)
      RES%E237 = TRANSPOSE(LHS%E237)
      RES%E337 = TRANSPOSE(LHS%E337)
      RES%E147 = TRANSPOSE(LHS%E147)
      RES%E247 = TRANSPOSE(LHS%E247)
      RES%E347 = TRANSPOSE(LHS%E347)
      RES%E447 = TRANSPOSE(LHS%E447)
      RES%E157 = TRANSPOSE(LHS%E157)
      RES%E257 = TRANSPOSE(LHS%E257)
      RES%E357 = TRANSPOSE(LHS%E357)
      RES%E457 = TRANSPOSE(LHS%E457)
      RES%E557 = TRANSPOSE(LHS%E557)
      RES%E167 = TRANSPOSE(LHS%E167)
      RES%E267 = TRANSPOSE(LHS%E267)
      RES%E367 = TRANSPOSE(LHS%E367)
      RES%E467 = TRANSPOSE(LHS%E467)
      RES%E567 = TRANSPOSE(LHS%E567)
      RES%E667 = TRANSPOSE(LHS%E667)
      RES%E177 = TRANSPOSE(LHS%E177)
      RES%E277 = TRANSPOSE(LHS%E277)
      RES%E377 = TRANSPOSE(LHS%E377)
      RES%E477 = TRANSPOSE(LHS%E477)
      RES%E577 = TRANSPOSE(LHS%E577)
      RES%E677 = TRANSPOSE(LHS%E677)
      RES%E777 = TRANSPOSE(LHS%E777)

   END FUNCTION ONUMM7N3_TRANSPOSE

FUNCTION ONUMM7N3_TO_CR_MAT_S(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: VAL
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
      ! R x E111 -> E111 (37, 37)
      RES(1+NROWS*36:NROWS*37,1+NCOLS*36:NCOLS*37) = VAL%R
      ! E111 x R -> E111 (37, 1)
      RES(1+NROWS*36:NROWS*37,1+NCOLS*0:NCOLS*1) = VAL%E111
      ! E1 x E11 -> E111 (37, 9)
      RES(1+NROWS*36:NROWS*37,1+NCOLS*8:NCOLS*9) = VAL%E1
      ! E11 x E1 -> E111 (37, 2)
      RES(1+NROWS*36:NROWS*37,1+NCOLS*1:NCOLS*2) = VAL%E11
      ! R x E112 -> E112 (38, 38)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*37:NCOLS*38) = VAL%R
      ! E112 x R -> E112 (38, 1)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*0:NCOLS*1) = VAL%E112
      ! E1 x E12 -> E112 (38, 10)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*9:NCOLS*10) = VAL%E1
      ! E12 x E1 -> E112 (38, 2)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*1:NCOLS*2) = VAL%E12
      ! E2 x E11 -> E112 (38, 9)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*8:NCOLS*9) = VAL%E2
      ! E11 x E2 -> E112 (38, 3)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*2:NCOLS*3) = VAL%E11
      ! R x E122 -> E122 (39, 39)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*38:NCOLS*39) = VAL%R
      ! E122 x R -> E122 (39, 1)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*0:NCOLS*1) = VAL%E122
      ! E1 x E22 -> E122 (39, 11)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*10:NCOLS*11) = VAL%E1
      ! E22 x E1 -> E122 (39, 2)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*1:NCOLS*2) = VAL%E22
      ! E2 x E12 -> E122 (39, 10)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*9:NCOLS*10) = VAL%E2
      ! E12 x E2 -> E122 (39, 3)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*2:NCOLS*3) = VAL%E12
      ! R x E222 -> E222 (40, 40)
      RES(1+NROWS*39:NROWS*40,1+NCOLS*39:NCOLS*40) = VAL%R
      ! E222 x R -> E222 (40, 1)
      RES(1+NROWS*39:NROWS*40,1+NCOLS*0:NCOLS*1) = VAL%E222
      ! E2 x E22 -> E222 (40, 11)
      RES(1+NROWS*39:NROWS*40,1+NCOLS*10:NCOLS*11) = VAL%E2
      ! E22 x E2 -> E222 (40, 3)
      RES(1+NROWS*39:NROWS*40,1+NCOLS*2:NCOLS*3) = VAL%E22
      ! R x E113 -> E113 (41, 41)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*40:NCOLS*41) = VAL%R
      ! E113 x R -> E113 (41, 1)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*0:NCOLS*1) = VAL%E113
      ! E1 x E13 -> E113 (41, 12)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*11:NCOLS*12) = VAL%E1
      ! E13 x E1 -> E113 (41, 2)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*1:NCOLS*2) = VAL%E13
      ! E3 x E11 -> E113 (41, 9)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*8:NCOLS*9) = VAL%E3
      ! E11 x E3 -> E113 (41, 4)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*3:NCOLS*4) = VAL%E11
      ! R x E123 -> E123 (42, 42)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*41:NCOLS*42) = VAL%R
      ! E123 x R -> E123 (42, 1)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*0:NCOLS*1) = VAL%E123
      ! E1 x E23 -> E123 (42, 13)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*12:NCOLS*13) = VAL%E1
      ! E23 x E1 -> E123 (42, 2)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*1:NCOLS*2) = VAL%E23
      ! E2 x E13 -> E123 (42, 12)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*11:NCOLS*12) = VAL%E2
      ! E13 x E2 -> E123 (42, 3)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*2:NCOLS*3) = VAL%E13
      ! E3 x E12 -> E123 (42, 10)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*9:NCOLS*10) = VAL%E3
      ! E12 x E3 -> E123 (42, 4)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*3:NCOLS*4) = VAL%E12
      ! R x E223 -> E223 (43, 43)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*42:NCOLS*43) = VAL%R
      ! E223 x R -> E223 (43, 1)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*0:NCOLS*1) = VAL%E223
      ! E2 x E23 -> E223 (43, 13)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*12:NCOLS*13) = VAL%E2
      ! E23 x E2 -> E223 (43, 3)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*2:NCOLS*3) = VAL%E23
      ! E3 x E22 -> E223 (43, 11)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*10:NCOLS*11) = VAL%E3
      ! E22 x E3 -> E223 (43, 4)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*3:NCOLS*4) = VAL%E22
      ! R x E133 -> E133 (44, 44)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*43:NCOLS*44) = VAL%R
      ! E133 x R -> E133 (44, 1)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*0:NCOLS*1) = VAL%E133
      ! E1 x E33 -> E133 (44, 14)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*13:NCOLS*14) = VAL%E1
      ! E33 x E1 -> E133 (44, 2)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*1:NCOLS*2) = VAL%E33
      ! E3 x E13 -> E133 (44, 12)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*11:NCOLS*12) = VAL%E3
      ! E13 x E3 -> E133 (44, 4)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*3:NCOLS*4) = VAL%E13
      ! R x E233 -> E233 (45, 45)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*44:NCOLS*45) = VAL%R
      ! E233 x R -> E233 (45, 1)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*0:NCOLS*1) = VAL%E233
      ! E2 x E33 -> E233 (45, 14)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*13:NCOLS*14) = VAL%E2
      ! E33 x E2 -> E233 (45, 3)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*2:NCOLS*3) = VAL%E33
      ! E3 x E23 -> E233 (45, 13)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*12:NCOLS*13) = VAL%E3
      ! E23 x E3 -> E233 (45, 4)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*3:NCOLS*4) = VAL%E23
      ! R x E333 -> E333 (46, 46)
      RES(1+NROWS*45:NROWS*46,1+NCOLS*45:NCOLS*46) = VAL%R
      ! E333 x R -> E333 (46, 1)
      RES(1+NROWS*45:NROWS*46,1+NCOLS*0:NCOLS*1) = VAL%E333
      ! E3 x E33 -> E333 (46, 14)
      RES(1+NROWS*45:NROWS*46,1+NCOLS*13:NCOLS*14) = VAL%E3
      ! E33 x E3 -> E333 (46, 4)
      RES(1+NROWS*45:NROWS*46,1+NCOLS*3:NCOLS*4) = VAL%E33
      ! R x E114 -> E114 (47, 47)
      RES(1+NROWS*46:NROWS*47,1+NCOLS*46:NCOLS*47) = VAL%R
      ! E114 x R -> E114 (47, 1)
      RES(1+NROWS*46:NROWS*47,1+NCOLS*0:NCOLS*1) = VAL%E114
      ! E1 x E14 -> E114 (47, 15)
      RES(1+NROWS*46:NROWS*47,1+NCOLS*14:NCOLS*15) = VAL%E1
      ! E14 x E1 -> E114 (47, 2)
      RES(1+NROWS*46:NROWS*47,1+NCOLS*1:NCOLS*2) = VAL%E14
      ! E4 x E11 -> E114 (47, 9)
      RES(1+NROWS*46:NROWS*47,1+NCOLS*8:NCOLS*9) = VAL%E4
      ! E11 x E4 -> E114 (47, 5)
      RES(1+NROWS*46:NROWS*47,1+NCOLS*4:NCOLS*5) = VAL%E11
      ! R x E124 -> E124 (48, 48)
      RES(1+NROWS*47:NROWS*48,1+NCOLS*47:NCOLS*48) = VAL%R
      ! E124 x R -> E124 (48, 1)
      RES(1+NROWS*47:NROWS*48,1+NCOLS*0:NCOLS*1) = VAL%E124
      ! E1 x E24 -> E124 (48, 16)
      RES(1+NROWS*47:NROWS*48,1+NCOLS*15:NCOLS*16) = VAL%E1
      ! E24 x E1 -> E124 (48, 2)
      RES(1+NROWS*47:NROWS*48,1+NCOLS*1:NCOLS*2) = VAL%E24
      ! E2 x E14 -> E124 (48, 15)
      RES(1+NROWS*47:NROWS*48,1+NCOLS*14:NCOLS*15) = VAL%E2
      ! E14 x E2 -> E124 (48, 3)
      RES(1+NROWS*47:NROWS*48,1+NCOLS*2:NCOLS*3) = VAL%E14
      ! E4 x E12 -> E124 (48, 10)
      RES(1+NROWS*47:NROWS*48,1+NCOLS*9:NCOLS*10) = VAL%E4
      ! E12 x E4 -> E124 (48, 5)
      RES(1+NROWS*47:NROWS*48,1+NCOLS*4:NCOLS*5) = VAL%E12
      ! R x E224 -> E224 (49, 49)
      RES(1+NROWS*48:NROWS*49,1+NCOLS*48:NCOLS*49) = VAL%R
      ! E224 x R -> E224 (49, 1)
      RES(1+NROWS*48:NROWS*49,1+NCOLS*0:NCOLS*1) = VAL%E224
      ! E2 x E24 -> E224 (49, 16)
      RES(1+NROWS*48:NROWS*49,1+NCOLS*15:NCOLS*16) = VAL%E2
      ! E24 x E2 -> E224 (49, 3)
      RES(1+NROWS*48:NROWS*49,1+NCOLS*2:NCOLS*3) = VAL%E24
      ! E4 x E22 -> E224 (49, 11)
      RES(1+NROWS*48:NROWS*49,1+NCOLS*10:NCOLS*11) = VAL%E4
      ! E22 x E4 -> E224 (49, 5)
      RES(1+NROWS*48:NROWS*49,1+NCOLS*4:NCOLS*5) = VAL%E22
      ! R x E134 -> E134 (50, 50)
      RES(1+NROWS*49:NROWS*50,1+NCOLS*49:NCOLS*50) = VAL%R
      ! E134 x R -> E134 (50, 1)
      RES(1+NROWS*49:NROWS*50,1+NCOLS*0:NCOLS*1) = VAL%E134
      ! E1 x E34 -> E134 (50, 17)
      RES(1+NROWS*49:NROWS*50,1+NCOLS*16:NCOLS*17) = VAL%E1
      ! E34 x E1 -> E134 (50, 2)
      RES(1+NROWS*49:NROWS*50,1+NCOLS*1:NCOLS*2) = VAL%E34
      ! E3 x E14 -> E134 (50, 15)
      RES(1+NROWS*49:NROWS*50,1+NCOLS*14:NCOLS*15) = VAL%E3
      ! E14 x E3 -> E134 (50, 4)
      RES(1+NROWS*49:NROWS*50,1+NCOLS*3:NCOLS*4) = VAL%E14
      ! E4 x E13 -> E134 (50, 12)
      RES(1+NROWS*49:NROWS*50,1+NCOLS*11:NCOLS*12) = VAL%E4
      ! E13 x E4 -> E134 (50, 5)
      RES(1+NROWS*49:NROWS*50,1+NCOLS*4:NCOLS*5) = VAL%E13
      ! R x E234 -> E234 (51, 51)
      RES(1+NROWS*50:NROWS*51,1+NCOLS*50:NCOLS*51) = VAL%R
      ! E234 x R -> E234 (51, 1)
      RES(1+NROWS*50:NROWS*51,1+NCOLS*0:NCOLS*1) = VAL%E234
      ! E2 x E34 -> E234 (51, 17)
      RES(1+NROWS*50:NROWS*51,1+NCOLS*16:NCOLS*17) = VAL%E2
      ! E34 x E2 -> E234 (51, 3)
      RES(1+NROWS*50:NROWS*51,1+NCOLS*2:NCOLS*3) = VAL%E34
      ! E3 x E24 -> E234 (51, 16)
      RES(1+NROWS*50:NROWS*51,1+NCOLS*15:NCOLS*16) = VAL%E3
      ! E24 x E3 -> E234 (51, 4)
      RES(1+NROWS*50:NROWS*51,1+NCOLS*3:NCOLS*4) = VAL%E24
      ! E4 x E23 -> E234 (51, 13)
      RES(1+NROWS*50:NROWS*51,1+NCOLS*12:NCOLS*13) = VAL%E4
      ! E23 x E4 -> E234 (51, 5)
      RES(1+NROWS*50:NROWS*51,1+NCOLS*4:NCOLS*5) = VAL%E23
      ! R x E334 -> E334 (52, 52)
      RES(1+NROWS*51:NROWS*52,1+NCOLS*51:NCOLS*52) = VAL%R
      ! E334 x R -> E334 (52, 1)
      RES(1+NROWS*51:NROWS*52,1+NCOLS*0:NCOLS*1) = VAL%E334
      ! E3 x E34 -> E334 (52, 17)
      RES(1+NROWS*51:NROWS*52,1+NCOLS*16:NCOLS*17) = VAL%E3
      ! E34 x E3 -> E334 (52, 4)
      RES(1+NROWS*51:NROWS*52,1+NCOLS*3:NCOLS*4) = VAL%E34
      ! E4 x E33 -> E334 (52, 14)
      RES(1+NROWS*51:NROWS*52,1+NCOLS*13:NCOLS*14) = VAL%E4
      ! E33 x E4 -> E334 (52, 5)
      RES(1+NROWS*51:NROWS*52,1+NCOLS*4:NCOLS*5) = VAL%E33
      ! R x E144 -> E144 (53, 53)
      RES(1+NROWS*52:NROWS*53,1+NCOLS*52:NCOLS*53) = VAL%R
      ! E144 x R -> E144 (53, 1)
      RES(1+NROWS*52:NROWS*53,1+NCOLS*0:NCOLS*1) = VAL%E144
      ! E1 x E44 -> E144 (53, 18)
      RES(1+NROWS*52:NROWS*53,1+NCOLS*17:NCOLS*18) = VAL%E1
      ! E44 x E1 -> E144 (53, 2)
      RES(1+NROWS*52:NROWS*53,1+NCOLS*1:NCOLS*2) = VAL%E44
      ! E4 x E14 -> E144 (53, 15)
      RES(1+NROWS*52:NROWS*53,1+NCOLS*14:NCOLS*15) = VAL%E4
      ! E14 x E4 -> E144 (53, 5)
      RES(1+NROWS*52:NROWS*53,1+NCOLS*4:NCOLS*5) = VAL%E14
      ! R x E244 -> E244 (54, 54)
      RES(1+NROWS*53:NROWS*54,1+NCOLS*53:NCOLS*54) = VAL%R
      ! E244 x R -> E244 (54, 1)
      RES(1+NROWS*53:NROWS*54,1+NCOLS*0:NCOLS*1) = VAL%E244
      ! E2 x E44 -> E244 (54, 18)
      RES(1+NROWS*53:NROWS*54,1+NCOLS*17:NCOLS*18) = VAL%E2
      ! E44 x E2 -> E244 (54, 3)
      RES(1+NROWS*53:NROWS*54,1+NCOLS*2:NCOLS*3) = VAL%E44
      ! E4 x E24 -> E244 (54, 16)
      RES(1+NROWS*53:NROWS*54,1+NCOLS*15:NCOLS*16) = VAL%E4
      ! E24 x E4 -> E244 (54, 5)
      RES(1+NROWS*53:NROWS*54,1+NCOLS*4:NCOLS*5) = VAL%E24
      ! R x E344 -> E344 (55, 55)
      RES(1+NROWS*54:NROWS*55,1+NCOLS*54:NCOLS*55) = VAL%R
      ! E344 x R -> E344 (55, 1)
      RES(1+NROWS*54:NROWS*55,1+NCOLS*0:NCOLS*1) = VAL%E344
      ! E3 x E44 -> E344 (55, 18)
      RES(1+NROWS*54:NROWS*55,1+NCOLS*17:NCOLS*18) = VAL%E3
      ! E44 x E3 -> E344 (55, 4)
      RES(1+NROWS*54:NROWS*55,1+NCOLS*3:NCOLS*4) = VAL%E44
      ! E4 x E34 -> E344 (55, 17)
      RES(1+NROWS*54:NROWS*55,1+NCOLS*16:NCOLS*17) = VAL%E4
      ! E34 x E4 -> E344 (55, 5)
      RES(1+NROWS*54:NROWS*55,1+NCOLS*4:NCOLS*5) = VAL%E34
      ! R x E444 -> E444 (56, 56)
      RES(1+NROWS*55:NROWS*56,1+NCOLS*55:NCOLS*56) = VAL%R
      ! E444 x R -> E444 (56, 1)
      RES(1+NROWS*55:NROWS*56,1+NCOLS*0:NCOLS*1) = VAL%E444
      ! E4 x E44 -> E444 (56, 18)
      RES(1+NROWS*55:NROWS*56,1+NCOLS*17:NCOLS*18) = VAL%E4
      ! E44 x E4 -> E444 (56, 5)
      RES(1+NROWS*55:NROWS*56,1+NCOLS*4:NCOLS*5) = VAL%E44
      ! R x E115 -> E115 (57, 57)
      RES(1+NROWS*56:NROWS*57,1+NCOLS*56:NCOLS*57) = VAL%R
      ! E115 x R -> E115 (57, 1)
      RES(1+NROWS*56:NROWS*57,1+NCOLS*0:NCOLS*1) = VAL%E115
      ! E1 x E15 -> E115 (57, 19)
      RES(1+NROWS*56:NROWS*57,1+NCOLS*18:NCOLS*19) = VAL%E1
      ! E15 x E1 -> E115 (57, 2)
      RES(1+NROWS*56:NROWS*57,1+NCOLS*1:NCOLS*2) = VAL%E15
      ! E5 x E11 -> E115 (57, 9)
      RES(1+NROWS*56:NROWS*57,1+NCOLS*8:NCOLS*9) = VAL%E5
      ! E11 x E5 -> E115 (57, 6)
      RES(1+NROWS*56:NROWS*57,1+NCOLS*5:NCOLS*6) = VAL%E11
      ! R x E125 -> E125 (58, 58)
      RES(1+NROWS*57:NROWS*58,1+NCOLS*57:NCOLS*58) = VAL%R
      ! E125 x R -> E125 (58, 1)
      RES(1+NROWS*57:NROWS*58,1+NCOLS*0:NCOLS*1) = VAL%E125
      ! E1 x E25 -> E125 (58, 20)
      RES(1+NROWS*57:NROWS*58,1+NCOLS*19:NCOLS*20) = VAL%E1
      ! E25 x E1 -> E125 (58, 2)
      RES(1+NROWS*57:NROWS*58,1+NCOLS*1:NCOLS*2) = VAL%E25
      ! E2 x E15 -> E125 (58, 19)
      RES(1+NROWS*57:NROWS*58,1+NCOLS*18:NCOLS*19) = VAL%E2
      ! E15 x E2 -> E125 (58, 3)
      RES(1+NROWS*57:NROWS*58,1+NCOLS*2:NCOLS*3) = VAL%E15
      ! E5 x E12 -> E125 (58, 10)
      RES(1+NROWS*57:NROWS*58,1+NCOLS*9:NCOLS*10) = VAL%E5
      ! E12 x E5 -> E125 (58, 6)
      RES(1+NROWS*57:NROWS*58,1+NCOLS*5:NCOLS*6) = VAL%E12
      ! R x E225 -> E225 (59, 59)
      RES(1+NROWS*58:NROWS*59,1+NCOLS*58:NCOLS*59) = VAL%R
      ! E225 x R -> E225 (59, 1)
      RES(1+NROWS*58:NROWS*59,1+NCOLS*0:NCOLS*1) = VAL%E225
      ! E2 x E25 -> E225 (59, 20)
      RES(1+NROWS*58:NROWS*59,1+NCOLS*19:NCOLS*20) = VAL%E2
      ! E25 x E2 -> E225 (59, 3)
      RES(1+NROWS*58:NROWS*59,1+NCOLS*2:NCOLS*3) = VAL%E25
      ! E5 x E22 -> E225 (59, 11)
      RES(1+NROWS*58:NROWS*59,1+NCOLS*10:NCOLS*11) = VAL%E5
      ! E22 x E5 -> E225 (59, 6)
      RES(1+NROWS*58:NROWS*59,1+NCOLS*5:NCOLS*6) = VAL%E22
      ! R x E135 -> E135 (60, 60)
      RES(1+NROWS*59:NROWS*60,1+NCOLS*59:NCOLS*60) = VAL%R
      ! E135 x R -> E135 (60, 1)
      RES(1+NROWS*59:NROWS*60,1+NCOLS*0:NCOLS*1) = VAL%E135
      ! E1 x E35 -> E135 (60, 21)
      RES(1+NROWS*59:NROWS*60,1+NCOLS*20:NCOLS*21) = VAL%E1
      ! E35 x E1 -> E135 (60, 2)
      RES(1+NROWS*59:NROWS*60,1+NCOLS*1:NCOLS*2) = VAL%E35
      ! E3 x E15 -> E135 (60, 19)
      RES(1+NROWS*59:NROWS*60,1+NCOLS*18:NCOLS*19) = VAL%E3
      ! E15 x E3 -> E135 (60, 4)
      RES(1+NROWS*59:NROWS*60,1+NCOLS*3:NCOLS*4) = VAL%E15
      ! E5 x E13 -> E135 (60, 12)
      RES(1+NROWS*59:NROWS*60,1+NCOLS*11:NCOLS*12) = VAL%E5
      ! E13 x E5 -> E135 (60, 6)
      RES(1+NROWS*59:NROWS*60,1+NCOLS*5:NCOLS*6) = VAL%E13
      ! R x E235 -> E235 (61, 61)
      RES(1+NROWS*60:NROWS*61,1+NCOLS*60:NCOLS*61) = VAL%R
      ! E235 x R -> E235 (61, 1)
      RES(1+NROWS*60:NROWS*61,1+NCOLS*0:NCOLS*1) = VAL%E235
      ! E2 x E35 -> E235 (61, 21)
      RES(1+NROWS*60:NROWS*61,1+NCOLS*20:NCOLS*21) = VAL%E2
      ! E35 x E2 -> E235 (61, 3)
      RES(1+NROWS*60:NROWS*61,1+NCOLS*2:NCOLS*3) = VAL%E35
      ! E3 x E25 -> E235 (61, 20)
      RES(1+NROWS*60:NROWS*61,1+NCOLS*19:NCOLS*20) = VAL%E3
      ! E25 x E3 -> E235 (61, 4)
      RES(1+NROWS*60:NROWS*61,1+NCOLS*3:NCOLS*4) = VAL%E25
      ! E5 x E23 -> E235 (61, 13)
      RES(1+NROWS*60:NROWS*61,1+NCOLS*12:NCOLS*13) = VAL%E5
      ! E23 x E5 -> E235 (61, 6)
      RES(1+NROWS*60:NROWS*61,1+NCOLS*5:NCOLS*6) = VAL%E23
      ! R x E335 -> E335 (62, 62)
      RES(1+NROWS*61:NROWS*62,1+NCOLS*61:NCOLS*62) = VAL%R
      ! E335 x R -> E335 (62, 1)
      RES(1+NROWS*61:NROWS*62,1+NCOLS*0:NCOLS*1) = VAL%E335
      ! E3 x E35 -> E335 (62, 21)
      RES(1+NROWS*61:NROWS*62,1+NCOLS*20:NCOLS*21) = VAL%E3
      ! E35 x E3 -> E335 (62, 4)
      RES(1+NROWS*61:NROWS*62,1+NCOLS*3:NCOLS*4) = VAL%E35
      ! E5 x E33 -> E335 (62, 14)
      RES(1+NROWS*61:NROWS*62,1+NCOLS*13:NCOLS*14) = VAL%E5
      ! E33 x E5 -> E335 (62, 6)
      RES(1+NROWS*61:NROWS*62,1+NCOLS*5:NCOLS*6) = VAL%E33
      ! R x E145 -> E145 (63, 63)
      RES(1+NROWS*62:NROWS*63,1+NCOLS*62:NCOLS*63) = VAL%R
      ! E145 x R -> E145 (63, 1)
      RES(1+NROWS*62:NROWS*63,1+NCOLS*0:NCOLS*1) = VAL%E145
      ! E1 x E45 -> E145 (63, 22)
      RES(1+NROWS*62:NROWS*63,1+NCOLS*21:NCOLS*22) = VAL%E1
      ! E45 x E1 -> E145 (63, 2)
      RES(1+NROWS*62:NROWS*63,1+NCOLS*1:NCOLS*2) = VAL%E45
      ! E4 x E15 -> E145 (63, 19)
      RES(1+NROWS*62:NROWS*63,1+NCOLS*18:NCOLS*19) = VAL%E4
      ! E15 x E4 -> E145 (63, 5)
      RES(1+NROWS*62:NROWS*63,1+NCOLS*4:NCOLS*5) = VAL%E15
      ! E5 x E14 -> E145 (63, 15)
      RES(1+NROWS*62:NROWS*63,1+NCOLS*14:NCOLS*15) = VAL%E5
      ! E14 x E5 -> E145 (63, 6)
      RES(1+NROWS*62:NROWS*63,1+NCOLS*5:NCOLS*6) = VAL%E14
      ! R x E245 -> E245 (64, 64)
      RES(1+NROWS*63:NROWS*64,1+NCOLS*63:NCOLS*64) = VAL%R
      ! E245 x R -> E245 (64, 1)
      RES(1+NROWS*63:NROWS*64,1+NCOLS*0:NCOLS*1) = VAL%E245
      ! E2 x E45 -> E245 (64, 22)
      RES(1+NROWS*63:NROWS*64,1+NCOLS*21:NCOLS*22) = VAL%E2
      ! E45 x E2 -> E245 (64, 3)
      RES(1+NROWS*63:NROWS*64,1+NCOLS*2:NCOLS*3) = VAL%E45
      ! E4 x E25 -> E245 (64, 20)
      RES(1+NROWS*63:NROWS*64,1+NCOLS*19:NCOLS*20) = VAL%E4
      ! E25 x E4 -> E245 (64, 5)
      RES(1+NROWS*63:NROWS*64,1+NCOLS*4:NCOLS*5) = VAL%E25
      ! E5 x E24 -> E245 (64, 16)
      RES(1+NROWS*63:NROWS*64,1+NCOLS*15:NCOLS*16) = VAL%E5
      ! E24 x E5 -> E245 (64, 6)
      RES(1+NROWS*63:NROWS*64,1+NCOLS*5:NCOLS*6) = VAL%E24
      ! R x E345 -> E345 (65, 65)
      RES(1+NROWS*64:NROWS*65,1+NCOLS*64:NCOLS*65) = VAL%R
      ! E345 x R -> E345 (65, 1)
      RES(1+NROWS*64:NROWS*65,1+NCOLS*0:NCOLS*1) = VAL%E345
      ! E3 x E45 -> E345 (65, 22)
      RES(1+NROWS*64:NROWS*65,1+NCOLS*21:NCOLS*22) = VAL%E3
      ! E45 x E3 -> E345 (65, 4)
      RES(1+NROWS*64:NROWS*65,1+NCOLS*3:NCOLS*4) = VAL%E45
      ! E4 x E35 -> E345 (65, 21)
      RES(1+NROWS*64:NROWS*65,1+NCOLS*20:NCOLS*21) = VAL%E4
      ! E35 x E4 -> E345 (65, 5)
      RES(1+NROWS*64:NROWS*65,1+NCOLS*4:NCOLS*5) = VAL%E35
      ! E5 x E34 -> E345 (65, 17)
      RES(1+NROWS*64:NROWS*65,1+NCOLS*16:NCOLS*17) = VAL%E5
      ! E34 x E5 -> E345 (65, 6)
      RES(1+NROWS*64:NROWS*65,1+NCOLS*5:NCOLS*6) = VAL%E34
      ! R x E445 -> E445 (66, 66)
      RES(1+NROWS*65:NROWS*66,1+NCOLS*65:NCOLS*66) = VAL%R
      ! E445 x R -> E445 (66, 1)
      RES(1+NROWS*65:NROWS*66,1+NCOLS*0:NCOLS*1) = VAL%E445
      ! E4 x E45 -> E445 (66, 22)
      RES(1+NROWS*65:NROWS*66,1+NCOLS*21:NCOLS*22) = VAL%E4
      ! E45 x E4 -> E445 (66, 5)
      RES(1+NROWS*65:NROWS*66,1+NCOLS*4:NCOLS*5) = VAL%E45
      ! E5 x E44 -> E445 (66, 18)
      RES(1+NROWS*65:NROWS*66,1+NCOLS*17:NCOLS*18) = VAL%E5
      ! E44 x E5 -> E445 (66, 6)
      RES(1+NROWS*65:NROWS*66,1+NCOLS*5:NCOLS*6) = VAL%E44
      ! R x E155 -> E155 (67, 67)
      RES(1+NROWS*66:NROWS*67,1+NCOLS*66:NCOLS*67) = VAL%R
      ! E155 x R -> E155 (67, 1)
      RES(1+NROWS*66:NROWS*67,1+NCOLS*0:NCOLS*1) = VAL%E155
      ! E1 x E55 -> E155 (67, 23)
      RES(1+NROWS*66:NROWS*67,1+NCOLS*22:NCOLS*23) = VAL%E1
      ! E55 x E1 -> E155 (67, 2)
      RES(1+NROWS*66:NROWS*67,1+NCOLS*1:NCOLS*2) = VAL%E55
      ! E5 x E15 -> E155 (67, 19)
      RES(1+NROWS*66:NROWS*67,1+NCOLS*18:NCOLS*19) = VAL%E5
      ! E15 x E5 -> E155 (67, 6)
      RES(1+NROWS*66:NROWS*67,1+NCOLS*5:NCOLS*6) = VAL%E15
      ! R x E255 -> E255 (68, 68)
      RES(1+NROWS*67:NROWS*68,1+NCOLS*67:NCOLS*68) = VAL%R
      ! E255 x R -> E255 (68, 1)
      RES(1+NROWS*67:NROWS*68,1+NCOLS*0:NCOLS*1) = VAL%E255
      ! E2 x E55 -> E255 (68, 23)
      RES(1+NROWS*67:NROWS*68,1+NCOLS*22:NCOLS*23) = VAL%E2
      ! E55 x E2 -> E255 (68, 3)
      RES(1+NROWS*67:NROWS*68,1+NCOLS*2:NCOLS*3) = VAL%E55
      ! E5 x E25 -> E255 (68, 20)
      RES(1+NROWS*67:NROWS*68,1+NCOLS*19:NCOLS*20) = VAL%E5
      ! E25 x E5 -> E255 (68, 6)
      RES(1+NROWS*67:NROWS*68,1+NCOLS*5:NCOLS*6) = VAL%E25
      ! R x E355 -> E355 (69, 69)
      RES(1+NROWS*68:NROWS*69,1+NCOLS*68:NCOLS*69) = VAL%R
      ! E355 x R -> E355 (69, 1)
      RES(1+NROWS*68:NROWS*69,1+NCOLS*0:NCOLS*1) = VAL%E355
      ! E3 x E55 -> E355 (69, 23)
      RES(1+NROWS*68:NROWS*69,1+NCOLS*22:NCOLS*23) = VAL%E3
      ! E55 x E3 -> E355 (69, 4)
      RES(1+NROWS*68:NROWS*69,1+NCOLS*3:NCOLS*4) = VAL%E55
      ! E5 x E35 -> E355 (69, 21)
      RES(1+NROWS*68:NROWS*69,1+NCOLS*20:NCOLS*21) = VAL%E5
      ! E35 x E5 -> E355 (69, 6)
      RES(1+NROWS*68:NROWS*69,1+NCOLS*5:NCOLS*6) = VAL%E35
      ! R x E455 -> E455 (70, 70)
      RES(1+NROWS*69:NROWS*70,1+NCOLS*69:NCOLS*70) = VAL%R
      ! E455 x R -> E455 (70, 1)
      RES(1+NROWS*69:NROWS*70,1+NCOLS*0:NCOLS*1) = VAL%E455
      ! E4 x E55 -> E455 (70, 23)
      RES(1+NROWS*69:NROWS*70,1+NCOLS*22:NCOLS*23) = VAL%E4
      ! E55 x E4 -> E455 (70, 5)
      RES(1+NROWS*69:NROWS*70,1+NCOLS*4:NCOLS*5) = VAL%E55
      ! E5 x E45 -> E455 (70, 22)
      RES(1+NROWS*69:NROWS*70,1+NCOLS*21:NCOLS*22) = VAL%E5
      ! E45 x E5 -> E455 (70, 6)
      RES(1+NROWS*69:NROWS*70,1+NCOLS*5:NCOLS*6) = VAL%E45
      ! R x E555 -> E555 (71, 71)
      RES(1+NROWS*70:NROWS*71,1+NCOLS*70:NCOLS*71) = VAL%R
      ! E555 x R -> E555 (71, 1)
      RES(1+NROWS*70:NROWS*71,1+NCOLS*0:NCOLS*1) = VAL%E555
      ! E5 x E55 -> E555 (71, 23)
      RES(1+NROWS*70:NROWS*71,1+NCOLS*22:NCOLS*23) = VAL%E5
      ! E55 x E5 -> E555 (71, 6)
      RES(1+NROWS*70:NROWS*71,1+NCOLS*5:NCOLS*6) = VAL%E55
      ! R x E116 -> E116 (72, 72)
      RES(1+NROWS*71:NROWS*72,1+NCOLS*71:NCOLS*72) = VAL%R
      ! E116 x R -> E116 (72, 1)
      RES(1+NROWS*71:NROWS*72,1+NCOLS*0:NCOLS*1) = VAL%E116
      ! E1 x E16 -> E116 (72, 24)
      RES(1+NROWS*71:NROWS*72,1+NCOLS*23:NCOLS*24) = VAL%E1
      ! E16 x E1 -> E116 (72, 2)
      RES(1+NROWS*71:NROWS*72,1+NCOLS*1:NCOLS*2) = VAL%E16
      ! E6 x E11 -> E116 (72, 9)
      RES(1+NROWS*71:NROWS*72,1+NCOLS*8:NCOLS*9) = VAL%E6
      ! E11 x E6 -> E116 (72, 7)
      RES(1+NROWS*71:NROWS*72,1+NCOLS*6:NCOLS*7) = VAL%E11
      ! R x E126 -> E126 (73, 73)
      RES(1+NROWS*72:NROWS*73,1+NCOLS*72:NCOLS*73) = VAL%R
      ! E126 x R -> E126 (73, 1)
      RES(1+NROWS*72:NROWS*73,1+NCOLS*0:NCOLS*1) = VAL%E126
      ! E1 x E26 -> E126 (73, 25)
      RES(1+NROWS*72:NROWS*73,1+NCOLS*24:NCOLS*25) = VAL%E1
      ! E26 x E1 -> E126 (73, 2)
      RES(1+NROWS*72:NROWS*73,1+NCOLS*1:NCOLS*2) = VAL%E26
      ! E2 x E16 -> E126 (73, 24)
      RES(1+NROWS*72:NROWS*73,1+NCOLS*23:NCOLS*24) = VAL%E2
      ! E16 x E2 -> E126 (73, 3)
      RES(1+NROWS*72:NROWS*73,1+NCOLS*2:NCOLS*3) = VAL%E16
      ! E6 x E12 -> E126 (73, 10)
      RES(1+NROWS*72:NROWS*73,1+NCOLS*9:NCOLS*10) = VAL%E6
      ! E12 x E6 -> E126 (73, 7)
      RES(1+NROWS*72:NROWS*73,1+NCOLS*6:NCOLS*7) = VAL%E12
      ! R x E226 -> E226 (74, 74)
      RES(1+NROWS*73:NROWS*74,1+NCOLS*73:NCOLS*74) = VAL%R
      ! E226 x R -> E226 (74, 1)
      RES(1+NROWS*73:NROWS*74,1+NCOLS*0:NCOLS*1) = VAL%E226
      ! E2 x E26 -> E226 (74, 25)
      RES(1+NROWS*73:NROWS*74,1+NCOLS*24:NCOLS*25) = VAL%E2
      ! E26 x E2 -> E226 (74, 3)
      RES(1+NROWS*73:NROWS*74,1+NCOLS*2:NCOLS*3) = VAL%E26
      ! E6 x E22 -> E226 (74, 11)
      RES(1+NROWS*73:NROWS*74,1+NCOLS*10:NCOLS*11) = VAL%E6
      ! E22 x E6 -> E226 (74, 7)
      RES(1+NROWS*73:NROWS*74,1+NCOLS*6:NCOLS*7) = VAL%E22
      ! R x E136 -> E136 (75, 75)
      RES(1+NROWS*74:NROWS*75,1+NCOLS*74:NCOLS*75) = VAL%R
      ! E136 x R -> E136 (75, 1)
      RES(1+NROWS*74:NROWS*75,1+NCOLS*0:NCOLS*1) = VAL%E136
      ! E1 x E36 -> E136 (75, 26)
      RES(1+NROWS*74:NROWS*75,1+NCOLS*25:NCOLS*26) = VAL%E1
      ! E36 x E1 -> E136 (75, 2)
      RES(1+NROWS*74:NROWS*75,1+NCOLS*1:NCOLS*2) = VAL%E36
      ! E3 x E16 -> E136 (75, 24)
      RES(1+NROWS*74:NROWS*75,1+NCOLS*23:NCOLS*24) = VAL%E3
      ! E16 x E3 -> E136 (75, 4)
      RES(1+NROWS*74:NROWS*75,1+NCOLS*3:NCOLS*4) = VAL%E16
      ! E6 x E13 -> E136 (75, 12)
      RES(1+NROWS*74:NROWS*75,1+NCOLS*11:NCOLS*12) = VAL%E6
      ! E13 x E6 -> E136 (75, 7)
      RES(1+NROWS*74:NROWS*75,1+NCOLS*6:NCOLS*7) = VAL%E13
      ! R x E236 -> E236 (76, 76)
      RES(1+NROWS*75:NROWS*76,1+NCOLS*75:NCOLS*76) = VAL%R
      ! E236 x R -> E236 (76, 1)
      RES(1+NROWS*75:NROWS*76,1+NCOLS*0:NCOLS*1) = VAL%E236
      ! E2 x E36 -> E236 (76, 26)
      RES(1+NROWS*75:NROWS*76,1+NCOLS*25:NCOLS*26) = VAL%E2
      ! E36 x E2 -> E236 (76, 3)
      RES(1+NROWS*75:NROWS*76,1+NCOLS*2:NCOLS*3) = VAL%E36
      ! E3 x E26 -> E236 (76, 25)
      RES(1+NROWS*75:NROWS*76,1+NCOLS*24:NCOLS*25) = VAL%E3
      ! E26 x E3 -> E236 (76, 4)
      RES(1+NROWS*75:NROWS*76,1+NCOLS*3:NCOLS*4) = VAL%E26
      ! E6 x E23 -> E236 (76, 13)
      RES(1+NROWS*75:NROWS*76,1+NCOLS*12:NCOLS*13) = VAL%E6
      ! E23 x E6 -> E236 (76, 7)
      RES(1+NROWS*75:NROWS*76,1+NCOLS*6:NCOLS*7) = VAL%E23
      ! R x E336 -> E336 (77, 77)
      RES(1+NROWS*76:NROWS*77,1+NCOLS*76:NCOLS*77) = VAL%R
      ! E336 x R -> E336 (77, 1)
      RES(1+NROWS*76:NROWS*77,1+NCOLS*0:NCOLS*1) = VAL%E336
      ! E3 x E36 -> E336 (77, 26)
      RES(1+NROWS*76:NROWS*77,1+NCOLS*25:NCOLS*26) = VAL%E3
      ! E36 x E3 -> E336 (77, 4)
      RES(1+NROWS*76:NROWS*77,1+NCOLS*3:NCOLS*4) = VAL%E36
      ! E6 x E33 -> E336 (77, 14)
      RES(1+NROWS*76:NROWS*77,1+NCOLS*13:NCOLS*14) = VAL%E6
      ! E33 x E6 -> E336 (77, 7)
      RES(1+NROWS*76:NROWS*77,1+NCOLS*6:NCOLS*7) = VAL%E33
      ! R x E146 -> E146 (78, 78)
      RES(1+NROWS*77:NROWS*78,1+NCOLS*77:NCOLS*78) = VAL%R
      ! E146 x R -> E146 (78, 1)
      RES(1+NROWS*77:NROWS*78,1+NCOLS*0:NCOLS*1) = VAL%E146
      ! E1 x E46 -> E146 (78, 27)
      RES(1+NROWS*77:NROWS*78,1+NCOLS*26:NCOLS*27) = VAL%E1
      ! E46 x E1 -> E146 (78, 2)
      RES(1+NROWS*77:NROWS*78,1+NCOLS*1:NCOLS*2) = VAL%E46
      ! E4 x E16 -> E146 (78, 24)
      RES(1+NROWS*77:NROWS*78,1+NCOLS*23:NCOLS*24) = VAL%E4
      ! E16 x E4 -> E146 (78, 5)
      RES(1+NROWS*77:NROWS*78,1+NCOLS*4:NCOLS*5) = VAL%E16
      ! E6 x E14 -> E146 (78, 15)
      RES(1+NROWS*77:NROWS*78,1+NCOLS*14:NCOLS*15) = VAL%E6
      ! E14 x E6 -> E146 (78, 7)
      RES(1+NROWS*77:NROWS*78,1+NCOLS*6:NCOLS*7) = VAL%E14
      ! R x E246 -> E246 (79, 79)
      RES(1+NROWS*78:NROWS*79,1+NCOLS*78:NCOLS*79) = VAL%R
      ! E246 x R -> E246 (79, 1)
      RES(1+NROWS*78:NROWS*79,1+NCOLS*0:NCOLS*1) = VAL%E246
      ! E2 x E46 -> E246 (79, 27)
      RES(1+NROWS*78:NROWS*79,1+NCOLS*26:NCOLS*27) = VAL%E2
      ! E46 x E2 -> E246 (79, 3)
      RES(1+NROWS*78:NROWS*79,1+NCOLS*2:NCOLS*3) = VAL%E46
      ! E4 x E26 -> E246 (79, 25)
      RES(1+NROWS*78:NROWS*79,1+NCOLS*24:NCOLS*25) = VAL%E4
      ! E26 x E4 -> E246 (79, 5)
      RES(1+NROWS*78:NROWS*79,1+NCOLS*4:NCOLS*5) = VAL%E26
      ! E6 x E24 -> E246 (79, 16)
      RES(1+NROWS*78:NROWS*79,1+NCOLS*15:NCOLS*16) = VAL%E6
      ! E24 x E6 -> E246 (79, 7)
      RES(1+NROWS*78:NROWS*79,1+NCOLS*6:NCOLS*7) = VAL%E24
      ! R x E346 -> E346 (80, 80)
      RES(1+NROWS*79:NROWS*80,1+NCOLS*79:NCOLS*80) = VAL%R
      ! E346 x R -> E346 (80, 1)
      RES(1+NROWS*79:NROWS*80,1+NCOLS*0:NCOLS*1) = VAL%E346
      ! E3 x E46 -> E346 (80, 27)
      RES(1+NROWS*79:NROWS*80,1+NCOLS*26:NCOLS*27) = VAL%E3
      ! E46 x E3 -> E346 (80, 4)
      RES(1+NROWS*79:NROWS*80,1+NCOLS*3:NCOLS*4) = VAL%E46
      ! E4 x E36 -> E346 (80, 26)
      RES(1+NROWS*79:NROWS*80,1+NCOLS*25:NCOLS*26) = VAL%E4
      ! E36 x E4 -> E346 (80, 5)
      RES(1+NROWS*79:NROWS*80,1+NCOLS*4:NCOLS*5) = VAL%E36
      ! E6 x E34 -> E346 (80, 17)
      RES(1+NROWS*79:NROWS*80,1+NCOLS*16:NCOLS*17) = VAL%E6
      ! E34 x E6 -> E346 (80, 7)
      RES(1+NROWS*79:NROWS*80,1+NCOLS*6:NCOLS*7) = VAL%E34
      ! R x E446 -> E446 (81, 81)
      RES(1+NROWS*80:NROWS*81,1+NCOLS*80:NCOLS*81) = VAL%R
      ! E446 x R -> E446 (81, 1)
      RES(1+NROWS*80:NROWS*81,1+NCOLS*0:NCOLS*1) = VAL%E446
      ! E4 x E46 -> E446 (81, 27)
      RES(1+NROWS*80:NROWS*81,1+NCOLS*26:NCOLS*27) = VAL%E4
      ! E46 x E4 -> E446 (81, 5)
      RES(1+NROWS*80:NROWS*81,1+NCOLS*4:NCOLS*5) = VAL%E46
      ! E6 x E44 -> E446 (81, 18)
      RES(1+NROWS*80:NROWS*81,1+NCOLS*17:NCOLS*18) = VAL%E6
      ! E44 x E6 -> E446 (81, 7)
      RES(1+NROWS*80:NROWS*81,1+NCOLS*6:NCOLS*7) = VAL%E44
      ! R x E156 -> E156 (82, 82)
      RES(1+NROWS*81:NROWS*82,1+NCOLS*81:NCOLS*82) = VAL%R
      ! E156 x R -> E156 (82, 1)
      RES(1+NROWS*81:NROWS*82,1+NCOLS*0:NCOLS*1) = VAL%E156
      ! E1 x E56 -> E156 (82, 28)
      RES(1+NROWS*81:NROWS*82,1+NCOLS*27:NCOLS*28) = VAL%E1
      ! E56 x E1 -> E156 (82, 2)
      RES(1+NROWS*81:NROWS*82,1+NCOLS*1:NCOLS*2) = VAL%E56
      ! E5 x E16 -> E156 (82, 24)
      RES(1+NROWS*81:NROWS*82,1+NCOLS*23:NCOLS*24) = VAL%E5
      ! E16 x E5 -> E156 (82, 6)
      RES(1+NROWS*81:NROWS*82,1+NCOLS*5:NCOLS*6) = VAL%E16
      ! E6 x E15 -> E156 (82, 19)
      RES(1+NROWS*81:NROWS*82,1+NCOLS*18:NCOLS*19) = VAL%E6
      ! E15 x E6 -> E156 (82, 7)
      RES(1+NROWS*81:NROWS*82,1+NCOLS*6:NCOLS*7) = VAL%E15
      ! R x E256 -> E256 (83, 83)
      RES(1+NROWS*82:NROWS*83,1+NCOLS*82:NCOLS*83) = VAL%R
      ! E256 x R -> E256 (83, 1)
      RES(1+NROWS*82:NROWS*83,1+NCOLS*0:NCOLS*1) = VAL%E256
      ! E2 x E56 -> E256 (83, 28)
      RES(1+NROWS*82:NROWS*83,1+NCOLS*27:NCOLS*28) = VAL%E2
      ! E56 x E2 -> E256 (83, 3)
      RES(1+NROWS*82:NROWS*83,1+NCOLS*2:NCOLS*3) = VAL%E56
      ! E5 x E26 -> E256 (83, 25)
      RES(1+NROWS*82:NROWS*83,1+NCOLS*24:NCOLS*25) = VAL%E5
      ! E26 x E5 -> E256 (83, 6)
      RES(1+NROWS*82:NROWS*83,1+NCOLS*5:NCOLS*6) = VAL%E26
      ! E6 x E25 -> E256 (83, 20)
      RES(1+NROWS*82:NROWS*83,1+NCOLS*19:NCOLS*20) = VAL%E6
      ! E25 x E6 -> E256 (83, 7)
      RES(1+NROWS*82:NROWS*83,1+NCOLS*6:NCOLS*7) = VAL%E25
      ! R x E356 -> E356 (84, 84)
      RES(1+NROWS*83:NROWS*84,1+NCOLS*83:NCOLS*84) = VAL%R
      ! E356 x R -> E356 (84, 1)
      RES(1+NROWS*83:NROWS*84,1+NCOLS*0:NCOLS*1) = VAL%E356
      ! E3 x E56 -> E356 (84, 28)
      RES(1+NROWS*83:NROWS*84,1+NCOLS*27:NCOLS*28) = VAL%E3
      ! E56 x E3 -> E356 (84, 4)
      RES(1+NROWS*83:NROWS*84,1+NCOLS*3:NCOLS*4) = VAL%E56
      ! E5 x E36 -> E356 (84, 26)
      RES(1+NROWS*83:NROWS*84,1+NCOLS*25:NCOLS*26) = VAL%E5
      ! E36 x E5 -> E356 (84, 6)
      RES(1+NROWS*83:NROWS*84,1+NCOLS*5:NCOLS*6) = VAL%E36
      ! E6 x E35 -> E356 (84, 21)
      RES(1+NROWS*83:NROWS*84,1+NCOLS*20:NCOLS*21) = VAL%E6
      ! E35 x E6 -> E356 (84, 7)
      RES(1+NROWS*83:NROWS*84,1+NCOLS*6:NCOLS*7) = VAL%E35
      ! R x E456 -> E456 (85, 85)
      RES(1+NROWS*84:NROWS*85,1+NCOLS*84:NCOLS*85) = VAL%R
      ! E456 x R -> E456 (85, 1)
      RES(1+NROWS*84:NROWS*85,1+NCOLS*0:NCOLS*1) = VAL%E456
      ! E4 x E56 -> E456 (85, 28)
      RES(1+NROWS*84:NROWS*85,1+NCOLS*27:NCOLS*28) = VAL%E4
      ! E56 x E4 -> E456 (85, 5)
      RES(1+NROWS*84:NROWS*85,1+NCOLS*4:NCOLS*5) = VAL%E56
      ! E5 x E46 -> E456 (85, 27)
      RES(1+NROWS*84:NROWS*85,1+NCOLS*26:NCOLS*27) = VAL%E5
      ! E46 x E5 -> E456 (85, 6)
      RES(1+NROWS*84:NROWS*85,1+NCOLS*5:NCOLS*6) = VAL%E46
      ! E6 x E45 -> E456 (85, 22)
      RES(1+NROWS*84:NROWS*85,1+NCOLS*21:NCOLS*22) = VAL%E6
      ! E45 x E6 -> E456 (85, 7)
      RES(1+NROWS*84:NROWS*85,1+NCOLS*6:NCOLS*7) = VAL%E45
      ! R x E556 -> E556 (86, 86)
      RES(1+NROWS*85:NROWS*86,1+NCOLS*85:NCOLS*86) = VAL%R
      ! E556 x R -> E556 (86, 1)
      RES(1+NROWS*85:NROWS*86,1+NCOLS*0:NCOLS*1) = VAL%E556
      ! E5 x E56 -> E556 (86, 28)
      RES(1+NROWS*85:NROWS*86,1+NCOLS*27:NCOLS*28) = VAL%E5
      ! E56 x E5 -> E556 (86, 6)
      RES(1+NROWS*85:NROWS*86,1+NCOLS*5:NCOLS*6) = VAL%E56
      ! E6 x E55 -> E556 (86, 23)
      RES(1+NROWS*85:NROWS*86,1+NCOLS*22:NCOLS*23) = VAL%E6
      ! E55 x E6 -> E556 (86, 7)
      RES(1+NROWS*85:NROWS*86,1+NCOLS*6:NCOLS*7) = VAL%E55
      ! R x E166 -> E166 (87, 87)
      RES(1+NROWS*86:NROWS*87,1+NCOLS*86:NCOLS*87) = VAL%R
      ! E166 x R -> E166 (87, 1)
      RES(1+NROWS*86:NROWS*87,1+NCOLS*0:NCOLS*1) = VAL%E166
      ! E1 x E66 -> E166 (87, 29)
      RES(1+NROWS*86:NROWS*87,1+NCOLS*28:NCOLS*29) = VAL%E1
      ! E66 x E1 -> E166 (87, 2)
      RES(1+NROWS*86:NROWS*87,1+NCOLS*1:NCOLS*2) = VAL%E66
      ! E6 x E16 -> E166 (87, 24)
      RES(1+NROWS*86:NROWS*87,1+NCOLS*23:NCOLS*24) = VAL%E6
      ! E16 x E6 -> E166 (87, 7)
      RES(1+NROWS*86:NROWS*87,1+NCOLS*6:NCOLS*7) = VAL%E16
      ! R x E266 -> E266 (88, 88)
      RES(1+NROWS*87:NROWS*88,1+NCOLS*87:NCOLS*88) = VAL%R
      ! E266 x R -> E266 (88, 1)
      RES(1+NROWS*87:NROWS*88,1+NCOLS*0:NCOLS*1) = VAL%E266
      ! E2 x E66 -> E266 (88, 29)
      RES(1+NROWS*87:NROWS*88,1+NCOLS*28:NCOLS*29) = VAL%E2
      ! E66 x E2 -> E266 (88, 3)
      RES(1+NROWS*87:NROWS*88,1+NCOLS*2:NCOLS*3) = VAL%E66
      ! E6 x E26 -> E266 (88, 25)
      RES(1+NROWS*87:NROWS*88,1+NCOLS*24:NCOLS*25) = VAL%E6
      ! E26 x E6 -> E266 (88, 7)
      RES(1+NROWS*87:NROWS*88,1+NCOLS*6:NCOLS*7) = VAL%E26
      ! R x E366 -> E366 (89, 89)
      RES(1+NROWS*88:NROWS*89,1+NCOLS*88:NCOLS*89) = VAL%R
      ! E366 x R -> E366 (89, 1)
      RES(1+NROWS*88:NROWS*89,1+NCOLS*0:NCOLS*1) = VAL%E366
      ! E3 x E66 -> E366 (89, 29)
      RES(1+NROWS*88:NROWS*89,1+NCOLS*28:NCOLS*29) = VAL%E3
      ! E66 x E3 -> E366 (89, 4)
      RES(1+NROWS*88:NROWS*89,1+NCOLS*3:NCOLS*4) = VAL%E66
      ! E6 x E36 -> E366 (89, 26)
      RES(1+NROWS*88:NROWS*89,1+NCOLS*25:NCOLS*26) = VAL%E6
      ! E36 x E6 -> E366 (89, 7)
      RES(1+NROWS*88:NROWS*89,1+NCOLS*6:NCOLS*7) = VAL%E36
      ! R x E466 -> E466 (90, 90)
      RES(1+NROWS*89:NROWS*90,1+NCOLS*89:NCOLS*90) = VAL%R
      ! E466 x R -> E466 (90, 1)
      RES(1+NROWS*89:NROWS*90,1+NCOLS*0:NCOLS*1) = VAL%E466
      ! E4 x E66 -> E466 (90, 29)
      RES(1+NROWS*89:NROWS*90,1+NCOLS*28:NCOLS*29) = VAL%E4
      ! E66 x E4 -> E466 (90, 5)
      RES(1+NROWS*89:NROWS*90,1+NCOLS*4:NCOLS*5) = VAL%E66
      ! E6 x E46 -> E466 (90, 27)
      RES(1+NROWS*89:NROWS*90,1+NCOLS*26:NCOLS*27) = VAL%E6
      ! E46 x E6 -> E466 (90, 7)
      RES(1+NROWS*89:NROWS*90,1+NCOLS*6:NCOLS*7) = VAL%E46
      ! R x E566 -> E566 (91, 91)
      RES(1+NROWS*90:NROWS*91,1+NCOLS*90:NCOLS*91) = VAL%R
      ! E566 x R -> E566 (91, 1)
      RES(1+NROWS*90:NROWS*91,1+NCOLS*0:NCOLS*1) = VAL%E566
      ! E5 x E66 -> E566 (91, 29)
      RES(1+NROWS*90:NROWS*91,1+NCOLS*28:NCOLS*29) = VAL%E5
      ! E66 x E5 -> E566 (91, 6)
      RES(1+NROWS*90:NROWS*91,1+NCOLS*5:NCOLS*6) = VAL%E66
      ! E6 x E56 -> E566 (91, 28)
      RES(1+NROWS*90:NROWS*91,1+NCOLS*27:NCOLS*28) = VAL%E6
      ! E56 x E6 -> E566 (91, 7)
      RES(1+NROWS*90:NROWS*91,1+NCOLS*6:NCOLS*7) = VAL%E56
      ! R x E666 -> E666 (92, 92)
      RES(1+NROWS*91:NROWS*92,1+NCOLS*91:NCOLS*92) = VAL%R
      ! E666 x R -> E666 (92, 1)
      RES(1+NROWS*91:NROWS*92,1+NCOLS*0:NCOLS*1) = VAL%E666
      ! E6 x E66 -> E666 (92, 29)
      RES(1+NROWS*91:NROWS*92,1+NCOLS*28:NCOLS*29) = VAL%E6
      ! E66 x E6 -> E666 (92, 7)
      RES(1+NROWS*91:NROWS*92,1+NCOLS*6:NCOLS*7) = VAL%E66
      ! R x E117 -> E117 (93, 93)
      RES(1+NROWS*92:NROWS*93,1+NCOLS*92:NCOLS*93) = VAL%R
      ! E117 x R -> E117 (93, 1)
      RES(1+NROWS*92:NROWS*93,1+NCOLS*0:NCOLS*1) = VAL%E117
      ! E1 x E17 -> E117 (93, 30)
      RES(1+NROWS*92:NROWS*93,1+NCOLS*29:NCOLS*30) = VAL%E1
      ! E17 x E1 -> E117 (93, 2)
      RES(1+NROWS*92:NROWS*93,1+NCOLS*1:NCOLS*2) = VAL%E17
      ! E7 x E11 -> E117 (93, 9)
      RES(1+NROWS*92:NROWS*93,1+NCOLS*8:NCOLS*9) = VAL%E7
      ! E11 x E7 -> E117 (93, 8)
      RES(1+NROWS*92:NROWS*93,1+NCOLS*7:NCOLS*8) = VAL%E11
      ! R x E127 -> E127 (94, 94)
      RES(1+NROWS*93:NROWS*94,1+NCOLS*93:NCOLS*94) = VAL%R
      ! E127 x R -> E127 (94, 1)
      RES(1+NROWS*93:NROWS*94,1+NCOLS*0:NCOLS*1) = VAL%E127
      ! E1 x E27 -> E127 (94, 31)
      RES(1+NROWS*93:NROWS*94,1+NCOLS*30:NCOLS*31) = VAL%E1
      ! E27 x E1 -> E127 (94, 2)
      RES(1+NROWS*93:NROWS*94,1+NCOLS*1:NCOLS*2) = VAL%E27
      ! E2 x E17 -> E127 (94, 30)
      RES(1+NROWS*93:NROWS*94,1+NCOLS*29:NCOLS*30) = VAL%E2
      ! E17 x E2 -> E127 (94, 3)
      RES(1+NROWS*93:NROWS*94,1+NCOLS*2:NCOLS*3) = VAL%E17
      ! E7 x E12 -> E127 (94, 10)
      RES(1+NROWS*93:NROWS*94,1+NCOLS*9:NCOLS*10) = VAL%E7
      ! E12 x E7 -> E127 (94, 8)
      RES(1+NROWS*93:NROWS*94,1+NCOLS*7:NCOLS*8) = VAL%E12
      ! R x E227 -> E227 (95, 95)
      RES(1+NROWS*94:NROWS*95,1+NCOLS*94:NCOLS*95) = VAL%R
      ! E227 x R -> E227 (95, 1)
      RES(1+NROWS*94:NROWS*95,1+NCOLS*0:NCOLS*1) = VAL%E227
      ! E2 x E27 -> E227 (95, 31)
      RES(1+NROWS*94:NROWS*95,1+NCOLS*30:NCOLS*31) = VAL%E2
      ! E27 x E2 -> E227 (95, 3)
      RES(1+NROWS*94:NROWS*95,1+NCOLS*2:NCOLS*3) = VAL%E27
      ! E7 x E22 -> E227 (95, 11)
      RES(1+NROWS*94:NROWS*95,1+NCOLS*10:NCOLS*11) = VAL%E7
      ! E22 x E7 -> E227 (95, 8)
      RES(1+NROWS*94:NROWS*95,1+NCOLS*7:NCOLS*8) = VAL%E22
      ! R x E137 -> E137 (96, 96)
      RES(1+NROWS*95:NROWS*96,1+NCOLS*95:NCOLS*96) = VAL%R
      ! E137 x R -> E137 (96, 1)
      RES(1+NROWS*95:NROWS*96,1+NCOLS*0:NCOLS*1) = VAL%E137
      ! E1 x E37 -> E137 (96, 32)
      RES(1+NROWS*95:NROWS*96,1+NCOLS*31:NCOLS*32) = VAL%E1
      ! E37 x E1 -> E137 (96, 2)
      RES(1+NROWS*95:NROWS*96,1+NCOLS*1:NCOLS*2) = VAL%E37
      ! E3 x E17 -> E137 (96, 30)
      RES(1+NROWS*95:NROWS*96,1+NCOLS*29:NCOLS*30) = VAL%E3
      ! E17 x E3 -> E137 (96, 4)
      RES(1+NROWS*95:NROWS*96,1+NCOLS*3:NCOLS*4) = VAL%E17
      ! E7 x E13 -> E137 (96, 12)
      RES(1+NROWS*95:NROWS*96,1+NCOLS*11:NCOLS*12) = VAL%E7
      ! E13 x E7 -> E137 (96, 8)
      RES(1+NROWS*95:NROWS*96,1+NCOLS*7:NCOLS*8) = VAL%E13
      ! R x E237 -> E237 (97, 97)
      RES(1+NROWS*96:NROWS*97,1+NCOLS*96:NCOLS*97) = VAL%R
      ! E237 x R -> E237 (97, 1)
      RES(1+NROWS*96:NROWS*97,1+NCOLS*0:NCOLS*1) = VAL%E237
      ! E2 x E37 -> E237 (97, 32)
      RES(1+NROWS*96:NROWS*97,1+NCOLS*31:NCOLS*32) = VAL%E2
      ! E37 x E2 -> E237 (97, 3)
      RES(1+NROWS*96:NROWS*97,1+NCOLS*2:NCOLS*3) = VAL%E37
      ! E3 x E27 -> E237 (97, 31)
      RES(1+NROWS*96:NROWS*97,1+NCOLS*30:NCOLS*31) = VAL%E3
      ! E27 x E3 -> E237 (97, 4)
      RES(1+NROWS*96:NROWS*97,1+NCOLS*3:NCOLS*4) = VAL%E27
      ! E7 x E23 -> E237 (97, 13)
      RES(1+NROWS*96:NROWS*97,1+NCOLS*12:NCOLS*13) = VAL%E7
      ! E23 x E7 -> E237 (97, 8)
      RES(1+NROWS*96:NROWS*97,1+NCOLS*7:NCOLS*8) = VAL%E23
      ! R x E337 -> E337 (98, 98)
      RES(1+NROWS*97:NROWS*98,1+NCOLS*97:NCOLS*98) = VAL%R
      ! E337 x R -> E337 (98, 1)
      RES(1+NROWS*97:NROWS*98,1+NCOLS*0:NCOLS*1) = VAL%E337
      ! E3 x E37 -> E337 (98, 32)
      RES(1+NROWS*97:NROWS*98,1+NCOLS*31:NCOLS*32) = VAL%E3
      ! E37 x E3 -> E337 (98, 4)
      RES(1+NROWS*97:NROWS*98,1+NCOLS*3:NCOLS*4) = VAL%E37
      ! E7 x E33 -> E337 (98, 14)
      RES(1+NROWS*97:NROWS*98,1+NCOLS*13:NCOLS*14) = VAL%E7
      ! E33 x E7 -> E337 (98, 8)
      RES(1+NROWS*97:NROWS*98,1+NCOLS*7:NCOLS*8) = VAL%E33
      ! R x E147 -> E147 (99, 99)
      RES(1+NROWS*98:NROWS*99,1+NCOLS*98:NCOLS*99) = VAL%R
      ! E147 x R -> E147 (99, 1)
      RES(1+NROWS*98:NROWS*99,1+NCOLS*0:NCOLS*1) = VAL%E147
      ! E1 x E47 -> E147 (99, 33)
      RES(1+NROWS*98:NROWS*99,1+NCOLS*32:NCOLS*33) = VAL%E1
      ! E47 x E1 -> E147 (99, 2)
      RES(1+NROWS*98:NROWS*99,1+NCOLS*1:NCOLS*2) = VAL%E47
      ! E4 x E17 -> E147 (99, 30)
      RES(1+NROWS*98:NROWS*99,1+NCOLS*29:NCOLS*30) = VAL%E4
      ! E17 x E4 -> E147 (99, 5)
      RES(1+NROWS*98:NROWS*99,1+NCOLS*4:NCOLS*5) = VAL%E17
      ! E7 x E14 -> E147 (99, 15)
      RES(1+NROWS*98:NROWS*99,1+NCOLS*14:NCOLS*15) = VAL%E7
      ! E14 x E7 -> E147 (99, 8)
      RES(1+NROWS*98:NROWS*99,1+NCOLS*7:NCOLS*8) = VAL%E14
      ! R x E247 -> E247 (100, 100)
      RES(1+NROWS*99:NROWS*100,1+NCOLS*99:NCOLS*100) = VAL%R
      ! E247 x R -> E247 (100, 1)
      RES(1+NROWS*99:NROWS*100,1+NCOLS*0:NCOLS*1) = VAL%E247
      ! E2 x E47 -> E247 (100, 33)
      RES(1+NROWS*99:NROWS*100,1+NCOLS*32:NCOLS*33) = VAL%E2
      ! E47 x E2 -> E247 (100, 3)
      RES(1+NROWS*99:NROWS*100,1+NCOLS*2:NCOLS*3) = VAL%E47
      ! E4 x E27 -> E247 (100, 31)
      RES(1+NROWS*99:NROWS*100,1+NCOLS*30:NCOLS*31) = VAL%E4
      ! E27 x E4 -> E247 (100, 5)
      RES(1+NROWS*99:NROWS*100,1+NCOLS*4:NCOLS*5) = VAL%E27
      ! E7 x E24 -> E247 (100, 16)
      RES(1+NROWS*99:NROWS*100,1+NCOLS*15:NCOLS*16) = VAL%E7
      ! E24 x E7 -> E247 (100, 8)
      RES(1+NROWS*99:NROWS*100,1+NCOLS*7:NCOLS*8) = VAL%E24
      ! R x E347 -> E347 (101, 101)
      RES(1+NROWS*100:NROWS*101,1+NCOLS*100:NCOLS*101) = VAL%R
      ! E347 x R -> E347 (101, 1)
      RES(1+NROWS*100:NROWS*101,1+NCOLS*0:NCOLS*1) = VAL%E347
      ! E3 x E47 -> E347 (101, 33)
      RES(1+NROWS*100:NROWS*101,1+NCOLS*32:NCOLS*33) = VAL%E3
      ! E47 x E3 -> E347 (101, 4)
      RES(1+NROWS*100:NROWS*101,1+NCOLS*3:NCOLS*4) = VAL%E47
      ! E4 x E37 -> E347 (101, 32)
      RES(1+NROWS*100:NROWS*101,1+NCOLS*31:NCOLS*32) = VAL%E4
      ! E37 x E4 -> E347 (101, 5)
      RES(1+NROWS*100:NROWS*101,1+NCOLS*4:NCOLS*5) = VAL%E37
      ! E7 x E34 -> E347 (101, 17)
      RES(1+NROWS*100:NROWS*101,1+NCOLS*16:NCOLS*17) = VAL%E7
      ! E34 x E7 -> E347 (101, 8)
      RES(1+NROWS*100:NROWS*101,1+NCOLS*7:NCOLS*8) = VAL%E34
      ! R x E447 -> E447 (102, 102)
      RES(1+NROWS*101:NROWS*102,1+NCOLS*101:NCOLS*102) = VAL%R
      ! E447 x R -> E447 (102, 1)
      RES(1+NROWS*101:NROWS*102,1+NCOLS*0:NCOLS*1) = VAL%E447
      ! E4 x E47 -> E447 (102, 33)
      RES(1+NROWS*101:NROWS*102,1+NCOLS*32:NCOLS*33) = VAL%E4
      ! E47 x E4 -> E447 (102, 5)
      RES(1+NROWS*101:NROWS*102,1+NCOLS*4:NCOLS*5) = VAL%E47
      ! E7 x E44 -> E447 (102, 18)
      RES(1+NROWS*101:NROWS*102,1+NCOLS*17:NCOLS*18) = VAL%E7
      ! E44 x E7 -> E447 (102, 8)
      RES(1+NROWS*101:NROWS*102,1+NCOLS*7:NCOLS*8) = VAL%E44
      ! R x E157 -> E157 (103, 103)
      RES(1+NROWS*102:NROWS*103,1+NCOLS*102:NCOLS*103) = VAL%R
      ! E157 x R -> E157 (103, 1)
      RES(1+NROWS*102:NROWS*103,1+NCOLS*0:NCOLS*1) = VAL%E157
      ! E1 x E57 -> E157 (103, 34)
      RES(1+NROWS*102:NROWS*103,1+NCOLS*33:NCOLS*34) = VAL%E1
      ! E57 x E1 -> E157 (103, 2)
      RES(1+NROWS*102:NROWS*103,1+NCOLS*1:NCOLS*2) = VAL%E57
      ! E5 x E17 -> E157 (103, 30)
      RES(1+NROWS*102:NROWS*103,1+NCOLS*29:NCOLS*30) = VAL%E5
      ! E17 x E5 -> E157 (103, 6)
      RES(1+NROWS*102:NROWS*103,1+NCOLS*5:NCOLS*6) = VAL%E17
      ! E7 x E15 -> E157 (103, 19)
      RES(1+NROWS*102:NROWS*103,1+NCOLS*18:NCOLS*19) = VAL%E7
      ! E15 x E7 -> E157 (103, 8)
      RES(1+NROWS*102:NROWS*103,1+NCOLS*7:NCOLS*8) = VAL%E15
      ! R x E257 -> E257 (104, 104)
      RES(1+NROWS*103:NROWS*104,1+NCOLS*103:NCOLS*104) = VAL%R
      ! E257 x R -> E257 (104, 1)
      RES(1+NROWS*103:NROWS*104,1+NCOLS*0:NCOLS*1) = VAL%E257
      ! E2 x E57 -> E257 (104, 34)
      RES(1+NROWS*103:NROWS*104,1+NCOLS*33:NCOLS*34) = VAL%E2
      ! E57 x E2 -> E257 (104, 3)
      RES(1+NROWS*103:NROWS*104,1+NCOLS*2:NCOLS*3) = VAL%E57
      ! E5 x E27 -> E257 (104, 31)
      RES(1+NROWS*103:NROWS*104,1+NCOLS*30:NCOLS*31) = VAL%E5
      ! E27 x E5 -> E257 (104, 6)
      RES(1+NROWS*103:NROWS*104,1+NCOLS*5:NCOLS*6) = VAL%E27
      ! E7 x E25 -> E257 (104, 20)
      RES(1+NROWS*103:NROWS*104,1+NCOLS*19:NCOLS*20) = VAL%E7
      ! E25 x E7 -> E257 (104, 8)
      RES(1+NROWS*103:NROWS*104,1+NCOLS*7:NCOLS*8) = VAL%E25
      ! R x E357 -> E357 (105, 105)
      RES(1+NROWS*104:NROWS*105,1+NCOLS*104:NCOLS*105) = VAL%R
      ! E357 x R -> E357 (105, 1)
      RES(1+NROWS*104:NROWS*105,1+NCOLS*0:NCOLS*1) = VAL%E357
      ! E3 x E57 -> E357 (105, 34)
      RES(1+NROWS*104:NROWS*105,1+NCOLS*33:NCOLS*34) = VAL%E3
      ! E57 x E3 -> E357 (105, 4)
      RES(1+NROWS*104:NROWS*105,1+NCOLS*3:NCOLS*4) = VAL%E57
      ! E5 x E37 -> E357 (105, 32)
      RES(1+NROWS*104:NROWS*105,1+NCOLS*31:NCOLS*32) = VAL%E5
      ! E37 x E5 -> E357 (105, 6)
      RES(1+NROWS*104:NROWS*105,1+NCOLS*5:NCOLS*6) = VAL%E37
      ! E7 x E35 -> E357 (105, 21)
      RES(1+NROWS*104:NROWS*105,1+NCOLS*20:NCOLS*21) = VAL%E7
      ! E35 x E7 -> E357 (105, 8)
      RES(1+NROWS*104:NROWS*105,1+NCOLS*7:NCOLS*8) = VAL%E35
      ! R x E457 -> E457 (106, 106)
      RES(1+NROWS*105:NROWS*106,1+NCOLS*105:NCOLS*106) = VAL%R
      ! E457 x R -> E457 (106, 1)
      RES(1+NROWS*105:NROWS*106,1+NCOLS*0:NCOLS*1) = VAL%E457
      ! E4 x E57 -> E457 (106, 34)
      RES(1+NROWS*105:NROWS*106,1+NCOLS*33:NCOLS*34) = VAL%E4
      ! E57 x E4 -> E457 (106, 5)
      RES(1+NROWS*105:NROWS*106,1+NCOLS*4:NCOLS*5) = VAL%E57
      ! E5 x E47 -> E457 (106, 33)
      RES(1+NROWS*105:NROWS*106,1+NCOLS*32:NCOLS*33) = VAL%E5
      ! E47 x E5 -> E457 (106, 6)
      RES(1+NROWS*105:NROWS*106,1+NCOLS*5:NCOLS*6) = VAL%E47
      ! E7 x E45 -> E457 (106, 22)
      RES(1+NROWS*105:NROWS*106,1+NCOLS*21:NCOLS*22) = VAL%E7
      ! E45 x E7 -> E457 (106, 8)
      RES(1+NROWS*105:NROWS*106,1+NCOLS*7:NCOLS*8) = VAL%E45
      ! R x E557 -> E557 (107, 107)
      RES(1+NROWS*106:NROWS*107,1+NCOLS*106:NCOLS*107) = VAL%R
      ! E557 x R -> E557 (107, 1)
      RES(1+NROWS*106:NROWS*107,1+NCOLS*0:NCOLS*1) = VAL%E557
      ! E5 x E57 -> E557 (107, 34)
      RES(1+NROWS*106:NROWS*107,1+NCOLS*33:NCOLS*34) = VAL%E5
      ! E57 x E5 -> E557 (107, 6)
      RES(1+NROWS*106:NROWS*107,1+NCOLS*5:NCOLS*6) = VAL%E57
      ! E7 x E55 -> E557 (107, 23)
      RES(1+NROWS*106:NROWS*107,1+NCOLS*22:NCOLS*23) = VAL%E7
      ! E55 x E7 -> E557 (107, 8)
      RES(1+NROWS*106:NROWS*107,1+NCOLS*7:NCOLS*8) = VAL%E55
      ! R x E167 -> E167 (108, 108)
      RES(1+NROWS*107:NROWS*108,1+NCOLS*107:NCOLS*108) = VAL%R
      ! E167 x R -> E167 (108, 1)
      RES(1+NROWS*107:NROWS*108,1+NCOLS*0:NCOLS*1) = VAL%E167
      ! E1 x E67 -> E167 (108, 35)
      RES(1+NROWS*107:NROWS*108,1+NCOLS*34:NCOLS*35) = VAL%E1
      ! E67 x E1 -> E167 (108, 2)
      RES(1+NROWS*107:NROWS*108,1+NCOLS*1:NCOLS*2) = VAL%E67
      ! E6 x E17 -> E167 (108, 30)
      RES(1+NROWS*107:NROWS*108,1+NCOLS*29:NCOLS*30) = VAL%E6
      ! E17 x E6 -> E167 (108, 7)
      RES(1+NROWS*107:NROWS*108,1+NCOLS*6:NCOLS*7) = VAL%E17
      ! E7 x E16 -> E167 (108, 24)
      RES(1+NROWS*107:NROWS*108,1+NCOLS*23:NCOLS*24) = VAL%E7
      ! E16 x E7 -> E167 (108, 8)
      RES(1+NROWS*107:NROWS*108,1+NCOLS*7:NCOLS*8) = VAL%E16
      ! R x E267 -> E267 (109, 109)
      RES(1+NROWS*108:NROWS*109,1+NCOLS*108:NCOLS*109) = VAL%R
      ! E267 x R -> E267 (109, 1)
      RES(1+NROWS*108:NROWS*109,1+NCOLS*0:NCOLS*1) = VAL%E267
      ! E2 x E67 -> E267 (109, 35)
      RES(1+NROWS*108:NROWS*109,1+NCOLS*34:NCOLS*35) = VAL%E2
      ! E67 x E2 -> E267 (109, 3)
      RES(1+NROWS*108:NROWS*109,1+NCOLS*2:NCOLS*3) = VAL%E67
      ! E6 x E27 -> E267 (109, 31)
      RES(1+NROWS*108:NROWS*109,1+NCOLS*30:NCOLS*31) = VAL%E6
      ! E27 x E6 -> E267 (109, 7)
      RES(1+NROWS*108:NROWS*109,1+NCOLS*6:NCOLS*7) = VAL%E27
      ! E7 x E26 -> E267 (109, 25)
      RES(1+NROWS*108:NROWS*109,1+NCOLS*24:NCOLS*25) = VAL%E7
      ! E26 x E7 -> E267 (109, 8)
      RES(1+NROWS*108:NROWS*109,1+NCOLS*7:NCOLS*8) = VAL%E26
      ! R x E367 -> E367 (110, 110)
      RES(1+NROWS*109:NROWS*110,1+NCOLS*109:NCOLS*110) = VAL%R
      ! E367 x R -> E367 (110, 1)
      RES(1+NROWS*109:NROWS*110,1+NCOLS*0:NCOLS*1) = VAL%E367
      ! E3 x E67 -> E367 (110, 35)
      RES(1+NROWS*109:NROWS*110,1+NCOLS*34:NCOLS*35) = VAL%E3
      ! E67 x E3 -> E367 (110, 4)
      RES(1+NROWS*109:NROWS*110,1+NCOLS*3:NCOLS*4) = VAL%E67
      ! E6 x E37 -> E367 (110, 32)
      RES(1+NROWS*109:NROWS*110,1+NCOLS*31:NCOLS*32) = VAL%E6
      ! E37 x E6 -> E367 (110, 7)
      RES(1+NROWS*109:NROWS*110,1+NCOLS*6:NCOLS*7) = VAL%E37
      ! E7 x E36 -> E367 (110, 26)
      RES(1+NROWS*109:NROWS*110,1+NCOLS*25:NCOLS*26) = VAL%E7
      ! E36 x E7 -> E367 (110, 8)
      RES(1+NROWS*109:NROWS*110,1+NCOLS*7:NCOLS*8) = VAL%E36
      ! R x E467 -> E467 (111, 111)
      RES(1+NROWS*110:NROWS*111,1+NCOLS*110:NCOLS*111) = VAL%R
      ! E467 x R -> E467 (111, 1)
      RES(1+NROWS*110:NROWS*111,1+NCOLS*0:NCOLS*1) = VAL%E467
      ! E4 x E67 -> E467 (111, 35)
      RES(1+NROWS*110:NROWS*111,1+NCOLS*34:NCOLS*35) = VAL%E4
      ! E67 x E4 -> E467 (111, 5)
      RES(1+NROWS*110:NROWS*111,1+NCOLS*4:NCOLS*5) = VAL%E67
      ! E6 x E47 -> E467 (111, 33)
      RES(1+NROWS*110:NROWS*111,1+NCOLS*32:NCOLS*33) = VAL%E6
      ! E47 x E6 -> E467 (111, 7)
      RES(1+NROWS*110:NROWS*111,1+NCOLS*6:NCOLS*7) = VAL%E47
      ! E7 x E46 -> E467 (111, 27)
      RES(1+NROWS*110:NROWS*111,1+NCOLS*26:NCOLS*27) = VAL%E7
      ! E46 x E7 -> E467 (111, 8)
      RES(1+NROWS*110:NROWS*111,1+NCOLS*7:NCOLS*8) = VAL%E46
      ! R x E567 -> E567 (112, 112)
      RES(1+NROWS*111:NROWS*112,1+NCOLS*111:NCOLS*112) = VAL%R
      ! E567 x R -> E567 (112, 1)
      RES(1+NROWS*111:NROWS*112,1+NCOLS*0:NCOLS*1) = VAL%E567
      ! E5 x E67 -> E567 (112, 35)
      RES(1+NROWS*111:NROWS*112,1+NCOLS*34:NCOLS*35) = VAL%E5
      ! E67 x E5 -> E567 (112, 6)
      RES(1+NROWS*111:NROWS*112,1+NCOLS*5:NCOLS*6) = VAL%E67
      ! E6 x E57 -> E567 (112, 34)
      RES(1+NROWS*111:NROWS*112,1+NCOLS*33:NCOLS*34) = VAL%E6
      ! E57 x E6 -> E567 (112, 7)
      RES(1+NROWS*111:NROWS*112,1+NCOLS*6:NCOLS*7) = VAL%E57
      ! E7 x E56 -> E567 (112, 28)
      RES(1+NROWS*111:NROWS*112,1+NCOLS*27:NCOLS*28) = VAL%E7
      ! E56 x E7 -> E567 (112, 8)
      RES(1+NROWS*111:NROWS*112,1+NCOLS*7:NCOLS*8) = VAL%E56
      ! R x E667 -> E667 (113, 113)
      RES(1+NROWS*112:NROWS*113,1+NCOLS*112:NCOLS*113) = VAL%R
      ! E667 x R -> E667 (113, 1)
      RES(1+NROWS*112:NROWS*113,1+NCOLS*0:NCOLS*1) = VAL%E667
      ! E6 x E67 -> E667 (113, 35)
      RES(1+NROWS*112:NROWS*113,1+NCOLS*34:NCOLS*35) = VAL%E6
      ! E67 x E6 -> E667 (113, 7)
      RES(1+NROWS*112:NROWS*113,1+NCOLS*6:NCOLS*7) = VAL%E67
      ! E7 x E66 -> E667 (113, 29)
      RES(1+NROWS*112:NROWS*113,1+NCOLS*28:NCOLS*29) = VAL%E7
      ! E66 x E7 -> E667 (113, 8)
      RES(1+NROWS*112:NROWS*113,1+NCOLS*7:NCOLS*8) = VAL%E66
      ! R x E177 -> E177 (114, 114)
      RES(1+NROWS*113:NROWS*114,1+NCOLS*113:NCOLS*114) = VAL%R
      ! E177 x R -> E177 (114, 1)
      RES(1+NROWS*113:NROWS*114,1+NCOLS*0:NCOLS*1) = VAL%E177
      ! E1 x E77 -> E177 (114, 36)
      RES(1+NROWS*113:NROWS*114,1+NCOLS*35:NCOLS*36) = VAL%E1
      ! E77 x E1 -> E177 (114, 2)
      RES(1+NROWS*113:NROWS*114,1+NCOLS*1:NCOLS*2) = VAL%E77
      ! E7 x E17 -> E177 (114, 30)
      RES(1+NROWS*113:NROWS*114,1+NCOLS*29:NCOLS*30) = VAL%E7
      ! E17 x E7 -> E177 (114, 8)
      RES(1+NROWS*113:NROWS*114,1+NCOLS*7:NCOLS*8) = VAL%E17
      ! R x E277 -> E277 (115, 115)
      RES(1+NROWS*114:NROWS*115,1+NCOLS*114:NCOLS*115) = VAL%R
      ! E277 x R -> E277 (115, 1)
      RES(1+NROWS*114:NROWS*115,1+NCOLS*0:NCOLS*1) = VAL%E277
      ! E2 x E77 -> E277 (115, 36)
      RES(1+NROWS*114:NROWS*115,1+NCOLS*35:NCOLS*36) = VAL%E2
      ! E77 x E2 -> E277 (115, 3)
      RES(1+NROWS*114:NROWS*115,1+NCOLS*2:NCOLS*3) = VAL%E77
      ! E7 x E27 -> E277 (115, 31)
      RES(1+NROWS*114:NROWS*115,1+NCOLS*30:NCOLS*31) = VAL%E7
      ! E27 x E7 -> E277 (115, 8)
      RES(1+NROWS*114:NROWS*115,1+NCOLS*7:NCOLS*8) = VAL%E27
      ! R x E377 -> E377 (116, 116)
      RES(1+NROWS*115:NROWS*116,1+NCOLS*115:NCOLS*116) = VAL%R
      ! E377 x R -> E377 (116, 1)
      RES(1+NROWS*115:NROWS*116,1+NCOLS*0:NCOLS*1) = VAL%E377
      ! E3 x E77 -> E377 (116, 36)
      RES(1+NROWS*115:NROWS*116,1+NCOLS*35:NCOLS*36) = VAL%E3
      ! E77 x E3 -> E377 (116, 4)
      RES(1+NROWS*115:NROWS*116,1+NCOLS*3:NCOLS*4) = VAL%E77
      ! E7 x E37 -> E377 (116, 32)
      RES(1+NROWS*115:NROWS*116,1+NCOLS*31:NCOLS*32) = VAL%E7
      ! E37 x E7 -> E377 (116, 8)
      RES(1+NROWS*115:NROWS*116,1+NCOLS*7:NCOLS*8) = VAL%E37
      ! R x E477 -> E477 (117, 117)
      RES(1+NROWS*116:NROWS*117,1+NCOLS*116:NCOLS*117) = VAL%R
      ! E477 x R -> E477 (117, 1)
      RES(1+NROWS*116:NROWS*117,1+NCOLS*0:NCOLS*1) = VAL%E477
      ! E4 x E77 -> E477 (117, 36)
      RES(1+NROWS*116:NROWS*117,1+NCOLS*35:NCOLS*36) = VAL%E4
      ! E77 x E4 -> E477 (117, 5)
      RES(1+NROWS*116:NROWS*117,1+NCOLS*4:NCOLS*5) = VAL%E77
      ! E7 x E47 -> E477 (117, 33)
      RES(1+NROWS*116:NROWS*117,1+NCOLS*32:NCOLS*33) = VAL%E7
      ! E47 x E7 -> E477 (117, 8)
      RES(1+NROWS*116:NROWS*117,1+NCOLS*7:NCOLS*8) = VAL%E47
      ! R x E577 -> E577 (118, 118)
      RES(1+NROWS*117:NROWS*118,1+NCOLS*117:NCOLS*118) = VAL%R
      ! E577 x R -> E577 (118, 1)
      RES(1+NROWS*117:NROWS*118,1+NCOLS*0:NCOLS*1) = VAL%E577
      ! E5 x E77 -> E577 (118, 36)
      RES(1+NROWS*117:NROWS*118,1+NCOLS*35:NCOLS*36) = VAL%E5
      ! E77 x E5 -> E577 (118, 6)
      RES(1+NROWS*117:NROWS*118,1+NCOLS*5:NCOLS*6) = VAL%E77
      ! E7 x E57 -> E577 (118, 34)
      RES(1+NROWS*117:NROWS*118,1+NCOLS*33:NCOLS*34) = VAL%E7
      ! E57 x E7 -> E577 (118, 8)
      RES(1+NROWS*117:NROWS*118,1+NCOLS*7:NCOLS*8) = VAL%E57
      ! R x E677 -> E677 (119, 119)
      RES(1+NROWS*118:NROWS*119,1+NCOLS*118:NCOLS*119) = VAL%R
      ! E677 x R -> E677 (119, 1)
      RES(1+NROWS*118:NROWS*119,1+NCOLS*0:NCOLS*1) = VAL%E677
      ! E6 x E77 -> E677 (119, 36)
      RES(1+NROWS*118:NROWS*119,1+NCOLS*35:NCOLS*36) = VAL%E6
      ! E77 x E6 -> E677 (119, 7)
      RES(1+NROWS*118:NROWS*119,1+NCOLS*6:NCOLS*7) = VAL%E77
      ! E7 x E67 -> E677 (119, 35)
      RES(1+NROWS*118:NROWS*119,1+NCOLS*34:NCOLS*35) = VAL%E7
      ! E67 x E7 -> E677 (119, 8)
      RES(1+NROWS*118:NROWS*119,1+NCOLS*7:NCOLS*8) = VAL%E67
      ! R x E777 -> E777 (120, 120)
      RES(1+NROWS*119:NROWS*120,1+NCOLS*119:NCOLS*120) = VAL%R
      ! E777 x R -> E777 (120, 1)
      RES(1+NROWS*119:NROWS*120,1+NCOLS*0:NCOLS*1) = VAL%E777
      ! E7 x E77 -> E777 (120, 36)
      RES(1+NROWS*119:NROWS*120,1+NCOLS*35:NCOLS*36) = VAL%E7
      ! E77 x E7 -> E777 (120, 8)
      RES(1+NROWS*119:NROWS*120,1+NCOLS*7:NCOLS*8) = VAL%E77
   END FUNCTION ONUMM7N3_TO_CR_MAT_S

FUNCTION ONUMM7N3_TO_CR_MAT_V(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: VAL(:)
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
      ! R x E111 -> E111 (37, 37)
      RES(1+NROWS*36:NROWS*37,37) = VAL%R
      ! E111 x R -> E111 (37, 1)
      RES(1+NROWS*36:NROWS*37,1) = VAL%E111
      ! E1 x E11 -> E111 (37, 9)
      RES(1+NROWS*36:NROWS*37,9) = VAL%E1
      ! E11 x E1 -> E111 (37, 2)
      RES(1+NROWS*36:NROWS*37,2) = VAL%E11
      ! R x E112 -> E112 (38, 38)
      RES(1+NROWS*37:NROWS*38,38) = VAL%R
      ! E112 x R -> E112 (38, 1)
      RES(1+NROWS*37:NROWS*38,1) = VAL%E112
      ! E1 x E12 -> E112 (38, 10)
      RES(1+NROWS*37:NROWS*38,10) = VAL%E1
      ! E12 x E1 -> E112 (38, 2)
      RES(1+NROWS*37:NROWS*38,2) = VAL%E12
      ! E2 x E11 -> E112 (38, 9)
      RES(1+NROWS*37:NROWS*38,9) = VAL%E2
      ! E11 x E2 -> E112 (38, 3)
      RES(1+NROWS*37:NROWS*38,3) = VAL%E11
      ! R x E122 -> E122 (39, 39)
      RES(1+NROWS*38:NROWS*39,39) = VAL%R
      ! E122 x R -> E122 (39, 1)
      RES(1+NROWS*38:NROWS*39,1) = VAL%E122
      ! E1 x E22 -> E122 (39, 11)
      RES(1+NROWS*38:NROWS*39,11) = VAL%E1
      ! E22 x E1 -> E122 (39, 2)
      RES(1+NROWS*38:NROWS*39,2) = VAL%E22
      ! E2 x E12 -> E122 (39, 10)
      RES(1+NROWS*38:NROWS*39,10) = VAL%E2
      ! E12 x E2 -> E122 (39, 3)
      RES(1+NROWS*38:NROWS*39,3) = VAL%E12
      ! R x E222 -> E222 (40, 40)
      RES(1+NROWS*39:NROWS*40,40) = VAL%R
      ! E222 x R -> E222 (40, 1)
      RES(1+NROWS*39:NROWS*40,1) = VAL%E222
      ! E2 x E22 -> E222 (40, 11)
      RES(1+NROWS*39:NROWS*40,11) = VAL%E2
      ! E22 x E2 -> E222 (40, 3)
      RES(1+NROWS*39:NROWS*40,3) = VAL%E22
      ! R x E113 -> E113 (41, 41)
      RES(1+NROWS*40:NROWS*41,41) = VAL%R
      ! E113 x R -> E113 (41, 1)
      RES(1+NROWS*40:NROWS*41,1) = VAL%E113
      ! E1 x E13 -> E113 (41, 12)
      RES(1+NROWS*40:NROWS*41,12) = VAL%E1
      ! E13 x E1 -> E113 (41, 2)
      RES(1+NROWS*40:NROWS*41,2) = VAL%E13
      ! E3 x E11 -> E113 (41, 9)
      RES(1+NROWS*40:NROWS*41,9) = VAL%E3
      ! E11 x E3 -> E113 (41, 4)
      RES(1+NROWS*40:NROWS*41,4) = VAL%E11
      ! R x E123 -> E123 (42, 42)
      RES(1+NROWS*41:NROWS*42,42) = VAL%R
      ! E123 x R -> E123 (42, 1)
      RES(1+NROWS*41:NROWS*42,1) = VAL%E123
      ! E1 x E23 -> E123 (42, 13)
      RES(1+NROWS*41:NROWS*42,13) = VAL%E1
      ! E23 x E1 -> E123 (42, 2)
      RES(1+NROWS*41:NROWS*42,2) = VAL%E23
      ! E2 x E13 -> E123 (42, 12)
      RES(1+NROWS*41:NROWS*42,12) = VAL%E2
      ! E13 x E2 -> E123 (42, 3)
      RES(1+NROWS*41:NROWS*42,3) = VAL%E13
      ! E3 x E12 -> E123 (42, 10)
      RES(1+NROWS*41:NROWS*42,10) = VAL%E3
      ! E12 x E3 -> E123 (42, 4)
      RES(1+NROWS*41:NROWS*42,4) = VAL%E12
      ! R x E223 -> E223 (43, 43)
      RES(1+NROWS*42:NROWS*43,43) = VAL%R
      ! E223 x R -> E223 (43, 1)
      RES(1+NROWS*42:NROWS*43,1) = VAL%E223
      ! E2 x E23 -> E223 (43, 13)
      RES(1+NROWS*42:NROWS*43,13) = VAL%E2
      ! E23 x E2 -> E223 (43, 3)
      RES(1+NROWS*42:NROWS*43,3) = VAL%E23
      ! E3 x E22 -> E223 (43, 11)
      RES(1+NROWS*42:NROWS*43,11) = VAL%E3
      ! E22 x E3 -> E223 (43, 4)
      RES(1+NROWS*42:NROWS*43,4) = VAL%E22
      ! R x E133 -> E133 (44, 44)
      RES(1+NROWS*43:NROWS*44,44) = VAL%R
      ! E133 x R -> E133 (44, 1)
      RES(1+NROWS*43:NROWS*44,1) = VAL%E133
      ! E1 x E33 -> E133 (44, 14)
      RES(1+NROWS*43:NROWS*44,14) = VAL%E1
      ! E33 x E1 -> E133 (44, 2)
      RES(1+NROWS*43:NROWS*44,2) = VAL%E33
      ! E3 x E13 -> E133 (44, 12)
      RES(1+NROWS*43:NROWS*44,12) = VAL%E3
      ! E13 x E3 -> E133 (44, 4)
      RES(1+NROWS*43:NROWS*44,4) = VAL%E13
      ! R x E233 -> E233 (45, 45)
      RES(1+NROWS*44:NROWS*45,45) = VAL%R
      ! E233 x R -> E233 (45, 1)
      RES(1+NROWS*44:NROWS*45,1) = VAL%E233
      ! E2 x E33 -> E233 (45, 14)
      RES(1+NROWS*44:NROWS*45,14) = VAL%E2
      ! E33 x E2 -> E233 (45, 3)
      RES(1+NROWS*44:NROWS*45,3) = VAL%E33
      ! E3 x E23 -> E233 (45, 13)
      RES(1+NROWS*44:NROWS*45,13) = VAL%E3
      ! E23 x E3 -> E233 (45, 4)
      RES(1+NROWS*44:NROWS*45,4) = VAL%E23
      ! R x E333 -> E333 (46, 46)
      RES(1+NROWS*45:NROWS*46,46) = VAL%R
      ! E333 x R -> E333 (46, 1)
      RES(1+NROWS*45:NROWS*46,1) = VAL%E333
      ! E3 x E33 -> E333 (46, 14)
      RES(1+NROWS*45:NROWS*46,14) = VAL%E3
      ! E33 x E3 -> E333 (46, 4)
      RES(1+NROWS*45:NROWS*46,4) = VAL%E33
      ! R x E114 -> E114 (47, 47)
      RES(1+NROWS*46:NROWS*47,47) = VAL%R
      ! E114 x R -> E114 (47, 1)
      RES(1+NROWS*46:NROWS*47,1) = VAL%E114
      ! E1 x E14 -> E114 (47, 15)
      RES(1+NROWS*46:NROWS*47,15) = VAL%E1
      ! E14 x E1 -> E114 (47, 2)
      RES(1+NROWS*46:NROWS*47,2) = VAL%E14
      ! E4 x E11 -> E114 (47, 9)
      RES(1+NROWS*46:NROWS*47,9) = VAL%E4
      ! E11 x E4 -> E114 (47, 5)
      RES(1+NROWS*46:NROWS*47,5) = VAL%E11
      ! R x E124 -> E124 (48, 48)
      RES(1+NROWS*47:NROWS*48,48) = VAL%R
      ! E124 x R -> E124 (48, 1)
      RES(1+NROWS*47:NROWS*48,1) = VAL%E124
      ! E1 x E24 -> E124 (48, 16)
      RES(1+NROWS*47:NROWS*48,16) = VAL%E1
      ! E24 x E1 -> E124 (48, 2)
      RES(1+NROWS*47:NROWS*48,2) = VAL%E24
      ! E2 x E14 -> E124 (48, 15)
      RES(1+NROWS*47:NROWS*48,15) = VAL%E2
      ! E14 x E2 -> E124 (48, 3)
      RES(1+NROWS*47:NROWS*48,3) = VAL%E14
      ! E4 x E12 -> E124 (48, 10)
      RES(1+NROWS*47:NROWS*48,10) = VAL%E4
      ! E12 x E4 -> E124 (48, 5)
      RES(1+NROWS*47:NROWS*48,5) = VAL%E12
      ! R x E224 -> E224 (49, 49)
      RES(1+NROWS*48:NROWS*49,49) = VAL%R
      ! E224 x R -> E224 (49, 1)
      RES(1+NROWS*48:NROWS*49,1) = VAL%E224
      ! E2 x E24 -> E224 (49, 16)
      RES(1+NROWS*48:NROWS*49,16) = VAL%E2
      ! E24 x E2 -> E224 (49, 3)
      RES(1+NROWS*48:NROWS*49,3) = VAL%E24
      ! E4 x E22 -> E224 (49, 11)
      RES(1+NROWS*48:NROWS*49,11) = VAL%E4
      ! E22 x E4 -> E224 (49, 5)
      RES(1+NROWS*48:NROWS*49,5) = VAL%E22
      ! R x E134 -> E134 (50, 50)
      RES(1+NROWS*49:NROWS*50,50) = VAL%R
      ! E134 x R -> E134 (50, 1)
      RES(1+NROWS*49:NROWS*50,1) = VAL%E134
      ! E1 x E34 -> E134 (50, 17)
      RES(1+NROWS*49:NROWS*50,17) = VAL%E1
      ! E34 x E1 -> E134 (50, 2)
      RES(1+NROWS*49:NROWS*50,2) = VAL%E34
      ! E3 x E14 -> E134 (50, 15)
      RES(1+NROWS*49:NROWS*50,15) = VAL%E3
      ! E14 x E3 -> E134 (50, 4)
      RES(1+NROWS*49:NROWS*50,4) = VAL%E14
      ! E4 x E13 -> E134 (50, 12)
      RES(1+NROWS*49:NROWS*50,12) = VAL%E4
      ! E13 x E4 -> E134 (50, 5)
      RES(1+NROWS*49:NROWS*50,5) = VAL%E13
      ! R x E234 -> E234 (51, 51)
      RES(1+NROWS*50:NROWS*51,51) = VAL%R
      ! E234 x R -> E234 (51, 1)
      RES(1+NROWS*50:NROWS*51,1) = VAL%E234
      ! E2 x E34 -> E234 (51, 17)
      RES(1+NROWS*50:NROWS*51,17) = VAL%E2
      ! E34 x E2 -> E234 (51, 3)
      RES(1+NROWS*50:NROWS*51,3) = VAL%E34
      ! E3 x E24 -> E234 (51, 16)
      RES(1+NROWS*50:NROWS*51,16) = VAL%E3
      ! E24 x E3 -> E234 (51, 4)
      RES(1+NROWS*50:NROWS*51,4) = VAL%E24
      ! E4 x E23 -> E234 (51, 13)
      RES(1+NROWS*50:NROWS*51,13) = VAL%E4
      ! E23 x E4 -> E234 (51, 5)
      RES(1+NROWS*50:NROWS*51,5) = VAL%E23
      ! R x E334 -> E334 (52, 52)
      RES(1+NROWS*51:NROWS*52,52) = VAL%R
      ! E334 x R -> E334 (52, 1)
      RES(1+NROWS*51:NROWS*52,1) = VAL%E334
      ! E3 x E34 -> E334 (52, 17)
      RES(1+NROWS*51:NROWS*52,17) = VAL%E3
      ! E34 x E3 -> E334 (52, 4)
      RES(1+NROWS*51:NROWS*52,4) = VAL%E34
      ! E4 x E33 -> E334 (52, 14)
      RES(1+NROWS*51:NROWS*52,14) = VAL%E4
      ! E33 x E4 -> E334 (52, 5)
      RES(1+NROWS*51:NROWS*52,5) = VAL%E33
      ! R x E144 -> E144 (53, 53)
      RES(1+NROWS*52:NROWS*53,53) = VAL%R
      ! E144 x R -> E144 (53, 1)
      RES(1+NROWS*52:NROWS*53,1) = VAL%E144
      ! E1 x E44 -> E144 (53, 18)
      RES(1+NROWS*52:NROWS*53,18) = VAL%E1
      ! E44 x E1 -> E144 (53, 2)
      RES(1+NROWS*52:NROWS*53,2) = VAL%E44
      ! E4 x E14 -> E144 (53, 15)
      RES(1+NROWS*52:NROWS*53,15) = VAL%E4
      ! E14 x E4 -> E144 (53, 5)
      RES(1+NROWS*52:NROWS*53,5) = VAL%E14
      ! R x E244 -> E244 (54, 54)
      RES(1+NROWS*53:NROWS*54,54) = VAL%R
      ! E244 x R -> E244 (54, 1)
      RES(1+NROWS*53:NROWS*54,1) = VAL%E244
      ! E2 x E44 -> E244 (54, 18)
      RES(1+NROWS*53:NROWS*54,18) = VAL%E2
      ! E44 x E2 -> E244 (54, 3)
      RES(1+NROWS*53:NROWS*54,3) = VAL%E44
      ! E4 x E24 -> E244 (54, 16)
      RES(1+NROWS*53:NROWS*54,16) = VAL%E4
      ! E24 x E4 -> E244 (54, 5)
      RES(1+NROWS*53:NROWS*54,5) = VAL%E24
      ! R x E344 -> E344 (55, 55)
      RES(1+NROWS*54:NROWS*55,55) = VAL%R
      ! E344 x R -> E344 (55, 1)
      RES(1+NROWS*54:NROWS*55,1) = VAL%E344
      ! E3 x E44 -> E344 (55, 18)
      RES(1+NROWS*54:NROWS*55,18) = VAL%E3
      ! E44 x E3 -> E344 (55, 4)
      RES(1+NROWS*54:NROWS*55,4) = VAL%E44
      ! E4 x E34 -> E344 (55, 17)
      RES(1+NROWS*54:NROWS*55,17) = VAL%E4
      ! E34 x E4 -> E344 (55, 5)
      RES(1+NROWS*54:NROWS*55,5) = VAL%E34
      ! R x E444 -> E444 (56, 56)
      RES(1+NROWS*55:NROWS*56,56) = VAL%R
      ! E444 x R -> E444 (56, 1)
      RES(1+NROWS*55:NROWS*56,1) = VAL%E444
      ! E4 x E44 -> E444 (56, 18)
      RES(1+NROWS*55:NROWS*56,18) = VAL%E4
      ! E44 x E4 -> E444 (56, 5)
      RES(1+NROWS*55:NROWS*56,5) = VAL%E44
      ! R x E115 -> E115 (57, 57)
      RES(1+NROWS*56:NROWS*57,57) = VAL%R
      ! E115 x R -> E115 (57, 1)
      RES(1+NROWS*56:NROWS*57,1) = VAL%E115
      ! E1 x E15 -> E115 (57, 19)
      RES(1+NROWS*56:NROWS*57,19) = VAL%E1
      ! E15 x E1 -> E115 (57, 2)
      RES(1+NROWS*56:NROWS*57,2) = VAL%E15
      ! E5 x E11 -> E115 (57, 9)
      RES(1+NROWS*56:NROWS*57,9) = VAL%E5
      ! E11 x E5 -> E115 (57, 6)
      RES(1+NROWS*56:NROWS*57,6) = VAL%E11
      ! R x E125 -> E125 (58, 58)
      RES(1+NROWS*57:NROWS*58,58) = VAL%R
      ! E125 x R -> E125 (58, 1)
      RES(1+NROWS*57:NROWS*58,1) = VAL%E125
      ! E1 x E25 -> E125 (58, 20)
      RES(1+NROWS*57:NROWS*58,20) = VAL%E1
      ! E25 x E1 -> E125 (58, 2)
      RES(1+NROWS*57:NROWS*58,2) = VAL%E25
      ! E2 x E15 -> E125 (58, 19)
      RES(1+NROWS*57:NROWS*58,19) = VAL%E2
      ! E15 x E2 -> E125 (58, 3)
      RES(1+NROWS*57:NROWS*58,3) = VAL%E15
      ! E5 x E12 -> E125 (58, 10)
      RES(1+NROWS*57:NROWS*58,10) = VAL%E5
      ! E12 x E5 -> E125 (58, 6)
      RES(1+NROWS*57:NROWS*58,6) = VAL%E12
      ! R x E225 -> E225 (59, 59)
      RES(1+NROWS*58:NROWS*59,59) = VAL%R
      ! E225 x R -> E225 (59, 1)
      RES(1+NROWS*58:NROWS*59,1) = VAL%E225
      ! E2 x E25 -> E225 (59, 20)
      RES(1+NROWS*58:NROWS*59,20) = VAL%E2
      ! E25 x E2 -> E225 (59, 3)
      RES(1+NROWS*58:NROWS*59,3) = VAL%E25
      ! E5 x E22 -> E225 (59, 11)
      RES(1+NROWS*58:NROWS*59,11) = VAL%E5
      ! E22 x E5 -> E225 (59, 6)
      RES(1+NROWS*58:NROWS*59,6) = VAL%E22
      ! R x E135 -> E135 (60, 60)
      RES(1+NROWS*59:NROWS*60,60) = VAL%R
      ! E135 x R -> E135 (60, 1)
      RES(1+NROWS*59:NROWS*60,1) = VAL%E135
      ! E1 x E35 -> E135 (60, 21)
      RES(1+NROWS*59:NROWS*60,21) = VAL%E1
      ! E35 x E1 -> E135 (60, 2)
      RES(1+NROWS*59:NROWS*60,2) = VAL%E35
      ! E3 x E15 -> E135 (60, 19)
      RES(1+NROWS*59:NROWS*60,19) = VAL%E3
      ! E15 x E3 -> E135 (60, 4)
      RES(1+NROWS*59:NROWS*60,4) = VAL%E15
      ! E5 x E13 -> E135 (60, 12)
      RES(1+NROWS*59:NROWS*60,12) = VAL%E5
      ! E13 x E5 -> E135 (60, 6)
      RES(1+NROWS*59:NROWS*60,6) = VAL%E13
      ! R x E235 -> E235 (61, 61)
      RES(1+NROWS*60:NROWS*61,61) = VAL%R
      ! E235 x R -> E235 (61, 1)
      RES(1+NROWS*60:NROWS*61,1) = VAL%E235
      ! E2 x E35 -> E235 (61, 21)
      RES(1+NROWS*60:NROWS*61,21) = VAL%E2
      ! E35 x E2 -> E235 (61, 3)
      RES(1+NROWS*60:NROWS*61,3) = VAL%E35
      ! E3 x E25 -> E235 (61, 20)
      RES(1+NROWS*60:NROWS*61,20) = VAL%E3
      ! E25 x E3 -> E235 (61, 4)
      RES(1+NROWS*60:NROWS*61,4) = VAL%E25
      ! E5 x E23 -> E235 (61, 13)
      RES(1+NROWS*60:NROWS*61,13) = VAL%E5
      ! E23 x E5 -> E235 (61, 6)
      RES(1+NROWS*60:NROWS*61,6) = VAL%E23
      ! R x E335 -> E335 (62, 62)
      RES(1+NROWS*61:NROWS*62,62) = VAL%R
      ! E335 x R -> E335 (62, 1)
      RES(1+NROWS*61:NROWS*62,1) = VAL%E335
      ! E3 x E35 -> E335 (62, 21)
      RES(1+NROWS*61:NROWS*62,21) = VAL%E3
      ! E35 x E3 -> E335 (62, 4)
      RES(1+NROWS*61:NROWS*62,4) = VAL%E35
      ! E5 x E33 -> E335 (62, 14)
      RES(1+NROWS*61:NROWS*62,14) = VAL%E5
      ! E33 x E5 -> E335 (62, 6)
      RES(1+NROWS*61:NROWS*62,6) = VAL%E33
      ! R x E145 -> E145 (63, 63)
      RES(1+NROWS*62:NROWS*63,63) = VAL%R
      ! E145 x R -> E145 (63, 1)
      RES(1+NROWS*62:NROWS*63,1) = VAL%E145
      ! E1 x E45 -> E145 (63, 22)
      RES(1+NROWS*62:NROWS*63,22) = VAL%E1
      ! E45 x E1 -> E145 (63, 2)
      RES(1+NROWS*62:NROWS*63,2) = VAL%E45
      ! E4 x E15 -> E145 (63, 19)
      RES(1+NROWS*62:NROWS*63,19) = VAL%E4
      ! E15 x E4 -> E145 (63, 5)
      RES(1+NROWS*62:NROWS*63,5) = VAL%E15
      ! E5 x E14 -> E145 (63, 15)
      RES(1+NROWS*62:NROWS*63,15) = VAL%E5
      ! E14 x E5 -> E145 (63, 6)
      RES(1+NROWS*62:NROWS*63,6) = VAL%E14
      ! R x E245 -> E245 (64, 64)
      RES(1+NROWS*63:NROWS*64,64) = VAL%R
      ! E245 x R -> E245 (64, 1)
      RES(1+NROWS*63:NROWS*64,1) = VAL%E245
      ! E2 x E45 -> E245 (64, 22)
      RES(1+NROWS*63:NROWS*64,22) = VAL%E2
      ! E45 x E2 -> E245 (64, 3)
      RES(1+NROWS*63:NROWS*64,3) = VAL%E45
      ! E4 x E25 -> E245 (64, 20)
      RES(1+NROWS*63:NROWS*64,20) = VAL%E4
      ! E25 x E4 -> E245 (64, 5)
      RES(1+NROWS*63:NROWS*64,5) = VAL%E25
      ! E5 x E24 -> E245 (64, 16)
      RES(1+NROWS*63:NROWS*64,16) = VAL%E5
      ! E24 x E5 -> E245 (64, 6)
      RES(1+NROWS*63:NROWS*64,6) = VAL%E24
      ! R x E345 -> E345 (65, 65)
      RES(1+NROWS*64:NROWS*65,65) = VAL%R
      ! E345 x R -> E345 (65, 1)
      RES(1+NROWS*64:NROWS*65,1) = VAL%E345
      ! E3 x E45 -> E345 (65, 22)
      RES(1+NROWS*64:NROWS*65,22) = VAL%E3
      ! E45 x E3 -> E345 (65, 4)
      RES(1+NROWS*64:NROWS*65,4) = VAL%E45
      ! E4 x E35 -> E345 (65, 21)
      RES(1+NROWS*64:NROWS*65,21) = VAL%E4
      ! E35 x E4 -> E345 (65, 5)
      RES(1+NROWS*64:NROWS*65,5) = VAL%E35
      ! E5 x E34 -> E345 (65, 17)
      RES(1+NROWS*64:NROWS*65,17) = VAL%E5
      ! E34 x E5 -> E345 (65, 6)
      RES(1+NROWS*64:NROWS*65,6) = VAL%E34
      ! R x E445 -> E445 (66, 66)
      RES(1+NROWS*65:NROWS*66,66) = VAL%R
      ! E445 x R -> E445 (66, 1)
      RES(1+NROWS*65:NROWS*66,1) = VAL%E445
      ! E4 x E45 -> E445 (66, 22)
      RES(1+NROWS*65:NROWS*66,22) = VAL%E4
      ! E45 x E4 -> E445 (66, 5)
      RES(1+NROWS*65:NROWS*66,5) = VAL%E45
      ! E5 x E44 -> E445 (66, 18)
      RES(1+NROWS*65:NROWS*66,18) = VAL%E5
      ! E44 x E5 -> E445 (66, 6)
      RES(1+NROWS*65:NROWS*66,6) = VAL%E44
      ! R x E155 -> E155 (67, 67)
      RES(1+NROWS*66:NROWS*67,67) = VAL%R
      ! E155 x R -> E155 (67, 1)
      RES(1+NROWS*66:NROWS*67,1) = VAL%E155
      ! E1 x E55 -> E155 (67, 23)
      RES(1+NROWS*66:NROWS*67,23) = VAL%E1
      ! E55 x E1 -> E155 (67, 2)
      RES(1+NROWS*66:NROWS*67,2) = VAL%E55
      ! E5 x E15 -> E155 (67, 19)
      RES(1+NROWS*66:NROWS*67,19) = VAL%E5
      ! E15 x E5 -> E155 (67, 6)
      RES(1+NROWS*66:NROWS*67,6) = VAL%E15
      ! R x E255 -> E255 (68, 68)
      RES(1+NROWS*67:NROWS*68,68) = VAL%R
      ! E255 x R -> E255 (68, 1)
      RES(1+NROWS*67:NROWS*68,1) = VAL%E255
      ! E2 x E55 -> E255 (68, 23)
      RES(1+NROWS*67:NROWS*68,23) = VAL%E2
      ! E55 x E2 -> E255 (68, 3)
      RES(1+NROWS*67:NROWS*68,3) = VAL%E55
      ! E5 x E25 -> E255 (68, 20)
      RES(1+NROWS*67:NROWS*68,20) = VAL%E5
      ! E25 x E5 -> E255 (68, 6)
      RES(1+NROWS*67:NROWS*68,6) = VAL%E25
      ! R x E355 -> E355 (69, 69)
      RES(1+NROWS*68:NROWS*69,69) = VAL%R
      ! E355 x R -> E355 (69, 1)
      RES(1+NROWS*68:NROWS*69,1) = VAL%E355
      ! E3 x E55 -> E355 (69, 23)
      RES(1+NROWS*68:NROWS*69,23) = VAL%E3
      ! E55 x E3 -> E355 (69, 4)
      RES(1+NROWS*68:NROWS*69,4) = VAL%E55
      ! E5 x E35 -> E355 (69, 21)
      RES(1+NROWS*68:NROWS*69,21) = VAL%E5
      ! E35 x E5 -> E355 (69, 6)
      RES(1+NROWS*68:NROWS*69,6) = VAL%E35
      ! R x E455 -> E455 (70, 70)
      RES(1+NROWS*69:NROWS*70,70) = VAL%R
      ! E455 x R -> E455 (70, 1)
      RES(1+NROWS*69:NROWS*70,1) = VAL%E455
      ! E4 x E55 -> E455 (70, 23)
      RES(1+NROWS*69:NROWS*70,23) = VAL%E4
      ! E55 x E4 -> E455 (70, 5)
      RES(1+NROWS*69:NROWS*70,5) = VAL%E55
      ! E5 x E45 -> E455 (70, 22)
      RES(1+NROWS*69:NROWS*70,22) = VAL%E5
      ! E45 x E5 -> E455 (70, 6)
      RES(1+NROWS*69:NROWS*70,6) = VAL%E45
      ! R x E555 -> E555 (71, 71)
      RES(1+NROWS*70:NROWS*71,71) = VAL%R
      ! E555 x R -> E555 (71, 1)
      RES(1+NROWS*70:NROWS*71,1) = VAL%E555
      ! E5 x E55 -> E555 (71, 23)
      RES(1+NROWS*70:NROWS*71,23) = VAL%E5
      ! E55 x E5 -> E555 (71, 6)
      RES(1+NROWS*70:NROWS*71,6) = VAL%E55
      ! R x E116 -> E116 (72, 72)
      RES(1+NROWS*71:NROWS*72,72) = VAL%R
      ! E116 x R -> E116 (72, 1)
      RES(1+NROWS*71:NROWS*72,1) = VAL%E116
      ! E1 x E16 -> E116 (72, 24)
      RES(1+NROWS*71:NROWS*72,24) = VAL%E1
      ! E16 x E1 -> E116 (72, 2)
      RES(1+NROWS*71:NROWS*72,2) = VAL%E16
      ! E6 x E11 -> E116 (72, 9)
      RES(1+NROWS*71:NROWS*72,9) = VAL%E6
      ! E11 x E6 -> E116 (72, 7)
      RES(1+NROWS*71:NROWS*72,7) = VAL%E11
      ! R x E126 -> E126 (73, 73)
      RES(1+NROWS*72:NROWS*73,73) = VAL%R
      ! E126 x R -> E126 (73, 1)
      RES(1+NROWS*72:NROWS*73,1) = VAL%E126
      ! E1 x E26 -> E126 (73, 25)
      RES(1+NROWS*72:NROWS*73,25) = VAL%E1
      ! E26 x E1 -> E126 (73, 2)
      RES(1+NROWS*72:NROWS*73,2) = VAL%E26
      ! E2 x E16 -> E126 (73, 24)
      RES(1+NROWS*72:NROWS*73,24) = VAL%E2
      ! E16 x E2 -> E126 (73, 3)
      RES(1+NROWS*72:NROWS*73,3) = VAL%E16
      ! E6 x E12 -> E126 (73, 10)
      RES(1+NROWS*72:NROWS*73,10) = VAL%E6
      ! E12 x E6 -> E126 (73, 7)
      RES(1+NROWS*72:NROWS*73,7) = VAL%E12
      ! R x E226 -> E226 (74, 74)
      RES(1+NROWS*73:NROWS*74,74) = VAL%R
      ! E226 x R -> E226 (74, 1)
      RES(1+NROWS*73:NROWS*74,1) = VAL%E226
      ! E2 x E26 -> E226 (74, 25)
      RES(1+NROWS*73:NROWS*74,25) = VAL%E2
      ! E26 x E2 -> E226 (74, 3)
      RES(1+NROWS*73:NROWS*74,3) = VAL%E26
      ! E6 x E22 -> E226 (74, 11)
      RES(1+NROWS*73:NROWS*74,11) = VAL%E6
      ! E22 x E6 -> E226 (74, 7)
      RES(1+NROWS*73:NROWS*74,7) = VAL%E22
      ! R x E136 -> E136 (75, 75)
      RES(1+NROWS*74:NROWS*75,75) = VAL%R
      ! E136 x R -> E136 (75, 1)
      RES(1+NROWS*74:NROWS*75,1) = VAL%E136
      ! E1 x E36 -> E136 (75, 26)
      RES(1+NROWS*74:NROWS*75,26) = VAL%E1
      ! E36 x E1 -> E136 (75, 2)
      RES(1+NROWS*74:NROWS*75,2) = VAL%E36
      ! E3 x E16 -> E136 (75, 24)
      RES(1+NROWS*74:NROWS*75,24) = VAL%E3
      ! E16 x E3 -> E136 (75, 4)
      RES(1+NROWS*74:NROWS*75,4) = VAL%E16
      ! E6 x E13 -> E136 (75, 12)
      RES(1+NROWS*74:NROWS*75,12) = VAL%E6
      ! E13 x E6 -> E136 (75, 7)
      RES(1+NROWS*74:NROWS*75,7) = VAL%E13
      ! R x E236 -> E236 (76, 76)
      RES(1+NROWS*75:NROWS*76,76) = VAL%R
      ! E236 x R -> E236 (76, 1)
      RES(1+NROWS*75:NROWS*76,1) = VAL%E236
      ! E2 x E36 -> E236 (76, 26)
      RES(1+NROWS*75:NROWS*76,26) = VAL%E2
      ! E36 x E2 -> E236 (76, 3)
      RES(1+NROWS*75:NROWS*76,3) = VAL%E36
      ! E3 x E26 -> E236 (76, 25)
      RES(1+NROWS*75:NROWS*76,25) = VAL%E3
      ! E26 x E3 -> E236 (76, 4)
      RES(1+NROWS*75:NROWS*76,4) = VAL%E26
      ! E6 x E23 -> E236 (76, 13)
      RES(1+NROWS*75:NROWS*76,13) = VAL%E6
      ! E23 x E6 -> E236 (76, 7)
      RES(1+NROWS*75:NROWS*76,7) = VAL%E23
      ! R x E336 -> E336 (77, 77)
      RES(1+NROWS*76:NROWS*77,77) = VAL%R
      ! E336 x R -> E336 (77, 1)
      RES(1+NROWS*76:NROWS*77,1) = VAL%E336
      ! E3 x E36 -> E336 (77, 26)
      RES(1+NROWS*76:NROWS*77,26) = VAL%E3
      ! E36 x E3 -> E336 (77, 4)
      RES(1+NROWS*76:NROWS*77,4) = VAL%E36
      ! E6 x E33 -> E336 (77, 14)
      RES(1+NROWS*76:NROWS*77,14) = VAL%E6
      ! E33 x E6 -> E336 (77, 7)
      RES(1+NROWS*76:NROWS*77,7) = VAL%E33
      ! R x E146 -> E146 (78, 78)
      RES(1+NROWS*77:NROWS*78,78) = VAL%R
      ! E146 x R -> E146 (78, 1)
      RES(1+NROWS*77:NROWS*78,1) = VAL%E146
      ! E1 x E46 -> E146 (78, 27)
      RES(1+NROWS*77:NROWS*78,27) = VAL%E1
      ! E46 x E1 -> E146 (78, 2)
      RES(1+NROWS*77:NROWS*78,2) = VAL%E46
      ! E4 x E16 -> E146 (78, 24)
      RES(1+NROWS*77:NROWS*78,24) = VAL%E4
      ! E16 x E4 -> E146 (78, 5)
      RES(1+NROWS*77:NROWS*78,5) = VAL%E16
      ! E6 x E14 -> E146 (78, 15)
      RES(1+NROWS*77:NROWS*78,15) = VAL%E6
      ! E14 x E6 -> E146 (78, 7)
      RES(1+NROWS*77:NROWS*78,7) = VAL%E14
      ! R x E246 -> E246 (79, 79)
      RES(1+NROWS*78:NROWS*79,79) = VAL%R
      ! E246 x R -> E246 (79, 1)
      RES(1+NROWS*78:NROWS*79,1) = VAL%E246
      ! E2 x E46 -> E246 (79, 27)
      RES(1+NROWS*78:NROWS*79,27) = VAL%E2
      ! E46 x E2 -> E246 (79, 3)
      RES(1+NROWS*78:NROWS*79,3) = VAL%E46
      ! E4 x E26 -> E246 (79, 25)
      RES(1+NROWS*78:NROWS*79,25) = VAL%E4
      ! E26 x E4 -> E246 (79, 5)
      RES(1+NROWS*78:NROWS*79,5) = VAL%E26
      ! E6 x E24 -> E246 (79, 16)
      RES(1+NROWS*78:NROWS*79,16) = VAL%E6
      ! E24 x E6 -> E246 (79, 7)
      RES(1+NROWS*78:NROWS*79,7) = VAL%E24
      ! R x E346 -> E346 (80, 80)
      RES(1+NROWS*79:NROWS*80,80) = VAL%R
      ! E346 x R -> E346 (80, 1)
      RES(1+NROWS*79:NROWS*80,1) = VAL%E346
      ! E3 x E46 -> E346 (80, 27)
      RES(1+NROWS*79:NROWS*80,27) = VAL%E3
      ! E46 x E3 -> E346 (80, 4)
      RES(1+NROWS*79:NROWS*80,4) = VAL%E46
      ! E4 x E36 -> E346 (80, 26)
      RES(1+NROWS*79:NROWS*80,26) = VAL%E4
      ! E36 x E4 -> E346 (80, 5)
      RES(1+NROWS*79:NROWS*80,5) = VAL%E36
      ! E6 x E34 -> E346 (80, 17)
      RES(1+NROWS*79:NROWS*80,17) = VAL%E6
      ! E34 x E6 -> E346 (80, 7)
      RES(1+NROWS*79:NROWS*80,7) = VAL%E34
      ! R x E446 -> E446 (81, 81)
      RES(1+NROWS*80:NROWS*81,81) = VAL%R
      ! E446 x R -> E446 (81, 1)
      RES(1+NROWS*80:NROWS*81,1) = VAL%E446
      ! E4 x E46 -> E446 (81, 27)
      RES(1+NROWS*80:NROWS*81,27) = VAL%E4
      ! E46 x E4 -> E446 (81, 5)
      RES(1+NROWS*80:NROWS*81,5) = VAL%E46
      ! E6 x E44 -> E446 (81, 18)
      RES(1+NROWS*80:NROWS*81,18) = VAL%E6
      ! E44 x E6 -> E446 (81, 7)
      RES(1+NROWS*80:NROWS*81,7) = VAL%E44
      ! R x E156 -> E156 (82, 82)
      RES(1+NROWS*81:NROWS*82,82) = VAL%R
      ! E156 x R -> E156 (82, 1)
      RES(1+NROWS*81:NROWS*82,1) = VAL%E156
      ! E1 x E56 -> E156 (82, 28)
      RES(1+NROWS*81:NROWS*82,28) = VAL%E1
      ! E56 x E1 -> E156 (82, 2)
      RES(1+NROWS*81:NROWS*82,2) = VAL%E56
      ! E5 x E16 -> E156 (82, 24)
      RES(1+NROWS*81:NROWS*82,24) = VAL%E5
      ! E16 x E5 -> E156 (82, 6)
      RES(1+NROWS*81:NROWS*82,6) = VAL%E16
      ! E6 x E15 -> E156 (82, 19)
      RES(1+NROWS*81:NROWS*82,19) = VAL%E6
      ! E15 x E6 -> E156 (82, 7)
      RES(1+NROWS*81:NROWS*82,7) = VAL%E15
      ! R x E256 -> E256 (83, 83)
      RES(1+NROWS*82:NROWS*83,83) = VAL%R
      ! E256 x R -> E256 (83, 1)
      RES(1+NROWS*82:NROWS*83,1) = VAL%E256
      ! E2 x E56 -> E256 (83, 28)
      RES(1+NROWS*82:NROWS*83,28) = VAL%E2
      ! E56 x E2 -> E256 (83, 3)
      RES(1+NROWS*82:NROWS*83,3) = VAL%E56
      ! E5 x E26 -> E256 (83, 25)
      RES(1+NROWS*82:NROWS*83,25) = VAL%E5
      ! E26 x E5 -> E256 (83, 6)
      RES(1+NROWS*82:NROWS*83,6) = VAL%E26
      ! E6 x E25 -> E256 (83, 20)
      RES(1+NROWS*82:NROWS*83,20) = VAL%E6
      ! E25 x E6 -> E256 (83, 7)
      RES(1+NROWS*82:NROWS*83,7) = VAL%E25
      ! R x E356 -> E356 (84, 84)
      RES(1+NROWS*83:NROWS*84,84) = VAL%R
      ! E356 x R -> E356 (84, 1)
      RES(1+NROWS*83:NROWS*84,1) = VAL%E356
      ! E3 x E56 -> E356 (84, 28)
      RES(1+NROWS*83:NROWS*84,28) = VAL%E3
      ! E56 x E3 -> E356 (84, 4)
      RES(1+NROWS*83:NROWS*84,4) = VAL%E56
      ! E5 x E36 -> E356 (84, 26)
      RES(1+NROWS*83:NROWS*84,26) = VAL%E5
      ! E36 x E5 -> E356 (84, 6)
      RES(1+NROWS*83:NROWS*84,6) = VAL%E36
      ! E6 x E35 -> E356 (84, 21)
      RES(1+NROWS*83:NROWS*84,21) = VAL%E6
      ! E35 x E6 -> E356 (84, 7)
      RES(1+NROWS*83:NROWS*84,7) = VAL%E35
      ! R x E456 -> E456 (85, 85)
      RES(1+NROWS*84:NROWS*85,85) = VAL%R
      ! E456 x R -> E456 (85, 1)
      RES(1+NROWS*84:NROWS*85,1) = VAL%E456
      ! E4 x E56 -> E456 (85, 28)
      RES(1+NROWS*84:NROWS*85,28) = VAL%E4
      ! E56 x E4 -> E456 (85, 5)
      RES(1+NROWS*84:NROWS*85,5) = VAL%E56
      ! E5 x E46 -> E456 (85, 27)
      RES(1+NROWS*84:NROWS*85,27) = VAL%E5
      ! E46 x E5 -> E456 (85, 6)
      RES(1+NROWS*84:NROWS*85,6) = VAL%E46
      ! E6 x E45 -> E456 (85, 22)
      RES(1+NROWS*84:NROWS*85,22) = VAL%E6
      ! E45 x E6 -> E456 (85, 7)
      RES(1+NROWS*84:NROWS*85,7) = VAL%E45
      ! R x E556 -> E556 (86, 86)
      RES(1+NROWS*85:NROWS*86,86) = VAL%R
      ! E556 x R -> E556 (86, 1)
      RES(1+NROWS*85:NROWS*86,1) = VAL%E556
      ! E5 x E56 -> E556 (86, 28)
      RES(1+NROWS*85:NROWS*86,28) = VAL%E5
      ! E56 x E5 -> E556 (86, 6)
      RES(1+NROWS*85:NROWS*86,6) = VAL%E56
      ! E6 x E55 -> E556 (86, 23)
      RES(1+NROWS*85:NROWS*86,23) = VAL%E6
      ! E55 x E6 -> E556 (86, 7)
      RES(1+NROWS*85:NROWS*86,7) = VAL%E55
      ! R x E166 -> E166 (87, 87)
      RES(1+NROWS*86:NROWS*87,87) = VAL%R
      ! E166 x R -> E166 (87, 1)
      RES(1+NROWS*86:NROWS*87,1) = VAL%E166
      ! E1 x E66 -> E166 (87, 29)
      RES(1+NROWS*86:NROWS*87,29) = VAL%E1
      ! E66 x E1 -> E166 (87, 2)
      RES(1+NROWS*86:NROWS*87,2) = VAL%E66
      ! E6 x E16 -> E166 (87, 24)
      RES(1+NROWS*86:NROWS*87,24) = VAL%E6
      ! E16 x E6 -> E166 (87, 7)
      RES(1+NROWS*86:NROWS*87,7) = VAL%E16
      ! R x E266 -> E266 (88, 88)
      RES(1+NROWS*87:NROWS*88,88) = VAL%R
      ! E266 x R -> E266 (88, 1)
      RES(1+NROWS*87:NROWS*88,1) = VAL%E266
      ! E2 x E66 -> E266 (88, 29)
      RES(1+NROWS*87:NROWS*88,29) = VAL%E2
      ! E66 x E2 -> E266 (88, 3)
      RES(1+NROWS*87:NROWS*88,3) = VAL%E66
      ! E6 x E26 -> E266 (88, 25)
      RES(1+NROWS*87:NROWS*88,25) = VAL%E6
      ! E26 x E6 -> E266 (88, 7)
      RES(1+NROWS*87:NROWS*88,7) = VAL%E26
      ! R x E366 -> E366 (89, 89)
      RES(1+NROWS*88:NROWS*89,89) = VAL%R
      ! E366 x R -> E366 (89, 1)
      RES(1+NROWS*88:NROWS*89,1) = VAL%E366
      ! E3 x E66 -> E366 (89, 29)
      RES(1+NROWS*88:NROWS*89,29) = VAL%E3
      ! E66 x E3 -> E366 (89, 4)
      RES(1+NROWS*88:NROWS*89,4) = VAL%E66
      ! E6 x E36 -> E366 (89, 26)
      RES(1+NROWS*88:NROWS*89,26) = VAL%E6
      ! E36 x E6 -> E366 (89, 7)
      RES(1+NROWS*88:NROWS*89,7) = VAL%E36
      ! R x E466 -> E466 (90, 90)
      RES(1+NROWS*89:NROWS*90,90) = VAL%R
      ! E466 x R -> E466 (90, 1)
      RES(1+NROWS*89:NROWS*90,1) = VAL%E466
      ! E4 x E66 -> E466 (90, 29)
      RES(1+NROWS*89:NROWS*90,29) = VAL%E4
      ! E66 x E4 -> E466 (90, 5)
      RES(1+NROWS*89:NROWS*90,5) = VAL%E66
      ! E6 x E46 -> E466 (90, 27)
      RES(1+NROWS*89:NROWS*90,27) = VAL%E6
      ! E46 x E6 -> E466 (90, 7)
      RES(1+NROWS*89:NROWS*90,7) = VAL%E46
      ! R x E566 -> E566 (91, 91)
      RES(1+NROWS*90:NROWS*91,91) = VAL%R
      ! E566 x R -> E566 (91, 1)
      RES(1+NROWS*90:NROWS*91,1) = VAL%E566
      ! E5 x E66 -> E566 (91, 29)
      RES(1+NROWS*90:NROWS*91,29) = VAL%E5
      ! E66 x E5 -> E566 (91, 6)
      RES(1+NROWS*90:NROWS*91,6) = VAL%E66
      ! E6 x E56 -> E566 (91, 28)
      RES(1+NROWS*90:NROWS*91,28) = VAL%E6
      ! E56 x E6 -> E566 (91, 7)
      RES(1+NROWS*90:NROWS*91,7) = VAL%E56
      ! R x E666 -> E666 (92, 92)
      RES(1+NROWS*91:NROWS*92,92) = VAL%R
      ! E666 x R -> E666 (92, 1)
      RES(1+NROWS*91:NROWS*92,1) = VAL%E666
      ! E6 x E66 -> E666 (92, 29)
      RES(1+NROWS*91:NROWS*92,29) = VAL%E6
      ! E66 x E6 -> E666 (92, 7)
      RES(1+NROWS*91:NROWS*92,7) = VAL%E66
      ! R x E117 -> E117 (93, 93)
      RES(1+NROWS*92:NROWS*93,93) = VAL%R
      ! E117 x R -> E117 (93, 1)
      RES(1+NROWS*92:NROWS*93,1) = VAL%E117
      ! E1 x E17 -> E117 (93, 30)
      RES(1+NROWS*92:NROWS*93,30) = VAL%E1
      ! E17 x E1 -> E117 (93, 2)
      RES(1+NROWS*92:NROWS*93,2) = VAL%E17
      ! E7 x E11 -> E117 (93, 9)
      RES(1+NROWS*92:NROWS*93,9) = VAL%E7
      ! E11 x E7 -> E117 (93, 8)
      RES(1+NROWS*92:NROWS*93,8) = VAL%E11
      ! R x E127 -> E127 (94, 94)
      RES(1+NROWS*93:NROWS*94,94) = VAL%R
      ! E127 x R -> E127 (94, 1)
      RES(1+NROWS*93:NROWS*94,1) = VAL%E127
      ! E1 x E27 -> E127 (94, 31)
      RES(1+NROWS*93:NROWS*94,31) = VAL%E1
      ! E27 x E1 -> E127 (94, 2)
      RES(1+NROWS*93:NROWS*94,2) = VAL%E27
      ! E2 x E17 -> E127 (94, 30)
      RES(1+NROWS*93:NROWS*94,30) = VAL%E2
      ! E17 x E2 -> E127 (94, 3)
      RES(1+NROWS*93:NROWS*94,3) = VAL%E17
      ! E7 x E12 -> E127 (94, 10)
      RES(1+NROWS*93:NROWS*94,10) = VAL%E7
      ! E12 x E7 -> E127 (94, 8)
      RES(1+NROWS*93:NROWS*94,8) = VAL%E12
      ! R x E227 -> E227 (95, 95)
      RES(1+NROWS*94:NROWS*95,95) = VAL%R
      ! E227 x R -> E227 (95, 1)
      RES(1+NROWS*94:NROWS*95,1) = VAL%E227
      ! E2 x E27 -> E227 (95, 31)
      RES(1+NROWS*94:NROWS*95,31) = VAL%E2
      ! E27 x E2 -> E227 (95, 3)
      RES(1+NROWS*94:NROWS*95,3) = VAL%E27
      ! E7 x E22 -> E227 (95, 11)
      RES(1+NROWS*94:NROWS*95,11) = VAL%E7
      ! E22 x E7 -> E227 (95, 8)
      RES(1+NROWS*94:NROWS*95,8) = VAL%E22
      ! R x E137 -> E137 (96, 96)
      RES(1+NROWS*95:NROWS*96,96) = VAL%R
      ! E137 x R -> E137 (96, 1)
      RES(1+NROWS*95:NROWS*96,1) = VAL%E137
      ! E1 x E37 -> E137 (96, 32)
      RES(1+NROWS*95:NROWS*96,32) = VAL%E1
      ! E37 x E1 -> E137 (96, 2)
      RES(1+NROWS*95:NROWS*96,2) = VAL%E37
      ! E3 x E17 -> E137 (96, 30)
      RES(1+NROWS*95:NROWS*96,30) = VAL%E3
      ! E17 x E3 -> E137 (96, 4)
      RES(1+NROWS*95:NROWS*96,4) = VAL%E17
      ! E7 x E13 -> E137 (96, 12)
      RES(1+NROWS*95:NROWS*96,12) = VAL%E7
      ! E13 x E7 -> E137 (96, 8)
      RES(1+NROWS*95:NROWS*96,8) = VAL%E13
      ! R x E237 -> E237 (97, 97)
      RES(1+NROWS*96:NROWS*97,97) = VAL%R
      ! E237 x R -> E237 (97, 1)
      RES(1+NROWS*96:NROWS*97,1) = VAL%E237
      ! E2 x E37 -> E237 (97, 32)
      RES(1+NROWS*96:NROWS*97,32) = VAL%E2
      ! E37 x E2 -> E237 (97, 3)
      RES(1+NROWS*96:NROWS*97,3) = VAL%E37
      ! E3 x E27 -> E237 (97, 31)
      RES(1+NROWS*96:NROWS*97,31) = VAL%E3
      ! E27 x E3 -> E237 (97, 4)
      RES(1+NROWS*96:NROWS*97,4) = VAL%E27
      ! E7 x E23 -> E237 (97, 13)
      RES(1+NROWS*96:NROWS*97,13) = VAL%E7
      ! E23 x E7 -> E237 (97, 8)
      RES(1+NROWS*96:NROWS*97,8) = VAL%E23
      ! R x E337 -> E337 (98, 98)
      RES(1+NROWS*97:NROWS*98,98) = VAL%R
      ! E337 x R -> E337 (98, 1)
      RES(1+NROWS*97:NROWS*98,1) = VAL%E337
      ! E3 x E37 -> E337 (98, 32)
      RES(1+NROWS*97:NROWS*98,32) = VAL%E3
      ! E37 x E3 -> E337 (98, 4)
      RES(1+NROWS*97:NROWS*98,4) = VAL%E37
      ! E7 x E33 -> E337 (98, 14)
      RES(1+NROWS*97:NROWS*98,14) = VAL%E7
      ! E33 x E7 -> E337 (98, 8)
      RES(1+NROWS*97:NROWS*98,8) = VAL%E33
      ! R x E147 -> E147 (99, 99)
      RES(1+NROWS*98:NROWS*99,99) = VAL%R
      ! E147 x R -> E147 (99, 1)
      RES(1+NROWS*98:NROWS*99,1) = VAL%E147
      ! E1 x E47 -> E147 (99, 33)
      RES(1+NROWS*98:NROWS*99,33) = VAL%E1
      ! E47 x E1 -> E147 (99, 2)
      RES(1+NROWS*98:NROWS*99,2) = VAL%E47
      ! E4 x E17 -> E147 (99, 30)
      RES(1+NROWS*98:NROWS*99,30) = VAL%E4
      ! E17 x E4 -> E147 (99, 5)
      RES(1+NROWS*98:NROWS*99,5) = VAL%E17
      ! E7 x E14 -> E147 (99, 15)
      RES(1+NROWS*98:NROWS*99,15) = VAL%E7
      ! E14 x E7 -> E147 (99, 8)
      RES(1+NROWS*98:NROWS*99,8) = VAL%E14
      ! R x E247 -> E247 (100, 100)
      RES(1+NROWS*99:NROWS*100,100) = VAL%R
      ! E247 x R -> E247 (100, 1)
      RES(1+NROWS*99:NROWS*100,1) = VAL%E247
      ! E2 x E47 -> E247 (100, 33)
      RES(1+NROWS*99:NROWS*100,33) = VAL%E2
      ! E47 x E2 -> E247 (100, 3)
      RES(1+NROWS*99:NROWS*100,3) = VAL%E47
      ! E4 x E27 -> E247 (100, 31)
      RES(1+NROWS*99:NROWS*100,31) = VAL%E4
      ! E27 x E4 -> E247 (100, 5)
      RES(1+NROWS*99:NROWS*100,5) = VAL%E27
      ! E7 x E24 -> E247 (100, 16)
      RES(1+NROWS*99:NROWS*100,16) = VAL%E7
      ! E24 x E7 -> E247 (100, 8)
      RES(1+NROWS*99:NROWS*100,8) = VAL%E24
      ! R x E347 -> E347 (101, 101)
      RES(1+NROWS*100:NROWS*101,101) = VAL%R
      ! E347 x R -> E347 (101, 1)
      RES(1+NROWS*100:NROWS*101,1) = VAL%E347
      ! E3 x E47 -> E347 (101, 33)
      RES(1+NROWS*100:NROWS*101,33) = VAL%E3
      ! E47 x E3 -> E347 (101, 4)
      RES(1+NROWS*100:NROWS*101,4) = VAL%E47
      ! E4 x E37 -> E347 (101, 32)
      RES(1+NROWS*100:NROWS*101,32) = VAL%E4
      ! E37 x E4 -> E347 (101, 5)
      RES(1+NROWS*100:NROWS*101,5) = VAL%E37
      ! E7 x E34 -> E347 (101, 17)
      RES(1+NROWS*100:NROWS*101,17) = VAL%E7
      ! E34 x E7 -> E347 (101, 8)
      RES(1+NROWS*100:NROWS*101,8) = VAL%E34
      ! R x E447 -> E447 (102, 102)
      RES(1+NROWS*101:NROWS*102,102) = VAL%R
      ! E447 x R -> E447 (102, 1)
      RES(1+NROWS*101:NROWS*102,1) = VAL%E447
      ! E4 x E47 -> E447 (102, 33)
      RES(1+NROWS*101:NROWS*102,33) = VAL%E4
      ! E47 x E4 -> E447 (102, 5)
      RES(1+NROWS*101:NROWS*102,5) = VAL%E47
      ! E7 x E44 -> E447 (102, 18)
      RES(1+NROWS*101:NROWS*102,18) = VAL%E7
      ! E44 x E7 -> E447 (102, 8)
      RES(1+NROWS*101:NROWS*102,8) = VAL%E44
      ! R x E157 -> E157 (103, 103)
      RES(1+NROWS*102:NROWS*103,103) = VAL%R
      ! E157 x R -> E157 (103, 1)
      RES(1+NROWS*102:NROWS*103,1) = VAL%E157
      ! E1 x E57 -> E157 (103, 34)
      RES(1+NROWS*102:NROWS*103,34) = VAL%E1
      ! E57 x E1 -> E157 (103, 2)
      RES(1+NROWS*102:NROWS*103,2) = VAL%E57
      ! E5 x E17 -> E157 (103, 30)
      RES(1+NROWS*102:NROWS*103,30) = VAL%E5
      ! E17 x E5 -> E157 (103, 6)
      RES(1+NROWS*102:NROWS*103,6) = VAL%E17
      ! E7 x E15 -> E157 (103, 19)
      RES(1+NROWS*102:NROWS*103,19) = VAL%E7
      ! E15 x E7 -> E157 (103, 8)
      RES(1+NROWS*102:NROWS*103,8) = VAL%E15
      ! R x E257 -> E257 (104, 104)
      RES(1+NROWS*103:NROWS*104,104) = VAL%R
      ! E257 x R -> E257 (104, 1)
      RES(1+NROWS*103:NROWS*104,1) = VAL%E257
      ! E2 x E57 -> E257 (104, 34)
      RES(1+NROWS*103:NROWS*104,34) = VAL%E2
      ! E57 x E2 -> E257 (104, 3)
      RES(1+NROWS*103:NROWS*104,3) = VAL%E57
      ! E5 x E27 -> E257 (104, 31)
      RES(1+NROWS*103:NROWS*104,31) = VAL%E5
      ! E27 x E5 -> E257 (104, 6)
      RES(1+NROWS*103:NROWS*104,6) = VAL%E27
      ! E7 x E25 -> E257 (104, 20)
      RES(1+NROWS*103:NROWS*104,20) = VAL%E7
      ! E25 x E7 -> E257 (104, 8)
      RES(1+NROWS*103:NROWS*104,8) = VAL%E25
      ! R x E357 -> E357 (105, 105)
      RES(1+NROWS*104:NROWS*105,105) = VAL%R
      ! E357 x R -> E357 (105, 1)
      RES(1+NROWS*104:NROWS*105,1) = VAL%E357
      ! E3 x E57 -> E357 (105, 34)
      RES(1+NROWS*104:NROWS*105,34) = VAL%E3
      ! E57 x E3 -> E357 (105, 4)
      RES(1+NROWS*104:NROWS*105,4) = VAL%E57
      ! E5 x E37 -> E357 (105, 32)
      RES(1+NROWS*104:NROWS*105,32) = VAL%E5
      ! E37 x E5 -> E357 (105, 6)
      RES(1+NROWS*104:NROWS*105,6) = VAL%E37
      ! E7 x E35 -> E357 (105, 21)
      RES(1+NROWS*104:NROWS*105,21) = VAL%E7
      ! E35 x E7 -> E357 (105, 8)
      RES(1+NROWS*104:NROWS*105,8) = VAL%E35
      ! R x E457 -> E457 (106, 106)
      RES(1+NROWS*105:NROWS*106,106) = VAL%R
      ! E457 x R -> E457 (106, 1)
      RES(1+NROWS*105:NROWS*106,1) = VAL%E457
      ! E4 x E57 -> E457 (106, 34)
      RES(1+NROWS*105:NROWS*106,34) = VAL%E4
      ! E57 x E4 -> E457 (106, 5)
      RES(1+NROWS*105:NROWS*106,5) = VAL%E57
      ! E5 x E47 -> E457 (106, 33)
      RES(1+NROWS*105:NROWS*106,33) = VAL%E5
      ! E47 x E5 -> E457 (106, 6)
      RES(1+NROWS*105:NROWS*106,6) = VAL%E47
      ! E7 x E45 -> E457 (106, 22)
      RES(1+NROWS*105:NROWS*106,22) = VAL%E7
      ! E45 x E7 -> E457 (106, 8)
      RES(1+NROWS*105:NROWS*106,8) = VAL%E45
      ! R x E557 -> E557 (107, 107)
      RES(1+NROWS*106:NROWS*107,107) = VAL%R
      ! E557 x R -> E557 (107, 1)
      RES(1+NROWS*106:NROWS*107,1) = VAL%E557
      ! E5 x E57 -> E557 (107, 34)
      RES(1+NROWS*106:NROWS*107,34) = VAL%E5
      ! E57 x E5 -> E557 (107, 6)
      RES(1+NROWS*106:NROWS*107,6) = VAL%E57
      ! E7 x E55 -> E557 (107, 23)
      RES(1+NROWS*106:NROWS*107,23) = VAL%E7
      ! E55 x E7 -> E557 (107, 8)
      RES(1+NROWS*106:NROWS*107,8) = VAL%E55
      ! R x E167 -> E167 (108, 108)
      RES(1+NROWS*107:NROWS*108,108) = VAL%R
      ! E167 x R -> E167 (108, 1)
      RES(1+NROWS*107:NROWS*108,1) = VAL%E167
      ! E1 x E67 -> E167 (108, 35)
      RES(1+NROWS*107:NROWS*108,35) = VAL%E1
      ! E67 x E1 -> E167 (108, 2)
      RES(1+NROWS*107:NROWS*108,2) = VAL%E67
      ! E6 x E17 -> E167 (108, 30)
      RES(1+NROWS*107:NROWS*108,30) = VAL%E6
      ! E17 x E6 -> E167 (108, 7)
      RES(1+NROWS*107:NROWS*108,7) = VAL%E17
      ! E7 x E16 -> E167 (108, 24)
      RES(1+NROWS*107:NROWS*108,24) = VAL%E7
      ! E16 x E7 -> E167 (108, 8)
      RES(1+NROWS*107:NROWS*108,8) = VAL%E16
      ! R x E267 -> E267 (109, 109)
      RES(1+NROWS*108:NROWS*109,109) = VAL%R
      ! E267 x R -> E267 (109, 1)
      RES(1+NROWS*108:NROWS*109,1) = VAL%E267
      ! E2 x E67 -> E267 (109, 35)
      RES(1+NROWS*108:NROWS*109,35) = VAL%E2
      ! E67 x E2 -> E267 (109, 3)
      RES(1+NROWS*108:NROWS*109,3) = VAL%E67
      ! E6 x E27 -> E267 (109, 31)
      RES(1+NROWS*108:NROWS*109,31) = VAL%E6
      ! E27 x E6 -> E267 (109, 7)
      RES(1+NROWS*108:NROWS*109,7) = VAL%E27
      ! E7 x E26 -> E267 (109, 25)
      RES(1+NROWS*108:NROWS*109,25) = VAL%E7
      ! E26 x E7 -> E267 (109, 8)
      RES(1+NROWS*108:NROWS*109,8) = VAL%E26
      ! R x E367 -> E367 (110, 110)
      RES(1+NROWS*109:NROWS*110,110) = VAL%R
      ! E367 x R -> E367 (110, 1)
      RES(1+NROWS*109:NROWS*110,1) = VAL%E367
      ! E3 x E67 -> E367 (110, 35)
      RES(1+NROWS*109:NROWS*110,35) = VAL%E3
      ! E67 x E3 -> E367 (110, 4)
      RES(1+NROWS*109:NROWS*110,4) = VAL%E67
      ! E6 x E37 -> E367 (110, 32)
      RES(1+NROWS*109:NROWS*110,32) = VAL%E6
      ! E37 x E6 -> E367 (110, 7)
      RES(1+NROWS*109:NROWS*110,7) = VAL%E37
      ! E7 x E36 -> E367 (110, 26)
      RES(1+NROWS*109:NROWS*110,26) = VAL%E7
      ! E36 x E7 -> E367 (110, 8)
      RES(1+NROWS*109:NROWS*110,8) = VAL%E36
      ! R x E467 -> E467 (111, 111)
      RES(1+NROWS*110:NROWS*111,111) = VAL%R
      ! E467 x R -> E467 (111, 1)
      RES(1+NROWS*110:NROWS*111,1) = VAL%E467
      ! E4 x E67 -> E467 (111, 35)
      RES(1+NROWS*110:NROWS*111,35) = VAL%E4
      ! E67 x E4 -> E467 (111, 5)
      RES(1+NROWS*110:NROWS*111,5) = VAL%E67
      ! E6 x E47 -> E467 (111, 33)
      RES(1+NROWS*110:NROWS*111,33) = VAL%E6
      ! E47 x E6 -> E467 (111, 7)
      RES(1+NROWS*110:NROWS*111,7) = VAL%E47
      ! E7 x E46 -> E467 (111, 27)
      RES(1+NROWS*110:NROWS*111,27) = VAL%E7
      ! E46 x E7 -> E467 (111, 8)
      RES(1+NROWS*110:NROWS*111,8) = VAL%E46
      ! R x E567 -> E567 (112, 112)
      RES(1+NROWS*111:NROWS*112,112) = VAL%R
      ! E567 x R -> E567 (112, 1)
      RES(1+NROWS*111:NROWS*112,1) = VAL%E567
      ! E5 x E67 -> E567 (112, 35)
      RES(1+NROWS*111:NROWS*112,35) = VAL%E5
      ! E67 x E5 -> E567 (112, 6)
      RES(1+NROWS*111:NROWS*112,6) = VAL%E67
      ! E6 x E57 -> E567 (112, 34)
      RES(1+NROWS*111:NROWS*112,34) = VAL%E6
      ! E57 x E6 -> E567 (112, 7)
      RES(1+NROWS*111:NROWS*112,7) = VAL%E57
      ! E7 x E56 -> E567 (112, 28)
      RES(1+NROWS*111:NROWS*112,28) = VAL%E7
      ! E56 x E7 -> E567 (112, 8)
      RES(1+NROWS*111:NROWS*112,8) = VAL%E56
      ! R x E667 -> E667 (113, 113)
      RES(1+NROWS*112:NROWS*113,113) = VAL%R
      ! E667 x R -> E667 (113, 1)
      RES(1+NROWS*112:NROWS*113,1) = VAL%E667
      ! E6 x E67 -> E667 (113, 35)
      RES(1+NROWS*112:NROWS*113,35) = VAL%E6
      ! E67 x E6 -> E667 (113, 7)
      RES(1+NROWS*112:NROWS*113,7) = VAL%E67
      ! E7 x E66 -> E667 (113, 29)
      RES(1+NROWS*112:NROWS*113,29) = VAL%E7
      ! E66 x E7 -> E667 (113, 8)
      RES(1+NROWS*112:NROWS*113,8) = VAL%E66
      ! R x E177 -> E177 (114, 114)
      RES(1+NROWS*113:NROWS*114,114) = VAL%R
      ! E177 x R -> E177 (114, 1)
      RES(1+NROWS*113:NROWS*114,1) = VAL%E177
      ! E1 x E77 -> E177 (114, 36)
      RES(1+NROWS*113:NROWS*114,36) = VAL%E1
      ! E77 x E1 -> E177 (114, 2)
      RES(1+NROWS*113:NROWS*114,2) = VAL%E77
      ! E7 x E17 -> E177 (114, 30)
      RES(1+NROWS*113:NROWS*114,30) = VAL%E7
      ! E17 x E7 -> E177 (114, 8)
      RES(1+NROWS*113:NROWS*114,8) = VAL%E17
      ! R x E277 -> E277 (115, 115)
      RES(1+NROWS*114:NROWS*115,115) = VAL%R
      ! E277 x R -> E277 (115, 1)
      RES(1+NROWS*114:NROWS*115,1) = VAL%E277
      ! E2 x E77 -> E277 (115, 36)
      RES(1+NROWS*114:NROWS*115,36) = VAL%E2
      ! E77 x E2 -> E277 (115, 3)
      RES(1+NROWS*114:NROWS*115,3) = VAL%E77
      ! E7 x E27 -> E277 (115, 31)
      RES(1+NROWS*114:NROWS*115,31) = VAL%E7
      ! E27 x E7 -> E277 (115, 8)
      RES(1+NROWS*114:NROWS*115,8) = VAL%E27
      ! R x E377 -> E377 (116, 116)
      RES(1+NROWS*115:NROWS*116,116) = VAL%R
      ! E377 x R -> E377 (116, 1)
      RES(1+NROWS*115:NROWS*116,1) = VAL%E377
      ! E3 x E77 -> E377 (116, 36)
      RES(1+NROWS*115:NROWS*116,36) = VAL%E3
      ! E77 x E3 -> E377 (116, 4)
      RES(1+NROWS*115:NROWS*116,4) = VAL%E77
      ! E7 x E37 -> E377 (116, 32)
      RES(1+NROWS*115:NROWS*116,32) = VAL%E7
      ! E37 x E7 -> E377 (116, 8)
      RES(1+NROWS*115:NROWS*116,8) = VAL%E37
      ! R x E477 -> E477 (117, 117)
      RES(1+NROWS*116:NROWS*117,117) = VAL%R
      ! E477 x R -> E477 (117, 1)
      RES(1+NROWS*116:NROWS*117,1) = VAL%E477
      ! E4 x E77 -> E477 (117, 36)
      RES(1+NROWS*116:NROWS*117,36) = VAL%E4
      ! E77 x E4 -> E477 (117, 5)
      RES(1+NROWS*116:NROWS*117,5) = VAL%E77
      ! E7 x E47 -> E477 (117, 33)
      RES(1+NROWS*116:NROWS*117,33) = VAL%E7
      ! E47 x E7 -> E477 (117, 8)
      RES(1+NROWS*116:NROWS*117,8) = VAL%E47
      ! R x E577 -> E577 (118, 118)
      RES(1+NROWS*117:NROWS*118,118) = VAL%R
      ! E577 x R -> E577 (118, 1)
      RES(1+NROWS*117:NROWS*118,1) = VAL%E577
      ! E5 x E77 -> E577 (118, 36)
      RES(1+NROWS*117:NROWS*118,36) = VAL%E5
      ! E77 x E5 -> E577 (118, 6)
      RES(1+NROWS*117:NROWS*118,6) = VAL%E77
      ! E7 x E57 -> E577 (118, 34)
      RES(1+NROWS*117:NROWS*118,34) = VAL%E7
      ! E57 x E7 -> E577 (118, 8)
      RES(1+NROWS*117:NROWS*118,8) = VAL%E57
      ! R x E677 -> E677 (119, 119)
      RES(1+NROWS*118:NROWS*119,119) = VAL%R
      ! E677 x R -> E677 (119, 1)
      RES(1+NROWS*118:NROWS*119,1) = VAL%E677
      ! E6 x E77 -> E677 (119, 36)
      RES(1+NROWS*118:NROWS*119,36) = VAL%E6
      ! E77 x E6 -> E677 (119, 7)
      RES(1+NROWS*118:NROWS*119,7) = VAL%E77
      ! E7 x E67 -> E677 (119, 35)
      RES(1+NROWS*118:NROWS*119,35) = VAL%E7
      ! E67 x E7 -> E677 (119, 8)
      RES(1+NROWS*118:NROWS*119,8) = VAL%E67
      ! R x E777 -> E777 (120, 120)
      RES(1+NROWS*119:NROWS*120,120) = VAL%R
      ! E777 x R -> E777 (120, 1)
      RES(1+NROWS*119:NROWS*120,1) = VAL%E777
      ! E7 x E77 -> E777 (120, 36)
      RES(1+NROWS*119:NROWS*120,36) = VAL%E7
      ! E77 x E7 -> E777 (120, 8)
      RES(1+NROWS*119:NROWS*120,8) = VAL%E77
   END FUNCTION ONUMM7N3_TO_CR_MAT_V

FUNCTION ONUMM7N3_TO_CR_MAT_M(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: VAL(:,:)
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
      ! R x E111 -> E111 (37, 37)
      RES(1+NROWS*36:NROWS*37,1+NCOLS*36:NCOLS*37) = VAL%R
      ! E111 x R -> E111 (37, 1)
      RES(1+NROWS*36:NROWS*37,1+NCOLS*0:NCOLS*1) = VAL%E111
      ! E1 x E11 -> E111 (37, 9)
      RES(1+NROWS*36:NROWS*37,1+NCOLS*8:NCOLS*9) = VAL%E1
      ! E11 x E1 -> E111 (37, 2)
      RES(1+NROWS*36:NROWS*37,1+NCOLS*1:NCOLS*2) = VAL%E11
      ! R x E112 -> E112 (38, 38)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*37:NCOLS*38) = VAL%R
      ! E112 x R -> E112 (38, 1)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*0:NCOLS*1) = VAL%E112
      ! E1 x E12 -> E112 (38, 10)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*9:NCOLS*10) = VAL%E1
      ! E12 x E1 -> E112 (38, 2)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*1:NCOLS*2) = VAL%E12
      ! E2 x E11 -> E112 (38, 9)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*8:NCOLS*9) = VAL%E2
      ! E11 x E2 -> E112 (38, 3)
      RES(1+NROWS*37:NROWS*38,1+NCOLS*2:NCOLS*3) = VAL%E11
      ! R x E122 -> E122 (39, 39)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*38:NCOLS*39) = VAL%R
      ! E122 x R -> E122 (39, 1)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*0:NCOLS*1) = VAL%E122
      ! E1 x E22 -> E122 (39, 11)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*10:NCOLS*11) = VAL%E1
      ! E22 x E1 -> E122 (39, 2)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*1:NCOLS*2) = VAL%E22
      ! E2 x E12 -> E122 (39, 10)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*9:NCOLS*10) = VAL%E2
      ! E12 x E2 -> E122 (39, 3)
      RES(1+NROWS*38:NROWS*39,1+NCOLS*2:NCOLS*3) = VAL%E12
      ! R x E222 -> E222 (40, 40)
      RES(1+NROWS*39:NROWS*40,1+NCOLS*39:NCOLS*40) = VAL%R
      ! E222 x R -> E222 (40, 1)
      RES(1+NROWS*39:NROWS*40,1+NCOLS*0:NCOLS*1) = VAL%E222
      ! E2 x E22 -> E222 (40, 11)
      RES(1+NROWS*39:NROWS*40,1+NCOLS*10:NCOLS*11) = VAL%E2
      ! E22 x E2 -> E222 (40, 3)
      RES(1+NROWS*39:NROWS*40,1+NCOLS*2:NCOLS*3) = VAL%E22
      ! R x E113 -> E113 (41, 41)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*40:NCOLS*41) = VAL%R
      ! E113 x R -> E113 (41, 1)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*0:NCOLS*1) = VAL%E113
      ! E1 x E13 -> E113 (41, 12)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*11:NCOLS*12) = VAL%E1
      ! E13 x E1 -> E113 (41, 2)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*1:NCOLS*2) = VAL%E13
      ! E3 x E11 -> E113 (41, 9)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*8:NCOLS*9) = VAL%E3
      ! E11 x E3 -> E113 (41, 4)
      RES(1+NROWS*40:NROWS*41,1+NCOLS*3:NCOLS*4) = VAL%E11
      ! R x E123 -> E123 (42, 42)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*41:NCOLS*42) = VAL%R
      ! E123 x R -> E123 (42, 1)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*0:NCOLS*1) = VAL%E123
      ! E1 x E23 -> E123 (42, 13)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*12:NCOLS*13) = VAL%E1
      ! E23 x E1 -> E123 (42, 2)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*1:NCOLS*2) = VAL%E23
      ! E2 x E13 -> E123 (42, 12)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*11:NCOLS*12) = VAL%E2
      ! E13 x E2 -> E123 (42, 3)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*2:NCOLS*3) = VAL%E13
      ! E3 x E12 -> E123 (42, 10)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*9:NCOLS*10) = VAL%E3
      ! E12 x E3 -> E123 (42, 4)
      RES(1+NROWS*41:NROWS*42,1+NCOLS*3:NCOLS*4) = VAL%E12
      ! R x E223 -> E223 (43, 43)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*42:NCOLS*43) = VAL%R
      ! E223 x R -> E223 (43, 1)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*0:NCOLS*1) = VAL%E223
      ! E2 x E23 -> E223 (43, 13)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*12:NCOLS*13) = VAL%E2
      ! E23 x E2 -> E223 (43, 3)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*2:NCOLS*3) = VAL%E23
      ! E3 x E22 -> E223 (43, 11)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*10:NCOLS*11) = VAL%E3
      ! E22 x E3 -> E223 (43, 4)
      RES(1+NROWS*42:NROWS*43,1+NCOLS*3:NCOLS*4) = VAL%E22
      ! R x E133 -> E133 (44, 44)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*43:NCOLS*44) = VAL%R
      ! E133 x R -> E133 (44, 1)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*0:NCOLS*1) = VAL%E133
      ! E1 x E33 -> E133 (44, 14)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*13:NCOLS*14) = VAL%E1
      ! E33 x E1 -> E133 (44, 2)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*1:NCOLS*2) = VAL%E33
      ! E3 x E13 -> E133 (44, 12)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*11:NCOLS*12) = VAL%E3
      ! E13 x E3 -> E133 (44, 4)
      RES(1+NROWS*43:NROWS*44,1+NCOLS*3:NCOLS*4) = VAL%E13
      ! R x E233 -> E233 (45, 45)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*44:NCOLS*45) = VAL%R
      ! E233 x R -> E233 (45, 1)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*0:NCOLS*1) = VAL%E233
      ! E2 x E33 -> E233 (45, 14)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*13:NCOLS*14) = VAL%E2
      ! E33 x E2 -> E233 (45, 3)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*2:NCOLS*3) = VAL%E33
      ! E3 x E23 -> E233 (45, 13)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*12:NCOLS*13) = VAL%E3
      ! E23 x E3 -> E233 (45, 4)
      RES(1+NROWS*44:NROWS*45,1+NCOLS*3:NCOLS*4) = VAL%E23
      ! R x E333 -> E333 (46, 46)
      RES(1+NROWS*45:NROWS*46,1+NCOLS*45:NCOLS*46) = VAL%R
      ! E333 x R -> E333 (46, 1)
      RES(1+NROWS*45:NROWS*46,1+NCOLS*0:NCOLS*1) = VAL%E333
      ! E3 x E33 -> E333 (46, 14)
      RES(1+NROWS*45:NROWS*46,1+NCOLS*13:NCOLS*14) = VAL%E3
      ! E33 x E3 -> E333 (46, 4)
      RES(1+NROWS*45:NROWS*46,1+NCOLS*3:NCOLS*4) = VAL%E33
      ! R x E114 -> E114 (47, 47)
      RES(1+NROWS*46:NROWS*47,1+NCOLS*46:NCOLS*47) = VAL%R
      ! E114 x R -> E114 (47, 1)
      RES(1+NROWS*46:NROWS*47,1+NCOLS*0:NCOLS*1) = VAL%E114
      ! E1 x E14 -> E114 (47, 15)
      RES(1+NROWS*46:NROWS*47,1+NCOLS*14:NCOLS*15) = VAL%E1
      ! E14 x E1 -> E114 (47, 2)
      RES(1+NROWS*46:NROWS*47,1+NCOLS*1:NCOLS*2) = VAL%E14
      ! E4 x E11 -> E114 (47, 9)
      RES(1+NROWS*46:NROWS*47,1+NCOLS*8:NCOLS*9) = VAL%E4
      ! E11 x E4 -> E114 (47, 5)
      RES(1+NROWS*46:NROWS*47,1+NCOLS*4:NCOLS*5) = VAL%E11
      ! R x E124 -> E124 (48, 48)
      RES(1+NROWS*47:NROWS*48,1+NCOLS*47:NCOLS*48) = VAL%R
      ! E124 x R -> E124 (48, 1)
      RES(1+NROWS*47:NROWS*48,1+NCOLS*0:NCOLS*1) = VAL%E124
      ! E1 x E24 -> E124 (48, 16)
      RES(1+NROWS*47:NROWS*48,1+NCOLS*15:NCOLS*16) = VAL%E1
      ! E24 x E1 -> E124 (48, 2)
      RES(1+NROWS*47:NROWS*48,1+NCOLS*1:NCOLS*2) = VAL%E24
      ! E2 x E14 -> E124 (48, 15)
      RES(1+NROWS*47:NROWS*48,1+NCOLS*14:NCOLS*15) = VAL%E2
      ! E14 x E2 -> E124 (48, 3)
      RES(1+NROWS*47:NROWS*48,1+NCOLS*2:NCOLS*3) = VAL%E14
      ! E4 x E12 -> E124 (48, 10)
      RES(1+NROWS*47:NROWS*48,1+NCOLS*9:NCOLS*10) = VAL%E4
      ! E12 x E4 -> E124 (48, 5)
      RES(1+NROWS*47:NROWS*48,1+NCOLS*4:NCOLS*5) = VAL%E12
      ! R x E224 -> E224 (49, 49)
      RES(1+NROWS*48:NROWS*49,1+NCOLS*48:NCOLS*49) = VAL%R
      ! E224 x R -> E224 (49, 1)
      RES(1+NROWS*48:NROWS*49,1+NCOLS*0:NCOLS*1) = VAL%E224
      ! E2 x E24 -> E224 (49, 16)
      RES(1+NROWS*48:NROWS*49,1+NCOLS*15:NCOLS*16) = VAL%E2
      ! E24 x E2 -> E224 (49, 3)
      RES(1+NROWS*48:NROWS*49,1+NCOLS*2:NCOLS*3) = VAL%E24
      ! E4 x E22 -> E224 (49, 11)
      RES(1+NROWS*48:NROWS*49,1+NCOLS*10:NCOLS*11) = VAL%E4
      ! E22 x E4 -> E224 (49, 5)
      RES(1+NROWS*48:NROWS*49,1+NCOLS*4:NCOLS*5) = VAL%E22
      ! R x E134 -> E134 (50, 50)
      RES(1+NROWS*49:NROWS*50,1+NCOLS*49:NCOLS*50) = VAL%R
      ! E134 x R -> E134 (50, 1)
      RES(1+NROWS*49:NROWS*50,1+NCOLS*0:NCOLS*1) = VAL%E134
      ! E1 x E34 -> E134 (50, 17)
      RES(1+NROWS*49:NROWS*50,1+NCOLS*16:NCOLS*17) = VAL%E1
      ! E34 x E1 -> E134 (50, 2)
      RES(1+NROWS*49:NROWS*50,1+NCOLS*1:NCOLS*2) = VAL%E34
      ! E3 x E14 -> E134 (50, 15)
      RES(1+NROWS*49:NROWS*50,1+NCOLS*14:NCOLS*15) = VAL%E3
      ! E14 x E3 -> E134 (50, 4)
      RES(1+NROWS*49:NROWS*50,1+NCOLS*3:NCOLS*4) = VAL%E14
      ! E4 x E13 -> E134 (50, 12)
      RES(1+NROWS*49:NROWS*50,1+NCOLS*11:NCOLS*12) = VAL%E4
      ! E13 x E4 -> E134 (50, 5)
      RES(1+NROWS*49:NROWS*50,1+NCOLS*4:NCOLS*5) = VAL%E13
      ! R x E234 -> E234 (51, 51)
      RES(1+NROWS*50:NROWS*51,1+NCOLS*50:NCOLS*51) = VAL%R
      ! E234 x R -> E234 (51, 1)
      RES(1+NROWS*50:NROWS*51,1+NCOLS*0:NCOLS*1) = VAL%E234
      ! E2 x E34 -> E234 (51, 17)
      RES(1+NROWS*50:NROWS*51,1+NCOLS*16:NCOLS*17) = VAL%E2
      ! E34 x E2 -> E234 (51, 3)
      RES(1+NROWS*50:NROWS*51,1+NCOLS*2:NCOLS*3) = VAL%E34
      ! E3 x E24 -> E234 (51, 16)
      RES(1+NROWS*50:NROWS*51,1+NCOLS*15:NCOLS*16) = VAL%E3
      ! E24 x E3 -> E234 (51, 4)
      RES(1+NROWS*50:NROWS*51,1+NCOLS*3:NCOLS*4) = VAL%E24
      ! E4 x E23 -> E234 (51, 13)
      RES(1+NROWS*50:NROWS*51,1+NCOLS*12:NCOLS*13) = VAL%E4
      ! E23 x E4 -> E234 (51, 5)
      RES(1+NROWS*50:NROWS*51,1+NCOLS*4:NCOLS*5) = VAL%E23
      ! R x E334 -> E334 (52, 52)
      RES(1+NROWS*51:NROWS*52,1+NCOLS*51:NCOLS*52) = VAL%R
      ! E334 x R -> E334 (52, 1)
      RES(1+NROWS*51:NROWS*52,1+NCOLS*0:NCOLS*1) = VAL%E334
      ! E3 x E34 -> E334 (52, 17)
      RES(1+NROWS*51:NROWS*52,1+NCOLS*16:NCOLS*17) = VAL%E3
      ! E34 x E3 -> E334 (52, 4)
      RES(1+NROWS*51:NROWS*52,1+NCOLS*3:NCOLS*4) = VAL%E34
      ! E4 x E33 -> E334 (52, 14)
      RES(1+NROWS*51:NROWS*52,1+NCOLS*13:NCOLS*14) = VAL%E4
      ! E33 x E4 -> E334 (52, 5)
      RES(1+NROWS*51:NROWS*52,1+NCOLS*4:NCOLS*5) = VAL%E33
      ! R x E144 -> E144 (53, 53)
      RES(1+NROWS*52:NROWS*53,1+NCOLS*52:NCOLS*53) = VAL%R
      ! E144 x R -> E144 (53, 1)
      RES(1+NROWS*52:NROWS*53,1+NCOLS*0:NCOLS*1) = VAL%E144
      ! E1 x E44 -> E144 (53, 18)
      RES(1+NROWS*52:NROWS*53,1+NCOLS*17:NCOLS*18) = VAL%E1
      ! E44 x E1 -> E144 (53, 2)
      RES(1+NROWS*52:NROWS*53,1+NCOLS*1:NCOLS*2) = VAL%E44
      ! E4 x E14 -> E144 (53, 15)
      RES(1+NROWS*52:NROWS*53,1+NCOLS*14:NCOLS*15) = VAL%E4
      ! E14 x E4 -> E144 (53, 5)
      RES(1+NROWS*52:NROWS*53,1+NCOLS*4:NCOLS*5) = VAL%E14
      ! R x E244 -> E244 (54, 54)
      RES(1+NROWS*53:NROWS*54,1+NCOLS*53:NCOLS*54) = VAL%R
      ! E244 x R -> E244 (54, 1)
      RES(1+NROWS*53:NROWS*54,1+NCOLS*0:NCOLS*1) = VAL%E244
      ! E2 x E44 -> E244 (54, 18)
      RES(1+NROWS*53:NROWS*54,1+NCOLS*17:NCOLS*18) = VAL%E2
      ! E44 x E2 -> E244 (54, 3)
      RES(1+NROWS*53:NROWS*54,1+NCOLS*2:NCOLS*3) = VAL%E44
      ! E4 x E24 -> E244 (54, 16)
      RES(1+NROWS*53:NROWS*54,1+NCOLS*15:NCOLS*16) = VAL%E4
      ! E24 x E4 -> E244 (54, 5)
      RES(1+NROWS*53:NROWS*54,1+NCOLS*4:NCOLS*5) = VAL%E24
      ! R x E344 -> E344 (55, 55)
      RES(1+NROWS*54:NROWS*55,1+NCOLS*54:NCOLS*55) = VAL%R
      ! E344 x R -> E344 (55, 1)
      RES(1+NROWS*54:NROWS*55,1+NCOLS*0:NCOLS*1) = VAL%E344
      ! E3 x E44 -> E344 (55, 18)
      RES(1+NROWS*54:NROWS*55,1+NCOLS*17:NCOLS*18) = VAL%E3
      ! E44 x E3 -> E344 (55, 4)
      RES(1+NROWS*54:NROWS*55,1+NCOLS*3:NCOLS*4) = VAL%E44
      ! E4 x E34 -> E344 (55, 17)
      RES(1+NROWS*54:NROWS*55,1+NCOLS*16:NCOLS*17) = VAL%E4
      ! E34 x E4 -> E344 (55, 5)
      RES(1+NROWS*54:NROWS*55,1+NCOLS*4:NCOLS*5) = VAL%E34
      ! R x E444 -> E444 (56, 56)
      RES(1+NROWS*55:NROWS*56,1+NCOLS*55:NCOLS*56) = VAL%R
      ! E444 x R -> E444 (56, 1)
      RES(1+NROWS*55:NROWS*56,1+NCOLS*0:NCOLS*1) = VAL%E444
      ! E4 x E44 -> E444 (56, 18)
      RES(1+NROWS*55:NROWS*56,1+NCOLS*17:NCOLS*18) = VAL%E4
      ! E44 x E4 -> E444 (56, 5)
      RES(1+NROWS*55:NROWS*56,1+NCOLS*4:NCOLS*5) = VAL%E44
      ! R x E115 -> E115 (57, 57)
      RES(1+NROWS*56:NROWS*57,1+NCOLS*56:NCOLS*57) = VAL%R
      ! E115 x R -> E115 (57, 1)
      RES(1+NROWS*56:NROWS*57,1+NCOLS*0:NCOLS*1) = VAL%E115
      ! E1 x E15 -> E115 (57, 19)
      RES(1+NROWS*56:NROWS*57,1+NCOLS*18:NCOLS*19) = VAL%E1
      ! E15 x E1 -> E115 (57, 2)
      RES(1+NROWS*56:NROWS*57,1+NCOLS*1:NCOLS*2) = VAL%E15
      ! E5 x E11 -> E115 (57, 9)
      RES(1+NROWS*56:NROWS*57,1+NCOLS*8:NCOLS*9) = VAL%E5
      ! E11 x E5 -> E115 (57, 6)
      RES(1+NROWS*56:NROWS*57,1+NCOLS*5:NCOLS*6) = VAL%E11
      ! R x E125 -> E125 (58, 58)
      RES(1+NROWS*57:NROWS*58,1+NCOLS*57:NCOLS*58) = VAL%R
      ! E125 x R -> E125 (58, 1)
      RES(1+NROWS*57:NROWS*58,1+NCOLS*0:NCOLS*1) = VAL%E125
      ! E1 x E25 -> E125 (58, 20)
      RES(1+NROWS*57:NROWS*58,1+NCOLS*19:NCOLS*20) = VAL%E1
      ! E25 x E1 -> E125 (58, 2)
      RES(1+NROWS*57:NROWS*58,1+NCOLS*1:NCOLS*2) = VAL%E25
      ! E2 x E15 -> E125 (58, 19)
      RES(1+NROWS*57:NROWS*58,1+NCOLS*18:NCOLS*19) = VAL%E2
      ! E15 x E2 -> E125 (58, 3)
      RES(1+NROWS*57:NROWS*58,1+NCOLS*2:NCOLS*3) = VAL%E15
      ! E5 x E12 -> E125 (58, 10)
      RES(1+NROWS*57:NROWS*58,1+NCOLS*9:NCOLS*10) = VAL%E5
      ! E12 x E5 -> E125 (58, 6)
      RES(1+NROWS*57:NROWS*58,1+NCOLS*5:NCOLS*6) = VAL%E12
      ! R x E225 -> E225 (59, 59)
      RES(1+NROWS*58:NROWS*59,1+NCOLS*58:NCOLS*59) = VAL%R
      ! E225 x R -> E225 (59, 1)
      RES(1+NROWS*58:NROWS*59,1+NCOLS*0:NCOLS*1) = VAL%E225
      ! E2 x E25 -> E225 (59, 20)
      RES(1+NROWS*58:NROWS*59,1+NCOLS*19:NCOLS*20) = VAL%E2
      ! E25 x E2 -> E225 (59, 3)
      RES(1+NROWS*58:NROWS*59,1+NCOLS*2:NCOLS*3) = VAL%E25
      ! E5 x E22 -> E225 (59, 11)
      RES(1+NROWS*58:NROWS*59,1+NCOLS*10:NCOLS*11) = VAL%E5
      ! E22 x E5 -> E225 (59, 6)
      RES(1+NROWS*58:NROWS*59,1+NCOLS*5:NCOLS*6) = VAL%E22
      ! R x E135 -> E135 (60, 60)
      RES(1+NROWS*59:NROWS*60,1+NCOLS*59:NCOLS*60) = VAL%R
      ! E135 x R -> E135 (60, 1)
      RES(1+NROWS*59:NROWS*60,1+NCOLS*0:NCOLS*1) = VAL%E135
      ! E1 x E35 -> E135 (60, 21)
      RES(1+NROWS*59:NROWS*60,1+NCOLS*20:NCOLS*21) = VAL%E1
      ! E35 x E1 -> E135 (60, 2)
      RES(1+NROWS*59:NROWS*60,1+NCOLS*1:NCOLS*2) = VAL%E35
      ! E3 x E15 -> E135 (60, 19)
      RES(1+NROWS*59:NROWS*60,1+NCOLS*18:NCOLS*19) = VAL%E3
      ! E15 x E3 -> E135 (60, 4)
      RES(1+NROWS*59:NROWS*60,1+NCOLS*3:NCOLS*4) = VAL%E15
      ! E5 x E13 -> E135 (60, 12)
      RES(1+NROWS*59:NROWS*60,1+NCOLS*11:NCOLS*12) = VAL%E5
      ! E13 x E5 -> E135 (60, 6)
      RES(1+NROWS*59:NROWS*60,1+NCOLS*5:NCOLS*6) = VAL%E13
      ! R x E235 -> E235 (61, 61)
      RES(1+NROWS*60:NROWS*61,1+NCOLS*60:NCOLS*61) = VAL%R
      ! E235 x R -> E235 (61, 1)
      RES(1+NROWS*60:NROWS*61,1+NCOLS*0:NCOLS*1) = VAL%E235
      ! E2 x E35 -> E235 (61, 21)
      RES(1+NROWS*60:NROWS*61,1+NCOLS*20:NCOLS*21) = VAL%E2
      ! E35 x E2 -> E235 (61, 3)
      RES(1+NROWS*60:NROWS*61,1+NCOLS*2:NCOLS*3) = VAL%E35
      ! E3 x E25 -> E235 (61, 20)
      RES(1+NROWS*60:NROWS*61,1+NCOLS*19:NCOLS*20) = VAL%E3
      ! E25 x E3 -> E235 (61, 4)
      RES(1+NROWS*60:NROWS*61,1+NCOLS*3:NCOLS*4) = VAL%E25
      ! E5 x E23 -> E235 (61, 13)
      RES(1+NROWS*60:NROWS*61,1+NCOLS*12:NCOLS*13) = VAL%E5
      ! E23 x E5 -> E235 (61, 6)
      RES(1+NROWS*60:NROWS*61,1+NCOLS*5:NCOLS*6) = VAL%E23
      ! R x E335 -> E335 (62, 62)
      RES(1+NROWS*61:NROWS*62,1+NCOLS*61:NCOLS*62) = VAL%R
      ! E335 x R -> E335 (62, 1)
      RES(1+NROWS*61:NROWS*62,1+NCOLS*0:NCOLS*1) = VAL%E335
      ! E3 x E35 -> E335 (62, 21)
      RES(1+NROWS*61:NROWS*62,1+NCOLS*20:NCOLS*21) = VAL%E3
      ! E35 x E3 -> E335 (62, 4)
      RES(1+NROWS*61:NROWS*62,1+NCOLS*3:NCOLS*4) = VAL%E35
      ! E5 x E33 -> E335 (62, 14)
      RES(1+NROWS*61:NROWS*62,1+NCOLS*13:NCOLS*14) = VAL%E5
      ! E33 x E5 -> E335 (62, 6)
      RES(1+NROWS*61:NROWS*62,1+NCOLS*5:NCOLS*6) = VAL%E33
      ! R x E145 -> E145 (63, 63)
      RES(1+NROWS*62:NROWS*63,1+NCOLS*62:NCOLS*63) = VAL%R
      ! E145 x R -> E145 (63, 1)
      RES(1+NROWS*62:NROWS*63,1+NCOLS*0:NCOLS*1) = VAL%E145
      ! E1 x E45 -> E145 (63, 22)
      RES(1+NROWS*62:NROWS*63,1+NCOLS*21:NCOLS*22) = VAL%E1
      ! E45 x E1 -> E145 (63, 2)
      RES(1+NROWS*62:NROWS*63,1+NCOLS*1:NCOLS*2) = VAL%E45
      ! E4 x E15 -> E145 (63, 19)
      RES(1+NROWS*62:NROWS*63,1+NCOLS*18:NCOLS*19) = VAL%E4
      ! E15 x E4 -> E145 (63, 5)
      RES(1+NROWS*62:NROWS*63,1+NCOLS*4:NCOLS*5) = VAL%E15
      ! E5 x E14 -> E145 (63, 15)
      RES(1+NROWS*62:NROWS*63,1+NCOLS*14:NCOLS*15) = VAL%E5
      ! E14 x E5 -> E145 (63, 6)
      RES(1+NROWS*62:NROWS*63,1+NCOLS*5:NCOLS*6) = VAL%E14
      ! R x E245 -> E245 (64, 64)
      RES(1+NROWS*63:NROWS*64,1+NCOLS*63:NCOLS*64) = VAL%R
      ! E245 x R -> E245 (64, 1)
      RES(1+NROWS*63:NROWS*64,1+NCOLS*0:NCOLS*1) = VAL%E245
      ! E2 x E45 -> E245 (64, 22)
      RES(1+NROWS*63:NROWS*64,1+NCOLS*21:NCOLS*22) = VAL%E2
      ! E45 x E2 -> E245 (64, 3)
      RES(1+NROWS*63:NROWS*64,1+NCOLS*2:NCOLS*3) = VAL%E45
      ! E4 x E25 -> E245 (64, 20)
      RES(1+NROWS*63:NROWS*64,1+NCOLS*19:NCOLS*20) = VAL%E4
      ! E25 x E4 -> E245 (64, 5)
      RES(1+NROWS*63:NROWS*64,1+NCOLS*4:NCOLS*5) = VAL%E25
      ! E5 x E24 -> E245 (64, 16)
      RES(1+NROWS*63:NROWS*64,1+NCOLS*15:NCOLS*16) = VAL%E5
      ! E24 x E5 -> E245 (64, 6)
      RES(1+NROWS*63:NROWS*64,1+NCOLS*5:NCOLS*6) = VAL%E24
      ! R x E345 -> E345 (65, 65)
      RES(1+NROWS*64:NROWS*65,1+NCOLS*64:NCOLS*65) = VAL%R
      ! E345 x R -> E345 (65, 1)
      RES(1+NROWS*64:NROWS*65,1+NCOLS*0:NCOLS*1) = VAL%E345
      ! E3 x E45 -> E345 (65, 22)
      RES(1+NROWS*64:NROWS*65,1+NCOLS*21:NCOLS*22) = VAL%E3
      ! E45 x E3 -> E345 (65, 4)
      RES(1+NROWS*64:NROWS*65,1+NCOLS*3:NCOLS*4) = VAL%E45
      ! E4 x E35 -> E345 (65, 21)
      RES(1+NROWS*64:NROWS*65,1+NCOLS*20:NCOLS*21) = VAL%E4
      ! E35 x E4 -> E345 (65, 5)
      RES(1+NROWS*64:NROWS*65,1+NCOLS*4:NCOLS*5) = VAL%E35
      ! E5 x E34 -> E345 (65, 17)
      RES(1+NROWS*64:NROWS*65,1+NCOLS*16:NCOLS*17) = VAL%E5
      ! E34 x E5 -> E345 (65, 6)
      RES(1+NROWS*64:NROWS*65,1+NCOLS*5:NCOLS*6) = VAL%E34
      ! R x E445 -> E445 (66, 66)
      RES(1+NROWS*65:NROWS*66,1+NCOLS*65:NCOLS*66) = VAL%R
      ! E445 x R -> E445 (66, 1)
      RES(1+NROWS*65:NROWS*66,1+NCOLS*0:NCOLS*1) = VAL%E445
      ! E4 x E45 -> E445 (66, 22)
      RES(1+NROWS*65:NROWS*66,1+NCOLS*21:NCOLS*22) = VAL%E4
      ! E45 x E4 -> E445 (66, 5)
      RES(1+NROWS*65:NROWS*66,1+NCOLS*4:NCOLS*5) = VAL%E45
      ! E5 x E44 -> E445 (66, 18)
      RES(1+NROWS*65:NROWS*66,1+NCOLS*17:NCOLS*18) = VAL%E5
      ! E44 x E5 -> E445 (66, 6)
      RES(1+NROWS*65:NROWS*66,1+NCOLS*5:NCOLS*6) = VAL%E44
      ! R x E155 -> E155 (67, 67)
      RES(1+NROWS*66:NROWS*67,1+NCOLS*66:NCOLS*67) = VAL%R
      ! E155 x R -> E155 (67, 1)
      RES(1+NROWS*66:NROWS*67,1+NCOLS*0:NCOLS*1) = VAL%E155
      ! E1 x E55 -> E155 (67, 23)
      RES(1+NROWS*66:NROWS*67,1+NCOLS*22:NCOLS*23) = VAL%E1
      ! E55 x E1 -> E155 (67, 2)
      RES(1+NROWS*66:NROWS*67,1+NCOLS*1:NCOLS*2) = VAL%E55
      ! E5 x E15 -> E155 (67, 19)
      RES(1+NROWS*66:NROWS*67,1+NCOLS*18:NCOLS*19) = VAL%E5
      ! E15 x E5 -> E155 (67, 6)
      RES(1+NROWS*66:NROWS*67,1+NCOLS*5:NCOLS*6) = VAL%E15
      ! R x E255 -> E255 (68, 68)
      RES(1+NROWS*67:NROWS*68,1+NCOLS*67:NCOLS*68) = VAL%R
      ! E255 x R -> E255 (68, 1)
      RES(1+NROWS*67:NROWS*68,1+NCOLS*0:NCOLS*1) = VAL%E255
      ! E2 x E55 -> E255 (68, 23)
      RES(1+NROWS*67:NROWS*68,1+NCOLS*22:NCOLS*23) = VAL%E2
      ! E55 x E2 -> E255 (68, 3)
      RES(1+NROWS*67:NROWS*68,1+NCOLS*2:NCOLS*3) = VAL%E55
      ! E5 x E25 -> E255 (68, 20)
      RES(1+NROWS*67:NROWS*68,1+NCOLS*19:NCOLS*20) = VAL%E5
      ! E25 x E5 -> E255 (68, 6)
      RES(1+NROWS*67:NROWS*68,1+NCOLS*5:NCOLS*6) = VAL%E25
      ! R x E355 -> E355 (69, 69)
      RES(1+NROWS*68:NROWS*69,1+NCOLS*68:NCOLS*69) = VAL%R
      ! E355 x R -> E355 (69, 1)
      RES(1+NROWS*68:NROWS*69,1+NCOLS*0:NCOLS*1) = VAL%E355
      ! E3 x E55 -> E355 (69, 23)
      RES(1+NROWS*68:NROWS*69,1+NCOLS*22:NCOLS*23) = VAL%E3
      ! E55 x E3 -> E355 (69, 4)
      RES(1+NROWS*68:NROWS*69,1+NCOLS*3:NCOLS*4) = VAL%E55
      ! E5 x E35 -> E355 (69, 21)
      RES(1+NROWS*68:NROWS*69,1+NCOLS*20:NCOLS*21) = VAL%E5
      ! E35 x E5 -> E355 (69, 6)
      RES(1+NROWS*68:NROWS*69,1+NCOLS*5:NCOLS*6) = VAL%E35
      ! R x E455 -> E455 (70, 70)
      RES(1+NROWS*69:NROWS*70,1+NCOLS*69:NCOLS*70) = VAL%R
      ! E455 x R -> E455 (70, 1)
      RES(1+NROWS*69:NROWS*70,1+NCOLS*0:NCOLS*1) = VAL%E455
      ! E4 x E55 -> E455 (70, 23)
      RES(1+NROWS*69:NROWS*70,1+NCOLS*22:NCOLS*23) = VAL%E4
      ! E55 x E4 -> E455 (70, 5)
      RES(1+NROWS*69:NROWS*70,1+NCOLS*4:NCOLS*5) = VAL%E55
      ! E5 x E45 -> E455 (70, 22)
      RES(1+NROWS*69:NROWS*70,1+NCOLS*21:NCOLS*22) = VAL%E5
      ! E45 x E5 -> E455 (70, 6)
      RES(1+NROWS*69:NROWS*70,1+NCOLS*5:NCOLS*6) = VAL%E45
      ! R x E555 -> E555 (71, 71)
      RES(1+NROWS*70:NROWS*71,1+NCOLS*70:NCOLS*71) = VAL%R
      ! E555 x R -> E555 (71, 1)
      RES(1+NROWS*70:NROWS*71,1+NCOLS*0:NCOLS*1) = VAL%E555
      ! E5 x E55 -> E555 (71, 23)
      RES(1+NROWS*70:NROWS*71,1+NCOLS*22:NCOLS*23) = VAL%E5
      ! E55 x E5 -> E555 (71, 6)
      RES(1+NROWS*70:NROWS*71,1+NCOLS*5:NCOLS*6) = VAL%E55
      ! R x E116 -> E116 (72, 72)
      RES(1+NROWS*71:NROWS*72,1+NCOLS*71:NCOLS*72) = VAL%R
      ! E116 x R -> E116 (72, 1)
      RES(1+NROWS*71:NROWS*72,1+NCOLS*0:NCOLS*1) = VAL%E116
      ! E1 x E16 -> E116 (72, 24)
      RES(1+NROWS*71:NROWS*72,1+NCOLS*23:NCOLS*24) = VAL%E1
      ! E16 x E1 -> E116 (72, 2)
      RES(1+NROWS*71:NROWS*72,1+NCOLS*1:NCOLS*2) = VAL%E16
      ! E6 x E11 -> E116 (72, 9)
      RES(1+NROWS*71:NROWS*72,1+NCOLS*8:NCOLS*9) = VAL%E6
      ! E11 x E6 -> E116 (72, 7)
      RES(1+NROWS*71:NROWS*72,1+NCOLS*6:NCOLS*7) = VAL%E11
      ! R x E126 -> E126 (73, 73)
      RES(1+NROWS*72:NROWS*73,1+NCOLS*72:NCOLS*73) = VAL%R
      ! E126 x R -> E126 (73, 1)
      RES(1+NROWS*72:NROWS*73,1+NCOLS*0:NCOLS*1) = VAL%E126
      ! E1 x E26 -> E126 (73, 25)
      RES(1+NROWS*72:NROWS*73,1+NCOLS*24:NCOLS*25) = VAL%E1
      ! E26 x E1 -> E126 (73, 2)
      RES(1+NROWS*72:NROWS*73,1+NCOLS*1:NCOLS*2) = VAL%E26
      ! E2 x E16 -> E126 (73, 24)
      RES(1+NROWS*72:NROWS*73,1+NCOLS*23:NCOLS*24) = VAL%E2
      ! E16 x E2 -> E126 (73, 3)
      RES(1+NROWS*72:NROWS*73,1+NCOLS*2:NCOLS*3) = VAL%E16
      ! E6 x E12 -> E126 (73, 10)
      RES(1+NROWS*72:NROWS*73,1+NCOLS*9:NCOLS*10) = VAL%E6
      ! E12 x E6 -> E126 (73, 7)
      RES(1+NROWS*72:NROWS*73,1+NCOLS*6:NCOLS*7) = VAL%E12
      ! R x E226 -> E226 (74, 74)
      RES(1+NROWS*73:NROWS*74,1+NCOLS*73:NCOLS*74) = VAL%R
      ! E226 x R -> E226 (74, 1)
      RES(1+NROWS*73:NROWS*74,1+NCOLS*0:NCOLS*1) = VAL%E226
      ! E2 x E26 -> E226 (74, 25)
      RES(1+NROWS*73:NROWS*74,1+NCOLS*24:NCOLS*25) = VAL%E2
      ! E26 x E2 -> E226 (74, 3)
      RES(1+NROWS*73:NROWS*74,1+NCOLS*2:NCOLS*3) = VAL%E26
      ! E6 x E22 -> E226 (74, 11)
      RES(1+NROWS*73:NROWS*74,1+NCOLS*10:NCOLS*11) = VAL%E6
      ! E22 x E6 -> E226 (74, 7)
      RES(1+NROWS*73:NROWS*74,1+NCOLS*6:NCOLS*7) = VAL%E22
      ! R x E136 -> E136 (75, 75)
      RES(1+NROWS*74:NROWS*75,1+NCOLS*74:NCOLS*75) = VAL%R
      ! E136 x R -> E136 (75, 1)
      RES(1+NROWS*74:NROWS*75,1+NCOLS*0:NCOLS*1) = VAL%E136
      ! E1 x E36 -> E136 (75, 26)
      RES(1+NROWS*74:NROWS*75,1+NCOLS*25:NCOLS*26) = VAL%E1
      ! E36 x E1 -> E136 (75, 2)
      RES(1+NROWS*74:NROWS*75,1+NCOLS*1:NCOLS*2) = VAL%E36
      ! E3 x E16 -> E136 (75, 24)
      RES(1+NROWS*74:NROWS*75,1+NCOLS*23:NCOLS*24) = VAL%E3
      ! E16 x E3 -> E136 (75, 4)
      RES(1+NROWS*74:NROWS*75,1+NCOLS*3:NCOLS*4) = VAL%E16
      ! E6 x E13 -> E136 (75, 12)
      RES(1+NROWS*74:NROWS*75,1+NCOLS*11:NCOLS*12) = VAL%E6
      ! E13 x E6 -> E136 (75, 7)
      RES(1+NROWS*74:NROWS*75,1+NCOLS*6:NCOLS*7) = VAL%E13
      ! R x E236 -> E236 (76, 76)
      RES(1+NROWS*75:NROWS*76,1+NCOLS*75:NCOLS*76) = VAL%R
      ! E236 x R -> E236 (76, 1)
      RES(1+NROWS*75:NROWS*76,1+NCOLS*0:NCOLS*1) = VAL%E236
      ! E2 x E36 -> E236 (76, 26)
      RES(1+NROWS*75:NROWS*76,1+NCOLS*25:NCOLS*26) = VAL%E2
      ! E36 x E2 -> E236 (76, 3)
      RES(1+NROWS*75:NROWS*76,1+NCOLS*2:NCOLS*3) = VAL%E36
      ! E3 x E26 -> E236 (76, 25)
      RES(1+NROWS*75:NROWS*76,1+NCOLS*24:NCOLS*25) = VAL%E3
      ! E26 x E3 -> E236 (76, 4)
      RES(1+NROWS*75:NROWS*76,1+NCOLS*3:NCOLS*4) = VAL%E26
      ! E6 x E23 -> E236 (76, 13)
      RES(1+NROWS*75:NROWS*76,1+NCOLS*12:NCOLS*13) = VAL%E6
      ! E23 x E6 -> E236 (76, 7)
      RES(1+NROWS*75:NROWS*76,1+NCOLS*6:NCOLS*7) = VAL%E23
      ! R x E336 -> E336 (77, 77)
      RES(1+NROWS*76:NROWS*77,1+NCOLS*76:NCOLS*77) = VAL%R
      ! E336 x R -> E336 (77, 1)
      RES(1+NROWS*76:NROWS*77,1+NCOLS*0:NCOLS*1) = VAL%E336
      ! E3 x E36 -> E336 (77, 26)
      RES(1+NROWS*76:NROWS*77,1+NCOLS*25:NCOLS*26) = VAL%E3
      ! E36 x E3 -> E336 (77, 4)
      RES(1+NROWS*76:NROWS*77,1+NCOLS*3:NCOLS*4) = VAL%E36
      ! E6 x E33 -> E336 (77, 14)
      RES(1+NROWS*76:NROWS*77,1+NCOLS*13:NCOLS*14) = VAL%E6
      ! E33 x E6 -> E336 (77, 7)
      RES(1+NROWS*76:NROWS*77,1+NCOLS*6:NCOLS*7) = VAL%E33
      ! R x E146 -> E146 (78, 78)
      RES(1+NROWS*77:NROWS*78,1+NCOLS*77:NCOLS*78) = VAL%R
      ! E146 x R -> E146 (78, 1)
      RES(1+NROWS*77:NROWS*78,1+NCOLS*0:NCOLS*1) = VAL%E146
      ! E1 x E46 -> E146 (78, 27)
      RES(1+NROWS*77:NROWS*78,1+NCOLS*26:NCOLS*27) = VAL%E1
      ! E46 x E1 -> E146 (78, 2)
      RES(1+NROWS*77:NROWS*78,1+NCOLS*1:NCOLS*2) = VAL%E46
      ! E4 x E16 -> E146 (78, 24)
      RES(1+NROWS*77:NROWS*78,1+NCOLS*23:NCOLS*24) = VAL%E4
      ! E16 x E4 -> E146 (78, 5)
      RES(1+NROWS*77:NROWS*78,1+NCOLS*4:NCOLS*5) = VAL%E16
      ! E6 x E14 -> E146 (78, 15)
      RES(1+NROWS*77:NROWS*78,1+NCOLS*14:NCOLS*15) = VAL%E6
      ! E14 x E6 -> E146 (78, 7)
      RES(1+NROWS*77:NROWS*78,1+NCOLS*6:NCOLS*7) = VAL%E14
      ! R x E246 -> E246 (79, 79)
      RES(1+NROWS*78:NROWS*79,1+NCOLS*78:NCOLS*79) = VAL%R
      ! E246 x R -> E246 (79, 1)
      RES(1+NROWS*78:NROWS*79,1+NCOLS*0:NCOLS*1) = VAL%E246
      ! E2 x E46 -> E246 (79, 27)
      RES(1+NROWS*78:NROWS*79,1+NCOLS*26:NCOLS*27) = VAL%E2
      ! E46 x E2 -> E246 (79, 3)
      RES(1+NROWS*78:NROWS*79,1+NCOLS*2:NCOLS*3) = VAL%E46
      ! E4 x E26 -> E246 (79, 25)
      RES(1+NROWS*78:NROWS*79,1+NCOLS*24:NCOLS*25) = VAL%E4
      ! E26 x E4 -> E246 (79, 5)
      RES(1+NROWS*78:NROWS*79,1+NCOLS*4:NCOLS*5) = VAL%E26
      ! E6 x E24 -> E246 (79, 16)
      RES(1+NROWS*78:NROWS*79,1+NCOLS*15:NCOLS*16) = VAL%E6
      ! E24 x E6 -> E246 (79, 7)
      RES(1+NROWS*78:NROWS*79,1+NCOLS*6:NCOLS*7) = VAL%E24
      ! R x E346 -> E346 (80, 80)
      RES(1+NROWS*79:NROWS*80,1+NCOLS*79:NCOLS*80) = VAL%R
      ! E346 x R -> E346 (80, 1)
      RES(1+NROWS*79:NROWS*80,1+NCOLS*0:NCOLS*1) = VAL%E346
      ! E3 x E46 -> E346 (80, 27)
      RES(1+NROWS*79:NROWS*80,1+NCOLS*26:NCOLS*27) = VAL%E3
      ! E46 x E3 -> E346 (80, 4)
      RES(1+NROWS*79:NROWS*80,1+NCOLS*3:NCOLS*4) = VAL%E46
      ! E4 x E36 -> E346 (80, 26)
      RES(1+NROWS*79:NROWS*80,1+NCOLS*25:NCOLS*26) = VAL%E4
      ! E36 x E4 -> E346 (80, 5)
      RES(1+NROWS*79:NROWS*80,1+NCOLS*4:NCOLS*5) = VAL%E36
      ! E6 x E34 -> E346 (80, 17)
      RES(1+NROWS*79:NROWS*80,1+NCOLS*16:NCOLS*17) = VAL%E6
      ! E34 x E6 -> E346 (80, 7)
      RES(1+NROWS*79:NROWS*80,1+NCOLS*6:NCOLS*7) = VAL%E34
      ! R x E446 -> E446 (81, 81)
      RES(1+NROWS*80:NROWS*81,1+NCOLS*80:NCOLS*81) = VAL%R
      ! E446 x R -> E446 (81, 1)
      RES(1+NROWS*80:NROWS*81,1+NCOLS*0:NCOLS*1) = VAL%E446
      ! E4 x E46 -> E446 (81, 27)
      RES(1+NROWS*80:NROWS*81,1+NCOLS*26:NCOLS*27) = VAL%E4
      ! E46 x E4 -> E446 (81, 5)
      RES(1+NROWS*80:NROWS*81,1+NCOLS*4:NCOLS*5) = VAL%E46
      ! E6 x E44 -> E446 (81, 18)
      RES(1+NROWS*80:NROWS*81,1+NCOLS*17:NCOLS*18) = VAL%E6
      ! E44 x E6 -> E446 (81, 7)
      RES(1+NROWS*80:NROWS*81,1+NCOLS*6:NCOLS*7) = VAL%E44
      ! R x E156 -> E156 (82, 82)
      RES(1+NROWS*81:NROWS*82,1+NCOLS*81:NCOLS*82) = VAL%R
      ! E156 x R -> E156 (82, 1)
      RES(1+NROWS*81:NROWS*82,1+NCOLS*0:NCOLS*1) = VAL%E156
      ! E1 x E56 -> E156 (82, 28)
      RES(1+NROWS*81:NROWS*82,1+NCOLS*27:NCOLS*28) = VAL%E1
      ! E56 x E1 -> E156 (82, 2)
      RES(1+NROWS*81:NROWS*82,1+NCOLS*1:NCOLS*2) = VAL%E56
      ! E5 x E16 -> E156 (82, 24)
      RES(1+NROWS*81:NROWS*82,1+NCOLS*23:NCOLS*24) = VAL%E5
      ! E16 x E5 -> E156 (82, 6)
      RES(1+NROWS*81:NROWS*82,1+NCOLS*5:NCOLS*6) = VAL%E16
      ! E6 x E15 -> E156 (82, 19)
      RES(1+NROWS*81:NROWS*82,1+NCOLS*18:NCOLS*19) = VAL%E6
      ! E15 x E6 -> E156 (82, 7)
      RES(1+NROWS*81:NROWS*82,1+NCOLS*6:NCOLS*7) = VAL%E15
      ! R x E256 -> E256 (83, 83)
      RES(1+NROWS*82:NROWS*83,1+NCOLS*82:NCOLS*83) = VAL%R
      ! E256 x R -> E256 (83, 1)
      RES(1+NROWS*82:NROWS*83,1+NCOLS*0:NCOLS*1) = VAL%E256
      ! E2 x E56 -> E256 (83, 28)
      RES(1+NROWS*82:NROWS*83,1+NCOLS*27:NCOLS*28) = VAL%E2
      ! E56 x E2 -> E256 (83, 3)
      RES(1+NROWS*82:NROWS*83,1+NCOLS*2:NCOLS*3) = VAL%E56
      ! E5 x E26 -> E256 (83, 25)
      RES(1+NROWS*82:NROWS*83,1+NCOLS*24:NCOLS*25) = VAL%E5
      ! E26 x E5 -> E256 (83, 6)
      RES(1+NROWS*82:NROWS*83,1+NCOLS*5:NCOLS*6) = VAL%E26
      ! E6 x E25 -> E256 (83, 20)
      RES(1+NROWS*82:NROWS*83,1+NCOLS*19:NCOLS*20) = VAL%E6
      ! E25 x E6 -> E256 (83, 7)
      RES(1+NROWS*82:NROWS*83,1+NCOLS*6:NCOLS*7) = VAL%E25
      ! R x E356 -> E356 (84, 84)
      RES(1+NROWS*83:NROWS*84,1+NCOLS*83:NCOLS*84) = VAL%R
      ! E356 x R -> E356 (84, 1)
      RES(1+NROWS*83:NROWS*84,1+NCOLS*0:NCOLS*1) = VAL%E356
      ! E3 x E56 -> E356 (84, 28)
      RES(1+NROWS*83:NROWS*84,1+NCOLS*27:NCOLS*28) = VAL%E3
      ! E56 x E3 -> E356 (84, 4)
      RES(1+NROWS*83:NROWS*84,1+NCOLS*3:NCOLS*4) = VAL%E56
      ! E5 x E36 -> E356 (84, 26)
      RES(1+NROWS*83:NROWS*84,1+NCOLS*25:NCOLS*26) = VAL%E5
      ! E36 x E5 -> E356 (84, 6)
      RES(1+NROWS*83:NROWS*84,1+NCOLS*5:NCOLS*6) = VAL%E36
      ! E6 x E35 -> E356 (84, 21)
      RES(1+NROWS*83:NROWS*84,1+NCOLS*20:NCOLS*21) = VAL%E6
      ! E35 x E6 -> E356 (84, 7)
      RES(1+NROWS*83:NROWS*84,1+NCOLS*6:NCOLS*7) = VAL%E35
      ! R x E456 -> E456 (85, 85)
      RES(1+NROWS*84:NROWS*85,1+NCOLS*84:NCOLS*85) = VAL%R
      ! E456 x R -> E456 (85, 1)
      RES(1+NROWS*84:NROWS*85,1+NCOLS*0:NCOLS*1) = VAL%E456
      ! E4 x E56 -> E456 (85, 28)
      RES(1+NROWS*84:NROWS*85,1+NCOLS*27:NCOLS*28) = VAL%E4
      ! E56 x E4 -> E456 (85, 5)
      RES(1+NROWS*84:NROWS*85,1+NCOLS*4:NCOLS*5) = VAL%E56
      ! E5 x E46 -> E456 (85, 27)
      RES(1+NROWS*84:NROWS*85,1+NCOLS*26:NCOLS*27) = VAL%E5
      ! E46 x E5 -> E456 (85, 6)
      RES(1+NROWS*84:NROWS*85,1+NCOLS*5:NCOLS*6) = VAL%E46
      ! E6 x E45 -> E456 (85, 22)
      RES(1+NROWS*84:NROWS*85,1+NCOLS*21:NCOLS*22) = VAL%E6
      ! E45 x E6 -> E456 (85, 7)
      RES(1+NROWS*84:NROWS*85,1+NCOLS*6:NCOLS*7) = VAL%E45
      ! R x E556 -> E556 (86, 86)
      RES(1+NROWS*85:NROWS*86,1+NCOLS*85:NCOLS*86) = VAL%R
      ! E556 x R -> E556 (86, 1)
      RES(1+NROWS*85:NROWS*86,1+NCOLS*0:NCOLS*1) = VAL%E556
      ! E5 x E56 -> E556 (86, 28)
      RES(1+NROWS*85:NROWS*86,1+NCOLS*27:NCOLS*28) = VAL%E5
      ! E56 x E5 -> E556 (86, 6)
      RES(1+NROWS*85:NROWS*86,1+NCOLS*5:NCOLS*6) = VAL%E56
      ! E6 x E55 -> E556 (86, 23)
      RES(1+NROWS*85:NROWS*86,1+NCOLS*22:NCOLS*23) = VAL%E6
      ! E55 x E6 -> E556 (86, 7)
      RES(1+NROWS*85:NROWS*86,1+NCOLS*6:NCOLS*7) = VAL%E55
      ! R x E166 -> E166 (87, 87)
      RES(1+NROWS*86:NROWS*87,1+NCOLS*86:NCOLS*87) = VAL%R
      ! E166 x R -> E166 (87, 1)
      RES(1+NROWS*86:NROWS*87,1+NCOLS*0:NCOLS*1) = VAL%E166
      ! E1 x E66 -> E166 (87, 29)
      RES(1+NROWS*86:NROWS*87,1+NCOLS*28:NCOLS*29) = VAL%E1
      ! E66 x E1 -> E166 (87, 2)
      RES(1+NROWS*86:NROWS*87,1+NCOLS*1:NCOLS*2) = VAL%E66
      ! E6 x E16 -> E166 (87, 24)
      RES(1+NROWS*86:NROWS*87,1+NCOLS*23:NCOLS*24) = VAL%E6
      ! E16 x E6 -> E166 (87, 7)
      RES(1+NROWS*86:NROWS*87,1+NCOLS*6:NCOLS*7) = VAL%E16
      ! R x E266 -> E266 (88, 88)
      RES(1+NROWS*87:NROWS*88,1+NCOLS*87:NCOLS*88) = VAL%R
      ! E266 x R -> E266 (88, 1)
      RES(1+NROWS*87:NROWS*88,1+NCOLS*0:NCOLS*1) = VAL%E266
      ! E2 x E66 -> E266 (88, 29)
      RES(1+NROWS*87:NROWS*88,1+NCOLS*28:NCOLS*29) = VAL%E2
      ! E66 x E2 -> E266 (88, 3)
      RES(1+NROWS*87:NROWS*88,1+NCOLS*2:NCOLS*3) = VAL%E66
      ! E6 x E26 -> E266 (88, 25)
      RES(1+NROWS*87:NROWS*88,1+NCOLS*24:NCOLS*25) = VAL%E6
      ! E26 x E6 -> E266 (88, 7)
      RES(1+NROWS*87:NROWS*88,1+NCOLS*6:NCOLS*7) = VAL%E26
      ! R x E366 -> E366 (89, 89)
      RES(1+NROWS*88:NROWS*89,1+NCOLS*88:NCOLS*89) = VAL%R
      ! E366 x R -> E366 (89, 1)
      RES(1+NROWS*88:NROWS*89,1+NCOLS*0:NCOLS*1) = VAL%E366
      ! E3 x E66 -> E366 (89, 29)
      RES(1+NROWS*88:NROWS*89,1+NCOLS*28:NCOLS*29) = VAL%E3
      ! E66 x E3 -> E366 (89, 4)
      RES(1+NROWS*88:NROWS*89,1+NCOLS*3:NCOLS*4) = VAL%E66
      ! E6 x E36 -> E366 (89, 26)
      RES(1+NROWS*88:NROWS*89,1+NCOLS*25:NCOLS*26) = VAL%E6
      ! E36 x E6 -> E366 (89, 7)
      RES(1+NROWS*88:NROWS*89,1+NCOLS*6:NCOLS*7) = VAL%E36
      ! R x E466 -> E466 (90, 90)
      RES(1+NROWS*89:NROWS*90,1+NCOLS*89:NCOLS*90) = VAL%R
      ! E466 x R -> E466 (90, 1)
      RES(1+NROWS*89:NROWS*90,1+NCOLS*0:NCOLS*1) = VAL%E466
      ! E4 x E66 -> E466 (90, 29)
      RES(1+NROWS*89:NROWS*90,1+NCOLS*28:NCOLS*29) = VAL%E4
      ! E66 x E4 -> E466 (90, 5)
      RES(1+NROWS*89:NROWS*90,1+NCOLS*4:NCOLS*5) = VAL%E66
      ! E6 x E46 -> E466 (90, 27)
      RES(1+NROWS*89:NROWS*90,1+NCOLS*26:NCOLS*27) = VAL%E6
      ! E46 x E6 -> E466 (90, 7)
      RES(1+NROWS*89:NROWS*90,1+NCOLS*6:NCOLS*7) = VAL%E46
      ! R x E566 -> E566 (91, 91)
      RES(1+NROWS*90:NROWS*91,1+NCOLS*90:NCOLS*91) = VAL%R
      ! E566 x R -> E566 (91, 1)
      RES(1+NROWS*90:NROWS*91,1+NCOLS*0:NCOLS*1) = VAL%E566
      ! E5 x E66 -> E566 (91, 29)
      RES(1+NROWS*90:NROWS*91,1+NCOLS*28:NCOLS*29) = VAL%E5
      ! E66 x E5 -> E566 (91, 6)
      RES(1+NROWS*90:NROWS*91,1+NCOLS*5:NCOLS*6) = VAL%E66
      ! E6 x E56 -> E566 (91, 28)
      RES(1+NROWS*90:NROWS*91,1+NCOLS*27:NCOLS*28) = VAL%E6
      ! E56 x E6 -> E566 (91, 7)
      RES(1+NROWS*90:NROWS*91,1+NCOLS*6:NCOLS*7) = VAL%E56
      ! R x E666 -> E666 (92, 92)
      RES(1+NROWS*91:NROWS*92,1+NCOLS*91:NCOLS*92) = VAL%R
      ! E666 x R -> E666 (92, 1)
      RES(1+NROWS*91:NROWS*92,1+NCOLS*0:NCOLS*1) = VAL%E666
      ! E6 x E66 -> E666 (92, 29)
      RES(1+NROWS*91:NROWS*92,1+NCOLS*28:NCOLS*29) = VAL%E6
      ! E66 x E6 -> E666 (92, 7)
      RES(1+NROWS*91:NROWS*92,1+NCOLS*6:NCOLS*7) = VAL%E66
      ! R x E117 -> E117 (93, 93)
      RES(1+NROWS*92:NROWS*93,1+NCOLS*92:NCOLS*93) = VAL%R
      ! E117 x R -> E117 (93, 1)
      RES(1+NROWS*92:NROWS*93,1+NCOLS*0:NCOLS*1) = VAL%E117
      ! E1 x E17 -> E117 (93, 30)
      RES(1+NROWS*92:NROWS*93,1+NCOLS*29:NCOLS*30) = VAL%E1
      ! E17 x E1 -> E117 (93, 2)
      RES(1+NROWS*92:NROWS*93,1+NCOLS*1:NCOLS*2) = VAL%E17
      ! E7 x E11 -> E117 (93, 9)
      RES(1+NROWS*92:NROWS*93,1+NCOLS*8:NCOLS*9) = VAL%E7
      ! E11 x E7 -> E117 (93, 8)
      RES(1+NROWS*92:NROWS*93,1+NCOLS*7:NCOLS*8) = VAL%E11
      ! R x E127 -> E127 (94, 94)
      RES(1+NROWS*93:NROWS*94,1+NCOLS*93:NCOLS*94) = VAL%R
      ! E127 x R -> E127 (94, 1)
      RES(1+NROWS*93:NROWS*94,1+NCOLS*0:NCOLS*1) = VAL%E127
      ! E1 x E27 -> E127 (94, 31)
      RES(1+NROWS*93:NROWS*94,1+NCOLS*30:NCOLS*31) = VAL%E1
      ! E27 x E1 -> E127 (94, 2)
      RES(1+NROWS*93:NROWS*94,1+NCOLS*1:NCOLS*2) = VAL%E27
      ! E2 x E17 -> E127 (94, 30)
      RES(1+NROWS*93:NROWS*94,1+NCOLS*29:NCOLS*30) = VAL%E2
      ! E17 x E2 -> E127 (94, 3)
      RES(1+NROWS*93:NROWS*94,1+NCOLS*2:NCOLS*3) = VAL%E17
      ! E7 x E12 -> E127 (94, 10)
      RES(1+NROWS*93:NROWS*94,1+NCOLS*9:NCOLS*10) = VAL%E7
      ! E12 x E7 -> E127 (94, 8)
      RES(1+NROWS*93:NROWS*94,1+NCOLS*7:NCOLS*8) = VAL%E12
      ! R x E227 -> E227 (95, 95)
      RES(1+NROWS*94:NROWS*95,1+NCOLS*94:NCOLS*95) = VAL%R
      ! E227 x R -> E227 (95, 1)
      RES(1+NROWS*94:NROWS*95,1+NCOLS*0:NCOLS*1) = VAL%E227
      ! E2 x E27 -> E227 (95, 31)
      RES(1+NROWS*94:NROWS*95,1+NCOLS*30:NCOLS*31) = VAL%E2
      ! E27 x E2 -> E227 (95, 3)
      RES(1+NROWS*94:NROWS*95,1+NCOLS*2:NCOLS*3) = VAL%E27
      ! E7 x E22 -> E227 (95, 11)
      RES(1+NROWS*94:NROWS*95,1+NCOLS*10:NCOLS*11) = VAL%E7
      ! E22 x E7 -> E227 (95, 8)
      RES(1+NROWS*94:NROWS*95,1+NCOLS*7:NCOLS*8) = VAL%E22
      ! R x E137 -> E137 (96, 96)
      RES(1+NROWS*95:NROWS*96,1+NCOLS*95:NCOLS*96) = VAL%R
      ! E137 x R -> E137 (96, 1)
      RES(1+NROWS*95:NROWS*96,1+NCOLS*0:NCOLS*1) = VAL%E137
      ! E1 x E37 -> E137 (96, 32)
      RES(1+NROWS*95:NROWS*96,1+NCOLS*31:NCOLS*32) = VAL%E1
      ! E37 x E1 -> E137 (96, 2)
      RES(1+NROWS*95:NROWS*96,1+NCOLS*1:NCOLS*2) = VAL%E37
      ! E3 x E17 -> E137 (96, 30)
      RES(1+NROWS*95:NROWS*96,1+NCOLS*29:NCOLS*30) = VAL%E3
      ! E17 x E3 -> E137 (96, 4)
      RES(1+NROWS*95:NROWS*96,1+NCOLS*3:NCOLS*4) = VAL%E17
      ! E7 x E13 -> E137 (96, 12)
      RES(1+NROWS*95:NROWS*96,1+NCOLS*11:NCOLS*12) = VAL%E7
      ! E13 x E7 -> E137 (96, 8)
      RES(1+NROWS*95:NROWS*96,1+NCOLS*7:NCOLS*8) = VAL%E13
      ! R x E237 -> E237 (97, 97)
      RES(1+NROWS*96:NROWS*97,1+NCOLS*96:NCOLS*97) = VAL%R
      ! E237 x R -> E237 (97, 1)
      RES(1+NROWS*96:NROWS*97,1+NCOLS*0:NCOLS*1) = VAL%E237
      ! E2 x E37 -> E237 (97, 32)
      RES(1+NROWS*96:NROWS*97,1+NCOLS*31:NCOLS*32) = VAL%E2
      ! E37 x E2 -> E237 (97, 3)
      RES(1+NROWS*96:NROWS*97,1+NCOLS*2:NCOLS*3) = VAL%E37
      ! E3 x E27 -> E237 (97, 31)
      RES(1+NROWS*96:NROWS*97,1+NCOLS*30:NCOLS*31) = VAL%E3
      ! E27 x E3 -> E237 (97, 4)
      RES(1+NROWS*96:NROWS*97,1+NCOLS*3:NCOLS*4) = VAL%E27
      ! E7 x E23 -> E237 (97, 13)
      RES(1+NROWS*96:NROWS*97,1+NCOLS*12:NCOLS*13) = VAL%E7
      ! E23 x E7 -> E237 (97, 8)
      RES(1+NROWS*96:NROWS*97,1+NCOLS*7:NCOLS*8) = VAL%E23
      ! R x E337 -> E337 (98, 98)
      RES(1+NROWS*97:NROWS*98,1+NCOLS*97:NCOLS*98) = VAL%R
      ! E337 x R -> E337 (98, 1)
      RES(1+NROWS*97:NROWS*98,1+NCOLS*0:NCOLS*1) = VAL%E337
      ! E3 x E37 -> E337 (98, 32)
      RES(1+NROWS*97:NROWS*98,1+NCOLS*31:NCOLS*32) = VAL%E3
      ! E37 x E3 -> E337 (98, 4)
      RES(1+NROWS*97:NROWS*98,1+NCOLS*3:NCOLS*4) = VAL%E37
      ! E7 x E33 -> E337 (98, 14)
      RES(1+NROWS*97:NROWS*98,1+NCOLS*13:NCOLS*14) = VAL%E7
      ! E33 x E7 -> E337 (98, 8)
      RES(1+NROWS*97:NROWS*98,1+NCOLS*7:NCOLS*8) = VAL%E33
      ! R x E147 -> E147 (99, 99)
      RES(1+NROWS*98:NROWS*99,1+NCOLS*98:NCOLS*99) = VAL%R
      ! E147 x R -> E147 (99, 1)
      RES(1+NROWS*98:NROWS*99,1+NCOLS*0:NCOLS*1) = VAL%E147
      ! E1 x E47 -> E147 (99, 33)
      RES(1+NROWS*98:NROWS*99,1+NCOLS*32:NCOLS*33) = VAL%E1
      ! E47 x E1 -> E147 (99, 2)
      RES(1+NROWS*98:NROWS*99,1+NCOLS*1:NCOLS*2) = VAL%E47
      ! E4 x E17 -> E147 (99, 30)
      RES(1+NROWS*98:NROWS*99,1+NCOLS*29:NCOLS*30) = VAL%E4
      ! E17 x E4 -> E147 (99, 5)
      RES(1+NROWS*98:NROWS*99,1+NCOLS*4:NCOLS*5) = VAL%E17
      ! E7 x E14 -> E147 (99, 15)
      RES(1+NROWS*98:NROWS*99,1+NCOLS*14:NCOLS*15) = VAL%E7
      ! E14 x E7 -> E147 (99, 8)
      RES(1+NROWS*98:NROWS*99,1+NCOLS*7:NCOLS*8) = VAL%E14
      ! R x E247 -> E247 (100, 100)
      RES(1+NROWS*99:NROWS*100,1+NCOLS*99:NCOLS*100) = VAL%R
      ! E247 x R -> E247 (100, 1)
      RES(1+NROWS*99:NROWS*100,1+NCOLS*0:NCOLS*1) = VAL%E247
      ! E2 x E47 -> E247 (100, 33)
      RES(1+NROWS*99:NROWS*100,1+NCOLS*32:NCOLS*33) = VAL%E2
      ! E47 x E2 -> E247 (100, 3)
      RES(1+NROWS*99:NROWS*100,1+NCOLS*2:NCOLS*3) = VAL%E47
      ! E4 x E27 -> E247 (100, 31)
      RES(1+NROWS*99:NROWS*100,1+NCOLS*30:NCOLS*31) = VAL%E4
      ! E27 x E4 -> E247 (100, 5)
      RES(1+NROWS*99:NROWS*100,1+NCOLS*4:NCOLS*5) = VAL%E27
      ! E7 x E24 -> E247 (100, 16)
      RES(1+NROWS*99:NROWS*100,1+NCOLS*15:NCOLS*16) = VAL%E7
      ! E24 x E7 -> E247 (100, 8)
      RES(1+NROWS*99:NROWS*100,1+NCOLS*7:NCOLS*8) = VAL%E24
      ! R x E347 -> E347 (101, 101)
      RES(1+NROWS*100:NROWS*101,1+NCOLS*100:NCOLS*101) = VAL%R
      ! E347 x R -> E347 (101, 1)
      RES(1+NROWS*100:NROWS*101,1+NCOLS*0:NCOLS*1) = VAL%E347
      ! E3 x E47 -> E347 (101, 33)
      RES(1+NROWS*100:NROWS*101,1+NCOLS*32:NCOLS*33) = VAL%E3
      ! E47 x E3 -> E347 (101, 4)
      RES(1+NROWS*100:NROWS*101,1+NCOLS*3:NCOLS*4) = VAL%E47
      ! E4 x E37 -> E347 (101, 32)
      RES(1+NROWS*100:NROWS*101,1+NCOLS*31:NCOLS*32) = VAL%E4
      ! E37 x E4 -> E347 (101, 5)
      RES(1+NROWS*100:NROWS*101,1+NCOLS*4:NCOLS*5) = VAL%E37
      ! E7 x E34 -> E347 (101, 17)
      RES(1+NROWS*100:NROWS*101,1+NCOLS*16:NCOLS*17) = VAL%E7
      ! E34 x E7 -> E347 (101, 8)
      RES(1+NROWS*100:NROWS*101,1+NCOLS*7:NCOLS*8) = VAL%E34
      ! R x E447 -> E447 (102, 102)
      RES(1+NROWS*101:NROWS*102,1+NCOLS*101:NCOLS*102) = VAL%R
      ! E447 x R -> E447 (102, 1)
      RES(1+NROWS*101:NROWS*102,1+NCOLS*0:NCOLS*1) = VAL%E447
      ! E4 x E47 -> E447 (102, 33)
      RES(1+NROWS*101:NROWS*102,1+NCOLS*32:NCOLS*33) = VAL%E4
      ! E47 x E4 -> E447 (102, 5)
      RES(1+NROWS*101:NROWS*102,1+NCOLS*4:NCOLS*5) = VAL%E47
      ! E7 x E44 -> E447 (102, 18)
      RES(1+NROWS*101:NROWS*102,1+NCOLS*17:NCOLS*18) = VAL%E7
      ! E44 x E7 -> E447 (102, 8)
      RES(1+NROWS*101:NROWS*102,1+NCOLS*7:NCOLS*8) = VAL%E44
      ! R x E157 -> E157 (103, 103)
      RES(1+NROWS*102:NROWS*103,1+NCOLS*102:NCOLS*103) = VAL%R
      ! E157 x R -> E157 (103, 1)
      RES(1+NROWS*102:NROWS*103,1+NCOLS*0:NCOLS*1) = VAL%E157
      ! E1 x E57 -> E157 (103, 34)
      RES(1+NROWS*102:NROWS*103,1+NCOLS*33:NCOLS*34) = VAL%E1
      ! E57 x E1 -> E157 (103, 2)
      RES(1+NROWS*102:NROWS*103,1+NCOLS*1:NCOLS*2) = VAL%E57
      ! E5 x E17 -> E157 (103, 30)
      RES(1+NROWS*102:NROWS*103,1+NCOLS*29:NCOLS*30) = VAL%E5
      ! E17 x E5 -> E157 (103, 6)
      RES(1+NROWS*102:NROWS*103,1+NCOLS*5:NCOLS*6) = VAL%E17
      ! E7 x E15 -> E157 (103, 19)
      RES(1+NROWS*102:NROWS*103,1+NCOLS*18:NCOLS*19) = VAL%E7
      ! E15 x E7 -> E157 (103, 8)
      RES(1+NROWS*102:NROWS*103,1+NCOLS*7:NCOLS*8) = VAL%E15
      ! R x E257 -> E257 (104, 104)
      RES(1+NROWS*103:NROWS*104,1+NCOLS*103:NCOLS*104) = VAL%R
      ! E257 x R -> E257 (104, 1)
      RES(1+NROWS*103:NROWS*104,1+NCOLS*0:NCOLS*1) = VAL%E257
      ! E2 x E57 -> E257 (104, 34)
      RES(1+NROWS*103:NROWS*104,1+NCOLS*33:NCOLS*34) = VAL%E2
      ! E57 x E2 -> E257 (104, 3)
      RES(1+NROWS*103:NROWS*104,1+NCOLS*2:NCOLS*3) = VAL%E57
      ! E5 x E27 -> E257 (104, 31)
      RES(1+NROWS*103:NROWS*104,1+NCOLS*30:NCOLS*31) = VAL%E5
      ! E27 x E5 -> E257 (104, 6)
      RES(1+NROWS*103:NROWS*104,1+NCOLS*5:NCOLS*6) = VAL%E27
      ! E7 x E25 -> E257 (104, 20)
      RES(1+NROWS*103:NROWS*104,1+NCOLS*19:NCOLS*20) = VAL%E7
      ! E25 x E7 -> E257 (104, 8)
      RES(1+NROWS*103:NROWS*104,1+NCOLS*7:NCOLS*8) = VAL%E25
      ! R x E357 -> E357 (105, 105)
      RES(1+NROWS*104:NROWS*105,1+NCOLS*104:NCOLS*105) = VAL%R
      ! E357 x R -> E357 (105, 1)
      RES(1+NROWS*104:NROWS*105,1+NCOLS*0:NCOLS*1) = VAL%E357
      ! E3 x E57 -> E357 (105, 34)
      RES(1+NROWS*104:NROWS*105,1+NCOLS*33:NCOLS*34) = VAL%E3
      ! E57 x E3 -> E357 (105, 4)
      RES(1+NROWS*104:NROWS*105,1+NCOLS*3:NCOLS*4) = VAL%E57
      ! E5 x E37 -> E357 (105, 32)
      RES(1+NROWS*104:NROWS*105,1+NCOLS*31:NCOLS*32) = VAL%E5
      ! E37 x E5 -> E357 (105, 6)
      RES(1+NROWS*104:NROWS*105,1+NCOLS*5:NCOLS*6) = VAL%E37
      ! E7 x E35 -> E357 (105, 21)
      RES(1+NROWS*104:NROWS*105,1+NCOLS*20:NCOLS*21) = VAL%E7
      ! E35 x E7 -> E357 (105, 8)
      RES(1+NROWS*104:NROWS*105,1+NCOLS*7:NCOLS*8) = VAL%E35
      ! R x E457 -> E457 (106, 106)
      RES(1+NROWS*105:NROWS*106,1+NCOLS*105:NCOLS*106) = VAL%R
      ! E457 x R -> E457 (106, 1)
      RES(1+NROWS*105:NROWS*106,1+NCOLS*0:NCOLS*1) = VAL%E457
      ! E4 x E57 -> E457 (106, 34)
      RES(1+NROWS*105:NROWS*106,1+NCOLS*33:NCOLS*34) = VAL%E4
      ! E57 x E4 -> E457 (106, 5)
      RES(1+NROWS*105:NROWS*106,1+NCOLS*4:NCOLS*5) = VAL%E57
      ! E5 x E47 -> E457 (106, 33)
      RES(1+NROWS*105:NROWS*106,1+NCOLS*32:NCOLS*33) = VAL%E5
      ! E47 x E5 -> E457 (106, 6)
      RES(1+NROWS*105:NROWS*106,1+NCOLS*5:NCOLS*6) = VAL%E47
      ! E7 x E45 -> E457 (106, 22)
      RES(1+NROWS*105:NROWS*106,1+NCOLS*21:NCOLS*22) = VAL%E7
      ! E45 x E7 -> E457 (106, 8)
      RES(1+NROWS*105:NROWS*106,1+NCOLS*7:NCOLS*8) = VAL%E45
      ! R x E557 -> E557 (107, 107)
      RES(1+NROWS*106:NROWS*107,1+NCOLS*106:NCOLS*107) = VAL%R
      ! E557 x R -> E557 (107, 1)
      RES(1+NROWS*106:NROWS*107,1+NCOLS*0:NCOLS*1) = VAL%E557
      ! E5 x E57 -> E557 (107, 34)
      RES(1+NROWS*106:NROWS*107,1+NCOLS*33:NCOLS*34) = VAL%E5
      ! E57 x E5 -> E557 (107, 6)
      RES(1+NROWS*106:NROWS*107,1+NCOLS*5:NCOLS*6) = VAL%E57
      ! E7 x E55 -> E557 (107, 23)
      RES(1+NROWS*106:NROWS*107,1+NCOLS*22:NCOLS*23) = VAL%E7
      ! E55 x E7 -> E557 (107, 8)
      RES(1+NROWS*106:NROWS*107,1+NCOLS*7:NCOLS*8) = VAL%E55
      ! R x E167 -> E167 (108, 108)
      RES(1+NROWS*107:NROWS*108,1+NCOLS*107:NCOLS*108) = VAL%R
      ! E167 x R -> E167 (108, 1)
      RES(1+NROWS*107:NROWS*108,1+NCOLS*0:NCOLS*1) = VAL%E167
      ! E1 x E67 -> E167 (108, 35)
      RES(1+NROWS*107:NROWS*108,1+NCOLS*34:NCOLS*35) = VAL%E1
      ! E67 x E1 -> E167 (108, 2)
      RES(1+NROWS*107:NROWS*108,1+NCOLS*1:NCOLS*2) = VAL%E67
      ! E6 x E17 -> E167 (108, 30)
      RES(1+NROWS*107:NROWS*108,1+NCOLS*29:NCOLS*30) = VAL%E6
      ! E17 x E6 -> E167 (108, 7)
      RES(1+NROWS*107:NROWS*108,1+NCOLS*6:NCOLS*7) = VAL%E17
      ! E7 x E16 -> E167 (108, 24)
      RES(1+NROWS*107:NROWS*108,1+NCOLS*23:NCOLS*24) = VAL%E7
      ! E16 x E7 -> E167 (108, 8)
      RES(1+NROWS*107:NROWS*108,1+NCOLS*7:NCOLS*8) = VAL%E16
      ! R x E267 -> E267 (109, 109)
      RES(1+NROWS*108:NROWS*109,1+NCOLS*108:NCOLS*109) = VAL%R
      ! E267 x R -> E267 (109, 1)
      RES(1+NROWS*108:NROWS*109,1+NCOLS*0:NCOLS*1) = VAL%E267
      ! E2 x E67 -> E267 (109, 35)
      RES(1+NROWS*108:NROWS*109,1+NCOLS*34:NCOLS*35) = VAL%E2
      ! E67 x E2 -> E267 (109, 3)
      RES(1+NROWS*108:NROWS*109,1+NCOLS*2:NCOLS*3) = VAL%E67
      ! E6 x E27 -> E267 (109, 31)
      RES(1+NROWS*108:NROWS*109,1+NCOLS*30:NCOLS*31) = VAL%E6
      ! E27 x E6 -> E267 (109, 7)
      RES(1+NROWS*108:NROWS*109,1+NCOLS*6:NCOLS*7) = VAL%E27
      ! E7 x E26 -> E267 (109, 25)
      RES(1+NROWS*108:NROWS*109,1+NCOLS*24:NCOLS*25) = VAL%E7
      ! E26 x E7 -> E267 (109, 8)
      RES(1+NROWS*108:NROWS*109,1+NCOLS*7:NCOLS*8) = VAL%E26
      ! R x E367 -> E367 (110, 110)
      RES(1+NROWS*109:NROWS*110,1+NCOLS*109:NCOLS*110) = VAL%R
      ! E367 x R -> E367 (110, 1)
      RES(1+NROWS*109:NROWS*110,1+NCOLS*0:NCOLS*1) = VAL%E367
      ! E3 x E67 -> E367 (110, 35)
      RES(1+NROWS*109:NROWS*110,1+NCOLS*34:NCOLS*35) = VAL%E3
      ! E67 x E3 -> E367 (110, 4)
      RES(1+NROWS*109:NROWS*110,1+NCOLS*3:NCOLS*4) = VAL%E67
      ! E6 x E37 -> E367 (110, 32)
      RES(1+NROWS*109:NROWS*110,1+NCOLS*31:NCOLS*32) = VAL%E6
      ! E37 x E6 -> E367 (110, 7)
      RES(1+NROWS*109:NROWS*110,1+NCOLS*6:NCOLS*7) = VAL%E37
      ! E7 x E36 -> E367 (110, 26)
      RES(1+NROWS*109:NROWS*110,1+NCOLS*25:NCOLS*26) = VAL%E7
      ! E36 x E7 -> E367 (110, 8)
      RES(1+NROWS*109:NROWS*110,1+NCOLS*7:NCOLS*8) = VAL%E36
      ! R x E467 -> E467 (111, 111)
      RES(1+NROWS*110:NROWS*111,1+NCOLS*110:NCOLS*111) = VAL%R
      ! E467 x R -> E467 (111, 1)
      RES(1+NROWS*110:NROWS*111,1+NCOLS*0:NCOLS*1) = VAL%E467
      ! E4 x E67 -> E467 (111, 35)
      RES(1+NROWS*110:NROWS*111,1+NCOLS*34:NCOLS*35) = VAL%E4
      ! E67 x E4 -> E467 (111, 5)
      RES(1+NROWS*110:NROWS*111,1+NCOLS*4:NCOLS*5) = VAL%E67
      ! E6 x E47 -> E467 (111, 33)
      RES(1+NROWS*110:NROWS*111,1+NCOLS*32:NCOLS*33) = VAL%E6
      ! E47 x E6 -> E467 (111, 7)
      RES(1+NROWS*110:NROWS*111,1+NCOLS*6:NCOLS*7) = VAL%E47
      ! E7 x E46 -> E467 (111, 27)
      RES(1+NROWS*110:NROWS*111,1+NCOLS*26:NCOLS*27) = VAL%E7
      ! E46 x E7 -> E467 (111, 8)
      RES(1+NROWS*110:NROWS*111,1+NCOLS*7:NCOLS*8) = VAL%E46
      ! R x E567 -> E567 (112, 112)
      RES(1+NROWS*111:NROWS*112,1+NCOLS*111:NCOLS*112) = VAL%R
      ! E567 x R -> E567 (112, 1)
      RES(1+NROWS*111:NROWS*112,1+NCOLS*0:NCOLS*1) = VAL%E567
      ! E5 x E67 -> E567 (112, 35)
      RES(1+NROWS*111:NROWS*112,1+NCOLS*34:NCOLS*35) = VAL%E5
      ! E67 x E5 -> E567 (112, 6)
      RES(1+NROWS*111:NROWS*112,1+NCOLS*5:NCOLS*6) = VAL%E67
      ! E6 x E57 -> E567 (112, 34)
      RES(1+NROWS*111:NROWS*112,1+NCOLS*33:NCOLS*34) = VAL%E6
      ! E57 x E6 -> E567 (112, 7)
      RES(1+NROWS*111:NROWS*112,1+NCOLS*6:NCOLS*7) = VAL%E57
      ! E7 x E56 -> E567 (112, 28)
      RES(1+NROWS*111:NROWS*112,1+NCOLS*27:NCOLS*28) = VAL%E7
      ! E56 x E7 -> E567 (112, 8)
      RES(1+NROWS*111:NROWS*112,1+NCOLS*7:NCOLS*8) = VAL%E56
      ! R x E667 -> E667 (113, 113)
      RES(1+NROWS*112:NROWS*113,1+NCOLS*112:NCOLS*113) = VAL%R
      ! E667 x R -> E667 (113, 1)
      RES(1+NROWS*112:NROWS*113,1+NCOLS*0:NCOLS*1) = VAL%E667
      ! E6 x E67 -> E667 (113, 35)
      RES(1+NROWS*112:NROWS*113,1+NCOLS*34:NCOLS*35) = VAL%E6
      ! E67 x E6 -> E667 (113, 7)
      RES(1+NROWS*112:NROWS*113,1+NCOLS*6:NCOLS*7) = VAL%E67
      ! E7 x E66 -> E667 (113, 29)
      RES(1+NROWS*112:NROWS*113,1+NCOLS*28:NCOLS*29) = VAL%E7
      ! E66 x E7 -> E667 (113, 8)
      RES(1+NROWS*112:NROWS*113,1+NCOLS*7:NCOLS*8) = VAL%E66
      ! R x E177 -> E177 (114, 114)
      RES(1+NROWS*113:NROWS*114,1+NCOLS*113:NCOLS*114) = VAL%R
      ! E177 x R -> E177 (114, 1)
      RES(1+NROWS*113:NROWS*114,1+NCOLS*0:NCOLS*1) = VAL%E177
      ! E1 x E77 -> E177 (114, 36)
      RES(1+NROWS*113:NROWS*114,1+NCOLS*35:NCOLS*36) = VAL%E1
      ! E77 x E1 -> E177 (114, 2)
      RES(1+NROWS*113:NROWS*114,1+NCOLS*1:NCOLS*2) = VAL%E77
      ! E7 x E17 -> E177 (114, 30)
      RES(1+NROWS*113:NROWS*114,1+NCOLS*29:NCOLS*30) = VAL%E7
      ! E17 x E7 -> E177 (114, 8)
      RES(1+NROWS*113:NROWS*114,1+NCOLS*7:NCOLS*8) = VAL%E17
      ! R x E277 -> E277 (115, 115)
      RES(1+NROWS*114:NROWS*115,1+NCOLS*114:NCOLS*115) = VAL%R
      ! E277 x R -> E277 (115, 1)
      RES(1+NROWS*114:NROWS*115,1+NCOLS*0:NCOLS*1) = VAL%E277
      ! E2 x E77 -> E277 (115, 36)
      RES(1+NROWS*114:NROWS*115,1+NCOLS*35:NCOLS*36) = VAL%E2
      ! E77 x E2 -> E277 (115, 3)
      RES(1+NROWS*114:NROWS*115,1+NCOLS*2:NCOLS*3) = VAL%E77
      ! E7 x E27 -> E277 (115, 31)
      RES(1+NROWS*114:NROWS*115,1+NCOLS*30:NCOLS*31) = VAL%E7
      ! E27 x E7 -> E277 (115, 8)
      RES(1+NROWS*114:NROWS*115,1+NCOLS*7:NCOLS*8) = VAL%E27
      ! R x E377 -> E377 (116, 116)
      RES(1+NROWS*115:NROWS*116,1+NCOLS*115:NCOLS*116) = VAL%R
      ! E377 x R -> E377 (116, 1)
      RES(1+NROWS*115:NROWS*116,1+NCOLS*0:NCOLS*1) = VAL%E377
      ! E3 x E77 -> E377 (116, 36)
      RES(1+NROWS*115:NROWS*116,1+NCOLS*35:NCOLS*36) = VAL%E3
      ! E77 x E3 -> E377 (116, 4)
      RES(1+NROWS*115:NROWS*116,1+NCOLS*3:NCOLS*4) = VAL%E77
      ! E7 x E37 -> E377 (116, 32)
      RES(1+NROWS*115:NROWS*116,1+NCOLS*31:NCOLS*32) = VAL%E7
      ! E37 x E7 -> E377 (116, 8)
      RES(1+NROWS*115:NROWS*116,1+NCOLS*7:NCOLS*8) = VAL%E37
      ! R x E477 -> E477 (117, 117)
      RES(1+NROWS*116:NROWS*117,1+NCOLS*116:NCOLS*117) = VAL%R
      ! E477 x R -> E477 (117, 1)
      RES(1+NROWS*116:NROWS*117,1+NCOLS*0:NCOLS*1) = VAL%E477
      ! E4 x E77 -> E477 (117, 36)
      RES(1+NROWS*116:NROWS*117,1+NCOLS*35:NCOLS*36) = VAL%E4
      ! E77 x E4 -> E477 (117, 5)
      RES(1+NROWS*116:NROWS*117,1+NCOLS*4:NCOLS*5) = VAL%E77
      ! E7 x E47 -> E477 (117, 33)
      RES(1+NROWS*116:NROWS*117,1+NCOLS*32:NCOLS*33) = VAL%E7
      ! E47 x E7 -> E477 (117, 8)
      RES(1+NROWS*116:NROWS*117,1+NCOLS*7:NCOLS*8) = VAL%E47
      ! R x E577 -> E577 (118, 118)
      RES(1+NROWS*117:NROWS*118,1+NCOLS*117:NCOLS*118) = VAL%R
      ! E577 x R -> E577 (118, 1)
      RES(1+NROWS*117:NROWS*118,1+NCOLS*0:NCOLS*1) = VAL%E577
      ! E5 x E77 -> E577 (118, 36)
      RES(1+NROWS*117:NROWS*118,1+NCOLS*35:NCOLS*36) = VAL%E5
      ! E77 x E5 -> E577 (118, 6)
      RES(1+NROWS*117:NROWS*118,1+NCOLS*5:NCOLS*6) = VAL%E77
      ! E7 x E57 -> E577 (118, 34)
      RES(1+NROWS*117:NROWS*118,1+NCOLS*33:NCOLS*34) = VAL%E7
      ! E57 x E7 -> E577 (118, 8)
      RES(1+NROWS*117:NROWS*118,1+NCOLS*7:NCOLS*8) = VAL%E57
      ! R x E677 -> E677 (119, 119)
      RES(1+NROWS*118:NROWS*119,1+NCOLS*118:NCOLS*119) = VAL%R
      ! E677 x R -> E677 (119, 1)
      RES(1+NROWS*118:NROWS*119,1+NCOLS*0:NCOLS*1) = VAL%E677
      ! E6 x E77 -> E677 (119, 36)
      RES(1+NROWS*118:NROWS*119,1+NCOLS*35:NCOLS*36) = VAL%E6
      ! E77 x E6 -> E677 (119, 7)
      RES(1+NROWS*118:NROWS*119,1+NCOLS*6:NCOLS*7) = VAL%E77
      ! E7 x E67 -> E677 (119, 35)
      RES(1+NROWS*118:NROWS*119,1+NCOLS*34:NCOLS*35) = VAL%E7
      ! E67 x E7 -> E677 (119, 8)
      RES(1+NROWS*118:NROWS*119,1+NCOLS*7:NCOLS*8) = VAL%E67
      ! R x E777 -> E777 (120, 120)
      RES(1+NROWS*119:NROWS*120,1+NCOLS*119:NCOLS*120) = VAL%R
      ! E777 x R -> E777 (120, 1)
      RES(1+NROWS*119:NROWS*120,1+NCOLS*0:NCOLS*1) = VAL%E777
      ! E7 x E77 -> E777 (120, 36)
      RES(1+NROWS*119:NROWS*120,1+NCOLS*35:NCOLS*36) = VAL%E7
      ! E77 x E7 -> E777 (120, 8)
      RES(1+NROWS*119:NROWS*120,1+NCOLS*7:NCOLS*8) = VAL%E77
   END FUNCTION ONUMM7N3_TO_CR_MAT_M

      SUBROUTINE ONUMM7N3_SETIM_S(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(INOUT) :: VAL
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

      ! Order 3
      CASE(36)
         VAL%E111=RES
      CASE(37)
         VAL%E112=RES
      CASE(38)
         VAL%E122=RES
      CASE(39)
         VAL%E222=RES
      CASE(40)
         VAL%E113=RES
      CASE(41)
         VAL%E123=RES
      CASE(42)
         VAL%E223=RES
      CASE(43)
         VAL%E133=RES
      CASE(44)
         VAL%E233=RES
      CASE(45)
         VAL%E333=RES
      CASE(46)
         VAL%E114=RES
      CASE(47)
         VAL%E124=RES
      CASE(48)
         VAL%E224=RES
      CASE(49)
         VAL%E134=RES
      CASE(50)
         VAL%E234=RES
      CASE(51)
         VAL%E334=RES
      CASE(52)
         VAL%E144=RES
      CASE(53)
         VAL%E244=RES
      CASE(54)
         VAL%E344=RES
      CASE(55)
         VAL%E444=RES
      CASE(56)
         VAL%E115=RES
      CASE(57)
         VAL%E125=RES
      CASE(58)
         VAL%E225=RES
      CASE(59)
         VAL%E135=RES
      CASE(60)
         VAL%E235=RES
      CASE(61)
         VAL%E335=RES
      CASE(62)
         VAL%E145=RES
      CASE(63)
         VAL%E245=RES
      CASE(64)
         VAL%E345=RES
      CASE(65)
         VAL%E445=RES
      CASE(66)
         VAL%E155=RES
      CASE(67)
         VAL%E255=RES
      CASE(68)
         VAL%E355=RES
      CASE(69)
         VAL%E455=RES
      CASE(70)
         VAL%E555=RES
      CASE(71)
         VAL%E116=RES
      CASE(72)
         VAL%E126=RES
      CASE(73)
         VAL%E226=RES
      CASE(74)
         VAL%E136=RES
      CASE(75)
         VAL%E236=RES
      CASE(76)
         VAL%E336=RES
      CASE(77)
         VAL%E146=RES
      CASE(78)
         VAL%E246=RES
      CASE(79)
         VAL%E346=RES
      CASE(80)
         VAL%E446=RES
      CASE(81)
         VAL%E156=RES
      CASE(82)
         VAL%E256=RES
      CASE(83)
         VAL%E356=RES
      CASE(84)
         VAL%E456=RES
      CASE(85)
         VAL%E556=RES
      CASE(86)
         VAL%E166=RES
      CASE(87)
         VAL%E266=RES
      CASE(88)
         VAL%E366=RES
      CASE(89)
         VAL%E466=RES
      CASE(90)
         VAL%E566=RES
      CASE(91)
         VAL%E666=RES
      CASE(92)
         VAL%E117=RES
      CASE(93)
         VAL%E127=RES
      CASE(94)
         VAL%E227=RES
      CASE(95)
         VAL%E137=RES
      CASE(96)
         VAL%E237=RES
      CASE(97)
         VAL%E337=RES
      CASE(98)
         VAL%E147=RES
      CASE(99)
         VAL%E247=RES
      CASE(100)
         VAL%E347=RES
      CASE(101)
         VAL%E447=RES
      CASE(102)
         VAL%E157=RES
      CASE(103)
         VAL%E257=RES
      CASE(104)
         VAL%E357=RES
      CASE(105)
         VAL%E457=RES
      CASE(106)
         VAL%E557=RES
      CASE(107)
         VAL%E167=RES
      CASE(108)
         VAL%E267=RES
      CASE(109)
         VAL%E367=RES
      CASE(110)
         VAL%E467=RES
      CASE(111)
         VAL%E567=RES
      CASE(112)
         VAL%E667=RES
      CASE(113)
         VAL%E177=RES
      CASE(114)
         VAL%E277=RES
      CASE(115)
         VAL%E377=RES
      CASE(116)
         VAL%E477=RES
      CASE(117)
         VAL%E577=RES
      CASE(118)
         VAL%E677=RES
      CASE(119)
         VAL%E777=RES

      END SELECT
   END SUBROUTINE ONUMM7N3_SETIM_S

      SUBROUTINE ONUMM7N3_SETIM_V(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(INOUT) :: VAL(:)
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

      ! Order 3
      CASE(36)
         VAL%E111=RES
      CASE(37)
         VAL%E112=RES
      CASE(38)
         VAL%E122=RES
      CASE(39)
         VAL%E222=RES
      CASE(40)
         VAL%E113=RES
      CASE(41)
         VAL%E123=RES
      CASE(42)
         VAL%E223=RES
      CASE(43)
         VAL%E133=RES
      CASE(44)
         VAL%E233=RES
      CASE(45)
         VAL%E333=RES
      CASE(46)
         VAL%E114=RES
      CASE(47)
         VAL%E124=RES
      CASE(48)
         VAL%E224=RES
      CASE(49)
         VAL%E134=RES
      CASE(50)
         VAL%E234=RES
      CASE(51)
         VAL%E334=RES
      CASE(52)
         VAL%E144=RES
      CASE(53)
         VAL%E244=RES
      CASE(54)
         VAL%E344=RES
      CASE(55)
         VAL%E444=RES
      CASE(56)
         VAL%E115=RES
      CASE(57)
         VAL%E125=RES
      CASE(58)
         VAL%E225=RES
      CASE(59)
         VAL%E135=RES
      CASE(60)
         VAL%E235=RES
      CASE(61)
         VAL%E335=RES
      CASE(62)
         VAL%E145=RES
      CASE(63)
         VAL%E245=RES
      CASE(64)
         VAL%E345=RES
      CASE(65)
         VAL%E445=RES
      CASE(66)
         VAL%E155=RES
      CASE(67)
         VAL%E255=RES
      CASE(68)
         VAL%E355=RES
      CASE(69)
         VAL%E455=RES
      CASE(70)
         VAL%E555=RES
      CASE(71)
         VAL%E116=RES
      CASE(72)
         VAL%E126=RES
      CASE(73)
         VAL%E226=RES
      CASE(74)
         VAL%E136=RES
      CASE(75)
         VAL%E236=RES
      CASE(76)
         VAL%E336=RES
      CASE(77)
         VAL%E146=RES
      CASE(78)
         VAL%E246=RES
      CASE(79)
         VAL%E346=RES
      CASE(80)
         VAL%E446=RES
      CASE(81)
         VAL%E156=RES
      CASE(82)
         VAL%E256=RES
      CASE(83)
         VAL%E356=RES
      CASE(84)
         VAL%E456=RES
      CASE(85)
         VAL%E556=RES
      CASE(86)
         VAL%E166=RES
      CASE(87)
         VAL%E266=RES
      CASE(88)
         VAL%E366=RES
      CASE(89)
         VAL%E466=RES
      CASE(90)
         VAL%E566=RES
      CASE(91)
         VAL%E666=RES
      CASE(92)
         VAL%E117=RES
      CASE(93)
         VAL%E127=RES
      CASE(94)
         VAL%E227=RES
      CASE(95)
         VAL%E137=RES
      CASE(96)
         VAL%E237=RES
      CASE(97)
         VAL%E337=RES
      CASE(98)
         VAL%E147=RES
      CASE(99)
         VAL%E247=RES
      CASE(100)
         VAL%E347=RES
      CASE(101)
         VAL%E447=RES
      CASE(102)
         VAL%E157=RES
      CASE(103)
         VAL%E257=RES
      CASE(104)
         VAL%E357=RES
      CASE(105)
         VAL%E457=RES
      CASE(106)
         VAL%E557=RES
      CASE(107)
         VAL%E167=RES
      CASE(108)
         VAL%E267=RES
      CASE(109)
         VAL%E367=RES
      CASE(110)
         VAL%E467=RES
      CASE(111)
         VAL%E567=RES
      CASE(112)
         VAL%E667=RES
      CASE(113)
         VAL%E177=RES
      CASE(114)
         VAL%E277=RES
      CASE(115)
         VAL%E377=RES
      CASE(116)
         VAL%E477=RES
      CASE(117)
         VAL%E577=RES
      CASE(118)
         VAL%E677=RES
      CASE(119)
         VAL%E777=RES

      END SELECT
   END SUBROUTINE ONUMM7N3_SETIM_V

      SUBROUTINE ONUMM7N3_SETIM_M(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(INOUT) :: VAL(:,:)
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

      ! Order 3
      CASE(36)
         VAL%E111=RES
      CASE(37)
         VAL%E112=RES
      CASE(38)
         VAL%E122=RES
      CASE(39)
         VAL%E222=RES
      CASE(40)
         VAL%E113=RES
      CASE(41)
         VAL%E123=RES
      CASE(42)
         VAL%E223=RES
      CASE(43)
         VAL%E133=RES
      CASE(44)
         VAL%E233=RES
      CASE(45)
         VAL%E333=RES
      CASE(46)
         VAL%E114=RES
      CASE(47)
         VAL%E124=RES
      CASE(48)
         VAL%E224=RES
      CASE(49)
         VAL%E134=RES
      CASE(50)
         VAL%E234=RES
      CASE(51)
         VAL%E334=RES
      CASE(52)
         VAL%E144=RES
      CASE(53)
         VAL%E244=RES
      CASE(54)
         VAL%E344=RES
      CASE(55)
         VAL%E444=RES
      CASE(56)
         VAL%E115=RES
      CASE(57)
         VAL%E125=RES
      CASE(58)
         VAL%E225=RES
      CASE(59)
         VAL%E135=RES
      CASE(60)
         VAL%E235=RES
      CASE(61)
         VAL%E335=RES
      CASE(62)
         VAL%E145=RES
      CASE(63)
         VAL%E245=RES
      CASE(64)
         VAL%E345=RES
      CASE(65)
         VAL%E445=RES
      CASE(66)
         VAL%E155=RES
      CASE(67)
         VAL%E255=RES
      CASE(68)
         VAL%E355=RES
      CASE(69)
         VAL%E455=RES
      CASE(70)
         VAL%E555=RES
      CASE(71)
         VAL%E116=RES
      CASE(72)
         VAL%E126=RES
      CASE(73)
         VAL%E226=RES
      CASE(74)
         VAL%E136=RES
      CASE(75)
         VAL%E236=RES
      CASE(76)
         VAL%E336=RES
      CASE(77)
         VAL%E146=RES
      CASE(78)
         VAL%E246=RES
      CASE(79)
         VAL%E346=RES
      CASE(80)
         VAL%E446=RES
      CASE(81)
         VAL%E156=RES
      CASE(82)
         VAL%E256=RES
      CASE(83)
         VAL%E356=RES
      CASE(84)
         VAL%E456=RES
      CASE(85)
         VAL%E556=RES
      CASE(86)
         VAL%E166=RES
      CASE(87)
         VAL%E266=RES
      CASE(88)
         VAL%E366=RES
      CASE(89)
         VAL%E466=RES
      CASE(90)
         VAL%E566=RES
      CASE(91)
         VAL%E666=RES
      CASE(92)
         VAL%E117=RES
      CASE(93)
         VAL%E127=RES
      CASE(94)
         VAL%E227=RES
      CASE(95)
         VAL%E137=RES
      CASE(96)
         VAL%E237=RES
      CASE(97)
         VAL%E337=RES
      CASE(98)
         VAL%E147=RES
      CASE(99)
         VAL%E247=RES
      CASE(100)
         VAL%E347=RES
      CASE(101)
         VAL%E447=RES
      CASE(102)
         VAL%E157=RES
      CASE(103)
         VAL%E257=RES
      CASE(104)
         VAL%E357=RES
      CASE(105)
         VAL%E457=RES
      CASE(106)
         VAL%E557=RES
      CASE(107)
         VAL%E167=RES
      CASE(108)
         VAL%E267=RES
      CASE(109)
         VAL%E367=RES
      CASE(110)
         VAL%E467=RES
      CASE(111)
         VAL%E567=RES
      CASE(112)
         VAL%E667=RES
      CASE(113)
         VAL%E177=RES
      CASE(114)
         VAL%E277=RES
      CASE(115)
         VAL%E377=RES
      CASE(116)
         VAL%E477=RES
      CASE(117)
         VAL%E577=RES
      CASE(118)
         VAL%E677=RES
      CASE(119)
         VAL%E777=RES

      END SELECT
   END SUBROUTINE ONUMM7N3_SETIM_M

FUNCTION ONUMM7N3_GETIM_S(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: VAL
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

      ! Order 3
      CASE(36)
         RES=VAL%E111
      CASE(37)
         RES=VAL%E112
      CASE(38)
         RES=VAL%E122
      CASE(39)
         RES=VAL%E222
      CASE(40)
         RES=VAL%E113
      CASE(41)
         RES=VAL%E123
      CASE(42)
         RES=VAL%E223
      CASE(43)
         RES=VAL%E133
      CASE(44)
         RES=VAL%E233
      CASE(45)
         RES=VAL%E333
      CASE(46)
         RES=VAL%E114
      CASE(47)
         RES=VAL%E124
      CASE(48)
         RES=VAL%E224
      CASE(49)
         RES=VAL%E134
      CASE(50)
         RES=VAL%E234
      CASE(51)
         RES=VAL%E334
      CASE(52)
         RES=VAL%E144
      CASE(53)
         RES=VAL%E244
      CASE(54)
         RES=VAL%E344
      CASE(55)
         RES=VAL%E444
      CASE(56)
         RES=VAL%E115
      CASE(57)
         RES=VAL%E125
      CASE(58)
         RES=VAL%E225
      CASE(59)
         RES=VAL%E135
      CASE(60)
         RES=VAL%E235
      CASE(61)
         RES=VAL%E335
      CASE(62)
         RES=VAL%E145
      CASE(63)
         RES=VAL%E245
      CASE(64)
         RES=VAL%E345
      CASE(65)
         RES=VAL%E445
      CASE(66)
         RES=VAL%E155
      CASE(67)
         RES=VAL%E255
      CASE(68)
         RES=VAL%E355
      CASE(69)
         RES=VAL%E455
      CASE(70)
         RES=VAL%E555
      CASE(71)
         RES=VAL%E116
      CASE(72)
         RES=VAL%E126
      CASE(73)
         RES=VAL%E226
      CASE(74)
         RES=VAL%E136
      CASE(75)
         RES=VAL%E236
      CASE(76)
         RES=VAL%E336
      CASE(77)
         RES=VAL%E146
      CASE(78)
         RES=VAL%E246
      CASE(79)
         RES=VAL%E346
      CASE(80)
         RES=VAL%E446
      CASE(81)
         RES=VAL%E156
      CASE(82)
         RES=VAL%E256
      CASE(83)
         RES=VAL%E356
      CASE(84)
         RES=VAL%E456
      CASE(85)
         RES=VAL%E556
      CASE(86)
         RES=VAL%E166
      CASE(87)
         RES=VAL%E266
      CASE(88)
         RES=VAL%E366
      CASE(89)
         RES=VAL%E466
      CASE(90)
         RES=VAL%E566
      CASE(91)
         RES=VAL%E666
      CASE(92)
         RES=VAL%E117
      CASE(93)
         RES=VAL%E127
      CASE(94)
         RES=VAL%E227
      CASE(95)
         RES=VAL%E137
      CASE(96)
         RES=VAL%E237
      CASE(97)
         RES=VAL%E337
      CASE(98)
         RES=VAL%E147
      CASE(99)
         RES=VAL%E247
      CASE(100)
         RES=VAL%E347
      CASE(101)
         RES=VAL%E447
      CASE(102)
         RES=VAL%E157
      CASE(103)
         RES=VAL%E257
      CASE(104)
         RES=VAL%E357
      CASE(105)
         RES=VAL%E457
      CASE(106)
         RES=VAL%E557
      CASE(107)
         RES=VAL%E167
      CASE(108)
         RES=VAL%E267
      CASE(109)
         RES=VAL%E367
      CASE(110)
         RES=VAL%E467
      CASE(111)
         RES=VAL%E567
      CASE(112)
         RES=VAL%E667
      CASE(113)
         RES=VAL%E177
      CASE(114)
         RES=VAL%E277
      CASE(115)
         RES=VAL%E377
      CASE(116)
         RES=VAL%E477
      CASE(117)
         RES=VAL%E577
      CASE(118)
         RES=VAL%E677
      CASE(119)
         RES=VAL%E777

      END SELECT
   END FUNCTION ONUMM7N3_GETIM_S

FUNCTION ONUMM7N3_GETIM_V(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: VAL(:)
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

      ! Order 3
      CASE(36)
         RES=VAL%E111
      CASE(37)
         RES=VAL%E112
      CASE(38)
         RES=VAL%E122
      CASE(39)
         RES=VAL%E222
      CASE(40)
         RES=VAL%E113
      CASE(41)
         RES=VAL%E123
      CASE(42)
         RES=VAL%E223
      CASE(43)
         RES=VAL%E133
      CASE(44)
         RES=VAL%E233
      CASE(45)
         RES=VAL%E333
      CASE(46)
         RES=VAL%E114
      CASE(47)
         RES=VAL%E124
      CASE(48)
         RES=VAL%E224
      CASE(49)
         RES=VAL%E134
      CASE(50)
         RES=VAL%E234
      CASE(51)
         RES=VAL%E334
      CASE(52)
         RES=VAL%E144
      CASE(53)
         RES=VAL%E244
      CASE(54)
         RES=VAL%E344
      CASE(55)
         RES=VAL%E444
      CASE(56)
         RES=VAL%E115
      CASE(57)
         RES=VAL%E125
      CASE(58)
         RES=VAL%E225
      CASE(59)
         RES=VAL%E135
      CASE(60)
         RES=VAL%E235
      CASE(61)
         RES=VAL%E335
      CASE(62)
         RES=VAL%E145
      CASE(63)
         RES=VAL%E245
      CASE(64)
         RES=VAL%E345
      CASE(65)
         RES=VAL%E445
      CASE(66)
         RES=VAL%E155
      CASE(67)
         RES=VAL%E255
      CASE(68)
         RES=VAL%E355
      CASE(69)
         RES=VAL%E455
      CASE(70)
         RES=VAL%E555
      CASE(71)
         RES=VAL%E116
      CASE(72)
         RES=VAL%E126
      CASE(73)
         RES=VAL%E226
      CASE(74)
         RES=VAL%E136
      CASE(75)
         RES=VAL%E236
      CASE(76)
         RES=VAL%E336
      CASE(77)
         RES=VAL%E146
      CASE(78)
         RES=VAL%E246
      CASE(79)
         RES=VAL%E346
      CASE(80)
         RES=VAL%E446
      CASE(81)
         RES=VAL%E156
      CASE(82)
         RES=VAL%E256
      CASE(83)
         RES=VAL%E356
      CASE(84)
         RES=VAL%E456
      CASE(85)
         RES=VAL%E556
      CASE(86)
         RES=VAL%E166
      CASE(87)
         RES=VAL%E266
      CASE(88)
         RES=VAL%E366
      CASE(89)
         RES=VAL%E466
      CASE(90)
         RES=VAL%E566
      CASE(91)
         RES=VAL%E666
      CASE(92)
         RES=VAL%E117
      CASE(93)
         RES=VAL%E127
      CASE(94)
         RES=VAL%E227
      CASE(95)
         RES=VAL%E137
      CASE(96)
         RES=VAL%E237
      CASE(97)
         RES=VAL%E337
      CASE(98)
         RES=VAL%E147
      CASE(99)
         RES=VAL%E247
      CASE(100)
         RES=VAL%E347
      CASE(101)
         RES=VAL%E447
      CASE(102)
         RES=VAL%E157
      CASE(103)
         RES=VAL%E257
      CASE(104)
         RES=VAL%E357
      CASE(105)
         RES=VAL%E457
      CASE(106)
         RES=VAL%E557
      CASE(107)
         RES=VAL%E167
      CASE(108)
         RES=VAL%E267
      CASE(109)
         RES=VAL%E367
      CASE(110)
         RES=VAL%E467
      CASE(111)
         RES=VAL%E567
      CASE(112)
         RES=VAL%E667
      CASE(113)
         RES=VAL%E177
      CASE(114)
         RES=VAL%E277
      CASE(115)
         RES=VAL%E377
      CASE(116)
         RES=VAL%E477
      CASE(117)
         RES=VAL%E577
      CASE(118)
         RES=VAL%E677
      CASE(119)
         RES=VAL%E777

      END SELECT
   END FUNCTION ONUMM7N3_GETIM_V

FUNCTION ONUMM7N3_GETIM_M(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: VAL(:,:)
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

      ! Order 3
      CASE(36)
         RES=VAL%E111
      CASE(37)
         RES=VAL%E112
      CASE(38)
         RES=VAL%E122
      CASE(39)
         RES=VAL%E222
      CASE(40)
         RES=VAL%E113
      CASE(41)
         RES=VAL%E123
      CASE(42)
         RES=VAL%E223
      CASE(43)
         RES=VAL%E133
      CASE(44)
         RES=VAL%E233
      CASE(45)
         RES=VAL%E333
      CASE(46)
         RES=VAL%E114
      CASE(47)
         RES=VAL%E124
      CASE(48)
         RES=VAL%E224
      CASE(49)
         RES=VAL%E134
      CASE(50)
         RES=VAL%E234
      CASE(51)
         RES=VAL%E334
      CASE(52)
         RES=VAL%E144
      CASE(53)
         RES=VAL%E244
      CASE(54)
         RES=VAL%E344
      CASE(55)
         RES=VAL%E444
      CASE(56)
         RES=VAL%E115
      CASE(57)
         RES=VAL%E125
      CASE(58)
         RES=VAL%E225
      CASE(59)
         RES=VAL%E135
      CASE(60)
         RES=VAL%E235
      CASE(61)
         RES=VAL%E335
      CASE(62)
         RES=VAL%E145
      CASE(63)
         RES=VAL%E245
      CASE(64)
         RES=VAL%E345
      CASE(65)
         RES=VAL%E445
      CASE(66)
         RES=VAL%E155
      CASE(67)
         RES=VAL%E255
      CASE(68)
         RES=VAL%E355
      CASE(69)
         RES=VAL%E455
      CASE(70)
         RES=VAL%E555
      CASE(71)
         RES=VAL%E116
      CASE(72)
         RES=VAL%E126
      CASE(73)
         RES=VAL%E226
      CASE(74)
         RES=VAL%E136
      CASE(75)
         RES=VAL%E236
      CASE(76)
         RES=VAL%E336
      CASE(77)
         RES=VAL%E146
      CASE(78)
         RES=VAL%E246
      CASE(79)
         RES=VAL%E346
      CASE(80)
         RES=VAL%E446
      CASE(81)
         RES=VAL%E156
      CASE(82)
         RES=VAL%E256
      CASE(83)
         RES=VAL%E356
      CASE(84)
         RES=VAL%E456
      CASE(85)
         RES=VAL%E556
      CASE(86)
         RES=VAL%E166
      CASE(87)
         RES=VAL%E266
      CASE(88)
         RES=VAL%E366
      CASE(89)
         RES=VAL%E466
      CASE(90)
         RES=VAL%E566
      CASE(91)
         RES=VAL%E666
      CASE(92)
         RES=VAL%E117
      CASE(93)
         RES=VAL%E127
      CASE(94)
         RES=VAL%E227
      CASE(95)
         RES=VAL%E137
      CASE(96)
         RES=VAL%E237
      CASE(97)
         RES=VAL%E337
      CASE(98)
         RES=VAL%E147
      CASE(99)
         RES=VAL%E247
      CASE(100)
         RES=VAL%E347
      CASE(101)
         RES=VAL%E447
      CASE(102)
         RES=VAL%E157
      CASE(103)
         RES=VAL%E257
      CASE(104)
         RES=VAL%E357
      CASE(105)
         RES=VAL%E457
      CASE(106)
         RES=VAL%E557
      CASE(107)
         RES=VAL%E167
      CASE(108)
         RES=VAL%E267
      CASE(109)
         RES=VAL%E367
      CASE(110)
         RES=VAL%E467
      CASE(111)
         RES=VAL%E567
      CASE(112)
         RES=VAL%E667
      CASE(113)
         RES=VAL%E177
      CASE(114)
         RES=VAL%E277
      CASE(115)
         RES=VAL%E377
      CASE(116)
         RES=VAL%E477
      CASE(117)
         RES=VAL%E577
      CASE(118)
         RES=VAL%E677
      CASE(119)
         RES=VAL%E777

      END SELECT
   END FUNCTION ONUMM7N3_GETIM_M

   SUBROUTINE ONUMM7N3_PPRINT_S(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: VAR
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

      !  Order 3
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E111 * '
      CALL PPRINT(VAR%E111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E112 * '
      CALL PPRINT(VAR%E112,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E122 * '
      CALL PPRINT(VAR%E122,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E222 * '
      CALL PPRINT(VAR%E222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E113 * '
      CALL PPRINT(VAR%E113,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E123 * '
      CALL PPRINT(VAR%E123,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E223 * '
      CALL PPRINT(VAR%E223,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E133 * '
      CALL PPRINT(VAR%E133,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E233 * '
      CALL PPRINT(VAR%E233,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E333 * '
      CALL PPRINT(VAR%E333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E114 * '
      CALL PPRINT(VAR%E114,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E124 * '
      CALL PPRINT(VAR%E124,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E224 * '
      CALL PPRINT(VAR%E224,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E134 * '
      CALL PPRINT(VAR%E134,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E234 * '
      CALL PPRINT(VAR%E234,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E334 * '
      CALL PPRINT(VAR%E334,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E144 * '
      CALL PPRINT(VAR%E144,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E244 * '
      CALL PPRINT(VAR%E244,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E344 * '
      CALL PPRINT(VAR%E344,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E444 * '
      CALL PPRINT(VAR%E444,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E115 * '
      CALL PPRINT(VAR%E115,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E125 * '
      CALL PPRINT(VAR%E125,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E225 * '
      CALL PPRINT(VAR%E225,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E135 * '
      CALL PPRINT(VAR%E135,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E235 * '
      CALL PPRINT(VAR%E235,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E335 * '
      CALL PPRINT(VAR%E335,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E145 * '
      CALL PPRINT(VAR%E145,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E245 * '
      CALL PPRINT(VAR%E245,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E345 * '
      CALL PPRINT(VAR%E345,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E445 * '
      CALL PPRINT(VAR%E445,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E155 * '
      CALL PPRINT(VAR%E155,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E255 * '
      CALL PPRINT(VAR%E255,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E355 * '
      CALL PPRINT(VAR%E355,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E455 * '
      CALL PPRINT(VAR%E455,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E555 * '
      CALL PPRINT(VAR%E555,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E116 * '
      CALL PPRINT(VAR%E116,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E126 * '
      CALL PPRINT(VAR%E126,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E226 * '
      CALL PPRINT(VAR%E226,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E136 * '
      CALL PPRINT(VAR%E136,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E236 * '
      CALL PPRINT(VAR%E236,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E336 * '
      CALL PPRINT(VAR%E336,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E146 * '
      CALL PPRINT(VAR%E146,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E246 * '
      CALL PPRINT(VAR%E246,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E346 * '
      CALL PPRINT(VAR%E346,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E446 * '
      CALL PPRINT(VAR%E446,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E156 * '
      CALL PPRINT(VAR%E156,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E256 * '
      CALL PPRINT(VAR%E256,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E356 * '
      CALL PPRINT(VAR%E356,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E456 * '
      CALL PPRINT(VAR%E456,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E556 * '
      CALL PPRINT(VAR%E556,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E166 * '
      CALL PPRINT(VAR%E166,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E266 * '
      CALL PPRINT(VAR%E266,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E366 * '
      CALL PPRINT(VAR%E366,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E466 * '
      CALL PPRINT(VAR%E466,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E566 * '
      CALL PPRINT(VAR%E566,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E666 * '
      CALL PPRINT(VAR%E666,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E117 * '
      CALL PPRINT(VAR%E117,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E127 * '
      CALL PPRINT(VAR%E127,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E227 * '
      CALL PPRINT(VAR%E227,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E137 * '
      CALL PPRINT(VAR%E137,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E237 * '
      CALL PPRINT(VAR%E237,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E337 * '
      CALL PPRINT(VAR%E337,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E147 * '
      CALL PPRINT(VAR%E147,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E247 * '
      CALL PPRINT(VAR%E247,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E347 * '
      CALL PPRINT(VAR%E347,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E447 * '
      CALL PPRINT(VAR%E447,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E157 * '
      CALL PPRINT(VAR%E157,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E257 * '
      CALL PPRINT(VAR%E257,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E357 * '
      CALL PPRINT(VAR%E357,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E457 * '
      CALL PPRINT(VAR%E457,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E557 * '
      CALL PPRINT(VAR%E557,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E167 * '
      CALL PPRINT(VAR%E167,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E267 * '
      CALL PPRINT(VAR%E267,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E367 * '
      CALL PPRINT(VAR%E367,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E467 * '
      CALL PPRINT(VAR%E467,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E567 * '
      CALL PPRINT(VAR%E567,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E667 * '
      CALL PPRINT(VAR%E667,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E177 * '
      CALL PPRINT(VAR%E177,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E277 * '
      CALL PPRINT(VAR%E277,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E377 * '
      CALL PPRINT(VAR%E377,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E477 * '
      CALL PPRINT(VAR%E477,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E577 * '
      CALL PPRINT(VAR%E577,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E677 * '
      CALL PPRINT(VAR%E677,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E777 * '
      CALL PPRINT(VAR%E777,unit=unt,fmt=output_format)


   END SUBROUTINE ONUMM7N3_PPRINT_S

   SUBROUTINE ONUMM7N3_PPRINT_V(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: VAR(:)
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

      !  Order 3
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E111 * '
      CALL PPRINT(VAR%E111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E112 * '
      CALL PPRINT(VAR%E112,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E122 * '
      CALL PPRINT(VAR%E122,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E222 * '
      CALL PPRINT(VAR%E222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E113 * '
      CALL PPRINT(VAR%E113,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E123 * '
      CALL PPRINT(VAR%E123,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E223 * '
      CALL PPRINT(VAR%E223,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E133 * '
      CALL PPRINT(VAR%E133,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E233 * '
      CALL PPRINT(VAR%E233,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E333 * '
      CALL PPRINT(VAR%E333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E114 * '
      CALL PPRINT(VAR%E114,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E124 * '
      CALL PPRINT(VAR%E124,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E224 * '
      CALL PPRINT(VAR%E224,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E134 * '
      CALL PPRINT(VAR%E134,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E234 * '
      CALL PPRINT(VAR%E234,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E334 * '
      CALL PPRINT(VAR%E334,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E144 * '
      CALL PPRINT(VAR%E144,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E244 * '
      CALL PPRINT(VAR%E244,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E344 * '
      CALL PPRINT(VAR%E344,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E444 * '
      CALL PPRINT(VAR%E444,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E115 * '
      CALL PPRINT(VAR%E115,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E125 * '
      CALL PPRINT(VAR%E125,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E225 * '
      CALL PPRINT(VAR%E225,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E135 * '
      CALL PPRINT(VAR%E135,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E235 * '
      CALL PPRINT(VAR%E235,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E335 * '
      CALL PPRINT(VAR%E335,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E145 * '
      CALL PPRINT(VAR%E145,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E245 * '
      CALL PPRINT(VAR%E245,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E345 * '
      CALL PPRINT(VAR%E345,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E445 * '
      CALL PPRINT(VAR%E445,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E155 * '
      CALL PPRINT(VAR%E155,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E255 * '
      CALL PPRINT(VAR%E255,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E355 * '
      CALL PPRINT(VAR%E355,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E455 * '
      CALL PPRINT(VAR%E455,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E555 * '
      CALL PPRINT(VAR%E555,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E116 * '
      CALL PPRINT(VAR%E116,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E126 * '
      CALL PPRINT(VAR%E126,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E226 * '
      CALL PPRINT(VAR%E226,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E136 * '
      CALL PPRINT(VAR%E136,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E236 * '
      CALL PPRINT(VAR%E236,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E336 * '
      CALL PPRINT(VAR%E336,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E146 * '
      CALL PPRINT(VAR%E146,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E246 * '
      CALL PPRINT(VAR%E246,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E346 * '
      CALL PPRINT(VAR%E346,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E446 * '
      CALL PPRINT(VAR%E446,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E156 * '
      CALL PPRINT(VAR%E156,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E256 * '
      CALL PPRINT(VAR%E256,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E356 * '
      CALL PPRINT(VAR%E356,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E456 * '
      CALL PPRINT(VAR%E456,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E556 * '
      CALL PPRINT(VAR%E556,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E166 * '
      CALL PPRINT(VAR%E166,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E266 * '
      CALL PPRINT(VAR%E266,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E366 * '
      CALL PPRINT(VAR%E366,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E466 * '
      CALL PPRINT(VAR%E466,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E566 * '
      CALL PPRINT(VAR%E566,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E666 * '
      CALL PPRINT(VAR%E666,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E117 * '
      CALL PPRINT(VAR%E117,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E127 * '
      CALL PPRINT(VAR%E127,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E227 * '
      CALL PPRINT(VAR%E227,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E137 * '
      CALL PPRINT(VAR%E137,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E237 * '
      CALL PPRINT(VAR%E237,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E337 * '
      CALL PPRINT(VAR%E337,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E147 * '
      CALL PPRINT(VAR%E147,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E247 * '
      CALL PPRINT(VAR%E247,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E347 * '
      CALL PPRINT(VAR%E347,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E447 * '
      CALL PPRINT(VAR%E447,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E157 * '
      CALL PPRINT(VAR%E157,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E257 * '
      CALL PPRINT(VAR%E257,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E357 * '
      CALL PPRINT(VAR%E357,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E457 * '
      CALL PPRINT(VAR%E457,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E557 * '
      CALL PPRINT(VAR%E557,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E167 * '
      CALL PPRINT(VAR%E167,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E267 * '
      CALL PPRINT(VAR%E267,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E367 * '
      CALL PPRINT(VAR%E367,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E467 * '
      CALL PPRINT(VAR%E467,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E567 * '
      CALL PPRINT(VAR%E567,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E667 * '
      CALL PPRINT(VAR%E667,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E177 * '
      CALL PPRINT(VAR%E177,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E277 * '
      CALL PPRINT(VAR%E277,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E377 * '
      CALL PPRINT(VAR%E377,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E477 * '
      CALL PPRINT(VAR%E477,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E577 * '
      CALL PPRINT(VAR%E577,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E677 * '
      CALL PPRINT(VAR%E677,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E777 * '
      CALL PPRINT(VAR%E777,unit=unt,fmt=output_format)


   END SUBROUTINE ONUMM7N3_PPRINT_V

   SUBROUTINE ONUMM7N3_PPRINT_M(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: VAR(:,:)
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

      !  Order 3
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E111 * '
      CALL PPRINT(VAR%E111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E112 * '
      CALL PPRINT(VAR%E112,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E122 * '
      CALL PPRINT(VAR%E122,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E222 * '
      CALL PPRINT(VAR%E222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E113 * '
      CALL PPRINT(VAR%E113,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E123 * '
      CALL PPRINT(VAR%E123,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E223 * '
      CALL PPRINT(VAR%E223,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E133 * '
      CALL PPRINT(VAR%E133,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E233 * '
      CALL PPRINT(VAR%E233,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E333 * '
      CALL PPRINT(VAR%E333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E114 * '
      CALL PPRINT(VAR%E114,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E124 * '
      CALL PPRINT(VAR%E124,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E224 * '
      CALL PPRINT(VAR%E224,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E134 * '
      CALL PPRINT(VAR%E134,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E234 * '
      CALL PPRINT(VAR%E234,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E334 * '
      CALL PPRINT(VAR%E334,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E144 * '
      CALL PPRINT(VAR%E144,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E244 * '
      CALL PPRINT(VAR%E244,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E344 * '
      CALL PPRINT(VAR%E344,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E444 * '
      CALL PPRINT(VAR%E444,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E115 * '
      CALL PPRINT(VAR%E115,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E125 * '
      CALL PPRINT(VAR%E125,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E225 * '
      CALL PPRINT(VAR%E225,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E135 * '
      CALL PPRINT(VAR%E135,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E235 * '
      CALL PPRINT(VAR%E235,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E335 * '
      CALL PPRINT(VAR%E335,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E145 * '
      CALL PPRINT(VAR%E145,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E245 * '
      CALL PPRINT(VAR%E245,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E345 * '
      CALL PPRINT(VAR%E345,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E445 * '
      CALL PPRINT(VAR%E445,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E155 * '
      CALL PPRINT(VAR%E155,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E255 * '
      CALL PPRINT(VAR%E255,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E355 * '
      CALL PPRINT(VAR%E355,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E455 * '
      CALL PPRINT(VAR%E455,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E555 * '
      CALL PPRINT(VAR%E555,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E116 * '
      CALL PPRINT(VAR%E116,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E126 * '
      CALL PPRINT(VAR%E126,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E226 * '
      CALL PPRINT(VAR%E226,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E136 * '
      CALL PPRINT(VAR%E136,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E236 * '
      CALL PPRINT(VAR%E236,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E336 * '
      CALL PPRINT(VAR%E336,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E146 * '
      CALL PPRINT(VAR%E146,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E246 * '
      CALL PPRINT(VAR%E246,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E346 * '
      CALL PPRINT(VAR%E346,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E446 * '
      CALL PPRINT(VAR%E446,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E156 * '
      CALL PPRINT(VAR%E156,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E256 * '
      CALL PPRINT(VAR%E256,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E356 * '
      CALL PPRINT(VAR%E356,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E456 * '
      CALL PPRINT(VAR%E456,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E556 * '
      CALL PPRINT(VAR%E556,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E166 * '
      CALL PPRINT(VAR%E166,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E266 * '
      CALL PPRINT(VAR%E266,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E366 * '
      CALL PPRINT(VAR%E366,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E466 * '
      CALL PPRINT(VAR%E466,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E566 * '
      CALL PPRINT(VAR%E566,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E666 * '
      CALL PPRINT(VAR%E666,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E117 * '
      CALL PPRINT(VAR%E117,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E127 * '
      CALL PPRINT(VAR%E127,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E227 * '
      CALL PPRINT(VAR%E227,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E137 * '
      CALL PPRINT(VAR%E137,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E237 * '
      CALL PPRINT(VAR%E237,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E337 * '
      CALL PPRINT(VAR%E337,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E147 * '
      CALL PPRINT(VAR%E147,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E247 * '
      CALL PPRINT(VAR%E247,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E347 * '
      CALL PPRINT(VAR%E347,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E447 * '
      CALL PPRINT(VAR%E447,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E157 * '
      CALL PPRINT(VAR%E157,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E257 * '
      CALL PPRINT(VAR%E257,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E357 * '
      CALL PPRINT(VAR%E357,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E457 * '
      CALL PPRINT(VAR%E457,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E557 * '
      CALL PPRINT(VAR%E557,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E167 * '
      CALL PPRINT(VAR%E167,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E267 * '
      CALL PPRINT(VAR%E267,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E367 * '
      CALL PPRINT(VAR%E367,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E467 * '
      CALL PPRINT(VAR%E467,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E567 * '
      CALL PPRINT(VAR%E567,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E667 * '
      CALL PPRINT(VAR%E667,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E177 * '
      CALL PPRINT(VAR%E177,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E277 * '
      CALL PPRINT(VAR%E277,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E377 * '
      CALL PPRINT(VAR%E377,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E477 * '
      CALL PPRINT(VAR%E477,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E577 * '
      CALL PPRINT(VAR%E577,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E677 * '
      CALL PPRINT(VAR%E677,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E777 * '
      CALL PPRINT(VAR%E777,unit=unt,fmt=output_format)


   END SUBROUTINE ONUMM7N3_PPRINT_M

   ELEMENTAL FUNCTION ONUMM7N3_FEVAL(X,DER0,DER1,DER2,DER3)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: FACTOR, COEF
      TYPE(ONUMM7N3), INTENT(IN)  :: X
      REAL(DP), INTENT(IN)  :: DER0,DER1,DER2,DER3
      TYPE(ONUMM7N3) :: RES
      TYPE(ONUMM7N3) :: DX, DX_P

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
      RES%E112 = RES%E112+COEF*DX_P%E112
      RES%E122 = RES%E122+COEF*DX_P%E122
      RES%E222 = RES%E222+COEF*DX_P%E222
      RES%E113 = RES%E113+COEF*DX_P%E113
      RES%E123 = RES%E123+COEF*DX_P%E123
      RES%E223 = RES%E223+COEF*DX_P%E223
      RES%E133 = RES%E133+COEF*DX_P%E133
      RES%E233 = RES%E233+COEF*DX_P%E233
      RES%E333 = RES%E333+COEF*DX_P%E333
      RES%E114 = RES%E114+COEF*DX_P%E114
      RES%E124 = RES%E124+COEF*DX_P%E124
      RES%E224 = RES%E224+COEF*DX_P%E224
      RES%E134 = RES%E134+COEF*DX_P%E134
      RES%E234 = RES%E234+COEF*DX_P%E234
      RES%E334 = RES%E334+COEF*DX_P%E334
      RES%E144 = RES%E144+COEF*DX_P%E144
      RES%E244 = RES%E244+COEF*DX_P%E244
      RES%E344 = RES%E344+COEF*DX_P%E344
      RES%E444 = RES%E444+COEF*DX_P%E444
      RES%E115 = RES%E115+COEF*DX_P%E115
      RES%E125 = RES%E125+COEF*DX_P%E125
      RES%E225 = RES%E225+COEF*DX_P%E225
      RES%E135 = RES%E135+COEF*DX_P%E135
      RES%E235 = RES%E235+COEF*DX_P%E235
      RES%E335 = RES%E335+COEF*DX_P%E335
      RES%E145 = RES%E145+COEF*DX_P%E145
      RES%E245 = RES%E245+COEF*DX_P%E245
      RES%E345 = RES%E345+COEF*DX_P%E345
      RES%E445 = RES%E445+COEF*DX_P%E445
      RES%E155 = RES%E155+COEF*DX_P%E155
      RES%E255 = RES%E255+COEF*DX_P%E255
      RES%E355 = RES%E355+COEF*DX_P%E355
      RES%E455 = RES%E455+COEF*DX_P%E455
      RES%E555 = RES%E555+COEF*DX_P%E555
      RES%E116 = RES%E116+COEF*DX_P%E116
      RES%E126 = RES%E126+COEF*DX_P%E126
      RES%E226 = RES%E226+COEF*DX_P%E226
      RES%E136 = RES%E136+COEF*DX_P%E136
      RES%E236 = RES%E236+COEF*DX_P%E236
      RES%E336 = RES%E336+COEF*DX_P%E336
      RES%E146 = RES%E146+COEF*DX_P%E146
      RES%E246 = RES%E246+COEF*DX_P%E246
      RES%E346 = RES%E346+COEF*DX_P%E346
      RES%E446 = RES%E446+COEF*DX_P%E446
      RES%E156 = RES%E156+COEF*DX_P%E156
      RES%E256 = RES%E256+COEF*DX_P%E256
      RES%E356 = RES%E356+COEF*DX_P%E356
      RES%E456 = RES%E456+COEF*DX_P%E456
      RES%E556 = RES%E556+COEF*DX_P%E556
      RES%E166 = RES%E166+COEF*DX_P%E166
      RES%E266 = RES%E266+COEF*DX_P%E266
      RES%E366 = RES%E366+COEF*DX_P%E366
      RES%E466 = RES%E466+COEF*DX_P%E466
      RES%E566 = RES%E566+COEF*DX_P%E566
      RES%E666 = RES%E666+COEF*DX_P%E666
      RES%E117 = RES%E117+COEF*DX_P%E117
      RES%E127 = RES%E127+COEF*DX_P%E127
      RES%E227 = RES%E227+COEF*DX_P%E227
      RES%E137 = RES%E137+COEF*DX_P%E137
      RES%E237 = RES%E237+COEF*DX_P%E237
      RES%E337 = RES%E337+COEF*DX_P%E337
      RES%E147 = RES%E147+COEF*DX_P%E147
      RES%E247 = RES%E247+COEF*DX_P%E247
      RES%E347 = RES%E347+COEF*DX_P%E347
      RES%E447 = RES%E447+COEF*DX_P%E447
      RES%E157 = RES%E157+COEF*DX_P%E157
      RES%E257 = RES%E257+COEF*DX_P%E257
      RES%E357 = RES%E357+COEF*DX_P%E357
      RES%E457 = RES%E457+COEF*DX_P%E457
      RES%E557 = RES%E557+COEF*DX_P%E557
      RES%E167 = RES%E167+COEF*DX_P%E167
      RES%E267 = RES%E267+COEF*DX_P%E267
      RES%E367 = RES%E367+COEF*DX_P%E367
      RES%E467 = RES%E467+COEF*DX_P%E467
      RES%E567 = RES%E567+COEF*DX_P%E567
      RES%E667 = RES%E667+COEF*DX_P%E667
      RES%E177 = RES%E177+COEF*DX_P%E177
      RES%E277 = RES%E277+COEF*DX_P%E277
      RES%E377 = RES%E377+COEF*DX_P%E377
      RES%E477 = RES%E477+COEF*DX_P%E477
      RES%E577 = RES%E577+COEF*DX_P%E577
      RES%E677 = RES%E677+COEF*DX_P%E677
      RES%E777 = RES%E777+COEF*DX_P%E777
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
      ! Order 3
      DX_P%E111 = DX_P%E1*DX%E11+DX_P%E11*DX%E1
      DX_P%E112 = DX_P%E1*DX%E12+DX_P%E12*DX%E1+ &
               DX_P%E2*DX%E11+DX_P%E11*DX%E2
      DX_P%E122 = DX_P%E1*DX%E22+DX_P%E22*DX%E1+ &
               DX_P%E2*DX%E12+DX_P%E12*DX%E2
      DX_P%E222 = DX_P%E2*DX%E22+DX_P%E22*DX%E2
      DX_P%E113 = DX_P%E1*DX%E13+DX_P%E13*DX%E1+ &
               DX_P%E3*DX%E11+DX_P%E11*DX%E3
      DX_P%E123 = DX_P%E1*DX%E23+DX_P%E23*DX%E1+ &
               DX_P%E2*DX%E13+DX_P%E13*DX%E2+DX_P%E3*DX%E12+ &
               DX_P%E12*DX%E3
      DX_P%E223 = DX_P%E2*DX%E23+DX_P%E23*DX%E2+ &
               DX_P%E3*DX%E22+DX_P%E22*DX%E3
      DX_P%E133 = DX_P%E1*DX%E33+DX_P%E33*DX%E1+ &
               DX_P%E3*DX%E13+DX_P%E13*DX%E3
      DX_P%E233 = DX_P%E2*DX%E33+DX_P%E33*DX%E2+ &
               DX_P%E3*DX%E23+DX_P%E23*DX%E3
      DX_P%E333 = DX_P%E3*DX%E33+DX_P%E33*DX%E3
      DX_P%E114 = DX_P%E1*DX%E14+DX_P%E14*DX%E1+ &
               DX_P%E4*DX%E11+DX_P%E11*DX%E4
      DX_P%E124 = DX_P%E1*DX%E24+DX_P%E24*DX%E1+ &
               DX_P%E2*DX%E14+DX_P%E14*DX%E2+DX_P%E4*DX%E12+ &
               DX_P%E12*DX%E4
      DX_P%E224 = DX_P%E2*DX%E24+DX_P%E24*DX%E2+ &
               DX_P%E4*DX%E22+DX_P%E22*DX%E4
      DX_P%E134 = DX_P%E1*DX%E34+DX_P%E34*DX%E1+ &
               DX_P%E3*DX%E14+DX_P%E14*DX%E3+DX_P%E4*DX%E13+ &
               DX_P%E13*DX%E4
      DX_P%E234 = DX_P%E2*DX%E34+DX_P%E34*DX%E2+ &
               DX_P%E3*DX%E24+DX_P%E24*DX%E3+DX_P%E4*DX%E23+ &
               DX_P%E23*DX%E4
      DX_P%E334 = DX_P%E3*DX%E34+DX_P%E34*DX%E3+ &
               DX_P%E4*DX%E33+DX_P%E33*DX%E4
      DX_P%E144 = DX_P%E1*DX%E44+DX_P%E44*DX%E1+ &
               DX_P%E4*DX%E14+DX_P%E14*DX%E4
      DX_P%E244 = DX_P%E2*DX%E44+DX_P%E44*DX%E2+ &
               DX_P%E4*DX%E24+DX_P%E24*DX%E4
      DX_P%E344 = DX_P%E3*DX%E44+DX_P%E44*DX%E3+ &
               DX_P%E4*DX%E34+DX_P%E34*DX%E4
      DX_P%E444 = DX_P%E4*DX%E44+DX_P%E44*DX%E4
      DX_P%E115 = DX_P%E1*DX%E15+DX_P%E15*DX%E1+ &
               DX_P%E5*DX%E11+DX_P%E11*DX%E5
      DX_P%E125 = DX_P%E1*DX%E25+DX_P%E25*DX%E1+ &
               DX_P%E2*DX%E15+DX_P%E15*DX%E2+DX_P%E5*DX%E12+ &
               DX_P%E12*DX%E5
      DX_P%E225 = DX_P%E2*DX%E25+DX_P%E25*DX%E2+ &
               DX_P%E5*DX%E22+DX_P%E22*DX%E5
      DX_P%E135 = DX_P%E1*DX%E35+DX_P%E35*DX%E1+ &
               DX_P%E3*DX%E15+DX_P%E15*DX%E3+DX_P%E5*DX%E13+ &
               DX_P%E13*DX%E5
      DX_P%E235 = DX_P%E2*DX%E35+DX_P%E35*DX%E2+ &
               DX_P%E3*DX%E25+DX_P%E25*DX%E3+DX_P%E5*DX%E23+ &
               DX_P%E23*DX%E5
      DX_P%E335 = DX_P%E3*DX%E35+DX_P%E35*DX%E3+ &
               DX_P%E5*DX%E33+DX_P%E33*DX%E5
      DX_P%E145 = DX_P%E1*DX%E45+DX_P%E45*DX%E1+ &
               DX_P%E4*DX%E15+DX_P%E15*DX%E4+DX_P%E5*DX%E14+ &
               DX_P%E14*DX%E5
      DX_P%E245 = DX_P%E2*DX%E45+DX_P%E45*DX%E2+ &
               DX_P%E4*DX%E25+DX_P%E25*DX%E4+DX_P%E5*DX%E24+ &
               DX_P%E24*DX%E5
      DX_P%E345 = DX_P%E3*DX%E45+DX_P%E45*DX%E3+ &
               DX_P%E4*DX%E35+DX_P%E35*DX%E4+DX_P%E5*DX%E34+ &
               DX_P%E34*DX%E5
      DX_P%E445 = DX_P%E4*DX%E45+DX_P%E45*DX%E4+ &
               DX_P%E5*DX%E44+DX_P%E44*DX%E5
      DX_P%E155 = DX_P%E1*DX%E55+DX_P%E55*DX%E1+ &
               DX_P%E5*DX%E15+DX_P%E15*DX%E5
      DX_P%E255 = DX_P%E2*DX%E55+DX_P%E55*DX%E2+ &
               DX_P%E5*DX%E25+DX_P%E25*DX%E5
      DX_P%E355 = DX_P%E3*DX%E55+DX_P%E55*DX%E3+ &
               DX_P%E5*DX%E35+DX_P%E35*DX%E5
      DX_P%E455 = DX_P%E4*DX%E55+DX_P%E55*DX%E4+ &
               DX_P%E5*DX%E45+DX_P%E45*DX%E5
      DX_P%E555 = DX_P%E5*DX%E55+DX_P%E55*DX%E5
      DX_P%E116 = DX_P%E1*DX%E16+DX_P%E16*DX%E1+ &
               DX_P%E6*DX%E11+DX_P%E11*DX%E6
      DX_P%E126 = DX_P%E1*DX%E26+DX_P%E26*DX%E1+ &
               DX_P%E2*DX%E16+DX_P%E16*DX%E2+DX_P%E6*DX%E12+ &
               DX_P%E12*DX%E6
      DX_P%E226 = DX_P%E2*DX%E26+DX_P%E26*DX%E2+ &
               DX_P%E6*DX%E22+DX_P%E22*DX%E6
      DX_P%E136 = DX_P%E1*DX%E36+DX_P%E36*DX%E1+ &
               DX_P%E3*DX%E16+DX_P%E16*DX%E3+DX_P%E6*DX%E13+ &
               DX_P%E13*DX%E6
      DX_P%E236 = DX_P%E2*DX%E36+DX_P%E36*DX%E2+ &
               DX_P%E3*DX%E26+DX_P%E26*DX%E3+DX_P%E6*DX%E23+ &
               DX_P%E23*DX%E6
      DX_P%E336 = DX_P%E3*DX%E36+DX_P%E36*DX%E3+ &
               DX_P%E6*DX%E33+DX_P%E33*DX%E6
      DX_P%E146 = DX_P%E1*DX%E46+DX_P%E46*DX%E1+ &
               DX_P%E4*DX%E16+DX_P%E16*DX%E4+DX_P%E6*DX%E14+ &
               DX_P%E14*DX%E6
      DX_P%E246 = DX_P%E2*DX%E46+DX_P%E46*DX%E2+ &
               DX_P%E4*DX%E26+DX_P%E26*DX%E4+DX_P%E6*DX%E24+ &
               DX_P%E24*DX%E6
      DX_P%E346 = DX_P%E3*DX%E46+DX_P%E46*DX%E3+ &
               DX_P%E4*DX%E36+DX_P%E36*DX%E4+DX_P%E6*DX%E34+ &
               DX_P%E34*DX%E6
      DX_P%E446 = DX_P%E4*DX%E46+DX_P%E46*DX%E4+ &
               DX_P%E6*DX%E44+DX_P%E44*DX%E6
      DX_P%E156 = DX_P%E1*DX%E56+DX_P%E56*DX%E1+ &
               DX_P%E5*DX%E16+DX_P%E16*DX%E5+DX_P%E6*DX%E15+ &
               DX_P%E15*DX%E6
      DX_P%E256 = DX_P%E2*DX%E56+DX_P%E56*DX%E2+ &
               DX_P%E5*DX%E26+DX_P%E26*DX%E5+DX_P%E6*DX%E25+ &
               DX_P%E25*DX%E6
      DX_P%E356 = DX_P%E3*DX%E56+DX_P%E56*DX%E3+ &
               DX_P%E5*DX%E36+DX_P%E36*DX%E5+DX_P%E6*DX%E35+ &
               DX_P%E35*DX%E6
      DX_P%E456 = DX_P%E4*DX%E56+DX_P%E56*DX%E4+ &
               DX_P%E5*DX%E46+DX_P%E46*DX%E5+DX_P%E6*DX%E45+ &
               DX_P%E45*DX%E6
      DX_P%E556 = DX_P%E5*DX%E56+DX_P%E56*DX%E5+ &
               DX_P%E6*DX%E55+DX_P%E55*DX%E6
      DX_P%E166 = DX_P%E1*DX%E66+DX_P%E66*DX%E1+ &
               DX_P%E6*DX%E16+DX_P%E16*DX%E6
      DX_P%E266 = DX_P%E2*DX%E66+DX_P%E66*DX%E2+ &
               DX_P%E6*DX%E26+DX_P%E26*DX%E6
      DX_P%E366 = DX_P%E3*DX%E66+DX_P%E66*DX%E3+ &
               DX_P%E6*DX%E36+DX_P%E36*DX%E6
      DX_P%E466 = DX_P%E4*DX%E66+DX_P%E66*DX%E4+ &
               DX_P%E6*DX%E46+DX_P%E46*DX%E6
      DX_P%E566 = DX_P%E5*DX%E66+DX_P%E66*DX%E5+ &
               DX_P%E6*DX%E56+DX_P%E56*DX%E6
      DX_P%E666 = DX_P%E6*DX%E66+DX_P%E66*DX%E6
      DX_P%E117 = DX_P%E1*DX%E17+DX_P%E17*DX%E1+ &
               DX_P%E7*DX%E11+DX_P%E11*DX%E7
      DX_P%E127 = DX_P%E1*DX%E27+DX_P%E27*DX%E1+ &
               DX_P%E2*DX%E17+DX_P%E17*DX%E2+DX_P%E7*DX%E12+ &
               DX_P%E12*DX%E7
      DX_P%E227 = DX_P%E2*DX%E27+DX_P%E27*DX%E2+ &
               DX_P%E7*DX%E22+DX_P%E22*DX%E7
      DX_P%E137 = DX_P%E1*DX%E37+DX_P%E37*DX%E1+ &
               DX_P%E3*DX%E17+DX_P%E17*DX%E3+DX_P%E7*DX%E13+ &
               DX_P%E13*DX%E7
      DX_P%E237 = DX_P%E2*DX%E37+DX_P%E37*DX%E2+ &
               DX_P%E3*DX%E27+DX_P%E27*DX%E3+DX_P%E7*DX%E23+ &
               DX_P%E23*DX%E7
      DX_P%E337 = DX_P%E3*DX%E37+DX_P%E37*DX%E3+ &
               DX_P%E7*DX%E33+DX_P%E33*DX%E7
      DX_P%E147 = DX_P%E1*DX%E47+DX_P%E47*DX%E1+ &
               DX_P%E4*DX%E17+DX_P%E17*DX%E4+DX_P%E7*DX%E14+ &
               DX_P%E14*DX%E7
      DX_P%E247 = DX_P%E2*DX%E47+DX_P%E47*DX%E2+ &
               DX_P%E4*DX%E27+DX_P%E27*DX%E4+DX_P%E7*DX%E24+ &
               DX_P%E24*DX%E7
      DX_P%E347 = DX_P%E3*DX%E47+DX_P%E47*DX%E3+ &
               DX_P%E4*DX%E37+DX_P%E37*DX%E4+DX_P%E7*DX%E34+ &
               DX_P%E34*DX%E7
      DX_P%E447 = DX_P%E4*DX%E47+DX_P%E47*DX%E4+ &
               DX_P%E7*DX%E44+DX_P%E44*DX%E7
      DX_P%E157 = DX_P%E1*DX%E57+DX_P%E57*DX%E1+ &
               DX_P%E5*DX%E17+DX_P%E17*DX%E5+DX_P%E7*DX%E15+ &
               DX_P%E15*DX%E7
      DX_P%E257 = DX_P%E2*DX%E57+DX_P%E57*DX%E2+ &
               DX_P%E5*DX%E27+DX_P%E27*DX%E5+DX_P%E7*DX%E25+ &
               DX_P%E25*DX%E7
      DX_P%E357 = DX_P%E3*DX%E57+DX_P%E57*DX%E3+ &
               DX_P%E5*DX%E37+DX_P%E37*DX%E5+DX_P%E7*DX%E35+ &
               DX_P%E35*DX%E7
      DX_P%E457 = DX_P%E4*DX%E57+DX_P%E57*DX%E4+ &
               DX_P%E5*DX%E47+DX_P%E47*DX%E5+DX_P%E7*DX%E45+ &
               DX_P%E45*DX%E7
      DX_P%E557 = DX_P%E5*DX%E57+DX_P%E57*DX%E5+ &
               DX_P%E7*DX%E55+DX_P%E55*DX%E7
      DX_P%E167 = DX_P%E1*DX%E67+DX_P%E67*DX%E1+ &
               DX_P%E6*DX%E17+DX_P%E17*DX%E6+DX_P%E7*DX%E16+ &
               DX_P%E16*DX%E7
      DX_P%E267 = DX_P%E2*DX%E67+DX_P%E67*DX%E2+ &
               DX_P%E6*DX%E27+DX_P%E27*DX%E6+DX_P%E7*DX%E26+ &
               DX_P%E26*DX%E7
      DX_P%E367 = DX_P%E3*DX%E67+DX_P%E67*DX%E3+ &
               DX_P%E6*DX%E37+DX_P%E37*DX%E6+DX_P%E7*DX%E36+ &
               DX_P%E36*DX%E7
      DX_P%E467 = DX_P%E4*DX%E67+DX_P%E67*DX%E4+ &
               DX_P%E6*DX%E47+DX_P%E47*DX%E6+DX_P%E7*DX%E46+ &
               DX_P%E46*DX%E7
      DX_P%E567 = DX_P%E5*DX%E67+DX_P%E67*DX%E5+ &
               DX_P%E6*DX%E57+DX_P%E57*DX%E6+DX_P%E7*DX%E56+ &
               DX_P%E56*DX%E7
      DX_P%E667 = DX_P%E6*DX%E67+DX_P%E67*DX%E6+ &
               DX_P%E7*DX%E66+DX_P%E66*DX%E7
      DX_P%E177 = DX_P%E1*DX%E77+DX_P%E77*DX%E1+ &
               DX_P%E7*DX%E17+DX_P%E17*DX%E7
      DX_P%E277 = DX_P%E2*DX%E77+DX_P%E77*DX%E2+ &
               DX_P%E7*DX%E27+DX_P%E27*DX%E7
      DX_P%E377 = DX_P%E3*DX%E77+DX_P%E77*DX%E3+ &
               DX_P%E7*DX%E37+DX_P%E37*DX%E7
      DX_P%E477 = DX_P%E4*DX%E77+DX_P%E77*DX%E4+ &
               DX_P%E7*DX%E47+DX_P%E47*DX%E7
      DX_P%E577 = DX_P%E5*DX%E77+DX_P%E77*DX%E5+ &
               DX_P%E7*DX%E57+DX_P%E57*DX%E7
      DX_P%E677 = DX_P%E6*DX%E77+DX_P%E77*DX%E6+ &
               DX_P%E7*DX%E67+DX_P%E67*DX%E7
      DX_P%E777 = DX_P%E7*DX%E77+DX_P%E77*DX%E7
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
      ! Order 3
      RES%E111 = RES%E111+COEF*DX_P%E111
      RES%E112 = RES%E112+COEF*DX_P%E112
      RES%E122 = RES%E122+COEF*DX_P%E122
      RES%E222 = RES%E222+COEF*DX_P%E222
      RES%E113 = RES%E113+COEF*DX_P%E113
      RES%E123 = RES%E123+COEF*DX_P%E123
      RES%E223 = RES%E223+COEF*DX_P%E223
      RES%E133 = RES%E133+COEF*DX_P%E133
      RES%E233 = RES%E233+COEF*DX_P%E233
      RES%E333 = RES%E333+COEF*DX_P%E333
      RES%E114 = RES%E114+COEF*DX_P%E114
      RES%E124 = RES%E124+COEF*DX_P%E124
      RES%E224 = RES%E224+COEF*DX_P%E224
      RES%E134 = RES%E134+COEF*DX_P%E134
      RES%E234 = RES%E234+COEF*DX_P%E234
      RES%E334 = RES%E334+COEF*DX_P%E334
      RES%E144 = RES%E144+COEF*DX_P%E144
      RES%E244 = RES%E244+COEF*DX_P%E244
      RES%E344 = RES%E344+COEF*DX_P%E344
      RES%E444 = RES%E444+COEF*DX_P%E444
      RES%E115 = RES%E115+COEF*DX_P%E115
      RES%E125 = RES%E125+COEF*DX_P%E125
      RES%E225 = RES%E225+COEF*DX_P%E225
      RES%E135 = RES%E135+COEF*DX_P%E135
      RES%E235 = RES%E235+COEF*DX_P%E235
      RES%E335 = RES%E335+COEF*DX_P%E335
      RES%E145 = RES%E145+COEF*DX_P%E145
      RES%E245 = RES%E245+COEF*DX_P%E245
      RES%E345 = RES%E345+COEF*DX_P%E345
      RES%E445 = RES%E445+COEF*DX_P%E445
      RES%E155 = RES%E155+COEF*DX_P%E155
      RES%E255 = RES%E255+COEF*DX_P%E255
      RES%E355 = RES%E355+COEF*DX_P%E355
      RES%E455 = RES%E455+COEF*DX_P%E455
      RES%E555 = RES%E555+COEF*DX_P%E555
      RES%E116 = RES%E116+COEF*DX_P%E116
      RES%E126 = RES%E126+COEF*DX_P%E126
      RES%E226 = RES%E226+COEF*DX_P%E226
      RES%E136 = RES%E136+COEF*DX_P%E136
      RES%E236 = RES%E236+COEF*DX_P%E236
      RES%E336 = RES%E336+COEF*DX_P%E336
      RES%E146 = RES%E146+COEF*DX_P%E146
      RES%E246 = RES%E246+COEF*DX_P%E246
      RES%E346 = RES%E346+COEF*DX_P%E346
      RES%E446 = RES%E446+COEF*DX_P%E446
      RES%E156 = RES%E156+COEF*DX_P%E156
      RES%E256 = RES%E256+COEF*DX_P%E256
      RES%E356 = RES%E356+COEF*DX_P%E356
      RES%E456 = RES%E456+COEF*DX_P%E456
      RES%E556 = RES%E556+COEF*DX_P%E556
      RES%E166 = RES%E166+COEF*DX_P%E166
      RES%E266 = RES%E266+COEF*DX_P%E266
      RES%E366 = RES%E366+COEF*DX_P%E366
      RES%E466 = RES%E466+COEF*DX_P%E466
      RES%E566 = RES%E566+COEF*DX_P%E566
      RES%E666 = RES%E666+COEF*DX_P%E666
      RES%E117 = RES%E117+COEF*DX_P%E117
      RES%E127 = RES%E127+COEF*DX_P%E127
      RES%E227 = RES%E227+COEF*DX_P%E227
      RES%E137 = RES%E137+COEF*DX_P%E137
      RES%E237 = RES%E237+COEF*DX_P%E237
      RES%E337 = RES%E337+COEF*DX_P%E337
      RES%E147 = RES%E147+COEF*DX_P%E147
      RES%E247 = RES%E247+COEF*DX_P%E247
      RES%E347 = RES%E347+COEF*DX_P%E347
      RES%E447 = RES%E447+COEF*DX_P%E447
      RES%E157 = RES%E157+COEF*DX_P%E157
      RES%E257 = RES%E257+COEF*DX_P%E257
      RES%E357 = RES%E357+COEF*DX_P%E357
      RES%E457 = RES%E457+COEF*DX_P%E457
      RES%E557 = RES%E557+COEF*DX_P%E557
      RES%E167 = RES%E167+COEF*DX_P%E167
      RES%E267 = RES%E267+COEF*DX_P%E267
      RES%E367 = RES%E367+COEF*DX_P%E367
      RES%E467 = RES%E467+COEF*DX_P%E467
      RES%E567 = RES%E567+COEF*DX_P%E567
      RES%E667 = RES%E667+COEF*DX_P%E667
      RES%E177 = RES%E177+COEF*DX_P%E177
      RES%E277 = RES%E277+COEF*DX_P%E277
      RES%E377 = RES%E377+COEF*DX_P%E377
      RES%E477 = RES%E477+COEF*DX_P%E477
      RES%E577 = RES%E577+COEF*DX_P%E577
      RES%E677 = RES%E677+COEF*DX_P%E677
      RES%E777 = RES%E777+COEF*DX_P%E777
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
      ! DX_P = DX_P * DX
      ! Order 3
      DX_P%E111 = DX_P%E11*DX%E1
      DX_P%E112 = DX_P%E12*DX%E1+DX_P%E11*DX%E2
      DX_P%E122 = DX_P%E22*DX%E1+DX_P%E12*DX%E2
      DX_P%E222 = DX_P%E22*DX%E2
      DX_P%E113 = DX_P%E13*DX%E1+DX_P%E11*DX%E3
      DX_P%E123 = DX_P%E23*DX%E1+DX_P%E13*DX%E2+ &
               DX_P%E12*DX%E3
      DX_P%E223 = DX_P%E23*DX%E2+DX_P%E22*DX%E3
      DX_P%E133 = DX_P%E33*DX%E1+DX_P%E13*DX%E3
      DX_P%E233 = DX_P%E33*DX%E2+DX_P%E23*DX%E3
      DX_P%E333 = DX_P%E33*DX%E3
      DX_P%E114 = DX_P%E14*DX%E1+DX_P%E11*DX%E4
      DX_P%E124 = DX_P%E24*DX%E1+DX_P%E14*DX%E2+ &
               DX_P%E12*DX%E4
      DX_P%E224 = DX_P%E24*DX%E2+DX_P%E22*DX%E4
      DX_P%E134 = DX_P%E34*DX%E1+DX_P%E14*DX%E3+ &
               DX_P%E13*DX%E4
      DX_P%E234 = DX_P%E34*DX%E2+DX_P%E24*DX%E3+ &
               DX_P%E23*DX%E4
      DX_P%E334 = DX_P%E34*DX%E3+DX_P%E33*DX%E4
      DX_P%E144 = DX_P%E44*DX%E1+DX_P%E14*DX%E4
      DX_P%E244 = DX_P%E44*DX%E2+DX_P%E24*DX%E4
      DX_P%E344 = DX_P%E44*DX%E3+DX_P%E34*DX%E4
      DX_P%E444 = DX_P%E44*DX%E4
      DX_P%E115 = DX_P%E15*DX%E1+DX_P%E11*DX%E5
      DX_P%E125 = DX_P%E25*DX%E1+DX_P%E15*DX%E2+ &
               DX_P%E12*DX%E5
      DX_P%E225 = DX_P%E25*DX%E2+DX_P%E22*DX%E5
      DX_P%E135 = DX_P%E35*DX%E1+DX_P%E15*DX%E3+ &
               DX_P%E13*DX%E5
      DX_P%E235 = DX_P%E35*DX%E2+DX_P%E25*DX%E3+ &
               DX_P%E23*DX%E5
      DX_P%E335 = DX_P%E35*DX%E3+DX_P%E33*DX%E5
      DX_P%E145 = DX_P%E45*DX%E1+DX_P%E15*DX%E4+ &
               DX_P%E14*DX%E5
      DX_P%E245 = DX_P%E45*DX%E2+DX_P%E25*DX%E4+ &
               DX_P%E24*DX%E5
      DX_P%E345 = DX_P%E45*DX%E3+DX_P%E35*DX%E4+ &
               DX_P%E34*DX%E5
      DX_P%E445 = DX_P%E45*DX%E4+DX_P%E44*DX%E5
      DX_P%E155 = DX_P%E55*DX%E1+DX_P%E15*DX%E5
      DX_P%E255 = DX_P%E55*DX%E2+DX_P%E25*DX%E5
      DX_P%E355 = DX_P%E55*DX%E3+DX_P%E35*DX%E5
      DX_P%E455 = DX_P%E55*DX%E4+DX_P%E45*DX%E5
      DX_P%E555 = DX_P%E55*DX%E5
      DX_P%E116 = DX_P%E16*DX%E1+DX_P%E11*DX%E6
      DX_P%E126 = DX_P%E26*DX%E1+DX_P%E16*DX%E2+ &
               DX_P%E12*DX%E6
      DX_P%E226 = DX_P%E26*DX%E2+DX_P%E22*DX%E6
      DX_P%E136 = DX_P%E36*DX%E1+DX_P%E16*DX%E3+ &
               DX_P%E13*DX%E6
      DX_P%E236 = DX_P%E36*DX%E2+DX_P%E26*DX%E3+ &
               DX_P%E23*DX%E6
      DX_P%E336 = DX_P%E36*DX%E3+DX_P%E33*DX%E6
      DX_P%E146 = DX_P%E46*DX%E1+DX_P%E16*DX%E4+ &
               DX_P%E14*DX%E6
      DX_P%E246 = DX_P%E46*DX%E2+DX_P%E26*DX%E4+ &
               DX_P%E24*DX%E6
      DX_P%E346 = DX_P%E46*DX%E3+DX_P%E36*DX%E4+ &
               DX_P%E34*DX%E6
      DX_P%E446 = DX_P%E46*DX%E4+DX_P%E44*DX%E6
      DX_P%E156 = DX_P%E56*DX%E1+DX_P%E16*DX%E5+ &
               DX_P%E15*DX%E6
      DX_P%E256 = DX_P%E56*DX%E2+DX_P%E26*DX%E5+ &
               DX_P%E25*DX%E6
      DX_P%E356 = DX_P%E56*DX%E3+DX_P%E36*DX%E5+ &
               DX_P%E35*DX%E6
      DX_P%E456 = DX_P%E56*DX%E4+DX_P%E46*DX%E5+ &
               DX_P%E45*DX%E6
      DX_P%E556 = DX_P%E56*DX%E5+DX_P%E55*DX%E6
      DX_P%E166 = DX_P%E66*DX%E1+DX_P%E16*DX%E6
      DX_P%E266 = DX_P%E66*DX%E2+DX_P%E26*DX%E6
      DX_P%E366 = DX_P%E66*DX%E3+DX_P%E36*DX%E6
      DX_P%E466 = DX_P%E66*DX%E4+DX_P%E46*DX%E6
      DX_P%E566 = DX_P%E66*DX%E5+DX_P%E56*DX%E6
      DX_P%E666 = DX_P%E66*DX%E6
      DX_P%E117 = DX_P%E17*DX%E1+DX_P%E11*DX%E7
      DX_P%E127 = DX_P%E27*DX%E1+DX_P%E17*DX%E2+ &
               DX_P%E12*DX%E7
      DX_P%E227 = DX_P%E27*DX%E2+DX_P%E22*DX%E7
      DX_P%E137 = DX_P%E37*DX%E1+DX_P%E17*DX%E3+ &
               DX_P%E13*DX%E7
      DX_P%E237 = DX_P%E37*DX%E2+DX_P%E27*DX%E3+ &
               DX_P%E23*DX%E7
      DX_P%E337 = DX_P%E37*DX%E3+DX_P%E33*DX%E7
      DX_P%E147 = DX_P%E47*DX%E1+DX_P%E17*DX%E4+ &
               DX_P%E14*DX%E7
      DX_P%E247 = DX_P%E47*DX%E2+DX_P%E27*DX%E4+ &
               DX_P%E24*DX%E7
      DX_P%E347 = DX_P%E47*DX%E3+DX_P%E37*DX%E4+ &
               DX_P%E34*DX%E7
      DX_P%E447 = DX_P%E47*DX%E4+DX_P%E44*DX%E7
      DX_P%E157 = DX_P%E57*DX%E1+DX_P%E17*DX%E5+ &
               DX_P%E15*DX%E7
      DX_P%E257 = DX_P%E57*DX%E2+DX_P%E27*DX%E5+ &
               DX_P%E25*DX%E7
      DX_P%E357 = DX_P%E57*DX%E3+DX_P%E37*DX%E5+ &
               DX_P%E35*DX%E7
      DX_P%E457 = DX_P%E57*DX%E4+DX_P%E47*DX%E5+ &
               DX_P%E45*DX%E7
      DX_P%E557 = DX_P%E57*DX%E5+DX_P%E55*DX%E7
      DX_P%E167 = DX_P%E67*DX%E1+DX_P%E17*DX%E6+ &
               DX_P%E16*DX%E7
      DX_P%E267 = DX_P%E67*DX%E2+DX_P%E27*DX%E6+ &
               DX_P%E26*DX%E7
      DX_P%E367 = DX_P%E67*DX%E3+DX_P%E37*DX%E6+ &
               DX_P%E36*DX%E7
      DX_P%E467 = DX_P%E67*DX%E4+DX_P%E47*DX%E6+ &
               DX_P%E46*DX%E7
      DX_P%E567 = DX_P%E67*DX%E5+DX_P%E57*DX%E6+ &
               DX_P%E56*DX%E7
      DX_P%E667 = DX_P%E67*DX%E6+DX_P%E66*DX%E7
      DX_P%E177 = DX_P%E77*DX%E1+DX_P%E17*DX%E7
      DX_P%E277 = DX_P%E77*DX%E2+DX_P%E27*DX%E7
      DX_P%E377 = DX_P%E77*DX%E3+DX_P%E37*DX%E7
      DX_P%E477 = DX_P%E77*DX%E4+DX_P%E47*DX%E7
      DX_P%E577 = DX_P%E77*DX%E5+DX_P%E57*DX%E7
      DX_P%E677 = DX_P%E77*DX%E6+DX_P%E67*DX%E7
      DX_P%E777 = DX_P%E77*DX%E7
      
      ! Sets order 3
      FACTOR = FACTOR * 3
      COEF = DER3 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 3
      RES%E111 = RES%E111+COEF*DX_P%E111
      RES%E112 = RES%E112+COEF*DX_P%E112
      RES%E122 = RES%E122+COEF*DX_P%E122
      RES%E222 = RES%E222+COEF*DX_P%E222
      RES%E113 = RES%E113+COEF*DX_P%E113
      RES%E123 = RES%E123+COEF*DX_P%E123
      RES%E223 = RES%E223+COEF*DX_P%E223
      RES%E133 = RES%E133+COEF*DX_P%E133
      RES%E233 = RES%E233+COEF*DX_P%E233
      RES%E333 = RES%E333+COEF*DX_P%E333
      RES%E114 = RES%E114+COEF*DX_P%E114
      RES%E124 = RES%E124+COEF*DX_P%E124
      RES%E224 = RES%E224+COEF*DX_P%E224
      RES%E134 = RES%E134+COEF*DX_P%E134
      RES%E234 = RES%E234+COEF*DX_P%E234
      RES%E334 = RES%E334+COEF*DX_P%E334
      RES%E144 = RES%E144+COEF*DX_P%E144
      RES%E244 = RES%E244+COEF*DX_P%E244
      RES%E344 = RES%E344+COEF*DX_P%E344
      RES%E444 = RES%E444+COEF*DX_P%E444
      RES%E115 = RES%E115+COEF*DX_P%E115
      RES%E125 = RES%E125+COEF*DX_P%E125
      RES%E225 = RES%E225+COEF*DX_P%E225
      RES%E135 = RES%E135+COEF*DX_P%E135
      RES%E235 = RES%E235+COEF*DX_P%E235
      RES%E335 = RES%E335+COEF*DX_P%E335
      RES%E145 = RES%E145+COEF*DX_P%E145
      RES%E245 = RES%E245+COEF*DX_P%E245
      RES%E345 = RES%E345+COEF*DX_P%E345
      RES%E445 = RES%E445+COEF*DX_P%E445
      RES%E155 = RES%E155+COEF*DX_P%E155
      RES%E255 = RES%E255+COEF*DX_P%E255
      RES%E355 = RES%E355+COEF*DX_P%E355
      RES%E455 = RES%E455+COEF*DX_P%E455
      RES%E555 = RES%E555+COEF*DX_P%E555
      RES%E116 = RES%E116+COEF*DX_P%E116
      RES%E126 = RES%E126+COEF*DX_P%E126
      RES%E226 = RES%E226+COEF*DX_P%E226
      RES%E136 = RES%E136+COEF*DX_P%E136
      RES%E236 = RES%E236+COEF*DX_P%E236
      RES%E336 = RES%E336+COEF*DX_P%E336
      RES%E146 = RES%E146+COEF*DX_P%E146
      RES%E246 = RES%E246+COEF*DX_P%E246
      RES%E346 = RES%E346+COEF*DX_P%E346
      RES%E446 = RES%E446+COEF*DX_P%E446
      RES%E156 = RES%E156+COEF*DX_P%E156
      RES%E256 = RES%E256+COEF*DX_P%E256
      RES%E356 = RES%E356+COEF*DX_P%E356
      RES%E456 = RES%E456+COEF*DX_P%E456
      RES%E556 = RES%E556+COEF*DX_P%E556
      RES%E166 = RES%E166+COEF*DX_P%E166
      RES%E266 = RES%E266+COEF*DX_P%E266
      RES%E366 = RES%E366+COEF*DX_P%E366
      RES%E466 = RES%E466+COEF*DX_P%E466
      RES%E566 = RES%E566+COEF*DX_P%E566
      RES%E666 = RES%E666+COEF*DX_P%E666
      RES%E117 = RES%E117+COEF*DX_P%E117
      RES%E127 = RES%E127+COEF*DX_P%E127
      RES%E227 = RES%E227+COEF*DX_P%E227
      RES%E137 = RES%E137+COEF*DX_P%E137
      RES%E237 = RES%E237+COEF*DX_P%E237
      RES%E337 = RES%E337+COEF*DX_P%E337
      RES%E147 = RES%E147+COEF*DX_P%E147
      RES%E247 = RES%E247+COEF*DX_P%E247
      RES%E347 = RES%E347+COEF*DX_P%E347
      RES%E447 = RES%E447+COEF*DX_P%E447
      RES%E157 = RES%E157+COEF*DX_P%E157
      RES%E257 = RES%E257+COEF*DX_P%E257
      RES%E357 = RES%E357+COEF*DX_P%E357
      RES%E457 = RES%E457+COEF*DX_P%E457
      RES%E557 = RES%E557+COEF*DX_P%E557
      RES%E167 = RES%E167+COEF*DX_P%E167
      RES%E267 = RES%E267+COEF*DX_P%E267
      RES%E367 = RES%E367+COEF*DX_P%E367
      RES%E467 = RES%E467+COEF*DX_P%E467
      RES%E567 = RES%E567+COEF*DX_P%E567
      RES%E667 = RES%E667+COEF*DX_P%E667
      RES%E177 = RES%E177+COEF*DX_P%E177
      RES%E277 = RES%E277+COEF*DX_P%E277
      RES%E377 = RES%E377+COEF*DX_P%E377
      RES%E477 = RES%E477+COEF*DX_P%E477
      RES%E577 = RES%E577+COEF*DX_P%E577
      RES%E677 = RES%E677+COEF*DX_P%E677
      RES%E777 = RES%E777+COEF*DX_P%E777
      
   END FUNCTION ONUMM7N3_FEVAL


  ! SUBROUTINE ONUMM7N3_PPRINT_M_R(X, FMT)
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

  ! END SUBROUTINE ONUMM7N3_PPRINT_M_R

  ! SUBROUTINE ONUMM7N3_PPRINT_V_R(X, FMT)
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

  ! END SUBROUTINE ONUMM7N3_PPRINT_V_R

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
  PURE FUNCTION ONUMM7N3_det2x2(A) RESULT(det)

    IMPLICIT NONE

    TYPE(ONUMM7N3), INTENT(IN) :: A(2,2)   !! Matrix
    TYPE(ONUMM7N3)             :: det

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
  PURE FUNCTION ONUMM7N3_det3x3(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(ONUMM7N3), INTENT(IN) :: A(3,3)   !! Matrix
    TYPE(ONUMM7N3)             :: det

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
  PURE FUNCTION ONUMM7N3_det4x4(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(ONUMM7N3), INTENT(IN) :: A(4,4)   !! Matrix
    TYPE(ONUMM7N3)             :: det

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
  PURE FUNCTION ONUMM7N3_cross3(a,b) RESULT(v)
      
    IMPLICIT NONE 

    TYPE(ONUMM7N3), DIMENSION (3),INTENT(IN) :: a,b
    TYPE(ONUMM7N3), DIMENSION (3) :: v
    
    v(1) = a(2) * b(3) - a(3) * b(2)
    v(2) = a(3) * b(1) - a(1) * b(3)
    v(3) = a(1) * b(2) - a(2) * b(1)

  END FUNCTION ONUMM7N3_cross3
  !===================================================================================================! 

  !***************************************************************************************************! 
  !> @brief Norm of a 3 element vector. # There is an intrinsic function named norm2.
  !!
  !! @param[in] a: Vector of 3 reals (rank 1).
  !! @param[in] b: Vector of 3 reals (rank 1).
  !!
  !***************************************************************************************************!
  FUNCTION ONUMM7N3_norm2_3(v) RESULT(n)
     
    IMPLICIT NONE 

    TYPE(ONUMM7N3), INTENT(IN) :: v(3)
    TYPE(ONUMM7N3) :: n
     
    n = SQRT( v(1)*v(1) + v(2)*v(2) + v(3)*v(3) )

  END FUNCTION ONUMM7N3_norm2_3
  !===================================================================================================! 

  ELEMENTAL FUNCTION ONUMM7N3_DIVISION_OO(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(ONUMM7N3), INTENT(IN) :: X
      TYPE(ONUMM7N3), INTENT(IN) :: Y
      TYPE(ONUMM7N3) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION ONUMM7N3_DIVISION_OO

  ELEMENTAL FUNCTION ONUMM7N3_DIVISION_OR(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(ONUMM7N3), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: Y
      TYPE(ONUMM7N3) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION ONUMM7N3_DIVISION_OR

  ELEMENTAL FUNCTION ONUMM7N3_DIVISION_RO(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      REAL(DP), INTENT(IN) :: X
      TYPE(ONUMM7N3), INTENT(IN) :: Y
      TYPE(ONUMM7N3) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION ONUMM7N3_DIVISION_RO

  ELEMENTAL FUNCTION ONUMM7N3_REAL(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: RES

      RES = X%R

  END FUNCTION ONUMM7N3_REAL

  FUNCTION ONUMM7N3_SQRT(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3), INTENT(IN) :: X
      TYPE(ONUMM7N3) :: RES

      RES = X**0.5_DP

  END FUNCTION ONUMM7N3_SQRT

   ELEMENTAL FUNCTION ONUMM7N3_TAN(X) RESULT(RES)

      TYPE(ONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(ONUMM7N3) :: RES
      
      DER0 = TAN(X%R)
      DER1 = TAN(X%R)**2 + 1
      DER2 = 2*(TAN(X%R)**2 + 1)*TAN(X%R)
      DER3 = 2*(TAN(X%R)**2 + 1)*(3*TAN(X%R)**2 + 1)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION ONUMM7N3_TAN

   ELEMENTAL FUNCTION ONUMM7N3_COS(X) RESULT(RES)

      TYPE(ONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(ONUMM7N3) :: RES
      
      DER0 = COS(X%R)
      DER1 = -SIN(X%R)
      DER2 = -COS(X%R)
      DER3 = SIN(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION ONUMM7N3_COS

   ELEMENTAL FUNCTION ONUMM7N3_SIN(X) RESULT(RES)

      TYPE(ONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(ONUMM7N3) :: RES
      
      DER0 = SIN(X%R)
      DER1 = COS(X%R)
      DER2 = -SIN(X%R)
      DER3 = -COS(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION ONUMM7N3_SIN

   ELEMENTAL FUNCTION ONUMM7N3_ATAN(X) RESULT(RES)

      TYPE(ONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(ONUMM7N3) :: RES
      
      DER0 = ATAN(X%R)
      DER1 = 1D0/(X%R**2 + 1)
      DER2 = -2*X%R/(X%R**2 + 1)**2
      DER3 = 2*(4*X%R**2/(X%R**2 + 1) - 1)/(X%R**2 + 1)**2

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION ONUMM7N3_ATAN

   ELEMENTAL FUNCTION ONUMM7N3_ACOS(X) RESULT(RES)

      TYPE(ONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(ONUMM7N3) :: RES
      
      DER0 = ACOS(X%R)
      DER1 = -1/SQRT(1 - X%R**2)
      DER2 = -X%R/(1 - X%R**2)**(3.0D0/2.0D0)
      DER3 = -(3*X%R**2/(1 - X%R**2) + 1)/(1 - X%R**2)**(3.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION ONUMM7N3_ACOS

   ELEMENTAL FUNCTION ONUMM7N3_ASIN(X) RESULT(RES)

      TYPE(ONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(ONUMM7N3) :: RES
      
      DER0 = ASIN(X%R)
      DER1 = 1/SQRT(1 - X%R**2)
      DER2 = X%R/(1 - X%R**2)**(3.0D0/2.0D0)
      DER3 = (3*X%R**2/(1 - X%R**2) + 1)/(1 - X%R**2)**(3.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION ONUMM7N3_ASIN

   ELEMENTAL FUNCTION ONUMM7N3_TANH(X) RESULT(RES)

      TYPE(ONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(ONUMM7N3) :: RES
      
      DER0 = TANH(X%R)
      DER1 = 1 - TANH(X%R)**2
      DER2 = 2*(TANH(X%R)**2 - 1)*TANH(X%R)
      DER3 = -2*(TANH(X%R)**2 - 1)*(3*TANH(X%R)**2 - 1)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION ONUMM7N3_TANH

   ELEMENTAL FUNCTION ONUMM7N3_COSH(X) RESULT(RES)

      TYPE(ONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(ONUMM7N3) :: RES
      
      DER0 = COSH(X%R)
      DER1 = SINH(X%R)
      DER2 = COSH(X%R)
      DER3 = SINH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION ONUMM7N3_COSH

   ELEMENTAL FUNCTION ONUMM7N3_SINH(X) RESULT(RES)

      TYPE(ONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(ONUMM7N3) :: RES
      
      DER0 = SINH(X%R)
      DER1 = COSH(X%R)
      DER2 = SINH(X%R)
      DER3 = COSH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION ONUMM7N3_SINH

   ELEMENTAL FUNCTION ONUMM7N3_EXP(X) RESULT(RES)

      TYPE(ONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(ONUMM7N3) :: RES
      
      DER0 = EXP(X%R)
      DER1 = EXP(X%R)
      DER2 = EXP(X%R)
      DER3 = EXP(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION ONUMM7N3_EXP

   ELEMENTAL FUNCTION ONUMM7N3_LOG(X) RESULT(RES)

      TYPE(ONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(ONUMM7N3) :: RES
      
      DER0 = LOG(X%R)
      DER1 = 1D0/X%R
      DER2 = -1/X%R**2
      DER3 = 2/X%R**3

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION ONUMM7N3_LOG

   ELEMENTAL FUNCTION ONUMM7N3_POW_OR(X,E) RESULT(RES)

      TYPE(ONUMM7N3), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(ONUMM7N3) :: RES
      
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

   END FUNCTION ONUMM7N3_POW_OR

   ELEMENTAL FUNCTION ONUMM7N3_POW_RO(E,X) RESULT(RES)

      TYPE(ONUMM7N3), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(ONUMM7N3) :: RES
      
      
      DER0 = E**X%R
      DER1 = E**X%R*LOG(E)
      DER2 = E**X%R*LOG(E)**2
      DER3 = E**X%R*LOG(E)**3

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION ONUMM7N3_POW_RO

   ELEMENTAL FUNCTION ONUMM7N3_F2EVAL(X,Y,DER0_0,DER1_0,DER1_1, &
                                  DER2_0,DER2_1,DER2_2,DER3_0, &
                                  DER3_1,DER3_2,DER3_3)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: COEF, DELTA
      TYPE(ONUMM7N3), INTENT(IN)  :: X,Y
      REAL(DP), INTENT(IN)  :: DER0_0,DER1_0,DER1_1, &
                               DER2_0,DER2_1,DER2_2,DER3_0, &
                               DER3_1,DER3_2,DER3_3
      TYPE(ONUMM7N3) :: RES
      TYPE(ONUMM7N3) :: DX, DY

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

      

   END FUNCTION ONUMM7N3_F2EVAL


   ELEMENTAL FUNCTION ONUMM7N3_POW_OO(X,Y) RESULT(RES)

      TYPE(ONUMM7N3), INTENT(IN) :: X, Y
      REAL(DP) :: DER0_0,DER1_0,DER1_1,DER2_0,DER2_1,DER2_2,DER3_0,DER3_1,DER3_2,DER3_3
      TYPE(ONUMM7N3) :: RES
      
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

   END FUNCTION ONUMM7N3_POW_OO


   FUNCTION ONUMM7N3_INV2X2(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3) , INTENT(IN) :: A(2,2) 
      TYPE(ONUMM7N3) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(ONUMM7N3) :: RES(SIZE(A,1),SIZE(A,2)) 

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

      ! Order 3
      RES%E111=-MATMUL(RES%R,(MATMUL(A%E111,RES%R)+MATMUL(A%E1,RES%E11)+&
              MATMUL(A%E11,RES%E1)))
      RES%E112=-MATMUL(RES%R,(MATMUL(A%E112,RES%R)+MATMUL(A%E1,RES%E12)+&
              MATMUL(A%E12,RES%E1)+MATMUL(A%E2,RES%E11)+MATMUL(A%E11,RES%E2)))
      RES%E122=-MATMUL(RES%R,(MATMUL(A%E122,RES%R)+MATMUL(A%E1,RES%E22)+&
              MATMUL(A%E22,RES%E1)+MATMUL(A%E2,RES%E12)+MATMUL(A%E12,RES%E2)))
      RES%E222=-MATMUL(RES%R,(MATMUL(A%E222,RES%R)+MATMUL(A%E2,RES%E22)+&
              MATMUL(A%E22,RES%E2)))
      RES%E113=-MATMUL(RES%R,(MATMUL(A%E113,RES%R)+MATMUL(A%E1,RES%E13)+&
              MATMUL(A%E13,RES%E1)+MATMUL(A%E3,RES%E11)+MATMUL(A%E11,RES%E3)))
      RES%E123=-MATMUL(RES%R,(MATMUL(A%E123,RES%R)+MATMUL(A%E1,RES%E23)+&
              MATMUL(A%E23,RES%E1)+MATMUL(A%E2,RES%E13)+MATMUL(A%E13,RES%E2)+&
              MATMUL(A%E3,RES%E12)+MATMUL(A%E12,RES%E3)))
      RES%E223=-MATMUL(RES%R,(MATMUL(A%E223,RES%R)+MATMUL(A%E2,RES%E23)+&
              MATMUL(A%E23,RES%E2)+MATMUL(A%E3,RES%E22)+MATMUL(A%E22,RES%E3)))
      RES%E133=-MATMUL(RES%R,(MATMUL(A%E133,RES%R)+MATMUL(A%E1,RES%E33)+&
              MATMUL(A%E33,RES%E1)+MATMUL(A%E3,RES%E13)+MATMUL(A%E13,RES%E3)))
      RES%E233=-MATMUL(RES%R,(MATMUL(A%E233,RES%R)+MATMUL(A%E2,RES%E33)+&
              MATMUL(A%E33,RES%E2)+MATMUL(A%E3,RES%E23)+MATMUL(A%E23,RES%E3)))
      RES%E333=-MATMUL(RES%R,(MATMUL(A%E333,RES%R)+MATMUL(A%E3,RES%E33)+&
              MATMUL(A%E33,RES%E3)))
      RES%E114=-MATMUL(RES%R,(MATMUL(A%E114,RES%R)+MATMUL(A%E1,RES%E14)+&
              MATMUL(A%E14,RES%E1)+MATMUL(A%E4,RES%E11)+MATMUL(A%E11,RES%E4)))
      RES%E124=-MATMUL(RES%R,(MATMUL(A%E124,RES%R)+MATMUL(A%E1,RES%E24)+&
              MATMUL(A%E24,RES%E1)+MATMUL(A%E2,RES%E14)+MATMUL(A%E14,RES%E2)+&
              MATMUL(A%E4,RES%E12)+MATMUL(A%E12,RES%E4)))
      RES%E224=-MATMUL(RES%R,(MATMUL(A%E224,RES%R)+MATMUL(A%E2,RES%E24)+&
              MATMUL(A%E24,RES%E2)+MATMUL(A%E4,RES%E22)+MATMUL(A%E22,RES%E4)))
      RES%E134=-MATMUL(RES%R,(MATMUL(A%E134,RES%R)+MATMUL(A%E1,RES%E34)+&
              MATMUL(A%E34,RES%E1)+MATMUL(A%E3,RES%E14)+MATMUL(A%E14,RES%E3)+&
              MATMUL(A%E4,RES%E13)+MATMUL(A%E13,RES%E4)))
      RES%E234=-MATMUL(RES%R,(MATMUL(A%E234,RES%R)+MATMUL(A%E2,RES%E34)+&
              MATMUL(A%E34,RES%E2)+MATMUL(A%E3,RES%E24)+MATMUL(A%E24,RES%E3)+&
              MATMUL(A%E4,RES%E23)+MATMUL(A%E23,RES%E4)))
      RES%E334=-MATMUL(RES%R,(MATMUL(A%E334,RES%R)+MATMUL(A%E3,RES%E34)+&
              MATMUL(A%E34,RES%E3)+MATMUL(A%E4,RES%E33)+MATMUL(A%E33,RES%E4)))
      RES%E144=-MATMUL(RES%R,(MATMUL(A%E144,RES%R)+MATMUL(A%E1,RES%E44)+&
              MATMUL(A%E44,RES%E1)+MATMUL(A%E4,RES%E14)+MATMUL(A%E14,RES%E4)))
      RES%E244=-MATMUL(RES%R,(MATMUL(A%E244,RES%R)+MATMUL(A%E2,RES%E44)+&
              MATMUL(A%E44,RES%E2)+MATMUL(A%E4,RES%E24)+MATMUL(A%E24,RES%E4)))
      RES%E344=-MATMUL(RES%R,(MATMUL(A%E344,RES%R)+MATMUL(A%E3,RES%E44)+&
              MATMUL(A%E44,RES%E3)+MATMUL(A%E4,RES%E34)+MATMUL(A%E34,RES%E4)))
      RES%E444=-MATMUL(RES%R,(MATMUL(A%E444,RES%R)+MATMUL(A%E4,RES%E44)+&
              MATMUL(A%E44,RES%E4)))
      RES%E115=-MATMUL(RES%R,(MATMUL(A%E115,RES%R)+MATMUL(A%E1,RES%E15)+&
              MATMUL(A%E15,RES%E1)+MATMUL(A%E5,RES%E11)+MATMUL(A%E11,RES%E5)))
      RES%E125=-MATMUL(RES%R,(MATMUL(A%E125,RES%R)+MATMUL(A%E1,RES%E25)+&
              MATMUL(A%E25,RES%E1)+MATMUL(A%E2,RES%E15)+MATMUL(A%E15,RES%E2)+&
              MATMUL(A%E5,RES%E12)+MATMUL(A%E12,RES%E5)))
      RES%E225=-MATMUL(RES%R,(MATMUL(A%E225,RES%R)+MATMUL(A%E2,RES%E25)+&
              MATMUL(A%E25,RES%E2)+MATMUL(A%E5,RES%E22)+MATMUL(A%E22,RES%E5)))
      RES%E135=-MATMUL(RES%R,(MATMUL(A%E135,RES%R)+MATMUL(A%E1,RES%E35)+&
              MATMUL(A%E35,RES%E1)+MATMUL(A%E3,RES%E15)+MATMUL(A%E15,RES%E3)+&
              MATMUL(A%E5,RES%E13)+MATMUL(A%E13,RES%E5)))
      RES%E235=-MATMUL(RES%R,(MATMUL(A%E235,RES%R)+MATMUL(A%E2,RES%E35)+&
              MATMUL(A%E35,RES%E2)+MATMUL(A%E3,RES%E25)+MATMUL(A%E25,RES%E3)+&
              MATMUL(A%E5,RES%E23)+MATMUL(A%E23,RES%E5)))
      RES%E335=-MATMUL(RES%R,(MATMUL(A%E335,RES%R)+MATMUL(A%E3,RES%E35)+&
              MATMUL(A%E35,RES%E3)+MATMUL(A%E5,RES%E33)+MATMUL(A%E33,RES%E5)))
      RES%E145=-MATMUL(RES%R,(MATMUL(A%E145,RES%R)+MATMUL(A%E1,RES%E45)+&
              MATMUL(A%E45,RES%E1)+MATMUL(A%E4,RES%E15)+MATMUL(A%E15,RES%E4)+&
              MATMUL(A%E5,RES%E14)+MATMUL(A%E14,RES%E5)))
      RES%E245=-MATMUL(RES%R,(MATMUL(A%E245,RES%R)+MATMUL(A%E2,RES%E45)+&
              MATMUL(A%E45,RES%E2)+MATMUL(A%E4,RES%E25)+MATMUL(A%E25,RES%E4)+&
              MATMUL(A%E5,RES%E24)+MATMUL(A%E24,RES%E5)))
      RES%E345=-MATMUL(RES%R,(MATMUL(A%E345,RES%R)+MATMUL(A%E3,RES%E45)+&
              MATMUL(A%E45,RES%E3)+MATMUL(A%E4,RES%E35)+MATMUL(A%E35,RES%E4)+&
              MATMUL(A%E5,RES%E34)+MATMUL(A%E34,RES%E5)))
      RES%E445=-MATMUL(RES%R,(MATMUL(A%E445,RES%R)+MATMUL(A%E4,RES%E45)+&
              MATMUL(A%E45,RES%E4)+MATMUL(A%E5,RES%E44)+MATMUL(A%E44,RES%E5)))
      RES%E155=-MATMUL(RES%R,(MATMUL(A%E155,RES%R)+MATMUL(A%E1,RES%E55)+&
              MATMUL(A%E55,RES%E1)+MATMUL(A%E5,RES%E15)+MATMUL(A%E15,RES%E5)))
      RES%E255=-MATMUL(RES%R,(MATMUL(A%E255,RES%R)+MATMUL(A%E2,RES%E55)+&
              MATMUL(A%E55,RES%E2)+MATMUL(A%E5,RES%E25)+MATMUL(A%E25,RES%E5)))
      RES%E355=-MATMUL(RES%R,(MATMUL(A%E355,RES%R)+MATMUL(A%E3,RES%E55)+&
              MATMUL(A%E55,RES%E3)+MATMUL(A%E5,RES%E35)+MATMUL(A%E35,RES%E5)))
      RES%E455=-MATMUL(RES%R,(MATMUL(A%E455,RES%R)+MATMUL(A%E4,RES%E55)+&
              MATMUL(A%E55,RES%E4)+MATMUL(A%E5,RES%E45)+MATMUL(A%E45,RES%E5)))
      RES%E555=-MATMUL(RES%R,(MATMUL(A%E555,RES%R)+MATMUL(A%E5,RES%E55)+&
              MATMUL(A%E55,RES%E5)))
      RES%E116=-MATMUL(RES%R,(MATMUL(A%E116,RES%R)+MATMUL(A%E1,RES%E16)+&
              MATMUL(A%E16,RES%E1)+MATMUL(A%E6,RES%E11)+MATMUL(A%E11,RES%E6)))
      RES%E126=-MATMUL(RES%R,(MATMUL(A%E126,RES%R)+MATMUL(A%E1,RES%E26)+&
              MATMUL(A%E26,RES%E1)+MATMUL(A%E2,RES%E16)+MATMUL(A%E16,RES%E2)+&
              MATMUL(A%E6,RES%E12)+MATMUL(A%E12,RES%E6)))
      RES%E226=-MATMUL(RES%R,(MATMUL(A%E226,RES%R)+MATMUL(A%E2,RES%E26)+&
              MATMUL(A%E26,RES%E2)+MATMUL(A%E6,RES%E22)+MATMUL(A%E22,RES%E6)))
      RES%E136=-MATMUL(RES%R,(MATMUL(A%E136,RES%R)+MATMUL(A%E1,RES%E36)+&
              MATMUL(A%E36,RES%E1)+MATMUL(A%E3,RES%E16)+MATMUL(A%E16,RES%E3)+&
              MATMUL(A%E6,RES%E13)+MATMUL(A%E13,RES%E6)))
      RES%E236=-MATMUL(RES%R,(MATMUL(A%E236,RES%R)+MATMUL(A%E2,RES%E36)+&
              MATMUL(A%E36,RES%E2)+MATMUL(A%E3,RES%E26)+MATMUL(A%E26,RES%E3)+&
              MATMUL(A%E6,RES%E23)+MATMUL(A%E23,RES%E6)))
      RES%E336=-MATMUL(RES%R,(MATMUL(A%E336,RES%R)+MATMUL(A%E3,RES%E36)+&
              MATMUL(A%E36,RES%E3)+MATMUL(A%E6,RES%E33)+MATMUL(A%E33,RES%E6)))
      RES%E146=-MATMUL(RES%R,(MATMUL(A%E146,RES%R)+MATMUL(A%E1,RES%E46)+&
              MATMUL(A%E46,RES%E1)+MATMUL(A%E4,RES%E16)+MATMUL(A%E16,RES%E4)+&
              MATMUL(A%E6,RES%E14)+MATMUL(A%E14,RES%E6)))
      RES%E246=-MATMUL(RES%R,(MATMUL(A%E246,RES%R)+MATMUL(A%E2,RES%E46)+&
              MATMUL(A%E46,RES%E2)+MATMUL(A%E4,RES%E26)+MATMUL(A%E26,RES%E4)+&
              MATMUL(A%E6,RES%E24)+MATMUL(A%E24,RES%E6)))
      RES%E346=-MATMUL(RES%R,(MATMUL(A%E346,RES%R)+MATMUL(A%E3,RES%E46)+&
              MATMUL(A%E46,RES%E3)+MATMUL(A%E4,RES%E36)+MATMUL(A%E36,RES%E4)+&
              MATMUL(A%E6,RES%E34)+MATMUL(A%E34,RES%E6)))
      RES%E446=-MATMUL(RES%R,(MATMUL(A%E446,RES%R)+MATMUL(A%E4,RES%E46)+&
              MATMUL(A%E46,RES%E4)+MATMUL(A%E6,RES%E44)+MATMUL(A%E44,RES%E6)))
      RES%E156=-MATMUL(RES%R,(MATMUL(A%E156,RES%R)+MATMUL(A%E1,RES%E56)+&
              MATMUL(A%E56,RES%E1)+MATMUL(A%E5,RES%E16)+MATMUL(A%E16,RES%E5)+&
              MATMUL(A%E6,RES%E15)+MATMUL(A%E15,RES%E6)))
      RES%E256=-MATMUL(RES%R,(MATMUL(A%E256,RES%R)+MATMUL(A%E2,RES%E56)+&
              MATMUL(A%E56,RES%E2)+MATMUL(A%E5,RES%E26)+MATMUL(A%E26,RES%E5)+&
              MATMUL(A%E6,RES%E25)+MATMUL(A%E25,RES%E6)))
      RES%E356=-MATMUL(RES%R,(MATMUL(A%E356,RES%R)+MATMUL(A%E3,RES%E56)+&
              MATMUL(A%E56,RES%E3)+MATMUL(A%E5,RES%E36)+MATMUL(A%E36,RES%E5)+&
              MATMUL(A%E6,RES%E35)+MATMUL(A%E35,RES%E6)))
      RES%E456=-MATMUL(RES%R,(MATMUL(A%E456,RES%R)+MATMUL(A%E4,RES%E56)+&
              MATMUL(A%E56,RES%E4)+MATMUL(A%E5,RES%E46)+MATMUL(A%E46,RES%E5)+&
              MATMUL(A%E6,RES%E45)+MATMUL(A%E45,RES%E6)))
      RES%E556=-MATMUL(RES%R,(MATMUL(A%E556,RES%R)+MATMUL(A%E5,RES%E56)+&
              MATMUL(A%E56,RES%E5)+MATMUL(A%E6,RES%E55)+MATMUL(A%E55,RES%E6)))
      RES%E166=-MATMUL(RES%R,(MATMUL(A%E166,RES%R)+MATMUL(A%E1,RES%E66)+&
              MATMUL(A%E66,RES%E1)+MATMUL(A%E6,RES%E16)+MATMUL(A%E16,RES%E6)))
      RES%E266=-MATMUL(RES%R,(MATMUL(A%E266,RES%R)+MATMUL(A%E2,RES%E66)+&
              MATMUL(A%E66,RES%E2)+MATMUL(A%E6,RES%E26)+MATMUL(A%E26,RES%E6)))
      RES%E366=-MATMUL(RES%R,(MATMUL(A%E366,RES%R)+MATMUL(A%E3,RES%E66)+&
              MATMUL(A%E66,RES%E3)+MATMUL(A%E6,RES%E36)+MATMUL(A%E36,RES%E6)))
      RES%E466=-MATMUL(RES%R,(MATMUL(A%E466,RES%R)+MATMUL(A%E4,RES%E66)+&
              MATMUL(A%E66,RES%E4)+MATMUL(A%E6,RES%E46)+MATMUL(A%E46,RES%E6)))
      RES%E566=-MATMUL(RES%R,(MATMUL(A%E566,RES%R)+MATMUL(A%E5,RES%E66)+&
              MATMUL(A%E66,RES%E5)+MATMUL(A%E6,RES%E56)+MATMUL(A%E56,RES%E6)))
      RES%E666=-MATMUL(RES%R,(MATMUL(A%E666,RES%R)+MATMUL(A%E6,RES%E66)+&
              MATMUL(A%E66,RES%E6)))
      RES%E117=-MATMUL(RES%R,(MATMUL(A%E117,RES%R)+MATMUL(A%E1,RES%E17)+&
              MATMUL(A%E17,RES%E1)+MATMUL(A%E7,RES%E11)+MATMUL(A%E11,RES%E7)))
      RES%E127=-MATMUL(RES%R,(MATMUL(A%E127,RES%R)+MATMUL(A%E1,RES%E27)+&
              MATMUL(A%E27,RES%E1)+MATMUL(A%E2,RES%E17)+MATMUL(A%E17,RES%E2)+&
              MATMUL(A%E7,RES%E12)+MATMUL(A%E12,RES%E7)))
      RES%E227=-MATMUL(RES%R,(MATMUL(A%E227,RES%R)+MATMUL(A%E2,RES%E27)+&
              MATMUL(A%E27,RES%E2)+MATMUL(A%E7,RES%E22)+MATMUL(A%E22,RES%E7)))
      RES%E137=-MATMUL(RES%R,(MATMUL(A%E137,RES%R)+MATMUL(A%E1,RES%E37)+&
              MATMUL(A%E37,RES%E1)+MATMUL(A%E3,RES%E17)+MATMUL(A%E17,RES%E3)+&
              MATMUL(A%E7,RES%E13)+MATMUL(A%E13,RES%E7)))
      RES%E237=-MATMUL(RES%R,(MATMUL(A%E237,RES%R)+MATMUL(A%E2,RES%E37)+&
              MATMUL(A%E37,RES%E2)+MATMUL(A%E3,RES%E27)+MATMUL(A%E27,RES%E3)+&
              MATMUL(A%E7,RES%E23)+MATMUL(A%E23,RES%E7)))
      RES%E337=-MATMUL(RES%R,(MATMUL(A%E337,RES%R)+MATMUL(A%E3,RES%E37)+&
              MATMUL(A%E37,RES%E3)+MATMUL(A%E7,RES%E33)+MATMUL(A%E33,RES%E7)))
      RES%E147=-MATMUL(RES%R,(MATMUL(A%E147,RES%R)+MATMUL(A%E1,RES%E47)+&
              MATMUL(A%E47,RES%E1)+MATMUL(A%E4,RES%E17)+MATMUL(A%E17,RES%E4)+&
              MATMUL(A%E7,RES%E14)+MATMUL(A%E14,RES%E7)))
      RES%E247=-MATMUL(RES%R,(MATMUL(A%E247,RES%R)+MATMUL(A%E2,RES%E47)+&
              MATMUL(A%E47,RES%E2)+MATMUL(A%E4,RES%E27)+MATMUL(A%E27,RES%E4)+&
              MATMUL(A%E7,RES%E24)+MATMUL(A%E24,RES%E7)))
      RES%E347=-MATMUL(RES%R,(MATMUL(A%E347,RES%R)+MATMUL(A%E3,RES%E47)+&
              MATMUL(A%E47,RES%E3)+MATMUL(A%E4,RES%E37)+MATMUL(A%E37,RES%E4)+&
              MATMUL(A%E7,RES%E34)+MATMUL(A%E34,RES%E7)))
      RES%E447=-MATMUL(RES%R,(MATMUL(A%E447,RES%R)+MATMUL(A%E4,RES%E47)+&
              MATMUL(A%E47,RES%E4)+MATMUL(A%E7,RES%E44)+MATMUL(A%E44,RES%E7)))
      RES%E157=-MATMUL(RES%R,(MATMUL(A%E157,RES%R)+MATMUL(A%E1,RES%E57)+&
              MATMUL(A%E57,RES%E1)+MATMUL(A%E5,RES%E17)+MATMUL(A%E17,RES%E5)+&
              MATMUL(A%E7,RES%E15)+MATMUL(A%E15,RES%E7)))
      RES%E257=-MATMUL(RES%R,(MATMUL(A%E257,RES%R)+MATMUL(A%E2,RES%E57)+&
              MATMUL(A%E57,RES%E2)+MATMUL(A%E5,RES%E27)+MATMUL(A%E27,RES%E5)+&
              MATMUL(A%E7,RES%E25)+MATMUL(A%E25,RES%E7)))
      RES%E357=-MATMUL(RES%R,(MATMUL(A%E357,RES%R)+MATMUL(A%E3,RES%E57)+&
              MATMUL(A%E57,RES%E3)+MATMUL(A%E5,RES%E37)+MATMUL(A%E37,RES%E5)+&
              MATMUL(A%E7,RES%E35)+MATMUL(A%E35,RES%E7)))
      RES%E457=-MATMUL(RES%R,(MATMUL(A%E457,RES%R)+MATMUL(A%E4,RES%E57)+&
              MATMUL(A%E57,RES%E4)+MATMUL(A%E5,RES%E47)+MATMUL(A%E47,RES%E5)+&
              MATMUL(A%E7,RES%E45)+MATMUL(A%E45,RES%E7)))
      RES%E557=-MATMUL(RES%R,(MATMUL(A%E557,RES%R)+MATMUL(A%E5,RES%E57)+&
              MATMUL(A%E57,RES%E5)+MATMUL(A%E7,RES%E55)+MATMUL(A%E55,RES%E7)))
      RES%E167=-MATMUL(RES%R,(MATMUL(A%E167,RES%R)+MATMUL(A%E1,RES%E67)+&
              MATMUL(A%E67,RES%E1)+MATMUL(A%E6,RES%E17)+MATMUL(A%E17,RES%E6)+&
              MATMUL(A%E7,RES%E16)+MATMUL(A%E16,RES%E7)))
      RES%E267=-MATMUL(RES%R,(MATMUL(A%E267,RES%R)+MATMUL(A%E2,RES%E67)+&
              MATMUL(A%E67,RES%E2)+MATMUL(A%E6,RES%E27)+MATMUL(A%E27,RES%E6)+&
              MATMUL(A%E7,RES%E26)+MATMUL(A%E26,RES%E7)))
      RES%E367=-MATMUL(RES%R,(MATMUL(A%E367,RES%R)+MATMUL(A%E3,RES%E67)+&
              MATMUL(A%E67,RES%E3)+MATMUL(A%E6,RES%E37)+MATMUL(A%E37,RES%E6)+&
              MATMUL(A%E7,RES%E36)+MATMUL(A%E36,RES%E7)))
      RES%E467=-MATMUL(RES%R,(MATMUL(A%E467,RES%R)+MATMUL(A%E4,RES%E67)+&
              MATMUL(A%E67,RES%E4)+MATMUL(A%E6,RES%E47)+MATMUL(A%E47,RES%E6)+&
              MATMUL(A%E7,RES%E46)+MATMUL(A%E46,RES%E7)))
      RES%E567=-MATMUL(RES%R,(MATMUL(A%E567,RES%R)+MATMUL(A%E5,RES%E67)+&
              MATMUL(A%E67,RES%E5)+MATMUL(A%E6,RES%E57)+MATMUL(A%E57,RES%E6)+&
              MATMUL(A%E7,RES%E56)+MATMUL(A%E56,RES%E7)))
      RES%E667=-MATMUL(RES%R,(MATMUL(A%E667,RES%R)+MATMUL(A%E6,RES%E67)+&
              MATMUL(A%E67,RES%E6)+MATMUL(A%E7,RES%E66)+MATMUL(A%E66,RES%E7)))
      RES%E177=-MATMUL(RES%R,(MATMUL(A%E177,RES%R)+MATMUL(A%E1,RES%E77)+&
              MATMUL(A%E77,RES%E1)+MATMUL(A%E7,RES%E17)+MATMUL(A%E17,RES%E7)))
      RES%E277=-MATMUL(RES%R,(MATMUL(A%E277,RES%R)+MATMUL(A%E2,RES%E77)+&
              MATMUL(A%E77,RES%E2)+MATMUL(A%E7,RES%E27)+MATMUL(A%E27,RES%E7)))
      RES%E377=-MATMUL(RES%R,(MATMUL(A%E377,RES%R)+MATMUL(A%E3,RES%E77)+&
              MATMUL(A%E77,RES%E3)+MATMUL(A%E7,RES%E37)+MATMUL(A%E37,RES%E7)))
      RES%E477=-MATMUL(RES%R,(MATMUL(A%E477,RES%R)+MATMUL(A%E4,RES%E77)+&
              MATMUL(A%E77,RES%E4)+MATMUL(A%E7,RES%E47)+MATMUL(A%E47,RES%E7)))
      RES%E577=-MATMUL(RES%R,(MATMUL(A%E577,RES%R)+MATMUL(A%E5,RES%E77)+&
              MATMUL(A%E77,RES%E5)+MATMUL(A%E7,RES%E57)+MATMUL(A%E57,RES%E7)))
      RES%E677=-MATMUL(RES%R,(MATMUL(A%E677,RES%R)+MATMUL(A%E6,RES%E77)+&
              MATMUL(A%E77,RES%E6)+MATMUL(A%E7,RES%E67)+MATMUL(A%E67,RES%E7)))
      RES%E777=-MATMUL(RES%R,(MATMUL(A%E777,RES%R)+MATMUL(A%E7,RES%E77)+&
              MATMUL(A%E77,RES%E7)))

   END FUNCTION ONUMM7N3_INV2X2

   FUNCTION ONUMM7N3_INV3X3(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3) , INTENT(IN) :: A(3,3) 
      TYPE(ONUMM7N3) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(ONUMM7N3) :: RES(SIZE(A,1),SIZE(A,2)) 

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

      ! Order 3
      RES%E111=-MATMUL(RES%R,(MATMUL(A%E111,RES%R)+MATMUL(A%E1,RES%E11)+&
              MATMUL(A%E11,RES%E1)))
      RES%E112=-MATMUL(RES%R,(MATMUL(A%E112,RES%R)+MATMUL(A%E1,RES%E12)+&
              MATMUL(A%E12,RES%E1)+MATMUL(A%E2,RES%E11)+MATMUL(A%E11,RES%E2)))
      RES%E122=-MATMUL(RES%R,(MATMUL(A%E122,RES%R)+MATMUL(A%E1,RES%E22)+&
              MATMUL(A%E22,RES%E1)+MATMUL(A%E2,RES%E12)+MATMUL(A%E12,RES%E2)))
      RES%E222=-MATMUL(RES%R,(MATMUL(A%E222,RES%R)+MATMUL(A%E2,RES%E22)+&
              MATMUL(A%E22,RES%E2)))
      RES%E113=-MATMUL(RES%R,(MATMUL(A%E113,RES%R)+MATMUL(A%E1,RES%E13)+&
              MATMUL(A%E13,RES%E1)+MATMUL(A%E3,RES%E11)+MATMUL(A%E11,RES%E3)))
      RES%E123=-MATMUL(RES%R,(MATMUL(A%E123,RES%R)+MATMUL(A%E1,RES%E23)+&
              MATMUL(A%E23,RES%E1)+MATMUL(A%E2,RES%E13)+MATMUL(A%E13,RES%E2)+&
              MATMUL(A%E3,RES%E12)+MATMUL(A%E12,RES%E3)))
      RES%E223=-MATMUL(RES%R,(MATMUL(A%E223,RES%R)+MATMUL(A%E2,RES%E23)+&
              MATMUL(A%E23,RES%E2)+MATMUL(A%E3,RES%E22)+MATMUL(A%E22,RES%E3)))
      RES%E133=-MATMUL(RES%R,(MATMUL(A%E133,RES%R)+MATMUL(A%E1,RES%E33)+&
              MATMUL(A%E33,RES%E1)+MATMUL(A%E3,RES%E13)+MATMUL(A%E13,RES%E3)))
      RES%E233=-MATMUL(RES%R,(MATMUL(A%E233,RES%R)+MATMUL(A%E2,RES%E33)+&
              MATMUL(A%E33,RES%E2)+MATMUL(A%E3,RES%E23)+MATMUL(A%E23,RES%E3)))
      RES%E333=-MATMUL(RES%R,(MATMUL(A%E333,RES%R)+MATMUL(A%E3,RES%E33)+&
              MATMUL(A%E33,RES%E3)))
      RES%E114=-MATMUL(RES%R,(MATMUL(A%E114,RES%R)+MATMUL(A%E1,RES%E14)+&
              MATMUL(A%E14,RES%E1)+MATMUL(A%E4,RES%E11)+MATMUL(A%E11,RES%E4)))
      RES%E124=-MATMUL(RES%R,(MATMUL(A%E124,RES%R)+MATMUL(A%E1,RES%E24)+&
              MATMUL(A%E24,RES%E1)+MATMUL(A%E2,RES%E14)+MATMUL(A%E14,RES%E2)+&
              MATMUL(A%E4,RES%E12)+MATMUL(A%E12,RES%E4)))
      RES%E224=-MATMUL(RES%R,(MATMUL(A%E224,RES%R)+MATMUL(A%E2,RES%E24)+&
              MATMUL(A%E24,RES%E2)+MATMUL(A%E4,RES%E22)+MATMUL(A%E22,RES%E4)))
      RES%E134=-MATMUL(RES%R,(MATMUL(A%E134,RES%R)+MATMUL(A%E1,RES%E34)+&
              MATMUL(A%E34,RES%E1)+MATMUL(A%E3,RES%E14)+MATMUL(A%E14,RES%E3)+&
              MATMUL(A%E4,RES%E13)+MATMUL(A%E13,RES%E4)))
      RES%E234=-MATMUL(RES%R,(MATMUL(A%E234,RES%R)+MATMUL(A%E2,RES%E34)+&
              MATMUL(A%E34,RES%E2)+MATMUL(A%E3,RES%E24)+MATMUL(A%E24,RES%E3)+&
              MATMUL(A%E4,RES%E23)+MATMUL(A%E23,RES%E4)))
      RES%E334=-MATMUL(RES%R,(MATMUL(A%E334,RES%R)+MATMUL(A%E3,RES%E34)+&
              MATMUL(A%E34,RES%E3)+MATMUL(A%E4,RES%E33)+MATMUL(A%E33,RES%E4)))
      RES%E144=-MATMUL(RES%R,(MATMUL(A%E144,RES%R)+MATMUL(A%E1,RES%E44)+&
              MATMUL(A%E44,RES%E1)+MATMUL(A%E4,RES%E14)+MATMUL(A%E14,RES%E4)))
      RES%E244=-MATMUL(RES%R,(MATMUL(A%E244,RES%R)+MATMUL(A%E2,RES%E44)+&
              MATMUL(A%E44,RES%E2)+MATMUL(A%E4,RES%E24)+MATMUL(A%E24,RES%E4)))
      RES%E344=-MATMUL(RES%R,(MATMUL(A%E344,RES%R)+MATMUL(A%E3,RES%E44)+&
              MATMUL(A%E44,RES%E3)+MATMUL(A%E4,RES%E34)+MATMUL(A%E34,RES%E4)))
      RES%E444=-MATMUL(RES%R,(MATMUL(A%E444,RES%R)+MATMUL(A%E4,RES%E44)+&
              MATMUL(A%E44,RES%E4)))
      RES%E115=-MATMUL(RES%R,(MATMUL(A%E115,RES%R)+MATMUL(A%E1,RES%E15)+&
              MATMUL(A%E15,RES%E1)+MATMUL(A%E5,RES%E11)+MATMUL(A%E11,RES%E5)))
      RES%E125=-MATMUL(RES%R,(MATMUL(A%E125,RES%R)+MATMUL(A%E1,RES%E25)+&
              MATMUL(A%E25,RES%E1)+MATMUL(A%E2,RES%E15)+MATMUL(A%E15,RES%E2)+&
              MATMUL(A%E5,RES%E12)+MATMUL(A%E12,RES%E5)))
      RES%E225=-MATMUL(RES%R,(MATMUL(A%E225,RES%R)+MATMUL(A%E2,RES%E25)+&
              MATMUL(A%E25,RES%E2)+MATMUL(A%E5,RES%E22)+MATMUL(A%E22,RES%E5)))
      RES%E135=-MATMUL(RES%R,(MATMUL(A%E135,RES%R)+MATMUL(A%E1,RES%E35)+&
              MATMUL(A%E35,RES%E1)+MATMUL(A%E3,RES%E15)+MATMUL(A%E15,RES%E3)+&
              MATMUL(A%E5,RES%E13)+MATMUL(A%E13,RES%E5)))
      RES%E235=-MATMUL(RES%R,(MATMUL(A%E235,RES%R)+MATMUL(A%E2,RES%E35)+&
              MATMUL(A%E35,RES%E2)+MATMUL(A%E3,RES%E25)+MATMUL(A%E25,RES%E3)+&
              MATMUL(A%E5,RES%E23)+MATMUL(A%E23,RES%E5)))
      RES%E335=-MATMUL(RES%R,(MATMUL(A%E335,RES%R)+MATMUL(A%E3,RES%E35)+&
              MATMUL(A%E35,RES%E3)+MATMUL(A%E5,RES%E33)+MATMUL(A%E33,RES%E5)))
      RES%E145=-MATMUL(RES%R,(MATMUL(A%E145,RES%R)+MATMUL(A%E1,RES%E45)+&
              MATMUL(A%E45,RES%E1)+MATMUL(A%E4,RES%E15)+MATMUL(A%E15,RES%E4)+&
              MATMUL(A%E5,RES%E14)+MATMUL(A%E14,RES%E5)))
      RES%E245=-MATMUL(RES%R,(MATMUL(A%E245,RES%R)+MATMUL(A%E2,RES%E45)+&
              MATMUL(A%E45,RES%E2)+MATMUL(A%E4,RES%E25)+MATMUL(A%E25,RES%E4)+&
              MATMUL(A%E5,RES%E24)+MATMUL(A%E24,RES%E5)))
      RES%E345=-MATMUL(RES%R,(MATMUL(A%E345,RES%R)+MATMUL(A%E3,RES%E45)+&
              MATMUL(A%E45,RES%E3)+MATMUL(A%E4,RES%E35)+MATMUL(A%E35,RES%E4)+&
              MATMUL(A%E5,RES%E34)+MATMUL(A%E34,RES%E5)))
      RES%E445=-MATMUL(RES%R,(MATMUL(A%E445,RES%R)+MATMUL(A%E4,RES%E45)+&
              MATMUL(A%E45,RES%E4)+MATMUL(A%E5,RES%E44)+MATMUL(A%E44,RES%E5)))
      RES%E155=-MATMUL(RES%R,(MATMUL(A%E155,RES%R)+MATMUL(A%E1,RES%E55)+&
              MATMUL(A%E55,RES%E1)+MATMUL(A%E5,RES%E15)+MATMUL(A%E15,RES%E5)))
      RES%E255=-MATMUL(RES%R,(MATMUL(A%E255,RES%R)+MATMUL(A%E2,RES%E55)+&
              MATMUL(A%E55,RES%E2)+MATMUL(A%E5,RES%E25)+MATMUL(A%E25,RES%E5)))
      RES%E355=-MATMUL(RES%R,(MATMUL(A%E355,RES%R)+MATMUL(A%E3,RES%E55)+&
              MATMUL(A%E55,RES%E3)+MATMUL(A%E5,RES%E35)+MATMUL(A%E35,RES%E5)))
      RES%E455=-MATMUL(RES%R,(MATMUL(A%E455,RES%R)+MATMUL(A%E4,RES%E55)+&
              MATMUL(A%E55,RES%E4)+MATMUL(A%E5,RES%E45)+MATMUL(A%E45,RES%E5)))
      RES%E555=-MATMUL(RES%R,(MATMUL(A%E555,RES%R)+MATMUL(A%E5,RES%E55)+&
              MATMUL(A%E55,RES%E5)))
      RES%E116=-MATMUL(RES%R,(MATMUL(A%E116,RES%R)+MATMUL(A%E1,RES%E16)+&
              MATMUL(A%E16,RES%E1)+MATMUL(A%E6,RES%E11)+MATMUL(A%E11,RES%E6)))
      RES%E126=-MATMUL(RES%R,(MATMUL(A%E126,RES%R)+MATMUL(A%E1,RES%E26)+&
              MATMUL(A%E26,RES%E1)+MATMUL(A%E2,RES%E16)+MATMUL(A%E16,RES%E2)+&
              MATMUL(A%E6,RES%E12)+MATMUL(A%E12,RES%E6)))
      RES%E226=-MATMUL(RES%R,(MATMUL(A%E226,RES%R)+MATMUL(A%E2,RES%E26)+&
              MATMUL(A%E26,RES%E2)+MATMUL(A%E6,RES%E22)+MATMUL(A%E22,RES%E6)))
      RES%E136=-MATMUL(RES%R,(MATMUL(A%E136,RES%R)+MATMUL(A%E1,RES%E36)+&
              MATMUL(A%E36,RES%E1)+MATMUL(A%E3,RES%E16)+MATMUL(A%E16,RES%E3)+&
              MATMUL(A%E6,RES%E13)+MATMUL(A%E13,RES%E6)))
      RES%E236=-MATMUL(RES%R,(MATMUL(A%E236,RES%R)+MATMUL(A%E2,RES%E36)+&
              MATMUL(A%E36,RES%E2)+MATMUL(A%E3,RES%E26)+MATMUL(A%E26,RES%E3)+&
              MATMUL(A%E6,RES%E23)+MATMUL(A%E23,RES%E6)))
      RES%E336=-MATMUL(RES%R,(MATMUL(A%E336,RES%R)+MATMUL(A%E3,RES%E36)+&
              MATMUL(A%E36,RES%E3)+MATMUL(A%E6,RES%E33)+MATMUL(A%E33,RES%E6)))
      RES%E146=-MATMUL(RES%R,(MATMUL(A%E146,RES%R)+MATMUL(A%E1,RES%E46)+&
              MATMUL(A%E46,RES%E1)+MATMUL(A%E4,RES%E16)+MATMUL(A%E16,RES%E4)+&
              MATMUL(A%E6,RES%E14)+MATMUL(A%E14,RES%E6)))
      RES%E246=-MATMUL(RES%R,(MATMUL(A%E246,RES%R)+MATMUL(A%E2,RES%E46)+&
              MATMUL(A%E46,RES%E2)+MATMUL(A%E4,RES%E26)+MATMUL(A%E26,RES%E4)+&
              MATMUL(A%E6,RES%E24)+MATMUL(A%E24,RES%E6)))
      RES%E346=-MATMUL(RES%R,(MATMUL(A%E346,RES%R)+MATMUL(A%E3,RES%E46)+&
              MATMUL(A%E46,RES%E3)+MATMUL(A%E4,RES%E36)+MATMUL(A%E36,RES%E4)+&
              MATMUL(A%E6,RES%E34)+MATMUL(A%E34,RES%E6)))
      RES%E446=-MATMUL(RES%R,(MATMUL(A%E446,RES%R)+MATMUL(A%E4,RES%E46)+&
              MATMUL(A%E46,RES%E4)+MATMUL(A%E6,RES%E44)+MATMUL(A%E44,RES%E6)))
      RES%E156=-MATMUL(RES%R,(MATMUL(A%E156,RES%R)+MATMUL(A%E1,RES%E56)+&
              MATMUL(A%E56,RES%E1)+MATMUL(A%E5,RES%E16)+MATMUL(A%E16,RES%E5)+&
              MATMUL(A%E6,RES%E15)+MATMUL(A%E15,RES%E6)))
      RES%E256=-MATMUL(RES%R,(MATMUL(A%E256,RES%R)+MATMUL(A%E2,RES%E56)+&
              MATMUL(A%E56,RES%E2)+MATMUL(A%E5,RES%E26)+MATMUL(A%E26,RES%E5)+&
              MATMUL(A%E6,RES%E25)+MATMUL(A%E25,RES%E6)))
      RES%E356=-MATMUL(RES%R,(MATMUL(A%E356,RES%R)+MATMUL(A%E3,RES%E56)+&
              MATMUL(A%E56,RES%E3)+MATMUL(A%E5,RES%E36)+MATMUL(A%E36,RES%E5)+&
              MATMUL(A%E6,RES%E35)+MATMUL(A%E35,RES%E6)))
      RES%E456=-MATMUL(RES%R,(MATMUL(A%E456,RES%R)+MATMUL(A%E4,RES%E56)+&
              MATMUL(A%E56,RES%E4)+MATMUL(A%E5,RES%E46)+MATMUL(A%E46,RES%E5)+&
              MATMUL(A%E6,RES%E45)+MATMUL(A%E45,RES%E6)))
      RES%E556=-MATMUL(RES%R,(MATMUL(A%E556,RES%R)+MATMUL(A%E5,RES%E56)+&
              MATMUL(A%E56,RES%E5)+MATMUL(A%E6,RES%E55)+MATMUL(A%E55,RES%E6)))
      RES%E166=-MATMUL(RES%R,(MATMUL(A%E166,RES%R)+MATMUL(A%E1,RES%E66)+&
              MATMUL(A%E66,RES%E1)+MATMUL(A%E6,RES%E16)+MATMUL(A%E16,RES%E6)))
      RES%E266=-MATMUL(RES%R,(MATMUL(A%E266,RES%R)+MATMUL(A%E2,RES%E66)+&
              MATMUL(A%E66,RES%E2)+MATMUL(A%E6,RES%E26)+MATMUL(A%E26,RES%E6)))
      RES%E366=-MATMUL(RES%R,(MATMUL(A%E366,RES%R)+MATMUL(A%E3,RES%E66)+&
              MATMUL(A%E66,RES%E3)+MATMUL(A%E6,RES%E36)+MATMUL(A%E36,RES%E6)))
      RES%E466=-MATMUL(RES%R,(MATMUL(A%E466,RES%R)+MATMUL(A%E4,RES%E66)+&
              MATMUL(A%E66,RES%E4)+MATMUL(A%E6,RES%E46)+MATMUL(A%E46,RES%E6)))
      RES%E566=-MATMUL(RES%R,(MATMUL(A%E566,RES%R)+MATMUL(A%E5,RES%E66)+&
              MATMUL(A%E66,RES%E5)+MATMUL(A%E6,RES%E56)+MATMUL(A%E56,RES%E6)))
      RES%E666=-MATMUL(RES%R,(MATMUL(A%E666,RES%R)+MATMUL(A%E6,RES%E66)+&
              MATMUL(A%E66,RES%E6)))
      RES%E117=-MATMUL(RES%R,(MATMUL(A%E117,RES%R)+MATMUL(A%E1,RES%E17)+&
              MATMUL(A%E17,RES%E1)+MATMUL(A%E7,RES%E11)+MATMUL(A%E11,RES%E7)))
      RES%E127=-MATMUL(RES%R,(MATMUL(A%E127,RES%R)+MATMUL(A%E1,RES%E27)+&
              MATMUL(A%E27,RES%E1)+MATMUL(A%E2,RES%E17)+MATMUL(A%E17,RES%E2)+&
              MATMUL(A%E7,RES%E12)+MATMUL(A%E12,RES%E7)))
      RES%E227=-MATMUL(RES%R,(MATMUL(A%E227,RES%R)+MATMUL(A%E2,RES%E27)+&
              MATMUL(A%E27,RES%E2)+MATMUL(A%E7,RES%E22)+MATMUL(A%E22,RES%E7)))
      RES%E137=-MATMUL(RES%R,(MATMUL(A%E137,RES%R)+MATMUL(A%E1,RES%E37)+&
              MATMUL(A%E37,RES%E1)+MATMUL(A%E3,RES%E17)+MATMUL(A%E17,RES%E3)+&
              MATMUL(A%E7,RES%E13)+MATMUL(A%E13,RES%E7)))
      RES%E237=-MATMUL(RES%R,(MATMUL(A%E237,RES%R)+MATMUL(A%E2,RES%E37)+&
              MATMUL(A%E37,RES%E2)+MATMUL(A%E3,RES%E27)+MATMUL(A%E27,RES%E3)+&
              MATMUL(A%E7,RES%E23)+MATMUL(A%E23,RES%E7)))
      RES%E337=-MATMUL(RES%R,(MATMUL(A%E337,RES%R)+MATMUL(A%E3,RES%E37)+&
              MATMUL(A%E37,RES%E3)+MATMUL(A%E7,RES%E33)+MATMUL(A%E33,RES%E7)))
      RES%E147=-MATMUL(RES%R,(MATMUL(A%E147,RES%R)+MATMUL(A%E1,RES%E47)+&
              MATMUL(A%E47,RES%E1)+MATMUL(A%E4,RES%E17)+MATMUL(A%E17,RES%E4)+&
              MATMUL(A%E7,RES%E14)+MATMUL(A%E14,RES%E7)))
      RES%E247=-MATMUL(RES%R,(MATMUL(A%E247,RES%R)+MATMUL(A%E2,RES%E47)+&
              MATMUL(A%E47,RES%E2)+MATMUL(A%E4,RES%E27)+MATMUL(A%E27,RES%E4)+&
              MATMUL(A%E7,RES%E24)+MATMUL(A%E24,RES%E7)))
      RES%E347=-MATMUL(RES%R,(MATMUL(A%E347,RES%R)+MATMUL(A%E3,RES%E47)+&
              MATMUL(A%E47,RES%E3)+MATMUL(A%E4,RES%E37)+MATMUL(A%E37,RES%E4)+&
              MATMUL(A%E7,RES%E34)+MATMUL(A%E34,RES%E7)))
      RES%E447=-MATMUL(RES%R,(MATMUL(A%E447,RES%R)+MATMUL(A%E4,RES%E47)+&
              MATMUL(A%E47,RES%E4)+MATMUL(A%E7,RES%E44)+MATMUL(A%E44,RES%E7)))
      RES%E157=-MATMUL(RES%R,(MATMUL(A%E157,RES%R)+MATMUL(A%E1,RES%E57)+&
              MATMUL(A%E57,RES%E1)+MATMUL(A%E5,RES%E17)+MATMUL(A%E17,RES%E5)+&
              MATMUL(A%E7,RES%E15)+MATMUL(A%E15,RES%E7)))
      RES%E257=-MATMUL(RES%R,(MATMUL(A%E257,RES%R)+MATMUL(A%E2,RES%E57)+&
              MATMUL(A%E57,RES%E2)+MATMUL(A%E5,RES%E27)+MATMUL(A%E27,RES%E5)+&
              MATMUL(A%E7,RES%E25)+MATMUL(A%E25,RES%E7)))
      RES%E357=-MATMUL(RES%R,(MATMUL(A%E357,RES%R)+MATMUL(A%E3,RES%E57)+&
              MATMUL(A%E57,RES%E3)+MATMUL(A%E5,RES%E37)+MATMUL(A%E37,RES%E5)+&
              MATMUL(A%E7,RES%E35)+MATMUL(A%E35,RES%E7)))
      RES%E457=-MATMUL(RES%R,(MATMUL(A%E457,RES%R)+MATMUL(A%E4,RES%E57)+&
              MATMUL(A%E57,RES%E4)+MATMUL(A%E5,RES%E47)+MATMUL(A%E47,RES%E5)+&
              MATMUL(A%E7,RES%E45)+MATMUL(A%E45,RES%E7)))
      RES%E557=-MATMUL(RES%R,(MATMUL(A%E557,RES%R)+MATMUL(A%E5,RES%E57)+&
              MATMUL(A%E57,RES%E5)+MATMUL(A%E7,RES%E55)+MATMUL(A%E55,RES%E7)))
      RES%E167=-MATMUL(RES%R,(MATMUL(A%E167,RES%R)+MATMUL(A%E1,RES%E67)+&
              MATMUL(A%E67,RES%E1)+MATMUL(A%E6,RES%E17)+MATMUL(A%E17,RES%E6)+&
              MATMUL(A%E7,RES%E16)+MATMUL(A%E16,RES%E7)))
      RES%E267=-MATMUL(RES%R,(MATMUL(A%E267,RES%R)+MATMUL(A%E2,RES%E67)+&
              MATMUL(A%E67,RES%E2)+MATMUL(A%E6,RES%E27)+MATMUL(A%E27,RES%E6)+&
              MATMUL(A%E7,RES%E26)+MATMUL(A%E26,RES%E7)))
      RES%E367=-MATMUL(RES%R,(MATMUL(A%E367,RES%R)+MATMUL(A%E3,RES%E67)+&
              MATMUL(A%E67,RES%E3)+MATMUL(A%E6,RES%E37)+MATMUL(A%E37,RES%E6)+&
              MATMUL(A%E7,RES%E36)+MATMUL(A%E36,RES%E7)))
      RES%E467=-MATMUL(RES%R,(MATMUL(A%E467,RES%R)+MATMUL(A%E4,RES%E67)+&
              MATMUL(A%E67,RES%E4)+MATMUL(A%E6,RES%E47)+MATMUL(A%E47,RES%E6)+&
              MATMUL(A%E7,RES%E46)+MATMUL(A%E46,RES%E7)))
      RES%E567=-MATMUL(RES%R,(MATMUL(A%E567,RES%R)+MATMUL(A%E5,RES%E67)+&
              MATMUL(A%E67,RES%E5)+MATMUL(A%E6,RES%E57)+MATMUL(A%E57,RES%E6)+&
              MATMUL(A%E7,RES%E56)+MATMUL(A%E56,RES%E7)))
      RES%E667=-MATMUL(RES%R,(MATMUL(A%E667,RES%R)+MATMUL(A%E6,RES%E67)+&
              MATMUL(A%E67,RES%E6)+MATMUL(A%E7,RES%E66)+MATMUL(A%E66,RES%E7)))
      RES%E177=-MATMUL(RES%R,(MATMUL(A%E177,RES%R)+MATMUL(A%E1,RES%E77)+&
              MATMUL(A%E77,RES%E1)+MATMUL(A%E7,RES%E17)+MATMUL(A%E17,RES%E7)))
      RES%E277=-MATMUL(RES%R,(MATMUL(A%E277,RES%R)+MATMUL(A%E2,RES%E77)+&
              MATMUL(A%E77,RES%E2)+MATMUL(A%E7,RES%E27)+MATMUL(A%E27,RES%E7)))
      RES%E377=-MATMUL(RES%R,(MATMUL(A%E377,RES%R)+MATMUL(A%E3,RES%E77)+&
              MATMUL(A%E77,RES%E3)+MATMUL(A%E7,RES%E37)+MATMUL(A%E37,RES%E7)))
      RES%E477=-MATMUL(RES%R,(MATMUL(A%E477,RES%R)+MATMUL(A%E4,RES%E77)+&
              MATMUL(A%E77,RES%E4)+MATMUL(A%E7,RES%E47)+MATMUL(A%E47,RES%E7)))
      RES%E577=-MATMUL(RES%R,(MATMUL(A%E577,RES%R)+MATMUL(A%E5,RES%E77)+&
              MATMUL(A%E77,RES%E5)+MATMUL(A%E7,RES%E57)+MATMUL(A%E57,RES%E7)))
      RES%E677=-MATMUL(RES%R,(MATMUL(A%E677,RES%R)+MATMUL(A%E6,RES%E77)+&
              MATMUL(A%E77,RES%E6)+MATMUL(A%E7,RES%E67)+MATMUL(A%E67,RES%E7)))
      RES%E777=-MATMUL(RES%R,(MATMUL(A%E777,RES%R)+MATMUL(A%E7,RES%E77)+&
              MATMUL(A%E77,RES%E7)))

   END FUNCTION ONUMM7N3_INV3X3

   FUNCTION ONUMM7N3_INV4X4(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM7N3) , INTENT(IN) :: A(4,4) 
      TYPE(ONUMM7N3) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(ONUMM7N3) :: RES(SIZE(A,1),SIZE(A,2)) 

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

      ! Order 3
      RES%E111=-MATMUL(RES%R,(MATMUL(A%E111,RES%R)+MATMUL(A%E1,RES%E11)+&
              MATMUL(A%E11,RES%E1)))
      RES%E112=-MATMUL(RES%R,(MATMUL(A%E112,RES%R)+MATMUL(A%E1,RES%E12)+&
              MATMUL(A%E12,RES%E1)+MATMUL(A%E2,RES%E11)+MATMUL(A%E11,RES%E2)))
      RES%E122=-MATMUL(RES%R,(MATMUL(A%E122,RES%R)+MATMUL(A%E1,RES%E22)+&
              MATMUL(A%E22,RES%E1)+MATMUL(A%E2,RES%E12)+MATMUL(A%E12,RES%E2)))
      RES%E222=-MATMUL(RES%R,(MATMUL(A%E222,RES%R)+MATMUL(A%E2,RES%E22)+&
              MATMUL(A%E22,RES%E2)))
      RES%E113=-MATMUL(RES%R,(MATMUL(A%E113,RES%R)+MATMUL(A%E1,RES%E13)+&
              MATMUL(A%E13,RES%E1)+MATMUL(A%E3,RES%E11)+MATMUL(A%E11,RES%E3)))
      RES%E123=-MATMUL(RES%R,(MATMUL(A%E123,RES%R)+MATMUL(A%E1,RES%E23)+&
              MATMUL(A%E23,RES%E1)+MATMUL(A%E2,RES%E13)+MATMUL(A%E13,RES%E2)+&
              MATMUL(A%E3,RES%E12)+MATMUL(A%E12,RES%E3)))
      RES%E223=-MATMUL(RES%R,(MATMUL(A%E223,RES%R)+MATMUL(A%E2,RES%E23)+&
              MATMUL(A%E23,RES%E2)+MATMUL(A%E3,RES%E22)+MATMUL(A%E22,RES%E3)))
      RES%E133=-MATMUL(RES%R,(MATMUL(A%E133,RES%R)+MATMUL(A%E1,RES%E33)+&
              MATMUL(A%E33,RES%E1)+MATMUL(A%E3,RES%E13)+MATMUL(A%E13,RES%E3)))
      RES%E233=-MATMUL(RES%R,(MATMUL(A%E233,RES%R)+MATMUL(A%E2,RES%E33)+&
              MATMUL(A%E33,RES%E2)+MATMUL(A%E3,RES%E23)+MATMUL(A%E23,RES%E3)))
      RES%E333=-MATMUL(RES%R,(MATMUL(A%E333,RES%R)+MATMUL(A%E3,RES%E33)+&
              MATMUL(A%E33,RES%E3)))
      RES%E114=-MATMUL(RES%R,(MATMUL(A%E114,RES%R)+MATMUL(A%E1,RES%E14)+&
              MATMUL(A%E14,RES%E1)+MATMUL(A%E4,RES%E11)+MATMUL(A%E11,RES%E4)))
      RES%E124=-MATMUL(RES%R,(MATMUL(A%E124,RES%R)+MATMUL(A%E1,RES%E24)+&
              MATMUL(A%E24,RES%E1)+MATMUL(A%E2,RES%E14)+MATMUL(A%E14,RES%E2)+&
              MATMUL(A%E4,RES%E12)+MATMUL(A%E12,RES%E4)))
      RES%E224=-MATMUL(RES%R,(MATMUL(A%E224,RES%R)+MATMUL(A%E2,RES%E24)+&
              MATMUL(A%E24,RES%E2)+MATMUL(A%E4,RES%E22)+MATMUL(A%E22,RES%E4)))
      RES%E134=-MATMUL(RES%R,(MATMUL(A%E134,RES%R)+MATMUL(A%E1,RES%E34)+&
              MATMUL(A%E34,RES%E1)+MATMUL(A%E3,RES%E14)+MATMUL(A%E14,RES%E3)+&
              MATMUL(A%E4,RES%E13)+MATMUL(A%E13,RES%E4)))
      RES%E234=-MATMUL(RES%R,(MATMUL(A%E234,RES%R)+MATMUL(A%E2,RES%E34)+&
              MATMUL(A%E34,RES%E2)+MATMUL(A%E3,RES%E24)+MATMUL(A%E24,RES%E3)+&
              MATMUL(A%E4,RES%E23)+MATMUL(A%E23,RES%E4)))
      RES%E334=-MATMUL(RES%R,(MATMUL(A%E334,RES%R)+MATMUL(A%E3,RES%E34)+&
              MATMUL(A%E34,RES%E3)+MATMUL(A%E4,RES%E33)+MATMUL(A%E33,RES%E4)))
      RES%E144=-MATMUL(RES%R,(MATMUL(A%E144,RES%R)+MATMUL(A%E1,RES%E44)+&
              MATMUL(A%E44,RES%E1)+MATMUL(A%E4,RES%E14)+MATMUL(A%E14,RES%E4)))
      RES%E244=-MATMUL(RES%R,(MATMUL(A%E244,RES%R)+MATMUL(A%E2,RES%E44)+&
              MATMUL(A%E44,RES%E2)+MATMUL(A%E4,RES%E24)+MATMUL(A%E24,RES%E4)))
      RES%E344=-MATMUL(RES%R,(MATMUL(A%E344,RES%R)+MATMUL(A%E3,RES%E44)+&
              MATMUL(A%E44,RES%E3)+MATMUL(A%E4,RES%E34)+MATMUL(A%E34,RES%E4)))
      RES%E444=-MATMUL(RES%R,(MATMUL(A%E444,RES%R)+MATMUL(A%E4,RES%E44)+&
              MATMUL(A%E44,RES%E4)))
      RES%E115=-MATMUL(RES%R,(MATMUL(A%E115,RES%R)+MATMUL(A%E1,RES%E15)+&
              MATMUL(A%E15,RES%E1)+MATMUL(A%E5,RES%E11)+MATMUL(A%E11,RES%E5)))
      RES%E125=-MATMUL(RES%R,(MATMUL(A%E125,RES%R)+MATMUL(A%E1,RES%E25)+&
              MATMUL(A%E25,RES%E1)+MATMUL(A%E2,RES%E15)+MATMUL(A%E15,RES%E2)+&
              MATMUL(A%E5,RES%E12)+MATMUL(A%E12,RES%E5)))
      RES%E225=-MATMUL(RES%R,(MATMUL(A%E225,RES%R)+MATMUL(A%E2,RES%E25)+&
              MATMUL(A%E25,RES%E2)+MATMUL(A%E5,RES%E22)+MATMUL(A%E22,RES%E5)))
      RES%E135=-MATMUL(RES%R,(MATMUL(A%E135,RES%R)+MATMUL(A%E1,RES%E35)+&
              MATMUL(A%E35,RES%E1)+MATMUL(A%E3,RES%E15)+MATMUL(A%E15,RES%E3)+&
              MATMUL(A%E5,RES%E13)+MATMUL(A%E13,RES%E5)))
      RES%E235=-MATMUL(RES%R,(MATMUL(A%E235,RES%R)+MATMUL(A%E2,RES%E35)+&
              MATMUL(A%E35,RES%E2)+MATMUL(A%E3,RES%E25)+MATMUL(A%E25,RES%E3)+&
              MATMUL(A%E5,RES%E23)+MATMUL(A%E23,RES%E5)))
      RES%E335=-MATMUL(RES%R,(MATMUL(A%E335,RES%R)+MATMUL(A%E3,RES%E35)+&
              MATMUL(A%E35,RES%E3)+MATMUL(A%E5,RES%E33)+MATMUL(A%E33,RES%E5)))
      RES%E145=-MATMUL(RES%R,(MATMUL(A%E145,RES%R)+MATMUL(A%E1,RES%E45)+&
              MATMUL(A%E45,RES%E1)+MATMUL(A%E4,RES%E15)+MATMUL(A%E15,RES%E4)+&
              MATMUL(A%E5,RES%E14)+MATMUL(A%E14,RES%E5)))
      RES%E245=-MATMUL(RES%R,(MATMUL(A%E245,RES%R)+MATMUL(A%E2,RES%E45)+&
              MATMUL(A%E45,RES%E2)+MATMUL(A%E4,RES%E25)+MATMUL(A%E25,RES%E4)+&
              MATMUL(A%E5,RES%E24)+MATMUL(A%E24,RES%E5)))
      RES%E345=-MATMUL(RES%R,(MATMUL(A%E345,RES%R)+MATMUL(A%E3,RES%E45)+&
              MATMUL(A%E45,RES%E3)+MATMUL(A%E4,RES%E35)+MATMUL(A%E35,RES%E4)+&
              MATMUL(A%E5,RES%E34)+MATMUL(A%E34,RES%E5)))
      RES%E445=-MATMUL(RES%R,(MATMUL(A%E445,RES%R)+MATMUL(A%E4,RES%E45)+&
              MATMUL(A%E45,RES%E4)+MATMUL(A%E5,RES%E44)+MATMUL(A%E44,RES%E5)))
      RES%E155=-MATMUL(RES%R,(MATMUL(A%E155,RES%R)+MATMUL(A%E1,RES%E55)+&
              MATMUL(A%E55,RES%E1)+MATMUL(A%E5,RES%E15)+MATMUL(A%E15,RES%E5)))
      RES%E255=-MATMUL(RES%R,(MATMUL(A%E255,RES%R)+MATMUL(A%E2,RES%E55)+&
              MATMUL(A%E55,RES%E2)+MATMUL(A%E5,RES%E25)+MATMUL(A%E25,RES%E5)))
      RES%E355=-MATMUL(RES%R,(MATMUL(A%E355,RES%R)+MATMUL(A%E3,RES%E55)+&
              MATMUL(A%E55,RES%E3)+MATMUL(A%E5,RES%E35)+MATMUL(A%E35,RES%E5)))
      RES%E455=-MATMUL(RES%R,(MATMUL(A%E455,RES%R)+MATMUL(A%E4,RES%E55)+&
              MATMUL(A%E55,RES%E4)+MATMUL(A%E5,RES%E45)+MATMUL(A%E45,RES%E5)))
      RES%E555=-MATMUL(RES%R,(MATMUL(A%E555,RES%R)+MATMUL(A%E5,RES%E55)+&
              MATMUL(A%E55,RES%E5)))
      RES%E116=-MATMUL(RES%R,(MATMUL(A%E116,RES%R)+MATMUL(A%E1,RES%E16)+&
              MATMUL(A%E16,RES%E1)+MATMUL(A%E6,RES%E11)+MATMUL(A%E11,RES%E6)))
      RES%E126=-MATMUL(RES%R,(MATMUL(A%E126,RES%R)+MATMUL(A%E1,RES%E26)+&
              MATMUL(A%E26,RES%E1)+MATMUL(A%E2,RES%E16)+MATMUL(A%E16,RES%E2)+&
              MATMUL(A%E6,RES%E12)+MATMUL(A%E12,RES%E6)))
      RES%E226=-MATMUL(RES%R,(MATMUL(A%E226,RES%R)+MATMUL(A%E2,RES%E26)+&
              MATMUL(A%E26,RES%E2)+MATMUL(A%E6,RES%E22)+MATMUL(A%E22,RES%E6)))
      RES%E136=-MATMUL(RES%R,(MATMUL(A%E136,RES%R)+MATMUL(A%E1,RES%E36)+&
              MATMUL(A%E36,RES%E1)+MATMUL(A%E3,RES%E16)+MATMUL(A%E16,RES%E3)+&
              MATMUL(A%E6,RES%E13)+MATMUL(A%E13,RES%E6)))
      RES%E236=-MATMUL(RES%R,(MATMUL(A%E236,RES%R)+MATMUL(A%E2,RES%E36)+&
              MATMUL(A%E36,RES%E2)+MATMUL(A%E3,RES%E26)+MATMUL(A%E26,RES%E3)+&
              MATMUL(A%E6,RES%E23)+MATMUL(A%E23,RES%E6)))
      RES%E336=-MATMUL(RES%R,(MATMUL(A%E336,RES%R)+MATMUL(A%E3,RES%E36)+&
              MATMUL(A%E36,RES%E3)+MATMUL(A%E6,RES%E33)+MATMUL(A%E33,RES%E6)))
      RES%E146=-MATMUL(RES%R,(MATMUL(A%E146,RES%R)+MATMUL(A%E1,RES%E46)+&
              MATMUL(A%E46,RES%E1)+MATMUL(A%E4,RES%E16)+MATMUL(A%E16,RES%E4)+&
              MATMUL(A%E6,RES%E14)+MATMUL(A%E14,RES%E6)))
      RES%E246=-MATMUL(RES%R,(MATMUL(A%E246,RES%R)+MATMUL(A%E2,RES%E46)+&
              MATMUL(A%E46,RES%E2)+MATMUL(A%E4,RES%E26)+MATMUL(A%E26,RES%E4)+&
              MATMUL(A%E6,RES%E24)+MATMUL(A%E24,RES%E6)))
      RES%E346=-MATMUL(RES%R,(MATMUL(A%E346,RES%R)+MATMUL(A%E3,RES%E46)+&
              MATMUL(A%E46,RES%E3)+MATMUL(A%E4,RES%E36)+MATMUL(A%E36,RES%E4)+&
              MATMUL(A%E6,RES%E34)+MATMUL(A%E34,RES%E6)))
      RES%E446=-MATMUL(RES%R,(MATMUL(A%E446,RES%R)+MATMUL(A%E4,RES%E46)+&
              MATMUL(A%E46,RES%E4)+MATMUL(A%E6,RES%E44)+MATMUL(A%E44,RES%E6)))
      RES%E156=-MATMUL(RES%R,(MATMUL(A%E156,RES%R)+MATMUL(A%E1,RES%E56)+&
              MATMUL(A%E56,RES%E1)+MATMUL(A%E5,RES%E16)+MATMUL(A%E16,RES%E5)+&
              MATMUL(A%E6,RES%E15)+MATMUL(A%E15,RES%E6)))
      RES%E256=-MATMUL(RES%R,(MATMUL(A%E256,RES%R)+MATMUL(A%E2,RES%E56)+&
              MATMUL(A%E56,RES%E2)+MATMUL(A%E5,RES%E26)+MATMUL(A%E26,RES%E5)+&
              MATMUL(A%E6,RES%E25)+MATMUL(A%E25,RES%E6)))
      RES%E356=-MATMUL(RES%R,(MATMUL(A%E356,RES%R)+MATMUL(A%E3,RES%E56)+&
              MATMUL(A%E56,RES%E3)+MATMUL(A%E5,RES%E36)+MATMUL(A%E36,RES%E5)+&
              MATMUL(A%E6,RES%E35)+MATMUL(A%E35,RES%E6)))
      RES%E456=-MATMUL(RES%R,(MATMUL(A%E456,RES%R)+MATMUL(A%E4,RES%E56)+&
              MATMUL(A%E56,RES%E4)+MATMUL(A%E5,RES%E46)+MATMUL(A%E46,RES%E5)+&
              MATMUL(A%E6,RES%E45)+MATMUL(A%E45,RES%E6)))
      RES%E556=-MATMUL(RES%R,(MATMUL(A%E556,RES%R)+MATMUL(A%E5,RES%E56)+&
              MATMUL(A%E56,RES%E5)+MATMUL(A%E6,RES%E55)+MATMUL(A%E55,RES%E6)))
      RES%E166=-MATMUL(RES%R,(MATMUL(A%E166,RES%R)+MATMUL(A%E1,RES%E66)+&
              MATMUL(A%E66,RES%E1)+MATMUL(A%E6,RES%E16)+MATMUL(A%E16,RES%E6)))
      RES%E266=-MATMUL(RES%R,(MATMUL(A%E266,RES%R)+MATMUL(A%E2,RES%E66)+&
              MATMUL(A%E66,RES%E2)+MATMUL(A%E6,RES%E26)+MATMUL(A%E26,RES%E6)))
      RES%E366=-MATMUL(RES%R,(MATMUL(A%E366,RES%R)+MATMUL(A%E3,RES%E66)+&
              MATMUL(A%E66,RES%E3)+MATMUL(A%E6,RES%E36)+MATMUL(A%E36,RES%E6)))
      RES%E466=-MATMUL(RES%R,(MATMUL(A%E466,RES%R)+MATMUL(A%E4,RES%E66)+&
              MATMUL(A%E66,RES%E4)+MATMUL(A%E6,RES%E46)+MATMUL(A%E46,RES%E6)))
      RES%E566=-MATMUL(RES%R,(MATMUL(A%E566,RES%R)+MATMUL(A%E5,RES%E66)+&
              MATMUL(A%E66,RES%E5)+MATMUL(A%E6,RES%E56)+MATMUL(A%E56,RES%E6)))
      RES%E666=-MATMUL(RES%R,(MATMUL(A%E666,RES%R)+MATMUL(A%E6,RES%E66)+&
              MATMUL(A%E66,RES%E6)))
      RES%E117=-MATMUL(RES%R,(MATMUL(A%E117,RES%R)+MATMUL(A%E1,RES%E17)+&
              MATMUL(A%E17,RES%E1)+MATMUL(A%E7,RES%E11)+MATMUL(A%E11,RES%E7)))
      RES%E127=-MATMUL(RES%R,(MATMUL(A%E127,RES%R)+MATMUL(A%E1,RES%E27)+&
              MATMUL(A%E27,RES%E1)+MATMUL(A%E2,RES%E17)+MATMUL(A%E17,RES%E2)+&
              MATMUL(A%E7,RES%E12)+MATMUL(A%E12,RES%E7)))
      RES%E227=-MATMUL(RES%R,(MATMUL(A%E227,RES%R)+MATMUL(A%E2,RES%E27)+&
              MATMUL(A%E27,RES%E2)+MATMUL(A%E7,RES%E22)+MATMUL(A%E22,RES%E7)))
      RES%E137=-MATMUL(RES%R,(MATMUL(A%E137,RES%R)+MATMUL(A%E1,RES%E37)+&
              MATMUL(A%E37,RES%E1)+MATMUL(A%E3,RES%E17)+MATMUL(A%E17,RES%E3)+&
              MATMUL(A%E7,RES%E13)+MATMUL(A%E13,RES%E7)))
      RES%E237=-MATMUL(RES%R,(MATMUL(A%E237,RES%R)+MATMUL(A%E2,RES%E37)+&
              MATMUL(A%E37,RES%E2)+MATMUL(A%E3,RES%E27)+MATMUL(A%E27,RES%E3)+&
              MATMUL(A%E7,RES%E23)+MATMUL(A%E23,RES%E7)))
      RES%E337=-MATMUL(RES%R,(MATMUL(A%E337,RES%R)+MATMUL(A%E3,RES%E37)+&
              MATMUL(A%E37,RES%E3)+MATMUL(A%E7,RES%E33)+MATMUL(A%E33,RES%E7)))
      RES%E147=-MATMUL(RES%R,(MATMUL(A%E147,RES%R)+MATMUL(A%E1,RES%E47)+&
              MATMUL(A%E47,RES%E1)+MATMUL(A%E4,RES%E17)+MATMUL(A%E17,RES%E4)+&
              MATMUL(A%E7,RES%E14)+MATMUL(A%E14,RES%E7)))
      RES%E247=-MATMUL(RES%R,(MATMUL(A%E247,RES%R)+MATMUL(A%E2,RES%E47)+&
              MATMUL(A%E47,RES%E2)+MATMUL(A%E4,RES%E27)+MATMUL(A%E27,RES%E4)+&
              MATMUL(A%E7,RES%E24)+MATMUL(A%E24,RES%E7)))
      RES%E347=-MATMUL(RES%R,(MATMUL(A%E347,RES%R)+MATMUL(A%E3,RES%E47)+&
              MATMUL(A%E47,RES%E3)+MATMUL(A%E4,RES%E37)+MATMUL(A%E37,RES%E4)+&
              MATMUL(A%E7,RES%E34)+MATMUL(A%E34,RES%E7)))
      RES%E447=-MATMUL(RES%R,(MATMUL(A%E447,RES%R)+MATMUL(A%E4,RES%E47)+&
              MATMUL(A%E47,RES%E4)+MATMUL(A%E7,RES%E44)+MATMUL(A%E44,RES%E7)))
      RES%E157=-MATMUL(RES%R,(MATMUL(A%E157,RES%R)+MATMUL(A%E1,RES%E57)+&
              MATMUL(A%E57,RES%E1)+MATMUL(A%E5,RES%E17)+MATMUL(A%E17,RES%E5)+&
              MATMUL(A%E7,RES%E15)+MATMUL(A%E15,RES%E7)))
      RES%E257=-MATMUL(RES%R,(MATMUL(A%E257,RES%R)+MATMUL(A%E2,RES%E57)+&
              MATMUL(A%E57,RES%E2)+MATMUL(A%E5,RES%E27)+MATMUL(A%E27,RES%E5)+&
              MATMUL(A%E7,RES%E25)+MATMUL(A%E25,RES%E7)))
      RES%E357=-MATMUL(RES%R,(MATMUL(A%E357,RES%R)+MATMUL(A%E3,RES%E57)+&
              MATMUL(A%E57,RES%E3)+MATMUL(A%E5,RES%E37)+MATMUL(A%E37,RES%E5)+&
              MATMUL(A%E7,RES%E35)+MATMUL(A%E35,RES%E7)))
      RES%E457=-MATMUL(RES%R,(MATMUL(A%E457,RES%R)+MATMUL(A%E4,RES%E57)+&
              MATMUL(A%E57,RES%E4)+MATMUL(A%E5,RES%E47)+MATMUL(A%E47,RES%E5)+&
              MATMUL(A%E7,RES%E45)+MATMUL(A%E45,RES%E7)))
      RES%E557=-MATMUL(RES%R,(MATMUL(A%E557,RES%R)+MATMUL(A%E5,RES%E57)+&
              MATMUL(A%E57,RES%E5)+MATMUL(A%E7,RES%E55)+MATMUL(A%E55,RES%E7)))
      RES%E167=-MATMUL(RES%R,(MATMUL(A%E167,RES%R)+MATMUL(A%E1,RES%E67)+&
              MATMUL(A%E67,RES%E1)+MATMUL(A%E6,RES%E17)+MATMUL(A%E17,RES%E6)+&
              MATMUL(A%E7,RES%E16)+MATMUL(A%E16,RES%E7)))
      RES%E267=-MATMUL(RES%R,(MATMUL(A%E267,RES%R)+MATMUL(A%E2,RES%E67)+&
              MATMUL(A%E67,RES%E2)+MATMUL(A%E6,RES%E27)+MATMUL(A%E27,RES%E6)+&
              MATMUL(A%E7,RES%E26)+MATMUL(A%E26,RES%E7)))
      RES%E367=-MATMUL(RES%R,(MATMUL(A%E367,RES%R)+MATMUL(A%E3,RES%E67)+&
              MATMUL(A%E67,RES%E3)+MATMUL(A%E6,RES%E37)+MATMUL(A%E37,RES%E6)+&
              MATMUL(A%E7,RES%E36)+MATMUL(A%E36,RES%E7)))
      RES%E467=-MATMUL(RES%R,(MATMUL(A%E467,RES%R)+MATMUL(A%E4,RES%E67)+&
              MATMUL(A%E67,RES%E4)+MATMUL(A%E6,RES%E47)+MATMUL(A%E47,RES%E6)+&
              MATMUL(A%E7,RES%E46)+MATMUL(A%E46,RES%E7)))
      RES%E567=-MATMUL(RES%R,(MATMUL(A%E567,RES%R)+MATMUL(A%E5,RES%E67)+&
              MATMUL(A%E67,RES%E5)+MATMUL(A%E6,RES%E57)+MATMUL(A%E57,RES%E6)+&
              MATMUL(A%E7,RES%E56)+MATMUL(A%E56,RES%E7)))
      RES%E667=-MATMUL(RES%R,(MATMUL(A%E667,RES%R)+MATMUL(A%E6,RES%E67)+&
              MATMUL(A%E67,RES%E6)+MATMUL(A%E7,RES%E66)+MATMUL(A%E66,RES%E7)))
      RES%E177=-MATMUL(RES%R,(MATMUL(A%E177,RES%R)+MATMUL(A%E1,RES%E77)+&
              MATMUL(A%E77,RES%E1)+MATMUL(A%E7,RES%E17)+MATMUL(A%E17,RES%E7)))
      RES%E277=-MATMUL(RES%R,(MATMUL(A%E277,RES%R)+MATMUL(A%E2,RES%E77)+&
              MATMUL(A%E77,RES%E2)+MATMUL(A%E7,RES%E27)+MATMUL(A%E27,RES%E7)))
      RES%E377=-MATMUL(RES%R,(MATMUL(A%E377,RES%R)+MATMUL(A%E3,RES%E77)+&
              MATMUL(A%E77,RES%E3)+MATMUL(A%E7,RES%E37)+MATMUL(A%E37,RES%E7)))
      RES%E477=-MATMUL(RES%R,(MATMUL(A%E477,RES%R)+MATMUL(A%E4,RES%E77)+&
              MATMUL(A%E77,RES%E4)+MATMUL(A%E7,RES%E47)+MATMUL(A%E47,RES%E7)))
      RES%E577=-MATMUL(RES%R,(MATMUL(A%E577,RES%R)+MATMUL(A%E5,RES%E77)+&
              MATMUL(A%E77,RES%E5)+MATMUL(A%E7,RES%E57)+MATMUL(A%E57,RES%E7)))
      RES%E677=-MATMUL(RES%R,(MATMUL(A%E677,RES%R)+MATMUL(A%E6,RES%E77)+&
              MATMUL(A%E77,RES%E6)+MATMUL(A%E7,RES%E67)+MATMUL(A%E67,RES%E7)))
      RES%E777=-MATMUL(RES%R,(MATMUL(A%E777,RES%R)+MATMUL(A%E7,RES%E77)+&
              MATMUL(A%E77,RES%E7)))

   END FUNCTION ONUMM7N3_INV4X4

END MODULE otim7n3
