! ============================================================================================!
!> This module defines core routines required to operate Order truncated imaginary numbers.
!! This includes mainly utility functions to determine number of directions (total and order)
!! and ways to multiply/divide directions in the 
!! 
!! This implementation resembles a dual number with multiple imaginary directions.
!!
!! Author: Mauricio Aristizabal, PhD
!!         University of Texas at San Antonio
!! Last mod date: 10/07/2024
! ============================================================================================!
MODULE OTI_CORE
   ! -----------------------------------------------------------------------------------------!
   USE real_utils
   USE master_parameters
   ! -----------------------------------------------------------------------------------------!
   IMPLICIT NONE
   ! -----------------------------------------------------------------------------------------!
   INTEGER, PARAMETER :: ord_t   = 1 ! Size of int for order.
   INTEGER, PARAMETER :: imdir_t = 8 ! Size of int for imaginary index.
   INTEGER, PARAMETER :: bases_t = 8 ! Size of int for imaginary bases.
   ! -----------------------------------------------------------------------------------------!

   ! Define IMDIR type

CONTAINS
   
   !==========================================================================================!
   !> @brief Compute number of imaginary directions that have nbases and order given.
   !! 
   !! @param[in] nbases: (bases_t) Number of bases.
   !! @param[in] order:  (ord_t) specific order.
   !******************************************************************************************!
   FUNCTION ndir_order(nbases,order) RESULT(ndir)
      ! --------------------------------------------------------------------------------------!      
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      INTEGER(bases_t) :: nbases
      INTEGER(ord_t)   :: order
      INTEGER(imdir_t) :: ndir

      INTEGER(imdir_t) :: m_denom, m_numer
      ! --------------------------------------------------------------------------------------!

      ! Evaluates ( n + m - 1 )! /( ( m - 1 )! n! )
      m_denom = nbases - 1  ! Overkill?
      m_numer = order + nbases - 1

      ndir = oti_core_comb( m_numer,m_denom)

   END FUNCTION ndir_order
   !==========================================================================================!
   

   !==========================================================================================!
   !> @brief Compute number of imaginary directions in total for nbases and truncation order 
   !! as given.
   !! 
   !! @param[in] nbases: (bases_t) Number of bases.
   !! @param[in] order:  (ord_t) specific order.
   !******************************************************************************************!
   FUNCTION ndir_total(nbases,order) RESULT(ndir)
      ! --------------------------------------------------------------------------------------!      
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      INTEGER(bases_t) :: nbases
      INTEGER(ord_t)   :: order
      INTEGER(imdir_t) :: ndir

      INTEGER(imdir_t) :: m_denom, m_numer
      ! --------------------------------------------------------------------------------------!

      ! Evaluates (n+m)!/(m!n!)
      
      ! Select maximum from m,n to set as Choose denom.
      m_denom = nbases ! Overkill?
      m_numer = nbases+order

      ndir = oti_core_comb( m_numer, m_denom )

   END FUNCTION ndir_total
   !==========================================================================================!
   
   !==========================================================================================!
   !> @brief Compute combinatorial: a C b
   !!        comb = a! / ( b! (a-b)! )
   !! 
   !! @param[in] a: (imdir_t) "numerator".
   !! @param[in] b: (imdir_t) "denominator".
   !******************************************************************************************!
   FUNCTION oti_core_comb(a,b) RESULT(comb)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      INTEGER(imdir_t) :: a, b
      INTEGER(imdir_t) :: comb
      ! --------------------------------------------------------------------------------------!
      INTEGER(imdir_t) :: niter 
      INTEGER(imdir_t) :: num, den !TODO Investigate if these need to be higher precision...
      INTEGER(imdir_t) :: i
      ! --------------------------------------------------------------------------------------!
      
      ! Initialize parameters
      niter = a - MAX(a-b,b)
      num   = 1
      den   = 1

      DO i = 0, niter-1

         den = den * ( i + 1 )
         num = num * ( a - i ) 
         
      END DO

      comb = num/den

   END FUNCTION oti_core_comb
   !==========================================================================================!


   ! !==========================================================================================!
   ! !> @brief Multiply two imaginary directions given by its base decomposition. pairs 
   ! !!        alpha_res = alpha_1 * alpha_2
   ! !! 
   ! !! TODO: 
   ! !! 
   ! !! @param[in]      idx1: (imdir_t) Index of 1st imaginary direction.
   ! !! @param[in]      ord1: (ord_t)   Order of 1st imaginary direction.
   ! !! @param[in]      idx2: (imdir_t) Index of 2nd imaginary direction.
   ! !! @param[in]      ord2: (ord_t)   Order of 2nd imaginary direction.
   ! !! @param[inout] idxres: (imdir_t) Index of result imaginary direction.
   ! !! @param[inout] ordres: (ord_t)   Order of result imaginary direction.
   ! !******************************************************************************************!
   ! SUBROUTINE oti_core_mul_im_bas_s(dir1,dir2,dirres)
   !    ! --------------------------------------------------------------------------------------!
   !    IMPLICIT NONE
   !    ! --------------------------------------------------------------------------------------!
   !    INTEGER(bases_t), INTENT(IN)    :: dir1(:), dir2(:)
   !    INTEGER(bases_t), INTENT(INOUT) :: dirres(SIZE(dir1,1)+SIZE(dir2,1))
   !    INTEGER(bases_t) :: bas1(ord1), bas2(ord2), basres(ord1+ord2)
   !    ! --------------------------------------------------------------------------------------!
      
   !    ! This fully effectuates the multiplication.
   !    ordres = ord1 + ord2 
      
   !    ! For each case, it is needed to have the imaginary direction bases fully available.
      
   !    ! Get  IM dir min-max sepparated.
   !    IF (ord1>ord2) THEN
   !       idxmax = idx1
   !       idxmin = idx2
   !       ordmax = ord1
   !       ordmin = ord2
   !    ELSE
   !       idxmax = idx2
   !       idxmin = idx1
   !       ordmax = ord2
   !       ordmin = ord1
   !    END IF 


      
   !    DO i = 0, niter-1
         
   !    END DO

   !    comb = num/den

   ! END SUBROUTINE oti_core_mul_im_imlist_s
   ! !==========================================================================================!

   ! !==========================================================================================!
   ! !> @brief Multiply two imaginary directions given by alpha=(idx,ord) pairs 
   ! !!        alpha_res = alpha_1 * alpha_2
   ! !! 
   ! !! TODO: 
   ! !! 
   ! !! @param[in]      idx1: (imdir_t) Index of 1st imaginary direction.
   ! !! @param[in]      ord1: (ord_t)   Order of 1st imaginary direction.
   ! !! @param[in]      idx2: (imdir_t) Index of 2nd imaginary direction.
   ! !! @param[in]      ord2: (ord_t)   Order of 2nd imaginary direction.
   ! !! @param[inout] idxres: (imdir_t) Index of result imaginary direction.
   ! !! @param[inout] ordres: (ord_t)   Order of result imaginary direction.
   ! !******************************************************************************************!
   ! SUBROUTINE oti_core_mul_im_idxord_s(idx1,ord1,idx2,ord2,idxres,ordres)
   !    ! --------------------------------------------------------------------------------------!
   !    IMPLICIT NONE
   !    ! --------------------------------------------------------------------------------------!
   !    INTEGER(imdir_t), INTENT(IN)    :: idx1, idx2
   !    INTEGER(ord_t),   INTENT(IN)    :: ord1, ord2
   !    INTEGER(imdir_t), INTENT(INOUT) :: idxres
   !    INTEGER(ord_t),   INTENT(INOUT) :: ordres
   !    INTEGER(imdir_t)                :: idxmin, idxmax
   !    INTEGER(ord_t)                  :: ordmin, ordmax
   !    INTEGER(bases_t) :: bas1(ord1), bas2(ord2), basres(ord1+ord2)
   !    ! --------------------------------------------------------------------------------------!
      
   !    ! This fully effectuates the multiplication.
   !    ordres = ord1 + ord2 
      
   !    ! For each case, it is needed to have the imaginary direction bases fully available.
      
   !    ! Get  IM dir min-max sepparated.
   !    IF (ord1>ord2) THEN
   !       idxmax = idx1
   !       idxmin = idx2
   !       ordmax = ord1
   !       ordmin = ord2
   !    ELSE
   !       idxmax = idx2
   !       idxmin = idx1
   !       ordmax = ord2
   !       ordmin = ord1
   !    END IF 


      
   !    DO i = 0, niter-1
         
   !    END DO

   !    comb = num/den

   ! END SUBROUTINE oti_core_mul_im_idxord_s
   ! !==========================================================================================!

END MODULE OTI_CORE
! ============================================================================================!