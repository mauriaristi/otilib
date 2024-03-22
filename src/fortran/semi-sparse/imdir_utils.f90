! ============================================================================================!
!> This module defines the sparse implementation of the Order truncated
!! imaginary numebers in Fortran.
!!
!! Author: Mauricio Aristizabal, PhD
!! Date Created: 3/21/2024
! ============================================================================================!
MODULE imdir_utils
   ! -----------------------------------------------------------------------------------------!
   USE real_utils
   USE master_parameters
   ! -----------------------------------------------------------------------------------------!
   IMPLICIT NONE
   ! -----------------------------------------------------------------------------------------!
   ! Integer types
   INTEGER, PARAMETER :: ord_t   = 1  !<-TODO This should go in a core Module.
   INTEGER, PARAMETER :: imdir_t = 8  !<-
   INTEGER, PARAMETER :: bases_t = 8  !<-
   INTEGER, PARAMETER :: nnz_t   = 8  !<-
   ! -----------------------------------------------------------------------------------------!
   INTEGER(ord_t),   PARAMETER, PRIVATE ::  max_n = 3  !< Max. Imag. order supported.
   INTEGER(bases_t), PARAMETER, PRIVATE ::  max_m = 4  !< Max. num. basis supported.
   INTEGER(imdir_t), PARAMETER, DIMENSION(max_n)   ::  ndir_order = [ 4, 10, 20 ]
   INTEGER(imdir_t), PARAMETER, PRIVATE            ::  max_ndir = 34 !< Max. im. dirs supportd.
   INTEGER(imdir_t), PARAMETER, DIMENSION(max_n+1) ::  ndir_order_cum = [ 1, 5, 15, 35 ]
   ! -----------------------------------------------------------------------------------------!
   TYPE imdir_type
      INTEGER(ord_t)   :: order=0  !<- Order of the imaginary direction
      INTEGER(imdir_t) :: index=0  !<- Index of the imaginary direction
   END TYPE imdir_type
   ! -----------------------------------------------------------------------------------------!
   INTERFACE PPRINT
      MODULE PROCEDURE sotinum_epsilon_i     ! Create sotinum from integer 
      ! MODULE PROCEDURE sotinum_epsilon_2i    ! Create sotinum from two integers
   END INTERFACE
   ! -----------------------------------------------------------------------------------------!

   CONTAINS

   !==========================================================================================!
   !> @brief This function assigns a real number to an OTI number object.
   !! 
   !! res = rhs
   !!
   !! @param[inout] res: otinum object.
   !! @param[in] rhs: (real) Real number to be assigned.
   !!
   !******************************************************************************************!
   SUBROUTINE imdir_type_pprint(self, )
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE(imdir_type), INTENT(IN) :: self
      ! --------------------------------------------------------------------------------------!
      
      ! Real
      res%r = rhs

      
   END SUBROUTINE imdir_type_pprint
   !==========================================================================================!

END MODULE imdir_utils