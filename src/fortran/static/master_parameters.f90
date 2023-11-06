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
   INTEGER,  PARAMETER :: dp     = SELECTED_REAL_KIND(15,306)
   INTEGER,  PARAMETER :: enum_t = SELECTED_INT_KIND(4)
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
   REAL(dp), PARAMETER :: ten    = 10.0_dp
   REAL(dp), PARAMETER :: eight  =  8.0_dp
   REAL(dp), PARAMETER :: six    =  6.0_dp
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