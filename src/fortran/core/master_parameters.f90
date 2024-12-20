!*******************************************************************************************************!
!> @brief This module contains the master parameters used in many Finite Element modules and other 
!! programs.
!!
!! @author Mauricio Aristizabal Cano, University of Texas at San Antonio
!*******************************************************************************************************!
MODULE master_parameters
   !----------------------------------------------------------------------------------------------------!
   IMPLICIT NONE
   !----------------------------------------------------------------------------------------------------!
   INTEGER,  PARAMETER :: dp      = SELECTED_REAL_KIND(15,306) ! Double precision
   INTEGER,  PARAMETER :: sp      = SELECTED_REAL_KIND( 8, 37) ! Single precision
   INTEGER,  PARAMETER :: enum_t  = SELECTED_INT_KIND(10)
   INTEGER,  PARAMETER :: i64_k   = SELECTED_INT_KIND(17) ! max int64 9,223,372,036,854,775,807
   INTEGER,  PARAMETER :: i32_k   = SELECTED_INT_KIND( 8) ! max int32             2,147,483,647
   !----------------------------------------------------------------------------------------------------!
   INTEGER(enum_t), PARAMETER :: elNode        =  400, &
                                 elLine        =  401, &
                                 elTriangle    =  402, &
                                 elQuadrangle  =  403, &
                                 elTetrahedra  =  404, &
                                 elHexahedra   =  405, &  
                                 ! Definition of integration points.
                                 intLobatto    =  410, &
                                 intGauss      =  411
   !----------------------------------------------------------------------------------------------------!
   INTEGER, PARAMETER :: maxIntPts = 1024 
   !----------------------------------------------------------------------------------------------------!
   INTEGER(i64_k), PARAMETER :: i10  = 10
   INTEGER(i64_k), PARAMETER :: i9   =  9
   INTEGER(i64_k), PARAMETER :: i8   =  8
   INTEGER(i64_k), PARAMETER :: i7   =  7
   INTEGER(i64_k), PARAMETER :: i6   =  6
   INTEGER(i64_k), PARAMETER :: i5   =  5
   INTEGER(i64_k), PARAMETER :: i4   =  4
   INTEGER(i64_k), PARAMETER :: i3   =  3
   INTEGER(i64_k), PARAMETER :: i2   =  2
   INTEGER(i64_k), PARAMETER :: i1   =  1
   INTEGER(i64_k), PARAMETER :: i0   =  1
   !----------------------------------------------------------------------------------------------------!
   INTEGER(i64_k), PARAMETER :: i10_i64  = 10
   INTEGER(i64_k), PARAMETER :: i9_i64   =  9
   INTEGER(i64_k), PARAMETER :: i8_i64   =  8
   INTEGER(i64_k), PARAMETER :: i7_i64   =  7
   INTEGER(i64_k), PARAMETER :: i6_i64   =  6
   INTEGER(i64_k), PARAMETER :: i5_i64   =  5
   INTEGER(i64_k), PARAMETER :: i4_i64   =  4
   INTEGER(i64_k), PARAMETER :: i3_i64   =  3
   INTEGER(i64_k), PARAMETER :: i2_i64   =  2
   INTEGER(i64_k), PARAMETER :: i1_i64   =  1
   INTEGER(i64_k), PARAMETER :: i0_i64   =  1
   !----------------------------------------------------------------------------------------------------!
   INTEGER(i32_k), PARAMETER :: i10_i32  = 10
   INTEGER(i32_k), PARAMETER :: i9_i32   =  9
   INTEGER(i32_k), PARAMETER :: i8_i32   =  8
   INTEGER(i32_k), PARAMETER :: i7_i32   =  7
   INTEGER(i32_k), PARAMETER :: i6_i32   =  6
   INTEGER(i32_k), PARAMETER :: i5_i32   =  5
   INTEGER(i32_k), PARAMETER :: i4_i32   =  4
   INTEGER(i32_k), PARAMETER :: i3_i32   =  3
   INTEGER(i32_k), PARAMETER :: i2_i32   =  2
   INTEGER(i32_k), PARAMETER :: i1_i32   =  1
   INTEGER(i32_k), PARAMETER :: i0_i32   =  1
   !----------------------------------------------------------------------------------------------------!
   REAL(dp), PARAMETER :: ten    = 10.0_dp
   REAL(dp), PARAMETER :: nine   =  9.0_dp
   REAL(dp), PARAMETER :: eight  =  8.0_dp
   REAL(dp), PARAMETER :: seven  =  7.0_dp
   REAL(dp), PARAMETER :: six    =  6.0_dp
   REAL(dp), PARAMETER :: five   =  5.0_dp
   REAL(dp), PARAMETER :: four   =  4.0_dp
   REAL(dp), PARAMETER :: three  =  3.0_dp
   REAL(dp), PARAMETER :: two    =  2.0_dp
   REAL(dp), PARAMETER :: one    =  1.0_dp
   REAL(dp), PARAMETER :: half   =  0.5_dp
   REAL(dp), PARAMETER :: third  =  1.0_dp/3.0_dp
   REAL(dp), PARAMETER :: fourth =  0.25_dp
   REAL(dp), PARAMETER :: eighth =  0.125_dp
   REAL(dp), PARAMETER :: zero   =  0.0_dp
   REAL(dp), PARAMETER :: piOver4 = ATAN(one)
   REAL(dp), PARAMETER :: piOver2 = piOver4 * two
   REAL(dp), PARAMETER :: pi      = piOver4 * 4.0_dp !3.141592653589793_dp
   !----------------------------------------------------------------------------------------------------!
END MODULE master_parameters
!*******************************************************************************************************!