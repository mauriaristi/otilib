! ============================================================================================!
!> This module defines a sparse implementation of the Order truncated
!! imaginary numbers in Fortran with truncation order 1.
!! 
!! This implementation resembles a dual number with multiple imaginary directions.
!!
!! Author: Mauricio Aristizabal, PhD
!! Last mod date: 9/27/2024
! ============================================================================================!
MODULE sotin1
   ! -----------------------------------------------------------------------------------------!
   USE real_utils
   USE master_parameters
   ! -----------------------------------------------------------------------------------------!
   IMPLICIT NONE
   ! -----------------------------------------------------------------------------------------!
   
   INTEGER, PARAMETER, PRIVATE :: m_max   = 100 ! up-to m_max imag. basis.

   INTEGER, PARAMETER, PRIVATE :: ord_t   = 1  ! TODO This should go in a core Module.
   INTEGER, PARAMETER, PRIVATE :: imdir_t = 8
   INTEGER, PARAMETER, PRIVATE :: bases_t = 8
   INTEGER, PARAMETER, PRIVATE :: nnz_t   = 8

   ! -----------------------------------------------------------------------------------------!
   TYPE sotin1_t
      REAL(dp)          :: r               !<- Real coefficient.
      REAL(dp)          :: imCoeff(m_max)  !<- Imag. coeffs.
      INTEGER(imdir_t)  :: imDir(m_max)    !<- Imag. dirs. (active, sorted). 
      INTEGER(imdir_t)  :: m_active        !<- Number of active dirs.
      INTEGER(ord_t)    :: act_ord         !<- Actual order. TODO: Should this be per-basis?
   END TYPE sotin1_t
   ! -----------------------------------------------------------------------------------------!
   INTERFACE PPRINT
      MODULE PROCEDURE sotin1_pprint_s!, sotin1_pprint_v, sotin1_pprint_m
   END INTERFACE

   ! INTERFACE PPRINT
   !    MODULE PROCEDURE sotin1_pfullprint_s
   ! END INTERFACE

   INTERFACE ASSIGNMENT(=)
      MODULE PROCEDURE sotin1_assign_r, sotin1_assign_i
   END INTERFACE

   INTERFACE OPERATOR(+)
      MODULE PROCEDURE &
         sotin1_add_ro_ss, sotin1_add_or_ss, sotin1_add_oo_ss ! Scalar addition
   END INTERFACE

   INTERFACE OPERATOR(*)
      MODULE PROCEDURE sotin1_mul_ro_ss, sotin1_mul_or_ss, sotin1_mul_oo_ss
   END INTERFACE

   INTERFACE EPS
      MODULE PROCEDURE sotin1_epsilon_i     ! Create sotin1_t from integer 
      ! MODULE PROCEDURE sotin1_epsilon_2i    ! Create sotin1_t from two integers
      ! MODULE PROCEDURE sotin1_epsilon_imdir ! Create sotin1_t from imdir
      ! MODULE PROCEDURE sotin1_epsilon_list  ! Create sotin1_t from list representing IMDIR
   END INTERFACE
   ! -----------------------------------------------------------------------------------------!

   CONTAINS

   !==========================================================================================!
   !> @brief This function assigns a real scalar to an OTI number object.
   !! 
   !! res = rhs
   !!
   !! @param[inout] res: otinum object.
   !! @param[in] rhs: (real) Real number to be assigned.
   !!
   !******************************************************************************************!
   SUBROUTINE sotin1_assign_r(res,rhs)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      REAL(dp), INTENT(IN) :: rhs
      TYPE( sotin1_t ), INTENT(OUT) :: res
      ! --------------------------------------------------------------------------------------!
      
      ! Real
      res%r          = rhs
      res%imCoeff(:) = zero ! Initialized for safety.
      res%imDir(:)   = 0    ! Initialized for safety.
            
      ! Actual order and m_active should be initialized to zero for safety.
      res%m_active = 0
      res%act_ord  = 0

      ! ! Truncation order is zero for real numbers
      ! res%order  = 0
      
   END SUBROUTINE sotin1_assign_r
   !==========================================================================================!

   !==========================================================================================!
   !> @brief This function assigns a real number to an OTI number object.
   !! 
   !! res = rhs
   !!
   !! @param[inout] res: otinum object.
   !! @param[in] rhs: (integer) Real number to be assigned.
   !!
   !******************************************************************************************!
   SUBROUTINE sotin1_assign_i(res,rhs)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      INTEGER, INTENT(IN) :: rhs
      TYPE( sotin1_t ), INTENT(OUT) :: res
      ! --------------------------------------------------------------------------------------!
      
      ! Real
      res = REAL(rhs, DP)
      
   END SUBROUTINE sotin1_assign_i
   !==========================================================================================!

   !==========================================================================================!
   !> @brief Add real and sotin1_t 
   !! 
   !! lhs + rhs
   !! 
   !! @param[in] lhs: (real) left hand side operation.
   !! @param[in] rhs: (sotin1_t) right hand side operation.
   !******************************************************************************************!
   FUNCTION sotin1_add_ro_ss(lhs,rhs) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      REAL(dp), INTENT(IN)         :: lhs
      TYPE( sotin1_t ), INTENT(IN) :: rhs
      TYPE( sotin1_t )             :: res
      ! 
      ! Internal variables
      INTEGER(ord_t) :: i_ord
      INTEGER(nnz_t) :: i_im, i
      ! --------------------------------------------------------------------------------------!
      
      ! Add two real numbers. This also initializes memory.
      res = lhs + rhs%r 

      IF (rhs%act_ord>0) THEN
         
         res%act_ord  = rhs%act_ord
         res%m_active = rhs%m_active
         
         ! Copy information from rhs to res.
         DO i_ord = 1, rhs%act_ord            
            
            res%imCoeff(1:rhs%m_active) = rhs%imCoeff(1:rhs%m_active)

            res%imDir(1:rhs%m_active)   = rhs%imDir(1:rhs%m_active)
            
         END DO

      END IF 

   END FUNCTION sotin1_add_ro_ss
   !==========================================================================================!

   !==========================================================================================!
   !> @brief Add  sotin1_t and real
   !! 
   !! lhs + rhs
   !! 
   !! @param[in] lhs: (sotin1_t) left hand side operation.
   !! @param[in] rhs: (real) right hand side operation.
   !******************************************************************************************!
   FUNCTION sotin1_add_or_ss(lhs,rhs) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE( sotin1_t ), INTENT(IN) :: lhs
      REAL(dp), INTENT(IN)         :: rhs
      TYPE( sotin1_t )             :: res
      ! --------------------------------------------------------------------------------------!
      
      ! Reuse previous implementation.
      res = rhs + lhs

   END FUNCTION sotin1_add_or_ss
   !==========================================================================================!


   !==========================================================================================!
   !> @brief Add real and sotin1_t 
   !! 
   !! lhs + rhs
   !! 
   !! @param[in] lhs: (real) left hand side operation.
   !! @param[in] rhs: (sotin1_t) right hand side operation.
   !******************************************************************************************!
   FUNCTION sotin1_add_oo_ss(lhs,rhs) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE( sotin1_t ), INTENT(IN)         :: lhs
      TYPE( sotin1_t ), INTENT(IN) :: rhs
      TYPE( sotin1_t )             :: res
      ! 
      ! Internal variables
      INTEGER(ord_t) :: i_ord
      INTEGER(nnz_t) :: i_im, i_lhs, i_rhs, i_res
      INTEGER(nnz_t) :: n_active
      ! --------------------------------------------------------------------------------------!
      
      IF ( (rhs%act_ord>0) .and. (lhs%act_ord>0) ) THEN
         
         res%r = lhs%r + rhs%r  ! This initializes res.

         res%act_ord  = MAX(rhs%act_ord,lhs%act_ord)
         res%m_active = 0

         ! Start at first location of both operators.
         i_lhs = 1 !
         i_rhs = 1 !
         i_res = 1 !
         ! Add up Copy information from rhs to res.
         DO 
            ! This is like a do while loop.
            IF (i_lhs>lhs%m_active .and. i_rhs>rhs%m_active)  exit

            IF (i_lhs>lhs%m_active) THEN ! Prevent overflow rhs
               ! Only add the rhs.
               res%imCoeff( i_res ) = rhs%imCoeff( i_rhs )
               res%imDir(   i_res ) = rhs%imDir(   i_rhs )
               i_rhs = i_rhs + 1
            ELSE IF (i_rhs>rhs%m_active) THEN ! Prevent overflow lhs
               ! Only add the lhs.
               res%imCoeff( i_res ) = lhs%imCoeff( i_lhs )
               res%imDir(   i_res ) = lhs%imDir(   i_lhs )
               i_lhs = i_lhs + 1
            ELSE ! Both lhs and rhs have something to evaluate.
               IF (rhs%imDir(i_rhs)==lhs%imDir(i_lhs)) THEN ! Same imdirs.
                  res%imCoeff(i_res) = rhs%imCoeff(i_rhs)+lhs%imCoeff(i_lhs)
                  res%imDir(i_res)   = rhs%imDir(i_rhs)
                  i_lhs = i_lhs + 1
                  i_rhs = i_rhs + 1
               ELSE IF (rhs%imDir(i_rhs) < lhs%imDir(i_lhs)) THEN ! Lower imdir rhs
                  res%imCoeff(i_res) = rhs%imCoeff(i_rhs)
                  res%imDir(i_res)   = rhs%imDir(i_rhs)
                  i_rhs = i_rhs + 1
               ELSE  ! Lower imdir lhs
                  res%imCoeff(i_res) = lhs%imCoeff(i_lhs)
                  res%imDir(i_res)   = lhs%imDir(i_lhs)
                  i_lhs = i_lhs + 1
               END IF 

            END IF

            res%m_active  = res%m_active + 1
            i_res = i_res + 1

         END DO

      ELSE IF(rhs%act_ord==0) THEN
         
         res = rhs%r  + lhs 

      ELSE  ! lhs%act_ord==0
         
         res = lhs%r  + rhs

      END IF 

   END FUNCTION sotin1_add_oo_ss
   !==========================================================================================!

   !==========================================================================================!
   !> @brief Multiply real and sotin1_t 
   !! 
   !! lhs * rhs
   !! 
   !! @param[in] lhs: (real) left hand side operation.
   !! @param[in] rhs: (sotin1_t) right hand side operation.
   !******************************************************************************************!
   FUNCTION sotin1_mul_ro_ss(lhs,rhs) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      REAL(dp), INTENT(IN)       :: lhs
      TYPE(sotin1_t), INTENT(IN) :: rhs
      TYPE(sotin1_t)             :: res
      INTEGER(ord_t) :: i_ord
      INTEGER(nnz_t) :: i_im

      ! --------------------------------------------------------------------------------------!
      
      ! Add two real numbers. This also deallocates memory.
      res = lhs * rhs%r 

      IF (rhs%act_ord>0) THEN
         
         res%act_ord = rhs%act_ord
         res%m_active = rhs%m_active
         
         ! Copy information from rhs to res.
         DO i_im = 1, rhs%m_active
         
            res%imcoeff(i_im) = lhs*rhs%imcoeff(i_im)
            res%imdir( i_im)  = rhs%imdir( i_im)

         END DO

      END IF 

   END FUNCTION sotin1_mul_ro_ss
   !==========================================================================================!

   !==========================================================================================!
   !> @brief Multiply sotin1_t and sotin1_t 
   !! 
   !! lhs * rhs
   !! 
   !! @param[in] lhs: (sotin1_t) left hand side operation.
   !! @param[in] rhs: (sotin1_t) right hand side operation.
   !******************************************************************************************!
   FUNCTION sotin1_mul_oo_ss(lhs,rhs) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE(sotin1_t), INTENT(IN)       :: lhs
      TYPE(sotin1_t), INTENT(IN) :: rhs
      TYPE(sotin1_t)             :: res
      
      INTEGER(nnz_t) :: i_res, i_rhs, i_lhs

      ! --------------------------------------------------------------------------------------!
      
      IF ( (rhs%act_ord>0) .and. (lhs%act_ord>0) ) THEN
         
         res%r = lhs%r * rhs%r  ! This initializes res.

         res%act_ord  = MAX(rhs%act_ord,lhs%act_ord)
         res%m_active = 0

         ! Start at first location of both operators.
         i_lhs = 1 !
         i_rhs = 1 !
         i_res = 1 !
         ! Multiply real x imdirs and add up
         DO 
            ! This is like a do while loop.
            IF (i_lhs>lhs%m_active .and. i_rhs>rhs%m_active)  exit

            IF (i_lhs>lhs%m_active) THEN ! Prevent overflow rhs
               ! Only add the rhs.
               res%imCoeff( i_res ) = lhs%r * rhs%imCoeff( i_rhs )
               res%imDir(   i_res ) = rhs%imDir(   i_rhs )
               i_rhs = i_rhs + 1
            ELSE IF (i_rhs>rhs%m_active) THEN ! Prevent overflow lhs
               ! Only add the lhs.
               res%imCoeff( i_res ) = rhs%r * lhs%imCoeff( i_lhs )
               res%imDir(   i_res ) = lhs%imDir(   i_lhs )
               i_lhs = i_lhs + 1
            ELSE ! Both lhs and rhs have something to evaluate.
               IF (rhs%imDir(i_rhs)==lhs%imDir(i_lhs)) THEN ! Same imdirs.
                  res%imCoeff(i_res) = lhs%r * rhs%imCoeff(i_rhs) + rhs%r * lhs%imCoeff(i_lhs)
                  res%imDir(i_res)   = rhs%imDir(i_rhs)
                  i_lhs = i_lhs + 1
                  i_rhs = i_rhs + 1
               ELSE IF (rhs%imDir(i_rhs) < lhs%imDir(i_lhs)) THEN ! Lower imdir rhs
                  res%imCoeff(i_res) = lhs%r*rhs%imCoeff(i_rhs)
                  res%imDir(i_res)   =       rhs%imDir(  i_rhs)
                  i_rhs = i_rhs + 1
               ELSE  ! Lower imdir lhs
                  res%imCoeff(i_res) = rhs%r*lhs%imCoeff(i_lhs)
                  res%imDir(i_res)   =       lhs%imDir(  i_lhs)
                  i_lhs = i_lhs + 1
               END IF 

            END IF

            ! TODO: Need a lower level function that handles this multiplication. 
            ! This can be done quite quickly for both cases. 
            res%m_active  = res%m_active + 1
            i_res = i_res + 1

         END DO

      ELSE IF(rhs%act_ord==0) THEN
         
         res = rhs%r  + lhs 

      ELSE  ! lhs%act_ord==0
         
         res = lhs%r  + rhs

      END IF 

   END FUNCTION sotin1_mul_oo_ss
   !==========================================================================================!

   !==========================================================================================!
   !> @brief Multiply  sotin1_t and real
   !! 
   !! lhs * rhs
   !! 
   !! @param[in] lhs: (sotin1_t) left hand side operation.
   !! @param[in] rhs: (real) right hand side operation.
   !******************************************************************************************!
   FUNCTION sotin1_mul_or_ss(lhs,rhs) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE(sotin1_t), INTENT(IN) :: lhs
      REAL(dp), INTENT(IN)      :: rhs
      TYPE(sotin1_t)             :: res
      INTEGER(ord_t) ::i_ord
      INTEGER(nnz_t) ::i_im
      ! --------------------------------------------------------------------------------------!
      
      ! multiply real - oti
      res = rhs * lhs

   END FUNCTION sotin1_mul_or_ss
   !==========================================================================================!


   ! !==========================================================================================!
   ! !> @brief Evaluate single-variable TSE at given OTI point.
   ! !! 
   ! !! TSE(val)
   ! !! 
   ! !! @param[in] oti_tse: (sotin1_t) Value to evaluate the function (OTI).
   ! !! @param[in] val: (sotin1_t) Value to evaluate the function (OTI).
   ! !******************************************************************************************!
   ! FUNCTION sotin1_tse_eval_o_s(val) RESULT (res)
   !    ! --------------------------------------------------------------------------------------!
   !    IMPLICIT NONE
   !    ! --------------------------------------------------------------------------------------!
   !    TYPE(sotin1_t), INTENT(IN) :: self
   !    TYPE(sotin1_t), INTENT(IN) :: val
   !    TYPE(sotin1_t)             :: res      
   !    ! --------------------------------------------------------------------------------------!
   !    INTEGER(nnz_t) :: i_val, i_ord
   !    ! --------------------------------------------------------------------------------------!
      
   !    ! Considerations. This considers single variable evaluation.
   !    !
   !    ! 1. initialize with real value.
   !    res  = self%r

   !    DO i_ord = 1, self%act_ord
   !       res

   !    END DO



   ! END FUNCTION sotin1_tse_eval_o_s
   ! !==========================================================================================!

   ! !==========================================================================================!
   ! !> @brief Evaluate single variable function at sotin1_t
   ! !! 
   ! !! f(val)
   ! !! 
   ! !! @param[in] val: (sotin1_t) Value to evaluate the function (OTI).
   ! !! @param[in] rhs: (sotin1_t) right hand side operation.
   ! !******************************************************************************************!
   ! FUNCTION sotin1_feval_o_s(val,fevald) RESULT (res)
   !    ! --------------------------------------------------------------------------------------!
   !    IMPLICIT NONE
   !    ! --------------------------------------------------------------------------------------!
   !    TYPE(sotin1_t), INTENT(IN) :: val
   !    TYPE(sotin1_t), INTENT(IN) :: fevald
   !    TYPE(sotin1_t)             :: res      
   !    ! --------------------------------------------------------------------------------------!
   !    INTEGER(nnz_t) :: i_res, i_val
   !    ! --------------------------------------------------------------------------------------!
            
   ! END FUNCTION sotin1_feval_o_s
   ! !==========================================================================================!

























   !==========================================================================================!
   !> @brief This function only creates imaginary directions with integer parameters.
   !!        of actual order 1.
   !!
   !! @param[in] base: Imaginary base to be created.
   !! @param[in] order(optional): Truncation order to be set to the number. Default 1.
   !!
   !******************************************************************************************!
   FUNCTION sotin1_epsilon_i(base,order) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      INTEGER, INTENT(IN)          :: base
      INTEGER, INTENT(IN),OPTIONAL :: order
      INTEGER(ord_t)               :: i_ord
      TYPE(sotin1_t)               :: res
      ! --------------------------------------------------------------------------------------!

      ! Create number as a zero. It also Deallocates memory.
      res = zero

      IF ( PRESENT(order) ) THEN
         i_ord = order
      ELSE
         i_ord = 1
      END IF
      
      ! Set truncation order to the one given.
      ! res%order=i_ord

      IF (i_ord == 0) THEN
         res = one
      ELSE
         ! Only if imaginary basis supported, allocate memory. See how to update this.
         IF (base <= m_max) THEN
            
            res%imcoeff(1) = one   
            res%imdir(1)   = base  
            res%act_ord    = i_ord 
            res%m_active   = 1
            
         ELSE
            ! RAISE Warning that the number of imaginary direction is not supported 
            ! in this occation.
            PRINT*, "WARNING: Cant create OTI number with t" 
         END IF

      END IF

   END FUNCTION sotin1_epsilon_i
   !==========================================================================================!

   ! ! !==========================================================================================!
   ! ! !>
   ! ! !!
   ! ! !!
   ! ! !******************************************************************************************!
   ! ! FUNCTION sotin1_epsilon_2i(idx,ordin,order) RESULT (res)
   ! !    ! --------------------------------------------------------------------------------------!
   ! !    IMPLICIT NONE
   ! !    ! --------------------------------------------------------------------------------------!
   ! !    INTEGER, INTENT(IN) :: idx
   ! !    INTEGER, INTENT(IN) :: ordin
   ! !    INTEGER, INTENT(IN),OPTIONAL :: order
   ! !    INTEGER(ord_t)      :: i_ord
   ! !    INTEGER(imdir_t)    :: i_idx
   ! !    TYPE(sotin1_t)       :: res
   ! !    ! --------------------------------------------------------------------------------------!

   ! !    res = zero
   ! !    i_ord = ordin
      
   ! !    IF ( PRESENT(order) ) THEN
   ! !       i_ord = MIN(MAX(order,ordin),max_n)
   ! !    END IF

   ! !    IF (idx <= ndir_order(ordin) .and. ordin <= max_n ) THEN

   ! !       i_idx = ndir_order_cum(ordin)

   ! !       res%im(i_idx)    = one 
   ! !       res%imdir(i_idx) = idx
   ! !       res%nnz(ordin)   = 1
   ! !       res%act_ord      = ordin
   ! !       res%order        = i_ord

   ! !    END IF


   ! ! END FUNCTION sotin1_epsilon_2i
   ! ! !==========================================================================================!



   ! ! ! sotin1_pfullprint_s
   ! ! !==========================================================================================!
   ! ! !> @ brief This function prints in a human friendly manner a sotin1_t object.
   ! ! !! 
   ! ! !! @param[in] num: sotin1_t object to be printed.
   ! ! !! @param[in] fmt(optional): Format of the real coefficients to be printed. Default: 'F10.4'
   ! ! !! @param[in] unit(optional): Unit to print. Default 6.
   ! ! !! @param[in] advance(optional): if 'YES', advance to next line, otherwise sets . Default 'YES'.
   ! ! !!
   ! ! !******************************************************************************************!
   ! ! SUBROUTINE sotin1_pfullprint_s(num, fmt, unit, advance)
   ! !    ! --------------------------------------------------------------------------------------!
   ! !    IMPLICIT NONE
   ! !    ! --------------------------------------------------------------------------------------!
   ! !    ! Inputs
   ! !    TYPE(sotin1_t), INTENT(IN), TARGET      :: num
   ! !    CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
   ! !    CHARACTER(len=*), INTENT(IN), OPTIONAL :: advance
   ! !    INTEGER, INTENT(IN), OPTIONAL          :: unit
   ! !    ! --------------------------------------------------------------------------------------!
   ! !    ! Local Defs.
   ! !    CHARACTER(len=:),ALLOCATABLE             :: output_format
   ! !    CHARACTER(len=:),ALLOCATABLE             :: advance_option
   ! !    INTEGER                                  :: unt
   ! !    INTEGER(ord_t)                           :: i_ord
   ! !    INTEGER(imdir_t)                         :: i_im
   ! !    INTEGER                                  :: offset, next_offset
   ! !    ! --------------------------------------------------------------------------------------!
   ! !    IF ( PRESENT(unit) ) THEN
   ! !       unt = unit
   ! !    ELSE
   ! !       unt = 6
   ! !    END IF

   ! !    IF ( PRESENT(fmt) ) THEN
   ! !       output_format = '('//trim(fmt)//')'
   ! !    ELSE
   ! !       output_format = '(F10.4)'
   ! !    END IF

   ! !    IF (PRESENT(advance)) THEN
   ! !       advance_option = trim(advance)
   ! !    ELSE
   ! !       advance_option = 'YES'
   ! !    END IF      

   ! !    ! Print real part.
   ! !    CALL pprint(num%r,unit=unt,fmt=output_format,advance='no')
   ! !    WRITE(unt,'(A)',advance='NO') ' ' !<- Adds space.

   ! !    ! Print imaginary coefficients.
   ! !    DO i_ord = 1, num%act_ord
         
   ! !       ! Loop through the imaginary terms
   ! !       DO i_im=num%nnz(i_ord),num%nnz(i_ord+1)
            
   ! !          ! Print imaginary coefficient 
   ! !          WRITE(unt,'(A)',advance='NO') '+ ' 

   ! !          CALL pprint( num%imcoef(i_im), unit=unt, fmt=output_format, advance='no')
             
   ! !          WRITE(unt,'(A)',advance='NO') '*eps(' 
   ! !          WRITE(unt,'(I2,A,I2)',advance='NO') num%imdir(i_im), ',', i_ord
   ! !          WRITE(unt,'(A)',advance='NO') ') '    !<- Adds space.
      
   ! !       END DO

   ! !    END DO

   ! !    WRITE(unt,'(A)',advance=advance_option) ''
   ! !    !
   ! ! END SUBROUTINE sotin1_pfullprint_s
   ! ! !==========================================================================================!


   !==========================================================================================!
   !> @brief This function prints in a human friendly manner a sotin1_t object.
   !! 
   !! @param[in] num: sotin1_t object to be printed.
   !! @param[in] fmt(optional): Format of the real coefficients to be printed. Default: 'F10.4'
   !! @param[in] unit(optional): Unit to print. Default 6.
   !! @param[in] advance(optional): if 'YES', advance to next line, otherwise sets . Default 'YES'.
   !!
   !******************************************************************************************!
   SUBROUTINE sotin1_pprint_s(num, fmt, unit, advance)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      ! Inputs
      TYPE(sotin1_t), INTENT(IN), TARGET      :: num
      CHARACTER(len=*), INTENT(IN), OPTIONAL  :: fmt
      CHARACTER(len=*), INTENT(IN), OPTIONAL  :: advance
      INTEGER, INTENT(IN), OPTIONAL           :: unit
      ! --------------------------------------------------------------------------------------!
      ! Local Defs.
      CHARACTER(len=:),ALLOCATABLE             :: output_format
      CHARACTER(len=:),ALLOCATABLE             :: advance_option
      INTEGER                                  :: unt
      INTEGER(ord_t)                           :: i_ord
      INTEGER(imdir_t)                         :: i_im
      INTEGER                                  :: offset, next_offset
      ! --------------------------------------------------------------------------------------!
         
      ! I assume it will be faster to write to a buffer instead of screen right away.
      ! TODO: Change this to write directly to a buffer then print off to screen.

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

      IF (PRESENT(advance)) THEN
         advance_option = trim(advance)
      ELSE
         advance_option = 'YES'
      END IF      

      ! Print real part.
      CALL pprint(num%r,unit=unt,fmt=output_format,advance='no')
      WRITE(unt,'(A)',advance='NO') ' ' !<- Adds space.

      ! Print imaginary coefficients (if memory has been allocated).
      DO i_ord = 1, num%act_ord
         
         ! Loop through the imaginary terms
         DO i_im=1,num%m_active
            
            ! Print imaginary coefficient 
            WRITE(unt,'(A)',advance='NO') '+ ' !<- Adds space.

            CALL pprint( num%imcoeff(i_im), unit=unt, fmt=output_format, advance='no')
             
            WRITE(unt,'(A)',advance='NO') ' * eps(' 
            WRITE(unt,'(I4)',advance='NO') num%imdir(i_im)
            WRITE(unt,'(A)',advance='NO') ') '    !<- Adds space.
      
         END DO

      END DO

      WRITE(unt,'(A)',advance=advance_option) ''
      !
   END SUBROUTINE sotin1_pprint_s
   !==========================================================================================!
      


END MODULE sotin1